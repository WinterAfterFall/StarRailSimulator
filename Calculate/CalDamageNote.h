#ifndef DAMAGE_NOTE_H
#define DAMAGE_NOTE_H
#include "../Class/Trigger_Function.h"

bool changeMaxDamage(Ally *ptr){
    
    if(ptr->AvgDmgRecord[0].maxDmgRecord < ptr->AvgDmgRecord[0].currentDmgRecord){
        ptr->maxTotalDmg = ptr->currentTotalDmg;
        
        for(auto &each : ptr->AvgDmgRecord){
            each.maxDmgRecord = each.currentDmgRecord;
        }

        for(auto &each1 : ptr->currentRealTimeDmg){
            ptr->maxRealTimeDmg[each1.first].total = each1.second.total;
            for(auto &each2 : each1.second.type){
                ptr->maxRealTimeDmg[each1.first].type[each2.first] = each2.second;
            }
        }

        for(auto &each1 : ptr->currentNonRealTimeDmg){
            ptr->maxNonRealTimeDmg[each1.first].total = each1.second.total;
            for(auto &each2 : each1.second.type){
                ptr->maxNonRealTimeDmg[each1.first].type[each2.first] = each2.second;
            }
        }

        for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++){
            ptr->Max_damage_Substats[i] = ptr->Substats[i].second;    
        }
        
        return true;
    }
    return false;
}
void Cal_AverageDamage(Ally *ptr,vector<Enemy*> enemyList){
    if(Current_atv<100)return;
    for(auto &enemy : enemyList){
        double rec = 0;
        enemy->toughnessAvgMultiplier = Cal_AvgToughnessMultiplier(enemy,Current_atv);

        for(auto &each : ptr->currentRealTimeDmg){
            if(each.first.recv->getNum() != enemy->getNum())continue;
            rec += each.second.total;
        }
        for(auto &each : ptr->currentNonRealTimeDmg){
            if(each.first.recv->getNum() != enemy->getNum())continue;
            rec += each.second.total*enemy->toughnessAvgMultiplier;
        }
        
        if(Current_atv < ptr->AvgDmgRecord[enemy->getNum()].lastNote +20){
            ptr->AvgDmgRecord[enemy->getNum()].
            avgDmgInstance[ptr->AvgDmgRecord[enemy->getNum()].avgDmgInstance.size()-1] = rec/Current_atv;
        }else{
            ptr->AvgDmgRecord[enemy->getNum()].lastNote = Current_atv;
            ptr->AvgDmgRecord[enemy->getNum()].avgDmgInstance.push_back(rec/Current_atv);
        }    

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
void Cal_DamageNote(shared_ptr<AllyActionData> &data_,Enemy *src,Enemy *recv,double damage,double ratio,string name){
    Ally *ptr = data_->Attacker->ptr_to_unit;
    if(data_->toughnessAvgCalculate){
        ptr->currentNonRealTimeDmg[{src,recv}].total += damage * ratio/100 ;
        ptr->currentNonRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }else{
        ptr->currentRealTimeDmg[{src,recv}].total += damage * ratio/100;
        ptr->currentRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }
    if(Normal_Damage_check_mode==data_->Attacker->getNum())
    cout<<data_->Attacker->Atv_stats->Unit_Name<<" "<<name<<" "<<damage<<endl;
}
void Cal_DamageSummary(){
    double sum;
    for(int i = 1; i<=Total_enemy ; i++ ){
        Enemy_unit[i]->toughnessAvgMultiplier = Cal_AvgToughnessMultiplier(Enemy_unit[i].get(),Current_atv);
    }
    for(int i=1;i<=Total_ally;i++){

        // Manage Avg Damage Record
        for(int j = 1; j<=Total_enemy;j++){
            sum = 0;
            for(auto &each : Ally_unit[i]->AvgDmgRecord[j].avgDmgInstance){
                sum += each;
            }
            if(sum == 0)continue;
            Ally_unit[i]->AvgDmgRecord[j].currentDmgRecord = sum/Ally_unit[i]->AvgDmgRecord[j].avgDmgInstance.size();
            Ally_unit[i]->AvgDmgRecord[0].currentDmgRecord += Ally_unit[i]->AvgDmgRecord[j].currentDmgRecord;
        }

        for(auto &each : Ally_unit[i]->currentRealTimeDmg){
            Ally_unit[i]->currentTotalDmg += each.second.total;
        }
        for(auto &each : Ally_unit[i]->currentRealTimeDmg){
            for(auto &each2 : each.second.type){
                each2.second*= each.first.src->toughnessAvgMultiplier;
            }
            each.second.total *= each.first.src->toughnessAvgMultiplier;
            Ally_unit[i]->currentTotalDmg += each.second.total;
        }
        
    }
}
#endif