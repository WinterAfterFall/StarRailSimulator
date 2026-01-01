#include "../include.h"

void dotAllEnemyApply(AllyUnit *ptr,vector<DotType> dotType,  string dotName);
void dotAllEnemyApply(AllyUnit *ptr,vector<DotType> dotType,  string dotName,int extend);
void dotEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  string dotName);
void dotEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  string dotName,int extend);

void dotAllEnemyMark(AllyUnit *ptr,vector<DotType> dotType,  string dotName);
void dotAllEnemyMark(AllyUnit *ptr,vector<DotType> dotType,  string dotName,int extend);
void dotEnemyTargetsMark(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  string dotName);
void dotEnemyTargetsMark(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  string dotName,int extend);

void dotAllEnemyStack(AllyUnit *ptr,vector<DotType> dotType,  int Stack_increase, int Stack_limit, string dotName);
void dotAllEnemyStack(AllyUnit *ptr,vector<DotType> dotType,  int Stack_increase, int Stack_limit, string dotName,int extend);
void dotEnemyTargetsStack(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  int Stack_increase, int Stack_limit, string dotName);
void dotEnemyTargetsStack(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,  int Stack_increase, int Stack_limit, string dotName,int extend);

    //Dot
    void dotSingleApply(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType,string dotName);
    void dotSingleApply(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType,string dotName, int extend);
    void dotSingleMark(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType,string dotName);
    void dotSingleMark(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType,string dotName, int extend);
    void dotSingleStack(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType, int Stack_increase, int Stack_limit, string dotName);
    void dotSingleStack(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType, int Stack_increase, int Stack_limit, string dotName,int extend);
    void dotRemove(Enemy *enemy,vector<DotType> dotType);
    int dotStackRemove(Enemy *enemy,vector<DotType> dotType,string dotName);