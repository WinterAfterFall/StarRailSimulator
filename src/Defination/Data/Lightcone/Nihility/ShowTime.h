#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> ShowTime(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "ShowTime";
            ptr->setEhrRequire(80);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 16 + 4 * superimpose;
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, SubUnit *Trigger) {
                if(Trigger->isSameUnit(ptr->getSubUnit())){
                    ptr->getSubUnit()->buffStackSingle({{Stats::DMG,AType::None,5.0 + superimpose}},1,3,"ShowTime Trick",1);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *ally = turn->canCastToSubUnit();
                if(!ally)return;

                if(ally->isBuffEnd("ShowTime Trick")){
                    ally->buffResetStack({{Stats::DMG,AType::None,5.0 + superimpose}},"ShowTime Trick");
                }
            }));
    
        };
    }
}