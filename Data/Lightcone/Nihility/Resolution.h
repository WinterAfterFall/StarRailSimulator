
#ifndef Resolution_H
#define Resolution_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Nihility_Lightcone{
    void Resolution(Ally *ptr);
    void Resolution(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,476,331);
        ptr->Light_cone.Name = "Resolution";

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            if(data_.Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name)return;
            for(auto e:data_.Target_Attack){
                if(e->Debuff["Ensnared"]==1)continue;
                e->Stats_type["Def"]["None"]+=16;
                e->Debuff["Ensnared"]=1;
                e->Debuff_time_count["Ensnared"]= 1 + e->Atv_stats->turn_cnt;
                Apply_debuff(ptr->Sub_Unit_ptr[0].get(),e);
                ++e->Total_debuff;
            }
            
        }
        ));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            if(turn->Side=="Enemy"){
                if(Enemy_unit[turn->Unit_num]->Debuff_time_count["Ensnared"]==Enemy_unit[turn->Unit_num]->Atv_stats->turn_cnt){
                    Enemy_unit[turn->Unit_num]->Stats_type["Def"]["None"]-=16;
                Enemy_unit[turn->Unit_num]->Debuff["Ensnared"]=0;
                --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
            }
        }
        ));

    }
}
#endif