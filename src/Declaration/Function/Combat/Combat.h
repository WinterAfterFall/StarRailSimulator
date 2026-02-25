#include "../include.h"

void Take_action();
void AhaInstant();
void Deal_damage();
void Attack(shared_ptr<AllyAttackAction> &act);
void genSkillPoint(AllyUnit *ptr,int p);
void genPunchLine(AllyUnit *ptr,int p);
void Superbreak_trigger(shared_ptr<AllyAttackAction> &act, double Superbreak_ratio,string triggerName);
void Dot_trigger(double Dot_ratio,Enemy *target,DotType Dot_type);
void Toughness_break(shared_ptr<AllyAttackAction> &act,Enemy* target);