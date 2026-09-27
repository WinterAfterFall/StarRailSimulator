#include "../include.h"

void takeAction();
void dealDamage();
void attack(shared_ptr<AllyAttackAction> &act);
void genSkillPoint(AllyUnit *ptr,int p);
void genPunchLine(AllyUnit *ptr,int p);
void superbreakTrigger(shared_ptr<AllyAttackAction> &act, double superbreakRatio,string triggerName);
void dotTrigger(double dotRatio,Enemy *target,DotType dotType);
void toughnessBreak(shared_ptr<AllyAttackAction> &act,Enemy* target);