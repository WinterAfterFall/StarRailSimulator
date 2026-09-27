#include "../include.h"
namespace Relic{
    void Captain(CharUnit *ptr){
        ptr->Relic.name = "Captain";
        string help = ptr->getName() + " help";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 16;
        }));

        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,help](CharUnit *ally){
            if (ally->isSameOwner(ptr)) {
                if(ptr->getStack(help)>=2){
                    ptr->setStack(help,0);
                    buffSingle(ptr,{{Stats::ATK_P,AType::NONE,48}},help,1);
                }
            }
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,help](shared_ptr<AllyBuffAction> &act) {
            if(act->isSameName(ptr))return;
            for(auto &each : act->buffTargetList){
                if(each->isSameName(ptr)){
                    calStack(each,1,2,help);
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [help](CharUnit *ptr) {
            if(isBuffEnd(ptr,help)){
                buffSingle(ptr,{{Stats::ATK_P,AType::NONE,-48}});
            }
        }));


        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,help](AllyUnit* target) {
            if(isBuffGoneByDeath(target,help)){
                buffSingle(ptr,{{Stats::ATK_P,AType::NONE,-48}});
            }
        }));


        
    }
}