
#ifndef The_Day_The_Cosmos_Fell_H
#define The_Day_The_Cosmos_Fell_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void Cosmos_Fell(Ally *ptr);
    void Cosmos_Fell(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,476,331);
        ptr->Light_cone.Name = "Cosmos_Fell";

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=40;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=24;

        }
        ));
        
        
    }
}
#endif