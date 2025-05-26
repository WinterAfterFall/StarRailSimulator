#ifndef ACTION_DATA_H
#define ACTION_DATA_H
#include "../Unit/Library.h"

class PointerWithValue{
    public : 
    SubUnit* ptr;
    double value = 0;

    PointerWithValue(SubUnit *ptr ,double value) : ptr(ptr),value(value){

    }

    static bool Less_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value < r.value;  // Higher priority first
    }
    static bool Greater_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value > r.value;  // Higher priority first
    }
};
class AttackSource{
    public : 
    SubUnit* attacker = nullptr;
    SubUnit* source = nullptr;
    int changeWhen = 0;
    AttackSource(int changeWhen , SubUnit* attacker)
        : attacker(attacker), source(attacker), changeWhen(changeWhen) {}
    AttackSource(int changeWhen , SubUnit* attacker, SubUnit* source)
        : attacker(attacker), source(source), changeWhen(changeWhen) {}

};
class HealRatio{
    public :
    double ATK = 0;
    double HP = 0;
    double DEF = 0;
    double fixHeal = 0;
    double healFromTotalHP = 0;
    double healFromLostHP = 0;
    bool isHeal(){
        if(ATK==0&&HP==0&&DEF==0&&fixHeal==0&&healFromTotalHP==0&&healFromLostHP==0)return false;
        return true;
    }

};
class Ratio_data{
    public:
    double Atk_ratio = 0;
    double Hp_ratio = 0;
    double Def_ratio = 0;
    double Toughness_ratio = 0;
    double fixDmg = 0;
};
class Hit_spilt{
    public:
    vector<Ratio_data> Main;
    vector<Ratio_data> Adjacent;
    vector<Ratio_data> Other;
};
class ActionData{
    public:
    string actionName = "";
    virtual ~ActionData() {}

    AllyActionData* castToAllyActionData();
    EnemyActionData* castToEnemyActionData();
};


#endif