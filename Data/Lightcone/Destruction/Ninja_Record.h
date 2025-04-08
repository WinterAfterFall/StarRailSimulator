
#ifndef Ninja_Record_H
#define Ninja_Record_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Ninja_Record(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,476,265);
            ptr->Light_cone.Name = "Ninja_Record";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT][AT_NONE] += 9 + 3 * superimpose;
            }));
    
            Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr,superimpose](Sub_Unit *Healer, Sub_Unit *target, double Value) {
                if (!target->isSameUnit(ptr->Sub_Unit_ptr[0].get())) return;
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ninja_Record_Buff")) {
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_CRIT_DAM, AT_NONE, 13.5 + 4.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Ninja_Record_Buff", 2);
            }));
    
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr,superimpose](Unit *Trigger, Sub_Unit *target, double Value) {
                if (!target->isSameUnit(ptr->Sub_Unit_ptr[0].get())) return;
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ninja_Record_Buff")) {
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_CRIT_DAM, AT_NONE, 13.5 + 4.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Ninja_Record_Buff", 2);
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Ninja_Record_Buff")) {
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_CRIT_DAM, AT_NONE, -(13.5 + 4.5 * superimpose));
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 0;
                }
            }));
        };
    }
}
#endif