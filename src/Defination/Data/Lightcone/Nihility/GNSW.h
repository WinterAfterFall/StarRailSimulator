#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> GNSW(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "GNSW";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::DMG][AType::None] += (9 + (3 * superimpose)) * 3;
            }));
        };
    }
}