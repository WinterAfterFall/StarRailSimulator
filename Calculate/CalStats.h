#ifndef Cal_Stats_H
#define Cal_Stats_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000






double calculateAtkOnStats(SubUnit *ptr){
    double ans = ptr->Base_atk;
    ans*= (100+ptr->Stats_type["Atk%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateHpOnStats(SubUnit *ptr){
    double ans = ptr->Base_hp;
    ans*= (100+ptr->Stats_type["Hp%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateDefOnStats(SubUnit *ptr){
    double ans = ptr->Base_def;
    ans*= (100+ptr->Stats_type["Def%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Def"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateSpeedOnStats(SubUnit *ptr){
    double ans = ptr->Atv_stats->Base_speed;
    ans*= (100 + ptr->Atv_stats->Speed_percent)/100.0;
    ans+= ptr->Atv_stats->Flat_Speed;
    return (ans < 0) ? 0 : ans;
}
double calculateCritrateOnStats(SubUnit *ptr){
    double ans = ptr->Stats_type[ST_CR][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateCritdamOnStats(SubUnit *ptr){
    double ans = ptr->Stats_type[ST_CD][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateBreakEffectOnStats(SubUnit *ptr){
    double ans = ptr->Stats_type[ST_BE][AT_NONE];
    return (ans < 0) ? 0 : ans;
}

double calculateHPLost(SubUnit *ptr){
    double ans = ptr->totalHP - ptr->currentHP;
    return (ans < 0) ? 0 : ans;
}

double calculateAtkForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Base_atk;
    ans*= (100+ptr->Stats_type["Atk%"][AT_NONE]-ptr->Stats_type["Atk%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"][AT_NONE]-ptr->Stats_type["Flat_Atk"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateHpForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Base_hp;
    ans*= (100+ptr->Stats_type["Hp%"][AT_NONE]-ptr->Stats_type["Hp%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"][AT_NONE]-ptr->Stats_type["Flat_Hp"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateDefForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Base_def;
    ans*= (100+ptr->Stats_type["Def%"][AT_NONE]-ptr->Stats_type["Def%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Def"][AT_NONE]-ptr->Stats_type["Flat_Def"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateSpeedForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Atv_stats->Base_speed;
    ans*= (100 + ptr->Atv_stats->Speed_percent - ptr->Stats_type["Speed%"][AT_TEMP])/100.0;
    ans+= ptr->Atv_stats->Flat_Speed - ptr->Stats_type["Flat_Speed"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;

}
double calculateCritrateForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Stats_type[ST_CR][AT_NONE]-ptr->Stats_type[ST_CR][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateCritdamForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Stats_type[ST_CD][AT_NONE]-ptr->Stats_type[ST_CD][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateBreakEffectForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Stats_type[ST_BE][AT_NONE]-ptr->Stats_type[ST_BE][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}

double Cal_Atk_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double ans = data_->source->Base_atk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;
    
    Atk_percent_mtpr += data_->source->Stats_type["Atk%"][AT_NONE] + target->Stats_type["Atk%"][AT_NONE];
    Flat_atk_mtpr += data_->source->Stats_type["Flat_Atk"][AT_NONE] + target->Stats_type["Flat_Atk"][AT_NONE];
    for(int i=0,sz=data_->abilityTypeList.size();i<sz;i++){
            Atk_percent_mtpr+= data_->source->Stats_type["Atk%"][data_->abilityTypeList[i]];
            Atk_percent_mtpr+= target->Stats_type["Atk%"][data_->abilityTypeList[i]];

            Flat_atk_mtpr += data_->source->Stats_type["Flat_Atk"][data_->abilityTypeList[i]];
            Flat_atk_mtpr += target->Stats_type["Flat_Atk"][data_->abilityTypeList[i]];
    }
    

    ans = (ans * Atk_percent_mtpr/100) + Flat_atk_mtpr;
    return (ans < 0) ? 0 : ans;
}
double Cal_Hp_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double ans = data_->source->Base_hp;
    double Hp_percent_mtpr = 100;
    double Flat_hp_mtpr = 0;
    Hp_percent_mtpr += data_->source->Stats_type["Hp%"][AT_NONE] + target->Stats_type["Hp%"][AT_NONE];
    Flat_hp_mtpr += data_->source->Stats_type["Flat_Hp"][AT_NONE] + target->Stats_type["Flat_Hp"][AT_NONE];

    for(int i=0,sz=data_->abilityTypeList.size();i<sz;i++){
            Hp_percent_mtpr+= data_->source->Stats_type["Hp%"][data_->abilityTypeList[i]];
            Hp_percent_mtpr+= target->Stats_type["Hp%"][data_->abilityTypeList[i]];

            Flat_hp_mtpr += data_->source->Stats_type["Flat_Hp"][data_->abilityTypeList[i]];
            Flat_hp_mtpr += target->Stats_type["Flat_Hp"][data_->abilityTypeList[i]];
    }
    

    ans = (ans * Hp_percent_mtpr/100) + Flat_hp_mtpr;
    return (ans < 0) ? 0 : ans;
}

double Cal_Def_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double ans = data_->source->Base_def;
    double Def_percent_mtpr = 100;
    double Flat_def_mtpr = 0;

    Def_percent_mtpr += data_->source->Stats_type["Def%"][AT_NONE] + target->Stats_type["Def%"][AT_NONE];
    Flat_def_mtpr += data_->source->Stats_type["Flat_Def"][AT_NONE] + target->Stats_type["Flat_Def"][AT_NONE];

    for(int i=0,sz=data_->abilityTypeList.size();i<sz;i++){
            Def_percent_mtpr+= data_->source->Stats_type["Def%"][data_->abilityTypeList[i]];
            Def_percent_mtpr+= target->Stats_type["Def%"][data_->abilityTypeList[i]];

            Flat_def_mtpr += data_->source->Stats_type["Flat_Def"][data_->abilityTypeList[i]];
            Flat_def_mtpr += target->Stats_type["Flat_Def"][data_->abilityTypeList[i]];
    }
    

    ans = (ans * Def_percent_mtpr/100) + Flat_def_mtpr;
    return (ans < 0) ? 0 : ans;
}
double Cal_Bonus_dmg_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Bonus_dmg_mtpr = 100;
    
    Bonus_dmg_mtpr += data_->Attacker->Stats_type[ST_DMG][AT_NONE] + target->Stats_type[ST_DMG][AT_NONE] + data_->Attacker->Stats_each_element[ST_DMG][data_->Damage_element][AT_NONE] + target->Stats_each_element[ST_DMG][data_->Damage_element][AT_NONE];

    for(int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++){
        Bonus_dmg_mtpr += data_->Attacker->Stats_type[ST_DMG][data_->abilityTypeList[i]] + data_->Attacker->Stats_each_element[ST_DMG][data_->Damage_element][data_->abilityTypeList[i]];
        Bonus_dmg_mtpr += target->Stats_type[ST_DMG][data_->abilityTypeList[i]] + target->Stats_each_element[ST_DMG][data_->Damage_element][data_->abilityTypeList[i]];
    }
    return Bonus_dmg_mtpr / 100;
    // return (Bonus_dmg_mtpr / 100 < 0) ? 0 : Bonus_dmg_mtpr / 100;
}
double Cal_Crit_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Crit_rate_mtpr;
    double Crit_dam_mtpr;

    Crit_rate_mtpr = data_->Attacker->Stats_type[ST_CR][AT_NONE] + target->Stats_type[ST_CR][AT_NONE];
    Crit_dam_mtpr = data_->Attacker->Stats_type[ST_CD][AT_NONE] + target->Stats_type[ST_CD][AT_NONE];
    for(int i=0,sz=data_->abilityTypeList.size();i<sz;i++){
            Crit_rate_mtpr += data_->Attacker->Stats_type[ST_CR][data_->abilityTypeList[i]] + target->Stats_type[ST_CR][data_->abilityTypeList[i]];
            Crit_dam_mtpr += data_->Attacker->Stats_type[ST_CD][data_->abilityTypeList[i]] + target->Stats_type[ST_CD][data_->abilityTypeList[i]];
    }
    

    if(Crit_rate_mtpr>=100){
        Crit_rate_mtpr = 100;
    }
    return (1+(Crit_rate_mtpr/100 * Crit_dam_mtpr/100));

}
double Cal_Crit_rate_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target) {
    double Crit_rate_mtpr;

    Crit_rate_mtpr = data_->Attacker->Stats_type[ST_CR][AT_NONE] + target->Stats_type[ST_CR][AT_NONE];
    for (int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++) {
        Crit_rate_mtpr += data_->Attacker->Stats_type[ST_CR][data_->abilityTypeList[i]] + target->Stats_type[ST_CR][data_->abilityTypeList[i]];
    }

    return (Crit_rate_mtpr < 0) ? 0 : Crit_rate_mtpr;
}

double Cal_Crit_dam_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target) {
    double Crit_dam_mtpr;

    Crit_dam_mtpr = data_->Attacker->Stats_type[ST_CD][AT_NONE] + target->Stats_type[ST_CD][AT_NONE];
    for (int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++) {
        Crit_dam_mtpr += data_->Attacker->Stats_type[ST_CD][data_->abilityTypeList[i]] + target->Stats_type[ST_CD][data_->abilityTypeList[i]];
    }

    return (Crit_dam_mtpr < 0) ? 0 : Crit_dam_mtpr;
}
double Cal_Def_shred_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Def_shred_mtpr;
    
    Def_shred_mtpr = data_->Attacker->Stats_type[ST_DEF_SHRED][AT_NONE] + target->Stats_type[ST_DEF_SHRED][AT_NONE];
    for(int i=0,sz=data_->abilityTypeList.size();i<sz;i++){
            Def_shred_mtpr += data_->Attacker->Stats_type[ST_DEF_SHRED][data_->abilityTypeList[i]] + target->Stats_type[ST_DEF_SHRED][data_->abilityTypeList[i]];
    }

    

    if(Def_shred_mtpr>=100){
        Def_shred_mtpr = 100;
    }
    return 100/(100 + 115*(1-1*Def_shred_mtpr/100));
}
double Cal_Respen_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Respen_mtpr = 100;
    
    Respen_mtpr += data_->Attacker->Stats_type["Respen"][AT_NONE] + target->Stats_type["Respen"][AT_NONE] + data_->Attacker->Stats_each_element["Respem"][data_->Damage_element][AT_NONE] + target->Stats_each_element["Respem"][data_->Damage_element][AT_NONE];

    for(int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++){
        Respen_mtpr += data_->Attacker->Stats_type["Respen"][data_->abilityTypeList[i]] + data_->Attacker->Stats_each_element["Respem"][data_->Damage_element][data_->abilityTypeList[i]];
        Respen_mtpr += target->Stats_type["Respen"][data_->abilityTypeList[i]] + target->Stats_each_element["Respem"][data_->Damage_element][data_->abilityTypeList[i]];
    }
    return (Respen_mtpr / 100 < 0) ? 0 : Respen_mtpr / 100;
}
double Cal_Vul_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Vul_mtpr = 100;
    
    Vul_mtpr += data_->Attacker->Stats_type["Vul"][AT_NONE] + target->Stats_type["Vul"][AT_NONE];
    for(int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++){
        Vul_mtpr += data_->Attacker->Stats_type["Vul"][data_->abilityTypeList[i]] + target->Stats_type["Vul"][data_->abilityTypeList[i]];
    }
    return (Vul_mtpr / 100 < 0) ? 0 : Vul_mtpr / 100;
}
double Cal_BreakEffect_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double BreakEffect_mtpr = 100;
  
    BreakEffect_mtpr += data_->Attacker->Stats_type[ST_BE][AT_NONE] + target->Stats_type[ST_BE][AT_NONE];
    for(int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++){
        BreakEffect_mtpr += data_->Attacker->Stats_type[ST_BE][data_->abilityTypeList[i]] + target->Stats_type[ST_BE][data_->abilityTypeList[i]];
    }
    return (BreakEffect_mtpr / 100 < 0) ? 0 : BreakEffect_mtpr / 100;
}
double Cal_Toughness_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    if(data_->toughnessAvgCalculate||target->Toughness_status==0){
        return 1;
    }else{
        return 0.9;
    }
}
double Cal_Superbreak_DamageIncrease_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Spb_dmg_mtpr = 100;
    Spb_dmg_mtpr += data_->Attacker->Stats_type["Superbreak_DamageIncrease"][AT_NONE] + target->Stats_type["Superbreak_DamageIncrease"][AT_NONE];
    return (Spb_dmg_mtpr / 100 < 0) ? 0 : Spb_dmg_mtpr / 100;
}
double Cal_Mitigation_multiplier(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Mitigation_mtpr = 100;

    Mitigation_mtpr += data_->Attacker->Stats_type["Mitigation"][AT_NONE] + target->Stats_type["Mitigation"][AT_NONE];
    for(int i = 0, sz = data_->abilityTypeList.size(); i < sz; i++){
        Mitigation_mtpr += data_->Attacker->Stats_type["Mitigation"][data_->abilityTypeList[i]] + target->Stats_type["Mitigation"][data_->abilityTypeList[i]];
    }
    return (Mitigation_mtpr / 100 < 0) ? 0 : Mitigation_mtpr / 100;
}
#endif