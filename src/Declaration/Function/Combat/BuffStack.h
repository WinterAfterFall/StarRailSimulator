#include "../include.h"

void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);

void buffStackAllMemosprite(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllMemosprite(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);

void buffStackTargets(vector<AllyUnit*> targets, vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);

void buffResetStackAllAlly(vector<BuffClass> buffSet, string Stack_Name);
void buffResetStackAllAlly(vector<BuffElementClass> buffSet, string Stack_Name);


    //Stack.h AllyUnit
    pair<int,int> calStack(AllyUnit *ptr,int Stack_increase,int StackLimit,string buffName);
    void buffResetStack(AllyUnit *ptr,vector<BuffClass> buffSet,string Stack_Name);
    void buffResetStack(AllyUnit *ptr,vector<BuffElementClass> buffSet,string Stack_Name);

    void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam);
    void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam,int extend);
    void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam);
    void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam,int extend);

    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);

    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets,vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);


    //StackBuff.h charunit
    void buffResetStack(CharUnit *ptr,vector<BuffClass> buffSet,string Stack_Name);
    void buffResetStack(CharUnit *ptr,vector<BuffElementClass> buffSet,string Stack_Name);
    
    void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend);
    void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Nam,int extend);