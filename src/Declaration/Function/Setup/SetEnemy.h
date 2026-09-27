#include "../include.h"

Enemy* createNewEnemy(double speed,double toughness,EnemyType type);
void setupEnemy(double speed,double toughness,pair<double,double> energy,pair<double,double> skillRatio,pair<int,int> attackCooldown,int action,EnemyType type);
