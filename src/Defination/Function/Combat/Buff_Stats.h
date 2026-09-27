#include "../include.h"

//Is have to buff
    bool isHaveToAddBuff(AllyUnit *ptr,string buffName){
        if(ptr->buffCheck[buffName]==1){
            return false;
        }
        ptr->buffCheck[buffName] = 1;
        return true;
    }
    bool isHaveToAddBuff(AllyUnit *ptr,string buffName,int extend){
        extendBuffTime(ptr,buffName,extend);
        if(ptr->buffCheck[buffName]==1){
            return false;
        }
        ptr->buffCheck[buffName] = 1;
        return true;
    }

//เช็คบัพว่าจบหรือยัง 
    bool isBuffEnd(AllyUnit *ptr,string buffName){
        if(ptr->atvStats->turnCnt==ptr->buffEnd[buffName]&&turn->name==ptr->atvStats->name){
            ptr->buffCheck[buffName] = 0;
            ptr->buffEnd[buffName] = 0;
            return true;
        }
        return false;
    }
    bool isBuffGoneByDeath(AllyUnit *ptr,string buffName){
        if(ptr->getBuffCheck(buffName)){
            ptr->buffCheck[buffName] = 0;
            ptr->buffEnd[buffName] = 0;
            return true;
        }
        return false;
    }

//Extend
    void extendBuffTime(AllyUnit *ptr,string buffName,int turnExtend){
        ptr->buffEnd[buffName] = ptr->atvStats->turnCnt+turnExtend;
    }
    void extendCharBuffTime(CharUnit *ptr,string buffName,int turnExtend){
        extendBuffTime(ptr,buffName,turnExtend);
        if(auto *each = ptr->memosprite.get()){
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeAllAlly(string buffName,int turnExtend){
        for(auto &each : allyList){
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeTargets(vector<AllyUnit*> target,string buffName,int turnExtend){
        for(auto &each : target){
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeExcludingBuffer(string bufferName,string buffName,int turnExtend){
        for(auto &each : allyList){
            if(each->isSameName(bufferName))continue;
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeExcludingBuffer(AllyUnit *buffer,string buffName,int turnExtend){
        for(auto &each : allyList){
            if(each->isSameName(buffer))continue;
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeExcludingBuffer(string bufferName,vector<AllyUnit*> target,std::string buffName, int turnExtend){    
        for(auto &each : target){
            if(each->isSameName(bufferName))continue;
            extendBuffTime(each,buffName,turnExtend);
        }
    }
    void extendBuffTimeExcludingBuffer(AllyUnit *buffer,vector<AllyUnit*> target,std::string buffName, int turnExtend){
            for(auto &each : target){
            if(each->isSameName(buffer))continue;
            extendBuffTime(each,buffName,turnExtend);
        }
    }

//buff เดี่ยว
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet){
        for(BuffClass &buff : buffSet){
            if(buff.statsType==Stats::FLAT_SPD||buff.statsType==Stats::SPD_P){
                ptr->speedBuff(buff);
                ahaSpeedAdjust(ptr->owner->path);
            }
            else ptr->statsType[buff.statsType][buff.actionType] += buff.value;
            if(buff.actionType==AType::NONE)statsAdjust(ptr,buff.statsType);
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend){
        if(isHaveToAddBuff(ptr,buffName,extend)){
            for(BuffClass &buff : buffSet){
                if(buff.statsType==Stats::FLAT_SPD||buff.statsType==Stats::SPD_P){
                    ptr->speedBuff(buff);
                    ahaSpeedAdjust(ptr->owner->path);
                }
                else ptr->statsType[buff.statsType][buff.actionType] += buff.value;
                if(buff.actionType==AType::NONE)statsAdjust(ptr,buff.statsType);
            }
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet){
        for(BuffElementClass &buff : buffSet){
            ptr->statsEachElement[buff.statsType][buff.element][buff.actionType] += buff.value;
        }
    }
    void buffSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend){
    if(isHaveToAddBuff(ptr,buffName,extend)){
        for(BuffElementClass &buff : buffSet){
            ptr->statsEachElement[buff.statsType][buff.element][buff.actionType] += buff.value;
        }
    }
}

//buff เดี่ยวแต่ให้ Memosprite ของคนนั้นด้วย
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet){
        buffSingle(ptr,buffSet);
        if(auto *e = ptr->memosprite.get()){
            buffSingle(e,buffSet);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet){
        buffSingle(ptr,buffSet);
        if(auto *e = ptr->memosprite.get()){
            buffSingle(e,buffSet);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffClass> buffSet,string buffName,int extend){
        buffSingle(ptr,buffSet,buffName,extend);
        if(auto *e = ptr->memosprite.get()){
            buffSingle(e,buffSet,buffName,extend);
        }
    }
    void buffSingleChar(CharUnit *ptr,vector<BuffElementClass> buffSet,string buffName,int extend){
        buffSingle(ptr,buffSet,buffName,extend);
        if(auto *e = ptr->memosprite.get()){
            buffSingle(e,buffSet,buffName,extend);
        }
    }   

//buff เฉพาะ Memosprite
    void buffAllMemosprite(vector<BuffClass> buffSet) {
        for (int i=1;i<=totalAlly;i++) {
            if(auto *memo = charUnit[i]->memosprite.get()){
                buffSingle(memo,buffSet);
            }
        }
    }
    void buffAllMemosprite(vector<BuffElementClass> buffSet) {
        for (int i=1;i<=totalAlly;i++) {
            if(auto *memo = charUnit[i]->memosprite.get()){
                buffSingle(memo,buffSet);
            }
        }
    }
    void buffAllMemosprite(vector<BuffClass> buffSet, string buffName,int extend) {
        for (int i=1;i<=totalAlly;i++) {
            if(auto *memo = charUnit[i]->memosprite.get()){
                buffSingle(memo,buffSet,buffName,extend);
            }
        }
    }
    void buffAllMemosprite(vector<BuffElementClass> buffSet, string buffName,int extend) {
        for (int i=1;i<=totalAlly;i++) {
            if(auto *memo = charUnit[i]->memosprite.get()){
                buffSingle(memo,buffSet,buffName,extend);
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
    void buffAllAlly(vector<BuffClass> buffSet, string buffName,int extend) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet,buffName,extend);
        }
    }
    void buffAllAlly(vector<BuffElementClass> buffSet, string buffName,int extend) {
        for (auto &e : allyList) {
            buffSingle(e,buffSet,buffName,extend);
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
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffClass> buffSet, std::string buffName, int extend){
        for (auto &each : target) {
            buffSingle(each,buffSet,buffName,extend);
        }
    }
    void buffTargets(vector<AllyUnit*> target,std::vector<BuffElementClass> buffSet, std::string buffName, int extend){
        for (auto &each : target) {
            buffSingle(each,buffSet,buffName,extend);
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
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet, string buffName,int extend) {
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,buffName,extend);
        }
    }
    void buffAllAllyExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet, string buffName,int extend) {
        for (auto &each : allyList) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,buffName,extend);
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
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffClass> buffSet,string buffName,int turnExtend){
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,buffName,turnExtend);
        }
    }
    void buffTargetsExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> target,vector<BuffElementClass> buffSet,string buffName,int turnExtend){
        for (auto &each : target) {
            if (ptr->isSameName(each)) continue;
            buffSingle(each,buffSet,buffName,turnExtend);
        }
    }