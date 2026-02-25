#include "../include.h"

void Setup(){
    if(Driver_num&&driverType==DriverType::None)driverType = DriverType::DoubleTurn;
    
    sort(Reset_List.begin(), Reset_List.end(), TriggerFunc::Trigger_cmp);
    sort(WhenOnField_List.begin(), WhenOnField_List.end(), TriggerFunc::Trigger_cmp);
    sort(Tune_stats_List.begin(), Tune_stats_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_game_List.begin(), Start_game_List.end(), TriggerFunc::Trigger_cmp);
    sort(Start_wave_List.begin(), Start_wave_List.end(), TriggerFunc::Trigger_cmp);
    sort(Before_turn_List.begin(), Before_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(After_turn_List.begin(), After_turn_List.end(), TriggerFunc::Trigger_cmp);
    sort(Ultimate_List.begin(), Ultimate_List.end(), TriggerFunc::Trigger_cmp);
    sort(ElationSkill_List.begin(), ElationSkill_List.end(), TriggerFunc::Trigger_cmp);
    sort(WhenUseUlt_List.begin(), WhenUseUlt_List.end(), TriggerFunc::Trigger_cmp);
    

    sort(BeforeAction_List.begin(), BeforeAction_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterAction_List.begin(), AfterAction_List.end(), TriggerFunc::Trigger_cmp);
    sort(BeforeAttackAction_List.begin(), BeforeAttackAction_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterAttackActionList.begin(), AfterAttackActionList.end(), TriggerFunc::Trigger_cmp);
    sort(BeforeAttack_List.begin(), BeforeAttack_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterAttack_List.begin(), AfterAttack_List.end(), TriggerFunc::Trigger_cmp);
    sort(BeforeAttackPerHit_List.begin(), BeforeAttackPerHit_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterAttackPerHit_List.begin(), AfterAttackPerHit_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_attack_List.begin(), When_attack_List.end(), TriggerFunc::Trigger_cmp);
    sort(Buff_List.begin(), Buff_List.end(), TriggerFunc::Trigger_cmp);

    sort(Stats_Adjust_List.begin(), Stats_Adjust_List.end(), TriggerFunc::Trigger_cmp);
    sort(Healing_List.begin(), Healing_List.end(), TriggerFunc::Trigger_cmp);
    sort(HPDecrease_List.begin(), HPDecrease_List.end(), TriggerFunc::Trigger_cmp);
    sort(AllyDeath_List.begin(), AllyDeath_List.end(), TriggerFunc::Trigger_cmp);

    sort(Toughness_break_List.begin(), Toughness_break_List.end(), TriggerFunc::Trigger_cmp);
    sort(BeforeApplyDebuff.begin(), BeforeApplyDebuff.end(), TriggerFunc::Trigger_cmp);
    sort(AfterApplyDebuff.begin(), AfterApplyDebuff.end(), TriggerFunc::Trigger_cmp);
    sort(Enemy_Death_List.begin(), Enemy_Death_List.end(), TriggerFunc::Trigger_cmp);

    sort(Enemy_hit_List.begin(), Enemy_hit_List.end(), TriggerFunc::Trigger_cmp);
    sort(Dot_List.begin(), Dot_List.end(), TriggerFunc::Trigger_cmp);
    sort(When_Energy_Increase_List.begin(), When_Energy_Increase_List.end(), TriggerFunc::Trigger_cmp);
    sort(Skill_point_List.begin(), Skill_point_List.end(), TriggerFunc::Trigger_cmp);
    sort(AfterDealingDamage_List.begin(), AfterDealingDamage_List.end(), TriggerFunc::Trigger_cmp);
    
    if(rerollSubstatsMode == SubstatsRerollMode::Standard)rerollFunction = StandardReroll;
    else
    if(rerollSubstatsMode == SubstatsRerollMode::AllCombination)rerollFunction = AllCombinationReroll;
    else
    if(rerollSubstatsMode == SubstatsRerollMode::AllPossible)rerollFunction = AllPossibleReroll;
    
    for(int i=1;i<=Total_ally;i++){
        charUnit[i]->StatsType_Compare_MAX_MIN.first = -1;
        charUnit[i]->StatsType_Compare_MAX_MIN.second = 1e9;
        charUnit[i]->TotalSubstats_Compare_MAX_MIN.first = -1;
        charUnit[i]->TotalSubstats_Compare_MAX_MIN.second = 1e9;
        charUnit[i]->AvgDmgRecord.resize(Total_enemy+1);
    }
    for(TriggerByYourSelf_Func &e : Setup_List){
        e.Call();
    }
    if(elationCount){
        Path temp = Path::Elation;
        atvList.push_back(aha.get());
        ahaSpeedAdjust(temp);
    }



}

void Reset(){
    turn = nullptr;
    sp =3;
    punchline = elationCount;
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
    for(TriggerByYourSelf_Func &e : WhenOnField_List){
        e.Call();
    }
    for(int i=1;i<=Total_ally;i++){
        charUnit[i]->SpeedRequirment();
        charUnit[i]->EhrRequirment();
    }
    for(TriggerByYourSelf_Func &e : Tune_stats_List){
        e.Call();
    }
    for(auto &each : charList){
        each->totalATK = calculateAtkOnStats(each);
        each->totalHP = calculateHpOnStats(each);
        each->totalDEF = calculateDefOnStats(each);
        totalTaunt += each->taunt;
        for(auto &memo : each->memospriteList){
            memo->totalATK = calculateAtkOnStats(memo.get());
            memo->totalHP = calculateHpOnStats(memo.get());
            memo->totalDEF = calculateDefOnStats(memo.get());
            totalTaunt += memo->taunt;
        }
        each->currentHP = each->totalHP;
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
        enemyUnit[i]->when_toughness_broken = 0;
        enemyUnit[i]->Total_toughness_broken_time = 0;
    }
    for(TriggerByYourSelf_Func &e : Start_wave_List){
        e.Call();
    }
    
}
