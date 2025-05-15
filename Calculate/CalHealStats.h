#ifndef Cal_Stats_HEAL_H
#define Cal_Stats_HEAL_H
#include "../Class/Trigger_Function.h"


double Cal_HealBonus_multiplier(SubUnit* Healer, SubUnit* target) {
    double mtpr = 100;
    mtpr += Healer->Stats_type[ST_HEALING_OUT][AT_NONE];
    return mtpr / 100 < 0 ? 0 : mtpr / 100;
}

#endif
