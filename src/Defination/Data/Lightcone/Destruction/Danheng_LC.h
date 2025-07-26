#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Danheng_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,635,397);
            ptr->Light_cone.Name = "Danheng_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AType::None]+=15 + (3*superimpose);
            }));

            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnit(ptr->getSubUnit()))return;
                if(act->isSameAction(AType::BA)){
                    double value = ptr->getSubUnit()->calStack(1,2,"Danheng LC").first;
                    ptr->getSubUnit()->buffSingle({{ST_ATK_P,AType::None,value*(15 + (3*superimpose))}});
                    ptr->Energy_recharge += (5 + superimpose) * value;
                    ptr->getSubUnit()->extendBuffTime("Danheng LC",2);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(ptr->getSubUnit()->isBuffEnd("Danheng LC")){
                    ptr->Energy_recharge -= (5 + superimpose) * ptr->getSubUnit()->getStack("Danheng LC");
                    ptr->getSubUnit()->buffResetStack({{ST_ATK_P,AType::None,(15.0 + (3*superimpose))}},"Danheng LC");
                }
            }));
            
        };
    }
}
