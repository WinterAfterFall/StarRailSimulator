#include "../include.h"

bool changeMaxDamage(CharUnit *ptr){
    
    if(ptr->avgDmgRecord[0].maxDmgRecord < ptr->avgDmgRecord[0].currentDmgRecord){
        ptr->maxTotalDmg = ptr->currentTotalDmg;
        
        for(auto &each : ptr->avgDmgRecord){
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

        for(int i=0,sz = ptr->bestSubstats.size();i<sz;i++){
            ptr->bestSubstats[i] = ptr->substats[i].second;    
        }
        
        return true;
    }
    return false;
}
void calAverageDamage(CharUnit *ptr,vector<Enemy*> enemyList){
    if(currentAtv<300)return;
    // refresh every enemy, not only this attack's targets: a note's src may not be hit now (True DMG can retarget)
    for(int i = 1; i<=totalEnemy ; i++ ){
        enemyUnit[i]->toughnessAvgMultiplier = calAvgToughnessMultiplier(enemyUnit[i].get(),currentAtv);
    }
    for(auto &enemy : enemyList){
        double rec = 0;

        for(auto &each : ptr->currentRealTimeDmg){
            if(each.first.recv->getNum() != enemy->getNum())continue;
            rec += each.second.total;
        }
        for(auto &each : ptr->currentNonRealTimeDmg){
            if(each.first.recv->getNum() != enemy->getNum())continue;
            rec += each.second.total*each.first.src->toughnessAvgMultiplier;
        }
        
        if(currentAtv < ptr->avgDmgRecord[enemy->getNum()].lastNote +20){
            ptr->avgDmgRecord[enemy->getNum()].
            avgDmgInstance[ptr->avgDmgRecord[enemy->getNum()].avgDmgInstance.size()-1] = rec/currentAtv;
        }else{
            ptr->avgDmgRecord[enemy->getNum()].lastNote = currentAtv;
            ptr->avgDmgRecord[enemy->getNum()].avgDmgInstance.push_back(rec/currentAtv);
        }    

    }
}
double calAvgToughnessMultiplier(Enemy *target,double totalAtv){
    double temp=0;
    if(target->toughnessStatus==0)
    temp = (1*(target->totalToughnessBrokenTime+(totalAtv - target->whenToughnessBroken)) + 0.9*(totalAtv-(target->totalToughnessBrokenTime+(totalAtv - target->whenToughnessBroken))))/totalAtv; 
    else
    temp = (1*(target->totalToughnessBrokenTime) + 0.9*(totalAtv-target->totalToughnessBrokenTime))/totalAtv; 
    
    return temp;
}
void calDamageNote(shared_ptr<AllyAttackAction> &act,Enemy *src,Enemy *recv,double damage,double ratio,string name){
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
void calDamageSummary(){
    double sum;
    for(int i = 1; i<=totalEnemy ; i++ ){
        enemyUnit[i]->toughnessAvgMultiplier = calAvgToughnessMultiplier(enemyUnit[i].get(),currentAtv);
    }
    for(int i=1;i<=totalAlly;i++){
        // Manage Avg Damage Record
        for(int j = 1; j<=totalEnemy;j++){
            sum = 0;
            for(auto &each : charUnit[i]->avgDmgRecord[j].avgDmgInstance){
                sum += each;
            }
            if(sum == 0)continue;
            charUnit[i]->avgDmgRecord[j].currentDmgRecord = sum/charUnit[i]->avgDmgRecord[j].avgDmgInstance.size();
            charUnit[i]->avgDmgRecord[0].currentDmgRecord += charUnit[i]->avgDmgRecord[j].currentDmgRecord;
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
