#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Reminiscence(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(635,423,265);
            ptr->lightCone.name = "Reminiscence";

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(auto *e = ptr->memosprite.get()){
                    if (e->atvStats->side == Side::MEMOSPRITE && e->isDeath()) {
                        buffCharResetStack(ptr,{{Stats::DMG,AType::NONE,7.0 + superimpose}},"Reminiscence");
                        return;
                    }
                }

                if (turn->num == ptr->atvStats->num && turn->side == Side::MEMOSPRITE) {
                    buffStackChar(ptr,{{Stats::DMG,AType::NONE,7.0 + superimpose}}, 1, 4,"Reminiscence");
                }
            }));

            // kit: removed as soon as the memosprite disappears
            allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](AllyUnit* target) {
                if (target != ptr->memosprite.get()) return;
                buffCharResetStack(ptr,{{Stats::DMG,AType::NONE,7.0 + superimpose}},"Reminiscence");
            }));
        };
    }

}