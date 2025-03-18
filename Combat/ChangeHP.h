#ifndef CHANGEHP_H
#define CHANGEHP_H
#include "../Print.h"

void Healing(Heal_data* Healptr){
    priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);

    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            pq.push(PointerWithValue(Ally_unit[i]->Sub_Unit_ptr[j].get(),calculateHPLost(Ally_unit[i]->Sub_Unit_ptr[j].get())));
            if(pq.size()>3){
                double totalHeal = 0;
                if(Healptr->other.ATK==0&&Healptr->other.HP==0&&Healptr->other.DEF==0){
                    totalHeal = calculateHeal(Healptr,Healptr->other,pq.top().ptr);
                    IncreaseHP(Healptr->Healer,pq.top().ptr,totalHeal);
                }
                pq.pop();
            }
        }
    }
    while(!pq.empty()){
        double totalHeal = 0;
        if(pq.size()==1){
            totalHeal = calculateHeal(Healptr,Healptr->main,pq.top().ptr);
        }else{
            totalHeal = calculateHeal(Healptr,Healptr->adjacent,pq.top().ptr);
        }
        IncreaseHP(Healptr->Healer,pq.top().ptr,totalHeal);
        pq.pop();
    }
}
void IncreaseCurrentHP(Sub_Unit *ptr,double Value){
    ptr->currentHP = (ptr->currentHP + Value > ptr->totalHP) ? ptr->totalHP : ptr->currentHP + Value;
}
void IncreaseHP(Sub_Unit *Healer,Sub_Unit *target,double Value){
    IncreaseCurrentHP(target,Value);
    allEventChangeHP(Healer,target,Value);
}
#endif