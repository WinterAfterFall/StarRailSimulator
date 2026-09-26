#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Cerydra_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Cerydra LC";
            string CerydraLCBuff = ptr->getName() +  " Cerydra LC Buff";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 48 + 16 * superimpose;
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff]() {
                AllyUnit *sptr = turn->canCastToAllyUnit();
                if(!sptr)return;
                if(isBuffEnd(sptr,CerydraLCBuff)){
                    buffSingle(sptr,{{Stats::DMG,AType::SKILL,-(40.5 + (13.5)*superimpose)}});
                }
            }));    
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff](AllyUnit* target) {
                if(isBuffGoneByDeath(target,CerydraLCBuff)){
                    buffSingle(target,{{Stats::DMG,AType::SKILL,-(40.5 + (13.5)*superimpose)}});
                }
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameAction(ptr,AType::Ult)) genSkillPoint(ptr,1);
            }));

            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff](shared_ptr<AllyBuffAction> &act) {
                if(act->isSameAction(ptr,AType::SKILL)&&act->traceType==TraceType::Single){
                    for (auto each : act->buffTargetList) {
                        buffSingle(each,{{Stats::DMG,AType::SKILL,(40.5 + (13.5)*superimpose)}},CerydraLCBuff,3);
                    }
                }
            }));
        };
    }
}