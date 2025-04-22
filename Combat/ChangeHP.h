#ifndef CHANGEHP_H
#define CHANGEHP_H
#include "../Class/Trigger_Function.h"

void Healing(Heal_data& Healptr){
    healCount++;
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);
    
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            if(Ally_unit[i]->Sub_Unit_ptr[j]->currentHP==0)continue;
            pq.push(PointerWithValue(Ally_unit[i]->Sub_Unit_ptr[j].get(),calculateHPLost(Ally_unit[i]->Sub_Unit_ptr[j].get())));
            if(pq.size()>3){
                double totalHeal = 0;
                if(Healptr.other.ATK!=0||Healptr.other.HP!=0||Healptr.other.DEF!=0||Healptr.other.fixHeal!=0||Healptr.other.healFromTotalHP!=0||Healptr.other.healFromLostHP!=0){
                    totalHeal = calculateHeal(Healptr,Healptr.other,pq.top().ptr);
                    IncreaseHP(Healptr.Healer,pq.top().ptr,totalHeal);
                }
                pq.pop();
            }
        }
    }
    
    while(!pq.empty()){
        double totalHeal = 0;
        if(pq.size()==1){
            totalHeal = calculateHeal(Healptr,Healptr.main,pq.top().ptr);
        }else{
            totalHeal = calculateHeal(Healptr,Healptr.adjacent,pq.top().ptr);
        }
        IncreaseHP(Healptr.Healer,pq.top().ptr,totalHeal);
        pq.pop();
    }
    
}
//heal เดี่ยว
void Healing(HealRatio& Healptr,SubUnit *Healer,SubUnit *target){
    healCount++;
    double totalHeal = calculateHeal(Healptr,Healer,target);
    IncreaseHP(Healer,target,totalHeal);

}
//heal ทั้งทีมแบบเท่าเที่ยม
void Healing(HealRatio& healRatio,SubUnit *Healer){
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
void Healing(HealRatio& healRatioMain,HealRatio& healRatio,SubUnit *Healer,SubUnit *target){
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