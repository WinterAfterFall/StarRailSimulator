#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Jingliu_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,582,397);
            ptr->lightCone.name = "Jingliu_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                ptr->statsType[Stats::CD][AType::NONE]+=17 + (3*superimpose);
            }));

            enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    buffStackSingle(ptr,{{Stats::DMG,AType::NONE,11.5 +2.5*superimpose}},1,3,"Jingliu_LC");
                }
                if(ptr->getStack("Jingliu_LC")>=3){
                    if(isHaveToAddBuff(ptr,"Jingliu_LC Def Shred"))
                        buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,10.0 +2*superimpose}});
                }
            }));

            hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,[ptr,superimpose](Unit *trigger,AllyUnit *target,double value){
                buffStackSingle(ptr,{{Stats::DMG,AType::NONE,11.5 +2.5*superimpose}},1,3,"Jingliu_LC");
                if(ptr->getStack("Jingliu_LC")>=3){
                    if(isHaveToAddBuff(ptr,"Jingliu_LC Def Shred"))
                        buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,10.0 +2*superimpose}});
                }

            }));
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->attacker->isSameName(ptr))return;
                buffCharResetStack(ptr,{{Stats::DMG,AType::NONE,11.5 +2.5*superimpose}},"Jingliu_LC");
                if(ptr->getBuffCheck("Jingliu_LC Def Shred")){
                    buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,-(10.0 +2*superimpose)}});
                    ptr->setBuffCheck("Jingliu_LC Def Shred",0);
                }

            }));
        };
    }
}
