#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Ninja_Record(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,476,265);
            ptr->lightCone.name = "Ninja Record";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::HP_P][AType::NONE] += 9 + 3 * superimpose;
            }));
    
            healingList.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr,superimpose](AllyUnit *healer, AllyUnit *target, double value) {
                if (!target->isSameName(ptr)) return; 
                if (isHaveToAddBuff(ptr,"Ninja_Record_Buff",2)) {
                    buffSingle(ptr,{{Stats::CD, AType::NONE, 13.5 + 4.5 * superimpose}});
                }
            }));
    
            hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr,superimpose](Unit *trigger, AllyUnit *target, double value) {
                if (!target->isSameName(ptr)) return; 
                if (isHaveToAddBuff(ptr,"Ninja_Record_Buff",2)) {
                    buffSingle(ptr,{{Stats::CD, AType::NONE, 13.5 + 4.5 * superimpose}});
                }
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Ninja_Record_Buff")) {
                    buffSingle(ptr,{{Stats::CD, AType::NONE, -(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }
}
