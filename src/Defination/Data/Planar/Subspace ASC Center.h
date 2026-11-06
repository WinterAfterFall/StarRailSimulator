#include "../include.h"
namespace Planar{
    // Subspace ASC Center
    // SPD +6% · all allies Break Effect +18% after entering combat
    // the kit's SPD >= 145 condition is not checked (user 2026-11-03): always on
    // cannot stack: only the first wearer (charList order) gives it
    void SubspaceASCCenter(CharUnit *ptr){
        ptr->Planar.name = "Subspace ASC Center";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            for(auto &each : charList){
                if(each->Planar.name != "Subspace ASC Center")continue;
                if(each != ptr)return;
                break;
            }
            buffAllAlly({{Stats::BE,AType::NONE,18}});
        }));
    }
}
