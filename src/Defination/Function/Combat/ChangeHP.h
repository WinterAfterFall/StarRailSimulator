#include "../include.h"

void AllyUnit::RestoreHP(HealSrc main,HealSrc adjacent,HealSrc other){
    healCount++;
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);
    
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
            if(other.ATK!=0||other.HP!=0||other.DEF!=0||other.constHeal!=0||other.healFromTotalHP!=0||other.healFromLostHP!=0){
                totalHeal = calculateHeal(other,this,pq.top().ptr);
                IncreaseHP(this,pq.top().ptr,totalHeal);
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
        IncreaseHP(this,pq.top().ptr,totalHeal);
        pq.pop();
    }
    
    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }
    
}
//heal เดี่ยว
void AllyUnit::RestoreHP(AllyUnit *target,HealSrc Healptr){
    healCount++;

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    double totalHeal = calculateHeal(Healptr,this,target);
    IncreaseHP(this,target,totalHeal);

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }

}
//heal ทั้งทีมแบบเท่าเที่ยม
void AllyUnit::RestoreHP(HealSrc healSrc){
    healCount++;
    
    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    for(auto &each : allyList){
        if(!each->isTargetable())continue;
        double totalHeal = calculateHeal(healSrc,this,each);
        IncreaseHP(this,each,totalHeal);
    }

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }

}
//heal ทั้งทีมแบบฮีลคนนึงเยอะสุด
void AllyUnit::RestoreHP(AllyUnit *target,HealSrc main,HealSrc other){
    healCount++;

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"\n----------------------- Heal Count : "<<healCount<<" -----------------------\n";
        cout << "\033[0m";
    }

    for(auto &each : allyList){
            if(!each->isTargetable())continue;
            double totalHeal = (target->Atv_stats->StatsOwnerName == each->Atv_stats->StatsOwnerName) ? 
            calculateHeal(main,this,each)
            :
            calculateHeal(other,this,each);
            IncreaseHP(this,each,totalHeal);
    }

    if(this->owner->checkHeal||this->owner->checkHealFormula){
        cout<<"\033[0;38;5;2m";
        cout<<"-----------------------------------------------------------\n";
        cout << "\033[0m";
    }
}
void IncreaseCurrentHP(AllyUnit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP + Value > ptr->totalHP) ? ptr->totalHP : ptr->currentHP + Value;
}
void IncreaseHP(AllyUnit *Healer,AllyUnit *target,double Value){
    if(Value==0||!target->isExsited())return;
    IncreaseCurrentHP(target,Value);
    allEventHeal(Healer,target,Value);
}

void DecreaseCurrentHP(AllyUnit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP - Value < 1) ? 1 : ptr->currentHP - Value;
}
void DecreaseHP(AllyUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;

    double Total = Value;
    if(!target->isExsited())return;
    Total += (percentFromTotalHP/100.0*target->totalHP);
    Total += (percentFromCurrentHP/100.0*target->currentHP);
    DecreaseCurrentHP(target,Total);
    allEventChangeHP(Trigger,target,Total);
    
}
//ลดเลือดทั้งทีม
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;

    for (auto &each : allyList) {
        double Total = Value;
        if(!each->isTargetable())return;
        Total += (percentFromTotalHP/100.0*each->totalHP);
        Total += (percentFromCurrentHP/100.0*each->currentHP);
        DecreaseCurrentHP(each,Total);
        allEventChangeHP(Trigger,each,Total);
    }

}
void DecreaseHP(Unit *Trigger,vector<AllyUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (AllyUnit* &AllyUnit : target) {
        double Total = Value;
        if(!AllyUnit->isTargetable())return;
        Total += (percentFromTotalHP/100.0*AllyUnit->totalHP);
        Total += (percentFromCurrentHP/100.0*AllyUnit->currentHP);
        DecreaseCurrentHP(AllyUnit,Total);
        allEventChangeHP(Trigger,AllyUnit,Total);
    }
    
}
//ลดเลือดทั้งทีมยกเว้นตัวเอง
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (auto &each : allyList) {
        if(each->isSameUnitName(Name))continue;
        double Total = Value;
        if(!each->isTargetable())return;
        Total += (percentFromTotalHP/100.0*each->totalHP);
        Total += (percentFromCurrentHP/100.0*each->currentHP);
        DecreaseCurrentHP(each,Total);
        allEventChangeHP(Trigger,each,Total);
    }

}
void AllyUnit::death(){
    this->currentHP = 0;
    this->status = UnitStatus::Death;
    allEventWhenAllyDeath(this);
}