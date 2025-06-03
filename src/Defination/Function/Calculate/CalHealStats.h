#include "../include.h"

double calAtkMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseAtk;
    ans *= (100 + Healer->Stats_type["Atk%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Atk"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}

double calHpMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseHp;
    ans *= (100 + Healer->Stats_type["Hp%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Hp"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseDef;
    ans *= (100 + Healer->Stats_type["Def%"][AT_NONE]) / 100.0;
    ans += Healer->Stats_type["Flat_Def"][AT_NONE];
    return (ans < 0) ? 0 : ans;
}
double calHealBonusMultiplier(SubUnit* Healer, SubUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[ST_HEALING_OUT][AT_NONE];
    mtpr += target->Stats_type[ST_HEALING_IN][AT_NONE];
    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}