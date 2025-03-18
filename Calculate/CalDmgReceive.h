#ifndef Cal_DMG_RECEIVE_H
#define Cal_DMG_RECEIVE_H
#include "../Print.h"

double calculateDmgReceive(Enemy *Attacker,Sub_Unit *ptr,double ratio){
    double Damage = ratio/100;
    Damage *= calEnemyATK(Attacker);
    Damage *= calAllyDefMultiplier(ptr);
    return Damage;

    
}
double calEnemyATK(Enemy *enemy){
    double Atk = enemy->ATK;
    Atk += (Atk*enemy->atkPercent/100.0);
    return Atk;
}
double calAllyDefMultiplier(Sub_Unit *ptr){
    double Def = ptr->totalDEF;
    Def = (1.0 - (Def)/(Def+1000));
    return Def;
}
#endif