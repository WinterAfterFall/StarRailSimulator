
#ifndef Lushaka_H
#define Lushaka_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Lushaka(Ally *ptr);
    void Lushaka(Ally *ptr){
        
        ptr->Planar.Name="Lushaka";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Energy_recharge += 5;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num != 1) {
                Ally_unit[1]->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 12;
            }
        }));
       
    }
}
#endif