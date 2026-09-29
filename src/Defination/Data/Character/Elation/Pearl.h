#include "../include.h"

// Pearl — kit: docs/kit-reference/Character/Elation/pearl.md (nanoka 4.5.54) · scales on DEF
// Simplifications:
//   Her Certified Banger is one permanent pool (cap 50): Skill / Ult / A4 / Technique and her Aha CB all go into it
//   Talent ≤50% HP DMG reduction = Stats::DMG_REDUCE on the ally (incoming-DMG formula)
//   Talent Repellency = the engine's team pool `repellency` (1 CB = 200) + Stats::BLOCK 60 on every ally;
//   blocked DMG is spent from the pool and her CB drops to match (pool / 200)
//   not modeled: A4 Effect RES / debuff dispel, E1 fatal-hit save
//   Deep Learning Elation DMG is "calculated with the Archetype's stats" -> the Archetype is the attacker (DMG is credited to them)
//   Elation Skill bonus hits the main target
namespace Pearl{
    constexpr int PARTICIPANT_ID = 104;
    const string ARCHETYPE = "Pearl Archetype";

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(99,180,180,eidolon,ElementType::ICE,Path::ELATION,"Pearl",UnitType::STANDARD);
        ptr->setAllyBaseStats(1203,466,728);

        //substats
        ptr->pushSubstats(Stats::DEF_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::DEF_P,Stats::ER);

        elationCount++;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Helper

        // Talent: her Certified Banger lasts indefinitely, cap 50 · every point is also 200 Repellency in the team pool
        function<void(double)> gainCB = [ptr](double value) {
            double add = min(value,50 - ptr->getBuffNote("Pearl CB"));
            if(add<=0)return;
            ptr->buffNote["Pearl CB"] += add;
            buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,add}});
            repellency += add*200;
        };

        // CB granted by other characters (e.g. EMC Ult) goes into the same permanent pool
        ptr->receiveCB = gainCB;

        // Repellency spent by decreaseBlock -> her CB follows the pool (pool / 200)
        function<void()> syncRepellency = [ptr]() {
            double cb = repellency/200;
            double delta = cb - ptr->getBuffNote("Pearl CB");
            if(delta>=0)return;
            ptr->buffNote["Pearl CB"] += delta;
            buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,delta}});
        };

        function<bool()> holdCB = [ptr]() {
            return ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0;
        };

        // heal all allies (DEF% + flat) and the lowest-HP% ally the same amount again
        function<void(double,double)> teamHeal = [ptr](double defRatio,double flat) {
            AllyUnit *lowest = nullptr;
            double lowestRatio = 1e9;
            for(auto &each : allyList){
                if(!each->isTargetable()||each->totalHP<=0)continue;
                double ratio = each->currentHP/each->totalHP;
                if(ratio<lowestRatio){ lowestRatio = ratio; lowest = each; }
            }
            if(!lowest)return;
            ptr->restoreHP(lowest,
                HealSrc(HealSrcType::DEF,defRatio*2,HealSrcType::CONST,flat*2),
                HealSrc(HealSrcType::DEF,defRatio,HealSrcType::CONST,flat));
        };

        function<AllyUnit*()> archetype = [ptr]() {
            return ptr->getBuffSubUnitTarget(ARCHETYPE);
        };

        // Deep Learning on/off · E6: all allies RES PEN +20% while active
        function<void(AllyUnit*,int)> startDeepLearning = [ptr](AllyUnit *target,int charges) {
            ptr->setBuffSubUnitTarget(ARCHETYPE,target);
            ptr->setBuffNote("Pearl DL Charges",charges);
            if(ptr->eidolon>=6&&!ptr->getBuffCheck("Pearl E6")){
                ptr->setBuffCheck("Pearl E6",1);
                buffAllAlly({{Stats::RESPEN,AType::NONE,20}});
            }
        };

        function<void()> endDeepLearning = [ptr]() {
            ptr->setBuffSubUnitTarget(ARCHETYPE,nullptr);
            ptr->setBuffNote("Pearl DL Charges",0);
            if(ptr->getBuffCheck("Pearl E6")){
                ptr->setBuffCheck("Pearl E6",0);
                buffAllAlly({{Stats::RESPEN,AType::NONE,-20}});
            }
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Pearl BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::DEF,90,10)
            );
            act->addToActionBar();
        };

        // Enhanced BA (Deep Learning): 100% DEF AoE (toughness 10) · heal 8% DEF + 160 (lowest again)
        //   Starry Night (Archetype is Elation) + holding CB: +15% Ice Elation (Pearl)
        //   then 60% Ice Elation AoE with the Archetype's stats (E6 +240%) · uses 1 Charge, ends at 0
        function<void()> eba = [ptr,holdCB,teamHeal,archetype,endDeepLearning]() {
            AllyUnit *arch = archetype();
            bool starry = arch&&arch->owner->path==Path::ELATION;
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::AOE,starry ? "Pearl Starry Night" : "Pearl Great Wave",
            [ptr,arch,starry,holdCB,teamHeal,endDeepLearning](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,30);
                attack(act);
                teamHeal(8,160);
                if(starry&&holdCB()){
                    shared_ptr<AllyAttackAction> cbDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"Pearl Starry Night Elation");
                    cbDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,15),
                        DmgSrc(DmgSrcType::ELATION,15),
                        DmgSrc(DmgSrcType::ELATION,15)
                    );
                    cbDmg->turnReset = 0;
                    attack(cbDmg);
                }
                if(arch){
                    shared_ptr<AllyAttackAction> dlDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,arch,TraceType::AOE,"Pearl Deep Learning Elation");
                    dlDmg->damageElement = ElementType::ICE;
                    dlDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,60),
                        DmgSrc(DmgSrcType::ELATION,60),
                        DmgSrc(DmgSrcType::ELATION,60)
                    );
                    if(ptr->eidolon>=6)dlDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,240),
                        DmgSrc(DmgSrcType::ELATION,240),
                        DmgSrc(DmgSrcType::ELATION,240)
                    );
                    dlDmg->turnReset = 0;
                    attack(dlDmg);
                }
                ptr->buffNote["Pearl DL Charges"] -= 1;
                if(ptr->getBuffNote("Pearl DL Charges")<=0)endDeepLearning();
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::DEF,100,10),
                DmgSrc(DmgSrcType::DEF,100,10),
                DmgSrc(DmgSrcType::DEF,100,10)
            );
            act->addToActionBar();
        };

        // Skill: +15 CB · heal 12% DEF + 240 (lowest again)
        function<void()> skill = [ptr,gainCB,teamHeal]() {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::AOE,"Pearl Skill",
            [ptr,gainCB,teamHeal](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                gainCB(15);
                teamHeal(12,240);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,ba,eba,skill]() {
            if(ptr->getBuffNote("Pearl DL Charges")>0)eba();
            else if(sp>spSafety)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        // Ult: +20 CB · Deep Learning (3 Charges) on 1 other ally = Aesthetic Archetype
        //   advance 10 / 15 / 30% by Elation count (E2: other Elation allies too) · 4+ Elation: 1 extra turn
        //   with +30 CB / +60 Punchline (E2 ×2) removed when it ends · A6 flag
        // the Archetype's extra turn: its last queued action (the extra turn ends after it)
        shared_ptr<AllyActionData*> extraLast = make_shared<AllyActionData*>(nullptr);

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [gainCB,startDeepLearning,extraLast](CharUnit *ptr) {
            CharUnit *target = chooseCharacterBuff(ptr);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"Pearl Ult",
            [ptr,target,gainCB,startDeepLearning,extraLast](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Pearl");
                gainCB(20);
                if(!target||target==ptr)return;
                startDeepLearning(target,3);
                ptr->setBuffCheck("Pearl A6",target->path==Path::ELATION);

                double advance = (elationCount>=3) ? 30 : (elationCount==2) ? 15 : 10;
                actionForward(target->atvStats.get(),advance);
                if(ptr->eidolon>=2){
                    for(auto &each : charList){
                        if(each==ptr||each==target||each->path!=Path::ELATION)continue;
                        actionForward(each->atvStats.get(),advance);
                    }
                }
                if(elationCount<4)return;

                // extra turn = the Archetype's turn function runs now; its actions do not reset ATV (no turnCnt +1)
                double cb = (ptr->eidolon>=2) ? 60 : 30;
                int pl = (ptr->eidolon>=2) ? 120 : 60;
                buffSingle(target,{{Stats::CERTIFIED_BANGER,AType::NONE,cb}});
                genPunchLine(target,pl);
                ptr->setBuffNote("Pearl Extra CB",cb);
                ptr->setBuffNote("Pearl Extra PL",pl);

                size_t before = actionBar.size();
                target->turnFunc();
                shared_ptr<AllyActionData> last = nullptr;
                for(size_t i = 0, n = actionBar.size(); i < n; i++){
                    shared_ptr<ActionData> each = actionBar.front();
                    actionBar.pop();
                    if(i>=before){
                        if(auto ally = dynamic_pointer_cast<AllyActionData>(each)){
                            ally->turnReset = false;
                            last = ally;
                        }
                    }
                    actionBar.push(each);
                }
                ptr->setBuffSubUnitTarget("Pearl Extra Owner",target);
                *extraLast = last.get();
                if(!last){
                    // nothing was queued -> remove at once
                    buffSingle(target,{{Stats::CERTIFIED_BANGER,AType::NONE,-cb}});
                    genPunchLine(nullptr,-min(pl,punchline));
                }
            });
            act->addBuffSingleTarget(target);
            act->addToActionBar();
            dealDamage();
        }));

        // extra turn ends after its last queued action -> remove the extra CB / Punchline
        afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,extraLast](shared_ptr<AllyActionData> &act) {
            if(!*extraLast||act.get()!=*extraLast)return;
            *extraLast = nullptr;
            AllyUnit *owner = ptr->getBuffSubUnitTarget("Pearl Extra Owner");
            if(owner)buffSingle(owner,{{Stats::CERTIFIED_BANGER,AType::NONE,-ptr->getBuffNote("Pearl Extra CB")}});
            genPunchLine(nullptr,-min((int)ptr->getBuffNote("Pearl Extra PL"),punchline));
        }));

        // Talent: an ally at <= 50% HP takes 30% less DMG -> DMG_REDUCE on that ally, re-checked whenever their HP changes
        function<void(AllyUnit*)> updateLowHp = [](AllyUnit *ally) {
            if(!ally||ally->totalHP<=0)return;
            bool low = ally->currentHP<=ally->totalHP*0.5;
            if(low==(bool)ally->getBuffCheck("Pearl Talent"))return;
            ally->setBuffCheck("Pearl Talent",low);
            buffSingle(ally,{{Stats::DMG_REDUCE,AType::NONE,low ? 30.0 : -30.0}});
        };
        hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [updateLowHp,syncRepellency](Unit *trigger, AllyUnit *target, double value) {
            syncRepellency();
            updateLowHp(target);
        }));
        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [updateLowHp](AllyUnit *healer, AllyUnit *target, double value) {
            updateLowHp(target);
        }));

        // A6: the Elation Archetype's next Ultimate -> Pearl fixed 90 Energy (does not stack)
        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr](CharUnit *ally) {
            if(!ptr->getBuffCheck("Pearl A6"))return;
            AllyUnit *arch = ptr->getBuffSubUnitTarget(ARCHETYPE);
            if(!arch||ally!=arch->owner)return;
            ptr->setBuffCheck("Pearl A6",0);
            increaseEnergy(ptr,0,90);
        }));

        // Elation Skill: all allies' next attack adds 10 / 15 / 20 / 40% Elation DMG of their own Type (E4 ×2) · Energy 5
        elationSkillList.push_back(TriggerByYourSelfFunc(PARTICIPANT_ID, ptr, [](CharUnit *ptr) {
            CharCmd::printText("Pearl Elation Skill");
            increaseEnergy(ptr,5);
            for(auto &each : allyList)each->setBuffCheck("Pearl Elation Bonus",1);
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(act->attacker!=act->attackSetList[0].attacker)return;
            if(!act->attacker->getBuffCheck("Pearl Elation Bonus"))return;
            act->attacker->setBuffCheck("Pearl Elation Bonus",0);
            double ratio = (elationCount>=4) ? 40 : (elationCount==3) ? 20 : (elationCount==2) ? 15 : 10;
            if(ptr->eidolon>=4)ratio *= 2;
            shared_ptr<AllyAttackAction> bonus = make_shared<AllyAttackAction>(AType::ELATION_DMG,act->attacker,TraceType::SINGLE,"Pearl Elation Bonus");
            bonus->addDamageIns(DmgSrc(DmgSrcType::ELATION,ratio),enemyUnit[mainEnemyNum].get());
            bonus->turnReset = 0;
            attack(bonus);
        }));

        // Aha Certified Banger -> into her permanent pool (take it out of the engine's expiring CB list)
        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB](CharUnit *ptr) {
            if(cbCheck.empty())return;
            auto &entry = cbCheck.back();
            string name = std::get<0>(entry);
            if(!ptr->getBuffCheck(name))return;
            double pl = std::get<2>(entry);
            buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,-pl}});
            ptr->buffCheck[name] = 0;
            ptr->buffEnd[name] = 0;
            std::get<1>(entry)--;
            gainCB(pl);
        }));

        // A4: at the start of each ally's turn +5 CB (at most 50 per Pearl-turn cycle, resets at Pearl's turn)
        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(ally==ptr)ptr->setBuffNote("Pearl A4 Gained",0);
            double add = min(5.0,50 - ptr->getBuffNote("Pearl A4 Gained"));
            if(add<=0)return;
            ptr->buffNote["Pearl A4 Gained"] += add;
            gainCB(add);
        }));

        // Technique: at battle start +20 CB and Deep Learning (2 Charges) on the Archetype
        // also moves the engine's starting 20 CB ("CB Buff") into her permanent pool
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB,startDeepLearning](CharUnit *ptr) {
            if(ptr->getBuffCheck("CB Buff")){
                buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,-20}});
                ptr->buffCheck["CB Buff"] = 0;
                ptr->buffEnd["CB Buff"] = 0;
                gainCB(20);
            }
            if(!ptr->technique)return;
            gainCB(20);
            CharUnit *target = chooseCharacterBuff(ptr);
            if(target&&target!=ptr)startDeepLearning(target,2);
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [extraLast](CharUnit *ptr) {
            *extraLast = nullptr;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 22.5;
            ptr->statsType[Stats::ELATION][AType::NONE] += 10;
            ptr->atvStats->flatSpeed += 9;
            // Effect RES +10% (not used by the sim)
        }));

        // E1: all allies Elation +10 / 20 / 60% with 2 / 3 / 4+ Elation characters · E2: all allies Elation DMG merrymake +15%
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=1){
                double value = (elationCount>=4) ? 60 : (elationCount==3) ? 20 : (elationCount==2) ? 10 : 0;
                if(value>0)buffAllAlly({{Stats::ELATION,AType::NONE,value}});
            }
            if(ptr->eidolon>=2)buffAllAlly({{Stats::MERRYMAKE,AType::NONE,15}});
            // Talent: Repellency blocks 60% of the DMG any ally takes
            buffAllAlly({{Stats::BLOCK,AType::NONE,60}});
            statsAdjust(ptr,Stats::DEF_P);
        }));

        // A2: DEF >= 2400 -> Elation +32%, +3% per 100 DEF above (max 3600 excess) · Outgoing Healing + 20% of her Elation
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            if(statsType==Stats::DEF_P||statsType==Stats::FLAT_DEF){
                double def = calculateDefOnStats(ptr);
                double buffValue = (def>=2400) ? 32 + 3*floor(min(3600.0,def - 2400)/100) : 0;
                buffSingle(ptr,{{Stats::ELATION,AType::NONE,buffValue - ptr->getBuffNote("Pearl A2")}});
                ptr->setBuffNote("Pearl A2",buffValue);
            }
            if(statsType==Stats::ELATION){
                double heal = 0.2*calculateElationOnStats(ptr);
                buffSingle(ptr,{{Stats::HEALING_OUT,AType::NONE,heal - ptr->getBuffNote("Pearl A2 Heal")}});
                ptr->setBuffNote("Pearl A2 Heal",heal);
            }
        }));

    }
}
