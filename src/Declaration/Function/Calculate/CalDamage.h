#include "../include.h"


void calDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, DmgSrc abilityRatio);
void Cal_Break_damage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double &Constant);
void Cal_Freeze_damage(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
void Cal_Dot_Toughness_break_damage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double Dot_ratio);
void Cal_Superbreak_damage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double Superbreak_ratio);
void Cal_Toughness_reduction(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double Toughness_reduce);
double Cal_Total_Toughness_Reduce(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double Base_Toughness_reduce);
