#include "../include.h"
void allEventBeforeTurn(){
    if(turn->side==Side::Enemy){
        shared_ptr<AllyAttackAction> act;
        Enemy *target = turn->canCastToEnemy();
        Dot_trigger(100, target, DotType::General);
        for(auto &each : target->breakEngList){
            act = make_shared<AllyAttackAction>(AType::Entanglement, each.ptr, TraceType::Single, "Entanglement");
            double Const = 0.6 * each.stack;
            Cal_Break_damage(act, target, Const);
        }
        if(!Turn_Skip)
        for(auto itr = target->breakFrzList.begin(); itr != target->breakFrzList.end();){
            act = make_shared<AllyAttackAction>(AType::Freeze, itr->ptr, TraceType::Single, "Freeze");
            Cal_Freeze_damage(act, target);
            Action_forward(target->Atv_stats.get(), -50);
            --target->Total_debuff;
            Turn_Skip = 1;
            itr = target->breakFrzList.erase(itr);
            break;
        }
    }

    for(TriggerByYourSelf_Func &e : Before_turn_List){
        e.Call();
    }
}
void allEventAfterTurn(){
    if(turn->side==Side::Enemy){
        shared_ptr<AllyAttackAction> act;
        Enemy *target = turn->canCastToEnemy();
        
        for (auto itr = target->breakDotList.begin(); itr != target->breakDotList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            itr = target->breakDotList.erase(itr);
            --target->Total_debuff;
            --target->DotCount;
            if(itr->type == BreakSEType::Burn){
                --target->BurnCount;
            } else if(itr->type == BreakSEType::Shock){
                --target->ShockCount;
            } else if(itr->type == BreakSEType::WindShear){
                --target->WindSheerCount;
            } else if(itr->type == BreakSEType::Bleed){
                --target->BleedCount;
            }
            
        }
        for (auto itr = target->breakEngList.begin(); itr != target->breakEngList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            itr = target->breakEngList.erase(itr);
            --target->Total_debuff;
            
        }
        for (auto itr = target->breakImsList.begin(); itr != target->breakImsList.end(); ) {
            if(itr->countdown!=turn->turnCnt){
                itr++;
                continue;
            }
            itr = target->breakImsList.erase(itr);
            target->debuffSingle({{Stats::SPD_P,AType::None,10}});
            --target->Total_debuff;
            
        }
        for(auto &e : target->Weakness_typeCountdown){
            if(e.second==turn->turnCnt&&target->Default_Weakness_type[e.first]==0){
                target->Weakness_type[e.first] = 0;
                target->currentWeaknessElementAmount--;
            }
        }
    }
    
    for(TriggerByYourSelf_Func &e : After_turn_List){
        e.Call();
    }
}
void allEventBeforeAction(shared_ptr<ActionData> &act){
    for(TriggerByAction_Func &e : BeforeAction_List){
        e.Call(act);
    }
}
void allEventWhenAllyAction(shared_ptr<AllyActionData> &act){
    for(TriggerByAllyAction_Func &e : AllyActionList){
        e.Call(act);
    }
}
void allEventAfterAction(shared_ptr<ActionData> &act){
    for(TriggerByAction_Func &e : AfterAction_List){
        e.Call(act);
    }
}
void allEventBuff(shared_ptr<AllyBuffAction> &act){
    for(TriggerByAllyBuffAction_Func &e : Buff_List){
        e.Call(act);
    }
}
void allEventBeforeAttackAction(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : BeforeAttackAction_List){
        e.Call(act);
    }
}
void allEventAfterAttackAction(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : AfterAttackActionList){
        e.Call(act);
    }
}
void allEventBeforeAttack(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : BeforeAttack_List){
        e.Call(act);
    }
}
void allEventAfterAttack(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : AfterAttack_List){
        e.Call(act);
    }
}
void allEventBeforeAttackPerHit(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : BeforeAttackPerHit_List){
        e.Call(act);
    }
}
void allEventAfterAttackPerHit(shared_ptr<AllyAttackAction> &act){
    for(TriggerByAllyAttackAction_Func &e : AfterAttackPerHit_List){
        e.Call(act);
    }
}
void allEventWhenAttack(shared_ptr<AllyAttackAction> &act){
    for(Enemy* &e : act->targetList){
        for (auto &each : e->breakEngList) {
            if(each.stack>=5)continue;
            each.stack++;
        }
    }
    
    for(TriggerByAllyAttackAction_Func &e : When_attack_List){
        e.Call(act);
    }
}
void allEventHeal(SubUnit *Healer,SubUnit *target,double Value){
    for(TriggerHealing &e : Healing_List){
        e.Call(Healer,target,Value);
    }
}
void allEventChangeHP(Unit *Trigger,SubUnit *target,double Value){
    for(TriggerDecreaseHP &e : HPDecrease_List){
        e.Call(Trigger,target,Value);
    }
}
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &act,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Toughness_break_List){
        e.Call(target,act->Attacker);
    }
}
void allEventWhenEnemyHit(Enemy* Attacker,vector<SubUnit*> vec){
    
    for(TriggerByEnemyHit &e : Enemy_hit_List){
        e.Call(Attacker,vec);
    }
    
    
}
void allEventWhenEnergyIncrease(Ally *target,double Energy){
    for(TriggerEnergy_Increase_Func &e : When_Energy_Increase_List){
        e.Call(target,Energy);
    }
}
void allEventSkillPoint(SubUnit *ptr,int p){
    for(TriggerSkill_point_func &e : Skill_point_List){
        e.Call(ptr,p);
    }
    return ;
}
void allEventAdjustStats(SubUnit *ptr,Stats statsType){
    AdjustCheck = 1;
    for(TriggerByStats &e : Stats_Adjust_List){
        e.Call(ptr,statsType);
    }
    AdjustCheck = 0;
}
void allEventBeforeApplyDebuff(SubUnit *ptr,Enemy* target){
    for(TriggerBySomeAlly_Func &e : BeforeApplyDebuff){
        e.Call(target,ptr);
    }
}
void allEventAfterApplyDebuff(SubUnit *ptr,Enemy* target){
    for(TriggerBySomeAlly_Func &e : BeforeApplyDebuff){
        e.Call(target,ptr);
    }
}
void allEventWhenEnemyDeath(SubUnit *Killer,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Enemy_Death_List){
        e.Call(target,Killer);
    }
}
void allEventWhenAllyDeath(SubUnit *Target){
    for(TriggerAllyDeath &e : AllyDeath_List){
        e.Call(Target);
    }
}
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &act, Enemy *src, double damage) {
    for (TriggerAfterDealDamage &e : AfterDealingDamage_List) {
        e.Call(act, src, damage);
    }
}
