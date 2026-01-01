#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Himeko_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,582,397);
            ptr->Light_cone.Name = "Himeko_LC";
    
            WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += (7.5 + superimpose * 1.5) * Total_enemy;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->isBuffEnd("Himeko_LC_buff")) {
                    ptr->Stats_type[Stats::DMG][AType::None] -= 25+superimpose*5;
                }
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Breaker) {
                ptr->buffSingle({{Stats::DMG,AType::None,(25.0 + superimpose*5)}},"Himeko_LC_buff",1);
            }));
        };
    }
}