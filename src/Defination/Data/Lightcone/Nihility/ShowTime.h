#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> ShowTime(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "ShowTime";
            ptr->newEhrRequire(80);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 16 + 4 * superimpose;
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                if(Trigger->isSameName(ptr)){
                    buffStackSingle(ptr,{{Stats::DMG,AType::None,5.0 + superimpose}},1,3,"ShowTime Trick",1);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;

                if(isBuffEnd(ally,"ShowTime Trick")){
                    buffResetStack(ally,{{Stats::DMG,AType::None,5.0 + superimpose}},"ShowTime Trick");
                }
            }));
    
        };
    }
}