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

AllyUnit* chooseAllyBuff(AllyUnit *ptr){
    if(!ptr || ptr->currentCharNum < 0 || ptr->currentCharNum >= static_cast<int>(charUnit.size())) return nullptr;
    CharUnit *character = charUnit[ptr->currentCharNum].get();
    if(!character) return nullptr;
    if(ptr->currentMemoNum){
        int memoIndex = ptr->currentMemoNum - 1;
        if(memoIndex < 0 || memoIndex >= static_cast<int>(character->memospriteList.size())) return character;
        return character->memospriteList[memoIndex].get();
    }
    return character;
}
CharUnit* chooseCharacterBuff(AllyUnit *ptr){
    if(!ptr || ptr->currentCharNum < 0 || ptr->currentCharNum >= static_cast<int>(charUnit.size())) return nullptr;
    return charUnit[ptr->currentCharNum].get();
}
Enemy* chooseEnemyTarget(AllyUnit *ptr){
    if(!ptr || ptr->Enemy_target_num < 0 || ptr->Enemy_target_num >= static_cast<int>(enemyUnit.size())) return nullptr;
    return enemyUnit[ptr->Enemy_target_num].get();
}
