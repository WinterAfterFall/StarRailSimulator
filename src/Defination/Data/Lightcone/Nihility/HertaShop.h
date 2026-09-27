#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> HertaShop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,397);
            ptr->lightCone.name = "Solitary Healing";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 15 + 5 * superimpose;
            }));
            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](CharUnit *ally) {
                if(ally->isSameOwner(ptr))buffSingle(ptr,{{Stats::DMG,AType::DOT,18.0 + 6 * superimpose}},"Solitary Healing",2);
            }));
            
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;

                if(isBuffEnd(ally,"Solitary Healing")){
                    buffSingle(ptr,{{Stats::DMG,AType::DOT,-(18.0 + 6 * superimpose)}});
                }
            }));
        };
    }
}