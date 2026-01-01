#include "../include.h"
namespace Planar{
    void Lushaka(CharUnit *ptr);
    void Lushaka(CharUnit *ptr){
        
        ptr->Planar.Name="Lushaka";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Energy_recharge += 5;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Atv_stats->num != 1) {
                charUnit[1]->Stats_type[Stats::ATK_P][AType::None] += 12;
            }
        }));
       
    }
}