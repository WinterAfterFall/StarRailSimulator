
#ifndef Gallagher_H
#define Gallagher_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Gallagher{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);



    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1305,529,441);
        SetBasicStats(Ally_unit[num].get(),98,110,110,E,"Fire","Abundance",num,"Gallagher","Ally");

        //substats
        ptr->pushSubstats("Break_effect");
        ptr->setTotalSubstats(20);

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt % 8 == 1) {
                Skill_func(ptr);
            } else {
                if (ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                    Enchance_Basic_Atk(ptr);
                } else {
                    Basic_Atk(ptr);
                }
            }
        };
        Ultimate_List.push_back({PRIORITY_DEBUFF, [ptr]() {
            if (Ult_After_Turn == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0 || !ultUseCheck(ptr)) return;
            

            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Gallagher Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({165, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({165, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({165, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_) {
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 1;
                Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(), "Vul", "Break_dmg", 13.2, "Besotted");
                if (ptr->Eidolon >= 4) {
                    Extend_Debuff_All_Enemy("Besotted", 3);
                } else {
                    Extend_Debuff_All_Enemy("Besotted", 2);
                }
                Attack(data_);
            };
            Action_bar.push(data_);
            if (ptr->Print) CharCmd::printUltStart(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name);
            if(!actionBarUse)Deal_damage();
        }});

        Reset_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES]["None"] += 18;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING]["None"] += 34.57;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"]["None"] += 20;
                ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 20;
            }
        }});

        After_turn_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Side == "Enemy") {
                if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "Besotted")) {
                    Debuff_single_target(Enemy_unit[turn->Unit_num].get(), "Vul", "Break_dmg", -13.2);
                    Enemy_unit[turn->Unit_num]->Debuff["Besotted"] = 0;
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
                if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "Nectar_Blitz")) {
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                    Enemy_unit[Main_Enemy_num]->Debuff["Nectar_Blitz"] = 0;
                }
            }
        }});

        Tune_stats_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, 150);
        }});

        Start_game_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Eidolon >= 1) {
                Increase_energy(ptr, 20);
            }
        }});

        When_Combat_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp - ptr->getSubUnit()->Buff_note["Novel Concoction"];
            Buff_single_target(ptr->getSubUnit(),ST_BREAK_EFFECT,AT_NONE,ptr->getSubUnit()->Buff_note["Novel Concoction"]);
            if (ptr->Technique) {
                ActionData data_ = ActionData();
                data_.Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","gallagher Technique");
                data_.Damage_spilt.Main.push_back({50, 0, 0, 20});
                data_.Damage_spilt.Adjacent.push_back({50, 0, 0, 20});
                data_.Damage_spilt.Other.push_back({50, 0, 0, 20});
                Action_bar.push(data_);
                data_.actionFunction = [ptr](ActionData &data_){
                    Extend_Debuff_All_Enemy("Besotted", 2);
                    Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(), "Vul", "Break_dmg", 13.2, "Besotted");
                    Attack(data_);
                };
                if (!actionBarUse) Deal_damage();
            }
        }});

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_HEAL, [ptr](ActionData &data_) {
            Heal_data healData = Heal_data();
            healData.setHealer(ptr->Sub_Unit_ptr[0].get());
            

            if (data_.Action_type.second == AT_BASIC_ATK && data_.Attacker->Atv_stats->Unit_Name == "Gallagher" && data_.Attacker->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 0;
                int cnt = 0;
                for (Enemy *e : data_.Target_Attack) {
                    if (Debuff_check(e, "Besotted")) {
                        cnt++;
                        
                    }
                }
                healData.main.setRatio(0, 0, 0, 707*cnt, 0, 0);
                healData.adjacent.setRatio(0, 0, 0, 707*cnt, 0, 0);
                healData.other.setRatio(0, 0, 0, 707*cnt, 0, 0);
                Healing(healData);
            } else {
                int cnt = 0;
                for (Enemy *e : data_.Target_Attack) {
                    if (Debuff_check(e, "Besotted")) {
                        cnt++;           
                    }
                }
                healData.main.setRatio(0, 0, 0, 707*cnt, 0, 0);
                Healing(healData.main, ptr->Sub_Unit_ptr[0].get(), data_.Attacker);
            }
        }));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](SubUnit* Target, string StatsType) {
            if(StatsType!=ST_BREAK_EFFECT||!Target->isSameUnitName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp - ptr->getSubUnit()->Buff_note["Novel Concoction"];
            Buff_single_target(ptr->getSubUnit(),ST_BREAK_EFFECT,AT_NONE,ptr->getSubUnit()->Buff_note["Novel Concoction"]);
        }));

        

        //substats

        
    }



    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Gallagher Basic_Atk");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Enchance_Basic_Atk(Ally *ptr){
       
        
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Nectar Blitz");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({62.5,0,0,7.5});
        data_.Damage_spilt.Main.push_back({37.5,0,0,4.5});
        data_.Damage_spilt.Main.push_back({150,0,0,18});
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            if(!Debuff_check(Enemy_unit[Main_Enemy_num].get(),"Nectar_Blitz")){
                Enemy_unit[Main_Enemy_num]->Debuff["Nectar_Blitz"] = 1;
                ++Enemy_unit[Main_Enemy_num]->Total_debuff;
                
            }
            debuffApply(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[Main_Enemy_num].get());
            Extend_Debuff_single_target(Enemy_unit[Main_Enemy_num].get(),"Nectar_Blitz",2);
            Attack(data_);
        };
        Action_bar.push(data_);
        

    }
    void Skill_func(Ally *ptr){

        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Heal","Gallagher Skill");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.resetTurn();
        data_.createHealRatio();
        data_.healPtr->setHealer(ptr->Sub_Unit_ptr[0].get());
        data_.healPtr->main.setRatio(0,0,0,1768,0,0);
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);

        };
        Action_bar.push(data_);
    }




}
#endif
