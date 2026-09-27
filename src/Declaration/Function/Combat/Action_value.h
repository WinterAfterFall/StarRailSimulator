#include "../include.h"

bool compareActionValueStats(ActionValueStats* a, ActionValueStats* b);
void updateMaxAtv(ActionValueStats *ptr);
void resetTurn(ActionValueStats *ptr);
void allAtvReset();
void actionForward(ActionValueStats *ptr,double fwd);
void allActionForward(double fwd);
void findTurn();
void atvFix(double atvReduce);
void ahaSpeedAdjust(Path &path);