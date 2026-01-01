#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> EyesOfThePrey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Eyes of the Prey";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 15 + superimpose * 5;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Dot] += 18 + superimpose * 6;
            }));
        };
    }
}