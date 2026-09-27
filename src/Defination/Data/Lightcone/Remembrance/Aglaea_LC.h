#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Aglaea_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,635,397);
            ptr->lightCone.name = "Aglaea_LC";
            ptr->atvStats->baseSpeed+= 10 + superimpose * 2;
            whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->isSameOwnerName(ptr)) {
                if (ptr->stack["Aglaea_LC_stack"] < 6) {
                    buffSingleChar(ptr,{{Stats::CD, AType::NONE, 7.5 + 1.5 * superimpose}});
                    ptr->stack["Aglaea_LC_stack"]++;
                    if (ptr->stack["Aglaea_LC_stack"] == 6) {
                    buffSingleChar(ptr,{{Stats::DMG, AType::BA, 6 * (7.5 + 1.5 * superimpose)}});
                    }
                }
                }
            }));
        };
    }
    
}