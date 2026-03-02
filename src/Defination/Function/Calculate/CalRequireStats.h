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
    x = this->changeTotalSubStats(-x);
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
    x = this->changeTotalSubStats(-x);
    x = x * 2.3;
    this->ExtraSpeed += x;
    this->Atv_stats->flatSpeed += x;
    for(auto &each : this->memospriteList){
        each->Atv_stats->flatSpeed+=x*(each->Unit_Speed_Ratio/100);
    }
    return;
}

void CharUnit::AtkRequirment(){
    if(this->AtkRequire <= 0)return;
    double temp = this->baseAtk + this->baseAtk*this->Stats_type[Stats::ATK_P][AType::None]/100 + this->Stats_type[Stats::FLAT_ATK][AType::None];
    temp = this->AtkRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseAtk * 3.888/100));
    x = this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->ExtraAtk += x;
    this->Stats_type[Stats::ATK_P][AType::None] += x;
    for(auto &each : this->memospriteList){
        each->Stats_type[Stats::ATK_P][AType::None] +=x;
    }
    return;
}

void CharUnit::HpRequirment(){
    if(this->HpRequire <= 0)return;
    double temp = this->baseHp + this->baseHp*this->Stats_type[Stats::HP_P][AType::None]/100 + this->Stats_type[Stats::FLAT_HP][AType::None];
    temp = this->HpRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseHp * 3.888/100));
    x = this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->ExtraHp += x;
    this->Stats_type[Stats::HP_P][AType::None] += x;
    for(auto &each : this->memospriteList){
        each->Stats_type[Stats::HP_P][AType::None] +=x*(each->Unit_Hp_Ratio /100);
    }
    return;
}

void CharUnit::DefRequirment(){
    if(this->DefRequire <= 0)return;
    double temp = this->baseDef + this->baseDef*this->Stats_type[Stats::DEF_P][AType::None]/100 + this->Stats_type[Stats::FLAT_DEF][AType::None];
    temp = this->DefRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseDef * 4.86/100));
    x = this->changeTotalSubStats(-x);
    x = x * 4.86;
    this->ExtraDef += x;
    this->Stats_type[Stats::DEF_P][AType::None] += x;
    for(auto &each : this->memospriteList){
        each->Stats_type[Stats::DEF_P][AType::None] +=x;
    }
    return;
}


