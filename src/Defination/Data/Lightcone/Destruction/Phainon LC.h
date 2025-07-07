#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Phainon_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,687,397);
            ptr->Light_cone.Name = "Phainon_LC";
            ptr->getSubUnit()->Atv_stats->baseSpeed += 10 + superimpose * 2;
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AT_NONE] += 13.5 + 4.5 * superimpose;
            }));
    
            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                    ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,42.0 + 18.0 * superimpose}},"Blazing Sun",1);
                }
            }));

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Blazing Sun")) {
                    ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-(42.0 + 18.0 * superimpose)}});
                }
            }));
        };
    }
}
