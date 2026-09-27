#include "../include.h"
namespace Planar{
    void Kalpagni_Lantern(CharUnit *ptr){
        
        ptr->Planar.name="Kalpagni_Lantern";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::BE][AType::NONE] += 40;
        }));
       
    }
}