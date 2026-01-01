#include "../include.h"

namespace BS{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(102,120,120,E,ElementType::Wind,Path::Nihility,"Black Swan",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,660,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setEhrRequire(120);
        ptr->setRelicMainStats(Stats::EHR,Stats::ATK_P,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *bs = ptr;
        #pragma region Ability

        function<void()> BA = [ptr,bs]() {
            Skill_point(bs,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"BS BA",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,20);
                for(auto &each : act->targetList){
                    each->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                }
                for(auto &each : act->targetList){
                    each->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                }
                Attack(act);
            }); 
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,bs]() {
            Skill_point(bs,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"BS Skill",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,30);
                for(auto &each : act->targetList){
                    each->debuffSingleApply({{Stats::DEF_SHRED,AType::None,20.8}},bs,"BS DefShred",3);
                }
                for(auto &each : act->targetList){
                    each->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                }
                for(auto &each : act->targetList){
                    each->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                }
                Attack(act);
            }); 
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,90,20),
                DmgSrc(DmgSrcType::ATK,90,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,bs,BA,Skill]() {
            for(int i = 1;i<= Total_enemy&&i<=3;i++){
                if(!enemyUnit[i]->getDebuff("BS DefShred")){
                    Skill();
                    return;
                }
            }
            // if(bs->getTurnCnt()%3==1)Skill();
            BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,bs]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"BS Ult",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Black Swan");
                for(auto &each : act->targetList){
                    if(each->debuffApply(bs,"Epiphany",2)){
                        each->changeBleed(1);
                        each->changeBurn(1);
                        each->changeShock(1);
                        each->setDebuff("Arcana Ignore",1);
                        if(turn->isSameUnit(each))each->debuffSingle({{Stats::VUL,AType::None,25}});
                    }
                }
                Attack(act);
            }); 
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,120,20),
                DmgSrc(DmgSrcType::ATK,120,20),
                DmgSrc(DmgSrcType::ATK,120,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 14.4;
            ptr->Stats_type[Stats::EHR][AType::None] += 10;

            ptr->Stats_type[Stats::DMG][AType::None] += 72;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,bs]() {
            if(ptr->Technique)dotAllEnemyStack({DotType::WindShear},bs,3,50,"Arcana");
            dotAllEnemyStack({DotType::WindShear},bs,1,50,"Arcana");
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,bs]() {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;
            
            enemy->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
            if(enemy->getDebuff("Epiphany")){
                enemy->debuffSingle({{Stats::VUL,AType::None,25}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;
            
            if(enemy->getDebuff("Epiphany")){
                enemy->debuffSingle({{Stats::VUL,AType::None,-25}});
            }

            if(enemy->isDebuffEnd("BS DefShred")){
                enemy->debuffSingle({{Stats::DEF_SHRED,AType::None,-20.8}});
            }

            if(enemy->isDebuffEnd("Epiphany")){
                enemy->changeBleed(-1);
                enemy->changeWindSheer(-1);
                enemy->changeShock(-1);
                enemy->setDebuff("Arcana Ignore",0);
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            bs->setBuffCheck("BS A4",1);
            bs->setStack("BS A4",0);
        }));
        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            bs->setBuffCheck("BS A4",0);
        }));
        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            if(!bs->getBuffCheck("BS A4")||!act->isSameDamageType(AType::Dot))return;
            for(auto & each : act->targetList){
                if(bs->getStack("BS A4")<=3){
                each->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                bs->addStack("BS A4",1);
                }
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_Last, [ptr,bs](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (Dot_type != DotType::General && Dot_type != DotType::WindShear) return;
            if (target->getStack("Arcana")){

                if(target->getStack("Arcana")>=7&&phaseStatus == PhaseStatus::DotBeforeTurn)
                    bs->buffSingle({{Stats::DEF_SHRED,AType::Dot,20}});

                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WindShear,ptr,TraceType::Single,"Arcana");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,240 + target->getStack("Arcana") * 12.0),target);

                if(target->getStack("Arcana")>=3&&phaseStatus == PhaseStatus::DotBeforeTurn){
                    act->traceType = TraceType::Blast;
                    if(target->nextToLeft){
                        act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToLeft);
                        target->nextToLeft->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                    }
                    if(target->nextToRight){
                        act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToRight);
                        target->nextToRight->dotSingleStack({DotType::WindShear},bs,1,50,"Arcana");
                    }
                }


                act->multiplyDmg(Dot_ratio);
                
                Attack(act);

                if(target->getStack("Arcana")>=7&&phaseStatus == PhaseStatus::DotBeforeTurn)
                    bs->buffSingle({{Stats::DEF_SHRED,AType::Dot,-20}});
                if(phaseStatus == PhaseStatus::DotBeforeTurn){
                    if(!target->getDebuff("Arcana Ignore")){
                        target->setStack("Arcana",1);
                    }else target->setDebuff("Arcana Ignore",0);

                }
            }
        }));
    }
}
