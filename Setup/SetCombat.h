#ifndef Setup_H
#define Setup_H
#include<bits/stdc++.h>
#include "../Print.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000
//Defination
void Setup(){
    if(Driver_Type=="None"&&(Driver_num!=0)){
        Driver_num = 0;
    }else if(Driver_Type!="None"&&(Driver_num==0)){
        Driver_num = 2;
    }
    sort(Reset_List.begin(), Reset_List.end(), TriggerFunc::Trigger_cmp);
    sort(Setup_Memo_List.begin(), Setup_Memo_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_Combat_List.begin(), When_Combat_List.end(), TriggerFunc::Trigger_cmp);
    sort(Tune_stats_List.begin(), Tune_stats_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_game_List.begin(), Start_game_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_wave_List.begin(), Start_wave_List.end(), TriggerFunc::Trigger_cmp);
    sort(Before_turn_List.begin(), Before_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(After_turn_List.begin(), After_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(Ultimate_List.begin(), Ultimate_List.end(), TriggerFunc::Trigger_cmp);
    
    sort(Before_attack_List.begin(), Before_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(After_attack_List.begin(), After_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_attack_List.begin(), When_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(Buff_List.begin(), Buff_List.end(), TriggerFunc::Trigger_cmp);
    
    sort(Stats_Adjust_List.begin(), Stats_Adjust_List.end(), TriggerFunc::Trigger_cmp);
    sort(Healing_List.begin(), Healing_List.end(), TriggerFunc::Trigger_cmp);
    sort(HPDecrease_List.begin(), HPDecrease_List.end(), TriggerFunc::Trigger_cmp);
    sort(EnemyDeath_List.begin(), EnemyDeath_List.end(), TriggerFunc::Trigger_cmp);
    sort(AllyDeath_List.begin(), AllyDeath_List.end(), TriggerFunc::Trigger_cmp);
    
    sort(Toughness_break_List.begin(), Toughness_break_List.end(), TriggerFunc::Trigger_cmp);
    sort(Apply_debuff_List.begin(), Apply_debuff_List.end(), TriggerFunc::Trigger_cmp);
    sort(Enemy_Death_List.begin(), Enemy_Death_List.end(), TriggerFunc::Trigger_cmp);
    
    sort(Enemy_hit_List.begin(), Enemy_hit_List.end(), TriggerFunc::Trigger_cmp);
    sort(Dot_List.begin(), Dot_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_Energy_Increase_List.begin(), When_Energy_Increase_List.end(), TriggerFunc::Trigger_cmp);
    sort(Skill_point_List.begin(), Skill_point_List.end(), TriggerFunc::Trigger_cmp);
    sort(Hit_Count_List.begin(), Hit_Count_List.end(), TriggerFunc::Trigger_cmp);
    
    for(int i=1;i<=Total_ally;i++){
        // Ally_unit[i]->Atk_flat["None"] = 0;
        // Ally_unit[i]->Atk_percent["None"] = 0;
        // Ally_unit[i]->Hp_flat["None"] = 0;
        // Ally_unit[i]->Hp_percent["None"] = 0;
        // Ally_unit[i]->Def_flat["None"] = 0;
        // Ally_unit[i]->Def_percent["None"] = 0;
        // Ally_unit[i]->Dmg_bonus["None"] = 0;
        // Ally_unit[i]->Crit_rate["None"] = 0;
        // Ally_unit[i]->Crit_dam["None"] = 0;
        // Ally_unit[i]->Def_shred["None"] = 0;
        // Ally_unit[i]->Respen["None"] = 0;
        // Ally_unit[i]->Vul["None"] = 0;
        // Ally_unit[i]->Break_effect["None"] = 0;
        // Ally_unit[i]->Mitigation["None"] = 0;
        // Ally_unit[i]->Weakness_Break_Efficiency["None"] = 0;
        // Ally_unit[i]->Toughness_reduction["None"] = 0;

        Ally_unit[i]->Current_substats=Ally_unit[i]->Total_substats;
        Ally_unit[i]->StatsType_Compare_MAX_MIN.first = -1;
        Ally_unit[i]->StatsType_Compare_MAX_MIN.second = 1e9;
        Ally_unit[i]->TotalSubstats_Compare_MAX_MIN.first = -1;
        Ally_unit[i]->TotalSubstats_Compare_MAX_MIN.second = 1e9;


        Ally_unit[i]->Normal_Damage.resize(Total_enemy+1);
        Ally_unit[i]->Dot_damage.resize(Total_enemy+1);
        Ally_unit[i]->Break_damage.resize(Total_enemy+1);
        Ally_unit[i]->Superbreak_damage.resize(Total_enemy+1);
        
        cout<<endl;
        Ally_unit[i]->Max_Damage.resize(Total_enemy+1);
        Ally_unit[i]->Max_Dot_damage.resize(Total_enemy+1);
        Ally_unit[i]->Max_Break_damage.resize(Total_enemy+1);
        Ally_unit[i]->Max_Superbreak_damage.resize(Total_enemy+1);




    }
}

void Reset(){
    turn = nullptr;
    sp =3;
    Basic_reset();
    Summon_reset();
    Countdown_reset();
    
    for(TriggerByYourSelf_Func &e : Reset_List){
        e.Call(e.ptr);
    }
    
    Memosprite_reset();
    for(TriggerByYourSelf_Func &e : Setup_Memo_List){
        e.Call(e.ptr);
    }
    for(TriggerByYourSelf_Func &e : When_Combat_List){
        e.Call(e.ptr);
    }
    for(TriggerByYourSelf_Func &e : Tune_stats_List){
        e.Call(e.ptr);
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
        Ally_unit[i]->Sub_Unit_ptr[j]->totalATK = calculateAtkOnStats(Ally_unit[i]->Sub_Unit_ptr[0].get());
        Ally_unit[i]->Sub_Unit_ptr[j]->totalHP = calculateHpOnStats(Ally_unit[i]->Sub_Unit_ptr[j].get());
        Ally_unit[i]->Sub_Unit_ptr[j]->totalDEF = calculateDefOnStats(Ally_unit[i]->Sub_Unit_ptr[j].get());
        }
        Ally_unit[i]->Sub_Unit_ptr[0]->currentHP = Ally_unit[i]->Sub_Unit_ptr[0]->totalHP;
    }
    
}

void Start_game(){
    All_atv_reset();
    for(TriggerByYourSelf_Func &e : Start_game_List){
        e.Call(e.ptr);
    }
}
void EndWave(double Total_atv){
    
    double temp = 0;
    for(int i=1;i<=Total_enemy;i++){
        
        for(int j=1;j<=Total_ally;j++){
            Ally_unit[j]->Normal_Damage[i] *= Cal_TotalPercentToughnessBrokenTime(Enemy_unit[i].get(),Total_atv);
            Ally_unit[j]->Dot_damage[i]*= Cal_TotalPercentToughnessBrokenTime(Enemy_unit[i].get(),Total_atv);
            Ally_unit[j]->Total_damage+=(Ally_unit[j]->Dot_damage[i]+Ally_unit[j]->Normal_Damage[i]+Ally_unit[j]->Superbreak_damage[i] +Ally_unit[j]->Break_damage[i]);
            Ally_unit[j]->Last_note = 0;
            
        }
        
    }

    cout<<endl;
    
}
void Start_wave(int WAVE){
    if(WAVE!=0)All_atv_reset();
    for(int i =1;i<=Total_enemy;i++){
        //Enemy_unit[i]->stats->Toughness_status=1;
        //Enemy_unit[i]->stats->Current_toughness=Enemy_unit[i]->Max_toughness;
        Enemy_unit[i]->when_toughness_broken = 0;
        Enemy_unit[i]->Total_toughness_broken_time = 0;
    }
    for(TriggerByYourSelf_Func &e : Start_wave_List){
        e.Call(e.ptr);
    }
    
}
#endif