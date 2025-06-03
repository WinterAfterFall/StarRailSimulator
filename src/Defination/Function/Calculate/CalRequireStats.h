#include "../include.h"

void Ally::EhrRequirment(){
    if(this->ApplyBaseChance==0)return;
    double temp=100/(this->ApplyBaseChance/100)/((100 - Enemy_effect_res)/100);
    temp = temp-100;
    double x =0;
    temp-=this->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE];
    if(temp<=0)return ;
    x = ceil(temp/3.888);
    this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->ExtraEhr += x;
    this->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += this->ExtraEhr;
    for(int i=1,sz = this->Sub_Unit_ptr.size();i<sz;i++){
        this->Sub_Unit_ptr[i]->Stats_type["Ehr"][AT_NONE]+=x;
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


