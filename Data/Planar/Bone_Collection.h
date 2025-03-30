
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
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] += 12;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Buff_single_with_all_memo(ptr, ST_CRIT_DAM, AT_NONE, 28);
        }));
    }
}
#endif