#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Before_Dawn(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,582,463);

            ptr->Light_cone.Name = "Before_Dawn";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AType::None] += 30 + 6 * superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::SKILL] += 15 + 3 * superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::Ult] += 15 + 3 * superimpose;
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name &&
                    ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::Fua) {
                            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::Fua] += 40 + 8 * superimpose;
                            break;
                        }
                    }
                }
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
    
                for (auto e : act->actionTypeList) {
                    if (e == AType::SKILL || e == AType::Ult) {
                        ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] = 1;
                        break;
                    }
                }
    
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name &&
                    ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::Fua) {
                            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::Fua] -= 40 + 8 * superimpose;
                            ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] = 0;
                            break;
                        }
                    }
                }
            }));
        };
    }
}