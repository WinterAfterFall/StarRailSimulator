#include "../include.h"

AllyUnit* ActionValueStats::canCastToAllyUnit(){
    return dynamic_cast<AllyUnit*>(this->charptr);
}
Enemy* ActionValueStats::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this->charptr);
}
AllyUnit* Unit::canCastToSubUnit() {
    return dynamic_cast<AllyUnit*>(this);
}
Enemy* Unit::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this);
}

AllyUnit* chooseSubUnitBuff(AllyUnit *ptr){
    if(ptr->currentMemoNum)return charUnit[ptr->currentCharNum]->memospriteList[ptr->currentMemoNum].get();
    return charUnit[ptr->currentCharNum].get();
}
CharUnit* chooseCharacterBuff(AllyUnit *ptr){
    return charUnit[ptr->currentCharNum].get();
}
Enemy* chooseEnemyTarget(AllyUnit *ptr){
    return enemyUnit[ptr->Enemy_target_num].get();
}