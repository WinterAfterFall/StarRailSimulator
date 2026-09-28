#include "../include.h"

double calculateDmgReceive(Enemy *attacker, AllyUnit *ptr, double ratio) {
    double Damage = ratio / 100;
    Damage *= calEnemyATK(attacker);
    Damage *= calDmgReduceMultiplier(attacker,ptr);
    Damage *= calAllyDefMultiplier(ptr);
    return (Damage < 0) ? 0 : Damage;
}

double calEnemyATK(Enemy *enemy) {
    double atk = enemy->atk;
    atk -= (atk * enemy->statsType[Stats::ATK_REDUCE][AType::NONE] / 100.0);
    return (atk < 0) ? 0 : atk;
}

// DMG reduction: the enemy's outgoing DMG_REDUCE and the ally's incoming DMG_REDUCE are summed into one multiplier
double calDmgReduceMultiplier(Enemy *enemy,AllyUnit *ptr) {
    double dmg = 100 - enemy->statsType[Stats::DMG_REDUCE][AType::NONE] - ptr->statsType[Stats::DMG_REDUCE][AType::NONE];
    dmg = dmg / 100.0;
    return (dmg < 0) ? 0 : dmg;
}

double calAllyDefMultiplier(AllyUnit *ptr) {
    double def = (ptr->totalDEF > 0) ? ptr->totalDEF : 0;
    def = (1.0 - (def) / (def + 1000));
    return (def < 0) ? 0 : def;
}
