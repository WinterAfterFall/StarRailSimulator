#include "../include.h"

void Ally::enableCheckDamage() {
    checkDamage = 1;
}
void Ally::enableCheckDamageFormula(DmgFormulaMode mode) {

    checkDmgFormula =1;
    if (mode == DmgFormulaMode::All) checkDmgFormulaAll = 1;
    else if (mode == DmgFormulaMode::Src) checkDmgFormulaSrc = 1;
    else if (mode == DmgFormulaMode::HP) checkDmgFormulaHP = 1;
    else if (mode == DmgFormulaMode::ATK) checkDmgFormulaATK = 1;
    else if (mode == DmgFormulaMode::DEF) checkDmgFormulaDEF = 1;
    else if (mode == DmgFormulaMode::Const) checkDmgFormulaConst = 1;
    else if (mode == DmgFormulaMode::Dmg) checkDmgFormulaDmg = 1;
    else if (mode == DmgFormulaMode::Crit) checkDmgFormulaCrit = 1;
    else if (mode == DmgFormulaMode::CritRate) checkDmgFormulaCritRate = 1;
    else if (mode == DmgFormulaMode::CritDam) checkDmgFormulaCritDam = 1;
    else if (mode == DmgFormulaMode::DefShred) checkDmgFormulaDefShred = 1;
    else if (mode == DmgFormulaMode::Respen) checkDmgFormulaRespen = 1;
    else if (mode == DmgFormulaMode::Vul) checkDmgFormulaVul = 1;
    else if (mode == DmgFormulaMode::Mtgt) checkDmgFormulaMtgt = 1;
    else if (mode == DmgFormulaMode::MtprInc) checkDmgFormulaMtprInc = 1;
    else if (mode == DmgFormulaMode::BE) checkDmgFormulaBE = 1;
    else if (mode == DmgFormulaMode::SpbInc) checkDmgFormulaSpbInc = 1;
}
void Ally::enableCheckHeal() {
    checkHeal = 1;
}
void Ally::enableCheckHealFormula() {
    checkHealFormula = 1;
}
void Ally::enableCheckHealReceive() {
    checkHealReceive = 1;
}
void Ally::enableCheckHealReceiveFormula() {
    checkHealReceiveFormula = 1;
}
void Ally::enableCheckHpChange() {
    checkHpChange = 1;
}
void Ally::enableCheckHpChangeFormula() {
    checkHpChangeFormula = 1;
}
bool Ally::canCheckDmgformula() {
    return checkDmgFormula; 
}
bool Ally::canCheckDmgformulaMtpr() {
    return checkDmgFormulaAll 
        || checkDmgFormulaSrc
        || checkDmgFormulaHP 
        || checkDmgFormulaATK 
        || checkDmgFormulaDEF 
        || checkDmgFormulaConst;
}
bool Ally::canCheckDmgformulaHP() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaHP;
}
bool Ally::canCheckDmgformulaATK() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaATK;
}
bool Ally::canCheckDmgformulaDEF() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaDEF;
}
bool Ally::canCheckDmgformulaConst() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaConst;
}
bool Ally::canCheckDmgformulaCritRate() {
    return checkDmgFormulaAll
        || checkDmgFormulaCrit
        || checkDmgFormulaCritRate;
}
bool Ally::canCheckDmgformulaCritDam() {
    return checkDmgFormulaAll
        || checkDmgFormulaCrit
        || checkDmgFormulaCritDam;
}
bool Ally::canCheckDmgformulaDmg() {
    return checkDmgFormulaAll
        || checkDmgFormulaDmg;
}
bool Ally::canCheckDmgformulaDefShred() {
    return checkDmgFormulaAll
        || checkDmgFormulaDefShred;
}
bool Ally::canCheckDmgformulaRespen() {
    return checkDmgFormulaAll
        || checkDmgFormulaRespen;
}
bool Ally::canCheckDmgformulaVul() {
    return checkDmgFormulaAll
        || checkDmgFormulaVul;
}
bool Ally::canCheckDmgformulaMtgt() {
    return checkDmgFormulaAll
        || checkDmgFormulaMtgt;
}
bool Ally::canCheckDmgformulaMtprInc() {
    return checkDmgFormulaAll
        || checkDmgFormulaMtprInc;
}
bool Ally::canCheckDmgformulaBE() {
    return checkDmgFormulaAll
        || checkDmgFormulaBE;
}
bool Ally::canCheckDmgformulaSpbInc() {
    return checkDmgFormulaAll
        || checkDmgFormulaSpbInc;
}
