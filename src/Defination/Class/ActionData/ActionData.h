#ifndef ACTION_DATA_H
#define ACTION_DATA_H
#include "../CombatData/Library.h"

class PointerWithValue{
    public : 
    AllyUnit* ptr;
    double value = 0;

    PointerWithValue(AllyUnit *ptr ,double value) : ptr(ptr),value(value){

    }

    static bool Less_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value < r.value;  // Higher priority first
    }
    static bool Greater_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value > r.value;  // Higher priority first
    }
};
class ActionData{
    public:
    string actionName = "";
    virtual ~ActionData() {}

    string getActionName(){
        return actionName;
    }
    void getActionName(string name){
        actionName = name;
    }
    AllyActionData* castToAllyActionData();
    EnemyActionData* castToEnemyActionData();
};


#endif