#include "../include.h"

double calAtkMultiplier(AllyUnit* Healer, AllyUnit* target) {
    double ans = Healer->baseAtk;
    ans *= (100 + Healer->Stats_type[Stats::ATK_P][AType::None]) / 100.0;
    ans += Healer->Stats_type[Stats::FLAT_ATK][AType::None];

    return (ans < 0) ? 0 : ans;
}

double calHpMultiplier(AllyUnit* Healer, AllyUnit* target) {
    double ans = Healer->baseHp;
    ans *= (100 + Healer->Stats_type[Stats::HP_P][AType::None]) / 100.0;
    ans += Healer->Stats_type[Stats::FLAT_HP][AType::None];

    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(AllyUnit* Healer, AllyUnit* target) {
    double ans = Healer->baseDef;
    ans *= (100 + Healer->Stats_type[Stats::DEF_P][AType::None]) / 100.0;
    ans += Healer->Stats_type[Stats::FLAT_DEF][AType::None];

    return (ans < 0) ? 0 : ans;
}
double calHealBonusMultiplier(AllyUnit* Healer, AllyUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[Stats::HEALING_OUT][AType::None];
    mtpr += target->Stats_type[Stats::HEALING_IN][AType::None];

    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}