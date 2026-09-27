#include "../include.h"

double calculateDmgReceive(Enemy *attacker, AllyUnit *ptr, double ratio) {
    double Damage = ratio / 100;
    Damage *= calEnemyATK(attacker);
    Damage *= calEnemyDMG(attacker);
    Damage *= calAllyDefMultiplier(ptr);
    return (Damage < 0) ? 0 : Damage;
}

double calEnemyATK(Enemy *enemy) {
    double atk = enemy->atk;
    atk += (atk * enemy->atkPercent / 100.0);
    return (atk < 0) ? 0 : atk;
}

double calEnemyDMG(Enemy *enemy) {
    double dmg = 100 + enemy->dmgPercent;
    dmg = dmg / 100.0;
    return (dmg < 0) ? 0 : dmg;
}

double calAllyDefMultiplier(AllyUnit *ptr) {
    double def = (ptr->totalDEF > 0) ? ptr->totalDEF : 0;
    def = (1.0 - (def) / (def + 1000));
    return (def < 0) ? 0 : def;
}

