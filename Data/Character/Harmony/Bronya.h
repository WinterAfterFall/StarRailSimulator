
#ifndef Bronya_H
#define Bronya_H

#define F first
#define S second
#include "../Library.h"

namespace Bronya{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    



//temp
    void Skill(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99,120,120,E,"Wind","Harmony","Bronya",TYPE_STD);
        ptr->SetAllyBaseStats(1242,582,534);
        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CRIT_DAM,ST_FLAT_SPD,ST_DMG_PERCENT,ST_EnergyRecharge);
        ptr->setSpeedRequire(133.4);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){            
            Skill(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(!ultUseCheck(ptr)) return;
            AllyActionData data_ = AllyActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff","Bronya Ult");
            data_.Add_Buff_All_Ally();
            data_.actionFunction = [ptr](AllyActionData &data_){
                for(auto e : data_.Target_Buff){
                    Extend_Buff_single_target(e,"Bronya_Ult",2);
                    double temp = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(),16)+20;
                    Buff_single_target(e,"Crit_dam",AT_TEMP,temp - e->Buff_note["Bronya_Ult"]);
                    Buff_single_target(e,"Crit_dam","None",temp - e->Buff_note["Bronya_Ult"]);
                    e->Buff_note["Bronya_Ult"] = temp;
                    if(e->Buff_check["Bronya_Ult"]) continue;
                    e->Buff_check["Bronya_Ult"] = 1;
                    Buff_single_target(e,"Atk%","None",55);
                }
                if(Ult_After_Turn == 0 && (turn->Side == "Memosprite" || turn->Side == "Ally")){
                    SubUnit *temp = dynamic_cast<SubUnit*>(turn->ptr_to_unit);
                    Extend_Buff_single_target(temp,"Bronya_Ult",1);
                }
                if(ptr->Print)CharCmd::printUltStart("Bronya");
            };
            
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 24;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Wind"]["None"] += 22.4;

            // relic

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Basic_Attack"] = 100;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                Buff_All_Ally("Atk%","None",15);
                Extend_Buff_All_Ally("Bronya_Technique",2);
            }
            Buff_All_Ally("Def%","None",20);
            Extend_Buff_All_Ally("Bronya_A4",2);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            SubUnit *tempstats = dynamic_cast<SubUnit*>(turn->ptr_to_unit);
            if(!tempstats) return;
            if(Buff_end(tempstats,"Bronya_Skill")){
                tempstats->Buff_check["Bronya_Skill"] = 0;
                Buff_single_target(tempstats,"Dmg%","None",-66);
            }
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Bronya_Skill_E1")){
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"] = 0;
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"] = 0;
            }
            if(Buff_end(tempstats,"Bronya_Skill_E2")){
                Speed_Buff(tempstats->Atv_stats.get(),-30,0);
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill_E2"] = 0;
            }
            if(Buff_end(tempstats,"Bronya_Ult")){
                Buff_single_target(tempstats,"Atk%","None",-55);
                Buff_single_target(tempstats,"Crit_dam",AT_TEMP,-tempstats->Buff_note["Bronya_Ult"]);
                Buff_single_target(tempstats,"Crit_dam","None",-tempstats->Buff_note["Bronya_Ult"]);
                tempstats->Buff_note["Bronya_Ult"] = 0;
                tempstats->Buff_check["Bronya_Ult"] = 0;
            }
            if(Buff_end(tempstats,"Bronya_A4")){
                Buff_single_target(tempstats,"Def%","None",-20);
            }
            if(Buff_end(tempstats,"Bronya_Technique")){
                Buff_single_target(tempstats,"Atk%","None",-15);
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(turn->Char_Name == "Bronya"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 0;
            }
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num != Driver_num) return;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            Buff_All_Ally("Dmg%","None",10);
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](AllyActionData &data_){
            if(data_.Action_type.second == "Basic_Attack" && data_.Attacker->Atv_stats->Char_Name == "Bronya"){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),30);
            }
            if(ptr->Eidolon >= 4 && data_.Action_type.second == "Basic_Attack" && data_.Attacker->Atv_stats->Char_Name != "Bronya" && ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] == 0){
                AllyActionData data_temp = AllyActionData();
                data_temp.Fua_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Bronya E4");
                data_temp.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
                data_temp.Damage_spilt.Main.push_back({80,0,0,10});
                Increase_energy(ptr,5);
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 1;
                data_temp.actionFunction = [ptr](AllyActionData &data_){
                    Increase_energy(ptr,5);
                    Attack(data_);
                };
                
                Action_bar.push(data_temp);
            }
        }));



        
    }


    
    void Skill(Ally *ptr){
        
        AllyActionData data_ = AllyActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Bronya Skill");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.actionFunction = [ptr](AllyActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);

            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),100);
            if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill")){
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill"] = 1;
                Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Dmg%","None",66);
            }
            if(ptr->Eidolon>=6){
                Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill",2);
            }else{
                Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill",1);
            }
            if(ptr->Eidolon>=2){
                if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill_E2")){
                    Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),30,0);
                    chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill_E2"] = 1;

                }
                Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill_E2",2);
            }
            if(ptr->Eidolon>=1){
                if(ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]==1&&ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"]==0){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Bronya_Skill_E1",1);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"]=1;

                }
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]++;
            }
        };
        
        
        Action_bar.push(data_);
    }




}
#endif