#ifndef CHANGEHP_H
#define CHANGEHP_H
#include "../Print.h"

void Healing(Heal_data& Healptr){
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);

    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
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
void Healing(HealRatio& Healptr,Sub_Unit *Healer,Sub_Unit *target){
    double totalHeal = calculateHeal(Healptr,Healer,target);
    IncreaseHP(Healer,target,totalHeal);

}
void Healing(HealRatio& healRatio,Sub_Unit *Healer){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            double totalHeal = calculateHeal(healRatio,Healer,Ally_unit[i]->Sub_Unit_ptr[i].get());
            IncreaseHP(Healer,Ally_unit[i]->Sub_Unit_ptr[i].get(),totalHeal);
        }
    }
}
void Healing(HealRatio& healRatioMain,HealRatio& healRatio,Sub_Unit *Healer,Sub_Unit *target){

    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            double totalHeal = (target->Atv_stats->Unit_Name == Ally_unit[i]->Sub_Unit_ptr[i]->Atv_stats->Unit_Name) ? 
            calculateHeal(healRatioMain,Healer,Ally_unit[i]->Sub_Unit_ptr[i].get())
            :
            calculateHeal(healRatio,Healer,Ally_unit[i]->Sub_Unit_ptr[i].get());
            IncreaseHP(Healer,Ally_unit[i]->Sub_Unit_ptr[i].get(),totalHeal);
        }
    }
}
void IncreaseCurrentHP(Sub_Unit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP + Value > ptr->totalHP) ? ptr->totalHP : ptr->currentHP + Value;
}
void IncreaseHP(Sub_Unit *Healer,Sub_Unit *target,double Value){
    IncreaseCurrentHP(target,Value);
    allEventChangeHP(Healer,target,Value);
}

void DecreaseCurrentHP(Sub_Unit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP - Value < 1) ? 1 : ptr->currentHP - Value;
}
void DecreaseHP(Sub_Unit *target,double Value,double percentFromTotalHP,double percentFromCurrentHP){
    double Total = Value;
    if(target->currentHP<=0)return;
    Total += (percentFromTotalHP/100.0*target->totalHP);
    Total += (percentFromCurrentHP/100.0*target->currentHP);
    DecreaseCurrentHP(target,Total);
    allEventChangeHP(target,target,-Total);
}
#endif