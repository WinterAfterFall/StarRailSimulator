#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> MushyShroomy(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(847,476,397);
            ptr->Light_cone.Name = "Mushy Shroomy's Adventures";
            string debuffName = ptr->getName() +  " MushyShroomy Debuff";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::Elation][AType::None] += 10 + superimpose * 2;
            }));


            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](shared_ptr<AllyActionData> &act) {
                if(act->isSameAction(ptr,AType::ElationSkill)){
                    debuffAllEnemyApply(ptr,{{Stats::VUL,AType::ElationDMG,5.0 + superimpose}},debuffName);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName]() {
                Enemy* enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,debuffName)){
                    debuffSingle(enemy,{{Stats::VUL,AType::ElationDMG,-5.0 - superimpose}});
                }
            }));

        };
    }
}
