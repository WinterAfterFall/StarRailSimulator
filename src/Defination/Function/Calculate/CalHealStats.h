#include "../include.h"

double calAtkMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseAtk;
    ans *= (100 + Healer->Stats_type["Atk%"][AType::None]) / 100.0;
    ans += Healer->Stats_type["Flat_Atk"][AType::None];

    return (ans < 0) ? 0 : ans;
}

double calHpMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseHp;
    ans *= (100 + Healer->Stats_type["Hp%"][AType::None]) / 100.0;
    ans += Healer->Stats_type["Flat_Hp"][AType::None];

    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(SubUnit* Healer, SubUnit* target) {
    double ans = Healer->baseDef;
    ans *= (100 + Healer->Stats_type["Def%"][AType::None]) / 100.0;
    ans += Healer->Stats_type["Flat_Def"][AType::None];

    return (ans < 0) ? 0 : ans;
}
double calHealBonusMultiplier(SubUnit* Healer, SubUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[ST_HEALING_OUT][AType::None];
    mtpr += target->Stats_type[ST_HEALING_IN][AType::None];

    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}