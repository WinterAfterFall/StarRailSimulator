#ifndef Cal_Stats_H
#define Cal_Stats_H
#include<bits/stdc++.h>
#include "../Print.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000






double calculateAtkOnStats(Sub_Unit *ptr){
    double ans = ptr->Base_atk;
    ans*= (100+ptr->Stats_type["Atk%"]["None"])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"]["None"];
    return (ans < 0) ? 0 : ans;
}
double calculateHpOnStats(Sub_Unit *ptr){
    double ans = ptr->Base_hp;
    ans*= (100+ptr->Stats_type["Hp%"]["None"])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"]["None"];
    return (ans < 0) ? 0 : ans;
}
double calculateDefOnStats(Sub_Unit *ptr){
    double ans = ptr->Base_def;
    ans*= (100+ptr->Stats_type["Def%"]["None"])/100.0;
    ans+= ptr->Stats_type["Flat_Def"]["None"];
    return (ans < 0) ? 0 : ans;
}
double calculateSpeedOnStats(Sub_Unit *ptr){
    double ans = ptr->Atv_stats->Base_speed;
    ans*= (100 + ptr->Atv_stats->Speed_percent)/100.0;
    ans+= ptr->Atv_stats->Flat_Speed;
    return (ans < 0) ? 0 : ans;
}
double calculateCritrateOnStats(Sub_Unit *ptr){
    double ans = ptr->Stats_type["Crit_rate"]["None"];
    return (ans < 0) ? 0 : ans;
}
double calculateCritdamOnStats(Sub_Unit *ptr){
    double ans = ptr->Stats_type["Crit_dam"]["None"];
    return (ans < 0) ? 0 : ans;
}
double calculateBreakEffectOnStats(Sub_Unit *ptr){
    double ans = ptr->Stats_type["Break_effect"]["None"];
    return (ans < 0) ? 0 : ans;
}

double calculateHPLost(Sub_Unit *ptr){
    double ans = ptr->totalHP - ptr->currentHP;
    return (ans < 0) ? 0 : ans;
}

double calculateAtkForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Base_atk;
    ans*= (100+ptr->Stats_type["Atk%"]["None"]-ptr->Stats_type["Atk%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"]["None"]-ptr->Stats_type["Flat_Atk"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateHpForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Base_hp;
    ans*= (100+ptr->Stats_type["Hp%"]["None"]-ptr->Stats_type["Hp%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"]["None"]-ptr->Stats_type["Flat_Hp"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateDefForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Base_def;
    ans*= (100+ptr->Stats_type["Def%"]["None"]-ptr->Stats_type["Def%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Def"]["None"]-ptr->Stats_type["Flat_Def"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateSpeedForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Atv_stats->Base_speed;
    ans*= (100 + ptr->Atv_stats->Speed_percent - ptr->Stats_type["Speed%"][AT_TEMP])/100.0;
    ans+= ptr->Atv_stats->Flat_Speed - ptr->Stats_type["Flat_Speed"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;

}
double calculateCritrateForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Stats_type["Crit_rate"]["None"]-ptr->Stats_type["Crit_rate"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateCritdamForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Stats_type["Crit_dam"]["None"]-ptr->Stats_type["Crit_dam"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateBreakEffectForBuff(Sub_Unit *ptr,double ratio){
    double ans = ptr->Stats_type["Break_effect"]["None"]-ptr->Stats_type["Break_effect"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}

double Cal_Atk_multiplier(ActionData &data_,Enemy *target){
    double ans = data_.Attacker->Base_atk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;
    
    Atk_percent_mtpr += data_.Attacker->Stats_type["Atk%"]["None"] + target->Stats_type["Atk%"]["None"];
    Flat_atk_mtpr += data_.Attacker->Stats_type["Flat_Atk"]["None"] + target->Stats_type["Flat_Atk"]["None"];

    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Atk_percent_mtpr+= data_.Attacker->Stats_type["Atk%"][data_.Skill_Type[i]];
            Atk_percent_mtpr+= target->Stats_type["Atk%"][data_.Skill_Type[i]];

            Flat_atk_mtpr += data_.Attacker->Stats_type["Flat_Atk"][data_.Skill_Type[i]];
            Flat_atk_mtpr += target->Stats_type["Flat_Atk"][data_.Skill_Type[i]];
    }
    

    ans = (ans * Atk_percent_mtpr/100) + Flat_atk_mtpr;
    return (ans < 0) ? 0 : ans;
}
double Cal_Hp_multiplier(ActionData &data_,Enemy *target){
    double ans = data_.Attacker->Base_hp;
    double Hp_percent_mtpr = 100;
    double Flat_hp_mtpr = 0;
    Hp_percent_mtpr += data_.Attacker->Stats_type["Hp%"]["None"] + target->Stats_type["Hp%"]["None"];
    Flat_hp_mtpr += data_.Attacker->Stats_type["Flat_Hp"]["None"] + target->Stats_type["Flat_Hp"]["None"];

    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Hp_percent_mtpr+= data_.Attacker->Stats_type["Hp%"][data_.Skill_Type[i]];
            Hp_percent_mtpr+= target->Stats_type["Hp%"][data_.Skill_Type[i]];

            Flat_hp_mtpr += data_.Attacker->Stats_type["Flat_Hp"][data_.Skill_Type[i]];
            Flat_hp_mtpr += target->Stats_type["Flat_Hp"][data_.Skill_Type[i]];
    }
    

    ans = (ans * Hp_percent_mtpr/100) + Flat_hp_mtpr;
    return (ans < 0) ? 0 : ans;
}

double Cal_Def_multiplier(ActionData &data_,Enemy *target){
    double ans = data_.Attacker->Base_def;
    double Def_percent_mtpr = 100;
    double Flat_def_mtpr = 0;

    Def_percent_mtpr += data_.Attacker->Stats_type["Def%"]["None"] + target->Stats_type["Def%"]["None"];
    Flat_def_mtpr += data_.Attacker->Stats_type["Flat_Def"]["None"] + target->Stats_type["Flat_Def"]["None"];

    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Def_percent_mtpr+= data_.Attacker->Stats_type["Def%"][data_.Skill_Type[i]];
            Def_percent_mtpr+= target->Stats_type["Def%"][data_.Skill_Type[i]];

            Flat_def_mtpr += data_.Attacker->Stats_type["Flat_Def"][data_.Skill_Type[i]];
            Flat_def_mtpr += target->Stats_type["Flat_Def"][data_.Skill_Type[i]];
    }
    

    ans = (ans * Def_percent_mtpr/100) + Flat_def_mtpr;
    return (ans < 0) ? 0 : ans;
}
double Cal_Bonus_dmg_multiplier(ActionData &data_,Enemy *target){
    double Bonus_dmg_mtpr = 100;
    
    Bonus_dmg_mtpr += data_.Attacker->Stats_type["Dmg%"]["None"] + target->Stats_type["Dmg%"]["None"] + data_.Attacker->Stats_each_element["Dmg%"][data_.Damage_element]["None"] + target->Stats_each_element["Dmg%"][data_.Damage_element]["None"];

    for(int i = 0, sz = data_.Skill_Type.size(); i < sz; i++){
        Bonus_dmg_mtpr += data_.Attacker->Stats_type["Dmg%"][data_.Skill_Type[i]] + data_.Attacker->Stats_each_element["Dmg%"][data_.Damage_element][data_.Skill_Type[i]];
        Bonus_dmg_mtpr += target->Stats_type["Dmg%"][data_.Skill_Type[i]] + target->Stats_each_element["Dmg%"][data_.Damage_element][data_.Skill_Type[i]];
    }
    return (Bonus_dmg_mtpr / 100 < 0) ? 0 : Bonus_dmg_mtpr / 100;
}
double Cal_Crit_multiplier(ActionData &data_,Enemy *target){
    double Crit_rate_mtpr;
    double Crit_dam_mtpr;

    Crit_rate_mtpr = data_.Attacker->Stats_type["Crit_rate"]["None"] + target->Stats_type["Crit_rate"]["None"];
    Crit_dam_mtpr = data_.Attacker->Stats_type["Crit_dam"]["None"] + target->Stats_type["Crit_dam"]["None"];
    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Crit_rate_mtpr += data_.Attacker->Stats_type["Crit_rate"][data_.Skill_Type[i]] + target->Stats_type["Crit_rate"][data_.Skill_Type[i]];
            Crit_dam_mtpr += data_.Attacker->Stats_type["Crit_dam"][data_.Skill_Type[i]] + target->Stats_type["Crit_dam"][data_.Skill_Type[i]];
    }
    

    if(Crit_rate_mtpr>=100){
        Crit_rate_mtpr = 100;
    }
    return (1+(Crit_rate_mtpr/100 * Crit_dam_mtpr/100));

}
double Cal_Crit_rate_multiplier(ActionData &data_,Enemy *target) {
    double Crit_rate_mtpr;

    Crit_rate_mtpr = data_.Attacker->Stats_type["Crit_rate"]["None"] + target->Stats_type["Crit_rate"]["None"];
    for (int i = 0, sz = data_.Skill_Type.size(); i < sz; i++) {
        Crit_rate_mtpr += data_.Attacker->Stats_type["Crit_rate"][data_.Skill_Type[i]] + target->Stats_type["Crit_rate"][data_.Skill_Type[i]];
    }

    return (Crit_rate_mtpr < 0) ? 0 : Crit_rate_mtpr;
}

double Cal_Crit_dam_multiplier(ActionData &data_,Enemy *target) {
    double Crit_dam_mtpr;

    Crit_dam_mtpr = data_.Attacker->Stats_type["Crit_dam"]["None"] + target->Stats_type["Crit_dam"]["None"];
    for (int i = 0, sz = data_.Skill_Type.size(); i < sz; i++) {
        Crit_dam_mtpr += data_.Attacker->Stats_type["Crit_dam"][data_.Skill_Type[i]] + target->Stats_type["Crit_dam"][data_.Skill_Type[i]];
    }

    return (Crit_dam_mtpr < 0) ? 0 : Crit_dam_mtpr;
}
double Cal_Def_shred_multiplier(ActionData &data_,Enemy *target){
    double Def_shred_mtpr;
    
    Def_shred_mtpr = data_.Attacker->Stats_type["Def_shred"]["None"] + target->Stats_type["Def_shred"]["None"];
    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Def_shred_mtpr += data_.Attacker->Stats_type["Def_shred"][data_.Skill_Type[i]] + target->Stats_type["Def_shred"][data_.Skill_Type[i]];
    }

    

    if(Def_shred_mtpr>=100){
        Def_shred_mtpr = 100;
    }
    return 100/(100 + 115*(1-1*Def_shred_mtpr/100));
}
double Cal_Respen_multiplier(ActionData &data_,Enemy *target){
    double Respen_mtpr = 100;
    
    Respen_mtpr += data_.Attacker->Stats_type["Respen"]["None"] + target->Stats_type["Respen"]["None"] + data_.Attacker->Stats_each_element["Respem"][data_.Damage_element]["None"] + target->Stats_each_element["Respem"][data_.Damage_element]["None"];

    for(int i = 0, sz = data_.Skill_Type.size(); i < sz; i++){
        Respen_mtpr += data_.Attacker->Stats_type["Respen"][data_.Skill_Type[i]] + data_.Attacker->Stats_each_element["Respem"][data_.Damage_element][data_.Skill_Type[i]];
        Respen_mtpr += target->Stats_type["Respen"][data_.Skill_Type[i]] + target->Stats_each_element["Respem"][data_.Damage_element][data_.Skill_Type[i]];
    }
    return (Respen_mtpr / 100 < 0) ? 0 : Respen_mtpr / 100;
}
double Cal_Vul_multiplier(ActionData &data_,Enemy *target){
    double Vul_mtpr = 100;
    
    Vul_mtpr += data_.Attacker->Stats_type["Vul"]["None"] + target->Stats_type["Vul"]["None"];
    for(int i = 0, sz = data_.Skill_Type.size(); i < sz; i++){
        Vul_mtpr += data_.Attacker->Stats_type["Vul"][data_.Skill_Type[i]] + target->Stats_type["Vul"][data_.Skill_Type[i]];
    }
    return (Vul_mtpr / 100 < 0) ? 0 : Vul_mtpr / 100;
}
double Cal_BreakEffect_multiplier(ActionData &data_,Enemy *target){
    double BreakEffect_mtpr = 100;
  
    BreakEffect_mtpr += data_.Attacker->Stats_type["Break_effect"]["None"] + target->Stats_type["Break_effect"]["None"];
    for(int i = 0, sz = data_.Skill_Type.size(); i < sz; i++){
        BreakEffect_mtpr += data_.Attacker->Stats_type["Break_effect"][data_.Skill_Type[i]] + target->Stats_type["Break_effect"][data_.Skill_Type[i]];
    }
    return (BreakEffect_mtpr / 100 < 0) ? 0 : BreakEffect_mtpr / 100;
}
double Cal_Toughness_multiplier(ActionData &data_,Enemy *target){
    if((data_.Action_type.second!="Break_dmg"&&Avg_damage_Mode)||target->Toughness_status==0){
        return 1;
    }else{
        return 0.9;
    }
}
double Cal_Superbreak_DamageIncrease_multiplier(ActionData &data_,Enemy *target){
    double Spb_dmg_mtpr = 100;
    Spb_dmg_mtpr += data_.Attacker->Stats_type["Superbreak_DamageIncrease"]["None"] + target->Stats_type["Superbreak_DamageIncrease"]["None"];
    return (Spb_dmg_mtpr / 100 < 0) ? 0 : Spb_dmg_mtpr / 100;
}
double Cal_Mitigation_multiplier(ActionData &data_,Enemy *target){
    double Mitigation_mtpr = 100;

    Mitigation_mtpr += data_.Attacker->Stats_type["Mitigation"]["None"] + target->Stats_type["Mitigation"]["None"];
    for(int i = 0, sz = data_.Skill_Type.size(); i < sz; i++){
        Mitigation_mtpr += data_.Attacker->Stats_type["Mitigation"][data_.Skill_Type[i]] + target->Stats_type["Mitigation"][data_.Skill_Type[i]];
    }
    return (Mitigation_mtpr / 100 < 0) ? 0 : Mitigation_mtpr / 100;
}

void Cal_effect_hit_rate(Ally *ptr,double Base_chance){
    double temp=100/(Base_chance/100)/((100 - Enemy_effect_res)/100);
    temp = temp-100;
    double x =0;
    temp-=ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"];
    if(temp<=0)return ;
    x = ceil(temp/3.888);
    ptr->Total_substats-=x;
    ptr->Separate_sub-=x;
    ptr->Substats[0].second -=x;
    x = x * 3.888;
    ptr->Sub_effect_hit_rate_use += x;
    ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += ptr->Sub_effect_hit_rate_use;
    for(int i=1,sz = ptr->Sub_Unit_ptr.size();i<sz;i++){
        ptr->Sub_Unit_ptr[i]->Stats_type["Ehr"]["None"]+=x;
    }
    return ;
}
void Cal_Speed_Needed(Ally *ptr,double Speed_Need){
    double temp = ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed+ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed*ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent/100 + ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed;
    temp = Speed_Need - temp;
    double x =0;
    if(temp<=0)return;
    x = ceil(temp/2.3);
    ptr->Total_substats-=x;
    ptr->Separate_sub-=x;
    ptr->Substats[0].second -=x;
    x = x * 2.3;
    ptr->Sub_Speed_use += x;
    ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += x;
    for(int i=1,sz = ptr->Sub_Unit_ptr.size();i<sz;i++){
        ptr->Sub_Unit_ptr[i]->Atv_stats->Flat_Speed+=x*(ptr->Sub_Unit_ptr[i]->Unit_Speed_Ratio/100);
    }
    return;
}
#endif