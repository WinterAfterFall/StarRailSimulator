
#ifndef Tribbie_H
#define Tribbie_H

#define F first
#define S second
#include "../Library.h"

namespace Tribbie{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Print_Stats(Ally *ptr);

    



//temp
    void Skill(Ally *ptr);
    void Basic_Atk(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(96,120,120,E,ElementType::Quantum,"Harmony","Tribbie",TYPE_STD);
        SubUnit *TBptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1048,524,728);
        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Hp%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CR,ST_HP_P,ST_HP_P,ST_EnergyRecharge);



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
            if (ptr->Light_cone.Name == "DDD" && Driver_num != 0 && Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return false;
            if (ptr->Light_cone.Name == "Eagle_Beaked_Helmet" && ptr->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TBptr]() {
            if (!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"TB Ult",
            [ptr,TBptr](shared_ptr<AllyAttackAction> &act){
                if (TBptr->isHaveToAddBuff("Tribbie_Zone",2)) {
                        debuffAllEnemyMark({{ST_VUL,AT_NONE,30}},ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone");
    
                    // A4 Trace
                    ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                    for (int i = 1; i <= Total_ally; i++) {
                        ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] += calculateHpForBuff(Ally_unit[i]->Sub_Unit_ptr[0].get(), 9);
                    }
                    TBptr->buffSingle({{ST_FLAT_HP, AT_TEMP , ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                    TBptr->buffSingle({{ST_FLAT_HP, AT_NONE, ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
    
                    // Eidolon 1
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{"True_Damage", AT_NONE, 24}});
                    }
                    if (ptr->Eidolon >= 4) {
                        buffAllAlly({{ST_DEF_SHRED, AT_NONE, 18}});
                    }
                }
                for (int i = 1; i <= Total_ally; i++) {
                    if (i == ptr->Sub_Unit_ptr[0]->Atv_stats->num) continue;
                    Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"] = 0;
                }
                Attack(act);
                
                if (ptr->Print)CharCmd::printUltStart("Tribbie");
                if (ptr->Eidolon >= 6) {
                    shared_ptr<AllyAttackAction> data_2 = 
                    make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_AOE,"TB Fua",
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
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 10;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Fua"] += 729;
            }
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (TBptr->isBuffEnd("Tribbie_Zone")) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"] = 0;
                for(int i=1;i<=Total_enemy;i++){
                    Enemy_unit[i]->debuffRemove("Tribbie_Zone");
                    Enemy_unit[i]->debuffSingle({{ST_VUL,AT_NONE,-30}});
                }
                if (ptr->Eidolon >= 1) {
                    buffAllAlly({{"True_Damage", AT_NONE, -24}});
                }
                if (ptr->Eidolon >= 4) {
                    buffAllAlly({{ST_DEF_SHRED, AT_NONE, -18}});
                }

                TBptr->buffSingle({{ST_FLAT_HP, AT_TEMP , -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                TBptr->buffSingle({{ST_FLAT_HP, AT_NONE, -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});

                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                if (ptr->Print)CharCmd::printUltEnd("Tribbie");
            }
            if (TBptr->isBuffEnd("Numinosity")) {
                buffAllAlly({{"Respen", AT_NONE, -24}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (TBptr->isBuffEnd("Tribbie_A2")) {
                TBptr->buffResetStack({{ST_DMG, AT_NONE, 72}},"Tribbie_A2");
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            Increase_energy(ptr, 30);
            buffAllAlly({{"Respen", AT_NONE, 24}});
            TBptr->isHaveToAddBuff("Numinosity", 3);
        }));
        
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
            int temp = act->targetList.size();
            if (act->isSameAttack("Tribbie",AT_FUA)) {
                TBptr->buffStackSingle({{ST_DMG, AT_NONE, 72}},1,3,"Tribbie_A2",3);
            }
            Increase_energy(ptr, (1.5) * temp);
            if (TBptr->getBuffCheck("Tribbie_Zone")) {
                shared_ptr<AllyAttackAction> data_1 = 
                make_shared<AllyAttackAction>(ActionType::Addtional,ptr->getSubUnit(),TT_SINGLE,"TB AddDmg");
                if (ptr->Eidolon >= 2) {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,14.4));
                } else {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,12));
                }

                Attack(data_1);
            }
            if (act->isSameAttack(AT_ULT)&& act->Attacker->getBuffCheck("Tribbie_ult_launch") == 0 && act->Attacker->Atv_stats->Char_Name != "Tribbie" && act->Attacker->Atv_stats->Side == "Ally") {
                act->Attacker->Buff_check["Tribbie_ult_launch"] = 1;
                shared_ptr<AllyAttackAction> data_2 = 
                make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_AOE,"TB Fua",
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

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,TBptr](SubUnit *target, string StatsType) {
            if (!TBptr->getBuffCheck("Tribbie_Zone")) return;
            if (StatsType == "Hp%" || StatsType == "Flat_Hp") {
                // adjust
                double temp = 0;
                for (int i = 1; i <= Total_ally; i++) {
                    temp += calculateHpForBuff(Ally_unit[i]->Sub_Unit_ptr[0].get(), 9);
                }
                
                // after
                TBptr->buffSingle({{ST_FLAT_HP, AT_TEMP , temp - ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                TBptr->buffSingle({{ST_FLAT_HP, AT_NONE, temp - ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = temp;
                return;
            }
        }));  
        if(ptr->Eidolon>=1){
            Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
                if(TBptr->getBuffCheck("Tribbie_Zone"))TBptr->setBuffCheck("TB_TrueDmg",1);
            }));
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
                TBptr->setBuffCheck("TB_TrueDmg",0);
            }));
            AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,TBptr]
                (shared_ptr<AllyAttackAction> &act, Enemy *src, double damage) {
                if(!TBptr->getBuffCheck("TB_TrueDmg"))return;
                Cal_DamageNote(act,src,Enemy_unit[Main_Enemy_num].get(),damage,24,"TB True" + act->actionName);
            }));
        }

    }


    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_BLAST,"TB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
                        Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,30,10),
            DmgSrc(DmgSrcType::HP,15,5)
        );
        act->addToActionBar();
    }
    
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"TB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            buffAllAlly({{"Respen",AT_NONE,24}});
            ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Numinosity", 3);
        });
        act->addBuffAllAllies();
        act->addToActionBar();
    }






    void Print_Stats(Ally *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]<<" ";
        for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Sub_Unit_ptr[0]->Atv_stats->num)continue;
                cout<<Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"]<<" ";
            }

    }

}
#endif