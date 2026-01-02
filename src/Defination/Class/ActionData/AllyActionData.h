#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    AllyUnit* Attacker = nullptr;
    AllyUnit* source = nullptr; 
    vector<AType> actionTypeList;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    TraceType traceType;
    


    
    #pragma region getMethod

    CharUnit* getChar(){
        Memosprite* memo = dynamic_cast<Memosprite*>(Attacker);
        CharUnit* owner = dynamic_cast<CharUnit*>(Attacker);
        if(memo){
            return memo->owner;
        }
        return owner;
    }
    AllyUnit* getAttacker(){
        return Attacker;
    }

    AType getActionType(){
        return actionTypeList[0];
    }
    
    AType getActionType(int index){
        if(index < 0 || index >= actionTypeList.size()) {
            return AType::AllyUnit;
        }
        return actionTypeList[index];
    }
    
    #pragma endregion

    #pragma region setMethod

    void setTurnReset(bool arg){
        Turn_reset = arg;
    }
    
    #pragma endregion

    #pragma region checkMethod

    bool isSameUnitName(AllyUnit *ptr);
    bool isSameUnitName(CharUnit *ptr);
    bool isSameStatsOwnerName(string name);
    bool isSameAction(AType ability);
    bool isSameAction(AllyUnit *ptr,AType ability);
    bool isSameAction(string name,AType ability);
    bool isSameAction(CharUnit *ptr,AType ability);



    
    #pragma endregion


    void AllyAction();
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    AType getAbitlityType(){
        return this->actionTypeList[0];
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