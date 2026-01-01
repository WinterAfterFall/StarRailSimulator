#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Castorice_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1270,529,397);
            ptr->Light_cone.Name = "Castorice_LC";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                ptr->Stats_type[Stats::HP_P][AType::None] += 22 + 8*superimpose;
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, superimpose](AllyUnit* target) {
                if (target->Atv_stats->num==ptr->Atv_stats->num
                &&target->Atv_stats->side==Side::AllyUnit
                &&ptr->getBuffCheck("Castorice_LC_check")==0){
                    Action_forward(ptr->Atv_stats.get(),9+3*superimpose);
                    ptr->setBuffCheck("Castorice_LC_check",1);
                }
            }));

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameChar(ptr)) {
                    ptr->setBuffCheck("Castorice_LC_check",0);
                }
            }));
            
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr, superimpose](Unit *Trigger, AllyUnit *target, double Value) {
                if(!turn)return;
                if((turn->side==Side::AllyUnit||turn->side==Side::Ally)
                &&turn->num==ptr->Atv_stats->num
                &&target->Atv_stats->num==ptr->Atv_stats->num){
                    if(ptr->isHaveToAddBuff("Death Flower",2))
                    ptr->buffSingleChar({{Stats::DEF_SHRED, AType::None, 25.0 + 5 * superimpose}});
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                if(ptr->isBuffEnd("Death Flower")){
                    ptr->buffSingleChar({{Stats::DEF_SHRED, AType::None, -(25.0 + 5 * superimpose)}});
                }
            }));
        };
    }
}