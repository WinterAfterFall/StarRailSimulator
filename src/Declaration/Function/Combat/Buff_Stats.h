#include "../include.h"

//Is have to buff
    bool isHaveToAddBuff(AllyUnit *ptr,string buffName);
    bool isHaveToAddBuff(AllyUnit *ptr,string buffName,int extend);

//เช็คบัพว่าจบหรือยัง 
    bool isBuffEnd(AllyUnit *ptr,string buffName);
    bool isBuffGoneByDeath(AllyUnit *ptr,string buffName);

//Extend buff time
    void extendBuffTime(AllyUnit *ptr,string buffName,int turnExtend);
    void extendCharBuffTime(CharUnit *ptr,string buffName,int turnExtend);
    void extendBuffTimeAllAlly(string buffName, int turnExtend);
    void extendBuffTimeTargets(vector<AllyUnit*> target,string buffName,int turnExtend);
    void extendBuffTimeExcludingBuffer(string bufferName,string buffName, int turnExtend);
    void extendBuffTimeExcludingBuffer(AllyUnit *buffer,std::string buffName, int turnExtend);
    void extendBuffTimeExcludingBuffer(string bufferName,vector<AllyUnit*> target,std::string buffName, int turnExtend);
    void extendBuffTimeExcludingBuffer(AllyUnit *buffer,vector<AllyUnit*> target,std::string buffName, int turnExtend);

//buff เดี่ยว
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet);
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend);
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet);
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend);
//buff เดี่ยวแต่ให้ Memosprite ของคนนั้นด้วย
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet);
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet);
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend);
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend);
//buff Memosprite ทุกตัว
    void buffAllMemosprite(std::vector<BuffClass> buffSet);
    void buffAllMemosprite(std::vector<BuffElementClass> buffSet);
    void buffAllMemosprite(std::vector<BuffClass> buffSet, std::string buffName, int extend);
    void buffAllMemosprite(std::vector<BuffElementClass> buffSet, std::string buffName, int extend);
//buff ทุกคน
    void buffAllAlly(std::vector<BuffClass> buffSet);
    void buffAllAlly(std::vector<BuffElementClass> buffSet);
    void buffAllAlly(std::vector<BuffClass> buffSet, std::string buffName, int extend);
    void buffAllAlly(std::vector<BuffElementClass> buffSet, std::string buffName, int extend);
//buff เป้าหมายที่กำหนด
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet, std::string buffName, int extend);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet, std::string buffName, int extend);
//buff ทุกคน ยกเว้นผู้บัพ    
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet,string buffName,int turnExtend);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int turnExtend);
//buff เป้าหมายที่กำหนด ยกเว้นผู้บัพ 
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet,string buffName,int turnExtend);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet,string buffName,int turnExtend);














