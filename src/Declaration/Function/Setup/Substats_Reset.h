#include "../include.h"

void setStats(CharUnit *ptr);
bool rerollSubstats();
bool standardReroll(CharUnit *ptr);
bool trySwapSubstat(CharUnit *ptr, int sourceIndex);
void restoreBestSubstats(CharUnit *ptr);
// bool AllCombinationReroll(CharUnit *ptr);   // ปิดไว้ก่อน
// bool AllPossibleReroll(CharUnit *ptr);      // ปิดไว้ก่อน
