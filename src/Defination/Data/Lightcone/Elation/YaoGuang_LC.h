#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> YaoGuang_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,529);
            ptr->Light_cone.Name = "YaoGuang_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Atv_stats->speedPercent += 15 + 3 * superimpose;
            }));

            Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr,0,15);
            }));

            Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(isHaveToAddBuff(ptr,"Great Fortune",3)){
                    ptr->Energy_recharge += 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::None,9.0 + superimpose},
                        {Stats::CD, AType::None,30.0 + 5 * superimpose}
                    });
                }
            }));

            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyBuffAction> &act) {
                if(!act->isSameAction(ptr,AType::Ult))return;
                if(isHaveToAddBuff(ptr,"Great Fortune",3)){
                    ptr->Energy_recharge += 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::None,9.0 + superimpose},
                        {Stats::CD, AType::None,30.0 + 5 * superimpose}
                    });
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (isBuffEnd(ptr,"Great Fortune")) {
                    ptr->Energy_recharge -= 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::None,-(9.0 + superimpose)},
                        {Stats::CD, AType::None,-(30.0 + 5 * superimpose)}
                    });
                }
            }));
        };
    }
}
