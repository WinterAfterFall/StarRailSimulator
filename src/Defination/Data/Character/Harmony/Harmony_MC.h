#include "../include.h"

namespace Harmony_MC{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally* ptr = SetAllyBasicStats( 105, 140, 140, E, ElementType::Imaginary, Path::Harmony, "Harmony_MC",UnitType::Standard);
        SubUnit *HMCptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1087, 446, 679);
        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){
            if(sp > Sp_Safety || ptr->Sub_Unit_ptr[0]->Atv_stats->turnCnt == 1){
                Skill_func(ptr);           
            } else {
                Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TT_AOE,"HMC Ult",
            [ptr,HMCptr](shared_ptr<AllyBuffAction> &act){
                if(HMCptr->isHaveToAddBuff("Harmony_MC_ult",3))
                buffAllAlly({{Stats::BE,AType::None,33}});
            });
            act->addBuffAllAllies();

            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Imaginary][AType::None] += 14.4;

            // relic

            // substats
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,HMCptr](){
            ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);                  
            HMCptr->buffAllAllyExcludingBuffer({{Stats::BE,AType::TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
            HMCptr->buffAllAllyExcludingBuffer({{Stats::BE,AType::None,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                buffAllAlly({{Stats::BE,AType::None,30}});
            }
            ptr->Energy_recharge += 25;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(HMCptr->isBuffEnd("Harmony_MC_ult")){
                buffAllAlly({{Stats::BE,AType::None,-33}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(turn->Char_Name == "Harmony_MC" && turn->turnCnt == 3){
                ptr->Energy_recharge -= 25;
            }
            if(turn->side == Side::Ally || turn->side == Side::Memosprite){
                if(turn->turnCnt == 2 && ptr->Technique == 1){
                    Ally_unit[turn->num]->Sub_Unit_ptr[0]->buffSingle({{Stats::BE,AType::None,-30}});
                }
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"] == 1){
                Superbreak_trigger(act, 100 * (1.7 - (0.1 * Total_enemy)),"HMC");
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Breaker){
            Increase_energy(ptr, 11);
            Action_forward(target->Atv_stats.get(), -30);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,HMCptr](SubUnit *target, Stats StatsType){
            if(target->Atv_stats->Unit_Name != "Harmony_MC") return;
            if(StatsType == Stats::BE){
                double temp = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);
                HMCptr->buffAllAllyExcludingBuffer({{Stats::BE,AType::TEMP,temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
                HMCptr->buffAllAllyExcludingBuffer({{Stats::BE,AType::None,temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] =  temp ;
            }
        }));
 
    }



void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"HMC BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10));
        act->addToActionBar();
    }
    void Skill_func(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_BOUNCE,"RMC Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turnCnt!=1)Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);     
            Increase_energy(ptr,30);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,10));
        act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,55,5),6);
        act->addToActionBar();
    }




}