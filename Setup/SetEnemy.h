#ifndef Setup_Enemy_H
#define Setup_Enemy_H
#include "../Unit/Trigger_Function.h"

void Setup_enemy(int num, double speed, double energy, double Toughness, double skillRatio, int attackCooldown, string type) {
    if (num == 0) {
        cout << "setup enemy error";
        exit(0);
    }
    Enemy_unit[num] = make_unique<Enemy>();

    Enemy_unit[num]->Atv_stats->Base_speed = speed;
    Enemy_unit[num]->Energy_gen = energy;
    Enemy_unit[num]->Max_toughness = Toughness;
    Enemy_unit[num]->Target_type = type;
    Enemy_unit[num]->skillRatio = skillRatio;
    Enemy_unit[num]->attackCooldown = attackCooldown;
    Enemy *enemyPtr = Enemy_unit[num].get();
    // Define the lambda function for Turn_func
    Enemy_unit[num]->Turn_func = [enemyPtr]() {
        
        if (enemyPtr->Toughness_status == 0) {
            enemyPtr->Toughness_status = 1;
            enemyPtr->Current_toughness = enemyPtr->Max_toughness;
            enemyPtr->Total_toughness_broken_time += (Current_atv - enemyPtr->when_toughness_broken);
        }
        if (enemyPtr->skillRatio == 0) return;
        ++enemyPtr->Debuff["attackCooldown"];

        if (enemyPtr->attackCooldown != 0 && enemyPtr->Debuff["attackCooldown"] % enemyPtr->attackCooldown == enemyPtr->attackStartAtTurn) {
            EnemyHit(enemyPtr);
        } else if (enemyPtr->target) {
            vector<SubUnit*> vec;
            vec.push_back(enemyPtr->target);
            EnemyHit(enemyPtr, vec);
        }
    };

    for (auto& e : Enemy_weak) {
        Enemy_unit[num]->Weakness_type[e.first] = e.second;
    }

    Enemy_unit[num]->Atv_stats->Unit_num = num;
    Enemy_unit[num]->Atv_stats->Char_Name = "Enemy_";
    Enemy_unit[num]->Atv_stats->Char_Name += type;
    Enemy_unit[num]->Atv_stats->Unit_Name = Enemy_unit[num]->Atv_stats->Char_Name;
    Enemy_unit[num]->Atv_stats->Side = "Enemy";
    Enemy_unit[num]->Atv_stats->ptr_to_unit = Enemy_unit[num].get();
}

#endif
