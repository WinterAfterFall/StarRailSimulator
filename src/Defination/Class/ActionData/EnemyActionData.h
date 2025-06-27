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
        vector<SubUnit*> vec;
        for(int i=1;i<=Total_ally;i++){
            for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
                if(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Type == ALLYTYPE_BACKUP)continue;
                if(!Ally_unit[i]->Sub_Unit_ptr[j]->isExsited())continue;
                vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j].get());
                Increase_energy(Ally_unit[i].get(),energy);
            }
        }
        allEventWhenEnemyHit(enemy,vec);
        decreaseHPCount++;
        for(SubUnit* e : vec){
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
            vector<SubUnit*> vec;
            for(auto &each : enemy->tauntList){
                if(each->Atv_stats->Type == ALLYTYPE_BACKUP)continue;
                if(!each->isExsited())continue;
                enemy->AttackCoolDown[each->Atv_stats->Char_Name] += each->calHitChance(enemy->tauntList);
                if(enemy->AttackCoolDown[each->Atv_stats->Char_Name]>100)enemy->AttackCoolDown[each->Atv_stats->Char_Name]-=100;
                else continue;
                Increase_energy(each,energy);
                vec.push_back(each);
            }
            allEventWhenEnemyHit(enemy,vec);
            decreaseHPCount++;
            for(SubUnit* e : vec){
                double damageDeal = calculateDmgReceive(enemy,e,SkillRatio);
                DecreaseCurrentHP(e,damageDeal);
                allEventChangeHP(enemy,e,damageDeal);
            }
        };
        else
        this->actionFunction = [enemy,SkillRatio,energy](){
            vector<SubUnit*> vec;
            for(int i=1;i<=Total_ally;i++){
                for(auto &e:Ally_unit[i]->Sub_Unit_ptr){
                    if(e->Atv_stats->Type == ALLYTYPE_BACKUP)continue;
                    if(!e->isExsited())continue;
                    vec.push_back(e.get());
                }
            }
            for(SubUnit* each : vec){
                enemy->AttackCoolDown[each->Atv_stats->Char_Name] += each->calHitChance(vec);
                if(enemy->AttackCoolDown[each->Atv_stats->Char_Name]>100)enemy->AttackCoolDown[each->Atv_stats->Char_Name]-=100;
                else continue;
                Increase_energy(each,energy);
            }
            allEventWhenEnemyHit(enemy,vec);
            decreaseHPCount++;
            for(SubUnit* e : vec){
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