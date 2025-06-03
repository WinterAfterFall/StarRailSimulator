
#include "../include.h"

namespace  Anaxa{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void AdditionalSkill(Ally *ptr);
    void AnaxaDebuff(Ally *ptr, Enemy *enemy);


//temp


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(97,140,140,E,ElementType::Wind,"Erudition","Anaxa",TYPE_STD);
        ptr->SetAllyBaseStats(970,757,558);
        SubUnit *Anaxaptr = ptr->getSubUnit();


        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_ATK_P,ST_ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (sp>Sp_Safety||turn->turnCnt==1) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        // ptr->addUltCondition([ptr,Anaxaptr]() -> bool {
        //     SubUnit *Driverptr = Ally_unit[Driver_num]->Sub_Unit_ptr[0].get();
        //     if(Anaxaptr->Atv_stats->atv - Anaxaptr->Atv_stats->Max_atv*0.25 > Driverptr->Atv_stats->atv&&Anaxaptr->Atv_stats->atv!=0)
        //     return false;
        //     return true;
        // });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,Anaxaptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Ult,Anaxaptr,TT_AOE,"Anaxa Ult",
            [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Anaxa");
                for(auto &each : act->targetList){
                    each->debuffApply(Anaxaptr,"Sublimation",1);
                    each->weaknessApply(ElementType::Fire,1);
                    each->weaknessApply(ElementType::Ice,1);
                    each->weaknessApply(ElementType::Lightning,1);
                    each->weaknessApply(ElementType::Wind,1);
                    each->weaknessApply(ElementType::Quantum,1);
                    each->weaknessApply(ElementType::Imaginary,1);
                    each->weaknessApply(ElementType::Physical,1);
                }
                for(auto &each : act->targetList){
                    each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                    each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                    if(each->currentWeaknessElementAmount>=5){
                        each->DebuffNote["AnaxaDmgBonus"] = 30;
                        each->debuffSingle({{ST_DMG,AT_NONE,30}});
                    }
                }
    
                Attack(act);
    
                for(auto &each : act->targetList){
                    each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                    each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                    each->DebuffNote["AnaxaDmgBonus"] = 0;
                    each->DebuffNote["AnaxaA6"] = 0;
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Wind][AT_NONE] += 22.4;

            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 30;

            // relic
            // substats
            if(!ptr->Adjust["AnaxaA4"]){
                int cnt = 0;
                for(int i=1; i<=Total_ally;i++){
                    if(Ally_unit[i]->Path[0]=="Erudition")
                    cnt++;
                    
                }
                if(cnt>=2)ptr->Adjust["AnaxaA4"] = 2;
                else ptr->Adjust["AnaxaA4"] = 1;
            }
            if(ptr->Eidolon>=6){
                buffAllAlly({{ST_DMG,AT_NONE,50}});
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 140;
                
            }else if(ptr->Adjust["AnaxaA4"]==2){
                buffAllAlly({{ST_DMG,AT_NONE,50}});
            }else if(ptr->Adjust["AnaxaA4"]==1){
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 140;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            ptr->getSubUnit()->buffStackSingle({{ST_DEF_SHRED,AT_NONE,4}},3,7,"Qualitative Shift");
            for(int i=1; i<= Total_enemy ;i++){
                AnaxaDebuff(ptr,Enemy_unit[i].get());
                if(ptr->Eidolon>=2){
                    AnaxaDebuff(ptr,Enemy_unit[i].get());
                    Enemy_unit[i]->debuffSingleMark({{ST_RESPEN,AT_NONE,20}},ptr->getSubUnit(),"AnaxaE2");
                }
                
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
            enemy->isDebuffEnd("Sublimation");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            SubUnit *ally = turn->canCastToSubUnit();
            if(enemy){
                for(auto &e : Enemy_weak){
                    enemy->isDebuffEnd("AnaxaTalent" + toString(e.first) );
                }
                if(enemy->isDebuffEnd("AnaxaE1")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AT_NONE,-16}});
                }
            }
            if(ally){
                if(ally->isBuffEnd("AnaxaE4")){
                    ally->buffResetStack({{ST_ATK_P,AT_NONE,30}},"AnaxaE4");
                }
            }
        }));

        Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act) {
            if(act->Attacker->isSameUnitName("Anaxa")){
                if(ptr->Eidolon>=6){
                    for(auto &each1 : act->damageSplit){
                        for(auto &each2 : each1){
                            each2.dmgSrc.ATK *=1.3;
                            each2.dmgSrc.HP *=1.3;
                            each2.dmgSrc.DEF *=1.3;
                            each2.dmgSrc.constDmg *=1.3;
                        }
                    }
                }
            }

        }));

        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act) {
            if((act->actionName=="Anaxa BA"||act->actionName=="Anaxa Skill")){
                for(auto &each : act->targetList){
                    if(each->currentWeaknessElementAmount>=5){
                        AdditionalSkill(ptr);
                        break;
                    }
                }
            }
        }));
    }




    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Anaxa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            for(auto &each : act->targetList){
                AnaxaDebuff(ptr,each);
            }

            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BOUNCE,"Anaxa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->getSubUnit()->Atv_stats->turnCnt==1){
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=1){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                }
            }

            act->Attacker->buffSingle({{ST_DMG,AT_NONE,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)act->Attacker->buffStackSingle({{ST_ATK_P,AT_NONE,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            act->Attacker->buffSingle({{ST_DMG,AT_NONE,-20.0 * Total_enemy}});
        });
        act->addEnemyFairBounce(DmgSrc(DmgSrcType::ATK,70,10),5);
        act->addToActionBar();
    }
    void AdditionalSkill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BOUNCE,"Anaxa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->getSubUnit()->Atv_stats->turnCnt==1){
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=1){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                }
            }

            act->Attacker->buffSingle({{ST_DMG,AT_NONE,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)act->Attacker->buffStackSingle({{ST_ATK_P,AT_NONE,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            act->Attacker->buffSingle({{ST_DMG,AT_NONE,-20.0 * Total_enemy}});
        });
        act->addEnemyFairBounce(DmgSrc(DmgSrcType::ATK,70,10),5);
        act->setTurnReset(false);
        act->addToActionBar();
        Deal_damage();
    }
    void AnaxaDebuff(Ally *ptr, Enemy *enemy) {
        string element;
        element = toString(enemy->weaknessApplyChoose(3));
        enemy->debuffApply(ptr->getSubUnit(),"AnaxaTalent" + element,3);
    }
    

}