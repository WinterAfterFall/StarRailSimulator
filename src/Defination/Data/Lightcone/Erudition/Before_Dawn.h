#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Before_Dawn(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,582,463);

            ptr->Light_cone.Name = "Before_Dawn";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CD][AType::None] += 30 + 6 * superimpose;
                ptr->Stats_type[Stats::DMG][AType::SKILL] += 15 + 3 * superimpose;
                ptr->Stats_type[Stats::DMG][AType::Ult] += 15 + 3 * superimpose;
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName &&
                    ptr->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::Fua) {
                            ptr->Stats_type[Stats::DMG][AType::Fua] += 40 + 8 * superimpose;
                            break;
                        }
                    }
                }
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName != ptr->Atv_stats->StatsOwnerName) return;
    
                for (auto e : act->actionTypeList) {
                    if (e == AType::SKILL || e == AType::Ult) {
                        ptr->Stack["Somnus_Corpus"] = 1;
                        break;
                    }
                }
    
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName &&
                    ptr->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::Fua) {
                            ptr->Stats_type[Stats::DMG][AType::Fua] -= 40 + 8 * superimpose;
                            ptr->Stack["Somnus_Corpus"] = 0;
                            break;
                        }
                    }
                }
            }));
        };
    }
}