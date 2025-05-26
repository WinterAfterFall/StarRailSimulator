#ifndef ENEMY_COMBAT_H
#define ENEMY_COMBAT_H

#include "../Class/ClassLibrary.h"

void Enemy::AoeAttack(double SkillRatio,double energy){
    shared_ptr<EnemyActionData> data_ = make_shared<EnemyActionData>();
    data_->setAoeAttack(this,SkillRatio,energy);
    Action_bar.push(data_);
}
void Enemy::BaAttack(double SkillRatio,double energy){
    shared_ptr<EnemyActionData> data_ = make_shared<EnemyActionData>();
    data_->setBaAttack(this,SkillRatio,energy);
    Action_bar.push(data_);
}
void Enemy::addTaunt(SubUnit* ptr){
    this->tauntList.push_back(ptr);
}
void Enemy::removeTaunt(string name){
    for (auto it = this->tauntList.begin(); it != this->tauntList.end(); ++it) {
        if ((*it)->isSameCharName(name)) {
            this->tauntList.erase(it); // Remove the pointer from the vector
            break; // Exit the loop after removing the taunt
        }
    }
}

// void EnemyHit(Enemy *Attacker,double energy){
//     vector<SubUnit*> vec;
//     for(int i=1;i<=Total_ally;i++){
//         for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
//             if(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Type == ALLYTYPE_BACKUP)continue;
//             if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
//             vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j].get());
//         }
//     }
//     EnemyHit(Attacker,vec,energy);
// }
// void EnemyHit(Enemy *Attacker,vector<SubUnit*> target,double energy){
//     double damageDeal;
//     allEventWhenEnemyHit(Attacker,target);
//     for(SubUnit* e : target){
//         Increase_energy(e->ptr_to_unit,energy);
//     }
//     DamageFormEnemy(Attacker,target);
// }
// void DamageFormEnemy(Enemy *Attacker,vector<SubUnit*> target){
//     decreaseHPCount++;
//     for(SubUnit* e : target){
//         double damageDeal = calculateDmgReceive(Attacker,e,Attacker->skillRatio);
//         if(e->currentHP<=0)return;
//         DecreaseCurrentHP(e,damageDeal);
//         allEventChangeHP(Attacker,e,damageDeal);
//     }
// }

#endif