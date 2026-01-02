
#include "../include.h"

namespace  Anaxa{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void AnaxaDebuff(CharUnit *ptr, Enemy *enemy);


//temp


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(97,140,140,E,ElementType::Wind,Path::Erudition,"Anaxa",UnitType::Standard);
        ptr->SetAllyBaseStats(970,757,558);
        AllyUnit *Anaxaptr = ptr;


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
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            allyPtr->setBuffCheck("AnaxaTalent",true);
            if (sp>Sp_Safety||turn->turnCnt==1) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        // ptr->addUltCondition([ptr,Anaxaptr]() -> bool {
        //     AllyUnit *Driverptr = Ally_unit[Driver_num].get();
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
                    debuffApply(Anaxaptr,each,"Sublimation",1);
                    weaknessApply(each,ElementType::Fire,1);
                    weaknessApply(each,ElementType::Ice,1);
                    weaknessApply(each,ElementType::Lightning,1);
                    weaknessApply(each,ElementType::Wind,1);
                    weaknessApply(each,ElementType::Quantum,1);
                    weaknessApply(each,ElementType::Imaginary,1);
                    weaknessApply(each,ElementType::Physical,1);
                }
                for(auto &each : act->targetList){
                    each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                    debuffSingle(each,{{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                    if(each->currentWeaknessElementAmount>=5){
                        each->DebuffNote["AnaxaDmgBonus"] = 30;
                        debuffSingle(each,{{Stats::DMG,AType::None,30}});
                    }
                }
    
                Attack(act);
    
                for(auto &each : act->targetList){
                    debuffSingle(each,{{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                    debuffSingle(each,{{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
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
            ptr->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Stats_type[Stats::HP_P][AType::None] += 10;
            ptr->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 22.4;

            ptr->Stats_type[Stats::DMG][AType::None] += 30;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            if(!ptr->Adjust["AnaxaA4"]){
                int cnt = 0;
                for(int i=1; i<=Total_ally;i++){
                    if(charUnit[i]->path[0]==Path::Erudition)
                    cnt++;
                    
                }
                if(cnt>=2)ptr->Adjust["AnaxaA4"] = 2;
                else ptr->Adjust["AnaxaA4"] = 1;
            }
            if(ptr->Eidolon>=6){
                buffAllAlly({{Stats::DMG,AType::None,50}});
                ptr->Stats_type[Stats::CD][AType::None] += 140;
                
            }else if(ptr->Adjust["AnaxaA4"]==2){
                buffAllAlly({{Stats::DMG,AType::None,50}});
            }else if(ptr->Adjust["AnaxaA4"]==1){
                ptr->Stats_type[Stats::CD][AType::None] += 140;
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            buffStackSingle(ptr,{{Stats::DEF_SHRED,AType::None,4}},3,7,"Qualitative Shift");
            for(auto &each : enemyList){
                AnaxaDebuff(ptr,each);
                if(ptr->Eidolon>=2){
                    AnaxaDebuff(ptr,each);
                    debuffSingleMark(ptr,each,{{Stats::RESPEN,AType::None,20}},"AnaxaE2");
                }
                
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
            isDebuffEnd(enemy,"Sublimation");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            AllyUnit *ally = turn->canCastToSubUnit();
            if(enemy){
                for(auto &e : Enemy_weak){
                    isDebuffEnd(enemy,"AnaxaTalent" + toString(e.first) );
                }
                if(isDebuffEnd(enemy,"AnaxaE1")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-16}});
                }
            }
            if(ally){
                if(isBuffEnd(ally,"AnaxaE4")){
                    buffResetStack(ally,{{Stats::ATK_P,AType::None,30}},"AnaxaE4");
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyAttackAction> &act) {
            if(act->Attacker->isSameStatsOwnerName("Anaxa")){
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
                if(Anaxaptr->getBuffCheck("AnaxaTalent"))
                for(auto &each : act->targetList){
                    Skill(ptr);
                    if(each->currentWeaknessElementAmount>=5){
                        Deal_damage();
                        Anaxaptr->setBuffCheck("AnaxaTalent",false);
                        break;
                    }
                }
                else Anaxaptr->setBuffCheck("AnaxaTalent",true);
            }
        }));
    }




    void Basic_Atk(CharUnit *ptr){
        
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Anaxa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(charUnit[ptr->Atv_stats->num].get(),30);
            for(auto &each : act->targetList){
                AnaxaDebuff(ptr,each);
            }

            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                debuffSingle(each,{{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    debuffSingle(each,{{Stats::DMG,AType::None,30}});
                }
            }

            Attack(act);

            for(auto &each : act->targetList){
                debuffSingle(each,{{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                debuffSingle(each,{{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){

        Skill_point(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Bounce,"Anaxa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(charUnit[ptr->Atv_stats->num].get(),30);
            if(!ptr->getBuffCheck("AnaxaFirstTurn")){
                ptr->setBuffCheck("AnaxaFirstTurn",true);
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=1){
                    Skill_point(ptr,1);
                }
            }

            buffSingle(act->Attacker,{{Stats::DMG,AType::None,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)buffStackSingle(act->Attacker,{{Stats::ATK_P,AType::None,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::None,16}},"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                debuffSingle(each,{{Stats::DEF_SHRED,AType::None,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    debuffSingle(each,{{Stats::DMG,AType::None,30}});
                }
            }
            CharCmd::printText("Anaxa Skill");
            Attack(act);

            for(auto &each : act->targetList){
                debuffSingle(each,{{Stats::DEF_SHRED,AType::None, -each->DebuffNote["AnaxaA6"]}});
                debuffSingle(each,{{Stats::DMG,AType::None, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            buffSingle(act->Attacker,{{Stats::DMG,AType::None,-20.0 * Total_enemy}});
        });
        act->addEnemyFairBounce(DmgSrc(DmgSrcType::ATK,70,10),5);
        act->addToActionBar();
    }
    void AnaxaDebuff(CharUnit *ptr, Enemy *enemy) {
        string element;
        element = toString(weaknessApplyChoose(enemy,3));
        debuffApply(ptr,enemy,"AnaxaTalent" + element,3);
    }
    

}