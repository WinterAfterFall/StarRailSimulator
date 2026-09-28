#include "../include.h"

namespace Huohuo{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(98,140,140,eidolon,ElementType::WIND,Path::ABUNDANCE,"Huohuo",UnitType::STANDARD);
        ptr->setAllyBaseStats(1358,601,509);

        //substats
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *hh = ptr;


        #pragma region Ability

        // Talent: gain/refresh "Divine Provision" (E1 +1 turn) · regaining resets the 6-trigger counter
        function<void(int)> gainDivineProvision = [ptr,hh](int turns) {
            if(isHaveToAddBuff(hh,"Divine Provision")){
                if(ptr->eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::NONE,12}});
            }
            hh->setStack("Divine Provision",6);
            if(ptr->eidolon>=1)turns++;
            extendBuffTime(hh,"Divine Provision",turns);
        };

        // Talent: heal the acting ally + lowest HP% ally, then every ally at HP <= 50% · A6 energy +1
        function<void(AllyUnit*)> divineProvisionHeal = [hh](AllyUnit *ally) {
            if(!hh->getBuffCheck("Divine Provision")||!hh->getStack("Divine Provision"))return;
            hh->stack["Divine Provision"]--;
            increaseEnergy(hh,1);
            AllyUnit *lowest = nullptr;
            for(auto &each : allyList){
                if(!each->isTargetable())continue;
                if(!lowest || each->currentHP/each->totalHP < lowest->currentHP/lowest->totalHP)lowest = each;
            }
            hh->restoreHP(ally,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            if(lowest && lowest != ally)hh->restoreHP(lowest,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            for(auto &each : allyList){
                if(each->isTargetable() && each->currentHP<=each->totalHP/2)
                    hh->restoreHP(each,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            }
        };

        function<void()> ba = [ptr,hh]() {
            genSkillPoint(hh,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"HH BA",
            [hh](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(hh,20);
                attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
            act->addToActionBar();
        };

        function<void()> skill = [ptr,hh,gainDivineProvision]() {
            genSkillPoint(hh,-1);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::BLAST,"HH Skill",
            [ptr,hh,gainDivineProvision](shared_ptr<AllyBuffAction> &act){
                increaseEnergy(hh,30);
                hh->restoreHP(HealSrc(HealSrcType::HP,24,HealSrcType::CONST,640),
                HealSrc(HealSrcType::HP,19.2,HealSrcType::CONST,512),
                HealSrc());
                gainDivineProvision(3);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,hh,ba,skill]() {
            if(hh->atvStats->turnCnt%3==0)skill();
            else ba();
        };

        ptr->addUltCondition([ptr,hh]() -> bool {
            if(phaseStatus == PhaseStatus::BEFORE_TURN&&turn->isSameUnit(chooseAllyBuff(hh)))return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hh,gainDivineProvision](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"HH Ult",
            [ptr,hh,gainDivineProvision](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Huohuo");
                buffAllAlly({{Stats::ATK_P,AType::NONE,40}},"HH Ult",2);
                // A4: allies with Max Energy >= 160 gain extra ATK +24%
                for(auto &each : allyList){
                    if(each->owner->maxEnergy>=160)buffSingle(each,{{Stats::ATK_P,AType::NONE,24}},"HH Ult A4",2);
                }
                // energy 20% of Max Energy to all allies except Huohuo (not per memosprite)
                for(auto &each : charList){
                    if(each == ptr)continue;
                    increaseEnergy(each,20,0);
                }
                gainDivineProvision(3);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::HP_P][AType::NONE] += 28;
            ptr->statsType[Stats::RES][AType::NONE] += 18;
            ptr->atvStats->flatSpeed +=5;

            // relic

            // substats
            ptr->statsType[Stats::HEALING_OUT][AType::NONE] += 40;

        }));

        // A2: energy 30 + Divine Provision 2 turns at battle start · Technique: all enemies ATK -25% 2 turns
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hh,gainDivineProvision](CharUnit *ptr) {
            increaseEnergy(hh,0,30);
            gainDivineProvision(2);
            if(ptr->technique){
                for(auto &each : enemyList){
                    if(!debuffApply(hh,each,"HH Technique",2))continue;
                    each->statsType[Stats::ATK_REDUCE][AType::NONE] += 25;
                }
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hh,divineProvisionHeal](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(hh,"Divine Provision")){
                hh->setStack("Divine Provision",0);
                if(ptr->eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::NONE,-12}});
            }
            divineProvisionHeal(ally);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(ally){
                if(isBuffEnd(ally,"HH Ult")){
                    buffSingle(ally,{{Stats::ATK_P,AType::NONE,-40}});
                }
                if(isBuffEnd(ally,"HH Ult A4")){
                    buffSingle(ally,{{Stats::ATK_P,AType::NONE,-24}});
                }
                if(isBuffEnd(ally,"HH E6")){
                    buffSingle(ally,{{Stats::DMG,AType::NONE,-50}});
                }
            }
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy && isDebuffEnd(enemy,"HH Technique")){
                enemy->statsType[Stats::ATK_REDUCE][AType::NONE] -= 25;
            }
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *target) {
            if(isBuffGoneByDeath(target,"HH Ult")){
                buffSingle(target,{{Stats::ATK_P,AType::NONE,-40}});
            }
            if(isBuffGoneByDeath(target,"HH Ult A4")){
                buffSingle(target,{{Stats::ATK_P,AType::NONE,-24}});
            }
            if(isBuffGoneByDeath(target,"HH E6")){
                buffSingle(target,{{Stats::DMG,AType::NONE,-50}});
            }
        }));

        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [divineProvisionHeal](CharUnit *ally) {
            divineProvisionHeal(ally);
        }));

        if(ptr->eidolon>=6)
        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,hh](AllyUnit *healer, AllyUnit *target, double value) {
            if(healer->isSameName(hh)){
                buffSingle(target,{{Stats::DMG,AType::NONE,50}},"HH E6",2);
            }
        }));

    }
}
