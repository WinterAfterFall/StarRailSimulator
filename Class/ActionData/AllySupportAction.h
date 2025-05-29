#ifndef AllySupportAction_H
#define AllySupportAction_H
#include "AllyActionData.h"

class AllySupportAction : public AllyActionData {
    public:
    vector<SubUnit*> buffTargetList;
    vector<string> buffType;//Buff Shield 

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
    AllySupportAction(){}
    AllySupportAction(ActionType actionType,SubUnit* ptr,string traceType, string name,function<void(shared_ptr<AllyActionData> &data_)> actionFunction)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        this->traceType = traceType;
        addActionType(actionType);
    }
    void addActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BASIC_ATTACK:
                abilityType.push_back(AT_BA);
                break;
            case ActionType::SKILL:
                abilityType.push_back(AT_SKILL);
                break;
            case ActionType::ULTIMATE:
                abilityType.push_back(AT_ULT);
                break;
            case ActionType::FUA:
                abilityType.push_back(AT_FUA);
                break;
            case ActionType::DOT:
                abilityType.push_back(AT_DOT);
                break;
            case ActionType::BREAK_DMG:
                abilityType.push_back(AT_BREAK);
                break;
            case ActionType::SUPER_BREAK:
                abilityType.push_back(AT_SPB);
                break;
            case ActionType::ADDITIONAL:
                abilityType.push_back(AT_ADD);
                break;
            case ActionType::TECHNIQUE:
                abilityType.push_back(AT_TECH);
                break;
            case ActionType::FREEZE:
                abilityType.push_back("Freeze");
                break;
            case ActionType::ENTANGLEMENT:
                abilityType.push_back("Entanglement");
                break;
            default:
                break;
        }
    }

};
AllySupportAction* AllyActionData::castToAllySupportAction(){
        return dynamic_cast<AllySupportAction*>(this);
}
#endif