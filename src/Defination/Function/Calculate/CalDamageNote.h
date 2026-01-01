#include "../include.h"

bool changeMaxDamage(CharUnit *ptr){
    
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
void Cal_AverageDamage(CharUnit *ptr,vector<Enemy*> enemyList){
    if(Current_atv<300)return;
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
void Cal_DamageNote(shared_ptr<AllyAttackAction> &act,Enemy *src,Enemy *recv,double damage,double ratio,string name){
    CharUnit *ptr = act->getChar();
    if(act->toughnessAvgCalculate){
        ptr->currentNonRealTimeDmg[{src,recv}].total += damage * ratio/100 ;
        ptr->currentNonRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }else{
        ptr->currentRealTimeDmg[{src,recv}].total += damage * ratio/100;
        ptr->currentRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }
    if(act->getChar()->checkDamage){
        cout<<name<<" Total Damage : "<<damage<<" with "<<ratio<<"%"<<endl;
    }
}
void Cal_DamageSummary(){
    double sum;
    for(int i = 1; i<=Total_enemy ; i++ ){
        enemyUnit[i]->toughnessAvgMultiplier = Cal_AvgToughnessMultiplier(enemyUnit[i].get(),Current_atv);
    }
    for(int i=1;i<=Total_ally;i++){
        // Manage Avg Damage Record
        for(int j = 1; j<=Total_enemy;j++){
            sum = 0;
            for(auto &each : charUnit[i]->AvgDmgRecord[j].avgDmgInstance){
                sum += each;
            }
            if(sum == 0)continue;
            charUnit[i]->AvgDmgRecord[j].currentDmgRecord = sum/charUnit[i]->AvgDmgRecord[j].avgDmgInstance.size();
            charUnit[i]->AvgDmgRecord[0].currentDmgRecord += charUnit[i]->AvgDmgRecord[j].currentDmgRecord;
        }

        for(auto &each : charUnit[i]->currentRealTimeDmg){
            charUnit[i]->currentTotalDmg += each.second.total;
        }
        for(auto &each : charUnit[i]->currentNonRealTimeDmg){
            for(auto &each2 : each.second.type){
                each2.second*= each.first.src->toughnessAvgMultiplier;
            }
            each.second.total *= each.first.src->toughnessAvgMultiplier;
            charUnit[i]->currentTotalDmg += each.second.total;
        }
        
    }
}
