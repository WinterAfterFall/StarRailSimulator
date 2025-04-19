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
    
    TriggerFunc(int priority) : priority(priority) {}

    static bool Trigger_cmp(const TriggerFunc& l, const TriggerFunc& r) {
        return l.priority > r.priority;  // Higher priority first
    }
};
class TriggerByYourSelf_Func : public TriggerFunc{
    public:
    function<void()> Call;
    TriggerByYourSelf_Func(int priority, function<void()> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByAction_Func : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyActionData> &data_)> Call;
    TriggerByAction_Func(int priority, function<void(shared_ptr<AllyActionData> &data_)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerByStats : public TriggerFunc{
    public:
    function<void(SubUnit* Target, string StatsType)> Call;
    TriggerByStats(int priority, function<void(SubUnit* Target, string StatsType)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerAllyDeath : public TriggerFunc{
    public:
    function<void(SubUnit* target)> Call;
    TriggerAllyDeath(int priority, function<void(SubUnit* target)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerBySomeAlly_Func : public TriggerFunc{
    public:
    function<void(Enemy *target, SubUnit *Trigger)> Call;
    TriggerBySomeAlly_Func(int priority, function<void(Enemy *target, SubUnit *Trigger)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerHealing : public TriggerFunc{
    public:
    function<void(SubUnit *Healer, SubUnit *target, double Value)> Call;
    TriggerHealing(int priority, function<void(SubUnit *Healer, SubUnit *target, double Value)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerDecreaseHP : public TriggerFunc{
    public:
    function<void(Unit *Trigger, SubUnit *target, double Value)> Call;
    TriggerDecreaseHP(int priority, function<void(Unit *Trigger, SubUnit *target, double Value)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByEnemyHit : public TriggerFunc{
    public:
    function<void(Enemy *Attacker, vector<SubUnit*> target)> Call;
    TriggerByEnemyHit(int priority, function<void(Enemy *Attacker, vector<SubUnit*> target)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerDot_Func : public TriggerFunc{
    public:
    function<void(Enemy* target,double Dot_ratio,string Dot_type)> Call;
    TriggerDot_Func(int priority, function<void(Enemy* target, double Dot_ratio, string Dot_type)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerEnergy_Increase_Func : public TriggerFunc{
    public:
    function<void(Ally *target, double Energy)> Call;
    TriggerEnergy_Increase_Func(int priority, function<void(Ally *target, double Energy)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerSkill_point_func : public TriggerFunc{
    public:
    function<void(SubUnit *SP_maker, int SP)> Call;
    TriggerSkill_point_func(int priority, function<void(SubUnit *SP_maker, int SP)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerHit_Count_func : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyActionData> &data_, int Hit_cnt, int Total_Hit_cnt)> Call;
    TriggerHit_Count_func(int priority, function<void(shared_ptr<AllyActionData> &data_, int Hit_cnt, int Total_Hit_cnt)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
#endif
