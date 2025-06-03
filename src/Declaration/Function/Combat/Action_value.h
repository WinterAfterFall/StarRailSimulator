#include "../include.h"

bool compareActionValueStats(ActionValueStats* a, ActionValueStats* b);
void Update_Max_atv(ActionValueStats *ptr);
void resetTurn(ActionValueStats *ptr);
void All_atv_reset();
void Action_forward(ActionValueStats *ptr,double fwd);
void All_Action_forward(double fwd);
void Find_turn();
void Atv_fix(double Atv_reduce);