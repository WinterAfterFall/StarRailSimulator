#ifndef AllySupportAction_H
#define AllySupportAction_H
#include "AllyActionData.h"

class AllyBuffAction : public AllyActionData {
    public:
    vector<SubUnit*> buffTargetList;
    function<void(shared_ptr<AllyBuffAction> &data_)> actionFunction;



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
        addActionType(actionType);
        switch(actionType) {
            case ActionType::BA:
                Turn_reset = 1;
                break;
            case ActionType::SKILL:
                Turn_reset = 1;
                break;
            default:
                break;
        }
    }
    AllyBuffAction(ActionType actionType,SubUnit* ptr,string traceType, string name,function<void(shared_ptr<AllyBuffAction> &data_)> actionFunction)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        this->traceType = traceType;
        addActionType(actionType);
        switch(actionType) {
            case ActionType::BA:
                Turn_reset = 1;
                break;
            case ActionType::SKILL:
                Turn_reset = 1;
                break;
            default:
                break;
        }
    }
    

};
AllyBuffAction* AllyActionData::castToAllyBuffAction(){
        return dynamic_cast<AllyBuffAction*>(this);
}
#endif