#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Victory_In_Blink(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(847,476,397);
            ptr->lightCone.name = "Victory_In_Blink";
            string victoryBlink = ptr->getName() + " Victory_Blink";

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,victoryBlink](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 9 + 3 * superimpose;
            }));

            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,victoryBlink](shared_ptr<AllyBuffAction> &act) {
                if (act->attacker->atvStats->side == Side::MEMOSPRITE &&
                    act->attacker->owner->atvStats->name == ptr->atvStats->name) {
                    buffAllAlly({{Stats::DMG, AType::NONE, (6.0 + 2 * superimpose)}}, victoryBlink,3);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,victoryBlink](CharUnit *ptr) {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (isBuffEnd(tempstats,victoryBlink)) {
                    buffSingle(tempstats,{{Stats::DMG, AType::NONE, -(6.0 + 2 * superimpose)}});
                }
            }));

            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,victoryBlink](AllyUnit* target) {
                if(isBuffGoneByDeath(target,victoryBlink)){
                    buffSingle(target,{{Stats::DMG, AType::NONE, -(6.0 + 2 * superimpose)}});
                }
            }));
        };
    }

}