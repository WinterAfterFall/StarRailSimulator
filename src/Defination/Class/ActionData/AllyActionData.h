#ifndef ALLY_ACTION_DATA_H
#define ALLY_ACTION_DATA_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool turnReset = 0;
    AllyUnit* attacker = nullptr;
    AllyUnit* source = nullptr; 
    vector<AType> actionTypeList;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    TraceType traceType;
    


    
    #pragma region getMethod

    CharUnit* getChar(){
        Memosprite* memo = dynamic_cast<Memosprite*>(attacker);
        CharUnit* owner = dynamic_cast<CharUnit*>(attacker);
        if(memo){
            return memo->owner;
        }
        return owner;
    }
    AllyUnit* getAttacker(){
        return attacker;
    }

    AType getActionType(){
        return actionTypeList[0];
    }
    
    AType getActionType(int index){
        if(index < 0 || index >= actionTypeList.size()) {
            return AType::ERROR;
        }
        return actionTypeList[index];
    }
    
    #pragma endregion

    #pragma region setMethod

    void setTurnReset(bool arg){
        turnReset = arg;
    }
    
    #pragma endregion

    #pragma region checkMethod

    bool isSameName(AllyUnit *ptr);
    bool isSameOwnerName(CharUnit *ptr);
    bool isSameName(string name);
    bool isSameAction(AType ability);
    bool isSameAction(AllyUnit *ptr,AType ability);
    bool isSameAction(string name,AType ability);
    bool isSameOwnerAction(CharUnit *ptr,AType ability);



    
    #pragma endregion


    void allyAction();
    void elationSkillAction();
    void turnResetTrue(){
        this->turnReset = true;
    }
    virtual void addActionType(AType actionType){
            actionTypeList.push_back(actionType);
    }
    AllyAttackAction* castToAllyAttackAction();
    AllyBuffAction* castToAllyBuffAction();
};


AllyActionData* ActionData::castToAllyActionData(){
        return dynamic_cast<AllyActionData*>(this);
}


#endif