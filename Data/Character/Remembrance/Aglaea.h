
#ifndef Aglaea_H
#define Aglaea_H

#define F first
#define S second
#include "../Library.h"

namespace Aglaea{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Memo_Skill(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Summon(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(102,350,350,E,"Lightning","Remembrance","Aglaea",TYPE_STD);
        ptr->SetAllyBaseStats(1242,699,485);

        //substats
        ptr->pushSubstats(ST_CRIT_DAM);
        ptr->pushSubstats(ST_CRIT_RATE);
        ptr->pushSubstats(ST_ATK_PERCENT);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Atv_stats->Base_speed == -1) {
                Skill(ptr);
                return;
            }

            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1) {
                Enchance_Basic_Atk(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1 && 
                (ptr->Countdown_ptr[0]->Atv_stats->atv > ptr->Sub_Unit_ptr[0]->Atv_stats->atv && 
                (ptr->Sub_Unit_ptr[0]->Atv_stats->atv != ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv))) return;
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->atv == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0) return;
            if (!ultUseCheck(ptr)) return;

            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff", "Aglaea Ultimate");
            data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_.actionFunction = [ptr](ActionData &data_) {
                if (ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed == -1) Summon(ptr);

                if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed == -1) 
                    Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 15 * ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"], 0);
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                ptr->Countdown_ptr[0]->Atv_stats->Base_speed = 100;
                Update_Max_atv(ptr->Countdown_ptr[0]->Atv_stats.get());
                atv_reset(ptr->Countdown_ptr[0]->Atv_stats.get());
                double BuffValue = calculateSpeedForBuff(ptr->Sub_Unit_ptr[0].get(), 360) + 
                calculateSpeedForBuff(ptr->Sub_Unit_ptr[1].get(), 720);

                Buff_single_with_all_memo(ptr, "Flat_Atk", AT_TEMP, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
                Buff_single_with_all_memo(ptr, "Flat_Atk", "None", BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
                ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] =  BuffValue;
                if (ptr->Print) CharCmd::printUltStart("Aglaea");
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 22.4;

            // relic
            if (ptr->Body_CritDam) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 32.4;
            }
            if (ptr->Speed_Boot) {
                ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Element_Orb) {
                ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 38.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Er_Rope) {
                ptr->Energy_recharge += 19.4;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }

            // substats

            // countdown
        }));


        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"]["None"] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ActionData data_ = ActionData();
                data_.Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Aglaea Technique");
                data_.Add_Target_Other();
                data_.Damage_spilt.Main.push_back({100, 0, 0, 20});
                data_.Damage_spilt.Adjacent.push_back({100, 0, 0, 20});
                data_.Damage_spilt.Other.push_back({100, 0, 0, 20});
                data_.actionFunction = [ptr](ActionData &data_) {
                    Increase_energy(ptr, 30);
                    ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed * 0.35;
                    Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    atv_reset(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(), 100);
                    Attack(data_);
                };
                Action_bar.push(data_);
                if (!actionBarUse) Deal_damage();
            }
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                if (data_.Attacker->Stack["Brewed_by_Tears"] < 6) {
                    Speed_Buff(data_.Attacker->Atv_stats.get(), 0, 55);
                    data_.Attacker->Stack["Brewed_by_Tears"]++;
                    if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1) {
                        Speed_Buff(data_.Attacker->ptr_to_unit->Sub_Unit_ptr[0]->Atv_stats.get(), 15, 0);
                    }
                }
            }
            if (data_.Attacker->isSameUnitName("Aglaea")) {
                if (Enemy_unit[Main_Enemy_num]->debuffMark(ptr->getSubUnit(),"Seam_Stitch")) {
                    if (ptr->Eidolon >= 1) {
                        Enemy_unit[Main_Enemy_num]->debuffSingleTarget("Vul", "None", 15);
                    }
                }
            }
            if (data_.Attacker->Atv_stats->Unit_num == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num) {
                ActionData data_Additional = ActionData();
                data_Additional.Additional_set(data_.Attacker, "Single_target", "Aglaea Additional Damage");
                Cal_Additional_damage(data_Additional, Enemy_unit[Main_Enemy_num].get(), {30, 0, 0, 0});
                if (ptr->Eidolon >= 1) {
                    Increase_energy(ptr, 20);
                }
            }
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (ptr->Eidolon >= 2) {
                if (data_.Attacker->Atv_stats->Unit_Name == "Aglaea" || data_.Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    Stack_Buff_single_with_all_memo(ptr, "Def_shred", "None", 14, 1, 3, "Aglaea_E2");
                } else {
                    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
                        Buff_single_target(ptr->Sub_Unit_ptr[i].get(), "Def_shred", "None", ptr->Sub_Unit_ptr[i]->Stack["Aglaea_E2"] * (-14));
                        ptr->Sub_Unit_ptr[i]->Stack["Aglaea_E2"] = 0;
                    }
                }
            }
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (ptr->Eidolon >= 2) {
                if (data_.Attacker->Atv_stats->Unit_Name == "Aglaea" || data_.Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    Stack_Buff_single_with_all_memo(ptr, "Def_shred", "None", 14, 1, 3, "Aglaea_E2");
                } else {
                    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
                        Buff_single_target(ptr->Sub_Unit_ptr[i].get(), "Def_shred", "None", ptr->Sub_Unit_ptr[i]->Stack["Aglaea_E2"] * (-14));
                        ptr->Sub_Unit_ptr[i]->Stack["Aglaea_E2"] = 0;
                    }
                }
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Aglaea") return;
            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed == -1) return;
            if (StatsType == "Speed") {
                // adjust
                double BuffValue = calculateSpeedForBuff(ptr->Sub_Unit_ptr[0].get(), 360) + 
                calculateSpeedForBuff(ptr->Sub_Unit_ptr[1].get(), 720);

                Buff_single_with_all_memo(ptr, "Flat_Atk", AT_TEMP, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
                Buff_single_with_all_memo(ptr, "Flat_Atk", "None", BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
                ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] =  BuffValue;
                return;
            }
        }));

        SetMemoStats(ptr,66,35,"Lightning","Garmentmaker","Memosprite");
        SetCountdownStats(ptr,"Supreme_Stance");
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr](){
        
            Memo_Skill(ptr);
            
        };

        ptr->Countdown_ptr[0]->Turn_func = [ptr](){
            Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),-15*ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"],0);
            
            ptr->Countdown_ptr[0]->Atv_stats->Base_speed=-1;
            Update_Max_atv(ptr->Countdown_ptr[0]->Atv_stats.get());
            atv_reset(ptr->Countdown_ptr[0]->Atv_stats.get());
            
            Buff_single_with_all_memo(ptr,"Flat_Atk",AT_TEMP,-ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
            Buff_single_with_all_memo(ptr,"Flat_Atk","None",-ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]);
    
            ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] = 0;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
    
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
            atv_reset(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
            double temp =0;
            if(ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]>1){
                temp = ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]-1;
            }
            Speed_Buff(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),0,(-55*temp));
            ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"] = 1;
            Increase_energy(ptr,20);
    
            if(ptr->Print)CharCmd::printUltEnd("Aglaea");
        };


    }
    



    void Enchance_Basic_Atk(Ally *ptr){
       
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Aglaea Joint Attack");
        data_.Add_Target_Adjacent();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({200,0,0,10});
        data_.Damage_spilt.Main.push_back({200,0,0,10});

        data_.Damage_spilt.Adjacent.push_back({90,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({90,0,0,5});
        data_.All_Attacker.push_back(ptr->Sub_Unit_ptr[1].get());
        data_.Attack_trigger++;
        data_.Joint.push_back(AttackSource(1,ptr->Sub_Unit_ptr[1].get()));
        data_.actionFunction =[ptr](ActionData &data_ ){
            Increase_energy(ptr,20);
            Attack(data_);
        };

        Action_bar.push(data_);
    }
    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Aglaea BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.actionFunction =[ptr](ActionData &data_ ){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Aglaea Skill");
        data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        data_.Turn_reset=true;
        data_.Buff_type.push_back("Summon");
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                Summon(ptr);
                data_.Turn_reset=false;
            }
        };
        
        Action_bar.push(data_);
    }
    void Summon(Ally *ptr){
        ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed*0.35;
        Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        atv_reset(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
    }
    

    
    void Memo_Skill(Ally *ptr){

        
        ActionData data_ = ActionData();

        data_.Skill_set(ptr->Sub_Unit_ptr[1].get(),"Blast","Garmentmaker Skill");
        data_.Add_Target_Adjacent();
        data_.Skill_Type.push_back("Summon");
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({110,0,0,10});
        data_.Damage_spilt.Adjacent.push_back({66,0,0,5});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,10);
            Attack(data_);
        };
        Action_bar.push(data_);
    }

    
    
    

    


}
#endif