
#ifndef Bone_Collection_H
#define Bone_Collection_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Bone_Collection(Ally *ptr);
    void Bone_Collection(Ally *ptr){
        ptr->Planar.Name="Bone_Collection";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 12;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->buffAlly({{ST_CD, AT_NONE, 28.0}});
        }));
    }
}
#endif