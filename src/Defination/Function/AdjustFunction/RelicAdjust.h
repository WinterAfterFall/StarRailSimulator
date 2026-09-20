#include "../include.h"


//SetReuqirements
void CharUnit::setSpeed(double speed) {
    this->SpeedRequire = speed;
}
void CharUnit::newSpeedRequire(double amount){
    if(this->SpeedRequire<amount)this->SpeedRequire = amount;
}

void CharUnit::newApplyBaseChanceRequire(double amount){
    if(this->ApplyBaseChance == 0 || this->ApplyBaseChance > amount)this->ApplyBaseChance = amount;
}
void CharUnit::newEhrRequire(double amount){
    if(this->EhrRequire<amount)this->EhrRequire = amount;
}


// Set Substats
void CharUnit::setTotalSubstats(int Value) {
    this->Total_substats = Value;
    this->Substats[0].second = Value;
    this->bestSubstats.resize(this->Substats.size());
}
void CharUnit::pushSubstats(Stats StatsType) {
    this->Substats.push_back({StatsType, 0});
}
int CharUnit::changeTotalSubStats(int amount) {
    if(this->Total_substats + amount < 0)amount = -this->Total_substats;
    this->Total_substats += amount;
    this->Substats[0].second += amount;
    return -1*amount;
}
