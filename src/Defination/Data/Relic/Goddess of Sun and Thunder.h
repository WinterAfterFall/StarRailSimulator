#include "../include.h"
namespace Relic{
    void Goddess_of_Sun_and_Thunder(CharUnit *ptr){
        ptr->Relic.name = "Goddess of Sun and Thunder";
        
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *healer, AllyUnit *target, double value) {
            if(healer->owner->isSameName(ptr)){
                if(isHaveToAddBuff(ptr,"Goddess of Sun and Thunder",2)){
                    buffSingle(ptr,{{Stats::SPD_P,AType::NONE,6}});
                    buffAllAlly({
                        {Stats::CD,AType::NONE,15}
                    });
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Goddess of Sun and Thunder")){
                    buffSingle(ptr,{{Stats::SPD_P,AType::NONE,-6}});
                    buffAllAlly({
                        {Stats::CD,AType::NONE,-15}
                    });
                }
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target) {
            if(target->isSameName(ptr) && isBuffGoneByDeath(ptr,"Goddess of Sun and Thunder")){
                buffSingle(ptr,{{Stats::SPD_P,AType::NONE,-6}});
                buffAllAlly({
                    {Stats::CD,AType::NONE,-15}
                });
            }
        }));
    }
}
