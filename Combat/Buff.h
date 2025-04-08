#ifndef BUFF_H
#define BUFF_H
#include "../Unit/Trigger_Function.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




//Set base

//normal buff/debuff
// 
SubUnit* Action_value_stats::isSubUnitCheck(){
    return dynamic_cast<SubUnit*>(this->ptr_to_unit);
}
Enemy* Action_value_stats::isEnemyCheck(){
    return dynamic_cast<Enemy*>(this->ptr_to_unit);
}
SubUnit* Unit::isSubUnitCheck() {
    return dynamic_cast<SubUnit*>(this);
}
Enemy* Unit::isEnemyCheck(){
    return dynamic_cast<Enemy*>(this);
}

SubUnit* chooseSubUnitBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum]->Sub_Unit_ptr[ptr->currentSubUnitTargetNum].get();
}
Ally* chooseCharacterBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum].get();
}
Enemy* chooseEnemyTarget(SubUnit *ptr){
    return Enemy_unit[ptr->Enemy_target_num].get();
}

void StatsAdjust(SubUnit *ptr,string statsType){
    if(statsType == "Atk%"||statsType == "Flat_Atk")AtkAdjust(ptr);
    if(statsType == "Hp%"||statsType == "Flat_Hp")HpAdjust(ptr);
    if(statsType == "Def%"||statsType == "Flat_Def")DefAdjust(ptr);

    if(!AdjustCheck)allEventAdjustStats(ptr,statsType);
}
void AtkAdjust(SubUnit *ptr){
    ptr->totalATK = calculateAtkOnStats(ptr);
}
void HpAdjust(SubUnit *ptr){
    double temp = calculateHpOnStats(ptr);
    if(ptr->currentHP==0){
        ptr->totalHP = temp;
        return;
    }
    if(temp<ptr->currentHP){
        ptr->currentHP = (ptr->currentHP > temp) ? temp : ptr->currentHP;
    }else{
        ptr->currentHP += (temp-ptr->totalHP);
    }
    ptr->totalHP = temp;
    
}
void DefAdjust(SubUnit *ptr){
    ptr->totalDEF= calculateDefOnStats(ptr);
    
}
//normal extend buff / debuff
void Extend_Buff_single_target(SubUnit *ptr,string Buff_name,int Turn_extend){
    ptr->Buff_countdown[Buff_name] = ptr->Atv_stats->turn_cnt+Turn_extend;
}
void Extend_Buff_single_with_all_memo(Ally *ptr,string Buff_name,int Turn_extend){
    for(int i=0;i<ptr->Sub_Unit_ptr.size();i++){
        ptr->Sub_Unit_ptr[i]->Buff_countdown[Buff_name] = ptr->Sub_Unit_ptr[i]->Atv_stats->turn_cnt+Turn_extend;
    }
}
void Extend_Buff_All_Ally(string Buff_name,int Turn_extend){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            Ally_unit[i]->Sub_Unit_ptr[j]->Buff_countdown[Buff_name] = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->turn_cnt + Turn_extend;
        }
    }
}
void Extend_Buff_All_Ally_Excluding_Buffer(string Buff_name,int Turn_extend,string Buffer_name){
    for(int i=1;i<=Total_ally;i++){
        if(Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name==Buffer_name)continue;

        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            Ally_unit[i]->Sub_Unit_ptr[j]->Buff_countdown[Buff_name] = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->turn_cnt + Turn_extend;
        }
    }
}
void Extend_Debuff_single_target(Enemy *ptr,string Debuff_name,int Turn_extend){
    ptr->Debuff_time_count[Debuff_name] = ptr->Atv_stats->turn_cnt+Turn_extend;
}
void Extend_Debuff_All_Enemy(string Debuff_name,int Turn_extend){
    for(int i=1;i<=Total_enemy;i++){
        Enemy_unit[i]->Debuff_time_count[Debuff_name] = Enemy_unit[i]->Atv_stats->turn_cnt + Turn_extend;
    }
}

bool Buff_end(SubUnit *ptr,string Buff_name){
    if(ptr->Atv_stats->turn_cnt==ptr->Buff_countdown[Buff_name]&&turn->Char_Name==ptr->Atv_stats->Char_Name){
        return true;
    }
    return false;
}
bool Debuff_end(Enemy *ptr,string Debuff_name){
    if(ptr->Atv_stats->turn_cnt==ptr->Debuff_time_count[Debuff_name]&&turn->Char_Name==ptr->Atv_stats->Char_Name){
        return true;
    }
    return false;
}
bool Buff_check(SubUnit *ptr,string Buff_name){
    if(ptr->Buff_check[Buff_name]==1){
        return true;
    }
    return false;
}
bool Debuff_check(Enemy *ptr,string Debuff_name){
    if(ptr->Debuff[Debuff_name]==1){
        return true;
    }
    return false;
}
#endif