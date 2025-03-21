#ifndef Setup_Enemy_H
#define Setup_Enemy_H
#include "../Print.h"
void Enemy_func(Unit *ptr){
    auto enemyPtr = dynamic_cast<Enemy*>(ptr);
    if(enemyPtr->Toughness_status==0){
        enemyPtr->Toughness_status = 1;
        enemyPtr->Current_toughness =  enemyPtr->Max_toughness;
        enemyPtr->Total_toughness_broken_time+=(Current_atv - enemyPtr->when_toughness_broken);
    }
    if(enemyPtr->attackCooldown==0)return;
    ++enemyPtr->Debuff["attackCooldown"];
    if(enemyPtr->Debuff["attackCooldown"]%enemyPtr->attackCooldown==enemyPtr->attackStartAtTurn){
        EnemyHit(enemyPtr);
    }

    
}
void Setup_enemy(int num,double speed,double energy,double Toughness,double skillRatio,int attackCooldown,string type){
    if(num ==0){
        cout<<"setup enemy error";
        exit(0);
    }
    Enemy_unit[num] = make_unique<Enemy>();

        Enemy_unit[num]->Atv_stats->Base_speed = speed;
        Enemy_unit[num]->Energy_gen = energy;
        Enemy_unit[num]->Max_toughness = Toughness;
        Enemy_unit[num]->Target_type = type;
        Enemy_unit[num]->skillRatio = skillRatio;
        Enemy_unit[num]->attackCooldown = attackCooldown;

        Enemy_unit[num]->Turn_func = Enemy_func;



        for(auto &e:Enemy_weak){
                Enemy_unit[num]->Weakness_type[e.first] = e.second;
        }
        
        Enemy_unit[num]->Atv_stats->Unit_num = num;
        Enemy_unit[num]->Atv_stats->Char_Name = "Enemy_";
        Enemy_unit[num]->Atv_stats->Char_Name += type;
        Enemy_unit[num]->Atv_stats->Unit_Name = Enemy_unit[num]->Atv_stats->Char_Name;
        Enemy_unit[num]->Atv_stats->Side = "Enemy";
        Enemy_unit[num]->Atv_stats->ptr_to_unit = Enemy_unit[num].get();
}
void EnemyHit(Enemy *Attacker){
    vector<Sub_Unit*> vec;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j].get());
        }
    }
    EnemyHit(Attacker,vec);
}
void EnemyHit(Enemy *Attacker,vector<Sub_Unit*> target){
    double damageDeal;
    allEventWhenEnemyHit(Attacker,target);
    for(Sub_Unit* e : target){
        Increase_energy(e->ptr_to_unit,Attacker->Energy_gen);
    }
    for(Sub_Unit* e : target){
        damageDeal = calculateDmgReceive(Attacker,e,Attacker->skillRatio);
        DecreaseHP(e,damageDeal,0,0);
    }

    
}
#endif