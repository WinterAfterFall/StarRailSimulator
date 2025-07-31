#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    vector<AType> actionTypeList;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string traceType = "";// Aoe Single_target Bounce
    


    
    #pragma region getMethod

    Ally* getAlly(){
        return Attacker->ptrToChar;
    }
    SubUnit* getSubUnit(){
        return Attacker;
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
        Turn_reset = arg;
    }
    
    #pragma endregion

    #pragma region checkMethod

    bool isSameUnit(SubUnit *ptr);
    bool isSameAlly(Ally *ptr);
    bool isSameUnitName(string name);
    bool isSameAction(AType ability);
    bool isSameAction(SubUnit *ptr,AType ability);
    bool isSameAction(string name,AType ability);
    bool isSameAction(Ally *ptr,AType ability);



    
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