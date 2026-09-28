#include "../include.h"

double calculateDmgReceive(Enemy *attacker, AllyUnit *ptr, double ratio);

double calEnemyATK(Enemy *enemy);
double calDmgReduceMultiplier(Enemy *enemy,AllyUnit *ptr);
double calAllyDefMultiplier(AllyUnit *ptr);