#ifndef FormulaCheck_H
#define FormulaCheck_H

#include "../Class/ClassLibrary.h"

void Ally::enableCheckDamage() {
    checkDamage = 1;
}
void Ally::enableCheckDamageFormula() {
    checkDamageFormula = 1;
}
void Ally::enableCheckHeal() {
    checkHeal = 1;
}
void Ally::enableCheckHealFormula() {
    checkHealFormula = 1;
}
void Ally::enableCheckHpChange() {
    checkHpChange = 1;
}
void Ally::enableCheckHpChangeFormula() {
    checkHpChangeFormula = 1;
}
    
#endif