#include "../include.h"
namespace Relic{
    void Eagle_Beaked_Helmet(Ally *ptr){
        ptr->Relic.Name = "Eagle_Beaked_Helmet";
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->getSubUnit()->Atv_stats->atv<=ptr->getSubUnit()->Atv_stats->Max_atv*0.25)return false;
            return true;
        });

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Wind][AType::None] += 10;
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr](shared_ptr<AllyActionData> &act){
            if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 25);
            }
        }));
        
    }
    
}