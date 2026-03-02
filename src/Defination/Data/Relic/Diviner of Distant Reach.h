#include "../include.h"
namespace Relic{
    function<void(CharUnit *ptr)> DivinerOfDistant(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
        ptr->Relic.Name = "Diviner of Distant Reach";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Atv_stats->speedPercent +=6;
            ptr->Stats_type[Stats::CR][AType::None] += 18;
        }));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            for(auto &each : allyList){
                if(isHaveToAddBuff(each,"DoD Buff"))
                buffSingle(ptr,{{Stats::Elation,AType::None,10}});
        }
        }));
        };
        else 
        return [=](CharUnit *ptr) {
        ptr->Relic.Name = "Diviner of Distant Reach";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Atv_stats->speedPercent +=6;
            ptr->Stats_type[Stats::CR][AType::None] += 10;
        }));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            for(auto &each : allyList){
                if(isHaveToAddBuff(each,"DoD Buff"))
                buffSingle(ptr,{{Stats::Elation,AType::None,10}});
        }
        }));
        };
        

    }
}
