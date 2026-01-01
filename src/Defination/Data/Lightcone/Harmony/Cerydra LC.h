#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Cerydra_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Cerydra LC";
            string CerydraLCBuff = ptr->getUnitName() +  " Cerydra LC Buff";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 48 + 16 * superimpose;
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff]() {
                AllyUnit *sptr = turn->canCastToSubUnit();
                if(!sptr)return;
                if(sptr->isBuffEnd(CerydraLCBuff)){
                    sptr->buffSingle({{Stats::DMG,AType::None,-(40.5 + (13.5)*superimpose)}});
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff](AllyUnit* target) {
                if(target->isBuffGoneByDeath(CerydraLCBuff)){
                    target->buffSingle({{Stats::DMG,AType::None,-(40.5 + (13.5)*superimpose)}});
                }
            }));
    
            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,CerydraLCBuff](shared_ptr<AllyBuffAction> &act) {
                if(act->isSameAction(ptr,AType::SKILL)&&act->traceType==TraceType::Single){
                    for (auto each : act->buffTargetList) {
                        each->buffSingle({{Stats::DMG,AType::None,(40.5 + (13.5)*superimpose)}},CerydraLCBuff,3);
                    }
                }
            }));
        };
    }
}