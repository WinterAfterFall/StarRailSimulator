#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    vector<string> abilityTypeList;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string traceType = "";// Aoe Single_target Bounce
    


    
    #pragma region getMethod

    string getActionType(){
        return abilityTypeList[0];
    }
    
    string getActionType(int index){
        if(index < 0 || index >= abilityTypeList.size()) {
            return "Invalid index";
        }
        return abilityTypeList[index];
    }
    
    #pragma endregion

    #pragma region setMethod

    string setTurnReset(bool arg){
        Turn_reset = arg;
    }
    
    #pragma endregion

    #pragma region checkMethod

    virtual bool isSameUnit(SubUnit *ptr){
        if (Attacker->isSameUnit(ptr))return true;
        return false;
    }
    virtual bool isSameUnitName(string name){
        if (Attacker->isSameUnitName(name))return true;
        return false;
    }

    virtual bool isSameAbility(string ability){
        for (const auto& abilityName : abilityTypeList) {
                if (abilityName == ability) {
                    return true;
                }
        }
        return false;
    }


    virtual bool isSameAbility(string name,string ability){
        if (Attacker->isSameUnitName(name)) {
            for (const auto& abilityName : abilityTypeList) {
                if (abilityName == ability) {
                    return true;
                }
            }
        }
        return false;
    }

    virtual bool isSameAbility(SubUnit *ptr,string ability){
        if (Attacker->isSameUnit(ptr)) {
            for (const auto& abilityName : abilityTypeList) {
                if (abilityName == ability) {
                    return true;
                }
            }
        }
        return false;
    }
    
    #pragma endregion

    void AllyAction();
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    string getAbitlityType(){
        return this->abilityTypeList[0];
    }
    void addActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BA:
                abilityTypeList.push_back(AT_BA);
                break;
            case ActionType::SKILL:
                abilityTypeList.push_back(AT_SKILL);
                break;
            case ActionType::Ult:
                abilityTypeList.push_back(AT_ULT);
                break;
            case ActionType::Fua:
                abilityTypeList.push_back(AT_FUA);
                break;
            case ActionType::Dot:
                abilityTypeList.push_back(AT_DOT);
                break;
            case ActionType::Break:
                abilityTypeList.push_back(AT_BREAK);
                break;
            case ActionType::SPB:
                abilityTypeList.push_back(AT_SPB);
                abilityTypeList.push_back(AT_BREAK);
                break;
            case ActionType::Addtional:
                abilityTypeList.push_back(AT_ADD);
                break;
            case ActionType::Technique:
                abilityTypeList.push_back(AT_TECH);
                break;
            case ActionType::Freeze:
                abilityTypeList.push_back("Freeze");
                break;
            case ActionType::Entanglement:
                abilityTypeList.push_back("Entanglement");
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