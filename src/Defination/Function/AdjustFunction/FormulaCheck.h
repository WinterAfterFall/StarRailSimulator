#include "../include.h"

void CharUnit::enableCheckDamage() {
    checkDamage = 1;
}
void CharUnit::enableCheckDamageFormula(DmgFormulaMode mode) {

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
void CharUnit::enableCheckHeal() {
    checkHeal = 1;
}
void CharUnit::enableCheckHealFormula() {
    checkHealFormula = 1;
}
void CharUnit::enableCheckHealReceive() {
    checkHealReceive = 1;
}
void CharUnit::enableCheckHealReceiveFormula() {
    checkHealReceiveFormula = 1;
}
void CharUnit::enableCheckHpChange() {
    checkHpChange = 1;
}
void CharUnit::enableCheckHpChangeFormula() {
    checkHpChangeFormula = 1;
}
bool CharUnit::canCheckDmgformula() {
    return checkDmgFormula; 
}
bool CharUnit::canCheckDmgformulaMtpr() {
    return checkDmgFormulaAll 
        || checkDmgFormulaSrc
        || checkDmgFormulaHP 
        || checkDmgFormulaATK 
        || checkDmgFormulaDEF 
        || checkDmgFormulaConst;
}
bool CharUnit::canCheckDmgformulaHP() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaHP;
}
bool CharUnit::canCheckDmgformulaATK() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaATK;
}
bool CharUnit::canCheckDmgformulaDEF() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaDEF;
}
bool CharUnit::canCheckDmgformulaConst() {
    return checkDmgFormulaAll
        || checkDmgFormulaSrc
        || checkDmgFormulaConst;
}
bool CharUnit::canCheckDmgformulaCritRate() {
    return checkDmgFormulaAll
        || checkDmgFormulaCrit
        || checkDmgFormulaCritRate;
}
bool CharUnit::canCheckDmgformulaCritDam() {
    return checkDmgFormulaAll
        || checkDmgFormulaCrit
        || checkDmgFormulaCritDam;
}
bool CharUnit::canCheckDmgformulaDmg() {
    return checkDmgFormulaAll
        || checkDmgFormulaDmg;
}
bool CharUnit::canCheckDmgformulaDefShred() {
    return checkDmgFormulaAll
        || checkDmgFormulaDefShred;
}
bool CharUnit::canCheckDmgformulaRespen() {
    return checkDmgFormulaAll
        || checkDmgFormulaRespen;
}
bool CharUnit::canCheckDmgformulaVul() {
    return checkDmgFormulaAll
        || checkDmgFormulaVul;
}
bool CharUnit::canCheckDmgformulaMtgt() {
    return checkDmgFormulaAll
        || checkDmgFormulaMtgt;
}
bool CharUnit::canCheckDmgformulaMtprInc() {
    return checkDmgFormulaAll
        || checkDmgFormulaMtprInc;
}
bool CharUnit::canCheckDmgformulaBE() {
    return checkDmgFormulaAll
        || checkDmgFormulaBE;
}
bool CharUnit::canCheckDmgformulaSpbInc() {
    return checkDmgFormulaAll
        || checkDmgFormulaSpbInc;
}
