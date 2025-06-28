#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Hertashop(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Fall of an Aeon";
    
            When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,superimpose]
                (shared_ptr<AllyAttackAction> &act) {
                ptr->getSubUnit()->buffStackSingle({{ST_ATK_P,AT_NONE,6.0+superimpose*2.0}},1,4,"Aeon Atk");
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_ACTTACK, [ptr,superimpose](Enemy *target, SubUnit *Trigger) {
                ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,9.0 + 3 * superimpose}},"Aeon Dmg%",2);
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Aeon Dmg%")) {
                ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-(9.0 + 3 * superimpose)}});
                }
            }));
    
        };
    }
}
