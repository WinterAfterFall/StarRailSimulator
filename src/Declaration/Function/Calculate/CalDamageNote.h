
#include "../include.h"

bool changeMaxDamage(Ally *ptr);
void Cal_AverageDamage(Ally *ptr, std::vector<Enemy*> enemyList);
double Cal_AvgToughnessMultiplier(Enemy *target, double Total_atv);
void Cal_DamageNote(std::shared_ptr<AllyAttackAction> &act, Enemy *src, Enemy *recv, double damage, double ratio, std::string name);
void Cal_DamageSummary();
