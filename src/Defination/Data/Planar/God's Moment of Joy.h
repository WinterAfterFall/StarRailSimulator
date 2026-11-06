#include "../include.h"
namespace Planar{
    // God's Moment of Joy
    // SPD +6% · Elation >= 40% -> the wearer's action advances 40% when entering combat
    void GodsMomentOfJoy(CharUnit *ptr){
        ptr->Planar.name = "God's Moment of Joy";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        // Elation is complete by startGame (traces / relics / on-field buffs are already in)
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(calculateElationOnStats(ptr)>=40)actionForward(ptr->atvStats.get(),40);
        }));
    }
}
