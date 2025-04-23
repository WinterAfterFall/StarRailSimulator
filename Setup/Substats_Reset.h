#ifndef Setup_Substats_H
#define Setup_Substats_H
#include "../Class/Trigger_Function.h"
void Set_Stats(Ally *ptr){
    for(int i=0,sz = ptr->Substats.size();i<sz;i++){
        if(ptr->Substats[i].first=="Speed"){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=2.3*ptr->Substats[i].second;
            for(int j=1,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            ptr->Sub_Unit_ptr[j]->Atv_stats->Flat_Speed+=(2.3*ptr->Substats[i].second)*(ptr->Sub_Unit_ptr[j]->Unit_Speed_Ratio/100);
            }
            
        }else if(ptr->Substats[i].first=="Hp%"){ 
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Hp%","None",3.888*ptr->Substats[i].second);
            }
        }
        if(ptr->Substats[i].first==ST_CR){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),ST_CR,"None",2.9*ptr->Substats[i].second);
            }

        }else if(ptr->Substats[i].first==ST_CD){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),ST_CD,"None",5.8*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first=="Atk%"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Atk%","None",3.888*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first=="Def%"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Def%","None",4.86*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first==ST_BE){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),ST_BE,"None",5.8*ptr->Substats[i].second);
            }
        }
    }
}
bool Reroll_substats(){
    bool ans = true;
    for(int i=1; i<= Total_ally; i++){
        again:
        if(rerollFunction(Ally_unit[i].get()))
        ans = false;
        else continue;
        for(auto &e:Ally_unit[i]->Substats){
            if(e.second<0){
                goto again;
            }
        }
        
    }
    return ans;
    
}
bool StandardReroll(Ally *ptr){
    
    if(0 == ptr->Reroll_check) return false;
    if(changeMaxDamage(ptr))ptr->Stop_reroll = 0;
    if(ptr->Substats.size()==1){
        ptr->Reroll_check = 0;
        return false;
    }

    if(ptr->Current_sub_choose+1==ptr->spiltPoint){
        
        if(1 == ptr->Stop_reroll||ptr->SeparateRatio==0){
            ptr->spiltPoint++;
            if(ptr->spiltPoint==ptr->Substats.size()){
                ptr->Reroll_check=0;
                for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++){
                    ptr->Substats[i].second = ptr->Max_damage_Substats[i];
                }
                return 0;
            }
            ptr->SeparateRatio = ptr->Total_substats-1;
            ptr->Current_sub_choose = 0;
            ptr->Stop_reroll = 1;

            ptr->Substats[0].second = ptr->Max_damage_Substats[0]-1;
            for(int i=1;i<ptr->spiltPoint;i++){
                ptr->Substats[i].second = ptr->Max_damage_Substats[i];
            }
            ptr->Substats[ptr->spiltPoint].second = ptr->Max_damage_Substats[ptr->spiltPoint]+1;
        
            
        }else{
        --ptr->SeparateRatio;
        ptr->Current_sub_choose = 0;
        ptr->Stop_reroll = 1;
        ptr->Substats[0].second = ptr->Max_damage_Substats[0]-1;
        for(int i=1;i<ptr->spiltPoint;i++){
            ptr->Substats[i].second = ptr->Max_damage_Substats[i];
        }
        ptr->Substats[ptr->spiltPoint].second = ptr->Max_damage_Substats[ptr->spiltPoint]+1;
        }
    }else{
        ptr->Substats[ptr->Current_sub_choose].second++;
        ++ptr->Current_sub_choose;
        ptr->Substats[ptr->Current_sub_choose].second--;

    }
    return 1;

}
bool AllCombinationReroll(Ally *ptr){
    if(0 == ptr->Reroll_check&&ptr->Max_Average_Damage>=0)return false;
    changeMaxDamage(ptr);
    if(ptr->Substats.size()<=1||ptr->Reroll_check==0){
        ptr->Reroll_check = 0;
        return false;
    }
    int index = 0;
    
        for(int i=0;i<ptr->Substats.size();i++){
            index+= ptr->Substats[i].second*pow(ptr->Total_substats+1,i);
        }
        ptr->Damage_data[index] = ptr->Average_Damage;
         
        if(ptr->Substats[ptr->Substats.size()-1].second==ptr->currentTotalSubstats){
        ptr->Reroll_check = 0;
        for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++)
        ptr->Substats[i].second = ptr->Max_damage_Substats[i];
        return false;
    }

    for(int i=0;i<ptr->Substats.size();i++){
        if(ptr->Substats[i].second!=0){
            ptr->Substats[0].second = ptr->Substats[i].second-1;
            if(i!=0){
              ptr->Substats[i].second = 0;  
            }
            ptr->Substats[i+1].second+=1;
            return true;
        }
    }
    return false;
}
bool AllPossibleReroll(Ally *ptr){
    if(0 == ptr->Reroll_check)return false;
    changeMaxDamage(ptr);
    if(ptr->Substats.size()<=1){
        ptr->Reroll_check = 0;
        return false;
    }
    int index = 0;
    
        for(int i=0;i<ptr->Substats.size();i++){
            index+= ptr->Substats[i].second*pow(ptr->Total_substats+1,i);
        }
        ptr->Damage_data[index] = ptr->Average_Damage;
    
    // When Reroll with all Combination it will decrease total substats
    if(ptr->Substats[ptr->Substats.size()-1].second==ptr->currentTotalSubstats){
        
        ptr->currentTotalSubstats--;
        ptr->Substats[0].second = ptr->currentTotalSubstats; 
        for(int i=1;i<ptr->Substats.size();i++){
            ptr->Substats[i].second = 0; 
        }
        if(ptr->currentTotalSubstats>=0)return true;
        
        ptr->Reroll_check = 0;
        return false;
    }
    
    //Reroll
    for(int i=0;i<ptr->Substats.size();i++){
        if(ptr->Substats[i].second!=0){
            ptr->Substats[0].second = ptr->Substats[i].second-1;
            if(i!=0){
              ptr->Substats[i].second = 0;  
            }
            ptr->Substats[i+1].second+=1;
            return true;
        }
    }
    return false;
}

#endif