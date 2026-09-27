#include "../include.h"
namespace Relic{
    function<void(CharUnit *ptr)> DivinerOfDistant(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
        ptr->Relic.name = "Diviner of Distant Reach";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent +=6;
            ptr->statsType[Stats::CR][AType::NONE] += 18;
        }));
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            for(auto &each : allyList){
                if(isHaveToAddBuff(each,"DoD Buff"))
                buffSingle(each,{{Stats::ELATION,AType::NONE,10}});
        }
        }));
        };
        else 
        return [=](CharUnit *ptr) {
        ptr->Relic.name = "Diviner of Distant Reach";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent +=6;
            ptr->statsType[Stats::CR][AType::NONE] += 10;
        }));
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            for(auto &each : allyList){
                if(isHaveToAddBuff(each,"DoD Buff"))
                buffSingle(each,{{Stats::ELATION,AType::NONE,10}});
        }
        }));
        };
        

    }
}
