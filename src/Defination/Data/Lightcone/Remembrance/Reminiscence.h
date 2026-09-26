#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Reminiscence(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(635,423,265);
            ptr->Light_cone.Name = "Reminiscence";

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(auto *e = ptr->memosprite.get()){
                    if (e->Atv_stats->side == Side::Memosprite && e->isDeath()) {
                        buffCharResetStack(ptr,{{Stats::DMG,AType::None,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }

                if (turn->num == ptr->Atv_stats->num && turn->side == Side::Memosprite) {
                    buffStackChar(ptr,{{Stats::DMG,AType::None,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));

            // kit: removed as soon as the memosprite disappears
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](AllyUnit* target) {
                if (target != ptr->memosprite.get()) return;
                buffCharResetStack(ptr,{{Stats::DMG,AType::None,7.0 + superimpose}},"Reminiscence");
            }));
        };
    }

}