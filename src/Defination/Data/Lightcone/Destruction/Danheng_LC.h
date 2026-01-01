#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Danheng_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,635,397);
            ptr->Light_cone.Name = "Danheng_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None]+=15 + (3*superimpose);
            }));

            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnitName(ptr->getMemosprite()))return;
                if(act->isSameAction(AType::BA)){
                    double value = ptr->getMemosprite()->calStack(1,2,"Danheng LC").first;
                    ptr->getMemosprite()->buffSingle({{Stats::ATK_P,AType::None,value*(15 + (3*superimpose))}});
                    ptr->Energy_recharge += (5 + superimpose) * value;
                    ptr->getMemosprite()->extendBuffTime("Danheng LC",2);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(ptr->getMemosprite()->isBuffEnd("Danheng LC")){
                    ptr->Energy_recharge -= (5 + superimpose) * ptr->getMemosprite()->getStack("Danheng LC");
                    ptr->getMemosprite()->buffResetStack({{Stats::ATK_P,AType::None,(15.0 + (3*superimpose))}},"Danheng LC");
                }
            }));
            
        };
    }
}
