#ifndef TARGET_CHOOSE_H
#define TARGET_CHOOSE_H
#include<bits/stdc++.h>
#include "../Unit/Trigger_Function.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000

void SubUnit::addTargetChangeCondition(function<bool()> condition) {
    changeTargetCondition.push_back(condition);
}

void SubUnit::addTargetChangeConditionImmediately(function<bool()> condition) {
    changeTargetImmediatelyCondtion.push_back(condition);
}

#endif