#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Passkey(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(741,370,265);
            ptr->Light_cone.Name = "Passkey";
            

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(turn->isSameCharName(ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name))ptr->getSubUnit()->setBuffCheck("Passkey",0);
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::SKILL)&&!ptr->getSubUnit()->getBuffCheck("Passkey")) {
                    Increase_energy(ptr, 7 + superimpose);
                    ptr->getSubUnit()->setBuffCheck("Passkey",1);
                }
            }));
        };
    }
}