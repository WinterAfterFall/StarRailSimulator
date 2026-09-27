#include "../include.h"


//SetReuqirements
void CharUnit::setSpeed(double speed) {
    this->speedRequire = speed;
}
void CharUnit::newSpeedRequire(double amount){
    if(this->speedRequire<amount)this->speedRequire = amount;
}

void CharUnit::newApplyBaseChanceRequire(double amount){
    if(this->applyBaseChance == 0 || this->applyBaseChance > amount)this->applyBaseChance = amount;
}
void CharUnit::newEhrRequire(double amount){
    if(this->ehrRequire<amount)this->ehrRequire = amount;
}


// Set Substats
void CharUnit::setTotalSubstats(int value) {
    this->totalSubstats = value;
    this->substats[0].second = value;
    this->bestSubstats.resize(this->substats.size());
}
void CharUnit::pushSubstats(Stats statsType) {
    this->substats.push_back({statsType, 0});
}
int CharUnit::changeTotalSubStats(int amount) {
    if(this->totalSubstats + amount < 0)amount = -this->totalSubstats;
    this->totalSubstats += amount;
    this->substats[0].second += amount;
    return -1*amount;
}
