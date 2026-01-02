#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Danheng_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,635,397);
            ptr->Light_cone.Name = "Danheng_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                ptr->Stats_type[Stats::CR][AType::None]+=15 + (3*superimpose);
            }));

            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameUnitName(ptr))return;
                if(act->isSameAction(AType::BA)){
                    double value = ptr->calStack(1,2,"Danheng LC").first;
                    buffSingle(ptr,{{Stats::ATK_P,AType::None,value*(15 + (3*superimpose))}});
                    ptr->Energy_recharge += (5 + superimpose) * value;
                    ptr->extendBuffTime("Danheng LC",2);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(isBuffEnd(ptr,"Danheng LC")){
                    ptr->Energy_recharge -= (5 + superimpose) * ptr->getStack("Danheng LC");
                    ptr->buffResetStack({{Stats::ATK_P,AType::None,(15.0 + (3*superimpose))}},"Danheng LC");
                }
            }));
            
        };
    }
}
