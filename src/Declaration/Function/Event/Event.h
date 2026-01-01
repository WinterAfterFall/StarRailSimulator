#include "../include.h"

void allEventBeforeTurn();
void allEventAfterTurn();
void allEventBeforeAction(shared_ptr<ActionData> &act);
void allEventWhenAllyAction(shared_ptr<AllyActionData> &act);
void allEventAfterAction(shared_ptr<ActionData> &act);
void allEventBuff(shared_ptr<AllyBuffAction> &act);
void allEventBeforeAttackAction(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttackAction(shared_ptr<AllyAttackAction> &act);
void allEventBeforeAttack(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttack(shared_ptr<AllyAttackAction> &act);
void allEventBeforeAttackPerHit(shared_ptr<AllyAttackAction> &act);
void allEventAfterAttackPerHit(shared_ptr<AllyAttackAction> &act);
void allEventWhenAttack(shared_ptr<AllyAttackAction> &act);
void allEventHeal(AllyUnit *Healer, AllyUnit *target, double Value);
void allEventChangeHP(Unit *Trigger, AllyUnit *target, double Value);
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &act, Enemy *target);
void allEventWhenEnemyHit(Enemy *Attacker, vector<AllyUnit *> vec);
void allEventWhenEnergyIncrease(CharUnit *target, double Energy);
void allEventSkillPoint(AllyUnit *ptr, int p);
void allEventAdjustStats(AllyUnit *ptr, Stats statsType);
void allEventBeforeApplyDebuff(AllyUnit *ptr, Enemy *target);
void allEventAfterApplyDebuff(AllyUnit *ptr, Enemy *target);
void allEventWhenEnemyDeath(AllyUnit *Killer, Enemy *target);
void allEventWhenAllyDeath(AllyUnit *Target);
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &act, Enemy *src, double damage);

