
#ifndef Iron_Cavalry_H
#define Iron_Cavalry_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Iron_Cavalry(Ally *ptr);
    void Iron_Cavalry(Ally *ptr){
        ptr->Relic.Name = "Iron_Cavalry";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=16;
        }
        ));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Def_shred"]["Break_dmg"]+=10;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def_shred"]["Super_break"]+=15;

        }
        ));

        
    }
}
#endif