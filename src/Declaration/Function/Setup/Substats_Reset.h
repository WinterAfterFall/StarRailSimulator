#include "../include.h"

void Set_Stats(CharUnit *ptr);
bool Reroll_substats();
bool StandardReroll(CharUnit *ptr);
bool trySwapSubstat(CharUnit *ptr, int sourceIndex);
void restoreBestSubstats(CharUnit *ptr);
// bool AllCombinationReroll(CharUnit *ptr);   // ปิดไว้ก่อน
// bool AllPossibleReroll(CharUnit *ptr);      // ปิดไว้ก่อน
