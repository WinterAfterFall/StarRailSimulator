#include "../include.h"

//Is have to buff
    bool isHaveToAddBuff(AllyUnit *ptr,string Buff_name){
        if(ptr->Buff_check[Buff_name]==1){
            return false;
        }
        ptr->Buff_check[Buff_name] = 1;
        return true;
    }
    bool isHaveToAddBuff(AllyUnit *ptr,string Buff_name,int extend){
        extendBuffTime(ptr,Buff_name,extend);
        if(ptr->Buff_check[Buff_name]==1){
            return false;
        }
        ptr->Buff_check[Buff_name] = 1;
        return true;
    }

//เช็คบัพว่าจบหรือยัง 
    bool isBuffEnd(AllyUnit *ptr,string Buff_name){
        if(ptr->Atv_stats->turnCnt==ptr->Buff_countdown[Buff_name]&&turn->Name==ptr->Atv_stats->Name){
            ptr->Buff_check[Buff_name] = 0;
            ptr->Buff_countdown[Buff_name] = 0;
            return true;
        }
        return false;
    }
    bool isBuffGoneByDeath(AllyUnit *ptr,string Buff_name){
        if(ptr->getBuffCheck(Buff_name)){
            ptr->Buff_check[Buff_name] = 0;
            ptr->Buff_countdown[Buff_name] = 0;
            return true;
        }
        return false;
    }

//Extend
    void extendBuffTime(AllyUnit *ptr,string Buff_name,int Turn_extend){
        ptr->Buff_countdown[Buff_name] = ptr->Atv_stats->turnCnt+Turn_extend;
    }
    void extendCharBuffTime(CharUnit *ptr,string Buff_name,int Turn_extend){
        extendBuffTime(ptr,Buff_name,Turn_extend);
        for(auto &each : ptr->memospriteList){
            extendBuffTime(each.get(),Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeAllAlly(string Buff_name,int Turn_extend){
        for(auto &each : allyList){
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeTargets(vector<AllyUnit*> target,string Buff_name,int Turn_extend){
        for(auto &each : target){
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeExcludingBuffer(string Buffer_name,string Buff_name,int Turn_extend){
        for(auto &each : allyList){
            if(each->isSameName(Buffer_name))continue;
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeExcludingBuffer(AllyUnit *Buffer,string Buff_name,int Turn_extend){
        for(auto &each : allyList){
            if(each->isSameName(Buffer))continue;
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeExcludingBuffer(string Buffer_name,vector<AllyUnit*> target,std::string Buff_name, int Turn_extend){    
        for(auto &each : target){
            if(each->isSameName(Buffer_name))continue;
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }
    void extendBuffTimeExcludingBuffer(AllyUnit *Buffer,vector<AllyUnit*> target,std::string Buff_name, int Turn_extend){
            for(auto &each : target){
            if(each->isSameName(Buffer))continue;
            extendBuffTime(each,Buff_name,Turn_extend);
        }
    }

//buff เดี่ยว
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet){
        for(BuffClass &buff : buffSet){
            if(buff.statsType==Stats::FLAT_SPD||buff.statsType==Stats::SPD_P)ptr->speedBuff(buff);
            else ptr->Stats_type[buff.statsType][buff.actionType] += buff.value;
            if(buff.actionType==AType::None)StatsAdjust(ptr,buff.statsType);
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend){
        if(isHaveToAddBuff(ptr,buffName,extend)){
            for(BuffClass &buff : buffSet){
                if(buff.statsType==Stats::FLAT_SPD||buff.statsType==Stats::SPD_P)ptr->speedBuff(buff);
                else ptr->Stats_type[buff.statsType][buff.actionType] += buff.value;
                if(buff.actionType==AType::None)StatsAdjust(ptr,buff.statsType);
            }
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet){
        for(BuffElementClass &buff : buffSet){
            ptr->Stats_each_element[buff.statsType][buff.element][buff.actionType] += buff.value;
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend){
    if(isHaveToAddBuff(ptr,buffName,extend)){
        for(BuffElementClass &buff : buffSet){
            ptr->Stats_each_element[buff.statsType][buff.element][buff.actionType] += buff.value;
        }
    }
}

//buff เดี่ยวแต่ให้ Memosprite ของคนนั้นด้วย
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet){
        buffSingle(ptr,buffSet);
        for (auto &e : ptr->memospriteList) {
            buffSingle(e.get(),buffSet);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet){
        buffSingle(ptr,buffSet);
        for (auto &e : ptr->memospriteList) {
            buffSingle(e.get(),buffSet);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet,string Buff_name,int extend){
        buffSingle(ptr,buffSet,Buff_name,extend);
        for (auto &e : ptr->memospriteList) {
            buffSingle(e.get(),buffSet,Buff_name,extend);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet,string Buff_name,int extend){
        buffSingle(ptr,buffSet,Buff_name,extend);
        for (auto &e : ptr->memospriteList) {
            buffSingle(e.get(),buffSet,Buff_name,extend);
        }
    }   

//buff เฉพาะ Memosprite
    void buffAllMemosprite(vector<BuffClass> buffSet) {
        for (int i=1;i<=Total_ally;i++) {
            for (auto &memo : charUnit[i]->memospriteList) {
                buffSingle(memo.get(),buffSet);
            }
        }
    }
    void buffAllMemosprite(vector<BuffElementClass> buffSet) {
        for (int i=1;i<=Total_ally;i++) {
            for (auto &memo : charUnit[i]->memospriteList) {
                buffSingle(memo.get(),buffSet);
            }
        }
    }
    void buffAllMemosprite(vector<BuffClass> buffSet, string Buff_name,int extend) {
        for (int i=1;i<=Total_ally;i++) {
            for (auto &memo : charUnit[i]->memospriteList) {
                buffSingle(memo.get(),buffSet,Buff_name,extend);
            }
        }
    }
    void buffAllMemosprite(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
        for (int i=1;i<=Total_ally;i++) {
            for (auto &memo : charUnit[i]->memospriteList) {
                buffSingle(memo.get(),buffSet,Buff_name,extend);
            }
        }
    }

//buff ทุกคน
    void buffAllAlly(vector<BuffClass> buffSet) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet);
        }
    }
    void buffAllAlly(vector<BuffElementClass> buffSet) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet);
        }
    }
    void buffAllAlly(vector<BuffClass> buffSet, string Buff_name,int extend) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet,Buff_name,extend);
        }
    }
    void buffAllAlly(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet,Buff_name,extend);
        }
    }
    
//buff เป้าหมายที่กำหนด
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet){
        for (auto &each : target) {
            buffSingle(each,buffSet);
        }
    }
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet){
        for (auto &each : target) {
            buffSingle(each,buffSet);
        }
    }
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet, std::string Buff_name, int extend){
        for (auto &each : target) {
            buffSingle(each,buffSet,Buff_name,extend);
        }
    }
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet, std::string Buff_name, int extend){
        for (auto &each : target) {
            buffSingle(each,buffSet,Buff_name,extend);
        }
    }

//buff ทุกคน ยกเว้นผู้บัพ 
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet){
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet);
        }
    }
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet) {
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet);
        }
    }
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, string Buff_name,int extend) {
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,Buff_name,extend);
        }
    }
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, string Buff_name,int extend) {
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,Buff_name,extend);
        }
    }

//buff เป้าหมายที่กำหนด ยกเว้นผู้บัพ 
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target, vector<BuffClass> buffSet) {
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet);
        }
    }
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet){
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet);
        }
    }
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet,string Buff_name,int Turn_extend){
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,Buff_name,Turn_extend);
        }
    }
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet,string Buff_name,int Turn_extend){
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,Buff_name,Turn_extend);
        }
    }