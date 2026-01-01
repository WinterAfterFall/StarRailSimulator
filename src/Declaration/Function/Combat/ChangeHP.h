#include "../include.h"

void IncreaseCurrentHP(AllyUnit *ptr,double Value);
void IncreaseHP(AllyUnit *Healer,AllyUnit *target,double Value);
double decreaseSheild(AllyUnit *ptr,double Value);
void DecreaseCurrentHP(AllyUnit *ptr,double Value);
void DecreaseHP(AllyUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,vector<AllyUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP);