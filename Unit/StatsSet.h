#ifndef STATSSET_H
#define STATSSET_H

#include "Stats.h"
void Ally::SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef){
        this->getSubUnit()->Base_hp +=BaseHp;
        this->getSubUnit()->Base_atk +=BaseAtk;
        this->getSubUnit()->Base_def +=BaseDef;
}
Ally* SetAllyBasicStats(double BaseSpeed,double Max_Energy,double Ult_cost,int Eidolon,string Element_type,string Path,string Name,string UnitType){
        Ally_unit.push_back(make_unique<Ally>());
        Total_ally++;
        int num = Total_ally;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = BaseSpeed;
        Ally_unit[num]->Max_energy = Max_Energy;
        Ally_unit[num]->Ult_cost = Ult_cost;
        Ally_unit[num]->Eidolon = Eidolon;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back(Element_type);
        Ally_unit[num]->Path.push_back(Path);
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = Name;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = Name;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Side = "Ally";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Type = UnitType;
        return Ally_unit[num].get();
}
void SetMemoStats(Ally *ptr,double Hp_ratio,double Speed_ratio,string Element_type,string Name,string UnitType){
        int num = ptr->Sub_Unit_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num;
        
        ptr->Sub_Unit_ptr.push_back(make_unique<SubUnit>());
        ptr->Sub_Unit_ptr[num]->Unit_Hp_Ratio = Hp_ratio;
        ptr->Sub_Unit_ptr[num]->Unit_Speed_Ratio = Speed_ratio;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Base_speed = -1;
        ptr->Sub_Unit_ptr[num]->Base_atk = ptr->Sub_Unit_ptr[0]->Base_atk;
        ptr->Sub_Unit_ptr[num]->Base_hp = ptr->Sub_Unit_ptr[0]->Base_hp*(ptr->Sub_Unit_ptr[num]->Unit_Hp_Ratio/100);
        ptr->Sub_Unit_ptr[num]->Base_def = ptr->Sub_Unit_ptr[0]->Base_def;
        ptr->Sub_Unit_ptr[num]->Element_type.push_back(Element_type);
        ptr->Sub_Unit_ptr[num]->Atv_stats->Unit_num = Num;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Unit_Name = Name;
        ptr->Sub_Unit_ptr[num]->Atv_stats->Side = "Memosprite";
        ptr->Sub_Unit_ptr[num]->Atv_stats->Type = UnitType;
        ptr->Sub_Unit_ptr[num]->Atv_stats->ptr_to_unit = ptr->Sub_Unit_ptr[num].get();
        ptr->Sub_Unit_ptr[num]->ptr_to_unit = ptr;

}
void SetCountdownStats(Ally *ptr,string Name){
        int num = ptr->Countdown_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num;

        ptr->Countdown_ptr.push_back(make_unique<SubUnit>());
        ptr->Countdown_ptr[num]->Atv_stats->Base_speed = -1;
        ptr->Countdown_ptr[num]->Atv_stats->Unit_num = Num;
        ptr->Countdown_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Countdown_ptr[num]->Atv_stats->Unit_Name = Name;
        ptr->Countdown_ptr[num]->Atv_stats->Side = "Countdown";
        ptr->Countdown_ptr[num]->Atv_stats->ptr_to_unit = ptr->Countdown_ptr[num].get();
}
void SetSummonStats(Ally *ptr,double BaseSpeed,string Name){
        int num = ptr->Summon_ptr.size();
        int Num = ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num;

        ptr->Summon_ptr.push_back(make_unique<SubUnit>());
        ptr->Summon_ptr[num]->Atv_stats->Base_speed = BaseSpeed;
        ptr->Summon_ptr[num]->Atv_stats->Unit_num = Num;
        ptr->Summon_ptr[num]->Atv_stats->Char_Name = Name;
        ptr->Summon_ptr[num]->Atv_stats->Unit_Name = ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name;
        ptr->Summon_ptr[num]->Atv_stats->Side = "Summon";
        ptr->Summon_ptr[num]->Atv_stats->ptr_to_unit = ptr->Summon_ptr[num].get();
}

#endif