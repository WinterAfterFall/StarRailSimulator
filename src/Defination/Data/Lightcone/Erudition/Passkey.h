#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Passkey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(741,370,265);
            ptr->lightCone.name = "Passkey";
            

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(turn->isSameName(ptr->atvStats->name))ptr->setBuffCheck("Passkey",0);
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::SKILL)&&!ptr->getBuffCheck("Passkey")) {
                    increaseEnergy(ptr, 7 + superimpose);
                    ptr->setBuffCheck("Passkey",1);
                }
            }));
        };
    }
}