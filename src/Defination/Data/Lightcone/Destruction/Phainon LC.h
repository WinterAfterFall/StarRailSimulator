#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Phainon_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,687,397);
            ptr->Light_cone.Name = "Phainon_LC";
            ptr->getSubUnit()->Atv_stats->baseSpeed += 10 + superimpose * 2;
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::None] += 13.5 + 4.5 * superimpose;
            }));
    
            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameAlly(ptr)) {
                    ptr->getSubUnit()->buffSingle({{Stats::DMG,AType::None,42.0 + 18.0 * superimpose}},"Blazing Sun",1);
                }
            }));

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Blazing Sun")) {
                    ptr->getSubUnit()->buffSingle({{Stats::DMG,AType::None,-(42.0 + 18.0 * superimpose)}});
                }
            }));
        };
    }
}
