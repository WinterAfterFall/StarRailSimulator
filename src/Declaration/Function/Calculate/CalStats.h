#include "../include.h"

double calculateAtkOnStats(SubUnit *ptr);
double calculateHpOnStats(SubUnit *ptr);
double calculateDefOnStats(SubUnit *ptr);
double calculateSpeedOnStats(SubUnit *ptr);
double calculateCritrateOnStats(SubUnit *ptr);
double calculateCritdamOnStats(SubUnit *ptr);
double calculateBreakEffectOnStats(SubUnit *ptr);
double calculateHPLost(SubUnit *ptr);

double calculateAtkForBuff(SubUnit *ptr, double ratio);
double calculateHpForBuff(SubUnit *ptr, double ratio);
double calculateDefForBuff(SubUnit *ptr, double ratio);
double calculateSpeedForBuff(SubUnit *ptr, double ratio);
double calculateCritrateForBuff(SubUnit *ptr, double ratio);
double calculateCritdamForBuff(SubUnit *ptr, double ratio);
double calculateBreakEffectForBuff(SubUnit *ptr, double ratio);

double calAtkMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calHpMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calDefMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calBonusDmgMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calCritMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double Cal_Crit_rate_multiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double Cal_Crit_dam_multiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calDefShredMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calRespenMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calVulMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calBreakEffectMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calToughnessMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double Cal_Superbreak_DamageIncrease_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target);
double calMitigationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target);