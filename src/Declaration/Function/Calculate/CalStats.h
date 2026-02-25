#include "../include.h"

double calculateAtkOnStats(AllyUnit *ptr);
double calculateHpOnStats(AllyUnit *ptr);
double calculateDefOnStats(AllyUnit *ptr);
double calculateSpeedOnStats(AllyUnit *ptr);
double calculateCritrateOnStats(AllyUnit *ptr);
double calculateCritdamOnStats(AllyUnit *ptr);
double calculateBreakEffectOnStats(AllyUnit *ptr);
double calculateElationOnStats(AllyUnit *ptr);
double calculateEhrOnStats(AllyUnit *ptr);
double calculateHPLost(AllyUnit *ptr);

double calculateAtkForBuff(AllyUnit *ptr, double ratio);
double calculateHpForBuff(AllyUnit *ptr, double ratio);
double calculateDefForBuff(AllyUnit *ptr, double ratio);
double calculateSpeedForBuff(AllyUnit *ptr, double ratio);
double calculateCritrateForBuff(AllyUnit *ptr, double ratio);
double calculateCritdamForBuff(AllyUnit *ptr, double ratio);
double calculateBreakEffectForBuff(AllyUnit *ptr, double ratio);
double calculateEhrForBuff(AllyUnit *ptr,double ratio);
double calculateElationForBuff(AllyUnit *ptr,double ratio);

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
double calElationMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calMerryMakeMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calPunchLineMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double calToughnessMultiplier(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
double Cal_Superbreak_DamageIncrease_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target);
double calMitigationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target);
double calMultiplierIncrease(shared_ptr<AllyAttackAction> &act,Enemy *target);