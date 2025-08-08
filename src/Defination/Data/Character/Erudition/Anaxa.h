
#include "../include.h"

namespace  Anaxa{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void AdditionalSkill(Ally *ptr);
    void AnaxaDebuff(Ally *ptr, Enemy *enemy);


//temp


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(97,140,140,E,ElementType::Wind,Path::Erudition,"Anaxa",UnitType::Standard);
        ptr->SetAllyBaseStats(970,757,558);
        SubUnit *Anaxaptr = ptr->getSubUnit();


        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::ATK_P,Stats::ATK_P);



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
            make_shared<AllyAttackAction>(AType::Ult,Anaxaptr,TraceType::Aoe,"Anaxa Ult",
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
                    each->debuffSingle({{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                    if(each->currentWeaknessElementAmount>=5){
                        each->DebuffNote["AnaxaDmgBonus"] = 30;
                        each->debuffSingle({{Stats::DMG,AType::None,30}});
                    }
                }
    
                Attack(act);
    
                for(auto &each : act->targetList){
                    each->debuffSingle({{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                    each->debuffSingle({{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
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
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 22.4;

            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 30;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            if(!ptr->Adjust["AnaxaA4"]){
                int cnt = 0;
                for(int i=1; i<=Total_ally;i++){
                    if(Ally_unit[i]->path[0]==Path::Erudition)
                    cnt++;
                    
                }
                if(cnt>=2)ptr->Adjust["AnaxaA4"] = 2;
                else ptr->Adjust["AnaxaA4"] = 1;
            }
            if(ptr->Eidolon>=6){
                buffAllAlly({{Stats::DMG,AType::None,50}});
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 140;
                
            }else if(ptr->Adjust["AnaxaA4"]==2){
                buffAllAlly({{Stats::DMG,AType::None,50}});
            }else if(ptr->Adjust["AnaxaA4"]==1){
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 140;
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            ptr->getSubUnit()->buffStackSingle({{Stats::DEF_SHRED,AType::None,4}},3,7,"Qualitative Shift");
            for(int i=1; i<= Total_enemy ;i++){
                AnaxaDebuff(ptr,Enemy_unit[i].get());
                if(ptr->Eidolon>=2){
                    AnaxaDebuff(ptr,Enemy_unit[i].get());
                    Enemy_unit[i]->debuffSingleMark({{Stats::RESPEN,AType::None,20}},ptr->getSubUnit(),"AnaxaE2");
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
                    enemy->debuffSingle({{Stats::DEF_SHRED,AType::None,-16}});
                }
            }
            if(ally){
                if(ally->isBuffEnd("AnaxaE4")){
                    ally->buffResetStack({{Stats::ATK_P,AType::None,30}},"AnaxaE4");
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act) {
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

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act) {
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
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Anaxa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            for(auto &each : act->targetList){
                AnaxaDebuff(ptr,each);
            }

            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{Stats::DMG,AType::None,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
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
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Bounce,"Anaxa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->getSubUnit()->Atv_stats->turnCnt==1){
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=1){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                }
            }

            act->Attacker->buffSingle({{Stats::DMG,AType::None,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)act->Attacker->buffStackSingle({{Stats::ATK_P,AType::None,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{Stats::DEF_SHRED,AType::None,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{Stats::DMG,AType::None,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            act->Attacker->buffSingle({{Stats::DMG,AType::None,-20.0 * Total_enemy}});
        });
        act->addEnemyFairBounce(DmgSrc(DmgSrcType::ATK,70,10),5);
        act->addToActionBar();
    }
    void AdditionalSkill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Bounce,"Anaxa ExtraSkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);

            act->Attacker->buffSingle({{Stats::DMG,AType::None,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)act->Attacker->buffStackSingle({{Stats::ATK_P,AType::None,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{Stats::DEF_SHRED,AType::None,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{Stats::DMG,AType::None,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                each->debuffSingle({{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            act->Attacker->buffSingle({{Stats::DMG,AType::None,-20.0 * Total_enemy}});
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