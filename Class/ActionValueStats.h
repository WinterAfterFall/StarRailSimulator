#ifndef ACTION_VALUE_STATS_H
#define ACTION_VALUE_STATS_H
#include <bits/stdc++.h>
#include "../Setting/Control_panel.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




// Action value stats for a unit (atv)
class ActionValueStats {
public:
    double Base_speed = 0.01;//*
    double Flat_Speed = 0;
    double Speed_percent = 0;
    double atv ;//*
    double Max_atv;//*
    int turn_cnt = 0;
    int Unit_num = 0;//*
    string Side;//Memosprite Ally Summon
    string Type;
    int priority = 0;
    string Char_Name;
    string Unit_Name;//ชื่อเจ้าของเทิร์น

    Unit* ptr_to_unit = nullptr; //* // This will be set to point back to the unit (Ally or Enemy)

    bool isSameCharName(string name){
        if(this->Char_Name == name)return true;
        return false;
    }
    bool isSameUnitName(string name){
        if(this->Unit_Name == name)return true;
        return false;
    }
    bool isSameUnit(SubUnit *ptr);
    SubUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();

    void speedBuff(double spd_percent ,double flat_spd);
    void resetATV();
    void resetATV(double baseSpeed);

};
class BuffClass{
    public:
    string statsType;
    string actionType;
    double value;
};
class BuffElementClass{
    public:
    string statsType;
    string element;
    string actionType;
    double value;
};

#endif