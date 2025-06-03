#include "include.h"
void SubUnit::printHpStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Current HP: " << this->currentHP << " ";
    cout << "Total HP: " << this->totalHP << " ";
    cout << "Base HP: " << this->baseHp << " ";
    cout << "HP Percent: " << this->Stats_type[ST_HP_P][AT_NONE] << " ";
    cout << "Flat HP: " << this->Stats_type[ST_FLAT_HP][AT_NONE] << " ";
    cout<<endl;
}
void SubUnit::printCritStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Crit rate : " << this->Stats_type[ST_CR][AT_NONE] << " ";
    cout << "Crit dam : " << this->Stats_type[ST_CD][AT_NONE] << " ";
    cout<<endl;
}