#include "../include.h"

Enemy* createNewEnemy(double speed,double Toughness,string type){
    Total_enemy++; 
    int num = Total_enemy;
    Enemy_unit.push_back(make_unique<Enemy>());
    Enemy_unit[num]->Atv_stats->baseSpeed = speed;
    Enemy_unit[num]->Max_toughness = Toughness;
    Enemy_unit[num]->Target_type = type;
    Enemy_unit[num]->Atv_stats->num = num;
    Enemy_unit[num]->Atv_stats->Char_Name = "Enemy-";
    Enemy_unit[num]->Atv_stats->Char_Name += std::to_string(num);
    Enemy_unit[num]->Atv_stats->Unit_Name = Enemy_unit[num]->Atv_stats->Char_Name;
    Enemy_unit[num]->Atv_stats->side = Side::Enemy;
    Enemy_unit[num]->Atv_stats->ptrToChar = Enemy_unit[num].get();
    return Enemy_unit[num].get();
}
void SetupEnemy(double speed,double Toughness,pair<double,double> energy,pair<double,double> skillRatio,pair<int,int> attackCooldown,int action,string type){    
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
