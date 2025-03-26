
#ifndef Blade_LC_H
#define Blade_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    void Blade_LC(Ally *ptr);
    void Blade_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1270,582,331);
        ptr->Light_cone.Name = "Blade_LC";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_NONE]+=18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT][AT_NONE]+=18;
            
            }
        ));
        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,ptr,[](Ally *ptr,Enemy *Attacker,vector<Sub_Unit*> target){
            for(Sub_Unit* e : target){
                if(e->isSameUnit(ptr->Sub_Unit_ptr[0].get())){
                    if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Blade_LC_Mark")){
                        Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,24);
                        ptr->Sub_Unit_ptr[0]->Buff_check["Blade_LC_Mark"] = 1;
                    }
                    return;
                }
            }
        }));
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,ptr,[](Ally *ptr,Unit *Trigger,Sub_Unit *target,double Value){
            if(!target->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Blade_LC_Mark")){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,24);
                ptr->Sub_Unit_ptr[0]->Buff_check["Blade_LC_Mark"] = 1;
            }
            
        }));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr,Combat_data &data_){
            if(!data_.Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Blade_LC_Mark")){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,-24);
                ptr->Sub_Unit_ptr[0]->Buff_check["Blade_LC_Mark"] = 0;
            }
        }));
    }
}
#endif