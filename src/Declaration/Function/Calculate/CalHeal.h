#include "../include.h"

double calculateHeal(HealSrc healSrc, SubUnit *Healer, SubUnit *target);
double calculateHealFromLostHP(SubUnit *target, double percent);
double calculateHealFromTotalHP(SubUnit *target, double percent);