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

void Print_damage();
void Print(){
    if(!Print_Atv)return;
    cout<<"Atv = "<<Current_atv<<" ";
    cout<<""<<turn->Char_Name<<" ";
    cout<<turn->turn_cnt<<" ";

    cout<<Ally_unit[1]->Sub_Unit_ptr[0]->totalHP<<" ";
    cout<<Ally_unit[1]->Current_energy<<" ";
    // cout<<"Talent :"<<Ally_unit[1]->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]<<" ";
    cout<<"A6 :"<<Ally_unit[1]->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]<<" ";
    // cout<<"Talent hp :"<<Ally_unit[1]->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]<<" ";
    cout<<"Mydei_Charge_point :"<<Ally_unit[1]->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]<<" ";
    cout<<" "<<Ally_unit[1]->Sub_Unit_ptr[0]->Buff_note["count"]<<" ";


    
    //cout<<sp<<" ";


    


    
    
    // cout<<Ally_unit[1]->Sub_Unit_ptr[0]->Atv_stats->Speed_percent<<" ";
    // cout<<Ally_unit[1]->Sub_Unit_ptr[1]->Atv_stats->Flat_speed<<" ";
    
    
    
    cout<<endl;
}
void Print_damage(){
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
#endif