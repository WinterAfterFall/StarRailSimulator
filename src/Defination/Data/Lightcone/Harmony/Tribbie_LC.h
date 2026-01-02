#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Tribbie_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1270,529,397);
            ptr->Light_cone.Name = "Tribbie_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CD][AType::None] += 30 + 6 * superimpose;
            }));
    
            Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr, 21);
                if(isHaveToAddBuff(ptr,"Presage",2)){
                    buffAllAlly({{Stats::CD, AType::None, (36.0 + 12 * superimpose)}});
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (isBuffEnd(ptr,"Presage")) {
                    buffAllAlly({{Stats::CD, AType::None, -(36.0 + 12 * superimpose)}});
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::Fua)) {
                    Increase_energy(ptr, 12);
                    if(isHaveToAddBuff(ptr,"Presage",2)){
                        buffAllAlly({{Stats::CD, AType::None, (36.0 + 12 * superimpose)}});
                    }
                }
            }));

        };
    }
}
