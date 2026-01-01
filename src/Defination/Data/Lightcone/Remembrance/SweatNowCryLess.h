#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> SweatNowCryLess(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,198);
            ptr->Light_cone.Name = "SweatNowCryLess";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CR][AType::None] += 10 + 2 * superimpose;
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (!ptr->memospriteList[0]->isDeath()&& ptr->isHaveToAddBuff("SweatNowCryLess")) {
                    ptr->buffSingleChar({{Stats::DMG, AType::None, 20.0 + superimpose * 4}});
                }
            }));
        };
    }
    
}