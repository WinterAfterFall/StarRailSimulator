#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Kafka_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,582,463);
            ptr->Light_cone.Name = "Kafka_LC";
            string Erode = ptr->getUnitName() + " Erode";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::DMG][AType::None] += 20 + 4 * superimpose;
            }));
            
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Erode](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameUnitName(ptr)){
                    ptr->buffStackSingle({{Stats::SPD_P,AType::None,4.0 + 0.8*superimpose}},1,3,"Kafka LC");
                    for(auto &each : act->targetList ){
                        if(!each->getDebuff(Erode))each->dotSingleApply({DotType::Shock},ptr,Erode,1);
                    }
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Erode]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(enemy->isDebuffEnd(Erode)){
                    enemy->changeShock(-1);
                }
            }));

            Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Erode](Enemy* target, double Dot_ratio,DotType Dot_type) {
                if (Dot_type != DotType::General && Dot_type != DotType::Shock) return;
                if (target->getDebuff(Erode)){
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>(AType::Shock,ptr,TraceType::Single,Erode);
                    act->addDamageIns(DmgSrc(DmgSrcType::ATK,50 + 10.0 * superimpose),target);
                    act->multiplyDmg(Dot_ratio);
                    Attack(act);
                }
            }));
    
        };
    }
}