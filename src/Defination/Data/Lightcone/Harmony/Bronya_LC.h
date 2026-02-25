#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Bronya_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,529,463);
            ptr->Light_cone.Name = "Bronya_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Energy_recharge += 8 + 2 * superimpose;
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->Attacker->Atv_stats->Name == ptr->Atv_stats->Name) {
                    if (act->isSameAction(AType::SKILL)) {
                        ptr->Buff_check["Battle_Isnt_Over_buff"] = 1;
                    }
                }
            }));
            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    if (ptr->Buff_check["Battle_Isnt_Over_cnt"] == 0) {
                        ptr->Buff_check["Battle_Isnt_Over_cnt"] = true;
                        genSkillPoint(ptr, 1);
                    } else {
                        ptr->Buff_check["Battle_Isnt_Over_cnt"] = false;
                    }
                }
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *tempstats = dynamic_cast<AllyUnit *>(turn->charptr);
                if (!tempstats) return;
                if (ptr->Buff_check["Battle_Isnt_Over_buff"] == 1) {
                    buffSingle(tempstats,{{Stats::DMG,AType::None,25.0+5*superimpose}},"Battle_Isnt_Over_buff_check",0);
                    ptr->Buff_check["Battle_Isnt_Over_buff"] = 0;
                    ptr->Buff_check["Battle_Isnt_Over_buff_check"] = 1;
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *tempstats = dynamic_cast<AllyUnit *>(turn->charptr);
                if (!tempstats) return;
                if (isBuffEnd(tempstats,"Battle_Isnt_Over_buff_check")) {
                    buffSingle(tempstats,{{Stats::DMG,AType::None,-25.0-5*superimpose}});
                }
            }));
        };
    }
    
}
