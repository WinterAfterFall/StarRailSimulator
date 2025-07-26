#ifndef AllyAttackAction_H
#define AllyAttackAction_H
#include "AllyActionData.h"


class Attacking{
    public : 
    SubUnit* attacker = nullptr;
    vector<AType> actionTypeList;
    vector<AType> damageTypeList;

    Attacking(SubUnit* attacker,vector<AType> abilityList)
        : attacker(attacker), actionTypeList(abilityList),damageTypeList(abilityList) {}
    Attacking(SubUnit* attacker,vector<AType> abilityList,vector<AType> damageTypeList)
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

    vector<AType> damageTypeList;//
    vector<Attacking> AttackSetList;//
    vector<SwitchAtk> switchAttacker;
    vector<Enemy*> targetList;

    ElementType Damage_element;//Physical Fire Ice Lightning Wind Quantum Imaginary

    #pragma region constructor
    AllyAttackAction(){}
    AllyAttackAction(AType actionType,SubUnit* ptr,string traceType,string name)
    {
        Attacker = ptr;
        source = ptr;
        this->actionName = name;
        Damage_element = ptr->Element_type[0];
        this->traceType = traceType;
        setupActionType(actionType);
        AttackSetList.emplace_back(Attacking(ptr,this->actionTypeList));
    }
    AllyAttackAction(AType actionType,SubUnit* ptr,string traceType,string name,function<void(shared_ptr<AllyAttackAction> &act)> actionFunction)
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
    void setupActionType(AType actionType){
        switch(actionType) {
            case AType::BA:
                actionTypeList.push_back(AType::BA);
                Turn_reset = true;
                break;
            case AType::SKILL:
                actionTypeList.push_back(AType::SKILL);
                Turn_reset = true;
                break;
            case AType::Ult:
                actionTypeList.push_back(AType::Ult);
                break;
            case AType::Fua:
                actionTypeList.push_back(AType::Fua);
                break;
            case AType::Dot:
                actionTypeList.push_back(AType::Dot);
                break;
            case AType::Break:
                actionTypeList.push_back(AType::Break);
                toughnessAvgCalculate = 0;
                break;
            case AType::SPB:
                actionTypeList.push_back(AType::SPB);
                toughnessAvgCalculate = 0;
                break;
            case AType::Addtional:
                actionTypeList.push_back(AType::Addtional);
                break;
            case AType::Technique:
                actionTypeList.push_back(AType::Technique);
                toughnessAvgCalculate = 0;
                break;
            case AType::Freeze:
                actionTypeList.push_back(AType::Freeze);
                toughnessAvgCalculate = 0;
                break;
            case AType::Entanglement:
                actionTypeList.push_back(AType::Entanglement);
                toughnessAvgCalculate = 0;
                break;
            default:
                break;
        }
    }
    public :
    #pragma endregion

    #pragma region checkMethod
    //check แค่ว่าตัวหลักตัวเดียวกันไหม
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
    bool isSameAttack(AType ability){
        for(auto &each : actionTypeList){
            if(each == ability)return true;
        }  
        return false;    
    }
    bool isSameAttack(SubUnit *ptr,AType ability){
        if(this->Attacker->isSameUnit(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
        return false;    
    }
    bool isSameAttack(Ally *ptr,AType ability){
        if(ptr->isSameAlly(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }        
        return false;    
    }
    bool isSameAttack(string name,AType ability){
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
        AttackSetList[1].actionTypeList.push_back(AType::Summon);
        AttackSetList[1].damageTypeList.push_back(AType::Summon);
    }
    virtual void addActionType(AType actionType){
        switch(actionType) {
            case AType::BA:
                actionTypeList.push_back(AType::BA);
                AttackSetList[0].actionTypeList.emplace_back(AType::BA);
                break;
            case AType::SKILL:
                actionTypeList.push_back(AType::SKILL);
                AttackSetList[0].actionTypeList.emplace_back(AType::SKILL);
                break;
            case AType::Ult:
                actionTypeList.push_back(AType::Ult);
                AttackSetList[0].actionTypeList.emplace_back(AType::Ult);
                break;
            case AType::Fua:
                actionTypeList.push_back(AType::Fua);
                AttackSetList[0].actionTypeList.emplace_back(AType::Fua);
                break;
            case AType::Dot:
                actionTypeList.push_back(AType::Dot);
                AttackSetList[0].actionTypeList.emplace_back(AType::Dot);
                break;
            case AType::Break:
                actionTypeList.push_back(AType::Break);
                AttackSetList[0].actionTypeList.emplace_back(AType::Break);
                break;
            case AType::SPB:
                actionTypeList.push_back(AType::SPB);
                AttackSetList[0].actionTypeList.emplace_back(AType::SPB);
                break;
            case AType::Addtional:
                actionTypeList.push_back(AType::Addtional);
                AttackSetList[0].actionTypeList.emplace_back(AType::Addtional);
                break;
            case AType::Technique:
                actionTypeList.push_back(AType::Technique);
                AttackSetList[0].actionTypeList.emplace_back(AType::Technique);
                break;
            case AType::Freeze:
                actionTypeList.push_back(AType::Freeze);
                AttackSetList[0].actionTypeList.emplace_back(AType::Freeze);
                break;
            case AType::Entanglement:
                actionTypeList.push_back(AType::Entanglement);
                AttackSetList[0].actionTypeList.emplace_back(AType::Entanglement);
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
        
    void addDamageInsByDebuff(DmgSrc dmgsrc,string debuffName){
        for(int i = 1;i<= Total_enemy;i++){
            if(!Enemy_unit[i]->getDebuff(debuffName)){
                addDamageIns(dmgsrc,Enemy_unit[i].get());
                return;
            }
        }
        addDamageIns(dmgsrc);
    }

    void addDamageInsByDebuff(DmgSrc dmgsrc,string debuffName,int max){
        for(int i = 1;i<= Total_enemy&&i<=max;i++){
            if(!Enemy_unit[i]->getDebuff(debuffName)){
                addDamageIns(dmgsrc,Enemy_unit[i].get());
                return;
            }
        }
        addDamageIns(dmgsrc);
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
        if(!Attacker->isExsited())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
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