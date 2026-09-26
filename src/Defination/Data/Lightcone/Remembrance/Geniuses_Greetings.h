#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Geniuses_Greetings(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Geniuses_Greetings";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 12 + 4 * superimpose;
            }));

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    buffSingleChar(ptr,{{Stats::DMG,AType::BA,(15.0 + superimpose * 5)}},"Geniuses_Greetings",3);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *tempstats = turn->canCastToAllyUnit();
                if (!tempstats) return;
                if (isBuffEnd(tempstats,"Geniuses_Greetings")) {
                    buffSingle(tempstats,{{Stats::DMG,AType::BA,-(15.0 + superimpose * 5)}});
                }
            }));
        };
    }
}