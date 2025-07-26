#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Reminiscence(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(635,423,265);
            ptr->Light_cone.Name = "Reminiscence";
            
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                for (auto &e : ptr->Sub_Unit_ptr) {
                    if (e->Atv_stats->Side == "Memosprite" && e->isDeath()) {
                        ptr->buffResetStack({{ST_DMG,AType::None,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }
    
                if (turn->num == ptr->Sub_Unit_ptr[0]->Atv_stats->num && turn->Side == "Memosprite") {
                    ptr->buffStackAlly({{ST_DMG,AType::None,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));
        };
    }
    
}