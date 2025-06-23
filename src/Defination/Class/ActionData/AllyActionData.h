#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    vector<string> actionTypeList;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string traceType = "";// Aoe Single_target Bounce
    


    
    #pragma region getMethod

    Ally* getAlly(){
        return Attacker->ptrToChar;
    }
    SubUnit* getSubUnit(){
        return Attacker;
    }

    string getActionType(){
        return actionTypeList[0];
    }
    
    string getActionType(int index){
        if(index < 0 || index >= actionTypeList.size()) {
            return "Invalid index";
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
    bool isSameAction(string ability);
    bool isSameAction(SubUnit *ptr,string ability);
    bool isSameAction(string name,string ability);
    bool isSameAction(Ally *ptr,string ability);


    
    #pragma endregion


    void AllyAction();
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    string getAbitlityType(){
        return this->actionTypeList[0];
    }
    virtual void addActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BA:
                actionTypeList.push_back(AT_BA);
                break;
            case ActionType::SKILL:
                actionTypeList.push_back(AT_SKILL);
                break;
            case ActionType::Ult:
                actionTypeList.push_back(AT_ULT);
                break;
            case ActionType::Fua:
                actionTypeList.push_back(AT_FUA);
                break;
            case ActionType::Dot:
                actionTypeList.push_back(AT_DOT);
                break;
            case ActionType::Break:
                actionTypeList.push_back(AT_BREAK);
                break;
            case ActionType::SPB:
                actionTypeList.push_back(AT_SPB);
                break;
            case ActionType::Addtional:
                actionTypeList.push_back(AT_ADD);
                break;
            case ActionType::Technique:
                actionTypeList.push_back(AT_TECH);
                break;
            case ActionType::Freeze:
                actionTypeList.push_back("Freeze");
                break;
            case ActionType::Entanglement:
                actionTypeList.push_back("Entanglement");
                break;
            default:
                break;
        }
    }
    AllyAttackAction* castToAllyAttackAction();
    AllyBuffAction* castToAllyBuffAction();
};


AllyActionData* ActionData::castToAllyActionData(){
        return dynamic_cast<AllyActionData*>(this);
}


#endif