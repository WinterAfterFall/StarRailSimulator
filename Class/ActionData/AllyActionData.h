#ifndef AllyActionData_H
#define AllyActionData_H
#include "ActionData.h"

class AllyActionData : public ActionData, public std::enable_shared_from_this<AllyActionData> {
    public:
    bool Turn_reset = 0;
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    function<void(shared_ptr<AllyActionData> &data_)> actionFunction;
    double Dont_care_weakness =0;
    SubUnit* Attacker = nullptr;
    SubUnit* source = nullptr; 
    vector<SubUnit*> Target_Buff;
    vector<Enemy*> Target_Attack;
    Hit_spilt Damage_spilt;
    vector<AttackSource> switchAttacker;
    vector<SubUnit*> attackerList;//

    pair<string,string> Action_type;//Attack Buff//Skill Basic_Attack Ultimate

    vector<string> Buff_type;//Buff Shield 
    vector<string> Skill_Type;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string Damage_element = "";//Physical Fire Ice Lightning Wind Quantum Imaginary

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
    void Add_Target(Enemy* ptr){
        Target_Attack.push_back(ptr);
    }
    void Add_Target_Main(){
        for(int i=1;i<=Total_enemy;i++){
            if(Enemy_unit[i]->Target_type=="Main"){
                Target_Attack.push_back(Enemy_unit[i].get());
                return;
            }
        }
    }
    void Add_Target_Adjacent(){
        for(int i=1;i<=Total_enemy;i++){
            if(Enemy_unit[i]->Target_type!="Other"){
                Target_Attack.push_back(Enemy_unit[i].get());
            }
        }
    }
    void Add_Target_Other(){
        for(int i=1;i<=Total_enemy;i++){
            Target_Attack.push_back(Enemy_unit[i].get());
            
        }
    }
    void Add_Target_Bounce(int amount,Ratio_data instanceRatio){
        this->Add_Target_Adjacent();
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
    void Add_Target_FairBounce(int amount,Ratio_data instanceRatio){
        this->Add_Target_Other();
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
    void Basic_Attack_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Basic_Attack";
        Skill_Type.push_back("Basic_Attack");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Basic_Attack_set(SubUnit* ptr, string target_type, string buff_type, string name) {
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
    void Skill_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Skill";
        Skill_Type.push_back("Skill");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Skill_set(SubUnit* ptr, string target_type, string buff_type, string name) {
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
    void Ultimate_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Ultimate";
        Skill_Type.push_back("Ultimate");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Ultimate_set(SubUnit* ptr, string target_type, string buff_type, string name) {
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
    void Fua_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Fua";
        Skill_Type.push_back("Fua");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Fua_set(SubUnit* ptr, string target_type, string buff_type, string name) {
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
    void Additional_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Additional";
        Skill_Type.push_back("Additional");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Dot_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Dot";
        Skill_Type.push_back("Dot");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Technique_set(SubUnit* ptr, string target_type, string name) {
        Attacker = ptr;
        source = ptr;
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Action_type.first = "Attack";
        Action_type.second = "Technique";
        Skill_Type.push_back("Technique");
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void Technique_set(SubUnit* ptr, string target_type, string buff_type, string name) {
        Attacker = ptr;
        source = ptr;
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Technique";
        Skill_Type.push_back("Technique");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    // void createHealRatio(){
    //     this->healPtr = make_shared<Heal_data>();
    //     this->healPtr->Combat_dataPtr = this;
    // }
    void turnResetTrue(){
        this->Turn_reset = true;
    }
    void setToughnessAvgCalculate(bool arg){
        this->toughnessAvgCalculate = arg;
    }
    void setDamageNote(bool arg){
        this->damageNote = arg;
    }
    void Entanglement_set(SubUnit* ptr){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Entanglement");
        Damage_element = "Quantum";

        Action_type.first = "Attack";
        Action_type.second = "Entanglement";
        traceType = "Single_target";
        actionName = "Entanglement";

    }
    void Freeze_set(SubUnit* ptr){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Freeze");
        Damage_element = "Ice";

        Action_type.first = "Attack";
        Action_type.second = "Freeze";
        traceType = "Single_target";
        actionName = "Freeze";

    }
    void SuperBreak_set(SubUnit* ptr,string target_type){
        Attacker = ptr;
        source = ptr;
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Break_dmg");
        Skill_Type.push_back("Super_break");
        Damage_element = ptr->Element_type[0];
        Action_type.first = "Attack";
        Action_type.second = "Super_break";
        traceType =target_type;
        actionName = "SuperBreak";

    }
    void Break_dmg_set(SubUnit* ptr,string name){
        Attacker = ptr;
        source = ptr; 
        toughnessAvgCalculate = 0;
        attackerList.push_back(ptr);
        Skill_Type.push_back("Break_dmg");
        Damage_element = ptr->Element_type[0];
        Action_type.first = "Attack";
        Action_type.second = "Break_dmg";
        traceType ="Single_target";
        actionName = name;

    }
};


AllyActionData* ActionData::castToAllyActionData(){
        return dynamic_cast<AllyActionData*>(this);
}


#endif