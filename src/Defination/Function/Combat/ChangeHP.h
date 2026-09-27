#include "../include.h"

void AllyUnit::restoreHP(HealSrc main,HealSrc adjacent,HealSrc other){
    healCount++;
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::greaterCmp)> pq(&PointerWithValue::lessCmp);
    
    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }
    
    for(auto &each : allyList){
        if(!each->isTargetable())continue;
        pq.push(PointerWithValue(each,calculateHPLost(each)));
        if(pq.size()>3){
            double totalHeal = 0;
            if(other.atk!=0||other.hp!=0||other.def!=0||other.constHeal!=0||other.healFromTotalHP!=0||other.healFromLostHP!=0){
                totalHeal = calculateHeal(other,this,pq.top().ptr);
                increaseHP(this,pq.top().ptr,totalHeal);
            }
            pq.pop();
        }
    }
    
    while(!pq.empty()){
        double totalHeal = 0;
        if(pq.size()==1){
            totalHeal = calculateHeal(main,this,pq.top().ptr);
        }else{
            totalHeal = calculateHeal(adjacent,this,pq.top().ptr);
        }
        increaseHP(this,pq.top().ptr,totalHeal);
        pq.pop();
    }
    
    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }
    
}
//heal เดี่ยว
void AllyUnit::restoreHP(AllyUnit *target,HealSrc healPtr){
    healCount++;

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    double totalHeal = calculateHeal(healPtr,this,target);
    increaseHP(this,target,totalHeal);

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }

}
//heal ทั้งทีมแบบเท่าเที่ยม
void AllyUnit::restoreHP(HealSrc healSrc){
    healCount++;
    
    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    for(auto &each : allyList){
        if(!each->isTargetable())continue;
        double totalHeal = calculateHeal(healSrc,this,each);
        increaseHP(this,each,totalHeal);
    }

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }

}
//heal ทั้งทีมแบบฮีลคนนึงเยอะสุด
void AllyUnit::restoreHP(AllyUnit *target,HealSrc main,HealSrc other){
    healCount++;

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    for(auto &each : allyList){
            if(!each->isTargetable())continue;
            double totalHeal = (target->atvStats->name == each->atvStats->name) ? 
            calculateHeal(main,this,each)
            :
            calculateHeal(other,this,each);
            increaseHP(this,each,totalHeal);
    }

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }
}
void increaseCurrentHP(AllyUnit *ptr,double value){
    ptr->currentHP = (ptr->currentHP + value > ptr->totalHP) ? ptr->totalHP : ptr->currentHP + value;
}
void increaseHP(AllyUnit *healer,AllyUnit *target,double value){
    if(value==0||!target->isExisted())return;
    increaseCurrentHP(target,value);
    allEventHeal(healer,target,value);
}

double decreaseCurrentHP(AllyUnit *ptr,double value){
    double previousHP = ptr->currentHP;
    ptr->currentHP = (ptr->currentHP - value < 1) ? 1 : ptr->currentHP - value;
    return previousHP - ptr->currentHP;
}
void decreaseHP(AllyUnit *target,Unit *trigger,double value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;

    double total = value;
    if(!target->isExisted())return;
    total += (percentFromTotalHP/100.0*target->totalHP);
    total += (percentFromCurrentHP/100.0*target->currentHP);
    double actualDecrease = decreaseCurrentHP(target,total);
    allEventChangeHP(trigger,target,actualDecrease);
    
}
//ลดเลือดทั้งทีม
void decreaseHP(Unit *trigger,double value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;

    for (auto &each : allyList) {
        double total = value;
        if(!each->isTargetable())continue;
        total += (percentFromTotalHP/100.0*each->totalHP);
        total += (percentFromCurrentHP/100.0*each->currentHP);
        double actualDecrease = decreaseCurrentHP(each,total);
        allEventChangeHP(trigger,each,actualDecrease);
    }

}
void decreaseHP(Unit *trigger,vector<AllyUnit*> target,double value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (AllyUnit* &AllyUnit : target) {
        double total = value;
        if(!AllyUnit->isTargetable())continue;
        total += (percentFromTotalHP/100.0*AllyUnit->totalHP);
        total += (percentFromCurrentHP/100.0*AllyUnit->currentHP);
        double actualDecrease = decreaseCurrentHP(AllyUnit,total);
        allEventChangeHP(trigger,AllyUnit,actualDecrease);
    }
    
}
//ลดเลือดทั้งทีมยกเว้นตัวเอง
void decreaseHP(Unit *trigger,string name,double value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (auto &each : allyList) {
        if(each->isSameName(name))continue;
        double total = value;
        if(!each->isTargetable())continue;
        total += (percentFromTotalHP/100.0*each->totalHP);
        total += (percentFromCurrentHP/100.0*each->currentHP);
        double actualDecrease = decreaseCurrentHP(each,total);
        allEventChangeHP(trigger,each,actualDecrease);
    }

}
double decreaseSheild(AllyUnit *ptr,double value){
    double absorbed = min(ptr->currentSheild,value);   // โล่กันได้เท่าที่มี
    ptr->currentSheild -= absorbed;
    return value - absorbed;                            // ดาเมจส่วนที่ทะลุโล่ → เข้า HP
}
void AllyUnit::death(){
this->currentHP = 0;
    this->status = UnitStatus::DEATH;
    allEventWhenAllyDeath(this);
}
