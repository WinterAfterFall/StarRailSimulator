#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> HertaShop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Solitary Healing";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::BE][AType::None] += 15 + 5 * superimpose;
            }));
            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](CharUnit *ally) {
                if(ally->isSameOwner(ptr))buffSingle(ptr,{{Stats::DMG,AType::Dot,18.0 + 6 * superimpose}},"Solitary Healing",2);
            }));
            
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;

                if(isBuffEnd(ally,"Solitary Healing")){
                    buffSingle(ptr,{{Stats::DMG,AType::Dot,-(18.0 + 6 * superimpose)}});
                }
            }));
        };
    }
}