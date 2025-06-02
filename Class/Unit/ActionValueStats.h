#ifndef ACTION_VALUE_STATS_H
#define ACTION_VALUE_STATS_H
#include <bits/stdc++.h>
#include "../../Setting/Control_panel.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




// Action value stats for a unit (atv)
class ActionValueStats {
public:
    double baseSpeed = 0.01;
    double flatSpeed = 0;
    double speedPercent = 0;
    double atv;
    double Max_atv;
    int turnCnt = 0;
    int num = 0;
    string Side;//Memosprite Ally Summon
    string Type;
    int priority = 0;
    string Char_Name;
    string Unit_Name;//ชื่อเจ้าของเทิร์น

    Unit* ptrToChar = nullptr; //* // This will be set to point back to the unit (Ally or Enemy)

#pragma region Get Method
    double getBaseSpeed(){
        return baseSpeed;
    }
    double getFlatSpeed(){
        return flatSpeed;
    }
    double getSpeedPercent(){
        return speedPercent;
    }
    double getATV(){
        return atv;
    }
    double getMaxATV(){
        return Max_atv;
    }
    int getTurnCnt(){
        return turnCnt;
    }
    int getUnitNum(){
        return num;
    }
    string getSide(){
        return Side;
    }
    string getType(){
        return Type;
    }
    int getPriority(){
        return priority;
    }
    string getCharName(){
        return Char_Name;
    }
    string getUnitName(){
        return Unit_Name;
    }
    Unit* getPtrToChar(){
        return ptrToChar;
    }
#pragma endregion

#pragma region Set Method
    void setBaseSpeed(double baseSpeed){
        this->baseSpeed = baseSpeed;
    }
    void setFlatSpeed(double flatSpeed) {
        this->flatSpeed = flatSpeed;
    }
    void setSpeedPercent(double speedPercent) {
        this->speedPercent = speedPercent;
    }
    void setATV(double atv) {
        this->atv = atv;
    }
    void setMaxATV(double Max_atv) {
        this->Max_atv = Max_atv;
    }
    void setTurnCnt(int turn_cnt) {
        this->turnCnt = turn_cnt;
    }
    void setUnitNum(int Unit_num) {
        this->num = Unit_num;
    }
    void setSide(string Side) {
        this->Side = Side;
    }
    void setType(string Type) {
        this->Type = Type;
    }
    void setPriority(int priority) {
        this->priority = priority;
    }
    void setCharName(string Char_Name) {
        this->Char_Name = Char_Name;
    }
    void setUnitName(string Unit_Name) {
        this->Unit_Name = Unit_Name;
    }
#pragma endregion

#pragma region Check Method
    bool isSameCharName(const string& name) {
        return this->Char_Name == name;
    }
    bool isSameUnitName(const string& name) {
        return this->Unit_Name == name;
    }
    bool isSameNum(int num) {
        return this->num == num;
    }
    bool isSameChar(Unit* ptr);
    bool isSameUnit(Unit* ptr);
    bool isSameNum(Unit* ptr);
#pragma endregion
    SubUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();
#pragma region SpeedCombat Function
    void speedBuff(double spd_percent ,double flat_spd);
    void resetATV();
    void resetATV(double baseSpeed);
#pragma endregion

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
    ElementType element;
    string actionType;
    double value;
};

#endif