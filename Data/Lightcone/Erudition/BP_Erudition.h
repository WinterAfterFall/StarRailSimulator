
#ifndef BP_Erudition_H
#define BP_Erudition_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void BP_Erudition(Ally *ptr);
    void BP_Erudition(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),847,529,331);
        ptr->Light_cone.Name = "BP_Erudition";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            if(ptr->Max_energy>160){
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"]+=64;
            }else{
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"]+=ptr->Max_energy*0.4;
            }
           
        }
        ));
        
        
    }
}
#endif