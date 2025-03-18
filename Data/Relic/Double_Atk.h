
#ifndef Double_Atk_H
#define Double_Atk_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Double_Atk(Ally *ptr);
    void Double_Atk(Ally *ptr){
        ptr->Relic.Name = "Double_Atk";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 24;
        }
        ));
    }
}
#endif