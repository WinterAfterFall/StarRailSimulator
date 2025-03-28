
#ifndef Rappa_LC_H
#define Rappa_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void Rappa_LC(Ally *ptr);
    void Rappa_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,582,529);
        ptr->Light_cone.Name = "Rappa_LC";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=60;
           
        }
        ));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            Increase_energy(ptr,30);

        }
        ));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            if(data_.Action_type.second=="Ultimate"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Ration"]=1;
                ptr->Sub_Unit_ptr[0]->Stack["Ration"]=0;

            }

        }
        ));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            if(data_.Action_type.second=="Ultimate"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Ration"]=1;
                ptr->Sub_Unit_ptr[0]->Stack["Ration"]=0;
            }
        }
        ));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            if(data_.Action_type.second=="Basic_Attack"&&ptr->Sub_Unit_ptr[0]->Buff_check["Ration"]==1){
                ptr->Sub_Unit_ptr[0]->Stack["Ration"]++;
                if(ptr->Sub_Unit_ptr[0]->Stack["Ration"]==2){
                    Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),50);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ration"]=0;
                }
            }
        }
        ));

        
        
    }
}
#endif