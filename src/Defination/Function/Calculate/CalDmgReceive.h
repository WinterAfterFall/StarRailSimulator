#include "../include.h"

double calculateDmgReceive(Enemy *Attacker, SubUnit *ptr, double ratio) {
    double Damage = ratio / 100;
    Damage *= calEnemyATK(Attacker);
    Damage *= calEnemyDMG(Attacker);
    Damage *= calAllyDefMultiplier(ptr);
    return (Damage < 0) ? 0 : Damage;
}

double calEnemyATK(Enemy *enemy) {
    double Atk = enemy->ATK;
    Atk += (Atk * enemy->atkPercent / 100.0);
    return (Atk < 0) ? 0 : Atk;
}

double calEnemyDMG(Enemy *enemy) {
    double Dmg = 100 + enemy->dmgPercent;
    Dmg = Dmg / 100.0;
    return (Dmg < 0) ? 0 : Dmg;
}

double calAllyDefMultiplier(SubUnit *ptr) {
    double Def = (ptr->totalDEF > 0) ? ptr->totalDEF : 0;
    Def = (1.0 - (Def) / (Def + 1000));
    return (Def < 0) ? 0 : Def;
}

