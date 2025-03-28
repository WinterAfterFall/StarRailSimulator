
#ifndef Robin_LC_H
#define Robin_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void Robin_LC(Ally *ptr);
    void Robin_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,635,463);
        ptr->Light_cone.Name = "Robin_LC";
        
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            if(ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]<5){
                ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]++;
                ptr->Energy_recharge+=3;
            }
        }
        ));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                ptr->Energy_recharge-=ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]*3;
                ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]=0;
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Cadenza")){
                    Buff_All_Ally("Dmg%","None",24);
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Atk%","None",48);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Cadenza",1);
            }

            
        }
        ));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                ptr->Energy_recharge-=ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]*3;
                ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]=0;
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Cadenza")){
                    Buff_All_Ally("Dmg%","None",24);
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Atk%","None",48);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Cadenza",1);
            }
        }
        ));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Cadenza")){
                Buff_All_Ally("Dmg%","None",-24);
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Atk%","None",-48);
                ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 0;
            }
        }
        ));

        // ptr->Light_cone.Print_Func = [](Ally *ptr){
            
        //     cout<<endl;
        //     cout<<ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name<<"_LC : ";
        //     cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Presage"]<<" ";
        // };
    }
}
#endif