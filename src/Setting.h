#ifndef SETTING_H
#define SETTING_H
#include"Declaration/Function/Library.h"

int sp=3,maxSp = 5,totalWave=1;//1450
double wave[3]={1100,450,450}; //1368.01 1442.83
bool avgDamageMode = 1;
bool superBreakMode = 0;
int mainDpsNum = 1;
int driverNum = 0;
int healerNum = 0;
SPMode spMode = SPMode::POSITIVE; //Positive Negative       
int mainEnemyNum = 1;
int adjacentEnemyNum[2] = {2,3};
int otherEnemyNum[2] = {4,5}; 

bool printAtv = 0;

int totalAlly = 0;
int totalEnemy = 0;
int forceBreak = 1;
bool dahliaCheck = 0;

DriverType driverType  = DriverType::NONE;
vector<unique_ptr<CharUnit>> charUnit(1);
vector<unique_ptr<Enemy>> enemyUnit(1);
vector<CharUnit*> charList;
vector<AllyUnit*> allyList;
vector<Enemy*> enemyList;
vector<ActionValueStats*> atvList;

unordered_map<ElementType, double> enemyRes = {
        {ElementType::FIRE, 0.0},
        {ElementType::ICE, 0.0},
        {ElementType::QUANTUM, 0.0},
        {ElementType::WIND, 0.0},
        {ElementType::LIGHTNING, 0.0},
        {ElementType::PHYSICAL, 0.0},
        {ElementType::IMAGINARY, 0.0}
};
unordered_map<ElementType, bool> enemyWeak = {
        {ElementType::FIRE, 1},
        {ElementType::ICE, 1},
        {ElementType::QUANTUM, 1},
        {ElementType::WIND, 1},
        {ElementType::LIGHTNING, 1},
        {ElementType::PHYSICAL, 1},
        {ElementType::IMAGINARY, 1}
};
unordered_map<Path, double> tauntValueEachPath = {
    {Path::ABUNDANCE, 100},
    {Path::PRESERVATION, 150},
    {Path::HUNT, 75},
    {Path::ERUDITION, 75},
    {Path::DESTRUCTION, 125},
    {Path::HARMONY, 100},
    {Path::NIHILITY, 100},
    {Path::REMEMBRANCE, 100},
    {Path::ELATION, 100}
};
ActionValueStats* turn = nullptr;
queue<shared_ptr<ActionData>> actionBar;
queue<shared_ptr<AllyActionData>> ahaInstantBar;

double levelMultiplier = 3767.5533;
double currentAtv =0;

PhaseStatus phaseStatus = PhaseStatus::NONE;
bool actionBarUse = 0;
bool adjustCheck = 0;
bool turnSkip=0;
string territory = "None";
int healCount;
int decreaseHPCount;

bool bestBounce = 0;

//Aha
unique_ptr<ActionValueStats> aha = make_unique<ActionValueStats>("Aha",80);
int punchline = 0;
int elationCount = 0;
int cbDuration = 2; // Certified Banger duration (turns) · Yao Guang A6 +1
deque<tuple<string,int, double>> cbCheck;


int spSafety = 1;
int nextForwardPriority = 0;  // ตัวนับที่แจกค่า priority ให้ unit ตัวถัดไปที่โดน actionForward จน atv แตะ 0 (reset ต่อ run ใน Reset())
double enemyEffectRes =40;

SubstatsRerollMode rerollSubstatsMode = SubstatsRerollMode::STANDARD; 
function<bool(CharUnit *ptr)> rerollFunction;

//-------- Trigger Function --------//
vector<TriggerByYourSelfFunc> setupList;
vector<TriggerByYourSelfFunc> resetList;
vector<TriggerByYourSelfFunc> whenOnFieldList;
vector<TriggerByYourSelfFunc> tuneStatsList;
vector<TriggerByYourSelfFunc> startGameList;
vector<TriggerByYourSelfFunc> startWaveList;
vector<TriggerByYourSelfFunc> beforeTurnList;
vector<TriggerByYourSelfFunc> afterTurnList;
vector<TriggerByYourSelfFunc> ultimateList;
vector<TriggerByYourSelfFunc> elationSkillList;
vector<TriggerByYourSelfFunc> beforeAhaInstantList;
vector<TriggerByYourSelfFunc> afterAhaInstantList;
vector<TriggerByAllyFunc> whenUseUltList;


vector<TriggerByActionFunc> beforeActionList;
vector<TriggerByActionFunc> afterActionList;
vector<TriggerByAllyActionFunc> beforeAllyActionList;
vector<TriggerByAllyActionFunc> afterAllyActionList;
vector<TriggerByAllyAttackActionFunc> beforeAttackActionList;
vector<TriggerByAllyAttackActionFunc> afterAttackActionList;
vector<TriggerByAllyAttackActionFunc> beforeAttackList;
vector<TriggerByAllyAttackActionFunc> afterAttackList;
vector<TriggerByAllyAttackActionFunc> beforeAttackPerHitList;
vector<TriggerByAllyAttackActionFunc> afterAttackPerHitList;
vector<TriggerByAllyAttackActionFunc> whenAttackList;
vector<TriggerByAllyBuffActionFunc> buffList;

vector<TriggerByStats> statsAdjustList;
vector<TriggerHealing> healingList;
vector<TriggerDecreaseHP> hpDecreaseList;
vector<TriggerAllyDeath> allyDeathList;

vector<TriggerBySomeAllyFunc> toughnessBreakList;
vector<TriggerBySomeAllyFunc> beforeApplyDebuff;
vector<TriggerBySomeAllyFunc> afterApplyDebuff;
vector<TriggerBySomeAllyFunc> enemyDeathList;

vector<TriggerByWeaknessApplyFunc> weaknessApplyList;
vector<TriggerByEnemyHit> enemyHitList;
vector<TriggerDotFunc> dotList;
vector<TriggerEnergyIncreaseFunc> whenEnergyIncreaseList;
vector<TriggerSkillPointFunc> skillPointList;
vector<TriggerSkillPointFunc> punchLineList;
vector<TriggerAfterDealDamage> afterDealingDamageList;


string toString(ElementType type){
        switch(type) {
                case ElementType::FIRE: return "Fire";
                case ElementType::ICE: return "Ice";
                case ElementType::LIGHTNING: return "Lightning";
                case ElementType::WIND: return "Wind";
                case ElementType::QUANTUM: return "Quantum";
                case ElementType::IMAGINARY: return "Imaginary";
                case ElementType::PHYSICAL: return "Physical";
                default: return "";
        }
}
string toString(Stats type){
        switch(type) {
                case Stats::HP_P: return "HP%";
                case Stats::FLAT_HP: return "Flat HP";
                case Stats::ATK_P: return "ATK%";
                case Stats::FLAT_ATK: return "Flat ATK";
                case Stats::DEF_P: return "DEF%";
                case Stats::FLAT_DEF: return "Flat DEF";
                case Stats::DMG: return "DMG%";
                case Stats::CR: return "Crit rate";
                case Stats::CD: return "Crit dam";
                case Stats::BE: return "BE";
                case Stats::DEF_SHRED: return "DEF Shred";
                case Stats::RESPEN: return "Respen";
                case Stats::VUL: return "Vul";
                case Stats::RES: return "Res";
                case Stats::EHR: return "Ehr";
                case Stats::ER: return "ER";
                case Stats::HEALING_OUT: return "Healing out";
                case Stats::HEALING_IN: return "Healing in";
                case Stats::SHEILD: return "Sheild";
                case Stats::FLAT_SPD: return "Flat Spd";
                case Stats::SPD_P: return "Spd%";
                case Stats::BREAK_EFF: return "Break Effeciency";
                case Stats::TOUGH_REDUCE: return "Toughness Reduce";
                default: return "";
        }
}

#endif
