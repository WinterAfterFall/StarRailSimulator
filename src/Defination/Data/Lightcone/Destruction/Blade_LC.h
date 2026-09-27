#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Blade_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1270,582,331);
            ptr->lightCone.name = "Blade LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                        
                ptr->statsType[Stats::CR][AType::NONE]+=15 + (3*superimpose);
                ptr->statsType[Stats::HP_P][AType::NONE]+=15 + (3*superimpose);
                
                }
            ));
            enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    if(e->isSameName(ptr)){
                        if(isHaveToAddBuff(ptr,"Blade_LC_Mark")){
                            buffSingle(ptr,{{Stats::DMG,AType::NONE,(20.0 + 4*superimpose)}});
                        }
                        return;
                    }
                }
            }));
            hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,[ptr,superimpose](Unit *trigger,AllyUnit *target,double value){
                if(!target->isSameName(ptr))return;
                if(isHaveToAddBuff(ptr,"Blade_LC_Mark")){
                            buffSingle(ptr,{{Stats::DMG,AType::NONE,(20.0 + 4*superimpose)}});
                }
                
            }));
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->attacker->isSameName(ptr))return;
                if(ptr->getBuffCheck("Blade_LC_Mark")){
                    buffSingle(ptr,{{Stats::DMG,AType::NONE,-(20.0 + 4*superimpose)}});
                    ptr->buffCheck["Blade_LC_Mark"] = 0;
                }
            }));
        };
    }
}
