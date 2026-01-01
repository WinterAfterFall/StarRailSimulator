#include "../include.h"
namespace Planar{
    void Revelry(CharUnit *ptr){
        ptr->Planar.Name="Revelry";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));
        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::DMG][AType::Dot] += 24;
        }));
    }
}