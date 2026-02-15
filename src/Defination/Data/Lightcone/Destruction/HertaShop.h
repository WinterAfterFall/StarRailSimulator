#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Hertashop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Fall of an Aeon";
    
            When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,superimpose]
                (shared_ptr<AllyAttackAction> &act) {
                if(act->isSameCharName(ptr))
                buffStackSingle(ptr,{{Stats::ATK_P,AType::None,6.0+superimpose*2.0}},1,4,"Aeon Atk");
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_ACTTACK, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                buffSingle(ptr,{{Stats::DMG,AType::None,9.0 + 3 * superimpose}},"Aeon Dmg%",2);
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (isBuffEnd(ptr,"Aeon Dmg%")) {
                buffSingle(ptr,{{Stats::DMG,AType::None,-(9.0 + 3 * superimpose)}});
                }
            }));
    
        };
    }
}
