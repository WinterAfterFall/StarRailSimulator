#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> RemembranceHertaShop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,397);
            ptr->lightCone.name = "Memory's Curtain Never Falls";
            string curtain = ptr->getName() + " Curtain Never Falls";

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 4.5 + 1.5 * superimpose;
            }));

            afterActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,curtain](shared_ptr<ActionData> &act) {
                AllyActionData *allyData = act->castToAllyActionData();
                if(!allyData)return;
                if(allyData->isSameAction(ptr,AType::SKILL)){
                    buffAllAlly({
                        {Stats::DMG,AType::NONE,6.0 + 2* superimpose}
                    },curtain,3);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,curtain](CharUnit *ptr) {
                AllyUnit *allyptr = turn->canCastToAllyUnit();
                if(!allyptr)return;
                if(isBuffEnd(allyptr,curtain)){
                    buffSingle(allyptr,{
                        {Stats::DMG,AType::NONE,-(6.0 + 2* superimpose)}
                    });
                }
            }));

            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,curtain](AllyUnit* target) {
                if(isBuffGoneByDeath(target,curtain)){
                    buffSingle(target,{
                        {Stats::DMG,AType::NONE,-(6.0 + 2* superimpose)}
                    });
                }
            }));

        };
    }

}