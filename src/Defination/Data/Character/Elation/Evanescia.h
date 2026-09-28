#include "../include.h"

// Evanescia — kit: docs/kit-reference/Character/Elation/evanescia.md (nanoka 4.5.54)
// Simplifications:
//   Energy <-> Certified Banger converts one way per gain (a converted gain does not convert back), cap 100 per instance
//   Energy from CB goes through ERR (kit does not say "fixed") · Master Fox counts only Energy actually gained (overflow ignored)
//   Her own Certified Banger gains are separate instances named "Evanescia CB <n>", lasting as long as an Aha CB (cbDuration, E6 +1)
//   A2 "lower Participant ID" = Elation teammates whose Elation Skill priority < 146
namespace Evanescia{
    constexpr int PARTICIPANT_ID = 146;

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(104,480,240,eidolon,ElementType::PHYSICAL,Path::ELATION,"Evanescia",UnitType::STANDARD);
        ptr->setAllyBaseStats(1048,737,461);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        elationCount++;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        // her own Certified Banger instances: {buff name, amount}
        shared_ptr<vector<pair<string,double>>> ownCB = make_shared<vector<pair<string,double>>>();

        #pragma region Energy <-> Certified Banger

        function<int()> cbTurns = [ptr]() {
            return cbDuration + ((ptr->eidolon>=6) ? 1 : 0);
        };

        // Talent: gaining Certified Banger also gains the same Energy (max 100 per instance)
        function<void(double,bool)> gainCB = [ptr,ownCB,cbTurns](double value,bool toEnergy) {
            if(value<=0)return;
            ptr->buffNote["Evanescia CB Id"] += 1;
            string name = "Evanescia CB " + to_string((int)ptr->getBuffNote("Evanescia CB Id"));
            buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,value}},name,cbTurns());
            ownCB->push_back({name,value});
            if(!toEnergy)return;
            ptr->setBuffCheck("Evanescia Energy From CB",1);
            increaseEnergy(ptr,min(100.0,value));
            ptr->setBuffCheck("Evanescia Energy From CB",0);
        };

        #pragma endregion

        #pragma region Ability

        // Talent: while holding Certified Banger, extra Physical Elation DMG
        function<bool()> holdCB = [ptr]() {
            return ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0;
        };

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Evn BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,holdCB]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Evn Skill",
            [ptr,holdCB](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                genPunchLine(ptr,10);
                increaseEnergy(ptr,30);
                attack(act);
                if(!holdCB())return;
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::BLAST,"Evn Skill Elation");
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,16),
                    DmgSrc(DmgSrcType::ELATION,16)
                );
                elDmg->turnReset = 0;
                attack(elDmg);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,150,10)
            );
            act->addToActionBar();
        };

        // Master Fox: FuA 100% ATK AoE (toughness 10) · +25% Elation with CB · A4 VUL 12% 3 turns · +10 Energy · E1 Elation Skill
        function<void()> masterFox = [ptr,holdCB]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"Evn Master Fox",
            [ptr,holdCB](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,12}},"Evanescia A4",3);
                attack(act);
                if(holdCB()){
                    shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"Evn Master Fox Elation");
                    elDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,25),
                        DmgSrc(DmgSrcType::ELATION,25),
                        DmgSrc(DmgSrcType::ELATION,25)
                    );
                    elDmg->turnReset = 0;
                    attack(elDmg);
                }
                increaseEnergy(ptr,10);
                if(ptr->eidolon>=1)elationSkillTrigger(punchline,{ptr->getName()});
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->turnReset = 0;
            act->addToActionBar();
            dealDamage();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,ba,skill]() {
            if(sp>spSafety)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        // Ult: 160% ATK AoE (toughness 20) + 5 bounces 120% (toughness 5, A2 +1/+2/+4 at >=3/2/1 enemies)
        // with CB: 24% Elation AoE + 28% Elation to each enemy hit by a bounce · counts CB >= Max Energy
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [holdCB](CharUnit *ptr) {
            CharCmd::printUltStart("Evanescia");
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Evn Ult",
            [ptr,holdCB](shared_ptr<AllyAttackAction> &act){
                // row 0 = AoE hit, rows 1.. = one bounce each
                vector<Enemy*> bounceTargets;
                for(size_t i = 1; i < act->damageSplit.size(); i++){
                    for(auto &hit : act->damageSplit[i]){
                        if(find(bounceTargets.begin(),bounceTargets.end(),hit.target)==bounceTargets.end())
                            bounceTargets.push_back(hit.target);
                    }
                }
                attack(act);

                ptr->buffNote["Evanescia Ult Count"] += 1;
                if(ptr->eidolon>=6&&((int)ptr->getBuffNote("Evanescia Ult Count"))%4==1)increaseEnergy(ptr,0,120);

                if(!holdCB())return;
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"Evn Ult Elation",
                [ptr](shared_ptr<AllyAttackAction> &elDmg){
                    double extra = max(0.0,ptr->maxEnergy - ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]);
                    ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] += extra;
                    attack(elDmg);
                    ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] -= extra;
                });
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,24),
                    DmgSrc(DmgSrcType::ELATION,24),
                    DmgSrc(DmgSrcType::ELATION,24)
                );
                for(auto &each : bounceTargets)elDmg->addDamageIns(DmgSrc(DmgSrcType::ELATION,28),each);
                elDmg->turnReset = 0;
                elDmg->actionFunction(elDmg);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20)
            );
            int bounce = 5 + ((totalEnemy>=3) ? 1 : (totalEnemy==2) ? 2 : 4);
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,120,5),bounce);
            act->addToActionBar();
            dealDamage();
        }));

        // Elation Skill: 110% Elation AoE (toughness 20) · +5 Energy · +5 CB (E1 +10)
        elationSkillList.push_back(TriggerByYourSelfFunc(PARTICIPANT_ID, ptr, [gainCB](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,"Evn Elation Skill",
            [ptr,gainCB](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,5);
                attack(act);
                gainCB((ptr->eidolon>=1) ? 15 : 5,true);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,110,20),
                DmgSrc(DmgSrcType::ELATION,110,20),
                DmgSrc(DmgSrcType::ELATION,110,20)
            );
            act->addToAhaInstant();
        }));

        // Talent: gaining Energy also gains the same CB (max 100) · every 240 Energy gained -> Master Fox (max 240 per gain)
        whenEnergyIncreaseList.push_back(TriggerEnergyIncreaseFunc(PRIORITY_IMMEDIATELY, [ptr,gainCB,masterFox](CharUnit *target, double energy) {
            if(!target->isSameName(ptr)||energy<=0)return;
            if(!ptr->getBuffCheck("Evanescia Energy From CB"))gainCB(min(100.0,energy),false);
            // event fires before Energy is added -> only the part that fits under Max Energy counts
            double gained = max(0.0,min(energy,ptr->maxEnergy - ptr->currentEnergy));
            ptr->buffNote["Evanescia Fox Acc"] += min(240.0,gained);
            while(ptr->getBuffNote("Evanescia Fox Acc")>=240){
                ptr->buffNote["Evanescia Fox Acc"] -= 240;
                masterFox();
            }
        }));

        // After an Aha Instant she (and every Elation teammate) got Certified Banger = that Aha's Punchline
        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB](CharUnit *ptr) {
            if(cbCheck.empty())return;
            double pl = std::get<2>(cbCheck.back());
            if(ptr->eidolon>=6)extendBuffTime(ptr,std::get<0>(cbCheck.back()),cbDuration + 1);
            // Talent: her own Aha CB -> Energy
            if(pl>0){
                ptr->setBuffCheck("Evanescia Energy From CB",1);
                increaseEnergy(ptr,min(100.0,pl));
                ptr->setBuffCheck("Evanescia Energy From CB",0);
            }
            // A2: 50% of each lower-ID Elation teammate's CB gain (E2 +50% of that)
            vector<CharUnit*> counted;
            for(TriggerByYourSelfFunc &e : elationSkillList){
                if(e.owner==ptr||e.priority>=PARTICIPANT_ID)continue;
                if(find(counted.begin(),counted.end(),e.owner)!=counted.end())continue;
                counted.push_back(e.owner);
                gainCB(pl*0.5*((ptr->eidolon>=2) ? 1.5 : 1),true);
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ownCB,gainCB](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&isDebuffEnd(enemy,"Evanescia A4")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-12}});
            }
            if(!ally)return;
            if(ally->isSameName(ptr)){
                for(auto itr = ownCB->begin(); itr != ownCB->end(); ){
                    if(!isBuffEnd(ptr,itr->first)){ itr++; continue; }
                    buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,-itr->second}});
                    itr = ownCB->erase(itr);
                }
                return;
            }
            // A6: an Elation teammate's Aha CB ends this turn -> 50% of it to her (E2 +100% of that)
            if(ally->owner->path!=Path::ELATION)return;
            for(auto &each : cbCheck){
                string name = std::get<0>(each);
                if(!ally->getBuffCheck(name)||ally->buffEnd[name]!=ally->atvStats->turnCnt)continue;
                gainCB(std::get<2>(each)*0.5*((ptr->eidolon>=2) ? 2 : 1),true);
            }
        }));

        // Technique: on entering combat 100% ATK AoE (toughness 20) + 20 CB
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB](CharUnit *ptr) {
            if(!ptr->technique)return;
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Evn Technique",
            [ptr,gainCB](shared_ptr<AllyAttackAction> &act){
                attack(act);
                gainCB(20,true);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,20),
                DmgSrc(DmgSrcType::ATK,100,20),
                DmgSrc(DmgSrcType::ATK,100,20)
            );
            act->turnReset = 0;
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ownCB](CharUnit *ptr) {
            ownCB->clear();
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsType[Stats::ELATION][AType::NONE] += 18;
            ptr->atvStats->flatSpeed += 5;

            ptr->statsType[Stats::CR][AType::NONE] += 30; // A2
            if(ptr->eidolon>=1)ptr->statsType[Stats::RESPEN][AType::NONE] += 20;
            if(ptr->eidolon>=2)ptr->statsType[Stats::CD][AType::NONE] += 36;
            if(ptr->eidolon>=4)ptr->statsType[Stats::DEF_SHRED][AType::NONE] += 15;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            statsAdjust(ptr,Stats::CD);
        }));

        // E6: Elation DMG merrymake 15% + 2% per 100 CB held (max 1000 CB)
        if(ptr->eidolon>=6)
        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameOwnerName(ptr))return;
            double cb = min(1000.0,max(0.0,ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]));
            double buffValue = 15 + 2*floor(cb/100);
            buffSingle(ptr,{{Stats::MERRYMAKE,AType::NONE,buffValue - ptr->getBuffNote("Evanescia E6")}});
            ptr->setBuffNote("Evanescia E6",buffValue);
        }));

        // Talent: Elation = 20% of CRIT DMG
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr)||statsType!=Stats::CD)return;
            double buffValue = 0.2*calculateCritdamOnStats(ptr);
            buffSingle(ptr,{{Stats::ELATION,AType::NONE,buffValue - ptr->getBuffNote("Evanescia Talent")}});
            ptr->setBuffNote("Evanescia Talent",buffValue);
        }));

    }
}
