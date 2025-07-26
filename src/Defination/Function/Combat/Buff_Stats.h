#include "../include.h"

bool SubUnit::isBuffEnd(string Buff_name){
    if(this->Atv_stats->turnCnt==this->Buff_countdown[Buff_name]&&turn->Char_Name==this->Atv_stats->Char_Name){
        this->Buff_check[Buff_name] = 0;
        this->Buff_countdown[Buff_name] = 0;
        return true;
    }
    return false;
}
bool SubUnit::isBuffGoneByDeath(string Buff_name){
    if(this->getBuffCheck(Buff_name)){
        this->Buff_check[Buff_name] = 0;
        this->Buff_countdown[Buff_name] = 0;
        return true;
    }
    return false;
}
bool SubUnit::isHaveToAddBuff(string Buff_name){
    if(this->Buff_check[Buff_name]==1){
        return false;
    }
    Buff_check[Buff_name] = 1;
    return true;
}
bool SubUnit::isHaveToAddBuff(string Buff_name,int extend){
    this->extendBuffTime(Buff_name,extend);
    if(this->Buff_check[Buff_name]==1){
        return false;
    }
    Buff_check[Buff_name] = 1;
    return true;
}
//Extend
void SubUnit::extendBuffTime(string Buff_name,int Turn_extend){
    this->Buff_countdown[Buff_name] = this->Atv_stats->turnCnt+Turn_extend;
}
void Ally::extendBuffTime(string Buff_name,int Turn_extend){
    for(int i=0;i<this->Sub_Unit_ptr.size();i++){
        this->Sub_Unit_ptr[i]->extendBuffTime(Buff_name,Turn_extend);
    }
}
void extendBuffTimeAllAlly(string Buff_name,int Turn_extend){
    for(int i=1;i<=Total_ally;i++){
        Ally_unit[i]->extendBuffTime(Buff_name,Turn_extend);
    }
}
void extendBuffTimeExcludingBuffer(string Buff_name,int Turn_extend,string Buffer_name){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->isSameUnitName(Buffer_name))continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,Turn_extend);
        }
    }
}
void extendBuffTimeExcludingBuffer(string Buff_name,int Turn_extend,SubUnit *Buffer){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->isSameUnit(Buffer))continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,Turn_extend);
        }
    }
}

void SubUnit::buffSingle(vector<BuffClass> buffSet){
    for(BuffClass &buff : buffSet){
        if(buff.statsType==ST_FLAT_SPD||buff.statsType==ST_SPD_P)this->speedBuff(buff);
        else this->Stats_type[buff.statsType][buff.actionType] += buff.value;
        if(buff.actionType==AType::None)StatsAdjust(this,buff.statsType);
    }
}
void SubUnit::buffSingle(vector<BuffClass> buffSet,string buffName,int extend){
    if(this->isHaveToAddBuff(buffName,extend)){
        for(BuffClass &buff : buffSet){
            if(buff.statsType==ST_FLAT_SPD||buff.statsType==ST_SPD_P)this->speedBuff(buff);
            else this->Stats_type[buff.statsType][buff.actionType] += buff.value;
            if(buff.actionType==AType::None)StatsAdjust(this,buff.statsType);
        }
    }
}
void SubUnit::buffSingle(vector<BuffElementClass> buffSet){
    for(BuffElementClass &buff : buffSet){
        this->Stats_each_element[buff.statsType][buff.element][buff.actionType] += buff.value;
    }
}
void SubUnit::buffSingle(vector<BuffElementClass> buffSet,string buffName,int extend){
    if(this->isHaveToAddBuff(buffName,extend)){
        for(BuffElementClass &buff : buffSet){
            this->Stats_each_element[buff.statsType][buff.element][buff.actionType] += buff.value;
        }
    }
}

void Ally::buffAlly(vector<BuffClass> buffSet){
    for (auto &e : this->Sub_Unit_ptr) {
        e->buffSingle(buffSet);
    }
}
void Ally::buffAlly(vector<BuffElementClass> buffSet){
    for (auto &e : this->Sub_Unit_ptr) {
        e->buffSingle(buffSet);
    }
}

void Ally::buffAlly(vector<BuffClass> buffSet,string Buff_name,int extend){
    for (auto &e : this->Sub_Unit_ptr) {
        e->buffSingle(buffSet,Buff_name,extend);
    }
}
void Ally::buffAlly(vector<BuffElementClass> buffSet,string Buff_name,int extend){
    for (auto &e : this->Sub_Unit_ptr) {
        e->buffSingle(buffSet,Buff_name,extend);
    }
}   

void buffAllAlly(vector<BuffClass> buffSet) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet);
        }
    }
}
void buffAllAlly(vector<BuffElementClass> buffSet) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet);
        }
    }
}

void buffAllAlly(vector<BuffClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet,Buff_name,extend);
        }
    }
}
void buffAllAlly(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet,Buff_name,extend);
        }
    }
}

void SubUnit::buffAllAllyExcludingBuffer(vector<BuffClass> buffSet){
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet);
        }
    }
}
void SubUnit::buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet);
        }
    }
}

void SubUnit::buffAllAllyExcludingBuffer(vector<BuffClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet,Buff_name,extend);
        }
    }
}
void SubUnit::buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffSingle(buffSet,Buff_name,extend);
        }
    }
}