#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Geniuses_Greetings(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Geniuses_Greetings";

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 12 + 4 * superimpose;
            }));

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    buffSingleChar(ptr,{{Stats::DMG,AType::BA,(15.0 + superimpose * 5)}},"Geniuses_Greetings",3);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (isBuffEnd(tempstats,"Geniuses_Greetings")) {
                    buffSingle(tempstats,{{Stats::DMG,AType::BA,-(15.0 + superimpose * 5)}});
                }
            }));
        };
    }
}