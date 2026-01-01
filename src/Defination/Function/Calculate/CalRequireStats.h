#include "../include.h"

void CharUnit::EhrRequirment(){
    if(this->ApplyBaseChance==0&&this->EhrRequire==0)return;
    double temp = 100;
    if(this->ApplyBaseChance!=0)temp=100/(this->ApplyBaseChance/100)/((100 - Enemy_effect_res)/100);
    temp = temp-100;
    temp = (temp>this->EhrRequire)? temp : this->EhrRequire;
    double x =0;
    temp-=this->Stats_type[Stats::EHR][AType::None];
    if(temp<=0)return;
    x = ceil(temp/3.888);
    this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->ExtraEhr += x;
    this->Stats_type[Stats::EHR][AType::None] += this->ExtraEhr;
    for(auto &each : this->memospriteList){
       each->Stats_type[Stats::EHR][AType::None]+=x;
    }
    return ;
}


void CharUnit::SpeedRequirment(){
    if(this->SpeedRequire==0)return;
    double temp = this->Atv_stats->baseSpeed+this->Atv_stats->baseSpeed*this->Atv_stats->speedPercent/100 + this->Atv_stats->flatSpeed;
    temp = this->SpeedRequire - temp;
    double x =0;
    if(temp<=0)return;
    x = ceil(temp/2.3);
    this->changeTotalSubStats(-x);
    x = x * 2.3;
    this->ExtraSpeed += x;
    this->Atv_stats->flatSpeed += x;
    for(auto &each : this->memospriteList){
        each->Atv_stats->flatSpeed+=x*(each->Unit_Speed_Ratio/100);
    }
    return;
}


