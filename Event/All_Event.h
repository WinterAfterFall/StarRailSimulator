#ifndef Event_H
#define Event_H
#include "../Print.h"
void allEventBeforeTurn(){
    Combat_data temp = Combat_data();
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
        e.Call(e.ptr);
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
        e.Call(e.ptr);
    }
}
void allEventBuff(Combat_data &data_){
    for(TriggerByAction_Func &e : Buff_List){
        e.Call(e.ptr,data_);
    }
}
void allEventBeforeAttack(Combat_data &data_){
    for(TriggerByAction_Func &e : Before_attack_List){
        e.Call(e.ptr,data_);
    }
}
void allEventAfterAttack(Combat_data &data_){
    for(TriggerByAction_Func &e : After_attack_List){
        e.Call(e.ptr,data_);
    }
}
void allEventWhenAttack(Combat_data &data_){
    for(TriggerByAction_Func &e : When_attack_List){
        e.Call(e.ptr,data_);
    }
}
void allEventHeal(Heal_data* Healptr ){
    for(TriggerHealing &e : Healing_List){
        e.Call(e.ptr,Healptr);
    }
}
void allEventChangeHP(Sub_Unit *Healer,Sub_Unit *target,double Value){
    for(TriggerChangeHP &e : ChangeHP_List){
        e.Call(e.ptr,Healer,target,Value);
    }
}
void allEventWhenToughnessBreak(Combat_data &data_,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Toughness_break_List){
        e.Call(e.ptr,target,data_.Attacker);
    }
}
void allEventWhenEnemyHit(double energy,Enemy *target){
    for(int i=1;i<=Total_ally;i++){
            Increase_energy(Ally_unit[i].get(),energy);
    }
    for(TriggerByEnemyHit &e : Enemy_hit_List){
        e.Call(e.ptr,target);
    }
}
void allEventWhenEnergyIncrease(Ally *target,double Energy){
    for(TriggerEnergy_Increase_Func &e : When_Energy_Increase_List){
        e.Call(e.ptr,target,Energy);
    }
}
void allEventSkillPoint(Sub_Unit *ptr,int p){
    for(TriggerSkill_point_func &e : Skill_point_List){
        e.Call(e.ptr,ptr,p);
    }
    return ;
}
void allEventAttackHitCount(Combat_data &data_,int Hit_cnt,int Total_Hit_cnt){
    for(TriggerHit_Count_func &e : Hit_Count_List){
        e.Call(e.ptr,data_,Hit_cnt,Total_Hit_cnt);
    }
}
void allEventAdjustStats(Sub_Unit *ptr,string statsType){
    AdjustCheck = 1;
    for(TriggerByStats &e : Stats_Adjust_List){
        e.Call(e.ptr,ptr,statsType);
    }
    AdjustCheck = 0;
}
void allEventApplyDebuff(Sub_Unit *ptr,Enemy* target){
    for(TriggerBySomeAlly_Func &e : Apply_debuff_List){
        e.Call(e.ptr,target,ptr);
    }
}
void allEventWhenEnemyDeath(Sub_Unit *Killer,Enemy *target){
    for(TriggerBySomeAlly_Func &e : Enemy_Death_List){
        e.Call(e.ptr,target,Killer);
    }
}

#endif