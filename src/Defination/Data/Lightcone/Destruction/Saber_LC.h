#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Saber_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Saber_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                        
                ptr->statsType[Stats::CD][AType::NONE]+=27 + (9*superimpose);
                
                }
            ));

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    buffSingle(ptr,{{Stats::ATK_P,AType::NONE,30.0 + 10.0 * superimpose}},"Saber_LC",2);
                    if(ptr->maxEnergy>=300){
                        increaseEnergy(ptr,10,0);
                        buffSingle(ptr,{{Stats::ATK_P,AType::NONE,30.0 + 10.0 * superimpose}},"Extra Saber_LC",2);

                    }
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Saber_LC")) {
                    buffSingle(ptr,{{Stats::ATK_P,AType::NONE,-(30.0 + 10.0 * superimpose)}});
                }
                if (isBuffEnd(ptr,"Extra Saber_LC")) {
                    buffSingle(ptr,{{Stats::ATK_P,AType::NONE,-(30.0 + 10.0 * superimpose)}});
                }
            }));
        };
    }
}
