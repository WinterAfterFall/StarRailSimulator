#include "../include.h"

namespace Huohuo{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(98,140,140,E,ElementType::Wind,Path::Abundance,"Huohuo",UnitType::Standard);
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

        SubUnit *hh = ptr->getSubUnit();

        
        #pragma region Ability

        function<void()> BA = [ptr,hh]() {
            Skill_point(hh,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"HH BA",
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
            make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Blast,"HH Skill",
            [ptr,hh](shared_ptr<AllyBuffAction> &act){
                Increase_energy(hh,30);
                hh->RestoreHP(HealSrc(HealSrcType::HP,21,HealSrcType::CONST,560),
                HealSrc(HealSrcType::HP,16.8,HealSrcType::CONST,448),
                HealSrc());
                if(hh->isHaveToAddBuff("Divine Provision")){
                    hh->setStack("Divine Provision",6);
                    if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,12}});
                }
                if(ptr->Eidolon>=1) hh->extendBuffTime("Divine Provision",3);
                else hh->extendBuffTime("Divine Provision",2);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,hh,BA,Skill]() {
            if(hh->Atv_stats->turnCnt%3==0)Skill();
            else BA();
        };
        
        ptr->addUltCondition([ptr,hh]() -> bool {
            if(phaseStatus == PhaseStatus::BeforeTurn&&turn->isSameChar(chooseSubUnitBuff(hh)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hh]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TraceType::Aoe,"HH Ult",
            [hh](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Huohuo");
                buffAllAlly({{Stats::ATK_P,AType::None,40}},"HH Ult",2);
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                        Increase_energy(each.get(),20,0);
                    }
                }
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed +=5;

            // relic

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 40;

        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hh]() {
            SubUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(hh->isBuffEnd("Divine Provision")){
                hh->setStack("Divine Provision",0);
                if(ptr->Eidolon>=1)buffAllAlly({{Stats::SPD_P,AType::None,-12}});
            }
            if(hh->getBuffCheck("Divine Provision")&&hh->getStack("Divine Provision")){
                hh->Stack["Divine Provision"]--;
                Increase_energy(hh,1);
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                        if(each->currentHP<=each->totalHP/2)
                        hh->RestoreHP(each.get(),HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
                    }
                }
                hh->RestoreHP(ally,HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));

            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            SubUnit *ally = turn->canCastToSubUnit();
            if(ally){
                if(ally->isBuffEnd("HH Ult")){
                    ally->buffSingle({{Stats::ATK_P,AType::None,-40}});
                }
                if(ally->isBuffEnd("HH E6")){
                    ally->buffSingle({{Stats::DMG,AType::None,-50}});
                }
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](SubUnit *target) {
            if(target->isBuffGoneByDeath("HH Ult")){
                    target->buffSingle({{Stats::ATK_P,AType::None,-40}});
            }
            if(target->isBuffGoneByDeath("HH E6")){
                    target->buffSingle({{Stats::DMG,AType::None,-50}});
            }
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [ptr,hh](Ally *ally) {
            if(hh->getBuffCheck("Divine Provision")&&hh->getStack("Divine Provision")){
                hh->Stack["Divine Provision"]--;
                Increase_energy(hh,1);
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                        if(each->currentHP<=each->totalHP/2)
                        hh->RestoreHP(each.get(),HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));
                    }
                }
                hh->RestoreHP(ally->getSubUnit(),HealSrc(HealSrcType::HP,4.5,HealSrcType::CONST,120));

            }
        }));

        if(ptr->Eidolon>=6)
        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,hh](SubUnit *Healer, SubUnit *target, double Value) {
            if(Healer->isSameUnit(hh)){
                target->buffSingle({{Stats::DMG,AType::None,50}},"HH E6",2);
            }
        }));

    }
}
