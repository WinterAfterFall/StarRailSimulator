
#ifndef Kalpagni_Lantern_H
#define Kalpagni_Lantern_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Planar{
    void Kalpagni_Lantern(Ally *ptr);
    void Kalpagni_Lantern(Ally *ptr){
        
        ptr->Planar.Name="Kalpagni_Lantern";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent += 6;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE]["None"] += 40;
        }));
       
    }
}
#endif