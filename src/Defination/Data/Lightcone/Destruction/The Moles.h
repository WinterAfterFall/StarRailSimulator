#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> The_Moles(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,476,265);
            ptr->Light_cone.Name = "The Moles";
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnitName(ptr))return;
                if(act->isSameAction(AType::BA)&&isHaveToAddBuff(ptr,"The Moles BA"))
                buffSingle(ptr,{{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::SKILL)&&isHaveToAddBuff(ptr,"The Moles Skill"))
                buffSingle(ptr,{{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
                if(act->isSameAction(AType::Ult)&&isHaveToAddBuff(ptr,"The Moles Ult"))
                buffSingle(ptr,{{Stats::ATK_P,AType::None,9.0 + 3 * superimpose}});
            }));
            
        };
    }
}
