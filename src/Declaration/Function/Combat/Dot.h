#include "../include.h"

void dotAllEnemyApply(vector<DotType> dotType, SubUnit *ptr, string dotName);
void dotAllEnemyApply(vector<DotType> dotType, SubUnit *ptr, string dotName,int extend);
void dotEnemyTargetsApply(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName);
void dotEnemyTargetsApply(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName,int extend);

void dotAllEnemyMark(vector<DotType> dotType, SubUnit *ptr, string dotName);
void dotAllEnemyMark(vector<DotType> dotType, SubUnit *ptr, string dotName,int extend);
void dotEnemyTargetsMark(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName);
void dotEnemyTargetsMark(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName,int extend);

void dotAllEnemyStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName);
void dotAllEnemyStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName,int extend);
void dotEnemyTargetsStack(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName);
void dotEnemyTargetsStack(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName,int extend);