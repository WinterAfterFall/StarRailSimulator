#include "../include.h"

double calAtkMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseAtk;
    ans *= (100 + Healer->Stats_type["Atk%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Atk"][AT_NONE];

    if(Healer->ptrToChar->checkHealFormula){
        cout<<"Base Atk  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseAtk
        <<" Atk% : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Atk%"][AT_NONE]
        <<" Flat Atk  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Atk"][AT_NONE]
        <<" Total Atk  : "<<setw(7)<<fixed<<setprecision(2)<<ans<<endl;
    }

    return (ans < 0) ? 0 : ans;
}

double calHpMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseHp;
    ans *= (100 + Healer->Stats_type["Hp%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Hp"][AT_NONE];

    if(Healer->ptrToChar->checkHealFormula){
        cout<<"Base Hp   : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseHp
        <<" Hp%  : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Hp%"][AT_NONE]
        <<" Flat Hp   : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Hp"][AT_NONE]
        <<" Total Hp   : "<<setw(7)<<fixed<<setprecision(2)<<ans<<endl;
    }

    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseDef;
    ans *= (100 + Healer->Stats_type["Def%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Def"][AT_NONE];

    if(Healer->ptrToChar->checkHealFormula){
        cout<<"Base Def  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->baseDef
        <<" Def% : "<<setw(6)<<fixed<<setprecision(2)<<Healer->Stats_type["Def%"][AT_NONE]
        <<" Flat Def  : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type["Flat_Def"][AT_NONE]
        <<" Total Def  : "<<setw(7)<<fixed<<setprecision(2)<<ans<<endl;
    }

    return (ans < 0) ? 0 : ans;
}
double calHealBonusMultiplier(SubUnit* Healer, SubUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[ST_HEALING_OUT][AT_NONE];
    mtpr += target->Stats_type[ST_HEALING_IN][AT_NONE];

    if(Healer->ptrToChar->checkHealFormula){
        cout<<"Healer Heal Bonus : "<<setw(7)<<fixed<<setprecision(2)<<Healer->Stats_type[ST_HEALING_OUT][AT_NONE]
        <<" target Heal Bonus : "<<setw(7)<<fixed<<setprecision(2)<<target->Stats_type[ST_HEALING_IN][AT_NONE]
        <<" Total Heal  : "<<setw(7)<<fixed<<setprecision(2)<<mtpr - 100<<endl;
    }

    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}