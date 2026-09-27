#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Fermata(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Fermata";
            shared_ptr<vector<Enemy*>> buffedTargets = make_shared<vector<Enemy*>>();
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 12 + superimpose * 4;
            }));

            beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffedTargets](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameOwnerName(ptr)){
                    for(auto &each : act->targetList ){
                        if(each->shockCount||each->windSheerCount){
                            debuffSingle(each,{{Stats::DMG,AType::NONE,12.0 + superimpose * 4}});
                            buffedTargets->push_back(each);
                        }
                    }
                }
            }));

            afterAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffedTargets](shared_ptr<AllyAttackAction> &act) {
                if(!act->isSameOwnerName(ptr))return;
                for(auto &each : *buffedTargets){
                    debuffSingle(each,{{Stats::DMG,AType::NONE,-(12.0 + superimpose * 4)}});
                }
                buffedTargets->clear();
            }));

        };
    }
}