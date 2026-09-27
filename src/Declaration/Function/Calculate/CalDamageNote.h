
#include "../include.h"

bool changeMaxDamage(CharUnit *ptr);
void calAverageDamage(CharUnit *ptr, std::vector<Enemy*> enemyList);
double calAvgToughnessMultiplier(Enemy *target, double totalAtv);
void calDamageNote(std::shared_ptr<AllyAttackAction> &act, Enemy *src, Enemy *recv, double damage, double ratio, std::string name);
void calDamageSummary();
