#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> RemembranceHertaShop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Memory's Curtain Never Falls";
            string Curtain = ptr->getName() + " Curtain Never Falls";

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Atv_stats->speedPercent += 4.5 + 1.5 * superimpose;
            }));

            AfterAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Curtain](shared_ptr<ActionData> &act) {
                AllyActionData *allyData_ = act->castToAllyActionData();
                if(!allyData_)return;
                if(allyData_->isSameAction(ptr,AType::SKILL)){
                    buffAllAlly({
                        {Stats::DMG,AType::None,6.0 + 2* superimpose}
                    },Curtain,3);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Curtain]() {
                AllyUnit *allyptr = turn->canCastToAllyUnit();
                if(!allyptr)return;
                if(isBuffEnd(allyptr,Curtain)){
                    buffSingle(allyptr,{
                        {Stats::DMG,AType::None,-(6.0 + 2* superimpose)}
                    });
                }
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,Curtain](AllyUnit* target) {
                if(isBuffGoneByDeath(target,Curtain)){
                    buffSingle(target,{
                        {Stats::DMG,AType::None,-(6.0 + 2* superimpose)}
                    });
                }
            }));

        };
    }

}