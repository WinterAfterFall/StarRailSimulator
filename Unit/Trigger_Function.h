#ifndef Trigger_H
#define Trigger_H
#include<bits/stdc++.h>
#include"Action_Data.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000
class TriggerFunc{
    public:
    int priority = 0;
    Ally* ptr;
    
    TriggerFunc(int priority ,Ally* ptr) : priority(priority),ptr(ptr){

    }
    static bool Trigger_cmp(const TriggerFunc& l, const TriggerFunc& r) {
        return l.priority > r.priority;  // Higher priority first
    }
};
class TriggerByYourSelf_Func : public TriggerFunc{
    public:
    function<void(Ally *ptr)> Call;
    TriggerByYourSelf_Func(int priority ,Ally* ptr,function<void(Ally *ptr)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};
class TriggerByAction_Func : public TriggerFunc{
    public:
    function<void(Ally *ptr,Combat_data &data_)> Call;
    TriggerByAction_Func(int priority ,Ally* ptr,function<void(Ally *ptr,Combat_data &data_)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerByStats : public TriggerFunc{
    public:
    function<void(Ally *ptr,Sub_Unit* Target,string StatsType)> Call;
    TriggerByStats(int priority ,Ally* ptr,function<void(Ally *ptr,Sub_Unit* Target,string StatsType)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerBySomeAlly_Func : public TriggerFunc{
    public:
    function<void(Ally *ptr,Enemy *target,Sub_Unit *Trigger)> Call;
    TriggerBySomeAlly_Func(int priority ,Ally* ptr,function<void(Ally *ptr,Enemy *target,Sub_Unit *Trigger)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerHealing : public TriggerFunc{
    public:
    function<void(Ally *ptr,Heal_data* Healptr)> Call;
    TriggerHealing(int priority ,Ally* ptr,function<void(Ally *ptr,Heal_data* Healptr)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};
class TriggerChangeHP : public TriggerFunc{
    public:
    function<void(Ally *ptr,Sub_Unit *Healer,Sub_Unit *target,double Value)> Call;
    TriggerChangeHP(int priority ,Ally* ptr,function<void(Ally *ptr,Sub_Unit *Healer,Sub_Unit *target,double Value)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};
class TriggerByEnemyHit : public TriggerFunc{
    public:
    function<void(Ally *ptr,Enemy *Attacker,vector<Sub_Unit*> target)> Call;
    TriggerByEnemyHit(int priority ,Ally* ptr,function<void(Ally *ptr,Enemy *Attacker,vector<Sub_Unit*> target)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerDot_Func : public TriggerFunc{
    public:
    function<void(Enemy* target,Ally *ptr,double Dot_ratio,string Dot_type)> Call;
    TriggerDot_Func(int priority ,Ally* ptr,function<void(Enemy* target,Ally *ptr,double Dot_ratio,string Dot_type)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerEnergy_Increase_Func : public TriggerFunc{
    public:
    function<void(Ally *ptr,Ally *target,double Energy)> Call;
    TriggerEnergy_Increase_Func(int priority ,Ally* ptr,function<void(Ally *ptr,Ally *target,double Energy)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerSkill_point_func : public TriggerFunc{
    public:
    function<void(Ally *ptr,Sub_Unit *SP_maker,int SP)> Call;
    TriggerSkill_point_func(int priority ,Ally* ptr,function<void(Ally *ptr,Sub_Unit *SP_maker,int SP)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};

class TriggerHit_Count_func : public TriggerFunc{
    public:
    function<void(Ally *ptr,Combat_data &data_,int Hit_cnt,int Total_Hit_cnt)> Call;
    TriggerHit_Count_func(int priority ,Ally* ptr,function<void(Ally *ptr,Combat_data &data_,int Hit_cnt,int Total_Hit_cnt)> Call) 
    : TriggerFunc(priority,ptr) ,Call(Call){}
};
#endif