
#ifndef Broken_Keel_H
#define Broken_Keel_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Broken_Keel(Ally *ptr);
    void Broken_Keel(Ally *ptr){
        ptr->Planar.Name="Broken_Keel";
        
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            Buff_All_Ally("Crit_dam","None",10);
        }
        ));
    }
}
#endif