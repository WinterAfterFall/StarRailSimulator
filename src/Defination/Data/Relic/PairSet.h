#include "../include.h"
namespace Relic{
    function<void(CharUnit *ptr)> pairSet(PairSetType first,PairSetType second){
        return [=](CharUnit *ptr) {
            ptr->Relic.name = "PairSet";
            function<void(CharUnit *ptr)> relic1 = ptr->relicPairSet(first);
            function<void(CharUnit *ptr)> relic2 = ptr->relicPairSet(second);
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [relic1,relic2](CharUnit *ptr) {
                relic1(ptr);
                relic2(ptr);
            }));
        };
    }

}