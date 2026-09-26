#include "../include.h"

namespace Huohuo{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(98,140,140,E,ElementType::Wind,Path::Abundance,"Huohuo",UnitType::Standard);
        ptr->SetAllyBaseStats(1358,601,509);

        //substats
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *hh = ptr;


        #pragma region Ability

        // Talent: gain/refresh "Divine Provision" (E1 +1 turn) · regaining resets the 6-trigger counter
        function<void(int)> gainDivineProvision = [ptr,hh](int turns) {
            if(isHaveToAddBuff(hh,"Divine Provision")){
                if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,12}});
            }
            hh->setStack("Divine Provision",6);
            if(ptr->Eidolon>=1)turns++;
            extendBuffTime(hh,"Divine Provision",turns);
        };

        // Talent: heal the acting ally + lowest HP% ally, then every ally at HP <= 50% · A6 energy +1
        function<void(AllyUnit*)> divineProvisionHeal = [hh](AllyUnit *ally) {
            if(!hh->getBuffCheck("Divine Provision")||!hh->getStack("Divine Provision"))return;
            hh->stack["Divine Provision"]--;
            Increase_energy(hh,1);
            AllyUnit *lowest = nullptr;
            for(auto &each : allyList){
                if(!each->isTargetable())continue;
                if(!lowest || each->currentHP/each->totalHP < lowest->currentHP/lowest->totalHP)lowest = each;
            }
            hh->RestoreHP(ally,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            if(lowest && lowest != ally)hh->RestoreHP(lowest,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            for(auto &each : allyList){
                if(each->isTargetable() && each->currentHP<=each->totalHP/2)
                    hh->RestoreHP(each,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            }
        };

        function<void()> BA = [ptr,hh]() {
            genSkillPoint(hh,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"HH BA",
            [hh](shared_ptr<AllyAttackAction> &act){
                Increase_energy(hh,20);
                Attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hh,gainDivineProvision]() {
            genSkillPoint(hh,-1);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Blast,"HH Skill",
            [ptr,hh,gainDivineProvision](shared_ptr<AllyBuffAction> &act){
                Increase_energy(hh,30);
                hh->RestoreHP(HealSrc(HealSrcType::HP,24,HealSrcType::CONST,640),
                HealSrc(HealSrcType::HP,19.2,HealSrcType::CONST,512),
                HealSrc());
                gainDivineProvision(3);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,hh,BA,Skill]() {
            if(hh->Atv_stats->turnCnt%3==0)Skill();
            else BA();
        };

        ptr->addUltCondition([ptr,hh]() -> bool {
            if(phaseStatus == PhaseStatus::BeforeTurn&&turn->isSameUnit(chooseAllyBuff(hh)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, ptr, [ptr,hh,gainDivineProvision]() {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"HH Ult",
            [ptr,hh,gainDivineProvision](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Huohuo");
                buffAllAlly({{Stats::ATK_P,AType::None,40}},"HH Ult",2);
                // A4: allies with Max Energy >= 160 gain extra ATK +24%
                for(auto &each : allyList){
                    if(each->owner->Max_energy>=160)buffSingle(each,{{Stats::ATK_P,AType::None,24}},"HH Ult A4",2);
                }
                // energy 20% of Max Energy to all allies except Huohuo (not per memosprite)
                for(auto &each : charList){
                    if(each == ptr)continue;
                    Increase_energy(each,20,0);
                }
                gainDivineProvision(3);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::HP_P][AType::None] += 28;
            ptr->Stats_type[Stats::RES][AType::None] += 18;
            ptr->Atv_stats->flatSpeed +=5;

            // relic

            // substats
            ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 40;

        }));

        // A2: energy 30 + Divine Provision 2 turns at battle start · Technique: all enemies ATK -25% 2 turns
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hh,gainDivineProvision]() {
            Increase_energy(hh,0,30);
            gainDivineProvision(2);
            if(ptr->Technique){
                for(auto &each : enemyList){
                    if(!debuffApply(hh,each,"HH Technique",2))continue;
                    each->atkPercent -= 25;
                }
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hh,divineProvisionHeal]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(hh,"Divine Provision")){
                hh->setStack("Divine Provision",0);
                if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,-12}});
            }
            divineProvisionHeal(ally);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(ally){
                if(isBuffEnd(ally,"HH Ult")){
                    buffSingle(ally,{{Stats::ATK_P,AType::None,-40}});
                }
                if(isBuffEnd(ally,"HH Ult A4")){
                    buffSingle(ally,{{Stats::ATK_P,AType::None,-24}});
                }
                if(isBuffEnd(ally,"HH E6")){
                    buffSingle(ally,{{Stats::DMG,AType::None,-50}});
                }
            }
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy && isDebuffEnd(enemy,"HH Technique")){
                enemy->atkPercent += 25;
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *target) {
            if(isBuffGoneByDeath(target,"HH Ult")){
                buffSingle(target,{{Stats::ATK_P,AType::None,-40}});
            }
            if(isBuffGoneByDeath(target,"HH Ult A4")){
                buffSingle(target,{{Stats::ATK_P,AType::None,-24}});
            }
            if(isBuffGoneByDeath(target,"HH E6")){
                buffSingle(target,{{Stats::DMG,AType::None,-50}});
            }
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [divineProvisionHeal](CharUnit *ally) {
            divineProvisionHeal(ally);
        }));

        if(ptr->Eidolon>=6)
        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,hh](AllyUnit *Healer, AllyUnit *target, double Value) {
            if(Healer->isSameName(hh)){
                buffSingle(target,{{Stats::DMG,AType::None,50}},"HH E6",2);
            }
        }));

    }
}
