#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Tribbie_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1270,529,397);
            ptr->lightCone.name = "Tribbie_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 30 + 6 * superimpose;
            }));
    
            startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                increaseEnergy(ptr, 21);
                if(isHaveToAddBuff(ptr,"Presage",2)){
                    buffAllAlly({{Stats::CD, AType::NONE, (36.0 + 12 * superimpose)}});
                }
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Presage")) {
                    buffAllAlly({{Stats::CD, AType::NONE, -(36.0 + 12 * superimpose)}});
                }
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::FUA)) {
                    increaseEnergy(ptr, 12);
                    if(isHaveToAddBuff(ptr,"Presage",2)){
                        buffAllAlly({{Stats::CD, AType::NONE, (36.0 + 12 * superimpose)}});
                    }
                }
            }));

        };
    }
}
