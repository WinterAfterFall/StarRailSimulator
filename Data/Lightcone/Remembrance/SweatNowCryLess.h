
#ifndef SweatNowCryLess_H
#define SweatNowCryLess_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> SweatNowCryLess(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,198);
            ptr->Light_cone.Name = "SweatNowCryLess";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 10 + 2 * superimpose;
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed > 0 && ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("SweatNowCryLess")) {
                    ptr->buffAlly({{ST_DMG, AT_NONE, 20.0 + superimpose * 4}});
                }
            }));
        };
    }
    
}
#endif