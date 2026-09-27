#ifndef STATSSET_H
#define STATSSET_H
#include "Enemy.h"

void CharUnit::setAllyBaseStats(double baseHp,double baseAtk,double baseDef){
        this->baseHp +=baseHp;
        this->baseAtk +=baseAtk;
        this->baseDef +=baseDef;
}
CharUnit* setCharBasicStats(double baseSpeed,double maxEnergy,double ultCost,int eidolon,ElementType elementType,Path path,string name,UnitType unitType){
        charUnit.push_back(make_unique<CharUnit>());
        totalAlly++;
        int num = totalAlly;
        allyList.push_back(charUnit[num].get());
        charList.push_back(charUnit[num].get());
        atvList.push_back(charUnit[num]->atvStats.get());
        charUnit[num]->atvStats->baseSpeed = baseSpeed;
        charUnit[num]->maxEnergy = maxEnergy;
        charUnit[num]->ultCost = ultCost;
        charUnit[num]->eidolon = eidolon;
        charUnit[num]->elementType = elementType;
        charUnit[num]->path = path;
        charUnit[num]->atvStats->num = num;
        charUnit[num]->atvStats->name = name;
        charUnit[num]->atvStats->side = Side::ALLY;
        charUnit[num]->atvStats->type = unitType;
        charUnit[num]->baseTaunt = tauntValueEachPath[charUnit[num]->path];
        return charUnit[num].get();
}
void setMemoStats(CharUnit *ptr,double fixHP,double hpRatio,double fixSpeed,double speedRatio,ElementType elementType,string name,UnitType unitType){
        int ownerNum = ptr->atvStats->num;
        
        ptr->memosprite = make_unique<Memosprite>();
        allyList.push_back(ptr->memosprite.get());
        atvList.push_back(ptr->memosprite->atvStats.get());
        ptr->memosprite->unitHpRatio = hpRatio;
        ptr->memosprite->unitSpeedRatio = speedRatio;
        ptr->memosprite->atvStats->baseSpeed = fixSpeed + speedRatio/100 * ptr->atvStats->baseSpeed;
        ptr->memosprite->fixHP =  fixHP;
        ptr->memosprite->fixSpeed =  fixSpeed;
        ptr->memosprite->baseAtk = ptr->baseAtk;
        ptr->memosprite->baseHp = ptr->baseHp*(ptr->memosprite->unitHpRatio/100);
        ptr->memosprite->baseDef = ptr->baseDef;
        ptr->memosprite->elementType = elementType;
        ptr->memosprite->atvStats->num = ownerNum;
        ptr->memosprite->atvStats->name = name;
        ptr->memosprite->atvStats->side = Side::MEMOSPRITE;
        ptr->memosprite->atvStats->type = unitType;
        ptr->memosprite->atvStats->charptr = ptr->memosprite.get();
        ptr->memosprite->owner = ptr;
        ptr->memosprite->baseTaunt = tauntValueEachPath[ptr->path];

}
void setCountdownStats(CharUnit *ptr,double baseSpeed,string name){
        int num = ptr->countdownList.size();
        int ownerNum = ptr->atvStats->num;
        ptr->countdownList.push_back(make_unique<TimerATV>());
        atvList.push_back(ptr->countdownList[num].get());
        ptr->countdownList[num]->baseSpeed = baseSpeed;
        ptr->countdownList[num]->num = ownerNum;
        ptr->countdownList[num]->name = name;
        ptr->countdownList[num]->side = Side::COUNTDOWN;
}
void setSummonStats(CharUnit *ptr,double baseSpeed,string name){
        int num = ptr->summonList.size();
        int ownerNum = ptr->atvStats->num;

        ptr->summonList.push_back(make_unique<TimerATV>());             
        atvList.push_back(ptr->summonList[num].get());
        ptr->summonList[num]->baseSpeed = baseSpeed;
        ptr->summonList[num]->num = ownerNum;
        ptr->summonList[num]->name = name;
        ptr->summonList[num]->side = Side::SUMMON;
}

#endif