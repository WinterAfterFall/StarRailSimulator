#include "../include.h"

double calculateHeal(HealSrc healSrc, AllyUnit *Healer, AllyUnit *target);
double calculateHealFromLostHP(AllyUnit *target, double percent);
double calculateHealFromTotalHP(AllyUnit *target, double percent);