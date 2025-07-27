#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> The_Moles(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "The Moles";
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnit(ptr->getSubUnit()))return;
                if(act->isSameAction(AType::BA)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles BA"))
                ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::SKILL)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles Skill"))
                ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::Ult)&&ptr->getSubUnit()->isHaveToAddBuff("The Moles Ult"))
                ptr->getSubUnit()->buffSingle({{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
            }));
            
        };
    }
}
