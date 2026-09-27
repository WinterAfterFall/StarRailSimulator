#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Bronya_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,529,463);
            ptr->lightCone.name = "Bronya_LC";
            string battleBuff = ptr->getName() + " Battle_Isnt_Over_buff_check";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->energyRecharge += 8 + 2 * superimpose;
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->attacker->atvStats->name == ptr->atvStats->name) {
                    if (act->isSameAction(AType::SKILL)) {
                        ptr->buffCheck["Battle_Isnt_Over_buff"] = 1;
                    }
                }
            }));
            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    if (ptr->buffCheck["Battle_Isnt_Over_cnt"] == 0) {
                        ptr->buffCheck["Battle_Isnt_Over_cnt"] = true;
                        genSkillPoint(ptr, 1);
                    } else {
                        ptr->buffCheck["Battle_Isnt_Over_cnt"] = false;
                    }
                }
            }));
    
            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,battleBuff](CharUnit *ptr) {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (tempstats->isSameName(ptr)) return; // kit: next ally except the wearer
                if (ptr->buffCheck["Battle_Isnt_Over_buff"] == 1) {
                    buffSingle(tempstats,{{Stats::DMG,AType::NONE,25.0+5*superimpose}},battleBuff,0);
                    ptr->buffCheck["Battle_Isnt_Over_buff"] = 0;
                }
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,battleBuff](CharUnit *ptr) {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (isBuffEnd(tempstats,battleBuff)) {
                    buffSingle(tempstats,{{Stats::DMG,AType::NONE,-25.0-5*superimpose}});
                }
            }));
        };
    }
    
}
