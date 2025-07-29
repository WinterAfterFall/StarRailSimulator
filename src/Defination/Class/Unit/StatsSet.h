#ifndef STATSSET_H
#define STATSSET_H
#include "Enemy.h"

void Ally::SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef){
        this->getSubUnit()->baseHp +=BaseHp;
        this->getSubUnit()->baseAtk +=BaseAtk;
        this->getSubUnit()->baseDef +=BaseDef;
}
Ally* SetAllyBasicStats(double BaseSpeed,double Max_Energy,double Ult_cost,int Eidolon,ElementType Element_type,Path path,string Name,UnitType unitType){
        Ally_unit.push_back(make_unique<Ally>());
        Total_ally++;
        int num = Total_ally;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->baseSpeed = BaseSpeed;
        Ally_unit[num]->Max_energy = Max_Energy;
        Ally_unit[num]->Ult_cost = Ult_cost;
        Ally_unit[num]->Eidolon = Eidolon;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back(Element_type);
        Ally_unit[num]->path.push_back(path);
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = Name;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = Name;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->side = Side::Ally;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Type = unitType;
        Ally_unit[num]->Sub_Unit_ptr[0]->baseTaunt = tauntValueEachPath[Ally_unit[num]->path[0]];
        return Ally_unit[num].get();
}
void SetMemoStats(Ally *ptr,double fixHP,double Hp_ratio,double fixSpeed,double Speed_ratio,ElementType Element_type,string Name,UnitType unitType){
        int num = ptr->Sub_Unit_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->num;
        
        ptr->Sub_Unit_ptr.push_back(make_unique<SubUnit>());
        ptr->Sub_Unit_ptr[num]->Unit_Hp_Ratio = Hp_ratio;
        ptr->Sub_Unit_ptr[num]->Unit_Speed_Ratio = Speed_ratio;
        ptr->Sub_Unit_ptr[num]->Atv_stats->baseSpeed = fixSpeed + Speed_ratio/100 * ptr->getSubUnit()->Atv_stats->baseSpeed;
        ptr->Sub_Unit_ptr[num]->fixHP =  fixHP;
        ptr->Sub_Unit_ptr[num]->baseAtk = ptr->Sub_Unit_ptr[0]->baseAtk;
        ptr->Sub_Unit_ptr[num]->baseHp = ptr->Sub_Unit_ptr[0]->baseHp*(ptr->Sub_Unit_ptr[num]->Unit_Hp_Ratio/100);
        ptr->Sub_Unit_ptr[num]->baseDef = ptr->Sub_Unit_ptr[0]->baseDef;
        ptr->Sub_Unit_ptr[num]->Element_type.push_back(Element_type);
        ptr->Sub_Unit_ptr[num]->Atv_stats->num = Num;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Unit_Name = Name;
        ptr->Sub_Unit_ptr[num]->Atv_stats->side = Side::Memosprite;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Type = unitType;
        ptr->Sub_Unit_ptr[num]->Atv_stats->ptrToChar = ptr->Sub_Unit_ptr[num].get();
        ptr->Sub_Unit_ptr[num]->ptrToChar = ptr;
        ptr->Sub_Unit_ptr[num]->baseTaunt = tauntValueEachPath[ptr->path[0]];

}
void SetCountdownStats(Ally *ptr,double BaseSpeed,string Name){
        int num = ptr->Countdown_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->num;

        ptr->Countdown_ptr.push_back(make_unique<SubUnit>());
        ptr->Countdown_ptr[num]->Atv_stats->baseSpeed = BaseSpeed;
        ptr->Countdown_ptr[num]->Atv_stats->num = Num;
        ptr->Countdown_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Countdown_ptr[num]->Atv_stats->Unit_Name = Name;
        ptr->Countdown_ptr[num]->Atv_stats->side = Side::Countdown;
        ptr->Countdown_ptr[num]->Atv_stats->ptrToChar = ptr->Countdown_ptr[num].get();
}
void SetSummonStats(Ally *ptr,double BaseSpeed,string Name){
        int num = ptr->Summon_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->num;

        ptr->Summon_ptr.push_back(make_unique<SubUnit>());
        ptr->Summon_ptr[num]->Atv_stats->baseSpeed = BaseSpeed;
        ptr->Summon_ptr[num]->Atv_stats->num = Num;
        ptr->Summon_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Summon_ptr[num]->Atv_stats->Unit_Name = ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name;
        ptr->Summon_ptr[num]->Atv_stats->side = Side::Summon;
        ptr->Summon_ptr[num]->Atv_stats->ptrToChar = ptr->Summon_ptr[num].get();
}

#endif