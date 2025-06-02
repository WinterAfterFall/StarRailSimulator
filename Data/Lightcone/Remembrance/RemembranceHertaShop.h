
#ifndef RemembranceHertaShop_H
#define RemembranceHertaShop_H

#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> RemembranceHertaShop(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "RemembranceHertaShop";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 4.5 + 1.5 * superimpose;
            }));
    
            AfterAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<ActionData> &act) {
                AllyActionData *allyData_ = act->castToAllyActionData();
                if(!allyData_)return;
                if(allyData_->isSameAction(ptr->getSubUnit(),AT_SKILL)){
                    buffAllAlly({
                        {ST_DMG,AT_NONE,6.0 + 2* superimpose}
                    },"Curtain Never Falls",3);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *allyptr = turn->canCastToSubUnit();
                if(!allyptr)return;
                if(allyptr->isBuffEnd("Curtain Never Falls")){
                    allyptr->buffSingle({
                        {ST_DMG,AT_NONE,-(6.0 + 2* superimpose)}
                    });
                }
            }));

            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](SubUnit* target) {
                if(target->isBuffGoneByDeath("Curtain Never Falls")){
                    target->buffSingle({
                        {ST_DMG,AT_NONE,-(6.0 + 2* superimpose)}
                    });
                }
            }));

        };
    }
    
}
#endif