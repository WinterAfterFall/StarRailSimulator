#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Ninja_Record(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "Ninja_Record";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 9 + 3 * superimpose;
            }));
    
            Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr,superimpose](AllyUnit *Healer, AllyUnit *target, double Value) {
                if (!target->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get())) return; 
                if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Ninja_Record_Buff",2)) {
                    ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::CD, AType::None, 13.5 + 4.5 * superimpose}});
                }
            }));
    
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr,superimpose](Unit *Trigger, AllyUnit *target, double Value) {
                if (!target->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get())) return; 
                if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Ninja_Record_Buff",2)) {
                    ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::CD, AType::None, 13.5 + 4.5 * superimpose}});
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Ninja_Record_Buff")) {
                    ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::CD, AType::None, -(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }
}
