
#ifndef Cal_Stats_HEAL_H
#define Cal_Stats_HEAL_H
#include "../Print.h"
double Cal_Atk_multiplier(Heal_data* ptr){
    double ans = ptr->Healer->Base_atk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;
    
    Atk_percent_mtpr += ptr->Healer->Stats_type["Atk%"]["None"];
    Flat_atk_mtpr += ptr->Healer->Stats_type["Flat_Atk"]["None"];
    if(ptr->Combat_dataPtr){
        for(int i=0,sz=ptr->Combat_dataPtr->Skill_Type.size();i<sz;i++){
                Atk_percent_mtpr+= ptr->Healer->Stats_type["Atk%"][ptr->Combat_dataPtr->Skill_Type[i]];
                Flat_atk_mtpr += ptr->Healer->Stats_type["Flat_Atk"][ptr->Combat_dataPtr->Skill_Type[i]];
        }
    }
    

    ans = (ans * Atk_percent_mtpr/100) + Flat_atk_mtpr;
    return ans;
}
double Cal_Hp_multiplier(Heal_data* ptr){
    double ans = ptr->Healer->Base_atk;
    double Hp_percent_mtpr = 100;
    double Flat_Hp_mtpr = 0;
    
    Hp_percent_mtpr += ptr->Healer->Stats_type["Hp%"]["None"];
    Flat_Hp_mtpr += ptr->Healer->Stats_type["Flat_Hp"]["None"];
    if(ptr->Combat_dataPtr){
        for(int i=0,sz=ptr->Combat_dataPtr->Skill_Type.size();i<sz;i++){
                Hp_percent_mtpr+= ptr->Healer->Stats_type["Hp%"][ptr->Combat_dataPtr->Skill_Type[i]];
                Flat_Hp_mtpr += ptr->Healer->Stats_type["Flat_Hp"][ptr->Combat_dataPtr->Skill_Type[i]];
        }
    }
    

    ans = (ans * Hp_percent_mtpr/100) + Flat_Hp_mtpr;
    return ans;
}
double Cal_Def_multiplier(Heal_data* ptr){
    double ans = ptr->Healer->Base_def;
    double Def_percent_mtpr = 100;
    double Flat_Def_mtpr = 0;
    
    Def_percent_mtpr += ptr->Healer->Stats_type["Def%"]["None"];
    Flat_Def_mtpr += ptr->Healer->Stats_type["Flat_Def"]["None"];
    if(ptr->Combat_dataPtr){
        for(int i=0,sz=ptr->Combat_dataPtr->Skill_Type.size();i<sz;i++){
                Def_percent_mtpr+= ptr->Healer->Stats_type["Def%"][ptr->Combat_dataPtr->Skill_Type[i]];
                Flat_Def_mtpr += ptr->Healer->Stats_type["Flat_Def"][ptr->Combat_dataPtr->Skill_Type[i]];
        }
    }
    

    ans = (ans * Def_percent_mtpr/100) + Flat_Def_mtpr;
    return ans;
}
double Cal_HealBonus_multiplier(Heal_data* ptr,Sub_Unit *target){
    double mtpr = 100;
    mtpr += ptr->Healer->Stats_type["HealingBonus"]["None"] + target->Stats_type["HealingBonus"]["None"];
    if(ptr->Combat_dataPtr){
        for(int i=0,sz=ptr->Combat_dataPtr->Skill_Type.size();i<sz;i++){
            mtpr += ptr->Healer->Stats_type["HealingBonus"][ptr->Combat_dataPtr->Skill_Type[i]] + target->Stats_type["HealingBonus"][ptr->Combat_dataPtr->Skill_Type[i]];
        }
    }
    if(ptr->Healer->Atv_stats->Unit_Name==target->Atv_stats->Unit_Name){
        mtpr = (mtpr+100) / 2;
    }
    return mtpr/100;
    
}
#endif
