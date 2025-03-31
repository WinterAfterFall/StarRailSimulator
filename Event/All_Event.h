#ifndef Event_H
#define Event_H
#include "../Unit/Trigger_Function.h"
void allEventBeforeTurn(){
    ActionData temp = ActionData();
    if(turn->Side=="Enemy"){
        Dot_trigger(100,Enemy_unit[turn->Unit_num].get(),"None");
        if(Enemy_unit[turn->Unit_num]->Entanglement != 0){
            temp.Entanglement_set(Ally_unit[Enemy_unit[turn->Unit_num]->Entanglement]->Sub_Unit_ptr[0].get());
            double Const = 0.6*Enemy_unit[turn->Unit_num]->Entanglement_stack;
            Cal_Break_damage(temp,Enemy_unit[turn->Unit_num].get(),Const);
        }
        if(Enemy_unit[turn->Unit_num]->Freeze != 0){
            
            temp.Freeze_set(Ally_unit[Enemy_unit[turn->Unit_num]->Freeze]->Sub_Unit_ptr[0].get());
            
            Cal_Freeze_damage(temp,Enemy_unit[turn->Unit_num].get());
            Action_forward(Enemy_unit[turn->Unit_num]->Atv_stats.get(),-50);
            Turn_Skip=1;
        }
    }
    for(TriggerByYourSelf_Func &e : Before_turn_List){
        e.Call();
    }
}
void allEventAfterTurn(){
    if(turn->Side=="Enemy"){
        if(Enemy_unit[turn->Unit_num]->Entanglement != 0){
           Enemy_unit[turn->Unit_num]->Entanglement = 0;
           Enemy_unit[turn->Unit_num]->Entanglement_stack = 0;
           --Enemy_unit[turn->Unit_num]->Total_debuff;
        }
        if(Enemy_unit[turn->Unit_num]->Freeze != 0){
            Enemy_unit[turn->Unit_num]->Freeze = 0;
           --Enemy_unit[turn->Unit_num]->Total_debuff;
        }
        if(Enemy_unit[turn->Unit_num]->Imprisonment != 0){
           Enemy_unit[turn->Unit_num]->Imprisonment = 0;
           Speed_Buff(Enemy_unit[turn->Unit_num]->Atv_stats.get(),10,0);
           --Enemy_unit[turn->Unit_num]->Total_debuff;
        }
        if(Enemy_unit[turn->Unit_num]->Bleed > 0){
           Enemy_unit[turn->Unit_num]->Bleed--;
           if(Enemy_unit[turn->Unit_num]->Bleed==0){
            Enemy_unit[turn->Unit_num]->Bleeder = 0;
            --Enemy_unit[turn->Unit_num]->Total_debuff;
           }
        }
        if(Enemy_unit[turn->Unit_num]->Burn > 0){
           Enemy_unit[turn->Unit_num]->Burn--;
           if(Enemy_unit[turn->Unit_num]->Burn==0){
            Enemy_unit[turn->Unit_num]->Burner = 0;
            --Enemy_unit[turn->Unit_num]->Total_debuff;
           }
        }
        if(Enemy_unit[turn->Unit_num]->Shock > 0){
           Enemy_unit[turn->Unit_num]->Shock--;
           if(Enemy_unit[turn->Unit_num]->Shock==0){
            Enemy_unit[turn->Unit_num]->Shocker = 0;
            --Enemy_unit[turn->Unit_num]->Total_debuff;
           }
        }
        if(Enemy_unit[turn->Unit_num]->Wind_shear > 0){
           Enemy_unit[turn->Unit_num]->Wind_shear--;
           if(Enemy_unit[turn->Unit_num]->Wind_shear==0){
            Enemy_unit[turn->Unit_num]->Wind_shearer = 0;
            Enemy_unit[turn->Unit_num]->Wind_shear_stack = 0;
            --Enemy_unit[turn->Unit_num]->Total_debuff;
           }
        }
    }
    for(TriggerByYourSelf_Func &e : After_turn_List){
        e.Call();
    }
}
void allEventBuff(ActionData &data_){
    for(TriggerByAction_Func &e : Buff_List){
        e.Call(data_);
    }
}
void allEventBeforeAttack(ActionData &data_){
    for(TriggerByAction_Func &e : Before_attack_List){
        e.Call(data_);
    }
}
void allEventAfterAttack(ActionData &data_){
    for(TriggerByAction_Func &e : After_attack_List){
        e.Call(data_);
    }
}
void allEventWhenAttack(ActionData &data_){
    for(TriggerByAction_Func &e : When_attack_List){
        e.Call(data_);
    }
}
void allEventHeal(Sub_Unit *Healer,Sub_Unit *target,double Value){
    for(TriggerHealing &e : Healing_List){
        e.Call(Healer,target,Value);
    }
}
void allEventChangeHP(Unit *Trigger,Sub_Unit *target,double Value){
    for(TriggerDecreaseHP &e : HPDecrease_List){
        e.Call(Trigger,target,Value);
    }
}
void allEventWhenToughnessBreak(ActionData &data_,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Toughness_break_List){
        e.Call(target,data_.Attacker);
    }
}
void allEventWhenEnemyHit(Enemy* Attacker,vector<Sub_Unit*> vec){
    
    for(TriggerByEnemyHit &e : Enemy_hit_List){
        e.Call(Attacker,vec);
    }
    
    
}
void allEventWhenEnergyIncrease(Ally *target,double Energy){
    for(TriggerEnergy_Increase_Func &e : When_Energy_Increase_List){
        e.Call(target,Energy);
    }
}
void allEventSkillPoint(Sub_Unit *ptr,int p){
    for(TriggerSkill_point_func &e : Skill_point_List){
        e.Call(ptr,p);
    }
    return ;
}
void allEventAttackHitCount(ActionData &data_,int Hit_cnt,int Total_Hit_cnt){
    for(TriggerHit_Count_func &e : Hit_Count_List){
        e.Call(data_,Hit_cnt,Total_Hit_cnt);
    }
}
void allEventAdjustStats(Sub_Unit *ptr,string statsType){
    AdjustCheck = 1;
    for(TriggerByStats &e : Stats_Adjust_List){
        e.Call(ptr,statsType);
    }
    AdjustCheck = 0;
}
void allEventApplyDebuff(Sub_Unit *ptr,Enemy* target){
    for(TriggerBySomeAlly_Func &e : Apply_debuff_List){
        e.Call(target,ptr);
    }
}
void allEventWhenEnemyDeath(Sub_Unit *Killer,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Enemy_Death_List){
        e.Call(target,Killer);
    }
}

#endif