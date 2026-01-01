#include "../include.h"


//SetReuqirements
void CharUnit::setSpeed(double speed) {
    this->SpeedRequire = speed;
}
void CharUnit::newSpeedRequire(double amount){
    if(this->SpeedRequire<amount)this->SpeedRequire = amount;
}

void CharUnit::newApplyBaseChanceRequire(double amount){
    if(this->ApplyBaseChance>amount)this->ApplyBaseChance = amount;
}
void CharUnit::newEhrRequire(double amount){
    if(this->EhrRequire<amount)this->EhrRequire = amount;
}


// Set Substats
void CharUnit::setTotalSubstats(int Value) {
    this->Total_substats = Value;
    this->currentTotalSubstats = Value;
    this->SeparateRatio = Value;
    this->Substats[0].second = Value;
    this->Max_damage_Substats.resize(this->Substats.size());
}
void CharUnit::pushSubstats(Stats StatsType) {
    this->Substats.push_back({StatsType, 0});
}
void CharUnit::changeTotalSubStats(int amount) {
    amount = (this->Total_substats + amount >= 0) ? amount : -this->Total_substats;
    this->Total_substats += amount;
    this->currentTotalSubstats += amount;
    this->SeparateRatio += amount;
    this->Substats[0].second += amount;
}
