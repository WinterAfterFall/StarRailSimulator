#ifndef Cal_Heal_H
#define Cal_Heal_H
#include "../Class/ClassLibrary.h"

double calculateHeal(HealSrc healRatio, SubUnit *Healer, SubUnit *target) {
    double TotalHeal = 0;

    TotalHeal += Healer->totalATK * healRatio.ATK / 100; 
    TotalHeal += Healer->totalHP * healRatio.HP / 100; 
    TotalHeal += Healer->totalDEF * healRatio.DEF / 100; 
    TotalHeal += calculateHealFromLostHP(target, healRatio.healFromLostHP);
    TotalHeal += calculateHealFromTotalHP(target, healRatio.healFromTotalHP);
    TotalHeal += healRatio.constHeal;
    TotalHeal *= Cal_HealBonus_multiplier(Healer, target);

    if(Healer->ptrToChar->checkHeal){
        // cout<<"RestoreHP : "<<healCount<<endl;
        // cout<<Healer->getCharName()<<" heal ";
        // cout<<target->getCharName()<<" ";
        cout<<TotalHeal<<endl;
    }
    if(Healer->ptrToChar->checkHealFormula){
        cout<<"---"<<endl;
        cout<<"RestoreHP : "<<healCount<<endl;
        cout<<Healer->getCharName()<<" heal ";
        cout<<target->getCharName()<<endl;
        cout<<"Atk : "<<Healer->totalATK<<" ATK Mtpr : "<<healRatio.ATK<<" Total : "<<Healer->totalATK * healRatio.ATK / 100<<endl;
        cout<<"HP : "<<Healer->totalHP<<" HP Mtpr : "<<healRatio.HP<<" Total : "<<Healer->totalHP * healRatio.HP / 100<<endl;
        cout<<"DEF : "<<Healer->totalDEF<<" DEF Mtpr : "<<healRatio.DEF<<" Total : "<<Healer->totalDEF * healRatio.DEF / 100<<endl;
        cout<<"Percent From Lost HP: "<<healRatio.healFromLostHP<<" Total : "<<calculateHealFromLostHP(target, healRatio.healFromTotalHP)<<endl;
        cout<<"Percent From Total HP: "<<healRatio.healFromTotalHP<<" Total : "<<calculateHealFromTotalHP(target, healRatio.healFromTotalHP)<<endl;
        cout<<"Fix Heal : "<<healRatio.constHeal<<endl;
        cout<<"RestoreHP Bonus : "<<Cal_HealBonus_multiplier(Healer, target)<<endl;
        cout<<"---"<<endl;

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

#endif