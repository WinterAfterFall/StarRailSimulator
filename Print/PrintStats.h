#ifndef PRINTSTATS_H
#define PRINTSTATS_H
#include<bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
using std::cout ;
using std::vector;
#include"../Unit/Trigger_Function.h"
void SubUnit::printHpStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Current HP: " << this->currentHP << " ";
    cout << "Total HP: " << this->totalHP << " ";
    cout << "Base HP: " << this->Base_hp << " ";
    cout << "HP Percent: " << this->Stats_type[ST_HP_PERCENT][AT_NONE] << " ";
    cout << "Flat HP: " << this->Stats_type[ST_FLAT_HP][AT_NONE] << " ";
    cout<<endl;
}
void SubUnit::printCritStats(){
    cout<<this->Atv_stats->Unit_Name<<" ";
    cout << "Crit rate : " << this->Stats_type[ST_CRIT_RATE][AT_NONE] << " ";
    cout << "Crit dam : " << this->Stats_type[ST_CRIT_DAM][AT_NONE] << " ";
    cout<<endl;
}
#endif