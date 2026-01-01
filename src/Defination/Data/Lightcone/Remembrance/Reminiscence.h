#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Reminiscence(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(635,423,265);
            ptr->Light_cone.Name = "Reminiscence";
            
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                for (auto &e : ptr->Sub_Unit_ptr) {
                    if (e->Atv_stats->side == Side::AllyUnit && e->isDeath()) {
                        ptr->buffResetStack({{Stats::DMG,AType::None,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }
    
                if (turn->num == ptr->Sub_Unit_ptr[0]->Atv_stats->num && turn->side == Side::AllyUnit) {
                    ptr->buffStackAlly({{Stats::DMG,AType::None,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));
        };
    }
    
}