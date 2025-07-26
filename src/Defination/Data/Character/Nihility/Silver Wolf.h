#include "../include.h"

namespace SW{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(107,110,110,E,ElementType::Quantum,"Nihility","SW",TYPE_STD);
        ptr->SetAllyBaseStats(1048,640,461);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(ST_EHR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        #pragma region Ability
        SubUnit *sw = ptr->getSubUnit();

        ptr->Adjust["SW Targets amount"] = 1;
        
        function<void()> BA = [ptr,sw]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"SW BA",
            [sw](shared_ptr<AllyAttackAction> &act){
                Skill_point(sw,1);
                Increase_energy(sw,20);
                Attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,50,5),"Bug 2");
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,sw]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_SINGLE,"SW Skill",
            [sw](shared_ptr<AllyAttackAction> &act){
                Skill_point(sw,-1);
                Increase_energy(sw,30);
                for(auto &enemy : act->targetList){
                    for(int i=1;i<=Total_ally;i++){
                        if(enemy->Default_Weakness_type[Ally_unit[i]->Sub_Unit_ptr[0]->Element_type[0]])continue;
                        enemy->weaknessApply(Ally_unit[i]->Sub_Unit_ptr[0]->Element_type[0],3);
                        enemy->debuffSingleApply({{ST_RESPEN,Ally_unit[i]->Sub_Unit_ptr[0]->Element_type[0],AType::None,20}},sw,"SW Weakness",3);
                        sw->setBuffNote("SW Weakness num",i);
                        break;
                    }
                    enemy->debuffSingleApply({{ST_RESPEN,AType::None,13}},sw,"SW Res",2);
                }
                Attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,196,20),string("SW Res"),ptr->getAdjust("SW Targets amount"));
            act->addToActionBar();
        };

        #pragma endregion

        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get(),BA,Skill]() {
            for(int i = 1;i<= Total_enemy&&i<=ptr->Adjust["SW Targets amount"];i++){
                if(!Enemy_unit[i]->getDebuff("SW Res")){
                    Skill();
                    return;
                }
            }
            BA();
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,sw]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TT_AOE,"SW Ult",
            [ptr,sw](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply({
                    {ST_DEF_SHRED,AType::None,45}
                },sw,"SW Ult",3);
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
                        make_shared<AllyAttackAction>(AType::Addtional,ptr->getSubUnit(),TT_SINGLE,"SW AddDmg");
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
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Quantum][AType::None] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"][AType::None] += 18;

            // relic

            // Trace
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] += 50;

            if(ptr->Eidolon>=6){
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::None] += 100;
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
                if(enemy->isDebuffEnd("SW Weakness")){
                    enemy->debuffSingle({{ST_RESPEN,Ally_unit[sw->getBuffNote("SW Weakness num")]->Sub_Unit_ptr[0]->Element_type[0],AType::None,-20}});
                }
                if(enemy->isDebuffEnd("SW Res")){
                    enemy->debuffSingle({{ST_RESPEN,AType::None,-13}});
                }
                if(enemy->isDebuffEnd("SW Ult")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AType::None,-45}});
                }
                enemy->isDebuffEnd("Bug 1");
                if(enemy->isDebuffEnd("Bug 2")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AType::None,-12}});
                }
                if(enemy->isDebuffEnd("Bug 3")){
                    enemy->atkPercent+=10;
                    enemy->debuffSingle({{ST_SPD_P,AType::None,6}});
                }

            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sw]() {
            
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TT_AOE,"SW Technique",
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
                debuffAllEnemyMark({{ST_VUL,AType::None,20}},sw,"SW E2");
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,sw](shared_ptr<AllyAttackAction> &act) {
            if(ptr->Eidolon>=2||act->isSameUnit(sw)){
                for(auto &enemy : act->targetList){
                    if(!enemy->getDebuff("Bug 1")){
                        enemy->debuffApply(sw,"Bug 1",4);
                    }
                    else if(!enemy->getDebuff("Bug 2")){
                        enemy->debuffSingleApply({{ST_DEF_SHRED,AType::None,12}},sw,"Bug 2",4);
                    }
                    else {
                        enemy->debuffApply(sw,"Bug 1",4);
                        enemy->debuffSingleApply({{ST_DEF_SHRED,AType::None,12}},sw,"Bug 2",4);
                        if(enemy->debuffApply(sw,"Bug 3",4)){
                            enemy->atkPercent-=10;
                            enemy->debuffSingle({{ST_SPD_P,AType::None,-6}});
                        }
                    }
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,sw](Enemy *target, SubUnit *Trigger) {
                if(!target->getDebuff("Bug 1")){
                    target->debuffApply(sw,"Bug 1",4);
                }
                else if(!target->getDebuff("Bug 2")){
                    target->debuffSingleApply({{ST_DEF_SHRED,AType::None,12}},sw,"Bug 2",4);
                }
                else {
                    target->debuffApply(sw,"Bug 1",4);
                    target->debuffSingleApply({{ST_DEF_SHRED,AType::None,12}},sw,"Bug 2",4);
                    if(target->debuffApply(sw,"Bug 3",4)){
                        target->atkPercent-=10;
                        target->debuffSingle({{ST_SPD_P,AType::None,-6}});
                    }
                }
        }));
    }
}
