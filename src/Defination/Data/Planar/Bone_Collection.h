#include "../include.h"
namespace Planar{
    void Bone_Collection(CharUnit *ptr){
        ptr->Planar.name="Bone_Collection";
        
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::HP_P][AType::NONE] += 12;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffSingleChar(ptr,{{Stats::CD, AType::NONE, 28.0}});
        }));
    }
}