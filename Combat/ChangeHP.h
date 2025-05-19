#ifndef CHANGEHP_H
#define CHANGEHP_H
#include "../Class/Trigger_Function.h"

void RestoreHP(SubUnit *healer,HealRatio main,HealRatio adjacent,HealRatio other){
    healCount++;
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);
    
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            pq.push(PointerWithValue(Ally_unit[i]->Sub_Unit_ptr[j].get(),calculateHPLost(Ally_unit[i]->Sub_Unit_ptr[j].get())));
            if(pq.size()>3){
                double totalHeal = 0;
                if(other.ATK!=0||other.HP!=0||other.DEF!=0||other.fixHeal!=0||other.healFromTotalHP!=0||other.healFromLostHP!=0){
                    totalHeal = calculateHeal(other,healer,pq.top().ptr);
                    IncreaseHP(healer,pq.top().ptr,totalHeal);
                }
                pq.pop();
            }
        }
    }
    
    while(!pq.empty()){
        double totalHeal = 0;
        if(pq.size()==1){
            totalHeal = calculateHeal(main,healer,pq.top().ptr);
        }else{
            totalHeal = calculateHeal(adjacent,healer,pq.top().ptr);
        }
        IncreaseHP(healer,pq.top().ptr,totalHeal);
        pq.pop();
    }
    
}
//heal เดี่ยว
void RestoreHP(HealRatio Healptr,SubUnit *Healer,SubUnit *target){
    healCount++;
    double totalHeal = calculateHeal(Healptr,Healer,target);
    IncreaseHP(Healer,target,totalHeal);

}
//heal ทั้งทีมแบบเท่าเที่ยม
void RestoreHP(HealRatio healRatio,SubUnit *Healer){
    healCount++;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            double totalHeal = calculateHeal(healRatio,Healer,Ally_unit[i]->Sub_Unit_ptr[j].get());
            IncreaseHP(Healer,Ally_unit[i]->Sub_Unit_ptr[j].get(),totalHeal);
        }
    }
}
//heal ทั้งทีมแบบฮีลคนนึงเยอะสุด
void RestoreHP(HealRatio healRatioMain,HealRatio healRatio,SubUnit *Healer,SubUnit *target){
    healCount++;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            double totalHeal = (target->Atv_stats->Unit_Name == Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Unit_Name) ? 
            calculateHeal(healRatioMain,Healer,Ally_unit[i]->Sub_Unit_ptr[j].get())
            :
            calculateHeal(healRatio,Healer,Ally_unit[i]->Sub_Unit_ptr[j].get());
            IncreaseHP(Healer,Ally_unit[i]->Sub_Unit_ptr[j].get(),totalHeal);
        }
    }
}
void IncreaseCurrentHP(SubUnit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP + Value > ptr->totalHP) ? ptr->totalHP : ptr->currentHP + Value;
}
void IncreaseHP(SubUnit *Healer,SubUnit *target,double Value){
    if(Value==0||target->currentHP<=0)return;
    IncreaseCurrentHP(target,Value);
    allEventHeal(Healer,target,Value);
}

void DecreaseCurrentHP(SubUnit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP - Value < 1) ? 1 : ptr->currentHP - Value;
}
void DecreaseHP(SubUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    double Total = Value;
    if(target->currentHP<=0)return;
    Total += (percentFromTotalHP/100.0*target->totalHP);
    Total += (percentFromCurrentHP/100.0*target->currentHP);
    DecreaseCurrentHP(target,Total);
    allEventChangeHP(Trigger,target,Total);
}
//ลดเลือดทั้งทีม
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (int i = 1; i <= Total_ally; ++i) {
        for (unique_ptr<SubUnit> &subUnit : Ally_unit[i]->Sub_Unit_ptr) {
            double Total = Value;
            if(subUnit->currentHP<=0)return;
            Total += (percentFromTotalHP/100.0*subUnit->totalHP);
            Total += (percentFromCurrentHP/100.0*subUnit->currentHP);
            DecreaseCurrentHP(subUnit.get(),Total);
            allEventChangeHP(Trigger,subUnit.get(),Total);
        }
    }
}
void DecreaseHP(Unit *Trigger,vector<SubUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (SubUnit* &subUnit : target) {
        double Total = Value;
        if(subUnit->currentHP<=0)return;
        Total += (percentFromTotalHP/100.0*subUnit->totalHP);
        Total += (percentFromCurrentHP/100.0*subUnit->currentHP);
        DecreaseCurrentHP(subUnit,Total);
        allEventChangeHP(Trigger,subUnit,Total);
    }
    
}
//ลดเลือดทั้งทีมยกเว้นตัวเอง
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    decreaseHPCount++;
    for (int i = 1; i <= Total_ally; ++i) {
        for (unique_ptr<SubUnit> &subUnit : Ally_unit[i]->Sub_Unit_ptr) {
            if(subUnit->isSameCharName(Name))continue;
            double Total = Value;
            if(subUnit->currentHP<=0)return;
            Total += (percentFromTotalHP/100.0*subUnit->totalHP);
            Total += (percentFromCurrentHP/100.0*subUnit->currentHP);
            DecreaseCurrentHP(subUnit.get(),Total);
            allEventChangeHP(Trigger,subUnit.get(),Total);
        }
    }

}
void SubUnit::Death(){
    this->currentHP = 0;
    this->Atv_stats->Base_speed=-1;
    Update_Max_atv(this->Atv_stats.get());
    resetTurn(this->Atv_stats.get());
    allEventWhenAllyDeath(this);
}
#endif