#ifndef AllyAttackAction_H
#define AllyAttackAction_H
#include "AllyActionData.h"



class AllyAttackAction : public AllyActionData {
    public:
    class SwitchAtk{
    public : 
    SubUnit* attacker = nullptr;
    SubUnit* source = nullptr;
    int changeWhen = 0;
    int changeSkillType = 0;
    SwitchAtk(int changeWhen , SubUnit* attacker)
        : attacker(attacker), source(attacker), changeWhen(changeWhen) {}
    SwitchAtk(int changeWhen , SubUnit* attacker, SubUnit* source)
        : attacker(attacker), source(source), changeWhen(changeWhen) {}

    SwitchAtk(int changeWhen , SubUnit* attacker,int changeSkillType)
        : attacker(attacker), source(attacker), changeWhen(changeWhen), changeSkillType(changeSkillType) {}
    SwitchAtk(int changeWhen , SubUnit* attacker, SubUnit* source,int changeSkillType)
        : attacker(attacker), source(source), changeWhen(changeWhen), changeSkillType(changeSkillType) {}

    };
    
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    double Dont_care_weakness = 0;

    DamageSplit damageSplit;

    vector<Enemy*> targetList;
    vector<SwitchAtk> switchAttacker;
    vector<SubUnit*> attackerList;//

    string Damage_element = "";//Physical Fire Ice Lightning Wind Quantum Imaginary


    void addDamageIns(DmgSrc main,DmgSrc adjacent,DmgSrc other){
            damageSplit.emplace_back();
            for(int i = 1;i<= Total_enemy;i++){
                if(Enemy_unit[i]->Target_type == "Main")
                    damageSplit.back().emplace_back(main, Enemy_unit[i].get());
                else if(Enemy_unit[i]->Target_type == "Adjacent")
                    damageSplit.back().emplace_back(adjacent, Enemy_unit[i].get());
                else
                    damageSplit.back().emplace_back(other, Enemy_unit[i].get());
            }

    }
    public:
        template<typename... Args>
        void addDamageIns(Args... args) {
            static_assert(sizeof...(Args) % 2 == 0, "ต้องส่ง argument เป็นคู่ DmgSrc, Enemy*");

            damageSplit.emplace_back();
            auto& row = damageSplit.back();

            addPairs(row, args...);
        }

    private:
        // recursive function เพื่อประมวลผล args ทีละ 2 ตัว
        void addPairs(std::vector<Damage>&) {} // base case

        template<typename D, typename E, typename... Rest>
        void addPairs(std::vector<Damage>& row, D dmg, E* enemy, Rest... rest) {
            static_assert(std::is_same_v<D, DmgSrc>, "expected DmgSrc");
            static_assert(std::is_same_v<E*, Enemy*>, "expected Enemy*");

            row.emplace_back(dmg, enemy);
            addPairs(row, rest...); // ทำซ้ำ
        }
        
    public:
    void addDamage(DmgSrc dmgSrc,Enemy* target){
        damageSplit.back().emplace_back(dmgSrc, target);
    }

    #pragma region addEnemyTarget
    void addToActionBar(){
        std::shared_ptr<AllyActionData> self = shared_from_this();
        if(this->traceType == "Bounce"){
            Action_bar.push(self);
            return;
        }
        vector<bool> check(Total_enemy, false);
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                if (dmg.target == nullptr)continue;
                if(check[dmg.target->Atv_stats->Unit_num])continue; // สมมติว่า Enemy มี field index
                check[dmg.target->Atv_stats->Unit_num] = true;
                targetList.emplace_back(dmg.target);
                
            }
        }
        Action_bar.push(self);
    }
    void addEnemyBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= Total_enemy;i++){
                if(Enemy_unit[i]->Target_type == "Main"||(Enemy_unit[i]->Target_type == "Adjacent"&&!bestBounce))
                    this->targetList.push_back(Enemy_unit[i].get());
        }
        for(int i = 0;i< amount;i++){
                damageSplit.emplace_back();
                damageSplit.back().emplace_back(ins,targetList[i%targetList.size()]);
        }
    }
    void addEnemyFairBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= Total_enemy;i++){
                if(!bestBounce||Enemy_unit[i]->Target_type == "Main")
                    this->targetList.push_back(Enemy_unit[i].get());
        }
        for(int i = 0;i< amount;i++){
                damageSplit.emplace_back();
                damageSplit.back().emplace_back(ins,targetList[i%targetList.size()]);
        }

    }

    #pragma endregion

    #pragma region setAction
    AllyAttackAction(){}
    AllyAttackAction(ActionType actionType,SubUnit* ptr,string traceType,string name,function<void(shared_ptr<AllyActionData> &data_)> actionFunction)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        attackerList.push_back(ptr);
        Damage_element = ptr->Element_type[0];
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
                toughnessAvgCalculate = 0;
                break;
            case ActionType::SUPER_BREAK:
                abilityType.push_back(AT_SPB);
                toughnessAvgCalculate = 0;
                break;
            case ActionType::ADDITIONAL:
                abilityType.push_back(AT_ADD);
                break;
            case ActionType::TECHNIQUE:
                abilityType.push_back(AT_TECH);
                toughnessAvgCalculate = 0;
                break;
            case ActionType::FREEZE:
                abilityType.push_back("Freeze");
                toughnessAvgCalculate = 0;
                break;
            case ActionType::ENTANGLEMENT:
                abilityType.push_back("Entanglement");
                toughnessAvgCalculate = 0;
                break;
            default:
                break;
        }
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
AllyAttackAction* AllyActionData::castToAllyAttackAction(){
        return dynamic_cast<AllyAttackAction*>(this);
}

#endif