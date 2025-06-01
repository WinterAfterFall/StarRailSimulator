
#ifndef Eagle_Beaked_Helmet_H
#define Eagle_Beaked_Helmet_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Eagle_Beaked_Helmet(Ally *ptr){
        ptr->Relic.Name = "Eagle_Beaked_Helmet";
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->getSubUnit()->Atv_stats->atv<=ptr->getSubUnit()->Atv_stats->Max_atv*0.25)return false;
            return true;
        });

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Wind"][AT_NONE] += 10;
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr](shared_ptr<AllyActionData> &data_){
            if (data_->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 25);
            }
        }));
        
    }
    
}
#endif