#ifndef Cal_damage_H
#define Cal_damage_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


void Cal_Damage(shared_ptr<AllyAttackAction> &data_,Enemy *target,DmgSrc abilityRatio){
    double Total_dmg = abilityRatio.constDmg;
    
    if(data_->Attacker->ptrToChar->checkDamageFormula)
    cout<<"Atk Ratio : "<<abilityRatio.ATK<<"Hp Ratio : "<<abilityRatio.HP<<"Def Ratio : "<<abilityRatio.DEF<<endl;

    Total_dmg += Cal_Atk_multiplier(data_,target)*abilityRatio.ATK/100;
    Total_dmg += Cal_Hp_multiplier(data_,target)*abilityRatio.HP/100;
    Total_dmg += Cal_Def_multiplier(data_,target)*abilityRatio.DEF/100;
    Total_dmg = Total_dmg*Cal_Bonus_dmg_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Crit_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    

    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);

}



void Cal_Break_damage(shared_ptr<AllyAttackAction> &data_,Enemy *target,double &Constant){
    double Total_dmg = Constant *Level_multiplier;
    if(Break_Formula_check_mode&&Break_Formula_check_mode==data_->Attacker->Atv_stats->Unit_num){
        cout<<data_->Attacker->Atv_stats->Char_Name<<" ";
        cout<<(0.5+target->Max_toughness/40)<<" ";
        cout<<Cal_BreakEffect_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<" ";
        cout<<Cal_Toughness_multiplier(data_,target)<<" ";
        cout<<endl;
    }
    Total_dmg = Total_dmg*(0.5+target->Max_toughness/40);    
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);
    
}
void Cal_Freeze_damage(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    double Total_dmg = Level_multiplier;
    
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);

}

void Cal_Dot_Toughness_break_damage(shared_ptr<AllyAttackAction> &data_,Enemy *target,double Dot_ratio){
    double Total_dmg = Level_multiplier*Dot_ratio/100;
        
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);
}
void Cal_Superbreak_damage(shared_ptr<AllyAttackAction> &data_,Enemy *target,double Superbreak_ratio){
    double Total_dmg = Level_multiplier*Superbreak_ratio/100;
    if(SuperBreak_Formula_check_mode&&SuperBreak_Formula_check_mode==data_->Attacker->Atv_stats->Unit_num){
        cout<<data_->Attacker->Atv_stats->Char_Name<<" ";
        cout<<Superbreak_ratio<<" ";
        cout<<Cal_BreakEffect_multiplier(data_,target)<<" ";
        cout<<Cal_Superbreak_DamageIncrease_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<endl;
    }
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Superbreak_DamageIncrease_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);
}
void Cal_Additional_damage(shared_ptr<AllyAttackAction> &data_,Enemy *target,DmgSrc abilityRatio){
    double Total_dmg = abilityRatio.constDmg;

    Total_dmg += Cal_Atk_multiplier(data_,target)*abilityRatio.ATK/100;
    Total_dmg += Cal_Hp_multiplier(data_,target)*abilityRatio.HP/100;
    Total_dmg += Cal_Def_multiplier(data_,target)*abilityRatio.DEF/100;
    Total_dmg = Total_dmg*Cal_Bonus_dmg_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Crit_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    
    Cal_DamageNote(data_,target,target,Total_dmg,100,data_->actionName);
    allEventAfterDealingDamage(data_,target,Total_dmg);
    
}
void Cal_Toughness_reduction(shared_ptr<AllyAttackAction> &data_,Enemy* target,double Toughness_reduce){
    if(target->Weakness_type[data_->Damage_element]==0&& 0 == data_->Dont_care_weakness&&target->Current_toughness>0)return ;
    if(target->Weakness_type[data_->Damage_element]==0&& 0 != data_->Dont_care_weakness&&target->Current_toughness>0){
        Toughness_reduce*=(data_->Dont_care_weakness/100);
        target->Current_toughness-=Cal_Total_Toughness_Reduce(data_,target,Toughness_reduce);
        if(target->Current_toughness<=0){
            target->Current_toughness*=(100/data_->Dont_care_weakness);
        }
    }else{
        target->Current_toughness-=Cal_Total_Toughness_Reduce(data_,target,Toughness_reduce);
    }
    
    if(target->Current_toughness<=0&&target->Toughness_status==1){
        
        Toughness_break(data_,target);
        target->when_toughness_broken = Current_atv;
    }
}

double Cal_Total_Toughness_Reduce(shared_ptr<AllyAttackAction> &data_,Enemy *target,double Base_Toughness_reduce){
    double ans = Base_Toughness_reduce;
    double Toughness_reduction_mtpr =100;
    double Weakness_Break_Efficiency_mtpr =100;
    Toughness_reduction_mtpr += data_->Attacker->Stats_type["Toughness_reduction"][AT_NONE] + target->Stats_type["Toughness_reduction"][AT_NONE];
    Weakness_Break_Efficiency_mtpr += data_->Attacker->Stats_type["Weakness_Break_Efficiency"][AT_NONE] + target->Stats_type["Weakness_Break_Efficiency"][AT_NONE];
    
    for(int i=0,sz=data_->actionTypeList.size();i<sz;i++){
            Toughness_reduction_mtpr += data_->Attacker->Stats_type["Toughness_reduction"][data_->actionTypeList[i]] + target->Stats_type["Toughness_reduction"][data_->actionTypeList[i]];

        }
    for(int i=0,sz=data_->actionTypeList.size();i<sz;i++){
            Weakness_Break_Efficiency_mtpr += data_->Attacker->Stats_type["Weakness_Break_Efficiency"][data_->actionTypeList[i]] + target->Stats_type["Weakness_Break_Efficiency"][data_->actionTypeList[i]];

        }
     
    ans *= (Toughness_reduction_mtpr/100);
    ans *= ((Weakness_Break_Efficiency_mtpr)/100);
    return ans;
}


#endif