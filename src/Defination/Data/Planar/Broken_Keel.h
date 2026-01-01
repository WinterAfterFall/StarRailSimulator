#include "../include.h"
namespace Planar{
    void Broken_Keel(CharUnit *ptr);
    void Broken_Keel(CharUnit *ptr){
        ptr->Planar.Name="Broken_Keel";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::RES][AType::None] += 10;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffAllAlly({{Stats::CD, AType::None, 10.0}});
        }));
    }
}