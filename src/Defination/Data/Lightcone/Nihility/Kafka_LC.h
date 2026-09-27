#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Kafka_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,582,463);
            ptr->lightCone.name = "Kafka_LC";
            string erode = ptr->getName() + " Erode";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DMG][AType::NONE] += 20 + 4 * superimpose;
            }));
            
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,erode](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameOwnerName(ptr)){
                    buffStackSingle(ptr,{{Stats::SPD_P,AType::NONE,4.0 + 0.8*superimpose}},1,3,"Kafka LC");
                    for(auto &each : act->targetList ){
                        if(!each->getDebuff(erode))dotSingleApply(ptr,each,{DotType::SHOCK},erode,1);
                    }
                }
            }));


            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,erode](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(isDebuffEnd(enemy,erode)){
                    dotRemove(enemy,{DotType::SHOCK});
                }
            }));

            dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,erode](Enemy* target, double dotRatio,DotType dotType) {
                if (dotType != DotType::GENERAL && dotType != DotType::SHOCK) return;
                if (target->getDebuff(erode)){
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,erode);
                    act->addDamageIns(DmgSrc(DmgSrcType::ATK,50 + 10.0 * superimpose),target);
                    act->multiplyDmg(dotRatio);
                    attack(act);
                }
            }));
    
        };
    }
}