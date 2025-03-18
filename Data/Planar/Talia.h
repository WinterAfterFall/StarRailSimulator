
#ifndef Talia_H
#define Talia_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Talia(Ally *ptr);
    void Talia(Ally *ptr){
        
        ptr->Planar.Name = "Talia";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 16;
        }
        ));
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 20;
        }
        ));
        
       
    }
}
#endif