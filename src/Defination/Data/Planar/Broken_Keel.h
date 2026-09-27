#include "../include.h"
namespace Planar{
    void Broken_Keel(CharUnit *ptr);
    void Broken_Keel(CharUnit *ptr){
        ptr->Planar.name="Broken_Keel";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::RES][AType::NONE] += 10;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffAllAlly({{Stats::CD, AType::NONE, 10.0}});
        }));
    }
}