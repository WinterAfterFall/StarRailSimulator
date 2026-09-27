#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Robin_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "Robin_LC";
            
            whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (ptr->stack["Cantillation"] < 5) {
                    ptr->stack["Cantillation"]++;
                    ptr->energyRecharge += 2.5 + 0.5 * superimpose;
                }
            }));

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    ptr->energyRecharge -= ptr->stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->stack["Cantillation"] = 0;
                    if (isHaveToAddBuff(ptr,"Cadenza",1)) {
                        buffAllAlly({{Stats::DMG, AType::NONE, (20.0 + 4 * superimpose)}});
                        buffSingle(ptr,{{Stats::ATK_P, AType::NONE, (36.0 + 12 * superimpose)}});
                    }
                }
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Cadenza")) {
                    buffAllAlly({{Stats::DMG, AType::NONE, -(20.0 + 4 * superimpose)}});
                    buffSingle(ptr,{{Stats::ATK_P, AType::NONE, -(36.0 + 12 * superimpose)}});
                }
            }));
        };
    }   
}
