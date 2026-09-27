#include "../include.h"
namespace Planar{
    void SpaceSealing(CharUnit *ptr){
        
        ptr->Planar.name = "SpaceSealing";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 24;
        }));
        
       
    }
}