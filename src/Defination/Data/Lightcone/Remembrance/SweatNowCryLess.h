#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> SweatNowCryLess(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,198);
            ptr->Light_cone.Name = "SweatNowCryLess";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AType::None] += 10 + 2 * superimpose;
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (!ptr->Sub_Unit_ptr[1]->isDeath()&& ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("SweatNowCryLess")) {
                    ptr->buffAlly({{ST_DMG, AType::None, 20.0 + superimpose * 4}});
                }
            }));
        };
    }
    
}