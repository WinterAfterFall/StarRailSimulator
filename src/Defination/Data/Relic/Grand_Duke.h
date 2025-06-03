#include "../include.h"
namespace Relic{
    void Grand_Duke(Ally *ptr);
    void Grand_Duke(Ally *ptr){
        ptr->Relic.Name = "Grand_Duke";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Fua"] += 20;
        }));

        Hit_Count_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;

            bool check = false;
            for (auto e : act->actionTypeList) {
                if (e == "Fua") {
                    check = true;
                    break;
                }
            }
            int hitCnt = 0;
            if (check) {
                hitCnt += act->Attacker->hitCount;
                if (hitCnt > 8) {
                    hitCnt = 8;
                }
                act->Attacker->Stats_type["Atk%"][AT_NONE] -= act->Attacker->Stack["Grand_Duke"] * 6;
                act->Attacker->Stack["Grand_Duke"] = hitCnt;
                act->Attacker->Stats_type["Atk%"][AT_NONE] += act->Attacker->Stack["Grand_Duke"] * 6;
                act->Attacker->extendBuffTime("Grand_Duke", 3);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Char_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name) return;

            if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Grand_Duke")) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] -= ptr->Sub_Unit_ptr[0]->Stack["Grand_Duke"] * 6;
                ptr->Sub_Unit_ptr[0]->Stack["Grand_Duke"] = 0;
            }
        }));
        
    }
}