#include "../include.h"

void extendDebuffAll(string Debuff_name,int Turn_extend);
void debuffAllEnemy(vector<BuffClass> debuffSet);
void debuffAllEnemy(vector<BuffElementClass> debuffSet);
void debuffAllEnemyApply(vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name);
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name);
void debuffAllEnemyApply(vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend);
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend);
void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);
