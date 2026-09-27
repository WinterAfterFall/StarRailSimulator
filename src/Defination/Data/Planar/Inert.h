#include "../include.h"
namespace Planar{
    void Inert(CharUnit *ptr){
        
        ptr->Planar.name = "Inert";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 8;
            ptr->statsType[Stats::DMG][AType::ULT] += 15;
            ptr->statsType[Stats::DMG][AType::FUA] += 15;
        }));
        
       
    }
}