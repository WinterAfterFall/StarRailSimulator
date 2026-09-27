#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Fugue_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Fugue_LC";
            string charring = ptr->getName() + " Charring";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,charring](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 50 + 10 * superimpose;
            }));
    
            toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,charring](Enemy *target, AllyUnit *breaker) {
                debuffStackSingle(ptr,target,{{Stats::VUL,AType::BREAK,15.0 + 3 * superimpose}},1,2,charring,2);
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,charring](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if (isDebuffEnd(enemy,charring)) {
                    debuffStackRemove(enemy,{{Stats::VUL,AType::BREAK,15.0 + 3 * superimpose}},charring);
                }
            }));
        };
    }
}