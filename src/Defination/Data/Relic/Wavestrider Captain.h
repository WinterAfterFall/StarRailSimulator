#include "../include.h"
namespace Relic{
    void Captain(Ally *ptr){
        ptr->Relic.Name = "Captain";
        string help = ptr->getSubUnit()->getUnitName() + " help";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 16;
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,help](shared_ptr<AllyActionData> &act){
            if (act->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                if(ptr->getSubUnit()->getStack(help)>=2){
                    ptr->getSubUnit()->setStack(help,0);
                    ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,48}},help,1);
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,help](shared_ptr<AllyBuffAction> &act) {
            for(auto &each : act->buffTargetList){
                if(each->isSameUnit(ptr->getSubUnit())){
                    each->calStack(1,2,help);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,help]() {
            if(ptr->getSubUnit()->isBuffEnd(help)){
                ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,-48}});
            }
        }));


        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](SubUnit* target) {
            if(target->isBuffGoneByDeath(help)){
                ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,-48}});
            }
        }));


        
    }
}