#include "include.h"
void AllyUnit::printHpStats(){
    cout<<this->atvStats->name<<" ";
    cout << "Current HP: " << this->currentHP << " ";
    cout << "Total HP: " << this->totalHP << " ";
    cout << "Base HP: " << this->baseHp << " ";
    cout << "HP Percent: " << this->statsType[Stats::HP_P][AType::NONE] << " ";
    cout << "Flat HP: " << this->statsType[Stats::FLAT_HP][AType::NONE] << " ";
    cout<<endl;
}
void AllyUnit::printCritStats(){
    cout<<this->atvStats->name<<" ";
    cout << "Crit rate : " << this->statsType[Stats::CR][AType::NONE] << " ";
    cout << "Crit dam : " << this->statsType[Stats::CD][AType::NONE] << " ";
    cout<<endl;
}