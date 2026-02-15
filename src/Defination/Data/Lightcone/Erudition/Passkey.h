#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Passkey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(741,370,265);
            ptr->Light_cone.Name = "Passkey";
            

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(turn->isSameName(ptr->Atv_stats->Name))ptr->setBuffCheck("Passkey",0);
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::SKILL)&&!ptr->getBuffCheck("Passkey")) {
                    Increase_energy(ptr, 7 + superimpose);
                    ptr->setBuffCheck("Passkey",1);
                }
            }));
        };
    }
}