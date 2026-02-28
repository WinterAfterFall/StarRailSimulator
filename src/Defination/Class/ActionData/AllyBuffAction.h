#ifndef AllySupportAction_H
#define AllySupportAction_H
#include "AllyActionData.h"

class AllyBuffAction : public AllyActionData {
    public:
    vector<AllyUnit*> buffTargetList;
    function<void(shared_ptr<AllyBuffAction> &act)> actionFunction;


    #pragma region checkMethod

    bool isSameBufferName(AllyUnit *ptr){
        if(this->Attacker->isSameName(ptr))return true;
        return false;
    }
    bool isSameBufferName(CharUnit *ptr){
        if(ptr->isSameOwner(this->Attacker))return true;
        return false;
    }
    bool isSameBufferName(string name){
        if(this->Attacker->isSameName(name))return true;
        return false;
    }
    bool isSameBuff(AType ability){
        for(auto &each : actionTypeList){
            if(each == ability)return true;
        }  
        return false;    
    }
    bool isSameBuff(AllyUnit *ptr,AType ability){
        if(this->Attacker->isSameName(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }
    bool isSameBuff(CharUnit *ptr,AType ability){
        if(ptr->isSameOwner(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }
    bool isSameBuff(string name,AType ability){
        if(this->Attacker->isSameName(name)){
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
            case AType::ElationSkill:
                actionTypeList.push_back(AType::ElationSkill);
                actionTypeList.push_back(AType::ElationDMG);
                break;
            case AType::ElationDMG:
                actionTypeList.push_back(AType::ElationDMG);
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

    void addBuffSingleTarget(AllyUnit* ptr){
        buffTargetList.push_back(ptr);
    }
    void addBuffChar(CharUnit* ptr){
        if(ptr->getType() != UnitType::OutofBounds)buffTargetList.push_back(ptr);
        for(auto &e:ptr->memospriteList){
            if(e->getType() != UnitType::OutofBounds)buffTargetList.push_back(e.get());
        }
    }
    void addBuffAllAllies(){
        for(int i=1;i<=Total_ally;i++){
            if(charUnit[i]->getType() != UnitType::OutofBounds)
                buffTargetList.push_back(charUnit[i].get());\

            for(auto &e:charUnit[i]->memospriteList){
                if(e->getType() != UnitType::OutofBounds)
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
    AllyBuffAction(AType actionType,AllyUnit* ptr,TraceType traceType, string name)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->traceType = traceType;
        setupActionType(actionType);
    }
    AllyBuffAction(AType actionType,AllyUnit* ptr,TraceType traceType, string name,function<void(shared_ptr<AllyBuffAction> &act)> actionFunction)
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