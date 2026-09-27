#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> FireFly_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,476,529);
            ptr->lightCone.name = "FireFly_LC";
            string debuffName = ptr->getName() + " FireFlyLC debuff";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,debuffName](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 50 + 10 * superimpose;
            }));
            
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameOwnerName(ptr)) return;
                for(Enemy* &e :act->targetList){
                    debuffSingleApply(ptr,e,{
                        {Stats::VUL,AType::BREAK,20.0 + 4 * superimpose},
                        {Stats::SPD_P,AType::NONE,-20.0}
                    },debuffName,2);
                } 
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,debuffName](CharUnit *ptr) {
                if (turn != nullptr && turn->side == Side::ENEMY) {
                    if (isDebuffEnd(enemyUnit[turn->num].get(),debuffName)) {
                        debuffSingle(enemyUnit[turn->num].get(),{
                            {Stats::VUL,AType::BREAK,-20.0 - 4 * superimpose},
                            {Stats::SPD_P,AType::NONE,20.0}
                        });
                    }
                }
            }));
        };
    }

}
