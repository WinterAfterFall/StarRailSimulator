#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> GreatCosmic(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "GreatCosmic";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += (6 + superimpose * 2);
                ptr->Stats_type[Stats::DMG][AType::None] += (3+superimpose)*7;
            }));
    
            // After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &act) {

            // }));
        };
    }
}