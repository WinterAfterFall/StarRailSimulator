#ifndef STATSSET_H
#define STATSSET_H
#include "Enemy.h"

void CharUnit::SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef){
        this->baseHp +=BaseHp;
        this->baseAtk +=BaseAtk;
        this->baseDef +=BaseDef;
}
CharUnit* SetCharBasicStats(double BaseSpeed,double Max_Energy,double Ult_cost,int Eidolon,ElementType Element_type,Path path,string Name,UnitType unitType){
        charUnit.push_back(make_unique<CharUnit>());
        Total_ally++;
        int num = Total_ally;
        allyList.push_back(charUnit[num].get());
        charList.push_back(charUnit[num].get());
        atvList.push_back(charUnit[num]->Atv_stats.get());
        charUnit[num]->Atv_stats->baseSpeed = BaseSpeed;
        charUnit[num]->Max_energy = Max_Energy;
        charUnit[num]->Ult_cost = Ult_cost;
        charUnit[num]->Eidolon = Eidolon;
        charUnit[num]->Element_type.push_back(Element_type);
        charUnit[num]->path.push_back(path);
        charUnit[num]->Atv_stats->num = num;
        charUnit[num]->Atv_stats->Name = Name;
        charUnit[num]->Atv_stats->side = Side::Ally;
        charUnit[num]->Atv_stats->Type = unitType;
        charUnit[num]->baseTaunt = tauntValueEachPath[charUnit[num]->path[0]];
        return charUnit[num].get();
}
void SetMemoStats(CharUnit *ptr,double fixHP,double Hp_ratio,double fixSpeed,double Speed_ratio,ElementType Element_type,string Name,UnitType unitType){
        int num = ptr->memospriteList.size();
        int Num = ptr->Atv_stats->num;
        
        ptr->memospriteList.push_back(make_unique<Memosprite>());
        allyList.push_back(ptr->memospriteList[num].get());
        atvList.push_back(ptr->memospriteList[num]->Atv_stats.get());
        ptr->memospriteList[num]->Unit_Hp_Ratio = Hp_ratio;
        ptr->memospriteList[num]->Unit_Speed_Ratio = Speed_ratio;
        ptr->memospriteList[num]->Atv_stats->baseSpeed = fixSpeed + Speed_ratio/100 * ptr->Atv_stats->baseSpeed;
        ptr->memospriteList[num]->fixHP =  fixHP;
        ptr->memospriteList[num]->fixSpeed =  fixSpeed;
        ptr->memospriteList[num]->baseAtk = ptr->baseAtk;
        ptr->memospriteList[num]->baseHp = ptr->baseHp*(ptr->memospriteList[num]->Unit_Hp_Ratio/100);
        ptr->memospriteList[num]->baseDef = ptr->baseDef;
        ptr->memospriteList[num]->Element_type.push_back(Element_type);
        ptr->memospriteList[num]->Atv_stats->num = Num;
        ptr->memospriteList[num]->Atv_stats->Name = Name;
        ptr->memospriteList[num]->Atv_stats->side = Side::Memosprite;
        ptr->memospriteList[num]->Atv_stats->Type = unitType;
        ptr->memospriteList[num]->Atv_stats->charptr = ptr->memospriteList[num].get();
        ptr->memospriteList[num]->owner = ptr;
        ptr->memospriteList[num]->baseTaunt = tauntValueEachPath[ptr->path[0]];

}
void SetCountdownStats(CharUnit *ptr,double BaseSpeed,string Name){
        int num = ptr->countdownList.size();
        int Num = ptr->Atv_stats->num;
        ptr->countdownList.push_back(make_unique<AllyUnit>());
        atvList.push_back(ptr->countdownList[num]->Atv_stats.get());
        ptr->countdownList[num]->Atv_stats->baseSpeed = BaseSpeed;
        ptr->countdownList[num]->Atv_stats->num = Num;
        ptr->countdownList[num]->Atv_stats->Name = Name;
        ptr->countdownList[num]->Atv_stats->side = Side::Countdown;
        ptr->countdownList[num]->Atv_stats->charptr = ptr->countdownList[num].get();
}
void SetSummonStats(CharUnit *ptr,double BaseSpeed,string Name){
        int num = ptr->summonList.size();
        int Num = ptr->Atv_stats->num;

        ptr->summonList.push_back(make_unique<AllyUnit>());             
        atvList.push_back(ptr->summonList[num]->Atv_stats.get());
        ptr->summonList[num]->Atv_stats->baseSpeed = BaseSpeed;
        ptr->summonList[num]->Atv_stats->num = Num;
        ptr->summonList[num]->Atv_stats->Name = ptr->Atv_stats->Name;
        ptr->summonList[num]->Atv_stats->side = Side::Summon;
        ptr->summonList[num]->Atv_stats->charptr = ptr->summonList[num].get();
}

#endif