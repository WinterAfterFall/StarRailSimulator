#ifndef ALLY_SUPPORT_ACTION_H
#define ALLY_SUPPORT_ACTION_H
#include "AllyActionData.h"

class AllyBuffAction : public AllyActionData {
    public:
    vector<AllyUnit*> buffTargetList;
    function<void(shared_ptr<AllyBuffAction> &act)> actionFunction;


    private :
    void setupActionType(AType actionType){
        switch(actionType) {
            case AType::BA:
                actionTypeList.push_back(AType::BA);
                turnReset = true;
                break;
            case AType::SKILL:
                actionTypeList.push_back(AType::SKILL);
                turnReset = true;
                break;
            case AType::ULT:
                actionTypeList.push_back(AType::ULT);
                break;
            case AType::FUA:
                actionTypeList.push_back(AType::FUA);
                break;
            case AType::DOT:
                actionTypeList.push_back(AType::DOT);
                break;
            case AType::BREAK:
                actionTypeList.push_back(AType::BREAK);
                break;
            case AType::SPB:
                actionTypeList.push_back(AType::BREAK);
                actionTypeList.push_back(AType::SPB);
                break;
            case AType::ELATION_SKILL:
                actionTypeList.push_back(AType::ELATION_SKILL);
                actionTypeList.push_back(AType::ELATION_DMG);
                break;
            case AType::ELATION_DMG:
                actionTypeList.push_back(AType::ELATION_DMG);
                break;
            case AType::ADDTIONAL:
                actionTypeList.push_back(AType::ADDTIONAL);
                break;
            case AType::TECHNIQUE:
                actionTypeList.push_back(AType::TECHNIQUE);
                break;
            case AType::FREEZE:
                actionTypeList.push_back(AType::FREEZE);
                break;
            case AType::ENTANGLEMENT:
                actionTypeList.push_back(AType::ENTANGLEMENT);
                break;
            default:
                break;
        }
    }
    public :

    void addBuffSingleTarget(){
        buffTargetList.push_back(chooseAllyBuff(attacker));
    }

    void addBuffSingleTarget(AllyUnit* ptr){
        buffTargetList.push_back(ptr);
    }
    void addBuffChar(CharUnit* ptr){
        if(ptr->getType() != UnitType::OUT_OF_BOUNDS)buffTargetList.push_back(ptr);
        if(auto *e = ptr->memosprite.get()){
            if(e->getType() != UnitType::OUT_OF_BOUNDS)buffTargetList.push_back(e);
        }
    }
    void addBuffAllAllies(){
        for(int i=1;i<=totalAlly;i++){
            if(charUnit[i]->getType() != UnitType::OUT_OF_BOUNDS)
                buffTargetList.push_back(charUnit[i].get());\

            if(auto *e = charUnit[i]->memosprite.get()){
                if(e->getType() != UnitType::OUT_OF_BOUNDS)
                    buffTargetList.push_back(e);
            }
        }
    }
    void addToActionBar(){
        if(!attacker->isExisted())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        actionBar.push(self);
    }
    AllyBuffAction(){}
    AllyBuffAction(AType actionType,AllyUnit* ptr,TraceType traceType, string name)
    {
        attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->traceType = traceType;
        setupActionType(actionType);
    }
    AllyBuffAction(AType actionType,AllyUnit* ptr,TraceType traceType, string name,function<void(shared_ptr<AllyBuffAction> &act)> actionFunction)
    {
        attacker = ptr;
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
