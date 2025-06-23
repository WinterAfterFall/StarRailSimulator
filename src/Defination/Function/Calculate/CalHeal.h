#include "../include.h"

double calculateHeal(HealSrc healSrc, SubUnit *Healer, SubUnit *target) {
    double TotalHeal = 0;

    if(Healer->ptrToChar->checkHealFormula||Healer->ptrToChar->checkHeal){
        cout<<"\033[0;38;5;85m";
        cout<<endl;
        cout<<"From "<<Healer->getCharName()<<" to "<<target->getCharName()<<endl;
        cout << "\033[0m";
    }

    TotalHeal += calAtkMultiplier(Healer,target) * healSrc.ATK / 100; 
    TotalHeal += calHpMultiplier(Healer,target) * healSrc.HP / 100; 
    TotalHeal += calDefMultiplier(Healer,target) * healSrc.DEF / 100; 
    TotalHeal += calculateHealFromLostHP(target, healSrc.healFromLostHP);
    TotalHeal += calculateHealFromTotalHP(target, healSrc.healFromTotalHP);
    TotalHeal += healSrc.constHeal;
    
    if(Healer->ptrToChar->checkHealFormula){
        cout<<"Lost Hp   : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromLostHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromLostHP / 100.0) * (target->totalHP - target->currentHP)<<endl;;
        cout<<"Total Hp  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromLostHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromTotalHP / 100.0) * (target->totalHP)<<endl;;
        cout<<"Fix Heal  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.constHeal<<endl;
    }

    TotalHeal *= calHealBonusMultiplier(Healer, target);

    if(Healer->ptrToChar->checkHeal){
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

