#include "../include.h"
namespace Relic{
    void Eagle_Beaked_Helmet(CharUnit *ptr){
        ptr->Relic.Name = "Eagle_Beaked_Helmet";
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->Atv_stats->atv<=ptr->Atv_stats->Max_atv*0.25)return false;
            return true;
        });

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 10;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr](CharUnit *ally){
            if (ally->isSameChar(ptr)) {
                Action_forward(ptr->Atv_stats.get(), 25);
            }
        }));
        
    }
    
}