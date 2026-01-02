#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Anaxa_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Anaxa_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::DMG][AType::None] += 50 + 10*superimpose;
            }));

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr,10);
            }));

            When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                for(auto &each : act->targetList){
                    debuffSingleApply(each,{{Stats::DEF_SHRED,AType::None,(9.0 + superimpose * 3.0)}},ptr,"AnaxaLC_Debuff",2);
                }
            }));

            
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"AnaxaLC_Debuff")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-(9.0 + superimpose * 3.0)}});
                }
            }));
        };
    }
}