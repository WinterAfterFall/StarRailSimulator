
#ifndef Rutilant_H
#define Rutilant_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Rutilant(Ally *ptr);
    void Rutilant(Ally *ptr){
        
        ptr->Planar.Name = "Rutilant";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=8;
        }
        ));
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"]+=20;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Basic_Attack"]+=20;
        }
        ));
        
       
    }
}
#endif