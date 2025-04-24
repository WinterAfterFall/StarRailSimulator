
#ifndef SpaceSealing_H
#define SpaceSealing_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void SpaceSealing(Ally *ptr){
        
        ptr->Planar.Name = "SpaceSealing";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AT_NONE] += 24;
        }));
        
       
    }
}
#endif