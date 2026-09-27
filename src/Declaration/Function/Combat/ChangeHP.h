#include "../include.h"

void increaseCurrentHP(AllyUnit *ptr,double value);
void increaseHP(AllyUnit *healer,AllyUnit *target,double value);
double decreaseSheild(AllyUnit *ptr,double value);
double decreaseCurrentHP(AllyUnit *ptr,double value);
void decreaseHP(AllyUnit *target,Unit *trigger,double value,double percentFromTotalHP,double percentFromCurrentHP);
void decreaseHP(Unit *trigger,double value,double percentFromTotalHP,double percentFromCurrentHP);
void decreaseHP(Unit *trigger,vector<AllyUnit*> target,double value,double percentFromTotalHP,double percentFromCurrentHP);
void decreaseHP(Unit *trigger,string name,double value,double percentFromTotalHP,double percentFromCurrentHP);
