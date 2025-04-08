#ifndef ENEMY_COMBAT_H
#define ENEMY_COMBAT_H

#include "../Unit/Trigger_Function.h"

void EnemyHit(Enemy *Attacker){
    vector<SubUnit*> vec;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j].get());
        }
    }
    EnemyHit(Attacker,vec);
}
void EnemyHit(Enemy *Attacker,vector<SubUnit*> target){
    double damageDeal;
    decreaseHPCount++;
    allEventWhenEnemyHit(Attacker,target);
    for(SubUnit* e : target){
        Increase_energy(e->ptr_to_unit,Attacker->Energy_gen);
    }
    for(SubUnit* e : target){
        damageDeal = calculateDmgReceive(Attacker,e,Attacker->skillRatio);
        DecreaseHP(e,Attacker,damageDeal,0,0);
    }
}

#endif