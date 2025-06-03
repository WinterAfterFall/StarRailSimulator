#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> GreatCosmic(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "GreatCosmic";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += (6 + superimpose * 2);
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += (3+superimpose)*7;
            }));
    
            // After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &act) {

            // }));
        };
    }
}