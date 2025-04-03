
#ifndef Castorice_LC_H
#define Castorice_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    void Castorice_LC(Ally *ptr);
    void Castorice_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1270,529,397);
        ptr->Light_cone.Name = "Castorice_LC";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 30;
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](Sub_Unit* target) {
            if (target->Atv_stats->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num
            &&target->Atv_stats->Side=="Memosprite"
            &&ptr->getSubUnit()->getBuffCheck("Castorice_LC_check")==0){
                Action_forward(ptr->getSubUnit()->Atv_stats.get(),12);
                ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",1);
            }
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name 
                && data_.Action_type.second == "Ultimate") {
                ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
            }
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name 
                && data_.Action_type.second == "Ultimate") {
                ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
            }
        }));
        
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr](Unit *Trigger, Sub_Unit *target, double Value) {
            if(!turn)return;
            if((turn->Side=="Memosprite"||turn->Side=="Ally")
            &&turn->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num
            &&target->Atv_stats->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num){
                if(!ptr->getSubUnit()->getBuffCheck("Death Flower"))
                Buff_single_with_all_memo(ptr,ST_DEF_SHRED,AT_NONE,30);
                ptr->getSubUnit()->setBuffCheck("Death Flower",1);
                Extend_Buff_single_target(ptr->getSubUnit(),"Death Flower",2);
            }
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(Buff_end(ptr->getSubUnit(),"Death Flower")){
                ptr->getSubUnit()->setBuffCheck("Death Flower",0);
                Buff_single_with_all_memo(ptr,ST_DEF_SHRED,AT_NONE,-30);
            }
        }));
    }
    
}
#endif