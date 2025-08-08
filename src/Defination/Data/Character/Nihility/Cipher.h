#include "../include.h"

namespace Cipher{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(105,130,130,E,ElementType::Quantum,Path::Nihility,"Cipher",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,660,509);

        //func


        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(170);
        if(ptr->Eidolon>=2)
            ptr->setApplyBaseChance(120);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        

        SubUnit *cph = ptr->getSubUnit(); 
        
        ptr->Adjust["Cipher A2"] = 2;
        ptr->Adjust["Cipher Ult Share"] = 1;
        ptr->Adjust["Cipher Use Only BA"] = 1;

        
        function<void()> BA = [ptr,cph]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Cipher BA",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                Skill_point(cph,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };
        function<void()> Skill = [ptr,cph]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Blast,"Cipher Skill",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                Skill_point(cph,-1);
                Increase_energy(ptr,30);
                for(auto &each : act->targetList){
                    if(each->debuffApply(cph,"Cipher Weaken",2)){
                        each->dmgPercent -= 10;
                    }
                }
                cph->buffSingle({{Stats::ATK_P,AType::None,30}},"Cipher Skill",2);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };
        
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,cph,BA,Skill]() {
            if(CharCmd::Using_Skill(ptr)&&!ptr->Adjust["Cipher Use Only BA"])Skill();
            else BA();
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,cph]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TraceType::Aoe,"Cipher Ult",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,120,10)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40,20),
                DmgSrc(DmgSrcType::ATK,40,20),
                DmgSrc(DmgSrcType::ATK,40,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 14;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 14.4;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 25 * ptr->getAdjust("Cipher A2");

            // ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 12;
            // ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 4;
            // ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 24;

            debuffAllEnemyMark({{Stats::VUL,AType::None,40}},ptr->Sub_Unit_ptr[0].get(),"Cipher A6");
            // relic

            // substats
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_Last,[ptr,cph](){
            if(turn->isSameUnitName("Cipher"))cph->setBuffCheck("Cipher Fua",0);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_Last,[ptr,cph](){
            auto enemy =  turn->canCastToEnemy();
            auto ally =  turn->canCastToSubUnit();
            if(ally){
                if(ally->isBuffEnd("Cipher Skill")){
                    ally->buffSingle({{Stats::ATK_P,AType::None,-30}});
                }
                if(ptr->Eidolon>=1&&ally->isBuffEnd("Cipher E1"))
                    ally->buffSingle({{Stats::ATK_P,AType::None,-80}});
            }
            if(enemy){
                if(enemy->isDebuffEnd("Cipher Weaken")){
                    enemy->dmgPercent +=10;
                }
                if(ptr->Eidolon>=2&&enemy->isDebuffEnd("Cipher E2")){
                    enemy->debuffSingle({{Stats::VUL,AType::None,-30}});
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_Last,[ptr,cph](){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TraceType::Aoe,"Cipher Tech",
                [ptr,cph](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                });
                newAct->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,100),
                    DmgSrc(DmgSrcType::ATK,100),
                    DmgSrc(DmgSrcType::ATK,100)
                );
                newAct->addToActionBar();
                Deal_damage();
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,cph](
            shared_ptr<AllyAttackAction> &act){
                if(ptr->Eidolon>=2&&act->isSameUnit(cph)){
                    for(auto &each : act->targetList){
                        each->debuffSingleApply({{Stats::VUL,AType::None,30}},cph,"Cipher E2",2);
                    }
                }
                if(act->isSameAction("Cipher",AType::SKILL)||act->isSameAction("Cipher",AType::Ult))
                    Enemy_unit[Main_Enemy_num]->debuffApply(cph,"Patron");

                if(!act->isSameUnitName("Cipher")&&!cph->getBuffCheck("Cipher Fua")){
                    cph->setBuffCheck("Cipher Fua",1);
                    shared_ptr<AllyAttackAction> newAct = 
                    make_shared<AllyAttackAction>(AType::Fua,ptr->getSubUnit(),TraceType::Single,"Cipher Fua",
                    [ptr,cph](shared_ptr<AllyAttackAction> &act){
                        Increase_energy(ptr,5);

                        if(ptr->Eidolon>=1)
                            cph->buffSingle({{Stats::ATK_P,AType::None,80}},"Cipher E1",2);

                        cph->buffSingle({{Stats::CD,AType::None,100}});
                        if(ptr->Eidolon>=6)cph->buffSingle({{Stats::DMG,AType::None,350}});
                        Attack(act);
                        cph->buffSingle({{Stats::CD,AType::None,-100}});
                        if(ptr->Eidolon>=6)cph->buffSingle({{Stats::DMG,AType::None,-350}});
                    });
                    newAct->addDamageIns(
                        DmgSrc(DmgSrcType::ATK,150,20)
                    );
                    newAct->addToActionBar();
                    Deal_damage();
                }
            }));

            
            AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_ACTTACK,[ptr,cph](
                shared_ptr<AllyAttackAction> &act, Enemy *src, double damage){
                    double percent = (src->Target_type == EnemyType::Main)
                    ? (12 * (1 + 0.5 * ptr->Adjust["Cipher A2"]))
                    : (8 * (1 + 0.5 * ptr->Adjust["Cipher A2"]));
                    
                    if(ptr->Eidolon>=6&&act->actionName=="Cipher Fua"){
                        percent += (16 * (1 + 0.5 * ptr->Adjust["Cipher A2"]));
                    }
                    if(ptr->Eidolon>=1)percent *= 1.5;
                    if(act->actionName=="Cipher Tech")percent *= 2;

                    for(int i=1;i<=ptr->getAdjust("Cipher Ult Share")&&i<=Total_enemy;i++){
                        Cal_DamageNote(act,src,Enemy_unit[i].get(),damage*percent/100,75.0/ptr->getAdjust("Cipher Ult Share"),"Cph True " + act->actionName);
                    }
                    Cal_DamageNote(act,src,Enemy_unit[Main_Enemy_num].get(),damage*percent/100,25,"Cph True " + act->actionName);
                            

                    if(ptr->Eidolon<6)return;
                    act->Attacker->ptrToChar->getSubUnit()
                    ->Buff_note["CipherNote" + src->getUnitName()] += damage * percent/100 * 0.2;
                    if(act->actionName!="Cipher Ult")return;
                    
                    double totaldmg = 0;
                    for(int i=1;i<=Total_ally;i++){
                        for(int j=1;j<=Total_enemy;j++){
                            totaldmg = Ally_unit[i]->getSubUnit()->getBuffNote("CipherNote" + Enemy_unit[j]->getUnitName());
                            for(int k=1;k<=ptr->getAdjust("Cipher Ult Share")&&k<=Total_enemy;k++){
                                act->Attacker = Ally_unit[i]->getSubUnit();
                                Cal_DamageNote(act,Enemy_unit[j].get(),Enemy_unit[k].get(),totaldmg*0.75/ptr->getAdjust("Cipher Ult Share"),100,"Cph E6 " + act->Attacker->getUnitName());
                            }
                            Cal_DamageNote(act,Enemy_unit[j].get(),Enemy_unit[Main_Enemy_num].get(),totaldmg*0.25,100,"Cph E6 " + act->Attacker->getUnitName());
                            Ally_unit[i]->getSubUnit()->Buff_note["CipherNote" + Enemy_unit[j]->getUnitName()] *= 0.2;
                        }  
                    }
                }));

            if(ptr->Eidolon>=4)    
                When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK,[ptr,cph](
                shared_ptr<AllyAttackAction> &act){
                    for(auto &each : act->targetList){
                        if(each->getDebuff("Patron")){
                            shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(
                                AType::Addtional,cph,TraceType::Single,"Cipher E4");
                            newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,50));
                            Attack(newAct);
                            break;
                        }
                    }
                }));
    }
}
