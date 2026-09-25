#include "../include.h"
namespace Planar{
    void Izumo(CharUnit *ptr){
        
        ptr->Planar.Name = "Izumo";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            for (int i = 1; i <= Total_ally; i++) {
                if (ptr->Atv_stats->Name == charUnit[i]->Atv_stats->Name) continue;
                if (charUnit[i]->path == ptr->path) {
                    ptr->Stats_type[Stats::CR][AType::None] += 12;
                    return;
                }
            }
        }));
        
       
    }
}