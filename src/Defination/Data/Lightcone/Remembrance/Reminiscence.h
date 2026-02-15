#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Reminiscence(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(635,423,265);
            ptr->Light_cone.Name = "Reminiscence";
            
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                for (auto &e : ptr->memospriteList) {
                    if (e->Atv_stats->side == Side::AllyUnit && e->isDeath()) {
                        buffResetStack(ptr,{{Stats::DMG,AType::None,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }
    
                if (turn->num == ptr->Atv_stats->num && turn->side == Side::AllyUnit) {
                    buffStackChar(ptr,{{Stats::DMG,AType::None,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));
        };
    }
    
}