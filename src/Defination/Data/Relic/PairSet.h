#include "../include.h"
namespace Relic{
    function<void(Ally *ptr)> PairSet(PairSetType first,PairSetType second){
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