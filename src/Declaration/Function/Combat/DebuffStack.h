#include "../include.h"

void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName);
void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName);
void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend);
void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend);
void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend);

    //Stack
    int debuffRemoveStack(Enemy *enemy,string debuffName);
    pair<int,int> calDebuffStack(AllyUnit *ptr,Enemy *enemy,string debuffName,int stackIncrease,int stackLimit);
    void debuffStackRemove(Enemy *enemy,vector<BuffClass> buffSet,string debuffName);
    void debuffStackRemove(Enemy *enemy,vector<BuffElementClass> buffSet,string debuffName);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName,int extend);
    void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName,int extend);