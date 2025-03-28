
#ifndef Tribbie_LC_H
#define Tribbie_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void Tribbie_LC(Ally *ptr);
    void Tribbie_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1270,529,397);
        ptr->Light_cone.Name = "Tribbie_LC";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=36;

        }
        ));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            Increase_energy(ptr,21);
            ptr->Sub_Unit_ptr[0]->Buff_check["Presage"] = 1;
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Presage",2);
            Buff_All_Ally("Crit_dam","None",48);
        }
        ));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Presage")){
                ptr->Sub_Unit_ptr[0]->Buff_check["Presage"] = 0;
                Buff_All_Ally("Crit_dam","None",-48);
            }
        }
        ));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Fua"){
                Increase_energy(ptr,12);
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Presage")){
                    Buff_All_Ally("Crit_dam","None",48);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Presage"] = 1;
                }
            }

            
        }
        ));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Fua"){
                Increase_energy(ptr,12);
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Presage")){
                    Buff_All_Ally("Crit_dam","None",48);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Presage"] = 1;
                }
            }
        }
        ));
        
        ptr->Light_cone.Print_Func = [](Ally *ptr){
            
            cout<<endl;
            cout<<ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name<<"_LC : ";
            cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Presage"]<<" ";
        };
    }
}
#endif