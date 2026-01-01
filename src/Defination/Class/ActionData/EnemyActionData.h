#ifndef EnemyAction_H
#define EnemyAction_H

#include "ActionData.h"

class EnemyActionData : public ActionData{
    public:
    Enemy *enemy;
    function<void()> actionFunction;
    void EnemyAction();
    void setAoeAttack(Enemy* enemy,double SkillRatio,double energy){
        this->enemy = enemy;
        this->actionFunction = [enemy,SkillRatio,energy](){
        vector<AllyUnit*> vec;
        for(auto &each : allyList){
            if(each->getType()== UnitType::Backup)continue;
            if(!each->isTargetable())continue;
            vec.push_back(each);
            Increase_energy(each,energy);
        }
        allEventWhenEnemyHit(enemy,vec);
        decreaseHPCount++;
        for(AllyUnit* e : vec){
            double damageDeal = calculateDmgReceive(enemy,e,SkillRatio);
            DecreaseCurrentHP(e,damageDeal);
            allEventChangeHP(enemy,e,damageDeal);
        }
        };
    }
    void setBaAttack(Enemy* enemy,double SkillRatio,double energy){
        this->enemy = enemy;
        if(enemy->tauntList.size()>0)
        this->actionFunction = [enemy,SkillRatio,energy](){
            vector<AllyUnit*> vec;
            vector<AllyUnit*> UnitGotHit;
            for(auto &e: enemy->tauntList){
                if(e->Atv_stats->Type == UnitType::Backup)continue;
                if(!e->isTargetable())continue;
                vec.push_back(e);
            }
            for(AllyUnit* each : vec){
                enemy->AttackCoolDown[each->Atv_stats->UnitName] += each->calHitChance(vec);
                if(enemy->AttackCoolDown[each->Atv_stats->UnitName]>=100)enemy->AttackCoolDown[each->Atv_stats->UnitName]-=100;
                else continue;
                Increase_energy(each,energy);
            }
            allEventWhenEnemyHit(enemy,UnitGotHit);
            decreaseHPCount++;
            for(AllyUnit* e : UnitGotHit){
                double damageDeal = calculateDmgReceive(enemy,e,SkillRatio);
                DecreaseCurrentHP(e,damageDeal);
                allEventChangeHP(enemy,e,damageDeal);
            }
        };
        else
        this->actionFunction = [enemy,SkillRatio,energy](){
            vector<AllyUnit*> vec;
            vector<AllyUnit*> UnitGotHit;
            for(auto &e:allyList){
                if(e->Atv_stats->Type == UnitType::Backup)continue;
                if(!e->isTargetable())continue;
                vec.push_back(e);
            }
            for(AllyUnit* each : vec){
                enemy->AttackCoolDown[each->Atv_stats->UnitName] += each->calHitChance(vec);
                if(enemy->AttackCoolDown[each->Atv_stats->UnitName]>=100)enemy->AttackCoolDown[each->Atv_stats->UnitName]-=100;
                else continue;
                Increase_energy(each,energy);
            }
            allEventWhenEnemyHit(enemy,UnitGotHit);
            decreaseHPCount++;
            for(AllyUnit* e : UnitGotHit){
                double damageDeal = calculateDmgReceive(enemy,e,SkillRatio);
                DecreaseCurrentHP(e,damageDeal);
                allEventChangeHP(enemy,e,damageDeal);
            }
        };
    }
};

EnemyActionData* ActionData::castToEnemyActionData(){
        return dynamic_cast<EnemyActionData*>(this);
}
#endif