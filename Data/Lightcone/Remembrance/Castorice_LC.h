
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
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 22 + 8*superimpose;
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, superimpose](SubUnit* target) {
                if (target->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num
                &&target->Atv_stats->Side=="Memosprite"
                &&ptr->getSubUnit()->getBuffCheck("Castorice_LC_check")==0){
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),9+3*superimpose);
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",1);
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                    ptr->getSubUnit()->setBuffCheck("Castorice_LC_check",0);
                }
            }));
            
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr, superimpose](Unit *Trigger, SubUnit *target, double Value) {
                if(!turn)return;
                if((turn->Side=="Memosprite"||turn->Side=="Ally")
                &&turn->num==ptr->getSubUnit()->Atv_stats->num
                &&target->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num){
                    if(ptr->getSubUnit()->isHaveToAddBuff("Death Flower",2))
                    ptr->buffAlly({{ST_DEF_SHRED, AT_NONE, 25.0 + 5 * superimpose}});
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, superimpose]() {
                if(ptr->getSubUnit()->isBuffEnd("Death Flower")){
                    ptr->buffAlly({{ST_DEF_SHRED, AT_NONE, -(25.0 + 5 * superimpose)}});
                }
            }));
        };
    }
}
#endif