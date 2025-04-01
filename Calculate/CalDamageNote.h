#ifndef DAMAGE_NOTE_H
#define DAMAGE_NOTE_H
#include "../Unit/Trigger_Function.h"

bool changeMaxDamage(Ally *ptr){
    
    if(ptr->maxDamage < ptr->totalDamage){
        ptr->maxDamage = ptr->totalDamage;
        ptr->Max_Average_Damage = ptr->Average_Damage;

        for(std::pair<const std::string, double> &e : ptr->damageAvgNote){
            ptr->maxDamageAvgNote[e.first] = e.second;
        }
        for(std::pair<const std::string, double> &e : ptr->damageRealTimeNote){
            ptr->maxDamageRealTimeNote[e.first] = e.second;
        }
        for(int i=1;i<=Total_enemy;i++){
            for(std::pair<const std::string, double> &e : Enemy_unit[i]->damageAvgNote[ptr->getNum()]){
                Enemy_unit[i]->maxDamageAvgNote[ptr->getNum()][e.first] = e.second;
            }
            for(std::pair<const std::string, double> &e : Enemy_unit[i]->damageRealTimeNote[ptr->getNum()]){
                Enemy_unit[i]->maxDamageRealTimeNote[ptr->getNum()][e.first] = e.second;
            }
        }
        
        for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++){
            ptr->Max_damage_Substats[i] = ptr->Substats[i].second;    
        }
        
        return true;
    }
    return false;
}
void Cal_AverageDamage(Ally *ptr){
    if(Current_atv<100)return;
    double Temp = ptr->totalRealTimeDamage;
    for(int i=1;i<=Total_enemy;i++)
    Temp += ptr->totalAvgToughnessDamage[i]*Cal_AvgToughnessMultiplier(Enemy_unit[i].get(),Current_atv);
    if(Current_atv < ptr->Last_note+20){
        ptr->averageDamageInstance[ptr->averageDamageInstance.size()-1] = Temp/Current_atv;
    }else{
        ptr->Last_note = Current_atv;
        ptr->averageDamageInstance.push_back(Temp/Current_atv);
    }    
}
double Cal_AvgToughnessMultiplier(Enemy *target,double Total_atv){
    double temp=0;
    if(target->Toughness_status==0)
    temp = (1*(target->Total_toughness_broken_time+(Total_atv - target->when_toughness_broken)) + 0.9*(Total_atv-(target->Total_toughness_broken_time+(Total_atv - target->when_toughness_broken))))/Total_atv; 
    else
    temp = (1*(target->Total_toughness_broken_time) + 0.9*(Total_atv-target->Total_toughness_broken_time))/Total_atv; 
    
    return temp;
}
void Cal_DamageNote(ActionData &data_,Enemy *target,double damage){
    Ally *ptr = data_.Attacker->ptr_to_unit;
    if(data_.toughnessAvgCalculate){
        ptr->totalAvgToughnessDamage[target->getNum()] += damage;
        target->damageAvgNote[ptr->getNum()][data_.actionName] += damage;
    }else{
        ptr->totalRealTimeDamage += damage;
        target->damageRealTimeNote[ptr->getNum()][data_.actionName] += damage;
    }
}
void Cal_DamageSummary(){
    int sum;
    for(int i = 1; i<=Total_enemy ; i++ ){
        Enemy_unit[i]->toughnessAvgMultiplier = Cal_AvgToughnessMultiplier(Enemy_unit[i].get(),Current_atv);
        for(unordered_map<string,double> &e :Enemy_unit[i]->damageAvgNote){
            for(std::pair<const std::string, double> &f : e){
                f.second *= Enemy_unit[i]->toughnessAvgMultiplier;
            }
        }
    }
    for(int i=1;i<=Total_ally;i++){
        sum = 0;
        for(auto &e:Ally_unit[i]->averageDamageInstance){
            sum += e;
        }
        Ally_unit[i]->Average_Damage = sum/Ally_unit[i]->averageDamageInstance.size();  
        Ally_unit[i]->totalDamage = Ally_unit[i]->totalRealTimeDamage;

        for(int j = 1; j<=Total_enemy ; j++ ){
            Ally_unit[i]->totalDamage += Ally_unit[i]->totalAvgToughnessDamage[j]*Enemy_unit[j]->toughnessAvgMultiplier;
            for(std::pair<const std::string, double> &e :Enemy_unit[j]->damageRealTimeNote[i]){
                Ally_unit[i]->damageRealTimeNote[e.first]  += e.second;
            }
            for(std::pair<const std::string, double> &e :Enemy_unit[j]->damageAvgNote[i]){
                Ally_unit[i]->damageAvgNote[e.first]  += e.second;
            }

        }
    }
}
#endif