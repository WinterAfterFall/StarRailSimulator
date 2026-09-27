#include "../include.h"
namespace Planar{
    void Rutilant(CharUnit *ptr){
        
        ptr->Planar.name = "Rutilant";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 8;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::DMG][AType::SKILL] += 20;
            ptr->statsType[Stats::DMG][AType::BA] += 20;
        }));
        
       
    }
}