#include "include.h"
void printRoundResult();
void Print(){
    if(!Print_Atv)return;
    cout<<"Atv = "<<Current_atv<<" ";
    cout<<""<<turn->Name<<" ";
    cout<<turn->turnCnt<<" ";
    cout<<sp<<" ";
    cout<<charUnit[1]->getBuffNote("Mydei_Charge_point")<<" ";
    cout<<charUnit[1]->Current_energy<<" ";
    cout<<endl;
}
void printRoundResult(){
    double total = 0;
    double avg = 0;
    for(int j=1;j<=Total_ally;j++){

    cout<<charUnit[j]->Atv_stats->Name<<endl;
    cout<<"Total Damage : ";
    cout<<static_cast<long long>(charUnit[j]->currentTotalDmg)<<" ";
    total += charUnit[j]->currentTotalDmg;

    
    cout<<"Avg Damage : ";
    cout<<static_cast<long long>(charUnit[j]->AvgDmgRecord[0].currentDmgRecord)<<endl;
    avg+=charUnit[j]->AvgDmgRecord[0].currentDmgRecord;

    cout<<"Substats : ";
    for(auto e:charUnit[j]->Substats)cout<<e.second<<" ";
    
    cout<<"Total Turn : ";
    cout<<charUnit[j]->Atv_stats->turnCnt<<" ";
    cout<<endl;
    }
    cout<<"Total Damage : "<<static_cast<long long>(total)<<" "<<static_cast<long long>(avg)<<endl;
}
void Print_All_Substats(){
    for(auto e:charUnit[1]->StatsType_Compare){
        cout<<e.first<<" ";
        cout<<e.second.first<<endl;
    }
    cout<<charUnit[1]->StatsType_Compare_MAX_MIN.first<<" "<<charUnit[1]->StatsType_Compare_MAX_MIN.second<<endl;
    for(auto e:charUnit[1]->TotalSubstats_Compare){
        cout<<e.first<<" ";
        cout<<e.second.first<<endl;
    }
    cout<<charUnit[1]->TotalSubstats_Compare_MAX_MIN.first<<" "<<charUnit[1]->TotalSubstats_Compare_MAX_MIN.second<<endl;
    return;
    // for(auto e:Ally_unit[1]->Damage_data){
    //     int index = e.first;
    //     cout<<"{ ";
    //     for(int i=Ally_unit[1]->Substats.size()-1;i>=0;i--){
    //         int temp = pow(Ally_unit[1]->Total_substats+1,i);
    //         cout<<index/temp<<" ";
    //         index = index % temp;
    //     }
    //     cout<<"} "<<e.second<<endl;
    // }
}
/*
void Calculate_All_Substats(){
    for(auto e:Ally_unit[1]->Damage_data){
        int index = e.first;
        for(int i=Ally_unit[1]->Substats.size()-1;i>=0;i--){
            int temp = pow(Ally_unit[1]->Total_substats+1,i);
            Ally_unit[1]->Substats[i].second=index/temp;
            index = index % temp;
        }
        for(int i=1;i<Ally_unit[1]->Substats.size();i++){
            if(Ally_unit[1]->Substats[i].second==0)continue;
            index = Ally_unit[1]->Substats[0].second+1;
            for(int j=1;j<Ally_unit[1]->Substats.size();j++){
                int temp = pow(Ally_unit[1]->Total_substats+1,j);
                if(i==j){
                    index+=(Ally_unit[1]->Substats[j].second-1)*temp;
                }else{
                    index+=(Ally_unit[1]->Substats[j].second)*temp;
                }   
            }
            Ally_unit[1]->StatsType_Compare[Ally_unit[1]->Substats[i].first].first=
            ((Ally_unit[1]->StatsType_Compare[Ally_unit[1]->Substats[i].first].first*Ally_unit[1]->StatsType_Compare[Ally_unit[1]->Substats[i].first].second)+(100*e.second/Ally_unit[1]->Damage_data[index]))
            /((double)Ally_unit[1]->StatsType_Compare[Ally_unit[1]->Substats[i].first].second+1);
            if(Ally_unit[1]->StatsType_Compare_MAX_MIN.first<100*e.second/Ally_unit[1]->Damage_data[index])Ally_unit[1]->StatsType_Compare_MAX_MIN.first = 100*e.second/Ally_unit[1]->Damage_data[index];
            if(Ally_unit[1]->StatsType_Compare_MAX_MIN.second>100*e.second/Ally_unit[1]->Damage_data[index])Ally_unit[1]->StatsType_Compare_MAX_MIN.second = 100*e.second/Ally_unit[1]->Damage_data[index];
            Ally_unit[1]->StatsType_Compare[Ally_unit[1]->Substats[i].first].second++;
        }
        
        if(Calculate_All_possible_mode){
        for(int i=0;i<Ally_unit[1]->Substats.size();i++){
            if(Ally_unit[1]->Substats[i].second==0)continue;
            index = e.first - pow(Ally_unit[1]->Total_substats+1,i);
            cout<<e.second<<" "<<Ally_unit[1]->Damage_data[index]<<endl;
            cout<<e.first<<" "<<index<<" "<<Ally_unit[1]->Substats[i].second<<endl;
            
            Ally_unit[1]->TotalSubstats_Compare[Ally_unit[1]->Substats[i].first].first=
            ((Ally_unit[1]->TotalSubstats_Compare[Ally_unit[1]->Substats[i].first].first*Ally_unit[1]->TotalSubstats_Compare[Ally_unit[1]->Substats[i].first].second)+(100*e.second/Ally_unit[1]->Damage_data[index]))
            /((double)Ally_unit[1]->TotalSubstats_Compare[Ally_unit[1]->Substats[i].first].second+1);
            if(Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.first<100*e.second/Ally_unit[1]->Damage_data[index])Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.first = 100*e.second/Ally_unit[1]->Damage_data[index];
            if(Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.second>100*e.second/Ally_unit[1]->Damage_data[index])Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.second = 100*e.second/Ally_unit[1]->Damage_data[index];
            Ally_unit[1]->TotalSubstats_Compare[Ally_unit[1]->Substats[i].first].second++;
        }
        }
    }
}
*/
void printSummaryResult(){
    cout<< "\033[0;38;5;117m";
    cout<<"------------------------------------Summary------------------------------------"<<endl;
    double teamDamage = 0;
    double teamAvgDamage = 0;
    unordered_map<string,double> dmgAnalysis;
    for(int i=1;i<=Total_ally;i++){
        teamDamage += charUnit[i]->maxTotalDmg;
        teamAvgDamage += charUnit[i]->AvgDmgRecord[0].maxDmgRecord;
        for(int j=1;j<=Total_enemy;j++){
            enemyUnit[j]->avgDmgRecord += charUnit[i]->AvgDmgRecord[j].maxDmgRecord;
        }
    }
    for(int i=1;i<=Total_ally;i++){
        cout<<left;
        cout << "\033[1;4;38;5;45m" // Set text color to green
        << charUnit[i]->Atv_stats->Name<<endl;

        cout<< "\033[0m"<<"| ";
        cout<<charUnit[i]->Atv_stats->Name + " Turn : "<<charUnit[i]->Atv_stats->turnCnt;
        cout<< "\033[0m"<<" | ";
        for(auto &e : charUnit[i]->memospriteList){
            cout<<e->Atv_stats->Name + " Turn : "<<e->Atv_stats->turnCnt;
            cout<< "\033[0m"<<" | ";
        }
        for(std::unique_ptr<Unit> &e : charUnit[i]->summonList){
            cout<<e->Atv_stats->Name + " Turn : "<<e->Atv_stats->turnCnt;
            cout<< "\033[0m"<<" | ";
        }
        cout<<endl;
        cout<<"Substats : | ";
        for(int j = 0;j<charUnit[i]->Max_damage_Substats.size();j++){
            cout<<toString(charUnit[i]->Substats[j].first)<<" : "<<charUnit[i]->Max_damage_Substats[j]<<" | ";
        }
        
        cout<<endl;
        cout<<"\033[1;4;38;5;107m"<<"Damage :";
        if(charUnit[i]->maxTotalDmg==0){
            cout<<"\033[1;24;38;5;1m";
            cout<<" No damage Deal"<<endl<<endl;
            continue;
        }
        cout<<endl;

        cout<<"\033[1;4;38;5;2m"<<"Total : "<<setw(10)<<static_cast<long long>(charUnit[i]->maxTotalDmg)<<" | "<<" Average per ATV : "<<setw(5)<<static_cast<long long>(charUnit[i]->AvgDmgRecord[0].maxDmgRecord);
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
    vector<double> enemyDmgRecord(Total_enemy+1,0);
    vector<double> enemyAvgDmgRecord(Total_enemy+1,0);
    for(int i=1;i<=Total_enemy;i++){
        double totaldamage = 0;
        cout<< "\033[1;4;38;5;9m"; // Reset text color
        cout<<enemyUnit[i]->Atv_stats->Name<<endl;
        
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
    for(int i=1;i<=Total_enemy;i++){
        cout<<"Focus "<<i<<" enemy : Total damage = "<<static_cast<long long>(enemyDmgRecord[i])<<" "<<static_cast<long long>(enemyAvgDmgRecord[i])<<endl;
    }
    // cout<<" total damage = "<<static_cast<long long>(teamDamage)<<" "<<static_cast<long long>(teamAvgDamage)<<endl;
}