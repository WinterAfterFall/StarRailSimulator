#include "../include.h"
namespace Relic{
    void Captain(CharUnit *ptr){
        ptr->Relic.Name = "Captain";
        string help = ptr->getMemosprite()->getUnitName() + " help";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 16;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,help](Ally *ally){
            if (ally->isSameChar(ptr)) {
                if(ptr->getMemosprite()->getStack(help)>=2){
                    ptr->getMemosprite()->setStack(help,0);
                    ptr->getMemosprite()->buffSingle({{Stats::ATK_P,AType::None,48}},help,1);
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,help](shared_ptr<AllyBuffAction> &act) {
            for(auto &each : act->buffTargetList){
                if(each->isSameStatsOwnerName(ptr->getMemosprite())){
                    each->calStack(1,2,help);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,help]() {
            if(ptr->getMemosprite()->isBuffEnd(help)){
                ptr->getMemosprite()->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](AllyUnit* target) {
            if(target->isBuffGoneByDeath(help)){
                ptr->getMemosprite()->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        
    }
}