
#ifndef Ninja_Record_H
#define Ninja_Record_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    void Ninja_Record(Ally *ptr);
    void Ninja_Record(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,476,265);
        ptr->Light_cone.Name = "Ninja_Record";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT][AT_NONE]+=24;
            
            }
        ));
        Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK,ptr,[](Ally *ptr,Sub_Unit *Healer,Sub_Unit *target,double Value){
            if(!target->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Ninja_Record_Buff")){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,36);
                ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 1;
            }
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Ninja_Record_Buff",2);
        }));
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,ptr,[](Ally *ptr,Unit *Trigger,Sub_Unit *target,double Value){
            if(!target->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Ninja_Record_Buff")){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,36);
                ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 1;
            }
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Ninja_Record_Buff",2);
        }));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,ptr,[](Ally *ptr){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Ninja_Record_Buff")){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,-36);
                ptr->Sub_Unit_ptr[0]->Buff_check["Ninja_Record_Buff"] = 0;
            }
        }));


    }
}
#endif