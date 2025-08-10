#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Fermata(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Fermata";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 12 + superimpose * 4;
            }));

            BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameUnit(ptr->getSubUnit())){
                    for(auto &each : act->targetList ){
                        if(each->ShockCount||each->WindSheerCount){
                            each->debuffSingle({{Stats::Mitigration,AType::None,12.0 + superimpose * 4}});
                        }
                    }
                }
            }));

            AfterAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameUnit(ptr->getSubUnit())){
                    for(auto &each : act->targetList ){
                        if(each->ShockCount||each->WindSheerCount){
                            each->debuffSingle({{Stats::Mitigration,AType::None,-(12.0 + superimpose * 4)}});
                        }
                    }
                }
            }));

        };
    }
}