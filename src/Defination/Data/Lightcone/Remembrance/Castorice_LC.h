#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Castorice_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1270,529,397);
            ptr->lightCone.name = "Castorice_LC";

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::HP_P][AType::NONE] += 22.5 + 7.5*superimpose;
            }));

            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, superimpose](AllyUnit* target) {
                if (target->atvStats->num==ptr->atvStats->num
                &&target->atvStats->side==Side::MEMOSPRITE
                &&ptr->getBuffCheck("Castorice_LC_check")==0){
                    actionForward(ptr->atvStats.get(),9+3*superimpose);
                    ptr->setBuffCheck("Castorice_LC_check",1);
                }
            }));

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    ptr->setBuffCheck("Castorice_LC_check",0);
                }
            }));

            hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr, superimpose](Unit *trigger, AllyUnit *target, double value) {
                if(!turn)return;
                if((turn->side==Side::MEMOSPRITE||turn->side==Side::ALLY)
                &&turn->num==ptr->atvStats->num
                &&target->atvStats->num==ptr->atvStats->num){
                    if(isHaveToAddBuff(ptr,"Death Flower",2))
                    buffSingleChar(ptr,{{Stats::DEF_SHRED, AType::NONE, 25.0 + 5 * superimpose}});
                }
            }));


            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(isBuffEnd(ptr,"Death Flower")){
                    buffSingleChar(ptr,{{Stats::DEF_SHRED, AType::NONE, -(25.0 + 5 * superimpose)}});
                }
            }));
        };
    }
}