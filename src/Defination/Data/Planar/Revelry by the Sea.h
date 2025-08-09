#include "../include.h"
namespace Planar{
    void Arcadia(Ally *ptr){
        ptr->Planar.Name="Revelry";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));
        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Dot] += 24;
        }));
    }
}