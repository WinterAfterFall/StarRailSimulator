#include "../include.h"

void calDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,DmgSrc abilityRatio){
    double Total_dmg = abilityRatio.constDmg;
    
    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;85m";
        cout<<endl;
        cout<<"From : "<<act->getSubUnit()->getCharName()<<" "<<act->actionName<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    if(act->Attacker->ptrToChar->checkDamageFormula){
        cout<<"Atk Ratio : "<<abilityRatio.ATK<<" Hp Ratio : "<<abilityRatio.HP<<" Def Ratio : "<<abilityRatio.DEF<<" Fix Dmg : "<<abilityRatio.constDmg<<endl;
    }
         
    Total_dmg += calHpMultiplier(act,target)*abilityRatio.HP/100;
    Total_dmg += calAtkMultiplier(act,target)*abilityRatio.ATK/100;
    Total_dmg += calDefMultiplier(act,target)*abilityRatio.DEF/100;
    Total_dmg = Total_dmg*calCritMultiplier(act,target);
    Total_dmg = Total_dmg*calBonusDmgMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);

    if(act->Attacker->ptrToChar->checkDamage){
        cout<<"Damage : "<<Total_dmg<<endl;
    }

    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);

}



void Cal_Break_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double &Constant){
    double Total_dmg = Constant *Level_multiplier;

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Break Dmg --------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getSubUnit()->getCharName()<<" "<<act->actionName<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    Total_dmg = Total_dmg*(0.5+target->Max_toughness/40);    
    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);

    if(act->Attacker->ptrToChar->checkDamage){
        cout<<"Damage : "<<Total_dmg<<endl;
    }

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }

    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);
    
}
void Cal_Freeze_damage(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Total_dmg = Level_multiplier;
    
    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Break Dmg --------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getSubUnit()->getCharName()<<" "<<act->actionName<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);

    if(act->Attacker->ptrToChar->checkDamage){
        cout<<"Damage : "<<Total_dmg<<endl;
    }

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }

    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);

}

void Cal_Dot_Toughness_break_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double Dot_ratio){
    double Total_dmg = Level_multiplier*Dot_ratio/100;

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Break Dmg --------------------\n";    
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getSubUnit()->getCharName()<<" "<<act->actionName<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);
    Total_dmg = Total_dmg*calToughnessMultiplier(act,target);

    if(act->Attacker->ptrToChar->checkDamage){
        cout<<"Damage : "<<Total_dmg<<endl;
    }

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }

    Cal_DamageNote(act,target,target,Total_dmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,Total_dmg);
}
void Cal_Superbreak_damage(shared_ptr<AllyAttackAction> &act,Enemy *target,double Superbreak_ratio){
    double Total_dmg = Level_multiplier*Superbreak_ratio/100;

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;191m";
        cout<<"\n----------------------- Super Break -----------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getSubUnit()->getCharName()<<" "<<act->actionName<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    Total_dmg = Total_dmg*calBreakEffectMultiplier(act,target);
    Total_dmg = Total_dmg*Cal_Superbreak_DamageIncrease_multiplier(act,target);
    Total_dmg = Total_dmg*calDefShredMultiplier(act,target);
    Total_dmg = Total_dmg*calRespenMultiplier(act,target);
    Total_dmg = Total_dmg*calVulMultiplier(act,target);
    Total_dmg = Total_dmg*calMitigationMultiplier(act,target);

    if(act->Attacker->ptrToChar->checkDamage){
        cout<<"Damage : "<<Total_dmg<<endl;
    }

    if(act->Attacker->ptrToChar->checkDamageFormula||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;191m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }

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


