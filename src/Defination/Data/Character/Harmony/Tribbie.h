#include "../include.h"

namespace Tribbie{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Print_Stats(CharUnit *ptr);

    



//temp
    void Skill(CharUnit *ptr);
    void Basic_Atk(CharUnit *ptr);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(96,120,120,E,ElementType::Quantum,Path::Harmony,"Tribbie",UnitType::Standard);
        AllyUnit *TBptr = ptr->getMemosprite();
        ptr->SetAllyBaseStats(1048,524,728);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(Stats::CR,Stats::HP_P,Stats::HP_P,Stats::ER);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->getBuffCheck("Numinosity")) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        ptr->Char.Print_Func = Print_Stats;
        ptr->addUltCondition([ptr,TBptr]() -> bool {
            if (ptr->Light_cone.Name == "DDD" && chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->atv <= 0) return false;
            if (ptr->Light_cone.Name == "DDD" && Driver_num != 0 && charUnit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return false;
            if (ptr->Light_cone.Name == "Eagle_Beaked_Helmet" && ptr->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TBptr]() {
            if (!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getMemosprite(),TraceType::Aoe,"TB Ult",
            [ptr,TBptr](shared_ptr<AllyAttackAction> &act){
                if (TBptr->isHaveToAddBuff("Tribbie_Zone",2)) {
                        debuffAllEnemyMark({{Stats::VUL,AType::None,30}},ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone");
    
                    // A4 Trace
                    ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                    for (int i = 1; i <= Total_ally; i++) {
                        ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] += calculateHpForBuff(charUnit[i]->Sub_Unit_ptr[0].get(), 9);
                    }
                    TBptr->buffSingle({{Stats::FLAT_HP, AType::TEMP , ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                    TBptr->buffSingle({{Stats::FLAT_HP, AType::None, ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
    
                    if (ptr->Eidolon >= 4) {
                        buffAllAlly({{Stats::DEF_SHRED, AType::None, 18}});
                    }
                }
                for (int i = 1; i <= Total_ally; i++) {
                    if (i == ptr->Sub_Unit_ptr[0]->Atv_stats->num) continue;
                    charUnit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"] = 0;
                }
                Attack(act);
                
                if (ptr->Print)CharCmd::printUltStart("Tribbie");
                if (ptr->Eidolon >= 6) {
                    shared_ptr<AllyAttackAction> data_2 = 
                    make_shared<AllyAttackAction>(AType::Fua,ptr->getMemosprite(),TraceType::Aoe,"TB Fua",
                    [ptr](shared_ptr<AllyAttackAction> &act){
                        Increase_energy(ptr, 5);
                        Attack(act);
                    });
                    data_2->addDamageIns(
                        DmgSrc(DmgSrcType::HP,18,5),
                        DmgSrc(DmgSrcType::HP,18,5),
                        DmgSrc(DmgSrcType::HP,18,5)
                    );
                    data_2->addToActionBar();
                    Deal_damage();
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,30,20),
                DmgSrc(DmgSrcType::HP,30,20),
                DmgSrc(DmgSrcType::HP,30,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 10;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Fua] += 729;
            }
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (TBptr->isBuffEnd("Tribbie_Zone")) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"] = 0;
                for(int i=1;i<=Total_enemy;i++){
                    enemyUnit[i]->debuffRemove("Tribbie_Zone");
                    enemyUnit[i]->debuffSingle({{Stats::VUL,AType::None,-30}});
                }
                if (ptr->Eidolon >= 4) {
                    buffAllAlly({{Stats::DEF_SHRED, AType::None, -18}});
                }

                TBptr->buffSingle({{Stats::FLAT_HP, AType::TEMP , -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                TBptr->buffSingle({{Stats::FLAT_HP, AType::None, -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});

                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                if (ptr->Print)CharCmd::printUltEnd("Tribbie");
            }
            if (TBptr->isBuffEnd("Numinosity")) {
                buffAllAlly({{Stats::RESPEN, AType::None, -24}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (TBptr->isBuffEnd("Tribbie_A2")) {
                TBptr->buffResetStack({{Stats::DMG, AType::None, 72}},"Tribbie_A2");
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            Increase_energy(ptr, 30);
            buffAllAlly({{Stats::RESPEN, AType::None, 24}});
            TBptr->isHaveToAddBuff("Numinosity", 3);
        }));
        
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
            int temp = act->targetList.size();
            if (act->isSameAttack("Tribbie",AType::Fua)) {
                TBptr->buffStackSingle({{Stats::DMG, AType::None, 72}},1,3,"Tribbie_A2",3);
            }
            Increase_energy(ptr, (1.5) * temp);
            if (TBptr->getBuffCheck("Tribbie_Zone")) {
                shared_ptr<AllyAttackAction> data_1 = 
                make_shared<AllyAttackAction>(AType::Addtional,ptr->getMemosprite(),TraceType::Single,"TB AddDmg");
                if (ptr->Eidolon >= 2) {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,14.4 * (temp + 1)));
                } else {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,12 * temp));
                }

                Attack(data_1);
            }
            if (act->isSameAttack(AType::Ult)&& act->Attacker->getBuffCheck("Tribbie_ult_launch") == 0 && act->Attacker->Atv_stats->UnitName != "Tribbie" && act->Attacker->Atv_stats->side == Side::Ally) {
                act->Attacker->Buff_check["Tribbie_ult_launch"] = 1;
                shared_ptr<AllyAttackAction> data_2 = 
                make_shared<AllyAttackAction>(AType::Fua,ptr->getMemosprite(),TraceType::Aoe,"TB Fua",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Increase_energy(ptr, 5);
                    Attack(act);
                });
                data_2->addDamageIns(
                    DmgSrc(DmgSrcType::HP,18,5),
                    DmgSrc(DmgSrcType::HP,18,5),
                    DmgSrc(DmgSrcType::HP,18,5)
                );
                data_2->addToActionBar();
                Deal_damage();
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,TBptr](AllyUnit *target, Stats StatsType) {
            if (!TBptr->getBuffCheck("Tribbie_Zone")) return;
            if (StatsType == Stats::HP_P || StatsType == Stats::FLAT_HP) {
                // adjust
                double temp = 0;
                for (int i = 1; i <= Total_ally; i++) {
                    temp += calculateHpForBuff(charUnit[i]->Sub_Unit_ptr[0].get(), 9);
                }
                
                // after
                TBptr->buffSingle({{Stats::FLAT_HP, AType::TEMP , temp - ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                TBptr->buffSingle({{Stats::FLAT_HP, AType::None, temp - ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = temp;
                return;
            }
        }));  
        if(ptr->Eidolon>=1){
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
                if(TBptr->getBuffCheck("Tribbie_Zone"))TBptr->setBuffCheck("TB_TrueDmg",1);
            }));
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
                TBptr->setBuffCheck("TB_TrueDmg",0);
            }));
            AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,TBptr]
                (shared_ptr<AllyAttackAction> &act, Enemy *src, double damage) {
                if(!TBptr->getBuffCheck("TB_TrueDmg"))return;
                Cal_DamageNote(act,src,enemyUnit[Main_Enemy_num].get(),damage,24,"TB True " + act->actionName);
            }));
        }

    }


    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getMemosprite(),TraceType::Blast,"TB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,30,10),
            DmgSrc(DmgSrcType::HP,15,5)
        );
        act->addToActionBar();
    }
    
    void Skill(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Aoe,"TB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            buffAllAlly({{Stats::RESPEN,AType::None,24}});
            ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Numinosity", 3);
        });
        act->addBuffAllAllies();
        act->addToActionBar();
    }






    void Print_Stats(CharUnit *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]<<" ";
        for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Sub_Unit_ptr[0]->Atv_stats->num)continue;
                cout<<charUnit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"]<<" ";
            }
    }
}