#include "../include.h"

void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend);

    //Stack
    int debuffRemoveStack(Enemy *enemy,string debuffName);
    pair<int,int> calDebuffStack(AllyUnit *ptr,Enemy *enemy,string debuffName,int Stack_increase,int StackLimit);
    void debuffStackRemove(Enemy *enemy,vector<BuffClass> buffSet,string debuffName);
    void debuffStackRemove(Enemy *enemy,vector<BuffElementClass> buffSet,string debuffName);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name,int extend);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name,int extend);