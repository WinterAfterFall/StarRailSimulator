#include "../include.h"

double calculateAtkOnStats(SubUnit *ptr){
    double ans = ptr->baseAtk;
    ans*= (100+ptr->Stats_type["Atk%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateHpOnStats(SubUnit *ptr){
    double ans = ptr->baseHp;
    ans*= (100+ptr->Stats_type["Hp%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateDefOnStats(SubUnit *ptr){
    double ans = ptr->baseDef;
    ans*= (100+ptr->Stats_type["Def%"][AT_NONE])/100.0;
    ans+= ptr->Stats_type["Flat_Def"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateSpeedOnStats(SubUnit *ptr){
    double ans = ptr->Atv_stats->baseSpeed;
    ans*= (100 + ptr->Atv_stats->speedPercent)/100.0;
    ans+= ptr->Atv_stats->flatSpeed;
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
    double ans = ptr->baseAtk;
    ans*= (100+ptr->Stats_type["Atk%"][AT_NONE]-ptr->Stats_type["Atk%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Atk"][AT_NONE]-ptr->Stats_type["Flat_Atk"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateHpForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->baseHp;
    ans*= (100+ptr->Stats_type["Hp%"][AT_NONE]-ptr->Stats_type["Hp%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Hp"][AT_NONE]-ptr->Stats_type["Flat_Hp"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateDefForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->baseDef;
    ans*= (100+ptr->Stats_type["Def%"][AT_NONE]-ptr->Stats_type["Def%"][AT_TEMP])/100.0;
    ans+= ptr->Stats_type["Flat_Def"][AT_NONE]-ptr->Stats_type["Flat_Def"][AT_TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateSpeedForBuff(SubUnit *ptr,double ratio){
    double ans = ptr->Atv_stats->baseSpeed;
    ans*= (100 + ptr->Atv_stats->speedPercent - ptr->Stats_type["Speed%"][AT_TEMP])/100.0;
    ans+= ptr->Atv_stats->flatSpeed - ptr->Stats_type["Flat_Speed"][AT_TEMP];
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

double calAtkMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseAtk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;
    
    Atk_percent_mtpr += act->source->Stats_type["Atk%"][AT_NONE] + target->Stats_type["Atk%"][AT_NONE];
    Flat_atk_mtpr += act->source->Stats_type["Flat_Atk"][AT_NONE] + target->Stats_type["Flat_Atk"][AT_NONE];
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Atk_percent_mtpr+= act->source->Stats_type["Atk%"][act->actionTypeList[i]];
            Atk_percent_mtpr+= target->Stats_type["Atk%"][act->actionTypeList[i]];

            Flat_atk_mtpr += act->source->Stats_type["Flat_Atk"][act->actionTypeList[i]];
            Flat_atk_mtpr += target->Stats_type["Flat_Atk"][act->actionTypeList[i]];
    }
    

    ans = (ans * Atk_percent_mtpr/100) + Flat_atk_mtpr;
    return (ans < 0) ? 0 : ans;
}
double calHpMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseHp;
    double Hp_percent_mtpr = 100;
    double Flat_hp_mtpr = 0;
    Hp_percent_mtpr += act->source->Stats_type["Hp%"][AT_NONE] + target->Stats_type["Hp%"][AT_NONE];
    Flat_hp_mtpr += act->source->Stats_type["Flat_Hp"][AT_NONE] + target->Stats_type["Flat_Hp"][AT_NONE];

    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Hp_percent_mtpr+= act->source->Stats_type["Hp%"][act->actionTypeList[i]];
            Hp_percent_mtpr+= target->Stats_type["Hp%"][act->actionTypeList[i]];

            Flat_hp_mtpr += act->source->Stats_type["Flat_Hp"][act->actionTypeList[i]];
            Flat_hp_mtpr += target->Stats_type["Flat_Hp"][act->actionTypeList[i]];
    }
    

    ans = (ans * Hp_percent_mtpr/100) + Flat_hp_mtpr;
    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseDef;
    double Def_percent_mtpr = 100;
    double Flat_def_mtpr = 0;

    Def_percent_mtpr += act->source->Stats_type["Def%"][AT_NONE] + target->Stats_type["Def%"][AT_NONE];
    Flat_def_mtpr += act->source->Stats_type["Flat_Def"][AT_NONE] + target->Stats_type["Flat_Def"][AT_NONE];

    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Def_percent_mtpr+= act->source->Stats_type["Def%"][act->actionTypeList[i]];
            Def_percent_mtpr+= target->Stats_type["Def%"][act->actionTypeList[i]];

            Flat_def_mtpr += act->source->Stats_type["Flat_Def"][act->actionTypeList[i]];
            Flat_def_mtpr += target->Stats_type["Flat_Def"][act->actionTypeList[i]];
    }
    

    ans = (ans * Def_percent_mtpr/100) + Flat_def_mtpr;
    return (ans < 0) ? 0 : ans;
}
double calBonusDmgMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Bonus_dmg_mtpr = 100;
    
    Bonus_dmg_mtpr += act->Attacker->Stats_type[ST_DMG][AT_NONE] + target->Stats_type[ST_DMG][AT_NONE] + act->Attacker->Stats_each_element[ST_DMG][act->Damage_element][AT_NONE] + target->Stats_each_element[ST_DMG][act->Damage_element][AT_NONE];

    for(int i = 0, sz = act->actionTypeList.size(); i < sz; i++){
        Bonus_dmg_mtpr += act->Attacker->Stats_type[ST_DMG][act->actionTypeList[i]] + act->Attacker->Stats_each_element[ST_DMG][act->Damage_element][act->actionTypeList[i]];
        Bonus_dmg_mtpr += target->Stats_type[ST_DMG][act->actionTypeList[i]] + target->Stats_each_element[ST_DMG][act->Damage_element][act->actionTypeList[i]];
    }
    return Bonus_dmg_mtpr / 100;
    // return (Bonus_dmg_mtpr / 100 < 0) ? 0 : Bonus_dmg_mtpr / 100;
}
double calCritMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Crit_rate_mtpr;
    double Crit_dam_mtpr;

    Crit_rate_mtpr = act->Attacker->Stats_type[ST_CR][AT_NONE] + target->Stats_type[ST_CR][AT_NONE];
    Crit_dam_mtpr = act->Attacker->Stats_type[ST_CD][AT_NONE] + target->Stats_type[ST_CD][AT_NONE];
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Crit_rate_mtpr += act->Attacker->Stats_type[ST_CR][act->actionTypeList[i]] + target->Stats_type[ST_CR][act->actionTypeList[i]];
            Crit_dam_mtpr += act->Attacker->Stats_type[ST_CD][act->actionTypeList[i]] + target->Stats_type[ST_CD][act->actionTypeList[i]];
    }
    

    if(Crit_rate_mtpr>=100){
        Crit_rate_mtpr = 100;
    }
    return (1+(Crit_rate_mtpr/100 * Crit_dam_mtpr/100));

}
double Cal_Crit_rate_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double Crit_rate_mtpr;

    Crit_rate_mtpr = act->Attacker->Stats_type[ST_CR][AT_NONE] + target->Stats_type[ST_CR][AT_NONE];
    for (int i = 0, sz = act->actionTypeList.size(); i < sz; i++) {
        Crit_rate_mtpr += act->Attacker->Stats_type[ST_CR][act->actionTypeList[i]] + target->Stats_type[ST_CR][act->actionTypeList[i]];
    }

    return (Crit_rate_mtpr < 0) ? 0 : Crit_rate_mtpr;
}

double Cal_Crit_dam_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double Crit_dam_mtpr;

    Crit_dam_mtpr = act->Attacker->Stats_type[ST_CD][AT_NONE] + target->Stats_type[ST_CD][AT_NONE];
    for (int i = 0, sz = act->actionTypeList.size(); i < sz; i++) {
        Crit_dam_mtpr += act->Attacker->Stats_type[ST_CD][act->actionTypeList[i]] + target->Stats_type[ST_CD][act->actionTypeList[i]];
    }

    return (Crit_dam_mtpr < 0) ? 0 : Crit_dam_mtpr;
}
double calDefShredMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Def_shred_mtpr;
    
    Def_shred_mtpr = act->Attacker->Stats_type[ST_DEF_SHRED][AT_NONE] + target->Stats_type[ST_DEF_SHRED][AT_NONE];
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Def_shred_mtpr += act->Attacker->Stats_type[ST_DEF_SHRED][act->actionTypeList[i]] + target->Stats_type[ST_DEF_SHRED][act->actionTypeList[i]];
    }

    

    if(Def_shred_mtpr>=100){
        Def_shred_mtpr = 100;
    }
    return 100/(100 + 115*(1-1*Def_shred_mtpr/100));
}
double calRespenMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Respen_mtpr = 100;
    
    Respen_mtpr += act->Attacker->Stats_type["Respen"][AT_NONE] + target->Stats_type["Respen"][AT_NONE] + act->Attacker->Stats_each_element["Respem"][act->Damage_element][AT_NONE] + target->Stats_each_element["Respem"][act->Damage_element][AT_NONE];

    for(int i = 0, sz = act->actionTypeList.size(); i < sz; i++){
        Respen_mtpr += act->Attacker->Stats_type["Respen"][act->actionTypeList[i]] + act->Attacker->Stats_each_element["Respem"][act->Damage_element][act->actionTypeList[i]];
        Respen_mtpr += target->Stats_type["Respen"][act->actionTypeList[i]] + target->Stats_each_element["Respem"][act->Damage_element][act->actionTypeList[i]];
    }
    return (Respen_mtpr / 100 < 0) ? 0 : Respen_mtpr / 100;
}
double calVulMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Vul_mtpr = 100;
    
    Vul_mtpr += act->Attacker->Stats_type["Vul"][AT_NONE] + target->Stats_type["Vul"][AT_NONE];
    for(int i = 0, sz = act->actionTypeList.size(); i < sz; i++){
        Vul_mtpr += act->Attacker->Stats_type["Vul"][act->actionTypeList[i]] + target->Stats_type["Vul"][act->actionTypeList[i]];
    }
    return (Vul_mtpr / 100 < 0) ? 0 : Vul_mtpr / 100;
}
double calBreakEffectMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double BreakEffect_mtpr = 100;
  
    BreakEffect_mtpr += act->Attacker->Stats_type[ST_BE][AT_NONE] + target->Stats_type[ST_BE][AT_NONE];
    for(int i = 0, sz = act->actionTypeList.size(); i < sz; i++){
        BreakEffect_mtpr += act->Attacker->Stats_type[ST_BE][act->actionTypeList[i]] + target->Stats_type[ST_BE][act->actionTypeList[i]];
    }
    return (BreakEffect_mtpr / 100 < 0) ? 0 : BreakEffect_mtpr / 100;
}
double calToughnessMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    if(act->toughnessAvgCalculate||target->Toughness_status==0){
        return 1;
    }else{
        return 0.9;
    }
}
double Cal_Superbreak_DamageIncrease_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Spb_dmg_mtpr = 100;
    Spb_dmg_mtpr += act->Attacker->Stats_type["Superbreak_DamageIncrease"][AT_NONE] + target->Stats_type["Superbreak_DamageIncrease"][AT_NONE];
    return (Spb_dmg_mtpr / 100 < 0) ? 0 : Spb_dmg_mtpr / 100;
}
double calMitigationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Mitigation_mtpr = 100;

    Mitigation_mtpr += act->Attacker->Stats_type["Mitigation"][AT_NONE] + target->Stats_type["Mitigation"][AT_NONE];
    for(int i = 0, sz = act->actionTypeList.size(); i < sz; i++){
        Mitigation_mtpr += act->Attacker->Stats_type["Mitigation"][act->actionTypeList[i]] + target->Stats_type["Mitigation"][act->actionTypeList[i]];
    }
    return (Mitigation_mtpr / 100 < 0) ? 0 : Mitigation_mtpr / 100;
}
