#include "../include.h"

void allEventBeforeTurn();
void allEventAfterTurn();
void allEventBeforeAction(shared_ptr<ActionData> &act);
void allEventBeforeAllyAction(shared_ptr<AllyActionData> &act);
void allEventAfterAllyAction(shared_ptr<AllyActionData> &act);
void allEventAfterAction(shared_ptr<ActionData> &act);
void allEventBuff(shared_ptr<AllyBuffAction> &act);
void allEventBeforeAttackAction(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttackAction(shared_ptr<AllyAttackAction> &act);
void allEventBeforeAttack(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttack(shared_ptr<AllyAttackAction> &act);
void allEventBeforeAttackPerHit(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttackPerHit(shared_ptr<AllyAttackAction> &act);
void allEventWhenAttack(shared_ptr<AllyAttackAction> &act);
void allEventHeal(AllyUnit *healer, AllyUnit *target, double value);
void allEventChangeHP(Unit *trigger, AllyUnit *target, double value);
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &act, Enemy *target);
void allEventWhenEnemyHit(Enemy *attacker, vector<AllyUnit *> vec);
void allEventWhenEnergyIncrease(CharUnit *target, double energy);
void allEventSkillPoint(AllyUnit *ptr, int p);
void allEventPunchLine(AllyUnit *ptr, int p);
void allEventAdjustStats(AllyUnit *ptr, Stats statsType);
void allEventBeforeApplyDebuff(AllyUnit *ptr, Enemy *target);
void allEventAfterApplyDebuff(AllyUnit *ptr, Enemy *target);
void allEventApplyWeakness(AllyUnit *trigger,Enemy *target,vector<ElementType> weaknessList);
void allEventWhenEnemyDeath(AllyUnit *killer, Enemy *target);
void allEventWhenAllyDeath(AllyUnit *target);
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &act, Enemy *target, double damage);
void allEventWhenUseElationSkill(CharUnit *ptr);

