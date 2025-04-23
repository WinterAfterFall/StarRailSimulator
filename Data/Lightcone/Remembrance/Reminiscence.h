
#ifndef Reminiscence_H
#define Reminiscence_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Reminiscence(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(635,423,265);
            ptr->Light_cone.Name = "Reminiscence";
            
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                for (auto &e : ptr->Sub_Unit_ptr) {
                    if (e->Atv_stats->Side == "Memosprite" && e->currentHP <= 0) {
                        ptr->buffResetStack({{ST_DMG,AT_NONE,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }
    
                if (turn->Unit_num == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num && turn->Side == "Memosprite") {
                    ptr->buffStackAlly({{ST_DMG,AT_NONE,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));
        };
    }
    
}
#endif