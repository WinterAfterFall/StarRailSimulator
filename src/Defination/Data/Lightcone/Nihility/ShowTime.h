#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> ShowTime(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,476,265);
            ptr->lightCone.name = "ShowTime";
            ptr->newEhrRequire(80);
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 16 + 4 * superimpose;
            }));

            afterApplyDebuff.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *trigger) {
                if(trigger->isSameName(ptr)){
                    buffStackSingle(ptr,{{Stats::DMG,AType::NONE,5.0 + superimpose}},1,3,"ShowTime Trick",1);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;

                if(isBuffEnd(ally,"ShowTime Trick")){
                    buffResetStack(ally,{{Stats::DMG,AType::NONE,5.0 + superimpose}},"ShowTime Trick");
                }
            }));
    
        };
    }
}