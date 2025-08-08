#include "../include.h"
namespace Planar{
    void Izumo(Ally *ptr);
    void Izumo(Ally *ptr){
        
        ptr->Planar.Name = "Izumo";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            for (int i = 1; i <= Total_ally; i++) {
                if (ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name) continue;
                for (auto e1 : Ally_unit[i]->path) {
                    for (auto e2 : ptr->path) {
                        if (e2 == e1) {
                            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 12;
                            return;
                        }
                    }
                }
            }
        }));
        
       
    }
}