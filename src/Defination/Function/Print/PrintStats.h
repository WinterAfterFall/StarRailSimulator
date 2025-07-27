#include "include.h"
void SubUnit::printHpStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Current HP: " << this->currentHP << " ";
    cout << "Total HP: " << this->totalHP << " ";
    cout << "Base HP: " << this->baseHp << " ";
    cout << "HP Percent: " << this->Stats_type[Stats::HP_P][AType::None] << " ";
    cout << "Flat HP: " << this->Stats_type[Stats::FLAT_HP][AType::None] << " ";
    cout<<endl;
}
void SubUnit::printCritStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Crit rate : " << this->Stats_type[Stats::CR][AType::None] << " ";
    cout << "Crit dam : " << this->Stats_type[Stats::CD][AType::None] << " ";
    cout<<endl;
}