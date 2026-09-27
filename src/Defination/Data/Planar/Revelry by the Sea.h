#include "../include.h"
namespace Planar{
    void Revelry(CharUnit *ptr){
        ptr->Planar.name="Revelry";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
        }));
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::DMG][AType::DOT] += 24;
        }));
    }
}