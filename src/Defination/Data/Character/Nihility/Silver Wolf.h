#include "../include.h"

namespace SW{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(107,110,110,E,ElementType::Quantum,Path::Nihility,"SW",UnitType::Standard);
        ptr->SetAllyBaseStats(1048,640,461);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        #pragma region Ability
        AllyUnit *sw = ptr;

        ptr->Adjust["SW Targets amount"] = 1;
        
        function<void()> BA = [ptr,sw]() {
            genSkillPoint(sw,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"SW BA",
            [sw](shared_ptr<AllyAttackAction> &act){
                Increase_energy(sw,20);
                Attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,50,5),"Bug 2");
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,sw]() {
            genSkillPoint(sw,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Single,"SW Skill",
            [sw](shared_ptr<AllyAttackAction> &act){
                Increase_energy(sw,30);
                for(auto &enemy : act->targetList){
                    for(int i=1;i<=Total_ally;i++){
                        if(enemy->Default_Weakness_type[charUnit[i]->Element_type[0]])continue;
                        weaknessApply(enemy,charUnit[i]->Element_type[0],3);
                        debuffSingleApply(sw,enemy,{{Stats::RESPEN,charUnit[i]->Element_type[0],AType::None,20}},"SW Weakness",3);
                        sw->setBuffNote("SW Weakness num",i);
                        break;
                    }
                    debuffSingleApply(sw,enemy,{{Stats::RESPEN,AType::None,13}},"SW Res",2);
                }
                Attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,196,20),string("SW Res"),ptr->getAdjust("SW Targets amount"));
            act->addToActionBar();
        };

        #pragma endregion

        ptr->Turn_func = [ptr, allyPtr = ptr,BA,Skill]() {
            for(int i = 1;i<= Total_enemy&&i<=ptr->Adjust["SW Targets amount"];i++){
                if(!enemyUnit[i]->getDebuff("SW Res")){
                    Skill();
                    return;
                }
            }
            BA();
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,sw]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"SW Ult",
            [ptr,sw](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(sw,{
                    {Stats::DEF_SHRED,AType::None,45}
                },"SW Ult",3);
                Attack(act);
                if(ptr->Eidolon>=1){
                    int debuffcnt = 0;
                    for(auto &enemy : act->targetList){
                        debuffcnt += enemy->Total_debuff;
                    }
                    debuffcnt = (debuffcnt>=5) ? 5 : debuffcnt;
                    Increase_energy(sw,7*debuffcnt);
                }
                if(ptr->Eidolon>=4){
                    int debuffcnt = 0;
                    for(auto &enemy : act->targetList){
                        debuffcnt = (enemy->Total_debuff>=5) ? 5 : enemy->Total_debuff;
                        shared_ptr<AllyAttackAction> add = 
                        make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"SW AddDmg");
                            add->addDamageIns(DmgSrc(DmgSrcType::ATK,20*debuffcnt),enemy);  
                        Attack(add);
                    }
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,380,20),
                DmgSrc(DmgSrcType::ATK,380,20),
                DmgSrc(DmgSrcType::ATK,380,20)
            );
            act->addToActionBar();
            Deal_damage();

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 8;
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_type[Stats::EHR][AType::None] += 18;

            // relic

            // Trace
            ptr->Stats_type[Stats::ATK_P][AType::None] += 50;

            if(ptr->Eidolon>=6){
            ptr->Stats_type[Stats::DMG][AType::None] += 100;
            }

        }));
               
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sw]() {

            if(turn->isSameUnit(sw)){
                Increase_energy(sw,5);
            }
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sw]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
                if(isDebuffEnd(enemy,"SW Weakness")){
                    debuffSingle(enemy,{{Stats::RESPEN,charUnit[sw->getBuffNote("SW Weakness num")]->Element_type[0],AType::None,-20}});
                }
                if(isDebuffEnd(enemy,"SW Res")){
                    debuffSingle(enemy,{{Stats::RESPEN,AType::None,-13}});
                }
                if(isDebuffEnd(enemy,"SW Ult")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-45}});
                }
                isDebuffEnd(enemy,"Bug 1");
                if(isDebuffEnd(enemy,"Bug 2")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-12}});
                }
                if(isDebuffEnd(enemy,"Bug 3")){
                    enemy->atkPercent+=10;
                    debuffSingle(enemy,{{Stats::SPD_P,AType::None,6}});
                }

            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sw]() {
            
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"SW Technique",
                [sw](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,80,20),
                    DmgSrc(DmgSrcType::ATK,80,20),
                    DmgSrc(DmgSrcType::ATK,80,20)
                );
                act->Dont_care_weakness = 100;
                act->addToActionBar();
                Deal_damage();
            }
            Increase_energy(sw,20);

            if(ptr->Eidolon>=2){
                debuffAllEnemyMark({{Stats::VUL,AType::None,20}},sw,"SW E2");
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,sw](shared_ptr<AllyAttackAction> &act) {
            if(ptr->Eidolon>=2||act->isSameName(sw)){
                for(auto &enemy : act->targetList){
                    if(!enemy->getDebuff("Bug 1")){
                        debuffApply(sw,enemy,"Bug 1",4);
                    }
                    else if(!enemy->getDebuff("Bug 2")){
                        debuffSingleApply(sw,enemy,{{Stats::DEF_SHRED,AType::None,12}},"Bug 2",4);
                    }
                    else {
                        debuffApply(sw,enemy,"Bug 1",4);
                        debuffSingleApply(sw,enemy,{{Stats::DEF_SHRED,AType::None,12}},"Bug 2",4);
                        if(debuffApply(sw,enemy,"Bug 3",4)){
                            enemy->atkPercent-=10;
                            debuffSingle(enemy,{{Stats::SPD_P,AType::None,-6}});
                        }
                    }
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,sw](Enemy *target, AllyUnit *Trigger) {
                if(!target->getDebuff("Bug 1")){
                    debuffApply(sw,target,"Bug 1",4);
                }
                else if(!target->getDebuff("Bug 2")){
                    debuffSingleApply(sw,target,{{Stats::DEF_SHRED,AType::None,12}},"Bug 2",4);
                }
                else {
                    debuffApply(sw,target,"Bug 1",4);
                    debuffSingleApply(sw,target,{{Stats::DEF_SHRED,AType::None,12}},"Bug 2",4);
                    if(debuffApply(sw,target,"Bug 3",4)){
                        target->atkPercent-=10;
                        debuffSingle(target,{{Stats::SPD_P,AType::None,-6}});
                    }
                }
        }));
    }
}
