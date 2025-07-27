#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> FireFly_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "FireFly_LC";
            string debuffName = ptr->getSubUnit()->getUnitName() + " FireFlyLC debuff";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 50 + 10 * superimpose;
            }));
            
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->num != ptr->Sub_Unit_ptr[0]->Atv_stats->num && act->Attacker->Atv_stats->Side != "Ally") return;
                for(Enemy* &e :act->targetList){
                    e->debuffSingleApply({
                        {Stats::VUL,AType::Break,20.0 + 4 * superimpose},
                        {Stats::SPD_P,AType::None,-20.0}
                    },ptr->Sub_Unit_ptr[0].get(),debuffName,2);
                } 
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName]() {
                if (turn != nullptr && turn->Side == "Enemy") {
                    if (Enemy_unit[turn->num]->isDebuffEnd(debuffName)) {
                        Enemy_unit[turn->num]->debuffSingle({
                            {Stats::VUL,AType::Break,-20.0 - 4 * superimpose},
                            {Stats::SPD_P,AType::None,20.0}
                        });
                    }
                }
            }));
        };
    }

}
