#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Cerydra_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "Cerydra LC";
            string cerydraLCBuff = ptr->getName() +  " Cerydra LC Buff";

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 48 + 16 * superimpose;
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,cerydraLCBuff](CharUnit *ptr) {
                AllyUnit *sptr = turn->canCastToAllyUnit();
                if(!sptr)return;
                if(isBuffEnd(sptr,cerydraLCBuff)){
                    buffSingle(sptr,{{Stats::DMG,AType::SKILL,-(40.5 + (13.5)*superimpose)}});
                }
            }));    
    
            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,cerydraLCBuff](AllyUnit* target) {
                if(isBuffGoneByDeath(target,cerydraLCBuff)){
                    buffSingle(target,{{Stats::DMG,AType::SKILL,-(40.5 + (13.5)*superimpose)}});
                }
            }));
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameAction(ptr,AType::ULT)) genSkillPoint(ptr,1);
            }));

            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,cerydraLCBuff](shared_ptr<AllyBuffAction> &act) {
                if(act->isSameAction(ptr,AType::SKILL)&&act->traceType==TraceType::SINGLE){
                    for (auto each : act->buffTargetList) {
                        buffSingle(each,{{Stats::DMG,AType::SKILL,(40.5 + (13.5)*superimpose)}},cerydraLCBuff,3);
                    }
                }
            }));
        };
    }
}