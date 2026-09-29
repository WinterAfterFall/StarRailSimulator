#include "../include.h"

// Trailblazer • Elation — kit: docs/kit-reference/Character/Elation/trailblazer-elation.md (nanoka 4.5.54)
// Simplifications:
//   Certified Banger she grants (Skill to self, Ult to the target) = separate instances "EMC CB <n>",
//   lasting as long as an Aha CB (cbDuration) · no CB-gain event exists, so e.g. Evanescia's CB->Energy does not see them
//   Technique: always "Irrepressible Laughter" (the high-chance roll) -> Elation +20%
//   A6: stacks — every Elation Skill used by an ally adds +2 CB to her next Skill (no cap)
namespace EMC{
    constexpr int PARTICIPANT_ID = 120;

    struct GrantedCB{
        AllyUnit *holder;
        string name;
        double value;
    };

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(106,160,160,eidolon,ElementType::LIGHTNING,Path::ELATION,"EMC",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,466,631);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        elationCount++;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        shared_ptr<vector<GrantedCB>> grantedCB = make_shared<vector<GrantedCB>>();

        #pragma region Helper

        function<void(AllyUnit*,double)> grantCB = [ptr,grantedCB](AllyUnit *holder,double value) {
            if(value<=0)return;
            // holder keeps CB by its own rules (Pearl: permanent pool, cap 50) -> hand it over, no timed buff
            if(holder->owner&&holder->owner->receiveCB){
                holder->owner->receiveCB(value);
                return;
            }
            ptr->buffNote["EMC CB Id"] += 1;
            string name = "EMC CB " + to_string((int)ptr->getBuffNote("EMC CB Id"));
            buffSingle(holder,{{Stats::CERTIFIED_BANGER,AType::NONE,value}},name,cbDuration);
            grantedCB->push_back({holder,name,value});
        };

        // Talent: after an attack -> fixed 10 Energy + 3 Punchline
        function<void()> talent = [ptr]() {
            increaseEnergy(ptr,0,10);
            genPunchLine(ptr,3);
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr,talent]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"EMC BA",
            [ptr,talent](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
                talent();
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        // Skill: 60% ATK AoE (toughness 20) · self +20 CB (A6 +2 per stack) · with CB: +30% Elation AoE using the team's highest CB
        function<void()> skill = [ptr,talent,grantCB]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"EMC Skill",
            [ptr,talent,grantCB](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                attack(act);

                grantCB(ptr,20 + 2*ptr->getBuffNote("EMC A6"));
                ptr->setBuffNote("EMC A6",0);
                if(ptr->eidolon>=1)ptr->setBuffNote("EMC E1",min(3.0,ptr->getBuffNote("EMC E1") + 1));

                if(ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0){
                    shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"EMC Skill Elation",
                    [ptr](shared_ptr<AllyAttackAction> &elDmg){
                        double best = 0;
                        for(auto &each : charList)best = max(best,each->statsType[Stats::CERTIFIED_BANGER][AType::NONE]);
                        double extra = best - ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE];
                        ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] += extra;
                        attack(elDmg);
                        ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] -= extra;
                    });
                    elDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,30),
                        DmgSrc(DmgSrcType::ELATION,30),
                        DmgSrc(DmgSrcType::ELATION,30)
                    );
                    elDmg->turnReset = 0;
                    elDmg->actionFunction(elDmg);
                }
                talent();
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,60,20),
                DmgSrc(DmgSrcType::ATK,60,20),
                DmgSrc(DmgSrcType::ATK,60,20)
            );
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,ba,skill]() {
            if(sp>spSafety)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        // Ult: +5 Punchline · target CD +50% 3 turns (E2 Elation +12% 2 turns)
        // target has an Elation Skill -> +10 CB (E1 +2 per stack) and casts it now with a fixed 20 Punchline · else advance 50%
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [grantCB](CharUnit *ptr) {
            AllyUnit *target = chooseAllyBuff(ptr);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"EMC Ult",
            [ptr,target,grantCB](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("EMC");
                genPunchLine(ptr,5);
                buffSingle(target,{{Stats::CD,AType::NONE,50}},"EMC Ult",3);
                if(ptr->eidolon>=2)buffSingle(target,{{Stats::ELATION,AType::NONE,12}},"EMC E2",2);
                genSkillPoint(ptr,1); // A4

                bool hasElationSkill = false;
                for(TriggerByYourSelfFunc &e : elationSkillList){
                    if(e.owner==target->owner)hasElationSkill = true;
                }
                if(hasElationSkill){
                    grantCB(target,10 + 2*ptr->getBuffNote("EMC E1"));
                    elationSkillTrigger(20,{target->owner->getName()});
                }
                else actionForward(target->atvStats.get(),50);
                ptr->setBuffNote("EMC E1",0);
            });
            act->addBuffSingleTarget(target);
            act->addToActionBar();
            dealDamage();
        }));

        // Elation Skill: 8 × 20% Elation bounces + 60% Elation split among all enemies (toughness 20) · Energy 5
        elationSkillList.push_back(TriggerByYourSelfFunc(PARTICIPANT_ID, ptr, [talent](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,"EMC Elation Skill",
            [ptr,talent](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,5);
                if(ptr->eidolon>=4)debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,10}},"EMC E4",2);
                if(ptr->eidolon>=6)buffSingle(ptr,{{Stats::CD,AType::NONE,100}},"EMC E6",3);
                attack(act);
                talent();
            });
            act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,20),8);
            double each = 60.0/max(1,totalEnemy);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,each,20),
                DmgSrc(DmgSrcType::ELATION,each,20),
                DmgSrc(DmgSrcType::ELATION,each,20)
            );
            act->addToAhaInstant();
        }));

        // A6: +1 stack per Elation Skill used by any ally
        //   Aha Instant: every entry of elationSkillList fires once -> + list size (counted once in afterAhaInstant)
        //   outside Aha (elationSkillTrigger, e.g. EMC Ult / Evanescia E1): one attack event per trigger -> +1
        //   "EMC In Aha" keeps the Aha's own attack event from being counted twice
        beforeAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setBuffCheck("EMC In Aha",1);
        }));
        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setBuffCheck("EMC In Aha",0);
            ptr->buffNote["EMC A6"] += elationSkillList.size();
        }));
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(ptr->getBuffCheck("EMC In Aha"))return;
            for(AType each : act->actionTypeList){
                if(each!=AType::ELATION_SKILL)continue;
                ptr->buffNote["EMC A6"] += 1;
                return;
            }
        }));

        // Technique: all allies Elation +20% for 3 turns at battle start
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(!ptr->technique)return;
            buffAllAlly({{Stats::ELATION,AType::NONE,20}},"EMC Technique",3);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [grantedCB](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&isDebuffEnd(enemy,"EMC E4")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-10}});
            }
            if(!ally)return;
            if(isBuffEnd(ally,"EMC Ult"))buffSingle(ally,{{Stats::CD,AType::NONE,-50}});
            if(isBuffEnd(ally,"EMC E2"))buffSingle(ally,{{Stats::ELATION,AType::NONE,-12}});
            if(isBuffEnd(ally,"EMC Technique"))buffSingle(ally,{{Stats::ELATION,AType::NONE,-20}});
            if(isBuffEnd(ally,"EMC E6"))buffSingle(ally,{{Stats::CD,AType::NONE,-100}});
            for(auto itr = grantedCB->begin(); itr != grantedCB->end(); ){
                if(itr->holder!=ally||!isBuffEnd(ally,itr->name)){ itr++; continue; }
                buffSingle(ally,{{Stats::CERTIFIED_BANGER,AType::NONE,-itr->value}});
                itr = grantedCB->erase(itr);
            }
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [grantedCB](CharUnit *ptr) {
            grantedCB->clear();
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::CD][AType::NONE] += 13.3;

            ptr->statsType[Stats::CR][AType::NONE] += 15; // A4
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            statsAdjust(ptr,Stats::ATK_P);
        }));

        // A2: Elation +10% per 200 ATK above 1000, max +60%
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            if(statsType!=Stats::ATK_P&&statsType!=Stats::FLAT_ATK)return;
            double atk = calculateAtkOnStats(ptr);
            double buffValue = min(60.0,max(0.0,floor((atk - 1000)/200)*10));
            buffSingle(ptr,{{Stats::ELATION,AType::NONE,buffValue - ptr->getBuffNote("EMC A2")}});
            ptr->setBuffNote("EMC A2",buffValue);
        }));

    }
}
