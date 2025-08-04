#include "../include.h"

namespace Kafka{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(100,120,120,E,ElementType::Lightning,Path::Nihility,"Kafka",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,679,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(75);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        
        SubUnit *kafka = ptr->getSubUnit();

        ptr->setAdjust("Kafka A2 Kafka",1);
        #pragma region Ability

        function<void()> BA = [ptr,kafka]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Kafka BA",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                Skill_point(kafka,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,kafka]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Blast,"Kafka Skill",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                Skill_point(kafka,-1);
                Increase_energy(ptr,30);
                Attack(act);
                for(auto &each : act->targetList){
                    if(each->Target_type == EnemyType::Main)Dot_trigger(75,each,DotType::General);
                    else Dot_trigger(50,each,DotType::General);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,60,10)
            );
            act->addToActionBar();
        };

        function<void()> Fua = [ptr,kafka]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Fua,ptr->getSubUnit(),TraceType::Single,"Kafka Fua",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,10);
                Attack(act);
                for(auto &each : act->targetList){
                    if(ptr->Eidolon>=6)if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",3))each->changeShock(1);
                    else if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",2))each->changeShock(1);
                    Dot_trigger(80,each,DotType::General);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,140,10)
            );
            act->addToActionBar();
            Deal_damage();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,kafka,Skill]() {
            Skill();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,kafka]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TraceType::Aoe,"Kafka Ult",
            [ptr,kafka](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Kafka");
                Attack(act);
                for(auto &each : act->targetList){
                    if(ptr->Eidolon>=6)if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",3))each->changeShock(1);
                    else if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",2))each->changeShock(1);
                    Dot_trigger(120,each,DotType::General);
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

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 10;

            // relic

            // substats
            for(int i=1;i<=Total_ally;i++){
                if(Ally_unit[i]->getAdjust("Kafka A2 " + Ally_unit[i]->getSubUnit()->getUnitName()))
                Ally_unit[i]->buffAlly({{Stats::ATK_P,AType::None,100}});
            }

            if(ptr->Eidolon>=2){
                buffAllAlly({{Stats::DMG,AType::Dot,33}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TraceType::Aoe,"Kafka Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                    for(auto &each : act->targetList){
                    if(ptr->Eidolon>=6)if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",3))each->changeShock(1);
                    else if(each->debuffApply(ptr->getSubUnit(),"Kafka Shock",2))each->changeShock(1);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,kafka]() {
            if(turn->isSameUnitName("Kafka"))kafka->addStack("Kafka Talent",1);
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&enemy->isDebuffEnd("Kafka Shock")){
                enemy->changeShock(-1);
            }
        }));

        AfterAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Fua,kafka](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameAtkerName("Kafka")&&kafka->getStack("Kafka Talent")>0){
                kafka->addStack("Kafka Talent",-1);
                Fua();
            }
        }));
        
        Dot_List.push_back(TriggerDot_Func(PRIORITY_ACTTACK, [ptr,kafka](Enemy* target, double Dot_ratio, DotType Dot_type) {
            if (!target->getDebuff("Kafka Shock")) return;
            if (Dot_type != DotType::General && Dot_type != DotType::Shock) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Dot,ptr->getSubUnit(),TraceType::Single,"Kafka Shock");
            if(ptr->Eidolon>=6)act->addDamageIns(DmgSrc(DmgSrcType::ATK,290+156),target);
            else act->addDamageIns(DmgSrc(DmgSrcType::ATK,290),target);
            act->multiplyDmg(Dot_ratio);
            if(ptr->Eidolon>=4)Increase_energy(ptr,2);
            Attack(act);
        }));

        if(ptr->Eidolon>=1){
        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Fua,kafka](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameAtkerName("Kafka")){
                for(auto &each : act->targetList){
                    each->debuffSingleApply({{Stats::VUL,AType::Dot,30}},kafka,"kafka E1",2);
                }
            }
        }));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,kafka]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy&&enemy->isDebuffEnd("Kafka E1")){
                enemy->debuffSingle({{Stats::VUL,AType::Dot,-30}});
            }
        }));
        }
    }

    void useKafkaA2(int num){
        Ally *ptr = CharCmd::findAllyName("Kafka");
        if(!ptr)return;
        ptr->setAdjust("Kafka A2 " + Ally_unit[num]->getSubUnit()->getUnitName(),1);
        Ally_unit[num]->newEhrRequire(75);
    }
}
