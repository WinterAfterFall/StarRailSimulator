#ifndef ENEMY_ACTION_H
#define ENEMY_ACTION_H

#include "ActionData.h"

class EnemyActionData : public ActionData{
    public:
    Enemy *enemy;
    function<void()> actionFunction;
    void enemyAction();
    void setAoeAttack(Enemy* enemy,double skillRatio,double energy){
        this->enemy = enemy;
        this->actionFunction = [enemy,skillRatio,energy](){
        vector<AllyUnit*> vec;
        for(auto &each : allyList){
            if(each->getType()== UnitType::BACKUP)continue;
            if(!each->isTargetable())continue;
            vec.push_back(each);
            increaseEnergy(each,energy);
        }
        allEventWhenEnemyHit(enemy,vec);
        decreaseHPCount++;
        for(AllyUnit* e : vec){
            double damageDeal = calculateDmgReceive(enemy,e,skillRatio);
            double hpDecreased = decreaseSheild(e,decreaseBlock(e,damageDeal));
            double actualDecrease = decreaseCurrentHP(e,hpDecreased);
            allEventChangeHP(enemy,e,actualDecrease);
        }
        };
    }
    void setBaAttack(Enemy* enemy,double skillRatio,double energy){
        this->enemy = enemy;
        if(enemy->tauntList.size()>0)
        this->actionFunction = [enemy,skillRatio,energy](){
            vector<AllyUnit*> vec;
            vector<AllyUnit*> unitGotHit;
            for(auto &e: enemy->tauntList){
                if(e->atvStats->type == UnitType::BACKUP)continue;
                if(!e->isTargetable())continue;
                vec.push_back(e);
            }
            for(AllyUnit* each : vec){
                enemy->attackCoolDown[each->atvStats->name] += each->calHitChance(vec);
                if(enemy->attackCoolDown[each->atvStats->name]>=100)enemy->attackCoolDown[each->atvStats->name]-=100;
                else continue;
                increaseEnergy(each,energy);
                unitGotHit.push_back(each);   // ผู้ที่โอกาสโดนตีครบ 100 -> โดนโจมตีจริง (damage loop ข้างล่างวน unitGotHit)
            }
            allEventWhenEnemyHit(enemy,unitGotHit);
            decreaseHPCount++;
            for(AllyUnit* e : unitGotHit){
                double damageDeal = calculateDmgReceive(enemy,e,skillRatio);
                double hpDecreased = decreaseSheild(e,decreaseBlock(e,damageDeal));
                double actualDecrease = decreaseCurrentHP(e,hpDecreased);
                allEventChangeHP(enemy,e,actualDecrease);
            }
        };
        else
        this->actionFunction = [enemy,skillRatio,energy](){
            vector<AllyUnit*> vec;
            vector<AllyUnit*> unitGotHit;
            for(auto &e:allyList){
                if(e->atvStats->type == UnitType::BACKUP)continue;
                if(!e->isTargetable())continue;
                vec.push_back(e);
            }
            for(AllyUnit* each : vec){
                enemy->attackCoolDown[each->atvStats->name] += each->calHitChance(vec);
                if(enemy->attackCoolDown[each->atvStats->name]>=100)enemy->attackCoolDown[each->atvStats->name]-=100;
                else continue;
                increaseEnergy(each,energy);
                unitGotHit.push_back(each);   // ผู้ที่โอกาสโดนตีครบ 100 -> โดนโจมตีจริง (damage loop ข้างล่างวน unitGotHit)
            }
            allEventWhenEnemyHit(enemy,unitGotHit);
            decreaseHPCount++;
            for(AllyUnit* e : unitGotHit){
                double damageDeal = calculateDmgReceive(enemy,e,skillRatio);
                double hpDecreased = decreaseSheild(e,decreaseBlock(e,damageDeal));
                double actualDecrease = decreaseCurrentHP(e,hpDecreased);
                allEventChangeHP(enemy,e,actualDecrease);
            }
        };
    }
};

EnemyActionData* ActionData::castToEnemyActionData(){
        return dynamic_cast<EnemyActionData*>(this);
}
#endif
