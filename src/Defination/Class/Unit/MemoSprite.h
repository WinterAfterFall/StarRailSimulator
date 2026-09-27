#ifndef MEMOSPRITE_H
#define MEMOSPRITE_H
#include <bits/stdc++.h>
#include "AllyUnit.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

class Memosprite : public AllyUnit {
public:
    double unitSpeedRatio = 0;
    double unitHpRatio = 0 ;
    double fixHP = 0;
    double fixSpeed = 0;

    Memosprite() : AllyUnit() {

    }
    ~Memosprite() {}


};
#endif