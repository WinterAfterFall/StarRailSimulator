#include "../include.h"

double calAtkMultiplier(AllyUnit* healer) {
    double ans = healer->baseAtk;
    ans *= (100 + healer->statsType[Stats::ATK_P][AType::NONE]) / 100.0;
    ans += healer->statsType[Stats::FLAT_ATK][AType::NONE];

    return (ans < 0) ? 0 : ans;
}

double calHpMultiplier(AllyUnit* healer) {
    double ans = healer->baseHp;
    ans *= (100 + healer->statsType[Stats::HP_P][AType::NONE]) / 100.0;
    ans += healer->statsType[Stats::FLAT_HP][AType::NONE];

    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(AllyUnit* healer) {
    double ans = healer->baseDef;
    ans *= (100 + healer->statsType[Stats::DEF_P][AType::NONE]) / 100.0;
    ans += healer->statsType[Stats::FLAT_DEF][AType::NONE];

    return (ans < 0) ? 0 : ans;
}
double calHealBonusMultiplier(AllyUnit* healer, AllyUnit* target) {
    double mtpr = 100;
    mtpr += healer->statsType[Stats::HEALING_OUT][AType::NONE];
    mtpr += target->statsType[Stats::HEALING_IN][AType::NONE];

    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}
