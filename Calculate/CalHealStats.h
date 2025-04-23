#ifndef Cal_Stats_HEAL_H
#define Cal_Stats_HEAL_H
#include "../Class/Trigger_Function.h"

double Cal_Atk_multiplier(Heal_data& healData) {
    double ans = healData.Healer->Base_atk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;

    Atk_percent_mtpr += healData.Healer->Stats_type["Atk%"][AT_NONE];
    Flat_atk_mtpr += healData.Healer->Stats_type["Flat_Atk"][AT_NONE];
    // if (healData.Combat_dataPtr) {
    //     for (int i = 0, sz = healData.Combat_dataPtr->Skill_Type.size(); i < sz; i++) {
    //         Atk_percent_mtpr += healData.Healer->Stats_type["Atk%"][healData.Combat_dataPtr->Skill_Type[i]];
    //         Flat_atk_mtpr += healData.Healer->Stats_type["Flat_Atk"][healData.Combat_dataPtr->Skill_Type[i]];
    //     }
    // }
    ans = (ans * Atk_percent_mtpr / 100) + Flat_atk_mtpr;
    return ans < 0 ? 0 : ans;
}

double Cal_Hp_multiplier(Heal_data& healData) {
    double ans = healData.Healer->Base_atk;
    double Hp_percent_mtpr = 100;
    double Flat_Hp_mtpr = 0;

    Hp_percent_mtpr += healData.Healer->Stats_type["Hp%"][AT_NONE];
    Flat_Hp_mtpr += healData.Healer->Stats_type["Flat_Hp"][AT_NONE];
    // if (healData.Combat_dataPtr) {
    //     for (int i = 0, sz = healData.Combat_dataPtr->Skill_Type.size(); i < sz; i++) {
    //         Hp_percent_mtpr += healData.Healer->Stats_type["Hp%"][healData.Combat_dataPtr->Skill_Type[i]];
    //         Flat_Hp_mtpr += healData.Healer->Stats_type["Flat_Hp"][healData.Combat_dataPtr->Skill_Type[i]];
    //     }
    // }

    ans = (ans * Hp_percent_mtpr / 100) + Flat_Hp_mtpr;
    return ans < 0 ? 0 : ans;
}

double Cal_Def_multiplier(Heal_data& healData) {
    double ans = healData.Healer->Base_def;
    double Def_percent_mtpr = 100;
    double Flat_Def_mtpr = 0;

    Def_percent_mtpr += healData.Healer->Stats_type["Def%"][AT_NONE];
    Flat_Def_mtpr += healData.Healer->Stats_type["Flat_Def"][AT_NONE];
    // if (healData.Combat_dataPtr) {
    //     for (int i = 0, sz = healData.Combat_dataPtr->Skill_Type.size(); i < sz; i++) {
    //         Def_percent_mtpr += healData.Healer->Stats_type["Def%"][healData.Combat_dataPtr->Skill_Type[i]];
    //         Flat_Def_mtpr += healData.Healer->Stats_type["Flat_Def"][healData.Combat_dataPtr->Skill_Type[i]];
    //     }
    // }

    ans = (ans * Def_percent_mtpr / 100) + Flat_Def_mtpr;
    return ans < 0 ? 0 : ans;
}

double Cal_HealBonus_multiplier(Heal_data& healData, SubUnit* target) {
    double mtpr = 100;
    
    mtpr += healData.Healer->Stats_type[ST_HEALING_OUT][AT_NONE];
    // if (healData.Combat_dataPtr) {
    //     for (int i = 0, sz = healData.Combat_dataPtr->Skill_Type.size(); i < sz; i++) {
    //         mtpr += healData.Healer->Stats_type["HealingBonus"][healData.Combat_dataPtr->Skill_Type[i]];
    //     }
    // }
    return (mtpr / 100 < 0) ? 0 : mtpr / 100;
}

double Cal_HealBonus_multiplier(SubUnit* Healer, SubUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[ST_HEALING_OUT][AT_NONE];
    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}

#endif
