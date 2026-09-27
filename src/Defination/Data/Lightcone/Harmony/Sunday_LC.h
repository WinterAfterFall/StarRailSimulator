#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Sunday_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,476,529);
            ptr->lightCone.name = "Sunday_LC";
            string hymn = ptr->getName() +  " Hymn";
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,hymn](CharUnit *ptr) {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (isBuffEnd(tempstats,hymn)) {
                    buffResetStack(tempstats,{{Stats::DMG,AType::NONE,(12.75 + (2.25)*superimpose)}},hymn);
                }
            }));
    
            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](AllyUnit* target) {
                buffResetStack(target,{{Stats::DMG,AType::NONE,(12.75 + (2.25)*superimpose)}},hymn);
            }));
    
            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](shared_ptr<AllyBuffAction> &act) {
                if (act->attacker->atvStats->name == ptr->atvStats->name && act->traceType == TraceType::SINGLE) {
                    increaseEnergy(ptr, 5.5 + 0.5 * superimpose);
                    for (auto each : act->buffTargetList) {
                        buffStackSingle(each,{{Stats::DMG,AType::NONE,(12.75 + (2.25)*superimpose)}},1,3,hymn,3);
                    }
                    ++ptr->stack["Hymn_cnt"];
                    if (ptr->stack["Hymn_cnt"] == 2) {
                        genSkillPoint(ptr, 1);
                        ptr->stack["Hymn_cnt"] = 0;
                    }
                }
            }));
        };
    }
}