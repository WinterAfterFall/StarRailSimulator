#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Hertashop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,397);
            ptr->lightCone.name = "Fall of an Aeon";
    
            whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr,superimpose]
                (shared_ptr<AllyAttackAction> &act) {
                if(act->isSameOwnerName(ptr))
                buffStackSingle(ptr,{{Stats::ATK_P,AType::NONE,6.0+superimpose*2.0}},1,4,"Aeon Atk");
            }));
    
            toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_ACTTACK, [ptr,superimpose](Enemy *target, AllyUnit *trigger) {
                if(!trigger->isSameNum(ptr))return;
                buffSingle(ptr,{{Stats::DMG,AType::NONE,9.0 + 3 * superimpose}},"Aeon Dmg%",2);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Aeon Dmg%")) {
                buffSingle(ptr,{{Stats::DMG,AType::NONE,-(9.0 + 3 * superimpose)}});
                }
            }));
    
        };
    }
}
