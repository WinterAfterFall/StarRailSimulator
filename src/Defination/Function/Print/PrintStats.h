#include "include.h"
void AllyUnit::printHpStats(){
    cout<<this->Atv_stats->Name<<" ";
    cout << "Current HP: " << this->currentHP << " ";
    cout << "Total HP: " << this->totalHP << " ";
    cout << "Base HP: " << this->baseHp << " ";
    cout << "HP Percent: " << this->Stats_type[Stats::HP_P][AType::None] << " ";
    cout << "Flat HP: " << this->Stats_type[Stats::FLAT_HP][AType::None] << " ";
    cout<<endl;
}
void AllyUnit::printCritStats(){
    cout<<this->Atv_stats->Name<<" ";
    cout << "Crit rate : " << this->Stats_type[Stats::CR][AType::None] << " ";
    cout << "Crit dam : " << this->Stats_type[Stats::CD][AType::None] << " ";
    cout<<endl;
}