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
    bool isSameBuff(AType ability){
        for(auto &each : actionTypeList){
            if(each == ability)return true;
        }  
        return false;    
    }
    bool isSameBuff(SubUnit *ptr,AType ability){
        if(this->Attacker->isSameUnit(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }
    bool isSameBuff(Ally *ptr,AType ability){
        if(ptr->isSameAlly(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }
    bool isSameBuff(string name,AType ability){
        if(this->Attacker->isSameUnitName(name)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }


    #pragma endregion

    private :
    void setupActionType(AType actionType){
        switch(actionType) {
            case AType::BA:
                actionTypeList.push_back(AType::BA);
                Turn_reset = true;
                break;
            case AType::SKILL:
                actionTypeList.push_back(AType::SKILL);
                Turn_reset = true;
                break;
            case AType::Ult:
                actionTypeList.push_back(AType::Ult);
                break;
            case AType::Fua:
                actionTypeList.push_back(AType::Fua);
                break;
            case AType::Dot:
                actionTypeList.push_back(AType::Dot);
                break;
            case AType::Break:
                actionTypeList.push_back(AType::Break);
                break;
            case AType::SPB:
                actionTypeList.push_back(AType::Break);
                actionTypeList.push_back(AType::SPB);
                break;
            case AType::Addtional:
                actionTypeList.push_back(AType::Addtional);
                break;
            case AType::Technique:
                actionTypeList.push_back(AType::Technique);
                break;
            case AType::Freeze:
                actionTypeList.push_back(AType::Freeze);
                break;
            case AType::Entanglement:
                actionTypeList.push_back(AType::Entanglement);
                break;
            default:
                break;
        }
    }
    public :

    void addBuffSingleTarget(){
        buffTargetList.push_back(chooseSubUnitBuff(Attacker));
    }

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
        if(!Attacker->isExsited())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        Action_bar.push(self);
    }
    AllyBuffAction(){}
    AllyBuffAction(AType actionType,SubUnit* ptr,TraceType traceType, string name)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->traceType = traceType;
        setupActionType(actionType);
    }
    AllyBuffAction(AType actionType,SubUnit* ptr,TraceType traceType, string name,function<void(shared_ptr<AllyBuffAction> &act)> actionFunction)
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