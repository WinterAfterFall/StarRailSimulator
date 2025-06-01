#ifndef Cal_damage_H
#define Cal_damage_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


void calDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,DmgSrc abilityRatio){
    double Total_dmg = abilityRatio.constDmg;
    
    if(act->Attacker->ptrToChar->checkDamageFormula)
    cout<<"Atk Ratio : "<<abilityRatio.ATK<<"Hp Ratio : "<<abilityRatio.HP<<"Def Ratio : "<<abilityRatio.DEF<<endl;

    Total_dmg += calAtkMultiplier(act,target)*abilityRatio.ATK/100;
    Total_dmg += calHpMultiplier(act,target)*abilityRatio.HP/100;
    Total_dmg += calDefMultiplier(act,target)*abilityRatio.DEF/100;
    Total_dmg = Total_dmg*calBonusDmgMultiplier(act,target);
    Total_dmg = Total_dmg*calCritMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);
    

    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);

}



void Cal_Break_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double &Constant){
    double Total_dmg = Constant *Level_multiplier;
    if(Break_Formula_check_mode&&Break_Formula_check_mode==act->Attacker->Atv_stats->Unit_num){
        cout<<act->Attacker->Atv_stats->Char_Name<<" ";
        cout<<(0.5+target->Max_toughness/40)<<" ";
        cout<<calBreakEffectMultiplier(act,target)<<" ";
        cout<<calDefShredMultiplier(act,target)<<" ";
        cout<<calRespenMultiplier(act,target)<<" ";
        cout<<calVulMultiplier(act,target)<<" ";
        cout<<calMitigationMultiplier(act,target)<<" ";
        cout<<calToughnessMultiplier(act,target)<<" ";
        cout<<endl;
    }
    Total_dmg = Total_dmg*(0.5+target->Max_toughness/40);    
    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);
    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);
    
}
void Cal_Freeze_damage(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Total_dmg = Level_multiplier;
    
    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);
    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);

}

void Cal_Dot_Toughness_break_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double Dot_ratio){
    double Total_dmg = Level_multiplier*Dot_ratio/100;
        
    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);
    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);
}
void Cal_Superbreak_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double Superbreak_ratio){
    double Total_dmg = Level_multiplier*Superbreak_ratio/100;
    if(SuperBreak_Formula_check_mode&&SuperBreak_Formula_check_mode==act->Attacker->Atv_stats->Unit_num){
        cout<<act->Attacker->Atv_stats->Char_Name<<" ";
        cout<<Superbreak_ratio<<" ";
        cout<<calBreakEffectMultiplier(act,target)<<" ";
        cout<<Cal_Superbreak_DamageIncrease_multiplier(act,target)<<" ";
        cout<<calDefShredMultiplier(act,target)<<" ";
        cout<<calRespenMultiplier(act,target)<<" ";
        cout<<calVulMultiplier(act,target)<<" ";
        cout<<calMitigationMultiplier(act,target)<<endl;
    }
    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*Cal_Superbreak_DamageIncrease_multiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);
}

void Cal_Toughness_reduction(shared_ptr<AllyAttackAction> &act,Enemy* target,double Toughness_reduce){
    if(target->Weakness_type[act->Damage_element]==0&& 0 == act->Dont_care_weakness&&target->Current_toughness>0)return ;
    if(target->Weakness_type[act->Damage_element]==0&& 0 != act->Dont_care_weakness&&target->Current_toughness>0){
        Toughness_reduce*=(act->Dont_care_weakness/100);
        target->Current_toughness-=Cal_Total_Toughness_Reduce(act,target,Toughness_reduce);
        if(target->Current_toughness<=0){
            target->Current_toughness*=(100/act->Dont_care_weakness);
        }
    }else{
        target->Current_toughness-=Cal_Total_Toughness_Reduce(act,target,Toughness_reduce);
    }
    
    if(target->Current_toughness<=0&&target->Toughness_status==1){
        
        Toughness_break(act,target);
        target->when_toughness_broken = Current_atv;
    }
}

double Cal_Total_Toughness_Reduce(shared_ptr<AllyAttackAction> &act,Enemy *target,double Base_Toughness_reduce){
    double ans = Base_Toughness_reduce;
    double Toughness_reduction_mtpr =100;
    double Weakness_Break_Efficiency_mtpr =100;
    Toughness_reduction_mtpr += act->Attacker->Stats_type["Toughness_reduction"][AT_NONE] + target->Stats_type["Toughness_reduction"][AT_NONE];
    Weakness_Break_Efficiency_mtpr += act->Attacker->Stats_type["Weakness_Break_Efficiency"][AT_NONE] + target->Stats_type["Weakness_Break_Efficiency"][AT_NONE];
    
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Toughness_reduction_mtpr += act->Attacker->Stats_type["Toughness_reduction"][act->actionTypeList[i]] + target->Stats_type["Toughness_reduction"][act->actionTypeList[i]];

        }
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            Weakness_Break_Efficiency_mtpr += act->Attacker->Stats_type["Weakness_Break_Efficiency"][act->actionTypeList[i]] + target->Stats_type["Weakness_Break_Efficiency"][act->actionTypeList[i]];

        }
     
    ans *= (Toughness_reduction_mtpr/100);
    ans *= ((Weakness_Break_Efficiency_mtpr)/100);
    return ans;
}


#endif