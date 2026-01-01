#include "../include.h"

//Is have to buff
    bool isHaveToAddBuff(AllyUnit *ptr,string Buff_name);
    bool isHaveToAddBuff(AllyUnit *ptr,string Buff_name,int extend);

//เช็คบัพว่าจบหรือยัง 
    bool isBuffEnd(AllyUnit *ptr,string Buff_name);
    bool isBuffGoneByDeath(AllyUnit *ptr,string Buff_name);

//Extend buff time
    void extendBuffTime(AllyUnit *ptr,string Buff_name,int Turn_extend);
    void extendBuffTime(CharUnit *ptr,string Buff_name,int Turn_extend);
    void extendBuffTimeAllAlly(string Buff_name, int Turn_extend);
    void extendBuffTimeTargets(vector<AllyUnit*> target,string Buff_name,int Turn_extend);
    void extendBuffTimeExcludingBuffer(string Buffer_name,string Buff_name, int Turn_extend);
    void extendBuffTimeExcludingBuffer(AllyUnit *Buffer,std::string Buff_name, int Turn_extend);
    void extendBuffTimeExcludingBuffer(string Buffer_name,vector<AllyUnit*> target,std::string Buff_name, int Turn_extend);
    void extendBuffTimeExcludingBuffer(AllyUnit *Buffer,vector<AllyUnit*> target,std::string Buff_name, int Turn_extend);

//buff เดี่ยว
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet);
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend);
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet);
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend);
//buff เดี่ยวแต่ให้ Memosprite ของคนนั้นด้วย
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet);
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet);
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet,string Buff_name,int extend);
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet,string Buff_name,int extend);
//buff Memosprite ทุกตัว
    void buffAllMemosprite(std::vector<BuffClass> buffSet);
    void buffAllMemosprite(std::vector<BuffElementClass> buffSet);
    void buffAllMemosprite(std::vector<BuffClass> buffSet, std::string Buff_name, int extend);
    void buffAllMemosprite(std::vector<BuffElementClass> buffSet, std::string Buff_name, int extend);
//buff ทุกคน
    void buffAllAlly(std::vector<BuffClass> buffSet);
    void buffAllAlly(std::vector<BuffElementClass> buffSet);
    void buffAllAlly(std::vector<BuffClass> buffSet, std::string Buff_name, int extend);
    void buffAllAlly(std::vector<BuffElementClass> buffSet, std::string Buff_name, int extend);
//buff เป้าหมายที่กำหนด
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet, std::string Buff_name, int extend);
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet, std::string Buff_name, int extend);
//buff ทุกคน ยกเว้นผู้บัพ    
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet,string Buff_name,int Turn_extend);
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet,string Buff_name,int Turn_extend);
//buff เป้าหมายที่กำหนด ยกเว้นผู้บัพ 
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet,string Buff_name,int Turn_extend);
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet,string Buff_name,int Turn_extend);














