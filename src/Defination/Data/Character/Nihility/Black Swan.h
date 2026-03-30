#include "../include.h"

namespace BS{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(102,120,120,E,ElementType::Wind,Path::Nihility,"Black Swan",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,660,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setEhrRequire(120);
        ptr->setRelicMainStats(Stats::EHR,Stats::ATK_P,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *bs = ptr;
        #pragma region Ability

        function<void()> BA = [ptr,bs]() {
            genSkillPoint(bs,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"BS BA",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,20);
                Attack(act);
            }); 
            act->addDamageInsByDebuff(
                DmgSrc(DmgSrcType::ATK,100,10),"BS DefShred"
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,bs]() {
            genSkillPoint(bs,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"BS Skill",
            [ptr,bs](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,30);
                for(auto &each : act->targetList){
                    debuffSingleApply(bs,each,{{Stats::DEF_SHRED,AType::None,20.8}},"BS DefShred",3);
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
                if(ptr->Eidolon>=4)debuffAllEnemyApply(ptr,{{Stats::VUL,AType::None,45}},"Epiphany",2);
                else debuffAllEnemyApply(ptr,{{Stats::VUL,AType::None,25}},"Epiphany",2);
                for(auto &each : act->targetList){
                    dotSingleStack(bs,each,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},each->getStack("Arcana")/2,1e9,"Arcana");
                    each->setDebuff("Arcana Ignore",1);
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

            if(ptr->Eidolon>=6)ptr->setStack("Arcana Maximum",80);
            else ptr->setStack("Arcana Maximum",50);
        }));

        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,bs](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameDamageType(AType::Dot))return;
            for(auto & each : act->targetList){
                dotSingleStack(ptr,each,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},5,1e9,"Arcana");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy* enemy = turn->canCastToEnemy();
            if(!enemy)return;

            if(isDebuffEnd(enemy,"BS DefShred")){
                debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-20.8}});
            }

            if(isDebuffEnd(enemy,"Epiphany")){
                if(ptr->Eidolon>=4)debuffSingle(enemy,{{Stats::VUL,AType::None,-45}});
                else debuffSingle(enemy,{{Stats::VUL,AType::None,-25}});
                enemy->setDebuff("Arcana Ignore",0);
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameCharName(ptr)){
                debuffEnemyTargetsApply(ptr,act->targetList,{{Stats::DEF_SHRED,AType::None,20.8}},"BS DefShred",3);
                for(auto &each : act->targetList){
                    dotSingleStack(ptr,each,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},5,1e9,"Arcana");
                }
            }else if(ptr->Eidolon>=6){
                for(auto &each : act->targetList){
                    dotSingleStack(ptr,each,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},1,1e9,"Arcana");
                }
            }
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,bs]() {
            buffAllAlly({{Stats::DMG,AType::None,72}});
            if(ptr->Eidolon>=1)debuffAllEnemyApply(bs,{
                {Stats::RESPEN,ElementType::Wind,AType::None,25},
                {Stats::RESPEN,ElementType::Lightning,AType::None,25},
                {Stats::RESPEN,ElementType::Physical,AType::None,25},
                {Stats::RESPEN,ElementType::Fire,AType::None,25}}
                ,"BS E1");
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,bs]() {
            if(ptr->Technique)dotAllEnemyStack(ptr,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},2,1e9,"Arcana");
            dotAllEnemyStack(ptr,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},1,1e9,"Arcana");
            debuffAllEnemyApply(bs,{{Stats::DEF_SHRED,AType::None,20.8}},"BS DefShred",3);
            if(ptr->Eidolon>=2)dotAllEnemyStack(ptr,{DotType::WindShear,DotType::Bleed,DotType::Burn,DotType::Shock},30,1e9,"Arcana");
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_Last, [ptr,bs](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (target->getStack("Arcana")){

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Shock,ptr,TraceType::Single,"Arcana");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,240 + target->getStack("Arcana")*12),target);

            if(phaseStatus == PhaseStatus::DotBeforeTurn){
                act->traceType = TraceType::Blast;
                if(target->nextToLeft){
                    act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToLeft);
                }
                if(target->nextToRight){
                    act->addDamageHit(DmgSrc(DmgSrcType::ATK,180),target->nextToRight);
                }
            }
            act->multiplyDmg(Dot_ratio);

            buffSingle(ptr,{{Stats::DEF_SHRED,AType::None,20}});
            Attack(act);
            buffSingle(ptr,{{Stats::DEF_SHRED,AType::None,-20}});

            if(phaseStatus == PhaseStatus::DotBeforeTurn){
                if(!target->getDebuff("Arcana Ignore"))target->setStack("Arcana",min(25,target->getStack("Arcana")/2));
                else target->setDebuff("Arcana Ignore",0);
            }
        }
        }));

    }
}
