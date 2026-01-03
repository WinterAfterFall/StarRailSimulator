#include "../include.h"
namespace Planar{
    void Bone_Collection(CharUnit *ptr);
    void Bone_Collection(CharUnit *ptr){
        ptr->Planar.Name="Bone_Collection";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::HP_P][AType::None] += 12;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffSingleChar(ptr,{{Stats::CD, AType::None, 28.0}});
        }));
    }
}