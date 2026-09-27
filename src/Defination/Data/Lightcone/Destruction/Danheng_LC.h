#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Danheng_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,635,397);
            ptr->lightCone.name = "Danheng_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                ptr->statsType[Stats::CR][AType::NONE]+=15 + (3*superimpose);
            }));

            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->isSameOwnerName(ptr))return;
                if(act->isSameAction(AType::BA)){
                    double value = calStack(ptr,1,2,"Danheng LC").first;
                    buffSingle(ptr,{{Stats::ATK_P,AType::NONE,value*(15 + (3*superimpose))}});
                    ptr->energyRecharge += (5 + superimpose) * value;
                    extendBuffTime(ptr,"Danheng LC",2);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(isBuffEnd(ptr,"Danheng LC")){
                    ptr->energyRecharge -= (5 + superimpose) * ptr->getStack("Danheng LC");
                    buffCharResetStack(ptr,{{Stats::ATK_P,AType::NONE,(15.0 + (3*superimpose))}},"Danheng LC");
                }
            }));
            
        };
    }
}
