#include "../include.h"

namespace BS{
    int arcanaStacksAfterTick(int current) {
        return max(1, current / 2);
    }

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

        int maxArcana = 50;
        if(ptr->eidolon>=6)maxArcana = 80;

        function<void()> ba = [ptr,bs]() {
            genSkillPoint(bs,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"BS BA",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            }); 
            act->addDamageInsByDebuff(
                DmgSrc(DmgSrcType::ATK,100,10),"BS DefShred"
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,bs]() {
            genSkillPoint(bs,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"BS Skill",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                for(auto &each : act->targetList){
                    debuffSingleApply(bs,each,{{Stats::DEF_SHRED,AType::NONE,20.8}},"BS DefShred",3);
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
            ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [bs](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"BS Ult",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Black Swan");
                if(ptr->eidolon>=4)debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,45}},"Epiphany",2);
                else debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,25}},"Epiphany",2);
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},each->getStack("Arcana")/2,1e9,"Arcana");
                    each->setDebuff("Arcana Ignore",1);
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
        }));

        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameDamageType(AType::DOT))return;
            for(auto & each : act->targetList){
                dotSingleStack(ptr,each,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},5,1e9,"Arcana");
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;

            if(isDebuffEnd(enemy,"BS DefShred")){
                debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-20.8}});
            }

            if(isDebuffEnd(enemy,"Epiphany")){
                if(ptr->eidolon>=4)debuffSingle(enemy,{{Stats::VUL,AType::NONE,-45}});
                else debuffSingle(enemy,{{Stats::VUL,AType::NONE,-25}});
                enemy->setDebuff("Arcana Ignore",0);
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameName(ptr)){
                debuffEnemyTargetsApply(ptr,act->targetList,{{Stats::DEF_SHRED,AType::NONE,20.8}},"BS DefShred",3);
                for(auto &each : act->targetList){
                    dotSingleStack(ptr,each,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},5,1e9,"Arcana");
                }
            }else if(ptr->eidolon>=6){
                for(auto &each : act->targetList){
                    dotSingleStack(ptr,each,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},1 + each->getStack("Arcana"),1e9,"Arcana");
                }
            }
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bs](CharUnit *ptr) {
            buffAllAlly({{Stats::DMG,AType::NONE,72}});
            if(ptr->eidolon>=1)debuffAllEnemyApply(bs,{
                {Stats::RESPEN,ElementType::WIND,AType::NONE,25},
                {Stats::RESPEN,ElementType::LIGHTNING,AType::NONE,25},
                {Stats::RESPEN,ElementType::PHYSICAL,AType::NONE,25},
                {Stats::RESPEN,ElementType::FIRE,AType::NONE,25}}
                ,"BS E1");
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bs](CharUnit *ptr) {
            if(ptr->technique)dotAllEnemyStack(ptr,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},2,1e9,"Arcana");
            dotAllEnemyStack(ptr,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},1,1e9,"Arcana");
            debuffAllEnemyApply(bs,{{Stats::DEF_SHRED,AType::NONE,20.8}},"BS DefShred",3);
            if(ptr->eidolon>=2)dotAllEnemyStack(ptr,{DotType::WIND_SHEAR,DotType::BLEED,DotType::BURN,DotType::SHOCK},30,1e9,"Arcana");
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_LAST, [ptr,maxArcana](Enemy* target, double dotRatio,DotType dotType) {
            if (target->getStack("Arcana")){

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,"Arcana");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,240 + target->getStack("Arcana")*12),target);

            if(phaseStatus == PhaseStatus::DOT_BEFORE_TURN){
                act->traceType = TraceType::BLAST;
                if(target->nextToLeft){
                    act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToLeft);
                }
                if(target->nextToRight){
                    act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToRight);
                }
            }
            act->multiplyDmg(dotRatio);

            buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,20}});
            attack(act);
            buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,-20}});

            target->setStack("Arcana",min(maxArcana,target->getStack("Arcana")));
            
            if(phaseStatus == PhaseStatus::DOT_BEFORE_TURN){
                if(!target->getDebuff("Arcana Ignore"))target->setStack("Arcana",arcanaStacksAfterTick(target->getStack("Arcana")));
                else target->setDebuff("Arcana Ignore",0);
            }
        }
        }));

    }
}
