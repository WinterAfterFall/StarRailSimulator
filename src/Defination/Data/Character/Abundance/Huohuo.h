#include "../include.h"

namespace Huohuo{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(98,140,140,E,ElementType::Wind,Path::Abundance,"Huohuo",UnitType::Standard);
        ptr->SetAllyBaseStats(1358,602,509);

        //substats
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *hh = ptr;

        
        #pragma region Ability

        function<void()> BA = [ptr,hh]() {
            Skill_point(hh,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"HH BA",
            [hh](shared_ptr<AllyAttackAction> &act){
                Increase_energy(hh,20);
                Attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hh]() {
            Skill_point(hh,-1);
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Blast,"HH Skill",
            [ptr,hh](shared_ptr<AllyBuffAction> &act){
                Increase_energy(hh,30);
                hh->RestoreHP(HealSrc(HealSrcType::HP,21,HealSrcType::CONST,560),
                HealSrc(HealSrcType::HP,16.8,HealSrcType::CONST,448),
                HealSrc());
                if(isHaveToAddBuff(hh,"Divine Provision")){
                    hh->setStack("Divine Provision",6);
                    if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,12}});
                }
                if(ptr->Eidolon>=1) extendBuffTime(hh,"Divine Provision",3);
                else extendBuffTime(hh,"Divine Provision",2);
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
            if(phaseStatus == PhaseStatus::BeforeTurn&&turn->isSameUnit(chooseSubUnitBuff(hh)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hh]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"HH Ult",
            [hh](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Huohuo");
                buffAllAlly({{Stats::ATK_P,AType::None,40}},"HH Ult",2);
                for(auto &each : allyList){
                    Increase_energy(each,20,0);
                }
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

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hh]() {
            AllyUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(isBuffEnd(hh,"Divine Provision")){
                hh->setStack("Divine Provision",0);
                if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,-12}});
            }
            if(hh->getBuffCheck("Divine Provision")&&hh->getStack("Divine Provision")){
                hh->Stack["Divine Provision"]--;
                Increase_energy(hh,1);
                for(auto &each : allyList){
                    if(each->currentHP<=each->totalHP/2)
                        hh->RestoreHP(each,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
                }
                hh->RestoreHP(ally,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToSubUnit();
            if(ally){
                if(isBuffEnd(ally,"HH Ult")){
                    buffSingle(ally,{{Stats::ATK_P,AType::None,-40}});
                }
                if(isBuffEnd(ally,"HH E6")){
                    buffSingle(ally,{{Stats::DMG,AType::None,-50}});
                }
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *target) {
            if(isBuffGoneByDeath(target,"HH Ult")){
                buffSingle(target,{{Stats::ATK_P,AType::None,-40}});
            }
            if(isBuffGoneByDeath(target,"HH E6")){
                buffSingle(target,{{Stats::DMG,AType::None,-50}});
            }
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [ptr,hh](CharUnit *ally) {
            if(hh->getBuffCheck("Divine Provision")&&hh->getStack("Divine Provision")){
                hh->Stack["Divine Provision"]--;
                Increase_energy(hh,1);
                for(auto &each : allyList){
                    if(each->currentHP<=each->totalHP/2)
                    hh->RestoreHP(each,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
                }
                hh->RestoreHP(ally,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));

            }
        }));

        if(ptr->Eidolon>=6)
        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,hh](AllyUnit *Healer, AllyUnit *target, double Value) {
            if(Healer->isSameName(hh)){
                buffSingle(target,{{Stats::DMG,AType::None,50}},"HH E6",2);
            }
        }));

    }
}
