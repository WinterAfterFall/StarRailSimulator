#ifndef ActionDataDefine_H
#define ActionDataDefine_H

#include "AllyAttackAction.h"
#include "AllyBuffAction.h"
bool AllyActionData::isSameUnitName(AllyUnit *ptr){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameStatsOwnerName(ptr))return true;
        }
    }else{
        if(this->Attacker->isSameStatsOwnerName(ptr))return true;
    }
    return false;
}

bool AllyActionData::isSameCharName(CharUnit *ptr){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(ptr->isSameChar(each.attacker))return true;
        }
    }else{
        if(ptr->isSameChar(this->Attacker))return true;
    }
    return false;
}


bool AllyActionData::isSameUnitName(string name){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameStatsOwnerName(name))return true;
        }
    }else{
        if(this->Attacker->isSameStatsOwnerName(name))return true;
    }
    return false;
}


bool AllyActionData::isSameAction(AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each1 : attackAct->AttackSetList){
            for(auto &each2 : each1.actionTypeList){
                if(each2 == ability)return true;
            }   
        }
    }else{
        for(auto &each : actionTypeList){
                if(each == ability)return true;
        }   
    }
    return false;
}

bool AllyActionData::isSameAction(AllyUnit *ptr,AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameStatsOwnerName(ptr)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(this->Attacker->isSameStatsOwnerName(ptr)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
    }
    return false;
}

bool AllyActionData::isSameAction(string name,AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameStatsOwnerName(name)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(this->Attacker->isSameStatsOwnerName(name)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
    }
    return false;
}
bool AllyActionData::isSameAction(CharUnit *ptr,AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(ptr->isSameChar(each.attacker)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(ptr->isSameChar(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
    }
    return false;
}
bool AllyAttackAction::isSameDamageType(AType ability){
    for(auto &each1 : AttackSetList){
        for(auto &each2 : each1.damageTypeList){
            if(each2 == ability) return true;
        }
    }
    return false;
}

bool AllyAttackAction::isSameDamageType(AllyUnit *ptr, AType ability){
    for(auto &each : AttackSetList){
        if(each.attacker->isSameStatsOwnerName(ptr)){
            for(auto &each2 : each.damageTypeList){
                if(each2 == ability) return true;
            }
        }
    }
    return false;
}

bool AllyAttackAction::isSameDamageType(string name, AType ability){
    for(auto &each : AttackSetList){
        if(each.attacker->isSameStatsOwnerName(name)){
            for(auto &each2 : each.damageTypeList){
                if(each2 == ability) return true;
            }
        }
    }
    return false;
}

bool AllyAttackAction::isSameDamageType(CharUnit *ptr, AType ability){
    for(auto &each : AttackSetList){
        if(ptr->isSameChar(each.attacker)){
            for(auto &each2 : each.damageTypeList){
                if(each2 == ability) return true;
            }
        }
    }
    return false;
}
#endif