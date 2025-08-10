#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> HertaShop(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Solitary Healing";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 15 + 5 * superimpose;
            }));
            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Ally *ally) {
                if(ally->isSameAlly(ptr))ptr->getSubUnit()->buffSingle({{Stats::DMG,AType::Dot,18.0 + 6 * superimpose}},"Solitary Healing",2);
            }));
            
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *ally = turn->canCastToSubUnit();
                if(!ally)return;

                if(ally->isBuffEnd("Solitary Healing")){
                    ptr->getSubUnit()->buffSingle({{Stats::DMG,AType::Dot,-(18.0 + 6 * superimpose)}});
                }
            }));
        };
    }
}