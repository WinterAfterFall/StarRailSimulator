#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Fermata(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Fermata";
            shared_ptr<vector<Enemy*>> buffedTargets = make_shared<vector<Enemy*>>();
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::BE][AType::None] += 12 + superimpose * 4;
            }));

            BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffedTargets](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameOwnerName(ptr)){
                    for(auto &each : act->targetList ){
                        if(each->ShockCount||each->WindSheerCount){
                            debuffSingle(each,{{Stats::DMG,AType::None,12.0 + superimpose * 4}});
                            buffedTargets->push_back(each);
                        }
                    }
                }
            }));

            AfterAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffedTargets](shared_ptr<AllyAttackAction> &act) {
                if(!act->isSameOwnerName(ptr))return;
                for(auto &each : *buffedTargets){
                    debuffSingle(each,{{Stats::DMG,AType::None,-(12.0 + superimpose * 4)}});
                }
                buffedTargets->clear();
            }));

        };
    }
}