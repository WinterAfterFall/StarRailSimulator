#ifndef TRIGGER_H
#define TRIGGER_H

#include"../ActionData/Library.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_CONST 10000
class TriggerFunc{
    public:
    int priority = 0;
    CharUnit *owner = nullptr;
    
    TriggerFunc(int priority) : priority(priority) {}
    TriggerFunc(int priority, CharUnit *owner) : priority(priority), owner(owner) {}

    static bool triggerCmp(const TriggerFunc& l, const TriggerFunc& r) {
        return l.priority > r.priority;  // Higher priority first
    }
};
// owner is required: the engine passes it back to Call as ptr
class TriggerByYourSelfFunc : public TriggerFunc{
    public:
    function<void(CharUnit *ptr)> call;
    TriggerByYourSelfFunc(int priority, CharUnit *ptr, function<void(CharUnit *ptr)> call)
    : TriggerFunc(priority, ptr), call(call) {}
};
class TriggerByAllyFunc : public TriggerFunc{
    public:
    function<void(CharUnit *ally)> call;
    TriggerByAllyFunc(int priority, function<void(CharUnit *ally)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerByActionFunc : public TriggerFunc{
    public:
    function<void(shared_ptr<ActionData> &act)> call;
    TriggerByActionFunc(int priority, function<void(shared_ptr<ActionData> &act)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerByAllyActionFunc : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyActionData> &act)> call;
    TriggerByAllyActionFunc(int priority, function<void(shared_ptr<AllyActionData> &act)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerByAllyAttackActionFunc : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyAttackAction> &act)> call;
    TriggerByAllyAttackActionFunc(int priority, function<void(shared_ptr<AllyAttackAction> &act)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerByAllyBuffActionFunc : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyBuffAction> &act)> call;
    TriggerByAllyBuffActionFunc(int priority, function<void(shared_ptr<AllyBuffAction> &act)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerByStats : public TriggerFunc{
    public:
    function<void(AllyUnit* target, Stats statsType)> call;
    TriggerByStats(int priority, function<void(AllyUnit* target, Stats statsType)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerAllyDeath : public TriggerFunc{
    public:
    function<void(AllyUnit* target)> call;
    TriggerAllyDeath(int priority, function<void(AllyUnit* target)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerBySomeAllyFunc : public TriggerFunc{
    public:
    function<void(Enemy *target, AllyUnit *trigger)> call;
    TriggerBySomeAllyFunc(int priority, function<void(Enemy *target, AllyUnit *trigger)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerByWeaknessApplyFunc : public TriggerFunc{
    public:
    function<void(AllyUnit *trigger,Enemy *target, vector<ElementType> elementList)> call;
    TriggerByWeaknessApplyFunc(int priority, function<void(AllyUnit *trigger,Enemy *target, vector<ElementType> elementList)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerHealing : public TriggerFunc{
    public:
    function<void(AllyUnit *healer, AllyUnit *target, double value)> call;
    TriggerHealing(int priority, function<void(AllyUnit *healer, AllyUnit *target, double value)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerDecreaseHP : public TriggerFunc{
    public:
    function<void(Unit *trigger, AllyUnit *target, double value)> call;
    TriggerDecreaseHP(int priority, function<void(Unit *trigger, AllyUnit *target, double value)> call) 
    : TriggerFunc(priority), call(call) {}
};
class TriggerByEnemyHit : public TriggerFunc{
    public:
    function<void(Enemy *attacker, vector<AllyUnit*> target)> call;
    TriggerByEnemyHit(int priority, function<void(Enemy *attacker, vector<AllyUnit*> target)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerDotFunc : public TriggerFunc{
    public:
    function<void(Enemy* target,double dotRatio,DotType dotType)> call;
    TriggerDotFunc(int priority, function<void(Enemy* target, double dotRatio,DotType dotType)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerEnergyIncreaseFunc : public TriggerFunc{
    public:
    function<void(CharUnit *target, double energy)> call;
    TriggerEnergyIncreaseFunc(int priority, function<void(CharUnit *target, double energy)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerSkillPointFunc : public TriggerFunc{
    public:
    function<void(AllyUnit *spMaker, int spChange)> call;
    TriggerSkillPointFunc(int priority, function<void(AllyUnit *spMaker, int spChange)> call) 
    : TriggerFunc(priority), call(call) {}
};

class TriggerAfterDealDamage : public TriggerFunc{
    public:
    function<void(shared_ptr<AllyAttackAction> &act,Enemy *target,double damage)> call;
    TriggerAfterDealDamage(int priority, function<void(shared_ptr<AllyAttackAction> &act,Enemy *target,double damage)> call)
    : TriggerFunc(priority), call(call) {}
};
#endif
