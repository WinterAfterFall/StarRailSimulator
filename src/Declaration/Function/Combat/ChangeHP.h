#include "../include.h"

void IncreaseCurrentHP(SubUnit *ptr,double Value);
void IncreaseHP(SubUnit *Healer,SubUnit *target,double Value);

void DecreaseCurrentHP(SubUnit *ptr,double Value);
void DecreaseHP(SubUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,vector<SubUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP);