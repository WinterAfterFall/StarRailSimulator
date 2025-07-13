#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> The_Moles(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "The Moles";
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnit(ptr->getSubUnit()))return;
                if(act->isSameAction(AT_BA)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles BA"))
                ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,9.0 + 3 * superimpose}});
                if(act->isSameAction(AT_SKILL)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles Skill"))
                ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,9.0 + 3 * superimpose}});
                if(act->isSameAction(AT_ULT)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles Ult"))
                ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,9.0 + 3 * superimpose}});
            }));
            
        };
    }
}
