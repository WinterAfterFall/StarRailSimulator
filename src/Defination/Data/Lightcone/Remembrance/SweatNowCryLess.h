#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> SweatNowCryLess(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,198);
            ptr->Light_cone.Name = "SweatNowCryLess";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CR][AType::None] += 10 + 2 * superimpose;
            }));

            // kit: only while the memosprite is on the field
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                auto *memo = ptr->memosprite.get();
                bool onField = memo && !memo->isDeath();
                if (onField && isHaveToAddBuff(ptr,"SweatNowCryLess")) {
                    buffSingleChar(ptr,{{Stats::DMG, AType::None, 21.0 + superimpose * 3}});
                } else if (!onField && ptr->getBuffCheck("SweatNowCryLess")) {
                    ptr->setBuffCheck("SweatNowCryLess",0);
                    buffSingleChar(ptr,{{Stats::DMG, AType::None, -(21.0 + superimpose * 3)}});
                }
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](AllyUnit* target) {
                if (target != ptr->memosprite.get()) return;
                if (!ptr->getBuffCheck("SweatNowCryLess")) return;
                ptr->setBuffCheck("SweatNowCryLess",0);
                buffSingleChar(ptr,{{Stats::DMG, AType::None, -(21.0 + superimpose * 3)}});
            }));
        };
    }

}
