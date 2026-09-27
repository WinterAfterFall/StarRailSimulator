#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Clara_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,582,397);
            ptr->lightCone.name = "Clara_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                ptr->statsType[Stats::ATK_P][AType::NONE]+=20 + (4*superimpose);
            }));
            enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    if(e->isSameName(ptr)){
                        if(ptr->getBuffCheck("Clara_LC_Triggered"))return;
                        ptr->setBuffCheck("Clara_LC_Triggered",1);
                        e->restoreHP(e,HealSrc(HealSrcType::ATK,7.0 + superimpose));
                        buffSingle(e,{{Stats::DMG,AType::NONE,(20.0 + 4*superimpose)}},"Clara_LC",1);
                        return;
                    }
                }
            }));
            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->setBuffCheck("Clara_LC_Triggered",0);
            }));
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(isBuffEnd(ptr,"Clara_LC")){
                    buffSingle(ptr,{{Stats::DMG,AType::NONE,-(20.0 + 4*superimpose)}});
                }
            }));
            
        };
    }
}
