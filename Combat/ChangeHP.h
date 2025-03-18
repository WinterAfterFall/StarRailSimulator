#ifndef CHANGEHP_H
#define CHANGEHP_H
#include "../Print.h"

// void Healing(Heal_data* Healptr){
//     priority_queue<PointerWithValue, vector<PointerWithValue>, decltype(&PointerWithValue::Greater_cmp)> pq(&PointerWithValue::Less_cmp);

//     for(int i=1;i<=Total_ally;i++){
//         for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
//             pq.push(PointerWithValue(Ally_unit[i]->Sub_Unit_ptr[j].get(),calculateHPLost(Ally_unit[i]->Sub_Unit_ptr[j].get())));
//             if(pq.size()>3){
                
//                 pq.pop();
//             }
//         }
//     }
//     while(!pq.empty()){

//         pq.pop();
//     }
// }
#endif