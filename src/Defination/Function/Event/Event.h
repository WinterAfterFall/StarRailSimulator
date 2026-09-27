#include "../include.h"
void allEventBeforeTurn(){
    phaseStatus = PhaseStatus::BEFORE_TURN;
    if(turn->side==Side::ENEMY){
        shared_ptr<AllyAttackAction> act;
        Enemy *target = turn->canCastToEnemy();
        dotTrigger(100, target, DotType::GENERAL);
        for(auto &each : target->breakEngList){
            act = make_shared<AllyAttackAction>(AType::ENTANGLEMENT, each.ptr, TraceType::SINGLE, "Entanglement");
            double constValue = 0.6 * each.stack;
            calBreakDamage(act, target, constValue);
        }
        if(!turnSkip)
        for(auto itr = target->breakFrzList.begin(); itr != target->breakFrzList.end();){
            act = make_shared<AllyAttackAction>(AType::FREEZE, itr->ptr, TraceType::SINGLE, "Freeze");
            calFreezeDamage(act, target);
            actionForward(target->atvStats.get(), -50);
            --target->totalDebuff;
            turnSkip = 1;
            itr = target->breakFrzList.erase(itr);
            break;
        }
    }

    for(TriggerByYourSelfFunc &e : beforeTurnList){
        e.call(e.owner);
    }
}
void allEventAfterTurn(){
    if(turn->side==Side::ENEMY){
        shared_ptr<AllyAttackAction> act;
        Enemy *target = turn->canCastToEnemy();
        
        for (auto itr = target->breakDotList.begin(); itr != target->breakDotList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            BreakSEType expiredType = itr->type;
            itr = target->breakDotList.erase(itr);
            --target->totalDebuff;
            --target->dotCount;
            if(expiredType == BreakSEType::BURN){
                --target->burnCount;
            } else if(expiredType == BreakSEType::SHOCK){
                --target->shockCount;
            } else if(expiredType == BreakSEType::WIND_SHEAR){
                --target->windSheerCount;
            } else if(expiredType == BreakSEType::BLEED){
                --target->bleedCount;
            }
            
        }
        for (auto itr = target->breakEngList.begin(); itr != target->breakEngList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            itr = target->breakEngList.erase(itr);
            --target->totalDebuff;
            
        }
        for (auto itr = target->breakImsList.begin(); itr != target->breakImsList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            itr = target->breakImsList.erase(itr);
            debuffSingle(target,{{Stats::SPD_P,AType::NONE,10}});
            --target->totalDebuff;
            
        }
        for(auto &e : target->weaknessTypeCountdown){
            if(e.second==turn->turnCnt&&target->defaultWeaknessType[e.first]==0){
                target->weaknessType[e.first] = 0;
                target->currentWeaknessElementAmount--;
            }
        }
    }
    for(TriggerByYourSelfFunc &e : afterTurnList){
        e.call(e.owner);
    }

    if (turn->side == Side::ALLY) {
        AllyUnit *ally = turn->canCastToAllyUnit();

        for (auto &each : cbCheck) {
            if (isBuffEnd(ally, std::get<0>(each))) {
                std::get<1>(each)--;
                buffSingle(ally, {{Stats::CERTIFIED_BANGER, AType::NONE, -1.0 * std::get<2>(each)}});
            }
        }

        while (!cbCheck.empty() && std::get<1>(cbCheck.front()) <= 0) {
            cbCheck.pop_front();
        }
    }

    
}
void allEventBeforeAction(shared_ptr<ActionData> &act){
    for(TriggerByActionFunc &e : beforeActionList){
        e.call(act);
    }
}
void allEventBeforeAllyAction(shared_ptr<AllyActionData> &act){
    for(TriggerByAllyActionFunc &e : beforeAllyActionList){
        e.call(act);
    }
}
void allEventAfterAllyAction(shared_ptr<AllyActionData> &act){
    for(TriggerByAllyActionFunc &e : afterAllyActionList){
        e.call(act);
    }
}
void allEventAfterAction(shared_ptr<ActionData> &act){
    for(TriggerByActionFunc &e : afterActionList){
        e.call(act);
    }
}
void allEventBuff(shared_ptr<AllyBuffAction> &act){
    for(TriggerByAllyBuffActionFunc &e : buffList){
        e.call(act);
    }
}
void allEventBeforeAttackAction(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : beforeAttackActionList){
        e.call(act);
    }
}
void allEventAfterAttackAction(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : afterAttackActionList){
        e.call(act);
    }
}
void allEventBeforeAttack(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : beforeAttackList){
        e.call(act);
    }
}
void allEventAfterAttack(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : afterAttackList){
        e.call(act);
    }
}
void allEventBeforeAttackPerHit(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : beforeAttackPerHitList){
        e.call(act);
    }
}
void allEventAfterAttackPerHit(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackActionFunc &e : afterAttackPerHitList){
        e.call(act);
    }
}
void allEventWhenAttack(shared_ptr<AllyAttackAction> &act){
    for(Enemy* &e : act->targetList){
        for (auto &each : e->breakEngList) {
            if(each.stack>=5)continue;
            each.stack++;
        }
    }
    
    for(TriggerByAllyAttackActionFunc &e : whenAttackList){
        e.call(act);
    }
}
void allEventHeal(AllyUnit *healer,AllyUnit *target,double value){
    for(TriggerHealing &e : healingList){
        e.call(healer,target,value);
    }
}
void allEventChangeHP(Unit *trigger,AllyUnit *target,double value){
    for(TriggerDecreaseHP &e : hpDecreaseList){
        e.call(trigger,target,value);
    }
}
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &act,Enemy *target){
    for(TriggerBySomeAllyFunc &e : toughnessBreakList){
        e.call(target,act->attacker);
    }
}
void allEventWhenEnemyHit(Enemy* attacker,vector<AllyUnit*> vec){
    
    for(TriggerByEnemyHit &e : enemyHitList){
        e.call(attacker,vec);
    }
    
    
}
void allEventWhenEnergyIncrease(CharUnit *target,double energy){
    for(TriggerEnergyIncreaseFunc &e : whenEnergyIncreaseList){
        e.call(target,energy);
    }
}
void allEventSkillPoint(AllyUnit *ptr,int p){
    for(TriggerSkillPointFunc &e : skillPointList){
        e.call(ptr,p);
    }
    return;
}
void allEventPunchLine(AllyUnit *ptr,int p){
    for(TriggerSkillPointFunc &e : punchLineList){
        e.call(ptr,p);
    }
    return;
}
void allEventAdjustStats(AllyUnit *ptr,Stats statsType){
    adjustCheck = 1;
    for(TriggerByStats &e : statsAdjustList){
        e.call(ptr,statsType);
    }
    adjustCheck = 0;
}
void allEventBeforeApplyDebuff(AllyUnit *ptr,Enemy* target){
    for(TriggerBySomeAllyFunc &e : beforeApplyDebuff){
        e.call(target,ptr);
    }
}
void allEventAfterApplyDebuff(AllyUnit *ptr,Enemy* target){
    for(TriggerBySomeAllyFunc &e : afterApplyDebuff){
        e.call(target,ptr);
    }
}
void allEventApplyWeakness(AllyUnit *trigger,Enemy *target,vector<ElementType> weaknessList){
    for(TriggerByWeaknessApplyFunc &e : weaknessApplyList){
        e.call(trigger,target,weaknessList);
    }
}
void allEventWhenEnemyDeath(AllyUnit *killer,Enemy *target){
    for(TriggerBySomeAllyFunc &e : enemyDeathList){
        e.call(target,killer);
    }
}
void allEventWhenAllyDeath(AllyUnit *target){
    for(TriggerAllyDeath &e : allyDeathList){
        e.call(target);
    }
}
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &act, Enemy *target, double damage) {
    for (TriggerAfterDealDamage &e : afterDealingDamageList) {
        e.call(act, target, damage);
    }
}
void beforeAhaInstant(){
    for(TriggerByYourSelfFunc &e : beforeAhaInstantList){
        e.call(e.owner);
    }
}
void afterAhaInstant(){
    for(TriggerByYourSelfFunc &e : afterAhaInstantList){
        e.call(e.owner);
    }
}
