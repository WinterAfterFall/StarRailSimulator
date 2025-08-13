#include "../include.h"

void Ally::EhrRequirment(){
    if(this->ApplyBaseChance==0&&this->EhrRequire==0)return;
    double temp = 100;
    if(this->ApplyBaseChance!=0)temp=100/(this->ApplyBaseChance/100)/((100 - Enemy_effect_res)/100);
    temp = temp-100;
    temp = (temp>this->EhrRequire)? temp : this->EhrRequire;
    double x =0;
    temp-=this->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None];
    if(temp<=0)return;
    x = ceil(temp/3.888);
    this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->ExtraEhr += x;
    this->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += this->ExtraEhr;
    for(int i=1,sz = this->Sub_Unit_ptr.size();i<sz;i++){
        this->Sub_Unit_ptr[i]->Stats_type[Stats::EHR][AType::None]+=x;
    }
    return ;
}


void Ally::SpeedRequirment(){
    if(this->SpeedRequire==0)return;
    double temp = this->Sub_Unit_ptr[0]->Atv_stats->baseSpeed+this->Sub_Unit_ptr[0]->Atv_stats->baseSpeed*this->Sub_Unit_ptr[0]->Atv_stats->speedPercent/100 + this->Sub_Unit_ptr[0]->Atv_stats->flatSpeed;
    temp = this->SpeedRequire - temp;
    double x =0;
    if(temp<=0)return;
    x = ceil(temp/2.3);
    this->changeTotalSubStats(-x);
    x = x * 2.3;
    this->ExtraSpeed += x;
    this->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += x;
    for(int i=1,sz = this->Sub_Unit_ptr.size();i<sz;i++){
        this->Sub_Unit_ptr[i]->Atv_stats->flatSpeed+=x*(this->Sub_Unit_ptr[i]->Unit_Speed_Ratio/100);
    }
    return;
}


