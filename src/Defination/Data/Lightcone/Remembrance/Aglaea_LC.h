#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Aglaea_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,635,397);
            ptr->Light_cone.Name = "Aglaea_LC";
            ptr->Atv_stats->baseSpeed+= 10 + superimpose * 2;
            When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->num == ptr->Atv_stats->num) {
                if (ptr->Stack["Aglaea_LC_stack"] < 6) {
                    ptr->buffSingleChar({{Stats::CD, AType::None, 7.5 + 1.5 * superimpose}});
                    ptr->Stack["Aglaea_LC_stack"]++;
                    if (ptr->Stack["Aglaea_LC_stack"] == 6) {
                    ptr->buffSingleChar({{Stats::DMG, AType::BA, 6 * (7.5 + 1.5 * superimpose)}});
                    }
                }
                }
            }));
        };
    }
    
}