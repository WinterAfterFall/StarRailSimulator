#include "../include.h"

Enemy* createNewEnemy(double speed,double Toughness,EnemyType type){
    Total_enemy++; 
    int num = Total_enemy;
    enemyUnit.push_back(make_unique<Enemy>());
    enemyUnit[num]->Atv_stats->baseSpeed = speed;
    enemyUnit[num]->Max_toughness = Toughness;
    enemyUnit[num]->Target_type = type;
    enemyUnit[num]->Atv_stats->num = num;
    enemyUnit[num]->Atv_stats->UnitName = "Enemy-";
    enemyUnit[num]->Atv_stats->UnitName += std::to_string(num);
    enemyUnit[num]->Atv_stats->StatsOwnerName = enemyUnit[num]->Atv_stats->UnitName;
    enemyUnit[num]->Atv_stats->side = Side::Enemy;
    enemyUnit[num]->Atv_stats->charptr = enemyUnit[num].get();
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
void SetupEnemy(double speed,double Toughness,pair<double,double> energy,pair<double,double> skillRatio,pair<int,int> attackCooldown,int action,EnemyType type){    
    Enemy *enemyPtr = createNewEnemy(speed,Toughness,type);
    // Define the lambda function for Turn_func
    enemyPtr->Turn_func = [enemyPtr,AoeStart = attackCooldown.first,AoeCoolDown = attackCooldown.second
        ,BAskillRatio = skillRatio.first,AOEskillRatio = skillRatio.second
        ,BAenergy = energy.first,AOEenergy = energy.second,action]() {
        
        if (enemyPtr->Toughness_status == 0) {
            enemyPtr->Toughness_status = 1;
            enemyPtr->Current_toughness = enemyPtr->Max_toughness;
            enemyPtr->Total_toughness_broken_time += (Current_atv - enemyPtr->when_toughness_broken);
        }

        for(int i=1;i<=action;i++){
            ++enemyPtr->AoeCharge;
            if (AoeCoolDown != 0 && AOEskillRatio!=0&& enemyPtr->AoeCharge % AoeCoolDown == AoeStart) {
                enemyPtr->AoeAttack(AOEskillRatio,AOEenergy);
            } else{
                enemyPtr->BaAttack(BAskillRatio,BAenergy);
            }
        }   
        
    };

    for (auto& e : Enemy_weak) {
        enemyPtr->Weakness_type[e.first] = e.second;
    }
    int amountweakness = 0;
    for (auto& e : Enemy_weak) {
        enemyPtr->Default_Weakness_type[e.first] = e.second;
        if(e.second==1)amountweakness++;
    }
    enemyPtr->defaultWeaknessElementAmount = amountweakness;
    
    for (auto& e : Enemy_res) {
        enemyPtr->DefaultElementRes[e.first] = e.second;
    }
}
