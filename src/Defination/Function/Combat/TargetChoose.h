#include "../include.h"

SubUnit* ActionValueStats::canCastToSubUnit(){
    return dynamic_cast<SubUnit*>(this->ptrToChar);
}
Enemy* ActionValueStats::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this->ptrToChar);
}
SubUnit* Unit::canCastToSubUnit() {
    return dynamic_cast<SubUnit*>(this);
}
Enemy* Unit::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this);
}

SubUnit* chooseSubUnitBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum]->Sub_Unit_ptr[ptr->currentSubUnitTargetNum].get();
}
Ally* chooseCharacterBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum].get();
}
Enemy* chooseEnemyTarget(SubUnit *ptr){
    return Enemy_unit[ptr->Enemy_target_num].get();
}