
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
        Ally *ptr = SetAllyBasicStats(96,120,120,E,"Quantum","Harmony","Tribbie",TYPE_STD);
        SubUnit *TBptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1048,524,728);
        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Hp%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CRIT_RATE,ST_HP_PERCENT,ST_HP_PERCENT,ST_EnergyRecharge);



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
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TBptr]() {
            if (ptr->Light_cone.Name == "DDD" && chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->atv <= 0) return;
            if (ptr->Light_cone.Name == "DDD" && Driver_num != 0 && Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return;
            if (ptr->Light_cone.Name == "Eagle_Beaked_Helmet" && ptr->Sub_Unit_ptr[0]->Atv_stats->atv <= 0) return;
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Tribbie Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({0, 30, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({0, 30, 0, 20});
            data_->Damage_spilt.Other.push_back({0, 30, 0, 20});
            data_->actionFunction = [ptr,TBptr](shared_ptr<AllyActionData> &data_){
                if (TBptr->isHaveToAddBuff("Tribbie_Zone",2)) {
                        debuffAllEnemyMark({{ST_VUL,AT_NONE,30}},ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone");
    
                    // A4 Trace
                    ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                    for (int i = 1; i <= Total_ally; i++) {
                        ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] += calculateHpForBuff(Ally_unit[i]->Sub_Unit_ptr[0].get(), 9);
                    }
                    TBptr->buffSingle({{ST_FLAT_HP, AT_TEMP , ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                    TBptr->buffSingle({{ST_FLAT_HP, "None", ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
    
                    // Eidolon 1
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{"True_Damage", "None", 24}});
                    }
                    if (ptr->Eidolon >= 4) {
                        buffAllAlly({{ST_DEF_SHRED, "None", 18}});
                    }
                }
                for (int i = 1; i <= Total_ally; i++) {
                    if (i == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num) continue;
                    Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"] = 0;
                }
                Attack(data_);
                
                if (ptr->Print)CharCmd::printUltStart("Tribbie");
                if (ptr->Eidolon >= 6) {
                    shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
                    data_2->Fua_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Tribbie Fua");
                    data_2->Add_Target_Other();
                    data_2->actionFunction =[ptr,TBptr](shared_ptr<AllyActionData> &data_2){
                        Increase_energy(ptr, 5);
                        Attack(data_2);
                    };
                    data_2->Damage_spilt.Main.push_back({0, 18, 0, 5});
                    data_2->Damage_spilt.Adjacent.push_back({0, 18, 0, 5});
                    data_2->Damage_spilt.Other.push_back({0, 18, 0, 5});
                    Action_bar.push(data_2);
                    if (!actionBarUse) Deal_damage();
                }
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] += 10;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"] += 729;
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
                    buffAllAlly({{"True_Damage", "None", -24}});
                }
                if (ptr->Eidolon >= 4) {
                    buffAllAlly({{ST_DEF_SHRED, "None", -18}});
                }

                TBptr->buffSingle({{ST_FLAT_HP, AT_TEMP , -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                TBptr->buffSingle({{ST_FLAT_HP, "None", -ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});

                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                if (ptr->Print)CharCmd::printUltEnd("Tribbie");
            }
            if (TBptr->isBuffEnd("Numinosity")) {
                buffAllAlly({{"Respen", "None", -24}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            if (TBptr->isBuffEnd("Tribbie_A2")) {
                TBptr->buffResetStack({{ST_DMG, AT_NONE, 72}},"Tribbie_A2");
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr]() {
            Increase_energy(ptr, 30);
            buffAllAlly({{"Respen", "None", 24}});
            TBptr->isHaveToAddBuff("Numinosity", 3);
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,TBptr](shared_ptr<AllyActionData> &data_) {
            int temp = data_->Target_Attack.size();
            if (data_->Attacker->Atv_stats->Char_Name == "Tribbie" && data_->Action_type.second == "Fua") {
                TBptr->buffStackSingle({{ST_DMG, AT_NONE, 72}},1,3,"Tribbie_A2",3);
            }
            Increase_energy(ptr, (1.5) * temp);
            if (TBptr->getBuffCheck("Tribbie_Zone")) {
                shared_ptr<AllyActionData> data_1 = make_shared<AllyActionData>();
                data_1->Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target","Tribbie Additional Damage");
                if (ptr->Eidolon >= 2) {
                    Cal_Additional_damage(data_1, chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()), {0, (14.4) * (temp + 1), 0, 0});
                } else {
                    Cal_Additional_damage(data_1, chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()), {0, (12.0) * temp, 0, 0});
                }
            }
            if (data_->Action_type.second == "Ultimate" && data_->Attacker->getBuffCheck("Tribbie_ult_launch") == 0 && data_->Attacker->Atv_stats->Char_Name != "Tribbie" && data_->Attacker->Atv_stats->Side == "Ally") {
                data_->Attacker->Buff_check["Tribbie_ult_launch"] = 1;
                shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
                data_2->Fua_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Tribbie Fua");
                data_2->Add_Target_Other();
                data_2->actionFunction = [ptr,TBptr](shared_ptr<AllyActionData> &data_){
                    Increase_energy(ptr, 5);
                    Attack(data_);
                };
                

                data_2->Damage_spilt.Main.push_back({0, 18, 0, 5});
                data_2->Damage_spilt.Adjacent.push_back({0, 18, 0, 5});
                data_2->Damage_spilt.Other.push_back({0, 18, 0, 5});
                Action_bar.push(data_2);
                if (!actionBarUse) Deal_damage();
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
                TBptr->buffSingle({{ST_FLAT_HP, "None", temp - ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = temp;
                return;
            }
        }));  
    }


    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Tribbie BasicAttack");
        data_->Add_Target_Adjacent();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({0,30,0,10});
        data_->Damage_spilt.Adjacent.push_back({0,15,0,5});
        data_->actionFunction =[ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };

        Action_bar.push(data_);
    }
    
    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff","Tribbie Skill");
        data_->Add_Buff_All_Ally();
        data_->Turn_reset=true;
        data_->actionFunction =[ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            buffAllAlly({{"Respen","None",24}});
            ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Numinosity", 3);
        };
        Action_bar.push(data_);
    }






    void Print_Stats(Ally *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]<<" ";
        for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num)continue;
                cout<<Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"]<<" ";
            }

    }

}
#endif