#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> The_Moles(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,476,265);
            ptr->lightCone.name = "The Moles";
            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameOwnerName(ptr))return;
                if(act->isSameAction(AType::BA)&&isHaveToAddBuff(ptr,"The Moles BA"))
                buffSingle(ptr,{{Stats::ATK_P,AType::NONE,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::SKILL)&&isHaveToAddBuff(ptr,"The Moles Skill"))
                buffSingle(ptr,{{Stats::ATK_P,AType::NONE,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::ULT)&&isHaveToAddBuff(ptr,"The Moles Ult"))
                buffSingle(ptr,{{Stats::ATK_P,AType::NONE,9.0 + 3 * superimpose}});
            }));
            
        };
    }
}
