#include "../include.h"

void CharUnit::ehrRequirment(){
    if(this->applyBaseChance==0&&this->ehrRequire==0)return;
    double temp = 100;
    if(this->applyBaseChance!=0)temp=100/(this->applyBaseChance/100)/((100 - enemyEffectRes)/100);
    temp = temp-100;
    temp = (temp>this->ehrRequire)? temp : this->ehrRequire;
    double x =0;
    temp-=this->statsType[Stats::EHR][AType::NONE];
    if(temp<=0)return;
    x = ceil(temp/3.888);
    x = this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->extraEhr += x;
    this->statsType[Stats::EHR][AType::NONE] += x;
    if(auto *each = this->memosprite.get()){
       each->statsType[Stats::EHR][AType::NONE]+=x;
    }
    return ;
}


void CharUnit::speedRequirment(){
    if(this->speedRequire==0)return;
    double temp = this->atvStats->baseSpeed+this->atvStats->baseSpeed*this->atvStats->speedPercent/100 + this->atvStats->flatSpeed;
    temp = this->speedRequire - temp;
    double x =0;
    if(temp<=0)return;
    x = ceil(temp/2.3);
    x = this->changeTotalSubStats(-x);
    x = x * 2.3;
    this->extraSpeed += x;
    this->atvStats->flatSpeed += x;
    if(auto *each = this->memosprite.get()){
        each->atvStats->flatSpeed+=x*(each->unitSpeedRatio/100);
    }
    return;
}

void CharUnit::atkRequirment(){
    if(this->atkRequire <= 0)return;
    double temp = this->baseAtk + this->baseAtk*this->statsType[Stats::ATK_P][AType::NONE]/100 + this->statsType[Stats::FLAT_ATK][AType::NONE];
    temp = this->atkRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseAtk * 3.888/100));
    x = this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->extraAtk += x;
    this->statsType[Stats::ATK_P][AType::NONE] += x;
    if(auto *each = this->memosprite.get()){
        each->statsType[Stats::ATK_P][AType::NONE] +=x;
    }
    return;
}

void CharUnit::hpRequirment(){
    if(this->hpRequire <= 0)return;
    double temp = this->baseHp + this->baseHp*this->statsType[Stats::HP_P][AType::NONE]/100 + this->statsType[Stats::FLAT_HP][AType::NONE];
    temp = this->hpRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseHp * 3.888/100));
    x = this->changeTotalSubStats(-x);
    x = x * 3.888;
    this->extraHp += x;
    this->statsType[Stats::HP_P][AType::NONE] += x;
    if(auto *each = this->memosprite.get()){
        each->statsType[Stats::HP_P][AType::NONE] += x;
    }
    return;
}

void CharUnit::defRequirment(){
    if(this->defRequire <= 0)return;
    double temp = this->baseDef + this->baseDef*this->statsType[Stats::DEF_P][AType::NONE]/100 + this->statsType[Stats::FLAT_DEF][AType::NONE];
    temp = this->defRequire - temp;
    double x = 0;
    if(temp<=0)return;
    x = ceil(temp/(this->baseDef * 4.86/100));
    x = this->changeTotalSubStats(-x);
    x = x * 4.86;
    this->extraDef += x;
    this->statsType[Stats::DEF_P][AType::NONE] += x;
    if(auto *each = this->memosprite.get()){
        each->statsType[Stats::DEF_P][AType::NONE] +=x;
    }
    return;
}


