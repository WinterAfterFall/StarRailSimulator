#include "../include.h"

namespace Kafka{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(100,120,120,eidolon,ElementType::LIGHTNING,Path::NIHILITY,"Kafka",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,679,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setEhrRequire(75);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
        
        AllyUnit *kafka = ptr;

        ptr->setAdjust("Kafka A2 Kafka",1);
        ptr->setAdjust("Kafka A2 Hysilens",1);
        ptr->setAdjust("Kafka A2 Black Swan",1);
        ptr->setAdjust("Kafka A2 Guinaifen",1);
        ptr->setAdjust("Kafka A2 Luka",1);
        ptr->setAdjust("Kafka A2 Robin",1);
        #pragma region Ability

        function<void()> ba = [ptr,kafka]() {
            genSkillPoint(kafka,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Kafka BA",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,kafka]() {
            genSkillPoint(kafka,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Kafka Skill",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                attack(act);
                for(auto &each : act->targetList){
                    if(each->targetType == EnemyType::MAIN)dotTrigger(75,each,DotType::GENERAL);
                    else dotTrigger(50,each,DotType::GENERAL);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,60,10)
            );
            act->addToActionBar();
        };

        function<void()> fua = [ptr,kafka]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::SINGLE,"Kafka Fua",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,10);
                attack(act);
                for(auto &each : act->targetList){
                    if(ptr->eidolon>=6)dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",3);
                    dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",2);
                    dotTrigger(80,each,DotType::GENERAL);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,140,10)
            );
            act->addToActionBar();
            dealDamage();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,kafka,skill]() {
            skill();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [kafka](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Kafka Ult",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Kafka");
                attack(act);
                for(auto &each : act->targetList){
                    if(ptr->eidolon>=6)dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",3);
                    dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",2);
                    dotTrigger(120,each,DotType::GENERAL);
                }
                kafka->addStack("Kafka Talent",1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,80,20),
                DmgSrc(DmgSrcType::ATK,80,20),
                DmgSrc(DmgSrcType::ATK,80,20)
            );
            act->addToActionBar();

        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::EHR][AType::NONE] += 18;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            for(auto &each : charList){
                if(ptr->getAdjust("Kafka A2 " + each->getName())){
                    buffSingleChar(each,{{Stats::ATK_P,AType::NONE,100}});
                    each->newEhrRequire(75);
                }
            }

            if(ptr->eidolon>=2){
                buffAllAlly({{Stats::DMG,AType::DOT,33}});
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [kafka](CharUnit *ptr) {
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Kafka Tech",
                [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                    for(auto &each : act->targetList){
                    if(ptr->eidolon>=6)dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",3);
                    dotSingleApply(kafka,each,{DotType::SHOCK},"Kafka Shock",2);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [kafka](CharUnit *ptr) {
            if(turn->isSameName("Kafka"))kafka->addStack("Kafka Talent",1);
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&isDebuffEnd(enemy,"Kafka Shock")){
                dotRemove(enemy,{DotType::SHOCK});
            }
        }));

        afterAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,fua,kafka](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameName("Kafka")&&kafka->getStack("Kafka Talent")>0){
                kafka->addStack("Kafka Talent",-1);
                fua();
            }
        }));
        
        dotList.push_back(TriggerDotFunc(PRIORITY_ACTTACK, [ptr,kafka](Enemy* target, double dotRatio, DotType dotType) {
            if (!target->getDebuff("Kafka Shock")) return;
            if (dotType != DotType::GENERAL && dotType != DotType::SHOCK) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,"Kafka Shock");
            if(ptr->eidolon>=6)act->addDamageIns(DmgSrc(DmgSrcType::ATK,290+156),target);
            else act->addDamageIns(DmgSrc(DmgSrcType::ATK,290),target);
            act->multiplyDmg(dotRatio);
            if(ptr->eidolon>=4)increaseEnergy(ptr,2);
            attack(act);
        }));

        if(ptr->eidolon>=1){
        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,fua,kafka](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameName("Kafka")){
                for(auto &each : act->targetList){
                    debuffSingleApply(kafka,each,{{Stats::VUL,AType::DOT,30}},"Kafka E1",2);
                }
            }
        }));
        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [kafka](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&isDebuffEnd(enemy,"Kafka E1")){
                debuffSingle(enemy,{{Stats::VUL,AType::DOT,-30}});
            }
        }));
        }
    }

    void useKafkaA2(int num){
        CharUnit *ptr = CharCmd::findAllyName("Kafka");
        if(!ptr)return;
        ptr->setAdjust("Kafka A2 " + charUnit[num]->getName(),1);
        charUnit[num]->newApplyBaseChanceRequire(75);
    }
}
