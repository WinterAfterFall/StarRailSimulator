#ifndef ACTION_DATA_H
#define ACTION_DATA_H
#include "StatsSet.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

class PointerWithValue{
    public : 
    SubUnit* ptr;
    double value = 0;

    PointerWithValue(SubUnit *ptr ,double value) : ptr(ptr),value(value){

    }

    static bool Less_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value < r.value;  // Higher priority first
    }
    static bool Greater_cmp(const PointerWithValue& l, const PointerWithValue& r) {
        return l.value > r.value;  // Higher priority first
    }
};
class AttackSource{
    public : 
    SubUnit* attacker = nullptr;
    SubUnit* source = nullptr;
    int changeWhen = 0;
    AttackSource(int changeWhen , SubUnit* attacker)
        : attacker(attacker), source(attacker), changeWhen(changeWhen) {}
    AttackSource(int changeWhen , SubUnit* attacker, SubUnit* source)
        : attacker(attacker), source(source), changeWhen(changeWhen) {}

};
class HealRatio{
    public :
    double ATK = 0;
    double HP = 0;
    double DEF = 0;
    double healFromTotalHP = 0;
    double healFromLostHP = 0;
    double fixHeal = 0;
    void setRatio(double Atk,double Hp,double Def,double fixHeal,double healFromTotalHP,double healFromLostHP){
        this->ATK = Atk;
        this->HP = Hp;
        this->DEF = Def;
        this->fixHeal = fixHeal;
        this->healFromTotalHP = healFromTotalHP;
        this->healFromLostHP = healFromLostHP;
    }

};
class Heal_data{
    public :
    
    SubUnit* Healer = nullptr; //
    HealRatio main;
    HealRatio adjacent;
    HealRatio other;
    // ActionData *Combat_dataPtr = nullptr;
    void setHealer(SubUnit* ptr){   
        this->Healer = ptr;
    }


};
class Ratio_data{
    public:
    double Atk_ratio;
    double Hp_ratio;
    double Def_ratio;
    double Toughness_ratio;
};
class Hit_spilt{
    public:
    vector<Ratio_data> Main;
    vector<Ratio_data> Adjacent;
    vector<Ratio_data> Other;
};
class ActionData{
    public:
    bool Turn_reset = 0;
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    function<void(ActionData &data_)> actionFunction;
    double Dont_care_weakness =0;
    SubUnit* Attacker = nullptr; 
    SubUnit* source = nullptr; 
    vector<SubUnit*> Target_Buff;
    vector<Enemy*> Target_Attack;
    Hit_spilt Damage_spilt;
    vector<AttackSource> Joint;
    int Attack_trigger = 1; 
    vector<SubUnit*> All_Attacker;//

    pair<string,string> Action_type;//Attack Buff//Skill Basic_Attack Ultimate

    vector<string> Buff_type;//Buff Shield 
    vector<string> Skill_Type;//  None Basic_Attack Skill Ultimate  Dot  Fua  Summon  Break_dmg  Super_break Additional
    string Damage_element = "";//Physical Fire Ice Lightning Wind Quantum Imaginary

    string traceType = "";// Aoe Single_target Bounce
    shared_ptr<Heal_data> healPtr;

    string actionName = "";

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
        if(extra>=1)
        this->Damage_spilt.Main.push_back(instanceRatio);
        else return;

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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
        Action_type.first = "Buff";
        Action_type.second = "Technique";
        Skill_Type.push_back("Technique");
        Buff_type.push_back(buff_type);
        Damage_element = ptr->Element_type[0];
        traceType = target_type;
        actionName = name;
    }
    void createHealRatio(){
        this->healPtr = make_shared<Heal_data>();
        // this->healPtr->Combat_dataPtr = this;
    }
    void resetTurn(){
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
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
        All_Attacker.push_back(ptr);
        Skill_Type.push_back("Break_dmg");
        Damage_element = ptr->Element_type[0];
        Action_type.first = "Attack";
        Action_type.second = "Break_dmg";
        traceType ="Single_target";
        actionName = name;

    }
};


#endif