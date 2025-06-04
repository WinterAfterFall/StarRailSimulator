#include "../include.h"

void Take_action();
void Deal_damage();
void Attack(shared_ptr<AllyAttackAction> &act);
void Skill_point(SubUnit *ptr,int p);
void Superbreak_trigger(shared_ptr<AllyAttackAction> &act, double Superbreak_ratio,string triggerName);
void Dot_trigger(double Dot_ratio,Enemy *target,DotType Dot_type);
void dotDamage(shared_ptr<AllyAttackAction> &act,double Dot_ratio);
void Toughness_break(shared_ptr<AllyAttackAction> &act,Enemy* target);