#ifndef Cal_Require_Stats_H
#define Cal_Require_Stats_H
#include<bits/stdc++.h>
#include "../Class/Trigger_Function.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000

void Ally::EhrRequirment(){
    if(this->ApplyBaseChance==0)return;
    double temp=100/(this->ApplyBaseChance/100)/((100 - Enemy_effect_res)/100);
    temp = temp-100;
    double x =0;
    temp-=this->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE];
    if(temp<=0)return ;
    x = ceil(temp/3.888);
    this->decreaseTotalSubStats(x);
    x = x * 3.888;
    this->ExtraEhr += x;
    this->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += this->ExtraEhr;
    for(int i=1,sz = this->Sub_Unit_ptr.size();i<sz;i++){
        this->Sub_Unit_ptr[i]->Stats_type["Ehr"][AT_NONE]+=x;
    }
    return ;
}
void Ally::newSpeedRequire(double amount){
    if(this->SpeedRequire<amount)this->SpeedRequire = amount;
}

void Ally::SpeedRequirment(){
    if(this->SpeedRequire==0)return;
    double temp = this->Sub_Unit_ptr[0]->Atv_stats->Base_speed+this->Sub_Unit_ptr[0]->Atv_stats->Base_speed*this->Sub_Unit_ptr[0]->Atv_stats->Speed_percent/100 + this->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed;
    temp = this->SpeedRequire - temp;
    double x =0;
    if(temp<=0)return;
    x = ceil(temp/2.3);
    this->decreaseTotalSubStats(x);
    x = x * 2.3;
    this->ExtraSpeed += x;
    this->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += x;
    for(int i=1,sz = this->Sub_Unit_ptr.size();i<sz;i++){
        this->Sub_Unit_ptr[i]->Atv_stats->Flat_Speed+=x*(this->Sub_Unit_ptr[i]->Unit_Speed_Ratio/100);
    }
    return;
}

void Ally::newEhrRequire(double amount){
    if(this->ApplyBaseChance<amount)this->ApplyBaseChance = amount;
}

#endif