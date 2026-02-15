#include "../include.h"
namespace Relic{
    void Captain(CharUnit *ptr){
        ptr->Relic.Name = "Captain";
        string help = ptr->getName() + " help";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 16;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,help](CharUnit *ally){
            if (ally->isSameOwner(ptr)) {
                if(ptr->getStack(help)>=2){
                    ptr->setStack(help,0);
                    buffSingle(ptr,{{Stats::ATK_P,AType::None,48}},help,1);
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,help](shared_ptr<AllyBuffAction> &act) {
            for(auto &each : act->buffTargetList){
                if(each->isSameName(ptr)){
                    calStack(each,1,2,help);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,help]() {
            if(isBuffEnd(ptr,help)){
                buffSingle(ptr,{{Stats::ATK_P,AType::None,-48}});
            }
        }));


        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](AllyUnit* target) {
            if(isBuffGoneByDeath(target,help)){
                buffSingle(ptr,{{Stats::ATK_P,AType::None,-48}});
            }
        }));


        
    }
}