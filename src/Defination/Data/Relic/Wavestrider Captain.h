#include "../include.h"
namespace Relic{
    void Captain(CharUnit *ptr){
        ptr->Relic.Name = "Captain";
        string help = ptr->getUnitName() + " help";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 16;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,help](Ally *ally){
            if (ally->isSameChar(ptr)) {
                if(ptr->getStack(help)>=2){
                    ptr->setStack(help,0);
                    ptr->buffSingle({{Stats::ATK_P,AType::None,48}},help,1);
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,help](shared_ptr<AllyBuffAction> &act) {
            for(auto &each : act->buffTargetList){
                if(each->isSameStatsOwnerName(ptr)){
                    each->calStack(1,2,help);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,help]() {
            if(ptr->isBuffEnd(help)){
                ptr->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](AllyUnit* target) {
            if(target->isBuffGoneByDeath(help)){
                ptr->buffSingle({{Stats::ATK_P,AType::None,-48}});
            }
        }));


        
    }
}