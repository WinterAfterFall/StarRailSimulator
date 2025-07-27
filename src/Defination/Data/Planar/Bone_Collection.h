#include "../include.h"
namespace Planar{
    void Bone_Collection(Ally *ptr);
    void Bone_Collection(Ally *ptr){
        ptr->Planar.Name="Bone_Collection";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 12;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->buffAlly({{Stats::CD, AType::None, 28.0}});
        }));
    }
}