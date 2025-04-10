#ifndef PRINT_H
#define PRINT_H
#include<bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
using std::cout ;
using std::vector;
#include"../Unit/Trigger_Function.h"

void printRoundResult();
void Print(){
    if(!Print_Atv)return;
    cout<<"Atv = "<<Current_atv<<" ";
    cout<<""<<turn->Char_Name<<" ";
    cout<<turn->turn_cnt<<" ";
    cout<<Ally_unit[1]->getSubUnit()->Buff_note["Newbud"]<<" ";
    cout<<Ally_unit[1]->Sub_Unit_ptr[0]->Atv_stats->Max_atv<<" ";
    cout<<Ally_unit[1]->Sub_Unit_ptr[0]->Atv_stats->atv<<" ";
    cout<<Ally_unit[2]->Sub_Unit_ptr[0]->Atv_stats->Max_atv<<" ";
    cout<<Ally_unit[2]->Sub_Unit_ptr[0]->Atv_stats->atv<<" ";


    
    
    cout<<endl;
}
void printRoundResult(){
    double total = 0;
    double avg = 0;
    for(int j=1;j<=Total_ally;j++){

    cout<<Ally_unit[j]->Sub_Unit_ptr[0]->Atv_stats->Char_Name<<endl;
    cout<<"Total Damage : ";
    cout<<static_cast<long long>(Ally_unit[j]->totalDamage)<<" ";
    total += Ally_unit[j]->totalDamage;

    
    cout<<"Avg Damage : ";
    cout<<static_cast<long long>(Ally_unit[j]->Average_Damage)<<endl;
    avg+=Ally_unit[j]->Average_Damage;

    cout<<"Substats : ";
    for(auto e:Ally_unit[j]->Substats)cout<<e.second<<" ";
    
    cout<<"Total Turn : ";
    cout<<Ally_unit[j]->Sub_Unit_ptr[0]->Atv_stats->turn_cnt<<" ";
    cout<<endl;
    }
    cout<<"Total Damage : "<<static_cast<long long>(total)<<" "<<static_cast<long long>(avg)<<endl;
}
void Print_All_Substats(){
    for(auto e:Ally_unit[1]->StatsType_Compare){
        cout<<e.first<<" ";
        cout<<e.second.first<<endl;
    }
    cout<<Ally_unit[1]->StatsType_Compare_MAX_MIN.first<<" "<<Ally_unit[1]->StatsType_Compare_MAX_MIN.second<<endl;
    for(auto e:Ally_unit[1]->TotalSubstats_Compare){
        cout<<e.first<<" ";
        cout<<e.second.first<<endl;
    }
    cout<<Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.first<<" "<<Ally_unit[1]->TotalSubstats_Compare_MAX_MIN.second<<endl;
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
    for(int i=1;i<=Total_ally;i++){
        teamDamage += Ally_unit[i]->maxDamage;
        teamAvgDamage += Ally_unit[i]->Max_Average_Damage;
    }
    for(int i=1;i<=Total_ally;i++){
        cout<<left;
        cout << "\033[1;4;38;5;45m" // Set text color to green
        << Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name<<endl;

        cout<< "\033[0m"<<"| ";
        for(std::unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
            cout<<e->Atv_stats->Char_Name + " Turn : "<<e->Atv_stats->turn_cnt;
            cout<< "\033[0m"<<" | ";
        }
        for(std::unique_ptr<Unit> &e : Ally_unit[i]->Summon_ptr){
            cout<<e->Atv_stats->Char_Name + " Turn : "<<e->Atv_stats->turn_cnt;
            cout<< "\033[0m"<<" | ";
        }
        cout<<endl;
        cout<<"Substats : | ";
        for(int j = 0;j<Ally_unit[i]->Max_damage_Substats.size();j++){
            cout<<Ally_unit[i]->Substats[j].first<<" : "<<Ally_unit[i]->Max_damage_Substats[j]<<" | ";
        }
        
        cout<<endl;
        cout<<"\033[1;4;38;5;107m"<<"Damage :";
        if(Ally_unit[i]->maxDamage==0){
            cout<<"\033[1;24;38;5;1m";
            cout<<" No damage Deal"<<endl<<endl;
            continue;
        }
        cout<<endl;

        cout<<"\033[1;4;38;5;2m"<<"Total : "<<setw(10)<<static_cast<long long>(Ally_unit[i]->maxDamage)<<" | "<<" Average per ATV : "<<setw(5)<<static_cast<long long>(Ally_unit[i]->Max_Average_Damage);
        cout<<" | "<<setw(3)<<fixed<<setprecision(1)<<Ally_unit[i]->maxDamage/teamDamage*100.0<<"% of Team"<<endl;
        
        for(std::pair<const std::string, double> &e : Ally_unit[i]->maxDamageAvgNote){
            cout<<left;
            cout<<"\033[0;38;5;34m";
            cout<<setw(25)<<e.first<<" : ";
            cout<<right;

            cout<<"\033[0;38;5;85m";
            cout<<setw(10)<<static_cast<long long>(e.second);
            cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<e.second/Ally_unit[i]->maxDamage*100.0<<"% and ";
            cout<<setw(5)<<fixed<<setprecision(1)<<e.second/teamDamage*100.0<<"% of Team"<<endl;
        }
        for(std::pair<const std::string, double> &e : Ally_unit[i]->maxDamageRealTimeNote){
            cout<<left;
            cout<<"\033[0;38;5;34m";
            cout<<setw(25)<<e.first<<" : ";
            cout<<right;

            cout<<"\033[0;38;5;85m";
            cout<<setw(10)<<static_cast<long long>(e.second);
            cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<e.second/Ally_unit[i]->maxDamage*100.0<<"% and ";
            cout<<setw(5)<<fixed<<setprecision(1)<<e.second/teamDamage*100.0<<"% of Team"<<endl;
            
        }
        cout<<left;
        cout<<endl;

    }
    cout<< "\033[0;38;5;9m"; // Reset text color
    cout<<"------------------------------------Damage Enemy Recive ------------------------------------"<<endl;
    for(int i=1;i<=Total_enemy;i++){
        double totaldamage = 0;
        for(Common_stats &e : Enemy_unit[i]->maxDamageAvgNote){
            for(std::pair<const std::string, double> &f : e){
                totaldamage += f.second;
            }
        }
        for(Common_stats &e : Enemy_unit[i]->maxDamageRealTimeNote){
            for(std::pair<const std::string, double> &f : e){
                totaldamage += f.second;
            }
        }
        cout<<endl<< "\033[1;4;38;5;9m"; // Reset text color
        cout<<Enemy_unit[i]->Atv_stats->Char_Name<<" "<<Enemy_unit[i]->Atv_stats->Unit_num<<" "<<Enemy_unit[i]->Target_type<<endl;
        for(Common_stats &e : Enemy_unit[i]->maxDamageAvgNote){
            for(std::pair<const std::string, double> &f : e){
                cout<<left;
                cout<<"\033[0;38;5;34m";
                cout<<setw(25)<<f.first<<" : ";
                cout<<right;
    
                cout<<"\033[0;38;5;85m";
                cout<<setw(10)<<static_cast<long long>(f.second);
                cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<f.second/totaldamage*100.0<<"%"<<endl;
            }
        }
        for(Common_stats &e : Enemy_unit[i]->maxDamageRealTimeNote){
            for(std::pair<const std::string, double> &f : e){
                cout<<left;
                cout<<"\033[0;38;5;34m";
                cout<<setw(25)<<f.first<<" : ";
                cout<<right;

                cout<<"\033[0;38;5;85m";
                cout<<setw(10)<<static_cast<long long>(f.second);
                cout<<" = "<<setw(5)<<fixed<<setprecision(1)<<f.second/totaldamage*100.0<<"%"<<endl;
            }
        }
        cout<<left;
    }
    cout<<"------------------------------------ Conclusion ------------------------------------"<<endl;
    cout<<"\033[0m";
    cout<<" total damage = "<<static_cast<long long>(teamDamage)<<" "<<static_cast<long long>(teamAvgDamage)<<endl;
}
#endif