#include "../include.h"

void extendDebuffAll(string Debuff_name,int Turn_extend);
void extendDebuffTargets(vector<Enemy*> targets,string Debuff_name,int Turn_extend);

void debuffAllEnemy(vector<BuffClass> debuffSet);
void debuffAllEnemy(vector<BuffElementClass> debuffSet);
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffClass> debuffSet);
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffElementClass> debuffSet);

void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string Debuff_Name);
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string Debuff_Name);
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string Debuff_Name,int extend);
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string Debuff_Name,int extend);
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string Debuff_Name);
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string Debuff_Name);
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string Debuff_Name,int extend);
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string Debuff_Name,int extend);

void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend);
void debuffEnemyTargetsyMark(vector<Enemy*> targets,vector<BuffClass> debuffSet,AllyUnit *ptr, string Debuff_Name);
void debuffEnemyTargetsyMark(vector<Enemy*> targets,vector<BuffElementClass> debuffSet,AllyUnit *ptr, string Debuff_Name);
void debuffEnemyTargetsyMark(vector<Enemy*> targets,vector<BuffClass> debuffSet,AllyUnit *ptr, string Debuff_Name,int extend);
void debuffEnemyTargetsyMark(vector<Enemy*> targets,vector<BuffElementClass> debuffSet,AllyUnit *ptr, string Debuff_Name,int extend);


    //debuff.h
    bool debuffApply(AllyUnit *ptr,Enemy *enemy, string debuffName);
    bool debuffApply(AllyUnit *ptr,Enemy *enemy, string debuffName,int extend);
    bool debuffMark(AllyUnit *ptr,Enemy *enemy, string debuffName);
    bool debuffMark(AllyUnit *ptr,Enemy *enemy, string debuffName,int extend);
    void debuffRemove(Enemy *enemy,string debuffName);

    vector<ElementType> weaknessApplyChoose(AllyUnit *ptr,Enemy *enemy,int amount,string debuffName,int extend);
    void weaknessApply(AllyUnit *ptr,Enemy *enemy,vector<ElementType> elementList,int extend);
    void weaknessApply(AllyUnit *ptr,Enemy *enemy,vector<ElementType> elementList ,string debuffName,int extend);
    
    bool isDebuffEnd(Enemy *enemy,string Debuff_name);
    void extendDebuff(Enemy *enemy,string Debuff_name,int Turn_extend);
    
    //Single target
    void debuffSingle(Enemy *enemy,vector<BuffClass> debuffSet);
    void debuffSingle(Enemy *enemy,vector<BuffElementClass> debuffSet);
    void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName);
    void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName);
    void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName);
    void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName);
    void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName ,int extend);
    void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet ,string debuffName ,int extend);
    void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName, int extend);
    void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName, int extend);