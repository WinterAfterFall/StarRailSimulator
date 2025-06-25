#ifndef AllySupportAction_H
#define AllySupportAction_H
#include "AllyActionData.h"

class AllyBuffAction : public AllyActionData {
    public:
    vector<SubUnit*> buffTargetList;
    function<void(shared_ptr<AllyBuffAction> &act)> actionFunction;


    #pragma region checkMethod

    bool isSameBuffer(SubUnit *ptr){
        if(this->Attacker->isSameUnit(ptr))return true;
        return false;
    }
    bool isSameBuffer(Ally *ptr){
        if(ptr->isSameAlly(this->Attacker))return true;
        return false;
    }
    bool isSameBufferName(string name){
        if(this->Attacker->isSameUnitName(name))return true;
        return false;
    }
    bool isSameBuff(string ability){
        for(auto &each : actionTypeList){
            if(each == ability)return true;
        }  
        return false;    
    }
    bool isSameBuff(SubUnit *ptr,string ability){
        if(this->Attacker->isSameUnit(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }
    bool isSameBuff(Ally *ptr,string ability){
        if(ptr->isSameAlly(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }
    bool isSameBuff(string name,string ability){
        if(this->Attacker->isSameUnitName(name)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }


    #pragma endregion

    private :
    void setupActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BA:
                actionTypeList.push_back(AT_BA);
                Turn_reset = true;
                break;
            case ActionType::SKILL:
                actionTypeList.push_back(AT_SKILL);
                Turn_reset = true;
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
    public :

    void addBuffSingleTarget(SubUnit* ptr){
        buffTargetList.push_back(ptr);
    }
    void addBuffAlly(Ally* ptr){
        for(auto &e:ptr->Sub_Unit_ptr){
            buffTargetList.push_back(e.get());
        }
    }
    void addBuffAllAllies(){
        
        for(int i=1;i<=Total_ally;i++){
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr){
                buffTargetList.push_back(e.get());
            }
        }
    }
    void addToActionBar(){
        if(!Attacker->isUseable())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        Action_bar.push(self);
    }
    AllyBuffAction(){}
    AllyBuffAction(ActionType actionType,SubUnit* ptr,string traceType, string name)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->traceType = traceType;
        setupActionType(actionType);
    }
    AllyBuffAction(ActionType actionType,SubUnit* ptr,string traceType, string name,function<void(shared_ptr<AllyBuffAction> &act)> actionFunction)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        this->traceType = traceType;
        setupActionType(actionType);
    }
    

};
AllyBuffAction* AllyActionData::castToAllyBuffAction(){
        return dynamic_cast<AllyBuffAction*>(this);
}
#endif