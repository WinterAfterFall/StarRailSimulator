#include "include.h"
void printRoundResult();
void print(){
    if(!printAtv)return;
    cout<<"Atv = "<<currentAtv<<" ";
    cout<<""<<turn->name<<" ";
    cout<<turn->turnCnt<<" ";
    cout<<sp<<" ";
    cout<<enemyUnit[1]->currentToughness<<" ";
    cout<<enemyUnit[2]->currentToughness<<" ";
    cout<<charUnit[1]->stack["FireFly_E2"]<<" ";
    // cout<<punchline<<" ";
    cout<<endl;
}
void printRoundResult(){
    double total = 0;
    double avg = 0;
    for(int j=1;j<=totalAlly;j++){

    cout<<charUnit[j]->atvStats->name<<endl;
    cout<<"Total Damage : ";
    cout<<static_cast<long long>(charUnit[j]->currentTotalDmg)<<" ";
    total += charUnit[j]->currentTotalDmg;

    
    cout<<"Avg Damage : ";
    cout<<static_cast<long long>(charUnit[j]->avgDmgRecord[0].currentDmgRecord)<<endl;
    avg+=charUnit[j]->avgDmgRecord[0].currentDmgRecord;

    cout<<"Substats : ";
    for(auto e:charUnit[j]->substats)cout<<e.second<<" ";
    
    cout<<"Total Turn : ";
    cout<<charUnit[j]->atvStats->turnCnt<<" ";
    cout<<endl;
    }
    cout<<"Total Damage : "<<static_cast<long long>(total)<<" "<<static_cast<long long>(avg)<<endl;
}
void printSummaryResult(){
    cout<< "\033[0;38;5;117m";
    cout<<"------------------------------------Summary------------------------------------"<<endl;
    double teamDamage = 0;
    double teamAvgDamage = 0;
    unordered_map<string,double> dmgAnalysis;
    for(int i=1;i<=totalAlly;i++){
        teamDamage += charUnit[i]->maxTotalDmg;
        teamAvgDamage += charUnit[i]->avgDmgRecord[0].maxDmgRecord;
        for(int j=1;j<=totalEnemy;j++){
            enemyUnit[j]->avgDmgRecord += charUnit[i]->avgDmgRecord[j].maxDmgRecord;
        }
    }
    for(int i=1;i<=totalAlly;i++){
        cout<<left;
        cout << "\033[1;4;38;5;45m" // Set text color to green
        << charUnit[i]->atvStats->name<<endl;

        cout<< "\033[0m"<<"| ";
        cout<<charUnit[i]->atvStats->name + " Turn : "<<charUnit[i]->atvStats->turnCnt;
        cout<< "\033[0m"<<" | ";
        if(auto *e = charUnit[i]->memosprite.get()){
            cout<<e->atvStats->name + " Turn : "<<e->atvStats->turnCnt;
            cout<< "\033[0m"<<" | ";
        }
        for(std::unique_ptr<TimerATV> &e : charUnit[i]->summonList){
            cout<<e->name + " Turn : "<<e->turnCnt;
            cout<< "\033[0m"<<" | ";
        }
        cout<<endl;
        cout<<"Substats : | ";
        for(int j = 0;j<charUnit[i]->bestSubstats.size();j++){
            cout<<toString(charUnit[i]->substats[j].first)<<" : "<<charUnit[i]->bestSubstats[j]<<" | ";
        }
        
        cout<<endl;
        cout<<"\033[1;4;38;5;107m"<<"Damage :";
        if(charUnit[i]->maxTotalDmg==0){
            cout<<"\033[1;24;38;5;1m";
            cout<<" No damage Deal"<<endl<<endl;
            continue;
        }
        cout<<endl;

        cout<<"\033[1;4;38;5;2m"<<"Total : "<<setw(10)<<static_cast<long long>(charUnit[i]->maxTotalDmg)<<" | "<<" Average per ATV : "<<setw(5)<<static_cast<long long>(charUnit[i]->avgDmgRecord[0].maxDmgRecord);
        cout<<" | "<<setw(3)<<fixed<<setprecision(1)<<charUnit[i]->maxTotalDmg/teamDamage*100.0<<"% of Team"<<endl;
        
        dmgAnalysis.clear();
        for(auto &e : charUnit[i]->maxRealTimeDmg){
            e.first.recv->totalDmgRecord += e.second.total;
            for(auto &f : e.second.type){
                dmgAnalysis[f.first] += f.second;
                e.first.recv->dmgRecordEachType[f.first] += f.second;
            }
        }
        for(auto &e : charUnit[i]->maxNonRealTimeDmg){
            e.first.recv->totalDmgRecord += e.second.total;
            for(auto &f : e.second.type){
                dmgAnalysis[f.first] += f.second;
                e.first.recv->dmgRecordEachType[f.first] += f.second;
            }
        }
        for(auto &e : dmgAnalysis){
            cout<<left;
            cout<<"\033[0;38;5;34m";
            cout<<setw(25)<<e.first<<" : ";
            cout<<right;

            cout<<"\033[0;38;5;85m";
            cout<<setw(10)<<static_cast<long long>(e.second);
            cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<e.second/charUnit[i]->maxTotalDmg*100.0<<"% and ";
            cout<<setw(5)<<fixed<<setprecision(1)<<e.second/teamDamage*100.0<<"% of Team"<<endl;
        }
        cout<<left;
        cout<<endl;

    }
    cout<< "\033[0;38;5;9m";
    cout<<"------------------------------------Damage Enemy Recive ------------------------------------"<<endl;
    vector<double> enemyDmgRecord(totalEnemy+1,0);
    vector<double> enemyAvgDmgRecord(totalEnemy+1,0);
    for(int i=1;i<=totalEnemy;i++){
        double totaldamage = 0;
        cout<< "\033[1;4;38;5;9m"; // Reset text color
        cout<<enemyUnit[i]->atvStats->name<<endl;
        
        cout<<"\033[1;4;38;5;2m"<<"Total : "<<setw(10)<<static_cast<long long>(enemyUnit[i]->totalDmgRecord)
        <<" | "<<" Average per ATV : "<<setw(5)<<static_cast<long long>(enemyUnit[i]->avgDmgRecord)<<endl;
        for(auto &e : enemyUnit[i]->dmgRecordEachType){
            cout<<left;
            cout<<"\033[0;38;5;34m";
            cout<<setw(25)<<e.first<<" : ";
            cout<<right;

            cout<<"\033[0;38;5;85m";
            cout<<setw(10)<<static_cast<long long>(e.second);
            cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<e.second/ enemyUnit[i]->totalDmgRecord*100.0<<"%"<<endl;
            
        }
        enemyDmgRecord[i] = enemyDmgRecord[i-1] + enemyUnit[i]->totalDmgRecord;
        enemyAvgDmgRecord[i] = enemyAvgDmgRecord[i-1] + enemyUnit[i]->avgDmgRecord;
        cout<<left;
    }
    cout<<"------------------------------------ Conclusion ------------------------------------"<<endl;
    cout<<"\033[0m";
    for(int i=1;i<=totalEnemy;i++){
        cout<<"Focus "<<i<<" enemy : Total damage = "<<static_cast<long long>(enemyDmgRecord[i])<<" "<<static_cast<long long>(enemyAvgDmgRecord[i])<<endl;
    }
    // cout<<" total damage = "<<static_cast<long long>(teamDamage)<<" "<<static_cast<long long>(teamAvgDamage)<<endl;
}