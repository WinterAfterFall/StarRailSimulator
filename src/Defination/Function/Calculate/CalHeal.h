#include "../include.h"

double calculateHeal(HealSrc healSrc, AllyUnit *healer, AllyUnit *target) {
    double totalHeal = 0;
    
    if((healer->owner->checkHealFormula&&target->owner->checkHealReceiveFormula)
        ||(healer->owner->checkHeal&&target->owner->checkHealReceive)){
        cout<<"\033[0;38;5;85m";
        cout<<endl;
        cout<<"From "<<healer->getName()<<" to "<<target->getName()<<endl;
        cout << "\033[0m";
    }
    if(healer->owner->checkHealFormula&&target->owner->checkHealReceiveFormula){
       
        cout<<"Atk Ratio : "<<healSrc.atk<<" Hp Ratio : "<<healSrc.hp<<" Def Ratio : "<<healSrc.def<<" Fix Dmg : "<<endl;

        cout<<"Base Atk  : "<<setw(7)<<fixed<<setprecision(2)<<healer->baseAtk
        <<" Atk% : "<<setw(6)<<fixed<<setprecision(2)<<healer->statsType[Stats::ATK_P][AType::NONE]
        <<" Flat Atk  : "<<setw(7)<<fixed<<setprecision(2)<<healer->statsType[Stats::FLAT_ATK][AType::NONE]
        <<" Total Atk  : "<<setw(7)<<fixed<<setprecision(2)<<calAtkMultiplier(healer)<<endl;

        cout<<"Base Hp   : "<<setw(7)<<fixed<<setprecision(2)<<healer->baseHp
        <<" Hp%  : "<<setw(6)<<fixed<<setprecision(2)<<healer->statsType[Stats::HP_P][AType::NONE]
        <<" Flat Hp   : "<<setw(7)<<fixed<<setprecision(2)<<healer->statsType[Stats::FLAT_HP][AType::NONE]
        <<" Total Hp   : "<<setw(7)<<fixed<<setprecision(2)<<calHpMultiplier(healer)<<endl;
    
        cout<<"Base Def  : "<<setw(7)<<fixed<<setprecision(2)<<healer->baseDef
        <<" Def% : "<<setw(6)<<fixed<<setprecision(2)<<healer->statsType[Stats::DEF_P][AType::NONE]
        <<" Flat Def  : "<<setw(7)<<fixed<<setprecision(2)<<healer->statsType[Stats::FLAT_DEF][AType::NONE]
        <<" Total Def  : "<<setw(7)<<fixed<<setprecision(2)<<calDefMultiplier(healer)<<endl;

        cout<<"Lost Hp   : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromLostHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromLostHP / 100.0) * (target->totalHP - target->currentHP)<<endl;;
        
        cout<<"Total Hp  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.healFromTotalHP
        <<" Final Heal : "<<setw(7)<<fixed<<setprecision(2)<<(healSrc.healFromTotalHP / 100.0) * (target->totalHP)<<endl;

        cout<<"Fix Heal  : "<<setw(7)<<fixed<<setprecision(2)<<healSrc.constHeal<<endl;

        cout<<"Healer Heal Bonus : "<<healer->statsType[Stats::HEALING_OUT][AType::NONE]
        <<" target Heal Bonus : "<<target->statsType[Stats::HEALING_IN][AType::NONE]
        <<" Total Heal  : "<<healer->statsType[Stats::HEALING_OUT][AType::NONE] + target->statsType[Stats::HEALING_IN][AType::NONE]<<endl;
    }
    
    totalHeal += calAtkMultiplier(healer) * healSrc.atk / 100;
    totalHeal += calHpMultiplier(healer) * healSrc.hp / 100;
    totalHeal += calDefMultiplier(healer) * healSrc.def / 100;
    totalHeal += calculateHealFromLostHP(target, healSrc.healFromLostHP);
    totalHeal += calculateHealFromTotalHP(target, healSrc.healFromTotalHP);
    totalHeal += healSrc.constHeal;
    totalHeal *= calHealBonusMultiplier(healer, target);
    


    if(healer->owner->checkHeal&&target->owner->checkHealReceive){
        cout<<"Total Heal : "<<setw(6)<<totalHeal<<endl;
    }

    return totalHeal < 0 ? 0 : totalHeal;
}

double calculateHealFromLostHP(AllyUnit *target, double percent) {
    double totalHeal;
    totalHeal = (percent / 100.0) * (target->totalHP - target->currentHP);
    
    return (totalHeal < 0) ? 0 : totalHeal;
}

double calculateHealFromTotalHP(AllyUnit *target, double percent) {
    double totalHeal = 0;
    totalHeal = (percent / 100.0) * (target->totalHP);
    
    return (totalHeal < 0) ? 0 : totalHeal;
}

