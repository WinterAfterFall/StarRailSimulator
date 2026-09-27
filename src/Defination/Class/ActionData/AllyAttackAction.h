#ifndef ALLY_ATTACK_ACTION_H
#define ALLY_ATTACK_ACTION_H
#include "AllyActionData.h"


class Attacking{
    public : 
    AllyUnit* attacker = nullptr;
    vector<AType> actionTypeList;
    vector<AType> damageTypeList;

    Attacking(AllyUnit* attacker,vector<AType> abilityList)
        : attacker(attacker), actionTypeList(abilityList),damageTypeList(abilityList) {}
    Attacking(AllyUnit* attacker,vector<AType> abilityList,vector<AType> damageTypeList)
        : attacker(attacker), actionTypeList(abilityList),damageTypeList(damageTypeList) {}
    
};
class SwitchAtk{
    public : 
    AllyUnit* source = nullptr; // ที่มาดาเมจ 
    int changeWhen = -1; // เลือกเวลาเปลี่ยน
    int changeTo = -1; // เลือก attackSetList
    SwitchAtk(int changeTo,int changeWhen)
        : changeTo(changeTo), changeWhen(changeWhen) {}
    SwitchAtk(int changeTo, AllyUnit* source,int changeWhen)
        : changeTo(changeTo), source(source), changeWhen(changeWhen) {}
};

class  AllyAttackAction : public AllyActionData {
    public:
    bool toughnessAvgCalculate = 1;
    bool damageNote = 1;
    double dontCareWeakness = 0;
    bool critAble = 1;
    bool critGarantee = 0;
    function<void(shared_ptr<AllyAttackAction> &act)> actionFunction;

    DamageSplit damageSplit;

    vector<AType> damageTypeList;//Record Damage Type at the moment
    vector<Attacking> attackSetList;// All Attacker Data
    vector<SwitchAtk> switchAttacker;// Recored Src Data and tell which attacker to change to
    vector<Enemy*> targetList;

    ElementType damageElement;//Physical Fire Ice Lightning Wind Quantum Imaginary

    #pragma region constructor
    AllyAttackAction(){}
    AllyAttackAction(AType actionType,AllyUnit* ptr,TraceType traceType,string name)
    {
        attacker = ptr;
        source = ptr;
        this->actionName = name;
        damageElement = ptr->elementType;
        this->traceType = traceType;
        setupActionType(actionType);
        attackSetList.emplace_back(Attacking(ptr,this->actionTypeList));
    }
    AllyAttackAction(AType actionType,AllyUnit* ptr,TraceType traceType,string name,function<void(shared_ptr<AllyAttackAction> &act)> actionFunction)
    {
        attacker = ptr;
        source = ptr;
        this->actionName = name;
        this->actionFunction = actionFunction;
        damageElement = ptr->elementType;
        this->traceType = traceType;
        setupActionType(actionType);
        attackSetList.emplace_back(Attacking(ptr,this->actionTypeList));
    }

    #pragma region SetMethod
    void setDamageElement(ElementType element) {
        damageElement = element;
    }
    #pragma endregion

    private :
    void setupActionType(AType actionType){
        switch(actionType) {
            case AType::BA:
                actionTypeList.push_back(AType::BA);
                damageTypeList.push_back(AType::BA);
                turnReset = true;
                break;
            case AType::SKILL:
                actionTypeList.push_back(AType::SKILL);
                damageTypeList.push_back(AType::SKILL);
                turnReset = true;
                break;
            case AType::ULT:
                actionTypeList.push_back(AType::ULT);
                damageTypeList.push_back(AType::ULT);
                break;
            case AType::FUA:
                actionTypeList.push_back(AType::FUA);
                damageTypeList.push_back(AType::FUA);
                break;
            case AType::DOT:
                actionTypeList.push_back(AType::DOT);
                damageTypeList.push_back(AType::DOT);
                critAble = 0;
                break;
            case AType::BREAK:
                actionTypeList.push_back(AType::BREAK);
                damageTypeList.push_back(AType::BREAK);
                toughnessAvgCalculate = 0;
                critAble = 0;
                break;
            case AType::SPB:
                actionTypeList.push_back(AType::BREAK);
                actionTypeList.push_back(AType::SPB);
                damageTypeList.push_back(AType::BREAK);
                damageTypeList.push_back(AType::SPB);
                toughnessAvgCalculate = 0;
                critAble = 0;
                break;
            case AType::ELATION_SKILL:
                actionTypeList.push_back(AType::ELATION_SKILL);
                actionTypeList.push_back(AType::ELATION_DMG);
                damageTypeList.push_back(AType::ELATION_SKILL);
                damageTypeList.push_back(AType::ELATION_DMG);
                break;
            case AType::ELATION_DMG:
                actionTypeList.push_back(AType::ELATION_DMG);
                damageTypeList.push_back(AType::ELATION_DMG);
                break;
            case AType::ADDTIONAL:
                actionTypeList.push_back(AType::ADDTIONAL);
                damageTypeList.push_back(AType::ADDTIONAL);
                break;
            case AType::TECHNIQUE:
                actionTypeList.push_back(AType::TECHNIQUE);
                damageTypeList.push_back(AType::TECHNIQUE);
                toughnessAvgCalculate = 0;
                break;
            case AType::FREEZE:
                actionTypeList.push_back(AType::FREEZE);
                damageTypeList.push_back(AType::FREEZE);
                toughnessAvgCalculate = 0;
                critAble = 0;
                break;
            case AType::ENTANGLEMENT:
                actionTypeList.push_back(AType::ENTANGLEMENT);
                damageTypeList.push_back(AType::ENTANGLEMENT);
                toughnessAvgCalculate = 0;
                critAble = 0;
                break;
            case AType::SHOCK:
                actionTypeList.push_back(AType::DOT);
                actionTypeList.push_back(AType::SHOCK);
                damageTypeList.push_back(AType::DOT);
                damageTypeList.push_back(AType::SHOCK);
                critAble = 0;
                break;
            case AType::BLEED:
                actionTypeList.push_back(AType::DOT);
                actionTypeList.push_back(AType::BLEED);
                damageTypeList.push_back(AType::DOT);
                damageTypeList.push_back(AType::BLEED);
                critAble = 0;
                break;
            case AType::WIND_SHEAR:
                actionTypeList.push_back(AType::DOT);
                actionTypeList.push_back(AType::WIND_SHEAR);
                damageTypeList.push_back(AType::DOT);
                damageTypeList.push_back(AType::WIND_SHEAR);
                critAble = 0;
                break;
            case AType::BURN:
                actionTypeList.push_back(AType::DOT);
                actionTypeList.push_back(AType::BURN);
                damageTypeList.push_back(AType::DOT);
                damageTypeList.push_back(AType::BURN);
                critAble = 0;
                break;    
            default:
                break;
        }
    }
    public :
    #pragma endregion

    #pragma region checkMethod
    //check แค่ว่าตัวหลักตัวเดียวกันไหม
    bool isSameDamageType(AType ability);
    bool isSameDamageType(AllyUnit *ptr,AType ability);
    bool isSameDamageType(string name,AType ability);
    bool isSameOwnerDamageType(CharUnit *ptr,AType ability);



    #pragma endregion

    void setJoint() {
        attackSetList.emplace_back(Attacking(attacker->owner->getMemosprite(),this->actionTypeList));
        attackSetList[1].actionTypeList.push_back(AType::SUMMON);
        attackSetList[1].damageTypeList.push_back(AType::SUMMON);
    }
    virtual void addActionType(AType actionType) override {
        actionTypeList.push_back(actionType);
        attackSetList[0].actionTypeList.emplace_back(actionType);
    }
    void addDamageType(AType actionType){
        damageTypeList.push_back(actionType);
        attackSetList[0].damageTypeList.emplace_back(actionType);
    }
    void addAttackType(AType actionType){
        actionTypeList.push_back(actionType);
        damageTypeList.push_back(actionType);
        attackSetList[0].actionTypeList.emplace_back(actionType);
        attackSetList[0].damageTypeList.emplace_back(actionType);
    }

    

    //act->addDamageIns(DmgSrc(DmgSrcType::ATK,120,6));
    void addDamageIns(DmgSrc main){
            damageSplit.emplace_back();
            for(int i = 1;i<= totalEnemy;i++){
                if(enemyUnit[i]->targetType == EnemyType::MAIN){
                    damageSplit.back().emplace_back(main, enemyUnit[i].get());
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
            for(int i = 1;i<= totalEnemy;i++){
                if(enemyUnit[i]->targetType == EnemyType::MAIN)
                    damageSplit.back().emplace_back(main, enemyUnit[i].get());
                else if(enemyUnit[i]->targetType == EnemyType::ADJACENT)
                    damageSplit.back().emplace_back(adjacent, enemyUnit[i].get());
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
            for(int i = 1;i<= totalEnemy;i++){
                if(enemyUnit[i]->targetType == EnemyType::MAIN)
                    damageSplit.back().emplace_back(main, enemyUnit[i].get());
                else if(enemyUnit[i]->targetType == EnemyType::ADJACENT)
                    damageSplit.back().emplace_back(adjacent, enemyUnit[i].get());
                else
                    damageSplit.back().emplace_back(other, enemyUnit[i].get());
            }
        }
        
    void addDamageInsByDebuff(DmgSrc dmgsrc,string debuffName){
        for(int i = 1;i<= totalEnemy;i++){
            if(!enemyUnit[i]->getDebuff(debuffName)){
                addDamageIns(dmgsrc,enemyUnit[i].get());
                return;
            }
        }
        addDamageIns(dmgsrc);
    }

    void addDamageInsByDebuff(DmgSrc dmgsrc,string debuffName,int max){
        for(int i = 1;i<= totalEnemy&&i<=max;i++){
            if(!enemyUnit[i]->getDebuff(debuffName)){
                addDamageIns(dmgsrc,enemyUnit[i].get());
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
                    dmg.dmgSrc.atk += value;
                else if(type == DmgSrcType::HP)
                    dmg.dmgSrc.hp += value;
                else if(type == DmgSrcType::DEF)
                    dmg.dmgSrc.def += value;
                else if(type == DmgSrcType::CONST)
                    dmg.dmgSrc.constDmg += value;
            }
        }
    }
    

    #pragma region addEnemyTarget
    void addEnemyToTargetList(){
        if(!attacker->isExisted())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        vector<bool> check(totalEnemy+1, false);
        for(auto &e : targetList){
            check[e->atvStats->num] = true;
        }
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                if (dmg.target == nullptr)continue;
                if(check[dmg.target->atvStats->num])continue; // สมมติว่า Enemy มี field index
                check[dmg.target->atvStats->num] = true;
                targetList.emplace_back(dmg.target);
                
            }
        }
    }
    void addToActionBar(){
        if(!attacker->isExisted())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        vector<bool> check(totalEnemy+1, false);
        for(auto &e : targetList){
            check[e->atvStats->num] = true;
        }
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                if (dmg.target == nullptr)continue;
                if(check[dmg.target->atvStats->num])continue; // สมมติว่า Enemy มี field index
                check[dmg.target->atvStats->num] = true;
                targetList.emplace_back(dmg.target);
                
            }
        }
        actionBar.push(self);
    }
    void addToAhaInstant(){
        if(!attacker->isExisted())return;
        std::shared_ptr<AllyActionData> self = shared_from_this();
        vector<bool> check(totalEnemy+1, false);
        for(auto &e : targetList){
            check[e->atvStats->num] = true;
        }
        for (size_t i = 0; i < damageSplit.size(); ++i) {
            for (size_t j = 0; j < damageSplit[i].size(); ++j) {
                Damage& dmg = damageSplit[i][j];
                if (dmg.target == nullptr)continue;
                if(check[dmg.target->atvStats->num])continue; // สมมติว่า Enemy มี field index
                check[dmg.target->atvStats->num] = true;
                targetList.emplace_back(dmg.target);
                
            }
        }
        ahaInstantBar.push(self);
    }
    void addEnemyBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= totalEnemy&&i<= amount;i++){
                if(enemyUnit[i]->targetType == EnemyType::MAIN||(enemyUnit[i]->targetType == EnemyType::ADJACENT&&!bestBounce))
                    this->targetList.push_back(enemyUnit[i].get());
        }
        for(int i = 0;i< amount;i++){
                damageSplit.emplace_back();
                damageSplit.back().emplace_back(ins,targetList[i%targetList.size()]);
        }
    }
    void addEnemyFairBounce(DmgSrc ins,int amount){
        for(int i = 1;i<= totalEnemy&&i<= amount;i++){
                    this->targetList.push_back(enemyUnit[i].get());
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
                dmg.dmgSrc.atk *=value/100;
                dmg.dmgSrc.hp *=value/100;
                dmg.dmgSrc.def *=value/100;
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