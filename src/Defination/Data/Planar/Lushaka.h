#include "../include.h"
namespace Planar{
    void Lushaka(Ally *ptr);
    void Lushaka(Ally *ptr){
        
        ptr->Planar.Name="Lushaka";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Energy_recharge += 5;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Atv_stats->num != 1) {
                Ally_unit[1]->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
            }
        }));
       
    }
}