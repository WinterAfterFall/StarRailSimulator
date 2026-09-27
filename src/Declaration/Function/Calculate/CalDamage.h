#include "../include.h"


void calDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, DmgSrc abilityRatio);
void calElationDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, DmgSrc abilityRatio);
void calBreakDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double &constant);
void calFreezeDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target);
void calDotToughnessBreakDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double dotRatio);
void calSuperbreakDamage(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double superbreakRatio);
void calToughnessReduction(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double toughnessReduce);
double calTotalToughnessReduce(std::shared_ptr<AllyAttackAction> &act, Enemy *target, double baseToughnessReduce);
