#include "../include.h"
namespace Planar{
    void Izumo(Ally *ptr);
    void Izumo(Ally *ptr){
        
        ptr->Planar.Name = "Izumo";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] += 12;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            for (int i = 1; i <= Total_ally; i++) {
                if (ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name) continue;
                for (auto e1 : Ally_unit[i]->Path) {
                    for (auto e2 : ptr->Path) {
                        if (e2 == e1) {
                            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AType::None] += 12;
                            return;
                        }
                    }
                }
            }
        }));
        
       
    }
}