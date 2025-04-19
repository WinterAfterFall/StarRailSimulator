
#ifndef Castorice_LC_H
#define Castorice_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Castorice_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1270,529,397);
            ptr->Light_cone.Name = "Castorice_LC";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 22 + 8*superimpose;
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, superimpose](SubUnit* target) {
                if (target->Atv_stats->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num
                &&target->Atv_stats->Side=="Memosprite"
                &&ptr->getSubUnit()->getBuffCheck("Castorice_LC_check")==0){
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),9+3*superimpose);
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",1);
                }
            }));

            Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name 
                    && data_->Action_type.second == "Ultimate") {
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
                }
            }));

            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name 
                    && data_->Action_type.second == "Ultimate") {
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
                }
            }));
            
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr, superimpose](Unit *Trigger, SubUnit *target, double Value) {
                if(!turn)return;
                if((turn->Side=="Memosprite"||turn->Side=="Ally")
                &&turn->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num
                &&target->Atv_stats->Unit_num==ptr->getSubUnit()->Atv_stats->Unit_num){
                    if(!ptr->getSubUnit()->getBuffCheck("Death Flower"))
                    Buff_single_with_all_memo(ptr,ST_DEF_SHRED,AT_NONE,25 + 5 * superimpose);
                    ptr->getSubUnit()->setBuffCheck("Death Flower",1);
                    Extend_Buff_single_target(ptr->getSubUnit(),"Death Flower",2);
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                if(Buff_end(ptr->getSubUnit(),"Death Flower")){
                    ptr->getSubUnit()->setBuffCheck("Death Flower",0);
                    Buff_single_with_all_memo(ptr,ST_DEF_SHRED,AT_NONE,-25 -(5 * superimpose));
                }
            }));
        };
    }
}
#endif