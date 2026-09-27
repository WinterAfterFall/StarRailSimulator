#include "../include.h"

void CharUnit::enableCheckDamage() {
    checkDamage = 1;
}
void CharUnit::enableCheckDamageFormula(DmgFormulaMode mode) {

    checkDmgFormula =1;
    if (mode == DmgFormulaMode::ALL) checkDmgFormulaAll = 1;
    else if (mode == DmgFormulaMode::SRC) checkDmgFormulaSrc = 1;
    else if (mode == DmgFormulaMode::HP) checkDmgFormulaHP = 1;
    else if (mode == DmgFormulaMode::ATK) checkDmgFormulaATK = 1;
    else if (mode == DmgFormulaMode::DEF) checkDmgFormulaDEF = 1;
    else if (mode == DmgFormulaMode::CONST) checkDmgFormulaConst = 1;
    else if (mode == DmgFormulaMode::DMG) checkDmgFormulaDmg = 1;
    else if (mode == DmgFormulaMode::CRIT) checkDmgFormulaCrit = 1;
    else if (mode == DmgFormulaMode::CRIT_RATE) checkDmgFormulaCritRate = 1;
    else if (mode == DmgFormulaMode::CRIT_DAM) checkDmgFormulaCritDam = 1;
    else if (mode == DmgFormulaMode::DEF_SHRED) checkDmgFormulaDefShred = 1;
    else if (mode == DmgFormulaMode::RESPEN) checkDmgFormulaRespen = 1;
    else if (mode == DmgFormulaMode::VUL) checkDmgFormulaVul = 1;
    else if (mode == DmgFormulaMode::MTGT) checkDmgFormulaMtgt = 1;
    else if (mode == DmgFormulaMode::MTPR_INC) checkDmgFormulaMtprInc = 1;
    else if (mode == DmgFormulaMode::BE) checkDmgFormulaBE = 1;
    else if (mode == DmgFormulaMode::SPB_INC) checkDmgFormulaSpbInc = 1;
    else if (mode == DmgFormulaMode::CB) checkDmgFormulaPL = 1;
    else if (mode == DmgFormulaMode::ELATION) checkDmgFormulaElation = 1;
    else if (mode == DmgFormulaMode::MERRYMAKE) checkDmgFormulaMM = 1;
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
bool CharUnit::canCheckDmgformulaPL(){
    return checkDmgFormulaAll
        || checkDmgFormulaPL;
}
bool CharUnit::canCheckDmgformulaMM(){
    return checkDmgFormulaAll
        || checkDmgFormulaMM;
}
bool CharUnit::canCheckDmgformulaElation(){
    return checkDmgFormulaAll
        || checkDmgFormulaElation;
}