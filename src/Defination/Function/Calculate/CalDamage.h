#include "../include.h"

void calDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,DmgSrc abilityRatio){
    double totalDmg = abilityRatio.constDmg;
    
    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;85m";
        cout<<endl;
        cout<<"From : "<<act->getAttacker()->getName()<<" --> "<<act->actionName<<" --> "<<target->getName()<<endl;
        cout << "\033[0m";
    }

    if(act->getChar()->canCheckDmgformulaMtpr()){
        cout<<"Atk Ratio : "<<abilityRatio.atk<<" Hp Ratio : "<<abilityRatio.hp<<" Def Ratio : "<<abilityRatio.def<<" Fix Dmg : "<<abilityRatio.constDmg<<endl;
    }
         
    totalDmg += calHpMultiplier(act,target)*abilityRatio.hp/100;
    totalDmg += calAtkMultiplier(act,target)*abilityRatio.atk/100;
    totalDmg += calDefMultiplier(act,target)*abilityRatio.def/100;
    totalDmg = totalDmg*calCritMultiplier(act,target);
    totalDmg = totalDmg*calBonusDmgMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calToughnessMultiplier(act,target);

    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

}

void calElationDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,DmgSrc abilityRatio){
    if(abilityRatio.elation <= 0 )return;
    double totalDmg = levelMultiplier*2*abilityRatio.elation/100;

    if(act->getChar()->canCheckDmgformulaMtpr()){
        cout<<"Elation Part : "<<endl;
        cout<<"Elation Ratio : "<<abilityRatio.elation<<endl;
    }
         
    totalDmg = totalDmg*calElationMultiplier(act,target);
    totalDmg = totalDmg*calPunchLineMultiplier(act,target);
    totalDmg = totalDmg*calMerryMakeMultiplier(act,target);
    totalDmg = totalDmg*calCritMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calToughnessMultiplier(act,target);

    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

}



void calBreakDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,double &constant){
    double totalDmg = constant *levelMultiplier;
    allEventBeforeAttack(act);
    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Break Dmg --------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getAttacker()->getName()<<" --> "<<act->actionName<<" --> "<<target->getName()<<endl;
        cout << "\033[0m";
    }

    totalDmg = totalDmg*(0.5+target->maxToughness/40);    
    totalDmg = totalDmg*calBreakEffectMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calToughnessMultiplier(act,target);
    
    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }
    allEventAfterAttack(act);

    
}
void calFreezeDamage(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double totalDmg = levelMultiplier;
        allEventBeforeAttack(act);
    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Break Dmg --------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getAttacker()->getName()<<" --> "<<act->actionName<<" --> "<<target->getName()<<endl;
        cout << "\033[0m";
    }

    totalDmg = totalDmg*calBreakEffectMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calToughnessMultiplier(act,target);

    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }
    allEventAfterAttack(act);
}

void calDotToughnessBreakDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,double dotRatio){
    double totalDmg = levelMultiplier*dotRatio/100;
    allEventBeforeAttack(act);
    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"\n-------------------- Dot Break Dmg --------------------\n";    
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getAttacker()->getName()<<" --> "<<act->actionName<<" --> "<<target->getName()<<endl;
        cout << "\033[0m";
    }

    totalDmg = totalDmg*calBreakEffectMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calToughnessMultiplier(act,target);

    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;45m";
        cout<<"---------------------------------------------------\n";
        cout << "\033[0m";
    }
    allEventAfterAttack(act);

}
void calSuperbreakDamage(shared_ptr<AllyAttackAction> &act,Enemy *target,double superbreakRatio){
    double totalDmg = levelMultiplier*superbreakRatio/100;
    allEventBeforeAttack(act);
    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;191m";
        cout<<"\n----------------------- Super Break -----------------------\n";
        cout<<"\033[0;38;5;85m";
        cout<<"From : "<<act->getAttacker()->getName()<<" --> "<<act->actionName<<" --> "<<target->getName()<<endl;
        cout << "\033[0m";
    }

    totalDmg = totalDmg*calBreakEffectMultiplier(act,target);
    totalDmg = totalDmg*calSuperbreakDamageIncreaseMultiplier(act,target);
    totalDmg = totalDmg*calDefShredMultiplier(act,target);
    totalDmg = totalDmg*calRespenMultiplier(act,target);
    totalDmg = totalDmg*calVulMultiplier(act,target);
    totalDmg = totalDmg*calMultiplierIncrease(act,target);
    totalDmg = totalDmg*calMitigationMultiplier(act,target);

    calDamageNote(act,target,target,totalDmg,100,act->actionName);
    allEventAfterDealingDamage(act,target,totalDmg);

    if(act->getChar()->canCheckDmgformula()||act->getChar()->checkDamage){
        cout<<"\033[0;38;5;191m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }
    allEventAfterAttack(act);

}

void calToughnessReduction(shared_ptr<AllyAttackAction> &act,Enemy* target,double toughnessReduce){
    if(target->weaknessType[act->damageElement]==0&& 0 == act->dontCareWeakness&&target->currentToughness>0)return ;
    if(target->weaknessType[act->damageElement]==0&& 0 != act->dontCareWeakness&&target->currentToughness>0){
        toughnessReduce*=(act->dontCareWeakness/100);
        target->currentToughness-=calTotalToughnessReduce(act,target,toughnessReduce);
        if(target->currentToughness<=0){
            target->currentToughness*=(100/act->dontCareWeakness);
        }
    }else{
        target->currentToughness-=calTotalToughnessReduce(act,target,toughnessReduce);
    }
    
    if(target->currentToughness<=0&&target->toughnessStatus==1){
        
        toughnessBreak(act,target);
        target->whenToughnessBroken = currentAtv;
    }
}

double calTotalToughnessReduce(shared_ptr<AllyAttackAction> &act,Enemy *target,double baseToughnessReduce){
    double ans = baseToughnessReduce;
    double toughnessReductionMtpr =100;
    double weaknessBreakEfficiencyBonus = 0;
    toughnessReductionMtpr += act->attacker->statsType[Stats::TOUGH_REDUCE][AType::NONE] + target->statsType[Stats::TOUGH_REDUCE][AType::NONE];
    weaknessBreakEfficiencyBonus += act->attacker->statsType[Stats::BREAK_EFF][AType::NONE] + target->statsType[Stats::BREAK_EFF][AType::NONE];

    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            toughnessReductionMtpr += act->attacker->statsType[Stats::TOUGH_REDUCE][act->actionTypeList[i]] + target->statsType[Stats::TOUGH_REDUCE][act->actionTypeList[i]];

        }
    for(int i=0,sz=act->actionTypeList.size();i<sz;i++){
            weaknessBreakEfficiencyBonus += act->attacker->statsType[Stats::BREAK_EFF][act->actionTypeList[i]] + target->statsType[Stats::BREAK_EFF][act->actionTypeList[i]];

        }

    // wiki: Weakness Break Efficiency โบนัส cap 300% (patch 2.7) — cap ก่อนบวก base 100%
    if(weaknessBreakEfficiencyBonus > 300) weaknessBreakEfficiencyBonus = 300;
    double weaknessBreakEfficiencyMtpr = 100 + weaknessBreakEfficiencyBonus;

    ans *= (toughnessReductionMtpr/100);
    ans *= ((weaknessBreakEfficiencyMtpr)/100);
    return ans;
}


