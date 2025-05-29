#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    function<void(shared_ptr<AllyActionData> &data_)> actionFunction;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    vector<string> abilityType;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string traceType = "";// Aoe Single_target Bounce
    


    
    
    void AllyAction();
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    
    AllyAttackAction* castToAllyAttackAction();
    AllySupportAction* castToAllySupportAction();
};


AllyActionData* ActionData::castToAllyActionData(){
        return dynamic_cast<AllyActionData*>(this);
}


#endif