
#ifndef The_Wondrous_H
#define The_Wondrous_H


#include "../Library.h"
namespace Planar{
    void The_Wondrous_BananAmusement_Park(Ally *ptr);
    void The_Wondrous_BananAmusement_Park(Ally *ptr){
        
        ptr->Planar.Name="The_Wondrous_BananAmusement_Park"; 
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 16;
        }
        ));
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            if(ptr->Summon_ptr.size()!=0||ptr->Sub_Unit_ptr.size()>1){
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 32;

            }
        }
        ));
       
    }
}
#endif