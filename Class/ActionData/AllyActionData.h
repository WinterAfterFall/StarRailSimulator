#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    
    function<void(shared_ptr<AllyActionData> &data_)> actionFunction;
    
    vector<SubUnit*> Target_Buff;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    


    vector<string> Buff_type;//Buff Shield 
    vector<string> Skill_Type;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional

    string traceType = "";// Aoe Single_target Bounce


    
    void AllyAction();

    void Add_Buff_Single_Target(SubUnit* ptr){
        Target_Buff.push_back(ptr);
    }
    void Add_Buff_Single_Target(Ally* ptr){
        for(auto &e:ptr->Sub_Unit_ptr){
            Target_Buff.push_back(e.get());
        }
    }
    void Add_Buff_All_Ally(){
        
        for(int i=1;i<=Total_ally;i++){
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr){
                Target_Buff.push_back(e.get());
            }
        }
    }
    
    
    
    void setBasicAttack(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Basic_Attack";
        Skill_Type.push_back("Basic_Attack");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    
    void setSkill(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Skill";
        Skill_Type.push_back("Skill");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    
    void setUltimate(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Ultimate";
        Skill_Type.push_back("Ultimate");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    
    void setFua(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Fua";
        Skill_Type.push_back("Fua");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    
    void setTechnique(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Technique";
        Skill_Type.push_back("Technique");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    
    
};


AllyActionData* ActionData::castToAllyActionData(){
        return dynamic_cast<AllyActionData*>(this);
}


#endif