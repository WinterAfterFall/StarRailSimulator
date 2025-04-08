
#ifndef Secret_Vow_NoBuff_H
#define Secret_Vow_NoBuff_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Secret_Vow_NoBuff(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,476,265);
            ptr->Light_cone.Name = "Secret_Vow";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG_PERCENT][AT_NONE] += 15 + 5 * superimpose;
            }));
        };
    }
}
#endif