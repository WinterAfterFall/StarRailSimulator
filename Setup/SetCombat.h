#ifndef Setup_H
#define Setup_H
#include<bits/stdc++.h>
#include "../Class/Trigger_Function.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000
//Defination
void Setup(){
    if(Driver_num)Driver_Type = "Double_turn";
    
    sort(Reset_List.begin(), Reset_List.end(), TriggerFunc::Trigger_cmp);
    sort(Setup_Memo_List.begin(), Setup_Memo_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_Combat_List.begin(), When_Combat_List.end(), TriggerFunc::Trigger_cmp);
    sort(Tune_stats_List.begin(), Tune_stats_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_game_List.begin(), Start_game_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_wave_List.begin(), Start_wave_List.end(), TriggerFunc::Trigger_cmp);
    sort(Before_turn_List.begin(), Before_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(After_turn_List.begin(), After_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(Ultimate_List.begin(), Ultimate_List.end(), TriggerFunc::Trigger_cmp);

    sort(BeforeAction_List.begin(), BeforeAction_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterAction_List.begin(), AfterAction_List.end(), TriggerFunc::Trigger_cmp);
    sort(Before_attack_List.begin(), Before_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(After_attack_List.begin(), After_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_attack_List.begin(), When_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(Buff_List.begin(), Buff_List.end(), TriggerFunc::Trigger_cmp);

    sort(Stats_Adjust_List.begin(), Stats_Adjust_List.end(), TriggerFunc::Trigger_cmp);
    sort(Healing_List.begin(), Healing_List.end(), TriggerFunc::Trigger_cmp);
    sort(HPDecrease_List.begin(), HPDecrease_List.end(), TriggerFunc::Trigger_cmp);
    sort(AllyDeath_List.begin(), AllyDeath_List.end(), TriggerFunc::Trigger_cmp);

    sort(Toughness_break_List.begin(), Toughness_break_List.end(), TriggerFunc::Trigger_cmp);
    sort(Apply_debuff_List.begin(), Apply_debuff_List.end(), TriggerFunc::Trigger_cmp);
    sort(Enemy_Death_List.begin(), Enemy_Death_List.end(), TriggerFunc::Trigger_cmp);

    sort(Enemy_hit_List.begin(), Enemy_hit_List.end(), TriggerFunc::Trigger_cmp);
    sort(Dot_List.begin(), Dot_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_Energy_Increase_List.begin(), When_Energy_Increase_List.end(), TriggerFunc::Trigger_cmp);
    sort(Skill_point_List.begin(), Skill_point_List.end(), TriggerFunc::Trigger_cmp);
    sort(Hit_Count_List.begin(), Hit_Count_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterDealingDamage_List.begin(), AfterDealingDamage_List.end(), TriggerFunc::Trigger_cmp);
    
    if(rerollSubstatsMode == TYPE_STD)rerollFunction = StandardReroll;
    else
    if(rerollSubstatsMode == "AllCombination")rerollFunction = AllCombinationReroll;
    else
    if(rerollSubstatsMode == "AllPossible")rerollFunction = AllPossibleReroll;
    
    for(int i=1;i<=Total_ally;i++){
        // Ally_unit[i]->Atk_flat[AT_NONE] = 0;
        // Ally_unit[i]->Atk_percent[AT_NONE] = 0;
        // Ally_unit[i]->Hp_flat[AT_NONE] = 0;
        // Ally_unit[i]->Hp_percent[AT_NONE] = 0;
        // Ally_unit[i]->Def_flat[AT_NONE] = 0;
        // Ally_unit[i]->Def_percent[AT_NONE] = 0;
        // Ally_unit[i]->Dmg_bonus[AT_NONE] = 0;
        // Ally_unit[i]->Crit_rate[AT_NONE] = 0;
        // Ally_unit[i]->Crit_dam[AT_NONE] = 0;
        // Ally_unit[i]->Def_shred[AT_NONE] = 0;
        // Ally_unit[i]->Respen[AT_NONE] = 0;
        // Ally_unit[i]->Vul[AT_NONE] = 0;
        // Ally_unit[i]->Break_effect[AT_NONE] = 0;
        // Ally_unit[i]->Mitigation[AT_NONE] = 0;
        // Ally_unit[i]->Weakness_Break_Efficiency[AT_NONE] = 0;
        // Ally_unit[i]->Toughness_reduction[AT_NONE] = 0;

        Ally_unit[i]->StatsType_Compare_MAX_MIN.first = -1;
        Ally_unit[i]->StatsType_Compare_MAX_MIN.second = 1e9;
        Ally_unit[i]->TotalSubstats_Compare_MAX_MIN.first = -1;
        Ally_unit[i]->TotalSubstats_Compare_MAX_MIN.second = 1e9;


        Ally_unit[i]->AvgDmgRecord.resize(Total_enemy+1);




    }
}

void Reset(){
    turn = nullptr;
    sp =3;
    Current_atv = 0;
    healCount = 0;
    decreaseHPCount = 0;
    totalTaunt = 0;
    Basic_reset();
    Summon_reset();
    Countdown_reset();
    
    for(TriggerByYourSelf_Func &e : Reset_List){
        e.Call();
    }
    
    Memosprite_reset();
    for(TriggerByYourSelf_Func &e : Setup_Memo_List){
        e.Call();
    }
    for(TriggerByYourSelf_Func &e : When_Combat_List){
        e.Call();
    }
    for(int i=1;i<=Total_ally;i++){
        Ally_unit[i]->SpeedRequirment();
        Ally_unit[i]->EhrRequirment();
    }
    for(TriggerByYourSelf_Func &e : Tune_stats_List){
        e.Call();
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
        Ally_unit[i]->Sub_Unit_ptr[j]->totalATK = calculateAtkOnStats(Ally_unit[i]->Sub_Unit_ptr[0].get());
        Ally_unit[i]->Sub_Unit_ptr[j]->totalHP = calculateHpOnStats(Ally_unit[i]->Sub_Unit_ptr[j].get());
        Ally_unit[i]->Sub_Unit_ptr[j]->totalDEF = calculateDefOnStats(Ally_unit[i]->Sub_Unit_ptr[j].get());
        totalTaunt += Ally_unit[i]->Sub_Unit_ptr[j]->taunt;
        }
        Ally_unit[i]->Sub_Unit_ptr[0]->currentHP = Ally_unit[i]->Sub_Unit_ptr[0]->totalHP;
    }
    
}

void Start_game(){
    All_atv_reset();
    for(TriggerByYourSelf_Func &e : Start_game_List){
        e.Call();
    }
}
void EndWave(double Total_atv){
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
        e.Call();
    }
    
}
#endif