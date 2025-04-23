#ifndef Unit_H
#define Unit_H
#include <bits/stdc++.h>
#include "ActionValueStats.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




// Action value stats for a unit (atv)
class Unit {
public:
    unique_ptr<ActionValueStats> Atv_stats;  // Moved Atv_stats here to be shared by both Ally and Enemy
    function<void()> Turn_func ;
    Common_stats_each_element Stats_each_element;//Ice Quantum
    Common_stats_type Stats_type;// Atk% Flat_Atk Def% Dmg% Crit_rate Crit_dam Def_shred Respen Vul Break_effect Weakness_Break_Efficiency HealingBonus 
    // Constructor to initialize Atv_stats and set ptr_to_unit to 'this'
    Unit() {
        Atv_stats = make_unique<ActionValueStats>();  // Create Atv_stats in Unit
        Atv_stats->ptr_to_unit = this;  // Set ptr_to_unit to this object (Unit, Ally, or Enemy)
    }
       
    //double Mitigation = 0;
    int getNum(){
        return this->Atv_stats->Unit_num;
    }
    int getUnitName(){
        return this->Atv_stats->Unit_Name
    }
    int getCharName(){
        return this->Atv_stats->Char_Name;
    }
    void speedBuff(BuffClass buffSet){
        if(buffSet.actionType==ST_FLAT_SPD)this->Atv_stats->speedBuff(0,buffSet.value);
        else this->Atv_stats->speedBuff(buffSet.value,0);
    }
    void resetATV(){
        this->Atv_stats->resetATV();
    }
    void resetATV(double baseSpeed){
        this->Atv_stats->resetATV(baseSpeed);
    }
    SubUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();
    
    virtual ~Unit() {}  // Virtual destructor to ensure proper cleanup of derived classes
};
#endif