#include "../include.h"

namespace BSV1{

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102,120,120,eidolon,ElementType::WIND,Path::NIHILITY,"Black Swan",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,660,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setEhrRequire(120);
        ptr->setRelicMainStats(Stats::EHR,Stats::ATK_P,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *bs = ptr;
        #pragma region Ability

        function<void()> ba = [ptr,bs]() {
            genSkillPoint(bs,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"BS BA",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WIND_SHEAR},1,50,"Arcana");
                }
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WIND_SHEAR},1,50,"Arcana");
                }
                attack(act);
            }); 
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,bs]() {
            genSkillPoint(bs,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"BS Skill",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                for(auto &each : act->targetList){
                    debuffSingleApply(bs,each,{{Stats::DEF_SHRED,AType::NONE,20.8}},"BS DefShred",3);
                }
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WIND_SHEAR},1,50,"Arcana");
                }
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WIND_SHEAR},1,50,"Arcana");
                }
                attack(act);
            }); 
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,90,20),
                DmgSrc(DmgSrcType::ATK,90,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,bs,ba,skill]() {
            for(int i = 1;i<= totalEnemy&&i<=3;i++){
                if(!enemyUnit[i]->getDebuff("BS DefShred")){
                    skill();
                    return;
                }
            }
            // if(bs->getTurnCnt()%3==1)Skill();
            ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [bs](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"BS Ult",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Black Swan");
                for(auto &each : act->targetList){
                    if(debuffApply(bs,each,"Epiphany",2)){
                        each->changeBleed(1);
                        each->changeBurn(1);
                        each->changeShock(1);
                        each->setDebuff("Arcana Ignore",1);
                        if(turn->isSameUnit(each))debuffSingle(each,{{Stats::VUL,AType::NONE,25}});
                    }
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,120,20),
                DmgSrc(DmgSrcType::ATK,120,20),
                DmgSrc(DmgSrcType::ATK,120,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 14.4;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;

            ptr->statsType[Stats::DMG][AType::NONE] += 72;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bs](CharUnit *ptr) {
            if(ptr->technique)dotAllEnemyStack(bs,{DotType::WIND_SHEAR},3,50,"Arcana");
            dotAllEnemyStack(bs,{DotType::WIND_SHEAR},1,50,"Arcana");
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bs](CharUnit *ptr) {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;
            
            dotSingleStack(bs,enemy,{DotType::WIND_SHEAR},1,50,"Arcana");
            if(enemy->getDebuff("Epiphany")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,25}});
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;
            
            if(enemy->getDebuff("Epiphany")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-25}});
            }

            if(isDebuffEnd(enemy,"BS DefShred")){
                debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-20.8}});
            }

            if(isDebuffEnd(enemy,"Epiphany")){
                enemy->changeBleed(-1);
                enemy->changeWindSheer(-1);
                enemy->changeShock(-1);
                enemy->setDebuff("Arcana Ignore",0);
            }
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            bs->setBuffCheck("BS A4",1);
            bs->setStack("BS A4",0);
        }));
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            bs->setBuffCheck("BS A4",0);
        }));
        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            if(!bs->getBuffCheck("BS A4")||!act->isSameDamageType(AType::DOT))return;
            for(auto & each : act->targetList){
                if(bs->getStack("BS A4")<=3){
                dotSingleStack(bs,each,{DotType::WIND_SHEAR},1,50,"Arcana");
                bs->addStack("BS A4",1);
                }
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_LAST, [ptr,bs](Enemy* target, double dotRatio,DotType dotType) {
            if (dotType != DotType::GENERAL && dotType != DotType::WIND_SHEAR) return;
            if (target->getStack("Arcana")){

                if(target->getStack("Arcana")>=7&&phaseStatus == PhaseStatus::DOT_BEFORE_TURN)
                    buffSingle(bs,{{Stats::DEF_SHRED,AType::DOT,20}});

                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WIND_SHEAR,ptr,TraceType::SINGLE,"Arcana");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,240 + target->getStack("Arcana") * 12.0),target);

                if(target->getStack("Arcana")>=3&&phaseStatus == PhaseStatus::DOT_BEFORE_TURN){
                    act->traceType = TraceType::BLAST;
                    if(target->nextToLeft){
                        act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToLeft);
                        dotSingleStack(bs,target->nextToLeft,{DotType::WIND_SHEAR},1,50,"Arcana");
                    }
                    if(target->nextToRight){
                        act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToRight);
                        dotSingleStack(bs,target->nextToRight,{DotType::WIND_SHEAR},1,50,"Arcana");
                    }
                }


                act->multiplyDmg(dotRatio);
                
                attack(act);

                if(target->getStack("Arcana")>=7&&phaseStatus == PhaseStatus::DOT_BEFORE_TURN)
                    buffSingle(bs,{{Stats::DEF_SHRED,AType::DOT,-20}});
                if(phaseStatus == PhaseStatus::DOT_BEFORE_TURN){
                    if(!target->getDebuff("Arcana Ignore")){
                        target->setStack("Arcana",1);
                    }else target->setDebuff("Arcana Ignore",0);

                }
            }
        }));
    }
}
