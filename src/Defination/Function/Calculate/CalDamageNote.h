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
    // sample only the last avgDmgSampleLastAtv ATV of the wave · ATV 0 would divide by zero below
    if(currentAtv < wave[currentWaveIndex] - avgDmgSampleLastAtv||currentAtv<=0)return;
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
        
        // first sample of the run always opens a new one (nothing to overwrite yet)
        if(!ptr->avgDmgRecord[enemy->getNum()].avgDmgInstance.empty()
            &&currentAtv < ptr->avgDmgRecord[enemy->getNum()].lastNote + avgDmgSampleGapAtv){
            // same window: keep the highest DMG/ATV seen in it, a lower reading is ignored (user 2026-10-12)
            double &last = ptr->avgDmgRecord[enemy->getNum()].avgDmgInstance.back();
            last = max(last, rec/currentAtv);
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
// Elation Debt (Aeon Aha): the debt takes the top elationDebt% of the enemy's Max HP -> only (100 - debt)% is left to deal
// -> every DMG to it is worth 100/(100 - debt) · applied once here, on the enemy whose HP takes the DMG (recv),
// so True DMG gets it too · allEventAfterDealingDamage still gets the DMG without it (no compounding in tallies)
double calElationDebtMultiplier(Enemy *target){
    double debt = min(99.0,max(0.0,target->elationDebt));
    return 100/(100 - debt);
}
void calDamageNote(shared_ptr<AllyAttackAction> &act,Enemy *src,Enemy *recv,double damage,double ratio,string name){
    CharUnit *ptr = act->getChar();
    damage *= calElationDebtMultiplier(recv);
    if(act->toughnessAvgCalculate){
        ptr->currentNonRealTimeDmg[{src,recv}].total += damage * ratio/100 ;
        ptr->currentNonRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }else{
        ptr->currentRealTimeDmg[{src,recv}].total += damage * ratio/100;
        ptr->currentRealTimeDmg[{src,recv}].type[name] += damage * ratio/100;
    }
    if(act->getChar()->checkDamage){
        if(recv->elationDebt>0)cout<<"Elation Debt   : "<<recv->elationDebt<<"% Max HP -> x"<<calElationDebtMultiplier(recv)<<endl;
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
