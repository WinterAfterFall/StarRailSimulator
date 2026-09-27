#include "../include.h"

void buffStackAllAlly(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackAllAlly(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);

void buffStackAllMemosprite(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackAllMemosprite(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);

void buffStackTargets(vector<AllyUnit*> targets, vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend);

void buffResetStackAllAlly(vector<BuffClass> buffSet, string stackName);
void buffResetStackAllAlly(vector<BuffElementClass> buffSet, string stackName);


    //Stack.h AllyUnit
    pair<int,int> calStack(AllyUnit *ptr,int stackIncrease,int stackLimit,string buffName);
    void buffResetStack(AllyUnit *ptr,vector<BuffClass> buffSet,string stackName);
    void buffResetStack(AllyUnit *ptr,vector<BuffElementClass> buffSet,string stackName);

    void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackNam);
    void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackNam,int extend);
    void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackNam);
    void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackNam,int extend);

    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend);

    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend);


    //StackBuff.h charunit
    void buffCharResetStack(CharUnit *ptr,vector<BuffClass> buffSet,string stackName);
    void buffCharResetStack(CharUnit *ptr,vector<BuffElementClass> buffSet,string stackName);
    
    void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName);
    void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend);
    void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName);
    void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackNam,int extend);