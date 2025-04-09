
#ifndef Double_Atk_H
#define Double_Atk_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    function<void(Ally *ptr)> PairSet(string first,string second){
        return [=](Ally *ptr) {
            ptr->Relic.Name = "PairSet";
            function<void(Ally *ptr)> Relic1 = ptr->RelicPairSet(first);
            function<void(Ally *ptr)> Relic2 = ptr->RelicPairSet(second);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Relic1,Relic2]() {
                Relic1(ptr);
                Relic2(ptr);
            }));
        };
    }

}
#endif