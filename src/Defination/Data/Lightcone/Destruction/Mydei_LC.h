#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Mydei_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1376,476,397);
            ptr->Light_cone.Name = "Mydei_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 15 + 3*superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_NONE] += 15 + 5 * superimpose;
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get())) return;
                if (act->isSameAttack(AT_SKILL)||act->isSameAttack(AT_ULT)) {
                    ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]++;
                    ptr->getSubUnit()->buffSingle({{ST_DMG, AT_NONE, (25.0 + 5 * superimpose)}});
                    if (ptr->Sub_Unit_ptr[0]->currentHP >= 50000.0 / (5.5 + 0.5 * superimpose)) {
                        ptr->getSubUnit()->buffSingle({{ST_DMG, AT_NONE, (25.0 + 5 * superimpose)}});
                        ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]++;
                        DecreaseHP(ptr->Sub_Unit_ptr[0].get(), ptr->Sub_Unit_ptr[0].get(), 0, (5.5 + 0.5 * superimpose), 0);
                    }
                }
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get())) return;
                ptr->getSubUnit()->buffSingle({{ST_DMG, AT_NONE, -(25 + 5 * superimpose) * ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"] = 0;
            }));
        };
    }
}
