#ifndef BUFFSPEED_H
#define BUFFSPEED_H
#include "../Class/Trigger_Function.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

void ActionValueStats::speedBuff(double spd_percent ,double flat_spd){
    double x = this->Max_atv;
    this->Flat_Speed += flat_spd;
    this->Speed_percent += spd_percent;
    Update_Max_atv(this);
    this->atv=this->atv/x*this->Max_atv;
    SubUnit *temp = this->canCastToSubUnit();
    if(!temp)return;
    StatsAdjust(temp,"Speed");
}
void Enemy::speedBuff(double spd_percent ,double flat_spd){
    this->Atv_stats->speedBuff(spd_percent,flat_spd);
}
void Enemy::speedBuff(double spd_percent ,double flat_spd,string buffName,int extend){
    this->Atv_stats->speedBuff(spd_percent,flat_spd);
}
void SubUnit::speedBuff(double spd_percent ,double flat_spd){
    this->Atv_stats->speedBuff(spd_percent,flat_spd);
}
void SubUnit::speedBuff(double spd_percent ,double flat_spd,string buffName,int extend){
    this->Atv_stats->speedBuff(spd_percent,flat_spd);
}
void Ally::speedBuff(double spd_percent ,double flat_spd,string buffName){
    for(auto &each : this->Sub_Unit_ptr)
    each->Atv_stats->speedBuff(spd_percent,flat_spd);
}
void Ally::speedBuff(double spd_percent ,double flat_spd,string buffName,int extend){
    for(auto &each : this->Sub_Unit_ptr)
    each->Atv_stats->speedBuff(spd_percent,flat_spd);
}

void speedBuffAll(double spd_percent ,double flat_spd){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            Speed_Buff(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get(),spd_percent,flat_spd);
        }
    }
}
void speedBuffAll(double spd_percent ,double flat_spd,string Buff_name){
    for(int i=1;i<=Total_ally;i++){
            for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
                if(Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name]==0){
                    Speed_Buff(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get(),spd_percent,flat_spd);
                    Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name]=1;
                }
            }
    }
}
void Speed_Buff_All_Ally_Exclude_Buffer(double spd_percent ,double flat_spd,string Buffer){
    for(int i=1;i<=Total_ally;i++){
        if(Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name==Buffer)continue;
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            Speed_Buff(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get(),spd_percent,flat_spd);
        }
    }
}
void Speed_Buff_All_Ally_Exclude_Buffer(double spd_percent ,double flat_spd,string Buffer,string Buff_name){
    for(int i=1;i<=Total_ally;i++){
        if(Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name==Buffer)continue;
            for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
                if(Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name]==0){
                    Speed_Buff(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get(),spd_percent,flat_spd);
                    Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name]=1;
                }
            }
    }
}



#endif