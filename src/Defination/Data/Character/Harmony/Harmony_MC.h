#include "../include.h"

namespace Harmony_MC{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);  
    void Skill_func(CharUnit *ptr);

    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit* ptr = SetCharBasicStats( 105, 140, 140, E, ElementType::Imaginary, Path::Harmony, "Harmony_MC",UnitType::Standard);
        AllyUnit *HMCptr = ptr;
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
        ptr->Turn_func = [ptr](){
            if(sp > Sp_Safety || ptr->Atv_stats->turnCnt == 1){
                Skill_func(ptr);           
            } else {
                Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"HMC Ult",
            [ptr,HMCptr](shared_ptr<AllyBuffAction> &act){
                if(isHaveToAddBuff(HMCptr,"Harmony_MC_ult",3))
                buffAllAlly({{Stats::BE,AType::None,33}});
            });
            act->addBuffAllAllies();

            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Stats_type[Stats::BE][AType::None] += 37.3;
            ptr->Stats_type[Stats::RES][AType::None] += 10;
            ptr->Stats_each_element[Stats::DMG][ElementType::Imaginary][AType::None] += 14.4;

            // relic

            // substats
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,HMCptr](){
            ptr->Buff_note["Harmony_MC_E4"] = calculateBreakEffectForBuff(ptr, 15);                  
            buffAllAllyExcludingBuffer(HMCptr,{{Stats::BE,AType::TEMP,ptr->Buff_note["Harmony_MC_E4"]}});
            buffAllAllyExcludingBuffer(HMCptr,{{Stats::BE,AType::None,ptr->Buff_note["Harmony_MC_E4"]}});
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                buffAllAlly({{Stats::BE,AType::None,30}});
            }
            ptr->Energy_recharge += 25;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(isBuffEnd(HMCptr,"Harmony_MC_ult")){
                buffAllAlly({{Stats::BE,AType::None,-33}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(turn->UnitName == "Harmony_MC" && turn->turnCnt == 3){
                ptr->Energy_recharge -= 25;
            }
            if(turn->side == Side::Ally || turn->side == Side::AllyUnit){
                if(turn->turnCnt == 2 && ptr->Technique == 1){
                    buffSingle(charUnit[turn->num].get(),{{Stats::BE,AType::None,-30}});
                }
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            if(ptr->Buff_check["Harmony_MC_ult"] == 1){
                Superbreak_trigger(act, 100 * (1.7 - (0.1 * Total_enemy)),"HMC");
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *Breaker){
            Increase_energy(ptr, 11);
            Action_forward(target->Atv_stats.get(), -30);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,HMCptr](AllyUnit *target, Stats StatsType){
            if(target->Atv_stats->StatsOwnerName != "Harmony_MC") return;
            if(StatsType == Stats::BE){
                double temp = calculateBreakEffectForBuff(ptr, 15);
                buffAllAllyExcludingBuffer(HMCptr,{{Stats::BE,AType::TEMP,temp - ptr->Buff_note["Harmony_MC_E4"]}});
                buffAllAllyExcludingBuffer(HMCptr,{{Stats::BE,AType::None,temp - ptr->Buff_note["Harmony_MC_E4"]}});
                ptr->Buff_note["Harmony_MC_E4"] =  temp ;
            }
        }));
 
    }



void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"HMC BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10));
        act->addToActionBar();
    }
    void Skill_func(CharUnit *ptr){
        if(ptr->Atv_stats->turnCnt!=1)Skill_point(ptr,-1);     
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Bounce,"RMC Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,10));
        act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,55,5),6);
        act->addToActionBar();
    }




}