#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Castorice_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1270,529,397);
            ptr->Light_cone.Name = "Castorice_LC";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 22 + 8*superimpose;
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, superimpose](SubUnit* target) {
                if (target->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num
                &&target->Atv_stats->side==Side::Memosprite
                &&ptr->getSubUnit()->getBuffCheck("Castorice_LC_check")==0){
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),9+3*superimpose);
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",1);
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
                }
            }));
            
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr, superimpose](Unit *Trigger, SubUnit *target, double Value) {
                if(!turn)return;
                if((turn->side==Side::Memosprite||turn->side==Side::Ally)
                &&turn->num==ptr->getSubUnit()->Atv_stats->num
                &&target->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num){
                    if(ptr->getSubUnit()->isHaveToAddBuff("Death Flower",2))
                    ptr->buffAlly({{Stats::DEF_SHRED, AType::None, 25.0 + 5 * superimpose}});
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                if(ptr->getSubUnit()->isBuffEnd("Death Flower")){
                    ptr->buffAlly({{Stats::DEF_SHRED, AType::None, -(25.0 + 5 * superimpose)}});
                }
            }));
        };
    }
}