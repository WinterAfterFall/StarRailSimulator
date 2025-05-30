
#ifndef Goddess_of_Sun_and_Thunder_H
#define Goddess_of_Sun_and_Thunder_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Goddess_of_Sun_and_Thunder(Ally *ptr){
        ptr->Relic.Name = "Goddess of Sun and Thunder";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent += 6;
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr](SubUnit *Healer, SubUnit *target, double Value) {
            if(Healer->ptrToChar->getSubUnit()->isSameUnit(ptr->getSubUnit())){
                if(ptr->getSubUnit()->isHaveToAddBuff("Goddess of Sun and Thunder",2)){
                    ptr->getSubUnit()->buffSingle({{ST_SPD,ST_SPD_P,6}});
                    buffAllAlly({
                        {ST_CD,AT_NONE,15}
                    });
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->getSubUnit()->isBuffEnd("Goddess of Sun and Thunder")){
                    ptr->getSubUnit()->buffSingle({{ST_SPD,ST_SPD_P,-6}});
                    buffAllAlly({
                        {ST_CD,AT_NONE,-15}
                    });
                }
        }));
        
        
    }
}
#endif