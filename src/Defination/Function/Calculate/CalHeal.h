#include "../include.h"

double calculateHeal(HealSrc healSrc, SubUnit *Healer, SubUnit *target) {
    double TotalHeal = 0;

    if((Healer->ptrToChar->checkHealFormula&&target->ptrToChar->checkHealReceiveFormula)
        ||(Healer->ptrToChar->checkHeal&&target->ptrToChar->checkHealReceive)){
        cout<<"\033[0;38;5;85m";
        cout<<endl;
        cout<<"From "<<Healer->getCharName()<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }
    if(Healer->ptrToChar->checkHealFormula&&target->ptrToChar->checkHealReceiveFormula){
       
        cout<<"Atk Ratio : "<<healSrc.ATK<<" Hp Ratio : "<<healSrc.HP<<" Def Ratio : "<<healSrc.DEF<<" Fix Dmg : "<<endl;

        cout<<"Base Atk  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseAtk
        <<" Atk% : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Atk%"][AT_NONE]
        <<" Flat Atk  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Atk"][AT_NONE]
        <<" Total Atk  : "<<setw(7)<<fixed<<setprecision(2)<<calAtkMultiplier(Healer,target)<<endl;

        cout<<"Base Hp   : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseHp
        <<" Hp%  : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Hp%"][AT_NONE]
        <<" Flat Hp   : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Hp"][AT_NONE]
        <<" Total Hp   : "<<setw(7)<<fixed<<setprecision(2)<<calHpMultiplier(Healer,target)<<endl;
    
        cout<<"Base Def  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseDef
        <<" Def% : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Def%"][AT_NONE]
        <<" Flat Def  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Def"][AT_NONE]
        <<" Total Def  : "<<setw(7)<<fixed<<setprecision(2)<<calDefMultiplier(Healer,target)<<endl;

        cout<<"Lost Hp   : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromLostHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromLostHP / 100.0) * (target->totalHP - target->currentHP)<<endl;;
        
        cout<<"Total Hp  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromLostHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromTotalHP / 100.0) * (target->totalHP)<<endl;

        cout<<"Fix Heal  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.constHeal<<endl;

        cout<<"Healer Heal Bonus : "<<Healer->Stats_type[ST_HEALING_OUT][AT_NONE]
        <<" target Heal Bonus : "<<target->Stats_type[ST_HEALING_IN][AT_NONE]
        <<" Total Heal  : "<<Healer->Stats_type[ST_HEALING_OUT][AT_NONE] + target->Stats_type[ST_HEALING_IN][AT_NONE]<<endl;
    }
    
    TotalHeal += calAtkMultiplier(Healer,target) * healSrc.ATK / 100; 
    TotalHeal += calHpMultiplier(Healer,target) * healSrc.HP / 100; 
    TotalHeal += calDefMultiplier(Healer,target) * healSrc.DEF / 100; 
    TotalHeal += calculateHealFromLostHP(target, healSrc.healFromLostHP);
    TotalHeal += calculateHealFromTotalHP(target, healSrc.healFromTotalHP);
    TotalHeal += healSrc.constHeal;
    TotalHeal *= calHealBonusMultiplier(Healer, target);
    


    if(Healer->ptrToChar->checkHeal&&target->ptrToChar->checkHealReceive){
        cout<<"Total Heal : "<<setw(6)<<TotalHeal<<endl;
    }

    return TotalHeal < 0 ? 0 : TotalHeal;
}

double calculateHealFromLostHP(SubUnit *target, double percent) {
    double TotalHeal;
    TotalHeal = (percent / 100.0) * (target->totalHP - target->currentHP);
    
    return (TotalHeal < 0) ? 0 : TotalHeal;
}

double calculateHealFromTotalHP(SubUnit *target, double percent) {
    double TotalHeal = 0;
    TotalHeal = (percent / 100.0) * (target->totalHP);
    
    return (TotalHeal < 0) ? 0 : TotalHeal;
}

