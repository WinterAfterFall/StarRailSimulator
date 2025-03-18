
#ifndef Himeko_LC_H
#define Himeko_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void Himeko_LC(Ally *ptr);
    void Himeko_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1164,582,397);
        ptr->Light_cone.Name = "Himeko_LC";

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=9*Total_enemy;
           
        }
        ));
        
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Himeko_LC_buff")){
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"]-=30;
                ptr->Sub_Unit_ptr[0]->Buff_check["Himeko_LC_buff"] = 0; 
            }
        }
        ));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr,Enemy *target,Sub_Unit *Breaker){
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Himeko_LC_buff")){
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"]+=30;
                ptr->Sub_Unit_ptr[0]->Buff_check["Himeko_LC_buff"] = 1; 
            }
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Himeko_LC_buff",1);
        }
        ));
        
        
    }
}
#endif