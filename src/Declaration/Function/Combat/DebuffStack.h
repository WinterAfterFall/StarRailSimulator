#include "../include.h"

void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackEnemyTargets(vector<Enemy*> targets,vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackEnemyTargets(vector<Enemy*> targets,vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackEnemyTargets(vector<Enemy*> targets,vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackEnemyTargets(vector<Enemy*> targets,vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
