#include "../include.h"
namespace Planar{
    void Broken_Keel(Ally *ptr);
    void Broken_Keel(Ally *ptr){
        ptr->Planar.Name="Broken_Keel";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AType::None] += 10;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffAllAlly({{ST_CD, AType::None, 10.0}});
        }));
    }
}