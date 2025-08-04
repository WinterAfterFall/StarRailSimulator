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
void allEventHeal(SubUnit *Healer, SubUnit *target, double Value);
void allEventChangeHP(Unit *Trigger, SubUnit *target, double Value);
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &act, Enemy *target);
void allEventWhenEnemyHit(Enemy *Attacker, vector<SubUnit *> vec);
void allEventWhenEnergyIncrease(Ally *target, double Energy);
void allEventSkillPoint(SubUnit *ptr, int p);
void allEventAdjustStats(SubUnit *ptr, Stats statsType);
void allEventBeforeApplyDebuff(SubUnit *ptr, Enemy *target);
void allEventAfterApplyDebuff(SubUnit *ptr, Enemy *target);
void allEventWhenEnemyDeath(SubUnit *Killer, Enemy *target);
void allEventWhenAllyDeath(SubUnit *Target);
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &act, Enemy *src, double damage);

