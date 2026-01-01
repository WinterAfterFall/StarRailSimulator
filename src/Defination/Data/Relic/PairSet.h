#include "../include.h"
namespace Relic{
    function<void(CharUnit *ptr)> PairSet(PairSetType first,PairSetType second){
        return [=](CharUnit *ptr) {
            ptr->Relic.Name = "PairSet";
            function<void(CharUnit *ptr)> Relic1 = ptr->RelicPairSet(first);
            function<void(CharUnit *ptr)> Relic2 = ptr->RelicPairSet(second);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Relic1,Relic2]() {
                Relic1(ptr);
                Relic2(ptr);
            }));
        };
    }

}