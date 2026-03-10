#include "../include.h"
namespace Planar{
    void TengokuLivestream(CharUnit *ptr){
        ptr->Planar.Name="Tengoku@Livestream";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 16;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->setStack("Tengoku sp count",0);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"Tengoku Buff"))
            buffSingle(ptr,{{Stats::CD,AType::None,-32}});
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *SP_maker, int SP) {
            if(SP<0)
            ptr->addStack("Tengoku sp count",-1*SP);
            if(ptr->getStack("Tengoku sp count")>=3)
            buffSingle(ptr,{{Stats::CD,AType::None,32}},"Tengoku Buff",3);  
        })); 
    }
}