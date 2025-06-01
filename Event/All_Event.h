#ifndef Event_H
#define Event_H
#include "../Class/ClassLibrary.h"
void allEventBeforeTurn(){
    if(turn->Side=="Enemy"){
        shared_ptr<AllyAttackAction> data_;
        Enemy *target = turn->canCastToEnemy();
        Dot_trigger(100, target, AT_NONE);
        for(auto &each : target->breakEngist){
            data_ = make_shared<AllyAttackAction>(ActionType::Entanglement, each.ptr, TT_SINGLE, "Entanglement");
            double Const = 0.6 * each.stack;
            Cal_Break_damage(data_, target, Const);
        }
        if(!Turn_Skip)
        for(auto itr = target->breakFrzist.begin(); itr != target->breakFrzist.end();){
            data_ = make_shared<AllyAttackAction>(ActionType::Freeze, itr->ptr, TT_SINGLE, "Freeze");
            Cal_Freeze_damage(data_, target);
            Action_forward(target->Atv_stats.get(), -50);
            --target->Total_debuff;
            Turn_Skip = 1;
            itr = target->breakFrzist.erase(itr);
            break;
        }
    }

    for(TriggerByYourSelf_Func &e : Before_turn_List){
        e.Call();
    }
}
void allEventAfterTurn(){
    if(turn->Side=="Enemy"){
        shared_ptr<AllyAttackAction> data_;
        Enemy *target = turn->canCastToEnemy();
        Dot_trigger(100, target, AT_NONE);
        for (auto itr = target->breakDotList.begin(); itr != target->breakDotList.end(); ) {
            if(itr->countdown!=turn->turn_cnt){
                itr++;
                continue;
            }
            itr = target->breakDotList.erase(itr);
            --target->Total_debuff;
            
        }
        for (auto itr = target->breakEngist.begin(); itr != target->breakEngist.end(); ) {
            if(itr->countdown!=turn->turn_cnt){
                itr++;
                continue;
            }
            itr = target->breakEngist.erase(itr);
            --target->Total_debuff;
            
        }
        for (auto itr = target->breakImsList.begin(); itr != target->breakImsList.end(); ) {
            if(itr->countdown!=turn->turn_cnt){
                itr++;
                continue;
            }
            itr = target->breakImsList.erase(itr);
            target->debuffSingle({{ST_SPD,ST_SPD_P,10}});
            --target->Total_debuff;
            
        }
        for(auto &e : target->Weakness_typeCountdown){
            if(e.second==turn->turn_cnt&&target->Default_Weakness_type[e.first]==0){
                target->Weakness_type[e.first] = 0;
                target->currentWeaknessElementAmount--;
            }
        }
    }
    
    for(TriggerByYourSelf_Func &e : After_turn_List){
        e.Call();
    }
}
void allEventBeforeAction(shared_ptr<ActionData> &data_){
    for(TriggerByAction_Func &e : BeforeAction_List){
        e.Call(data_);
    }
}
void allEventWhenAllyAction(shared_ptr<AllyActionData> &data_){
    for(TriggerByAllyAction_Func &e : AllyActionList){
        e.Call(data_);
    }
}
void allEventAfterAction(shared_ptr<ActionData> &data_){
    for(TriggerByAction_Func &e : AfterAction_List){
        e.Call(data_);
    }
}
void allEventBuff(shared_ptr<AllyBuffAction> &data_){
    for(TriggerByAllyBuffAction_Func &e : Buff_List){
        e.Call(data_);
    }
}
void allEventBeforeAttack(shared_ptr<AllyAttackAction> &data_){
    for(TriggerByAllyAttackAction_Func &e : Before_attack_List){
        e.Call(data_);
    }
}
void allEventAfterAttack(shared_ptr<AllyAttackAction> &data_){
    for(TriggerByAllyAttackAction_Func &e : After_attack_List){
        e.Call(data_);
    }
}
void allEventWhenAttack(shared_ptr<AllyAttackAction> &data_){
    for(Enemy* &e : data_->targetList){
        for (auto &each : e->breakEngist) {
            if(each.stack>=5)continue;
            each.stack++;
        }
    }
    
    for(TriggerByAllyAttackAction_Func &e : When_attack_List){
        e.Call(data_);
    }
}
void allEventAttackHitCount(shared_ptr<AllyAttackAction> &data_){
    for(TriggerByAllyAttackAction_Func &e : Hit_Count_List){
        e.Call(data_);
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
void allEventWhenToughnessBreak(shared_ptr<AllyAttackAction> &data_,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Toughness_break_List){
        e.Call(target,data_->Attacker);
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
void allEventAdjustStats(SubUnit *ptr,string statsType){
    AdjustCheck = 1;
    for(TriggerByStats &e : Stats_Adjust_List){
        e.Call(ptr,statsType);
    }
    AdjustCheck = 0;
}
void allEventApplyDebuff(SubUnit *ptr,Enemy* target){
    for(TriggerBySomeAlly_Func &e : Apply_debuff_List){
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
void allEventAfterDealingDamage(shared_ptr<AllyAttackAction> &data_, Enemy *src, double damage) {
    for (TriggerAfterDealDamage &e : AfterDealingDamage_List) {
        e.Call(data_, src, damage);
    }
}
#endif