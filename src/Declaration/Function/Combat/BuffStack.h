#include "../include.h"

void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackTargets(vector<SubUnit*> targets, vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackTargets(vector<SubUnit*> targets,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackTargets(vector<SubUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackTargets(vector<SubUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend);

void buffResetStackAllAlly(vector<BuffClass> buffSet, string Stack_Name);
void buffResetStackAllAlly(vector<BuffElementClass> buffSet, string Stack_Name);