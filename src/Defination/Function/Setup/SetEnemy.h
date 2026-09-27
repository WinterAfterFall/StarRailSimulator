#include "../include.h"

Enemy* createNewEnemy(double speed,double toughness,EnemyType type){
    totalEnemy++; 
    int num = totalEnemy;
    enemyUnit.push_back(make_unique<Enemy>());
    enemyList.push_back(enemyUnit[num].get());
    atvList.push_back(enemyUnit[num]->atvStats.get());
    enemyUnit[num]->atvStats->baseSpeed = speed;
    enemyUnit[num]->maxToughness = toughness;
    enemyUnit[num]->targetType = type;
    enemyUnit[num]->atvStats->num = num;
    enemyUnit[num]->atvStats->name = "Enemy-";
    enemyUnit[num]->atvStats->name += std::to_string(num);
    enemyUnit[num]->atvStats->side = Side::ENEMY;
    enemyUnit[num]->atvStats->charptr = enemyUnit[num].get();
    if(num == 2){
        enemyUnit[2]->nextToLeft = enemyUnit[1].get();
        enemyUnit[1]->nextToRight = enemyUnit[2].get();
    }
    else if(num == 3){
        enemyUnit[3]->nextToRight = enemyUnit[1].get();
        enemyUnit[1]->nextToLeft = enemyUnit[3].get();
    }
    else if(num == 4){
        enemyUnit[4]->nextToLeft = enemyUnit[2].get();
        enemyUnit[2]->nextToRight = enemyUnit[4].get();
    }
    else if(num == 5){
        enemyUnit[5]->nextToRight = enemyUnit[3].get();
        enemyUnit[3]->nextToLeft = enemyUnit[5].get();
    }
    return enemyUnit[num].get();
}
void setupEnemy(double speed,double toughness,pair<double,double> energy,pair<double,double> skillRatio,pair<int,int> attackCooldown,int action,EnemyType type){    
    Enemy *enemyPtr = createNewEnemy(speed,toughness,type);
    // Define the lambda function for turnFunc
    enemyPtr->turnFunc = [enemyPtr,aoeStart = attackCooldown.first,aoeCoolDown = attackCooldown.second
        ,baSkillRatio = skillRatio.first,aoeSkillRatio = skillRatio.second
        ,baEnergy = energy.first,aoeEnergy = energy.second,action]() {
        
        if (enemyPtr->toughnessStatus == 0) {
            enemyPtr->toughnessStatus = 1;
            enemyPtr->currentToughness = enemyPtr->maxToughness;
            enemyPtr->totalToughnessBrokenTime += (currentAtv - enemyPtr->whenToughnessBroken);
        }

        for(int i=1;i<=action;i++){
            ++enemyPtr->aoeCharge;
            if (aoeCoolDown != 0 && aoeSkillRatio!=0&& enemyPtr->aoeCharge % aoeCoolDown == aoeStart) {
                enemyPtr->aoeAttack(aoeSkillRatio,aoeEnergy);
            } else{
                enemyPtr->baAttack(baSkillRatio,baEnergy);
            }
        }   
        
    };

    for (auto& e : enemyWeak) {
        enemyPtr->weaknessType[e.first] = e.second;
    }
    int amountweakness = 0;
    for (auto& e : enemyWeak) {
        enemyPtr->defaultWeaknessType[e.first] = e.second;
        if(e.second==1)amountweakness++;
    }
    enemyPtr->defaultWeaknessElementAmount = amountweakness;
    
    for (auto& e : enemyRes) {
        enemyPtr->defaultElementRes[e.first] = e.second;
    }
}
