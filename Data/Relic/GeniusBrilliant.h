
#ifndef GeniusBrilliant_H
#define GeniusBrilliant_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void GeniusBrilliant(Ally *ptr){
        ptr->Relic.Name = "GeniusBrilliant";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ET_QT][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AT_NONE] += 20;
        }));
        
        
    }
    
}
#endif