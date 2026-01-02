#include "../include.h"
namespace Relic{
    void Goddess_of_Sun_and_Thunder(CharUnit *ptr){
        ptr->Relic.Name = "Goddess of Sun and Thunder";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Atv_stats->speedPercent += 6;
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *Healer, AllyUnit *target, double Value) {
            if(Healer->owner->isSameStatsOwnerName(ptr)){
                if(isHaveToAddBuff(ptr,"Goddess of Sun and Thunder",2)){
                    buffSingle(ptr,{{Stats::SPD_P,AType::None,6}});
                    buffAllAlly({
                        {Stats::CD,AType::None,15}
                    });
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"Goddess of Sun and Thunder")){
                    buffSingle(ptr,{{Stats::SPD_P,AType::None,-6}});
                    buffAllAlly({
                        {Stats::CD,AType::None,-15}
                    });
                }
        }));
        
        
    }
}
