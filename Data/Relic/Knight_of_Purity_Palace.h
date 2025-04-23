
#ifndef Knight_H
#define Knight_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Knight(Ally *ptr);
    void Knight(Ally *ptr){
        ptr->Relic.Name = "Knight";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE]+=15;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_SHEILD][AT_NONE]+=20;
        }));
        
    }
}
#endif