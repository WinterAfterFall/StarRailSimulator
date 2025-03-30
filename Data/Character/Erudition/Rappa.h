
#ifndef Rappa_H
#define Rappa_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Rappa{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void After_turn(Ally *ptr);
    void After_attack(Ally *ptr, ActionData &data_);
    void Start_game(Ally *ptr);
    void Tune_stats(Ally *ptr);
    void Toughness_break_func(Ally *ptr,Enemy *target,Sub_Unit *Breaker);
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(), 1087, 718, 461);
        SetBasicStats(Ally_unit[num].get(), 96, 140, 140, E, "Imaginary", "Erudition", num, "Rappa", "Ally");

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Buff_check["Rappa_Ult"] == 0) {
            Skill_func(ptr);
            } else {
            Enchance_Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1) return;
            if (!ultUseCheck(ptr)) return;
            
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff", "Rappa Ultimate");
            data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_.actionFunction = [ptr](ActionData &data_){
                if (ptr->Print)Char_Command::printUltStart("Rappa");
                ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 1;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] = 2;
                ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 30;
                ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"]["None"] += 50;
                if (ptr->Eidolon >= 1)ptr->Sub_Unit_ptr[0]->Stats_type["Def_shred"]["None"] += 15;
                

                ActionData data_2 = ActionData();
                data_2.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(), "Blast", "Rappa Enchance BasicAttack");
                data_.Dont_care_weakness = 50;
                data_2.Add_Target_Other();
                data_2.Damage_spilt.Main.push_back({100, 0, 0, 10});
                data_2.Damage_spilt.Main.push_back({100, 0, 0, 10});
                data_2.Damage_spilt.Main.push_back({100, 0, 0, 5});
                data_2.Damage_spilt.Adjacent.push_back({50, 0, 0, 5});
                data_2.Damage_spilt.Adjacent.push_back({50, 0, 0, 5});
                data_2.Damage_spilt.Adjacent.push_back({100, 0, 0, 5});
                data_2.Damage_spilt.Other.push_back({100, 0, 0, 5});

                double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] + 2;
                ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] * 0.5 + 0.6;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

                data_2.Damage_spilt.Main.push_back({0, 0, 0, temp});
                data_2.Damage_spilt.Adjacent.push_back({0, 0, 0, temp});
                data_2.Damage_spilt.Other.push_back({0, 0, 0, temp});

                data_2.actionFunction = [ptr](ActionData &data_2){
                    Increase_energy(ptr, 20);
                    Attack(data_2);
                };
                Action_bar.push(data_2);

                if(!actionBarUse)Deal_damage();
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();

            // extra turn
            
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 13.3;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 9;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 64.8;
            // ptr->stats->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;

            // skill
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, 145);
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            if (turn->Side == "Enemy") {
                if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "Withered_Leaf")) {
                    Debuff_single_target(Enemy_unit[turn->Unit_num].get(), "Vul", "Break_dmg", -Enemy_unit[turn->Unit_num]->Debuff["Withered_Leaf"]);
                    Enemy_unit[turn->Unit_num]->Debuff["Withered_Leaf"] = 0;
                    Enemy_unit[turn->Unit_num]->Total_debuff--;
                }
            }
            if (turn->Char_Name == "Rappa") {
                if (ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] == 0 && ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] -= 30;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"]["None"] -= 50;

                    ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 0;
                    if (ptr->Eidolon >= 1) {
                        ptr->Sub_Unit_ptr[0]->Stats_type["Def_shred"]["None"] -= 15;
                        Increase_energy(ptr, 20);
                    }
                    if (ptr->Print == 1) {
                        cout << " --------------Rappa Ult End at     " << Current_atv << endl;
                    }
                }
            }
        }));


        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_){
            if(data_.Attacker->Atv_stats->Char_Name=="Rappa"){
                if(ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"]==1){
                    Superbreak_trigger(data_,60);

                    ActionData data_ = ActionData();
                    data_.Break_dmg_set(ptr->Sub_Unit_ptr[0].get(),"Rappa Break Talent");
                    double temp = ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"];

                    for(int i=1;i<=Total_enemy;i++){
                        Cal_Break_damage(data_,Enemy_unit[i].get(),temp);
                    }
                    ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = 0;
                }
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
                Increase_energy(ptr, 10);
                for (int i = 1; i <= Total_enemy; i++) {
                    ActionData data_ = ActionData();
                    double temp;
                    data_.Break_dmg_set(ptr->Sub_Unit_ptr[0].get(), "Rappa Technique");

                    if (Enemy_unit[i]->Target_type == "Main") {
                        temp = 2;
                        Cal_Break_damage(data_, Enemy_unit[i].get(), temp);
                    } else {
                        temp = 1.8;
                        Cal_Break_damage(data_, Enemy_unit[i].get(), temp);
                    }
                    data_ = ActionData();
                    data_.Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Rappa Technique");
                    data_.Add_Target_Other();
                    Cal_Toughness_reduction(data_, Enemy_unit[i].get(), 30);
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, Sub_Unit *Breaker) {
            ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]++;
            if (target->Max_toughness > 90) {
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]++;
                Increase_energy(ptr, 10);
            }
            if (target->Debuff["Withered_Leaf"] <= 0) {
                target->Total_debuff++;
            }
            Debuff_single_target(target, "Vul", "Break_dmg", -target->Debuff["Withered_Leaf"]);
            target->Debuff["Withered_Leaf"] = floor((((ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] / 100 * ptr->Sub_Unit_ptr[0]->Base_atk + ptr->Sub_Unit_ptr[0]->Base_atk) + ptr->Sub_Unit_ptr[0]->Stats_type["Flat_Atk"]["None"]) - 2400) / 100) + 2;
            if (target->Debuff["Withered_Leaf"] > 10) {
                target->Debuff["Withered_Leaf"] = 10;
            }
            if (target->Debuff["Withered_Leaf"] < 0) {
                target->Debuff["Withered_Leaf"] = 0;
            }
            Apply_debuff(ptr->Sub_Unit_ptr[0].get(), target);
            Debuff_single_target(target, "Vul", "Break_dmg", target->Debuff["Withered_Leaf"]);
            Extend_Debuff_single_target(target, "Withered_Leaf", 2);
        }));

        

        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;

        Ally_unit[num]->Substats.push_back({"Break_effect",20});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


    }


    void Enchance_Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Rappa Enchance BasicAttack");
        data_.Add_Target_Other();
        data_.Turn_reset = 1;
        data_.Dont_care_weakness = 50;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.Damage_spilt.Main.push_back({100,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({50,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({50,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({100,0,0,5});
        data_.Damage_spilt.Other.push_back({100,0,0,5});

        double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]+2;
        ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]*0.5+0.6;
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

        data_.Damage_spilt.Main.push_back({0,0,0,temp});
        data_.Damage_spilt.Adjacent.push_back({0,0,0,temp});
        data_.Damage_spilt.Other.push_back({0,0,0,temp});
        
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"]--;
        
        
    }
    void Skill_func(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Rappa Skill");
        data_.Add_Target_Other();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({60,0,0,5});
        data_.Damage_spilt.Main.push_back({60,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({60,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({60,0,0,5});
        data_.Damage_spilt.Other.push_back({60,0,0,5});
        data_.Damage_spilt.Other.push_back({60,0,0,5});
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    





}
#endif
