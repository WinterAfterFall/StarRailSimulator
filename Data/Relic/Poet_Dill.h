
#ifndef Poet_Dill_H
#define Poet_Dill_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Poet_Dill(Ally *ptr);
    void Poet_Dill(Ally *ptr){
        ptr->Relic.Name = "Poet_Dill";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent-=8;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"]+=10;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=32;
        }
        ));
        
        
    }
}
#endif