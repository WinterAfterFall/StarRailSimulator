#include "../include.h"
namespace Relic{
    void Captain(Ally *ptr){
        ptr->Relic.Name = "Captain";
        string help = ptr->getSubUnit()->getUnitName() + " help";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 16;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,help](Ally *ally){
            if (ally->isSameAlly(ptr)) {
                if(ptr->getSubUnit()->getStack(help)>=2){
                    ptr->getSubUnit()->setStack(help,0);
                    ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,48}},help,1);
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
                ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](SubUnit* target) {
            if(target->isBuffGoneByDeath(help)){
                ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        
    }
}