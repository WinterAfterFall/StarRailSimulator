#ifndef AllyAttackAction_H
#define AllyAttackAction_H
#include "AllyActionData.h"

enum class SourceType {
    ATK,
    HP,
    DEF,
    CONST,
};

class Damage{
public:
    double atkRatio = 0;
    double hpRatio = 0;
    double defRatio = 0;
    double constDamage = 0;
    double toughnessReduce = 0;
    Enemy* target = nullptr;

    Damage(){}

    Damage(SourceType type, double value, double toughnessReduce, Enemy* target)
        : target(target), toughnessReduce(toughnessReduce)
    {
        switch(type) {
            case SourceType::ATK:
                atkRatio = value;
                break;
            case SourceType::HP:
                hpRatio = value;
                break;
            case SourceType::DEF:
                defRatio = value;
                break;
            case SourceType::CONST:
                constDamage = value;
                break;    
        }
        
    }
};
typedef vector<vector<Damage>> DaamageSplit;
class AllyAttackAction : public AllyActionData {
    public:
    
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    double Dont_care_weakness = 0;

    
    vector<Enemy*> Target_Attack;
    Hit_spilt Damage_spilt;
    vector<AttackSource> switchAttacker;
    vector<SubUnit*> attackerList;//
    string Damage_element = "";//Physical Fire Ice Lightning Wind Quantum Imaginary

    #pragma region addEnemyTarget
    void addEnemyTarget(Enemy* ptr){
        Target_Attack.push_back(ptr);
    }
    // void addEnemyTarget(Enemy* ptr){
    //     Target_Attack.push_back(ptr);
    // }
    void addEnemyMainTarget(){
        for(int i=1;i<=Total_enemy;i++){
            if(Enemy_unit[i]->Target_type=="Main"){
                Target_Attack.push_back(Enemy_unit[i].get());
                return;
            }
        }
    }
    void addEnemyAdjacentTarget(){
        for(int i=1;i<=Total_enemy;i++){
            if(Enemy_unit[i]->Target_type!="Other"){
                Target_Attack.push_back(Enemy_unit[i].get());
            }
        }
    }
    void addEnemyOtherTarget(){
        for(int i=1;i<=Total_enemy;i++){
            Target_Attack.push_back(Enemy_unit[i].get());
            
        }
    }
    void addEnemyBounce(int amount,Ratio_data instanceRatio){
        this->addEnemyAdjacentTarget();
        int loop = amount/this->Target_Attack.size();
        int extra = amount%this->Target_Attack.size();
        while(loop--){
            this->Damage_spilt.Main.push_back(instanceRatio);
            this->Damage_spilt.Adjacent.push_back(instanceRatio);
        }
        while(extra--){
            this->Damage_spilt.Main.push_back(instanceRatio);
        }
    }
    void addEnemyFairBounce(int amount,Ratio_data instanceRatio){
        this->addEnemyOtherTarget();
        int loop = amount/this->Target_Attack.size();
        int extra = amount%this->Target_Attack.size();
        while(loop--){
            this->Damage_spilt.Main.push_back(instanceRatio);
            this->Damage_spilt.Adjacent.push_back(instanceRatio);
            this->Damage_spilt.Other.push_back(instanceRatio);
        }
        if(extra==0)return;

        this->Damage_spilt.Main.push_back(instanceRatio);
        if(extra==1)return;


        if(extra>2)
        this->Damage_spilt.Adjacent.push_back(instanceRatio);
        else
        this->Damage_spilt.Main.push_back(instanceRatio);

        if(extra==4)
        this->Damage_spilt.Other.push_back(instanceRatio);

    }

    #pragma endregion

    #pragma region setAction
    void setBasicAttack(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_BA);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setSkill(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_SKILL);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setUltimate(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_ULT);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setFua(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_FUA);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setAdditonal(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_ADD);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setDot(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_DOT);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setTechnique(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back(AT_TECH);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void setEntanglement(SubUnit* ptr){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Entanglement");
        Damage_element = "Quantum";

        traceType = "Single_target";
        actionName = "Entanglement";

    }
    void setFreeze(SubUnit* ptr){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Freeze");
        Damage_element = "Ice";

        traceType = "Single_target";
        actionName = "Freeze";

    }
    void setSuperBreak(SubUnit* ptr,string target_type){
        Attacker = ptr;
        source = ptr;
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Break_dmg");
        Skill_Type.push_back("Super_break");
        Damage_element = ptr->Element_type[0];
        traceType =target_type;
        actionName = "SuperBreak";

    }
    void setBreakDmg(SubUnit* ptr,string name){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Break_dmg");
        Damage_element = ptr->Element_type[0];
        traceType ="Single_target";
        actionName = name;

    }
    
    #pragma endregion

    #pragma region adjust
    void setToughnessAvgCalculate(bool arg){
        this->toughnessAvgCalculate = arg;
    }
    void setDamageNote(bool arg){
        this->damageNote = arg;
    }
    #pragma endregion
};
#endif