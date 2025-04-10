#ifndef ENEMY_COMBAT_H
#define ENEMY_COMBAT_H

#include "../Unit/Trigger_Function.h"

void EnemyHit(Enemy *Attacker){
    vector<SubUnit*> vec;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->isSameUnitName("Netherwing"))continue;
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j].get());
        }
    }
    EnemyHit(Attacker,vec);
}
void EnemyHit(Enemy *Attacker,vector<SubUnit*> target){
    double damageDeal;
    allEventWhenEnemyHit(Attacker,target);
    for(SubUnit* e : target){
        Increase_energy(e->ptr_to_unit,Attacker->Energy_gen);
    }
    DamageFormEnemy(Attacker,target);
}
void DamageFormEnemy(Enemy *Attacker,vector<SubUnit*> target){
    decreaseHPCount++;
    for(SubUnit* e : target){
        double damageDeal = calculateDmgReceive(Attacker,e,Attacker->skillRatio);
        if(e->currentHP<=0)return;
        DecreaseCurrentHP(e,damageDeal);
        allEventChangeHP(Attacker,e,damageDeal);
    }
}

#endif