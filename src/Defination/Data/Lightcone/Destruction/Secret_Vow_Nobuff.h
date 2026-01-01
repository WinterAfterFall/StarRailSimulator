#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Secret_Vow_NoBuff(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "Secret_Vow";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::DMG][AType::None] += 15 + 5 * superimpose;
            }));
        };
    }
}