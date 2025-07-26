#ifndef ActionDataDefine_H
#define ActionDataDefine_H

#include "AllyAttackAction.h"
#include "AllyBuffAction.h"
bool AllyActionData::isSameUnit(SubUnit *ptr){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameUnit(ptr))return true;
        }
    }else{
        if(this->Attacker->isSameUnit(ptr))return true;
    }
    return false;
}

bool AllyActionData::isSameAlly(Ally *ptr){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(ptr->isSameAlly(each.attacker))return true;
        }
    }else{
        if(ptr->isSameAlly(this->Attacker))return true;
    }
    return false;
}


bool AllyActionData::isSameUnitName(string name){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameUnitName(name))return true;
        }
    }else{
        if(this->Attacker->isSameUnitName(name))return true;
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

bool AllyActionData::isSameAction(SubUnit *ptr,AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(each.attacker->isSameUnit(ptr)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(this->Attacker->isSameUnit(ptr)){
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
            if(each.attacker->isSameUnitName(name)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(this->Attacker->isSameUnitName(name)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
    }
    return false;
}
bool AllyActionData::isSameAction(Ally *ptr,AType ability){
    AllyAttackAction * attackAct = dynamic_cast<AllyAttackAction*>(this);
    if(attackAct){
        for(auto &each : attackAct->AttackSetList){
            if(ptr->isSameAlly(each.attacker)){
                for(auto &each2 : each.actionTypeList){
                    if(each2 == ability)return true;
                }
            }
        }
    }else{
        if(ptr->isSameAlly(this->Attacker)){
            for(auto &each : actionTypeList){
                if(each == ability)return true;
            }
        }
    }
    return false;
}

#endif