
#ifndef Harmony_MC_H
#define Harmony_MC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Harmony_MC{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally* ptr = SetAllyBasicStats( 105, 140, 140, E, "Imaginary", "Harmony", "Harmony_MC",TYPE_STD);
        SubUnit *HMCptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1087, 446, 679);
        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){
            if(sp > Sp_Safety || ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt == 1){
                Skill_func(ptr);           
            } else {
                Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(!ultUseCheck(ptr)) return;
            
            
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->setUltimate(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Buff", "HMC Ultimate");
            data_->Add_Buff_All_Ally();
            data_->actionFunction = [ptr,HMCptr](shared_ptr<AllyActionData> &data_){
                if(HMCptr->isHaveToAddBuff("Harmony_MC_ult",3))
                buffAllAlly({{ST_BE,AT_NONE,33}});
            };

            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Imaginary"][AT_NONE] += 14.4;

            // relic

            // substats
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,HMCptr](){
            ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);                  
            HMCptr->buffAllAllyExcludingBuffer({{ST_BE,AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
            HMCptr->buffAllAllyExcludingBuffer({{ST_BE,AT_NONE,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                buffAllAlly({{ST_BE,AT_NONE,30}});
            }
            ptr->Energy_recharge += 25;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,HMCptr](){
            if(HMCptr->isBuffEnd("Harmony_MC_ult")){
                buffAllAlly({{ST_BE,AT_NONE,-33}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(turn->Char_Name == "Harmony_MC" && turn->turn_cnt == 3){
                ptr->Energy_recharge -= 25;
            }
            if(turn->Side == "Ally" || turn->Side == "Memosprite"){
                if(turn->turn_cnt == 2 && ptr->Technique == 1){
                    Ally_unit[turn->Unit_num]->Sub_Unit_ptr[0]->buffSingle({{ST_BE,AT_NONE,-30}});
                }
            }
        }));

        After_attack_List.push_back(TriggerByAllyAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyActionData> &data_){
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"] == 1){
                Superbreak_trigger(data_, 100 * (1.7 - (0.1 * Total_enemy)));
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Breaker){
            Increase_energy(ptr, 11);
            Action_forward(target->Atv_stats.get(), -30);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,HMCptr](SubUnit *target, string StatsType){
            if(target->Atv_stats->Unit_Name != "Harmony_MC") return;
            if(StatsType == ST_BE){
                double temp = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);
                HMCptr->buffAllAllyExcludingBuffer({{ST_BE,AT_TEMP,temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
                HMCptr->buffAllAllyExcludingBuffer({{ST_BE,AT_NONE,temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] =  temp ;
            }
        }));
 
    }



void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setBasicAttack(ptr->Sub_Unit_ptr[0].get(),"Single_target","HMC BasicAttack");
        data_->addEnemyTarget(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({110,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill_func(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[0].get(),"Bounce","HMC Skill");
        data_->addEnemyAdjacentTarget();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({55,0,0,10});
        data_->Damage_spilt.Main.push_back({55,0,0,5});
        data_->Damage_spilt.Main.push_back({55,0,0,5});
        
        if(Total_enemy==1){
            data_->Damage_spilt.Main.push_back({55,0,0,5});
            data_->Damage_spilt.Main.push_back({55,0,0,5});
            data_->Damage_spilt.Main.push_back({55,0,0,5});
            data_->Damage_spilt.Main.push_back({55,0,0,5});
        }else if(Total_enemy==2){
            data_->Damage_spilt.Main.push_back({55,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({55,0,0,5});
        }else if(Total_enemy>=3){
            data_->Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({55,0,0,5});
        }
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt!=1)Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);     
            Increase_energy(ptr,30);
            Attack(data_);
        };
        
        Action_bar.push(data_);
    }




}
#endif
