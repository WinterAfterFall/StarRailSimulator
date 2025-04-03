
#ifndef RMC_H
#define RMC_H

#define F first
#define S second
#include "../Library.h"

namespace RMC{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Increase_Charge(Ally *ptr,double charge);
    void Memo_Skill(Ally *ptr);
    void Memo_Echance_Skill(Ally *ptr);


    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1048,543,631);
        SetBasicStats(Ally_unit[num].get(),103,160,160,E,"Ice","Remembrance",num,"RMC","Ally");

        //substats
        

        ptr->pushSubstats("Crit_dam");
        ptr->setTotalSubstats(20);

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr](){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt%3!=1){
                Basic_Atk(ptr);
            }else{
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"] >= 60 && chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats->atv <= 20) return;
            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[1].get(), "Aoe", "RMC Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({264, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({264, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({264, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_) {
                Increase_Charge(ptr, 40);
                Buff_single_target(ptr->Sub_Unit_ptr[1].get(), "Crit_rate", "None", 100);
                if (ptr->Print) CharCmd::printUltStart("RMC");
                Attack(data_);
                Buff_single_target(ptr->Sub_Unit_ptr[1].get(), "Crit_rate", "None", -100);
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 37.3;

            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Ice"]["None"] += 22.4;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Ice"]["None"] += 38.8;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](Sub_Unit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Mem") return;
            if (StatsType == "Crit_dam") {
                // before
                // adjust
                ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = (calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4) - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"];
                // after
                Buff_All_Ally("Crit_dam", AT_TEMP, ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]);
                Buff_All_Ally("Crit_dam", "None", ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]);
                return;
            }
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, 150);
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"]["None"] += 688;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                for (int i = 1; i <= Total_enemy; i++) {
                    Action_forward(Enemy_unit[i]->Atv_stats.get(), -50);
                }
                ActionData data_ = ActionData();
                data_.Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "RMC Technique");
                data_.Add_Target_Other();
                data_.Damage_spilt.Main.push_back({50, 0, 0, 0});
                data_.Damage_spilt.Adjacent.push_back({50, 0, 0, 0});
                data_.Damage_spilt.Other.push_back({50, 0, 0, 0});
                data_.actionFunction = [ptr](ActionData &data_) {
                    Attack(data_);
                };
                Action_bar.push(data_);
                if (!actionBarUse) Deal_damage();
            }
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 30);
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4;
            Buff_All_Ally("Crit_dam", AT_TEMP, -ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]);
            Buff_All_Ally("Crit_dam", "None", -ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (Buff_end(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()), "Mem_Support")) {
                if(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy == 0)
                Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get()),"True_Damage","None",-36);
                else if (Ally_unit[ptr->Sub_Unit_ptr[1]->currentAllyTargetNum]->Max_energy >= 200)
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[1]->currentAllyTargetNum].get(), "True_Damage", "None", -50);
                else 
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[1]->currentAllyTargetNum].get(), "True_Damage", "None", -30 - 2 * floor((Ally_unit[ptr->Sub_Unit_ptr[1]->currentAllyTargetNum]->Max_energy - 100) / 10));

                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[1]->currentAllyTargetNum].get(), "Crit_rate", "None", -10);
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Buff_check["Mem_Support"] = 0;
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 1;
        }));

        When_Energy_Increase_List.push_back(TriggerEnergy_Increase_Func(PRIORITY_IMMEDIATELY, [ptr](Ally *target, double Energy) {
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed == -1) return;
            if(Energy==0){
                Increase_Charge(ptr,3);
                return;
            }
            if (Energy + target->Current_energy > target->Max_energy) {
                Energy = target->Max_energy - target->Current_energy;
            }
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] += Energy;
            Increase_Charge(ptr, floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10));
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] -= floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10) * 10;
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name != "Mem" && data_.Attacker->Atv_stats->Side == "Memosprite" && ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] == 1) {
                Increase_energy(ptr, 8);
                ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 0;
            }
        }));



        SetMemoStats(Ally_unit[num].get(),68,0,"Ice","Mem","Memosprite");
        Ally_unit[num]->Sub_Unit_ptr[1]->Turn_func = [ptr](){
        
            if(ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]==1){
                Memo_Echance_Skill(ptr);
            }else{
                Memo_Skill(ptr);
            }
        };

    }


    void Increase_Charge(Ally *ptr,double charge){
        if(ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed==-1)return;
        ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]+=charge;
        if(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]>=100){
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]= 0;
            ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=1;
            Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        }
    }


    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","RMC Basic Attack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){

        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","RMC Skill");
        data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        data_.Turn_reset=true;
        data_.Buff_type.push_back("Summon");
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
                ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = 130;
                Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                atv_reset(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                Increase_Charge(ptr,90);
            }
        };
        Action_bar.push(data_);

    }



    void Memo_Skill(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[1].get(),"Aoe","Mem Skill");
        data_.Add_Target_Adjacent();
        data_.Skill_Type.push_back("Summon");
        data_.Turn_reset=true;
        if(Total_enemy==1){
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
        }else if(Total_enemy==2){
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({39.6,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({39.6,0,0,5});

        }else{
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Main.push_back({39.6,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({39.6,0,0,5});
        }
        data_.Damage_spilt.Main.push_back({99,0,0,10});
        data_.Damage_spilt.Adjacent.push_back({99,0,0,10});
        data_.Damage_spilt.Other.push_back({99,0,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,10);
            Increase_Charge(ptr,5);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Memo_Echance_Skill(Ally *ptr){

        ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=0;
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[1].get(),"Single","Buff","Mem Buff");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()));
        data_.Turn_reset=true;
        data_.Skill_Type.push_back("Summon");
        
        
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,10);
            if(ptr->Print)CharCmd::printUltStart("Mem");
            if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()),"Mem_Support")){
                if(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy == 0)
                Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get()),"True_Damage","None",30+6);
                else if(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy>=200)
                Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get()),"True_Damage","None",30+20);
                else
                Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get()),"True_Damage","None",30+2*floor((chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy-100)/10));
                
                Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get()),"Crit_rate","None",10);
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Buff_check["Mem_Support"]=1;
            }
            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats.get(),100);
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()),"Mem_Support",3);
        };
        Action_bar.push(data_);
    }  
}
#endif