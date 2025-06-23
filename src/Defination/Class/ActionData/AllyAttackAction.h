#ifndef AllyAttackAction_H
#define AllyAttackAction_H
#include "AllyActionData.h"


class Attacking{
    public : 
    SubUnit* attacker = nullptr;
    vector<string> actionTypeList;
    vector<string> damageTypeList;

    Attacking(SubUnit* attacker,vector<string> abilityList)
        : attacker(attacker), actionTypeList(abilityList),damageTypeList(abilityList) {}
    Attacking(SubUnit* attacker,vector<string> abilityList,vector<string> damageTypeList)
        : attacker(attacker), actionTypeList(abilityList),damageTypeList(damageTypeList) {}
    
};
class SwitchAtk{
    public : 
    SubUnit* source = nullptr;
    int changeWhen = -1;
    int changeTo = -1;
    SwitchAtk(int changeTo,int changeWhen)
        : changeTo(changeTo), changeWhen(changeWhen) {}
    SwitchAtk(int changeTo, SubUnit* source,int changeWhen)
        : changeTo(changeTo), source(source), changeWhen(changeWhen) {}
};

class AllyAttackAction : public AllyActionData {
    public:
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    double Dont_care_weakness = 0;
    function<void(shared_ptr<AllyAttackAction> &act)> actionFunction;

    DamageSplit damageSplit;

    vector<string> damageTypeList;//
    vector<Attacking> AttackSetList;//
    vector<SwitchAtk> switchAttacker;
    vector<Enemy*> targetList;

    ElementType Damage_element;//Physical Fire Ice Lightning Wind Quantum Imaginary

    #pragma region constructor
    AllyAttackAction(){}
    AllyAttackAction(ActionType actionType,SubUnit* ptr,string traceType,string name)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        Damage_element = ptr->Element_type[0];
        this->traceType = traceType;
        setupActionType(actionType);
        AttackSetList.emplace_back(Attacking(ptr,this->actionTypeList));
    }
    AllyAttackAction(ActionType actionType,SubUnit* ptr,string traceType,string name,function<void(shared_ptr<AllyAttackAction> &act)> actionFunction)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        Damage_element = ptr->Element_type[0];
        this->traceType = traceType;
        setupActionType(actionType);
        AttackSetList.emplace_back(Attacking(ptr,this->actionTypeList));
    }

    private :
    void setupActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BA:
                actionTypeList.push_back(AT_BA);
                Turn_reset = true;
                break;
            case ActionType::SKILL:
                actionTypeList.push_back(AT_SKILL);
                Turn_reset = true;
                break;
            case ActionType::Ult:
                actionTypeList.push_back(AT_ULT);
                break;
            case ActionType::Fua:
                actionTypeList.push_back(AT_FUA);
                break;
            case ActionType::Dot:
                actionTypeList.push_back(AT_DOT);
                break;
            case ActionType::Break:
                actionTypeList.push_back(AT_BREAK);
                toughnessAvgCalculate = 0;
                break;
            case ActionType::SPB:
                actionTypeList.push_back(AT_SPB);
                toughnessAvgCalculate = 0;
                break;
            case ActionType::Addtional:
                actionTypeList.push_back(AT_ADD);
                break;
            case ActionType::Technique:
                actionTypeList.push_back(AT_TECH);
                toughnessAvgCalculate = 0;
                break;
            case ActionType::Freeze:
                actionTypeList.push_back("Freeze");
                toughnessAvgCalculate = 0;
                break;
            case ActionType::Entanglement:
                actionTypeList.push_back("Entanglement");
                toughnessAvgCalculate = 0;
                break;
            default:
                break;
        }
    }
    public :
    #pragma endregion


    #pragma region checkMethod
    bool isSameAtker(SubUnit *ptr){
        if(this->Attacker->isSameUnit(ptr))return true;
        return false;
    }
    bool isSameAtker(Ally *ptr){
        if(ptr->isSameAlly(this->Attacker))return true;
        return false;
    }
    bool isSameAtkerName(string name){
        if(this->Attacker->isSameUnitName(name))return true;
        return false;
    }
    bool isSameAttack(string ability){
        for(auto &each : actionTypeList){
            if(each == ability)return true;
        }  
        return false;    
    }
    bool isSameAttack(SubUnit *ptr,string ability){
        if(this->Attacker->isSameUnit(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }
    bool isSameAttack(Ally *ptr,string ability){
        if(ptr->isSameAlly(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }
    bool isSameAttack(string name,string ability){
        if(this->Attacker->isSameUnitName(name)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }



    #pragma endregion

    void setJoint() {
        AttackSetList.emplace_back(Attacking(Attacker->ptrToChar->getSubUnit(1),this->actionTypeList));
        AttackSetList[1].actionTypeList.push_back("Summon");
        AttackSetList[1].damageTypeList.push_back("Summon");
    }
    virtual void addActionType(ActionType actionType){
        switch(actionType) {
            case ActionType::BA:
                actionTypeList.push_back(AT_BA);
                AttackSetList[0].actionTypeList.emplace_back(AT_BA);
                break;
            case ActionType::SKILL:
                actionTypeList.push_back(AT_SKILL);
                AttackSetList[0].actionTypeList.emplace_back(AT_SKILL);
                break;
            case ActionType::Ult:
                actionTypeList.push_back(AT_ULT);
                AttackSetList[0].actionTypeList.emplace_back(AT_ULT);
                break;
            case ActionType::Fua:
                actionTypeList.push_back(AT_FUA);
                AttackSetList[0].actionTypeList.emplace_back(AT_FUA);
                break;
            case ActionType::Dot:
                actionTypeList.push_back(AT_DOT);
                AttackSetList[0].actionTypeList.emplace_back(AT_DOT);
                break;
            case ActionType::Break:
                actionTypeList.push_back(AT_BREAK);
                AttackSetList[0].actionTypeList.emplace_back(AT_BREAK);
                break;
            case ActionType::SPB:
                actionTypeList.push_back(AT_SPB);
                AttackSetList[0].actionTypeList.emplace_back(AT_SPB);
                break;
            case ActionType::Addtional:
                actionTypeList.push_back(AT_ADD);
                AttackSetList[0].actionTypeList.emplace_back(AT_ADD);
                break;
            case ActionType::Technique:
                actionTypeList.push_back(AT_TECH);
                AttackSetList[0].actionTypeList.emplace_back(AT_TECH);
                break;
            case ActionType::Freeze:
                actionTypeList.push_back("Freeze");
                AttackSetList[0].actionTypeList.emplace_back("Freeze");
                break;
            case ActionType::Entanglement:
                actionTypeList.push_back("Entanglement");
                AttackSetList[0].actionTypeList.emplace_back("Entanglement");
                break;
            default:
                break;
        }
    }

    

    //act->addDamageIns(DmgSrc(DmgSrcType::ATK,120,6));
    void addDamageIns(DmgSrc main){
            damageSplit.emplace_back();
            for(int i = 1;i<= Total_enemy;i++){
                if(Enemy_unit[i]->Target_type == "Main"){
                    damageSplit.back().emplace_back(main, Enemy_unit[i].get());
                    break;
                }
            }
    }
    /**
     * Example usage:
     *   act->addDamageIns(
     *       DmgSrc(DmgSrcType::ATK,120,6),
     *       DmgSrc(DmgSrcType::ATK,120,6)
     *   );
     *
     * @brief Add damage for main, adjacent, and other targets.
     * @param main Damage for main target.
     * @param adjacent Damage for adjacent targets.
     */
    void addDamageIns(DmgSrc main,DmgSrc adjacent){
            damageSplit.emplace_back();
            for(int i = 1;i<= Total_enemy;i++){
                if(Enemy_unit[i]->Target_type == "Main")
                    damageSplit.back().emplace_back(main, Enemy_unit[i].get());
                else if(Enemy_unit[i]->Target_type == "Adjacent")
                    damageSplit.back().emplace_back(adjacent, Enemy_unit[i].get());
            }

    }
    /**
     * Example usage:
     *   act->addDamageIns(
     *       DmgSrc(DmgSrcType::ATK,120,6),
     *       DmgSrc(DmgSrcType::ATK,120,6),
     *       DmgSrc(DmgSrcType::ATK,120,6)
     *   );
     *
     * @brief Add damage for main, adjacent, and other targets.
     * @param main Damage for main target.
     * @param adjacent Damage for adjacent targets.
     * @param other Damage for other targets.
     */
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
    void addDamageHit(DmgSrc dmgSrc,Enemy* target){
        damageSplit.back().emplace_back(dmgSrc, target);
    }

    void addDamage(DmgSrcType type,double value){
        for(auto &each : damageSplit){
            for(auto &dmg : each){
                if(type == DmgSrcType::ATK)
                    dmg.dmgSrc.ATK += value;
                else if(type == DmgSrcType::HP)
                    dmg.dmgSrc.HP += value;
                else if(type == DmgSrcType::DEF)
                    dmg.dmgSrc.DEF += value;
                else if(type == DmgSrcType::CONST)
                    dmg.dmgSrc.constDmg += value;
            }
        }
    }
    

    #pragma region addEnemyTarget
    void addToActionBar(){
        std::shared_ptr<AllyActionData> self = shared_from_this();
        if(this->traceType == "Bounce"){
            Action_bar.push(self);
            return;
        }
        vector<bool> check(Total_enemy+1, false);
        for(auto &e : targetList){
            check[e->Atv_stats->num] = true;
        }
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                if (dmg.target == nullptr)continue;
                if(check[dmg.target->Atv_stats->num])continue; // สมมติว่า Enemy มี field index
                check[dmg.target->Atv_stats->num] = true;
                targetList.emplace_back(dmg.target);
                
            }
        }
        Action_bar.push(self);
    }
    void addEnemyBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= Total_enemy&&i<= amount;i++){
                if(Enemy_unit[i]->Target_type == "Main"||(Enemy_unit[i]->Target_type == "Adjacent"&&!bestBounce))
                    this->targetList.push_back(Enemy_unit[i].get());
        }
        for(int i = 0;i< amount;i++){
                damageSplit.emplace_back();
                damageSplit.back().emplace_back(ins,targetList[i%targetList.size()]);
        }
    }
    void addEnemyFairBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= Total_enemy&&i<= amount;i++){
                    this->targetList.push_back(Enemy_unit[i].get());
        }
        for(int i = 0;i< amount;i++){
                damageSplit.emplace_back();
                damageSplit.back().emplace_back(ins,targetList[i%targetList.size()]);
        }

    }

    #pragma endregion
    void multiplyDmg(double value){
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                dmg.dmgSrc.ATK *=value/100;
                dmg.dmgSrc.HP *=value/100;
                dmg.dmgSrc.DEF *=value/100;
                dmg.dmgSrc.constDmg *=value/100;
            }
        }

    }

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