
#ifndef Himeko_LC_H
#define Himeko_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Himeko_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,582,397);
            ptr->Light_cone.Name = "Himeko_LC";
    
            When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += (7.5 + superimpose * 1.5) * Total_enemy;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Himeko_LC_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["None"] -= 25+superimpose*5;
                }
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, SubUnit *Breaker) {
                ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,(25.0 + superimpose*5)}},"Himeko_LC_buff",1);
            }));
        };
    }
}
#endif