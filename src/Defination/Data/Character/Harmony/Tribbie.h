#include "../include.h"

namespace Tribbie{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Print_Stats(CharUnit *ptr);

    



//temp
    void Skill(CharUnit *ptr);
    void Basic_Atk(CharUnit *ptr);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(96,120,120,E,ElementType::Quantum,Path::Harmony,"Tribbie",UnitType::Standard);
        AllyUnit *TBptr = ptr;
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
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            if (allyPtr->getBuffCheck("Numinosity")) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        ptr->Char.Print_Func = Print_Stats;
        ptr->addUltCondition([ptr,TBptr]() -> bool {
            if (ptr->Light_cone.Name == "DDD" && chooseSubUnitBuff(ptr)->Atv_stats->atv <= 0) return false;
            if (ptr->Light_cone.Name == "DDD" && Driver_num != 0 && charUnit[Driver_num]->Atv_stats->atv <= 0) return false;
            if (ptr->Light_cone.Name == "Eagle_Beaked_Helmet" && ptr->Atv_stats->atv <= 0) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TBptr]() {
            if (!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"TB Ult",
            [ptr,TBptr](shared_ptr<AllyAttackAction> &act){
                if (isHaveToAddBuff(TBptr,"Tribbie_Zone",2)) {
                        debuffAllEnemyMark({{Stats::VUL,AType::None,30}},ptr,"Tribbie_Zone");
    
                    // A4 Trace
                    ptr->Buff_note["Tribbie_A4"] = 0;
                    for (int i = 1; i <= Total_ally; i++) {
                        ptr->Buff_note["Tribbie_A4"] += calculateHpForBuff(charUnit[i].get(), 9);
                    }
                    buffSingle(TBptr,{{Stats::FLAT_HP, AType::TEMP , ptr->Buff_note["Tribbie_A4"]}});
                    buffSingle(TBptr,{{Stats::FLAT_HP, AType::None, ptr->Buff_note["Tribbie_A4"]}});
    
                    if (ptr->Eidolon >= 4) {
                        buffAllAlly({{Stats::DEF_SHRED, AType::None, 18}});
                    }
                }
                for (int i = 1; i <= Total_ally; i++) {
                    if (i == ptr->Atv_stats->num) continue;
                    charUnit[i]->Buff_check["Tribbie_ult_launch"] = 0;
                }
                Attack(act);
                
                if (ptr->Print)CharCmd::printUltStart("Tribbie");
                if (ptr->Eidolon >= 6) {
                    shared_ptr<AllyAttackAction> data_2 = 
                    make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Aoe,"TB Fua",
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
            ptr->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Stats_type[Stats::HP_P][AType::None] += 10;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Stats_type[Stats::DMG][AType::Fua] += 729;
            }
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (isBuffEnd(TBptr,"Tribbie_Zone")) {
                ptr->Buff_check["Tribbie_Zone"] = 0;
                for(auto &each : enemyList){
                    debuffRemove(each,"Tribbie_Zone");
                    debuffSingle(each,{{Stats::VUL,AType::None,-30}});
                }
                if (ptr->Eidolon >= 4) {
                    buffAllAlly({{Stats::DEF_SHRED, AType::None, -18}});
                }

                buffSingle(TBptr,{{Stats::FLAT_HP, AType::TEMP , -ptr->Buff_note["Tribbie_A4"]}});
                buffSingle(TBptr,{{Stats::FLAT_HP, AType::None, -ptr->Buff_note["Tribbie_A4"]}});

                ptr->Buff_note["Tribbie_A4"] = 0;
                if (ptr->Print)CharCmd::printUltEnd("Tribbie");
            }
            if (isBuffEnd(TBptr,"Numinosity")) {
                buffAllAlly({{Stats::RESPEN, AType::None, -24}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (isBuffEnd(TBptr,"Tribbie_A2")) {
                buffResetStack(TBptr,{{Stats::DMG, AType::None, 72}},"Tribbie_A2");
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            Increase_energy(ptr, 30);
            buffAllAlly({{Stats::RESPEN, AType::None, 24}});
            isHaveToAddBuff(TBptr,"Numinosity", 3);
        }));
        
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyAttackAction> &act) {
            int temp = act->targetList.size();
            if (act->isSameAction("Tribbie",AType::Fua)) {
                buffStackSingle(ptr,{{Stats::DMG, AType::None, 72}},1,3,"Tribbie_A2",3);
            }
            Increase_energy(ptr, (1.5) * temp);
            if (TBptr->getBuffCheck("Tribbie_Zone")) {
                shared_ptr<AllyAttackAction> data_1 = 
                make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"TB AddDmg");
                if (ptr->Eidolon >= 2) {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,14.4 * (temp + 1)));
                } else {
                    data_1->addDamageIns(DmgSrc(DmgSrcType::HP,12 * temp));
                }

                Attack(data_1);
            }
            if (act->isSameAction(AType::Ult)&& act->Attacker->getBuffCheck("Tribbie_ult_launch") == 0 && act->Attacker->Atv_stats->Name != "Tribbie" && act->Attacker->Atv_stats->side == Side::Ally) {
                act->Attacker->Buff_check["Tribbie_ult_launch"] = 1;
                shared_ptr<AllyAttackAction> data_2 = 
                make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Aoe,"TB Fua",
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
                    temp += calculateHpForBuff(charUnit[i].get(), 9);
                }
                
                // after
                buffSingle(TBptr,{{Stats::FLAT_HP, AType::TEMP , temp - ptr->Buff_note["Tribbie_A4"]}});
                buffSingle(TBptr,{{Stats::FLAT_HP, AType::None, temp - ptr->Buff_note["Tribbie_A4"]}});
                ptr->Buff_note["Tribbie_A4"] = temp;
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
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"TB BA",
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
        Skill_point(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Aoe,"TB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            buffAllAlly({{Stats::RESPEN,AType::None,24}});
            isHaveToAddBuff(ptr,"Numinosity", 3);
        });
        act->addBuffAllAllies();
        act->addToActionBar();
    }






    void Print_Stats(CharUnit *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->Buff_check["Numinosity"]<<" ";
        cout<<ptr->Buff_check["Tribbie_Zone"]<<" ";
        cout<<ptr->Stack["Tribbie_A2"]<<" ";
        cout<<ptr->Buff_note["Tribbie_A4"]<<" ";
        for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Atv_stats->num)continue;
                cout<<charUnit[i]->Buff_check["Tribbie_ult_launch"]<<" ";
            }
    }
}