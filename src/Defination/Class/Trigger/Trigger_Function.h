#ifndef Trigger_H
#define Trigger_H

#include"../ActionData/Library.h"

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
class TriggerByAlly_Func : public TriggerFunc{
    public:
    function<void(Ally *ally)> Call;
    TriggerByAlly_Func(int priority, function<void(Ally *ally)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByAction_Func : public TriggerFunc{
    public:
    function<void(shared_ptr<ActionData> &act)> Call;
    TriggerByAction_Func(int priority, function<void(shared_ptr<ActionData> &act)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByAllyAction_Func : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyActionData> &act)> Call;
    TriggerByAllyAction_Func(int priority, function<void(shared_ptr<AllyActionData> &act)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByAllyAttackAction_Func : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyAttackAction> &act)> Call;
    TriggerByAllyAttackAction_Func(int priority, function<void(shared_ptr<AllyAttackAction> &act)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
class TriggerByAllyBuffAction_Func : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyBuffAction> &act)> Call;
    TriggerByAllyBuffAction_Func(int priority, function<void(shared_ptr<AllyBuffAction> &act)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};

class TriggerByStats : public TriggerFunc{
    public:
    function<void(SubUnit* Target, Stats StatsType)> Call;
    TriggerByStats(int priority, function<void(SubUnit* Target, Stats StatsType)> Call) 
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
    function<void(Enemy* target,double Dot_ratio,DotType Dot_type)> Call;
    TriggerDot_Func(int priority, function<void(Enemy* target, double Dot_ratio,DotType Dot_type)> Call) 
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

class TriggerAfterDealDamage : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyAttackAction> &act,Enemy *src,double damage)> Call;
    TriggerAfterDealDamage(int priority, function<void(shared_ptr<AllyAttackAction> &act,Enemy *src,double damage)> Call) 
    : TriggerFunc(priority), Call(Call) {}
};
#endif
