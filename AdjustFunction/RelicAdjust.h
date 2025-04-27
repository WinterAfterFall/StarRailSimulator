#ifndef RelicAdjust_H
#define RelicAdjust_H

#include "../Class/Trigger_Function.h"


//SetReuqirements
void Ally::setSpeed(double speed) {
    this->SpeedRequire = speed;
}
void Ally::newSpeedRequire(double amount){
    if(this->SpeedRequire<amount)this->SpeedRequire = amount;
}

void Ally::newEhrRequire(double amount){
    if(this->ApplyBaseChance<amount)this->ApplyBaseChance = amount;
}


// Set Substats
void Ally::setTotalSubstats(int Value) {
    this->Total_substats = Value;
    this->currentTotalSubstats = Value;
    this->SeparateRatio = Value;
    this->Substats[0].second = Value;
    this->Max_damage_Substats.resize(this->Substats.size());
}
void Ally::pushSubstats(string StatsType) {
    this->Substats.push_back({StatsType, 0});
}
void Ally::decreaseTotalSubStats(int amount) {
    amount = (this->Total_substats >= amount) ? amount : this->Total_substats;
    this->Total_substats -= amount;
    this->currentTotalSubstats -= amount;
    this->SeparateRatio -= amount;
    this->Substats[0].second -= amount;
}
void Ally::adjustStats(vector<pair<string,int>> stats) {
    
}
#endif