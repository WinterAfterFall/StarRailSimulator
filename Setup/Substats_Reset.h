#ifndef Setup_Substats_H
#define Setup_Substats_H
#include "../Print.h"
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
        if(ptr->Substats[i].first=="Crit_rate"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Crit_rate","None",2.9*ptr->Substats[i].second);
            }

        }else if(ptr->Substats[i].first=="Crit_dam"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Crit_dam","None",5.8*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first=="Atk%"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Atk%","None",3.888*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first=="Def%"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Def%","None",4.86*ptr->Substats[i].second);
            }
            
        }else if(ptr->Substats[i].first=="Break_effect"){
            for(int j=0,SZ = ptr->Sub_Unit_ptr.size();j<SZ;j++){
            Buff_single_target(ptr->Sub_Unit_ptr[j].get(),"Break_effect","None",5.8*ptr->Substats[i].second);
            }
        }
    }
}
bool Reroll_substats(Ally *ptr){
    
    if(0 == ptr->Reroll_check){
        double Temp_mx=0;
        ptr->Average_Damage = 0;
        ptr->Average_damage_instance.clear();
        
        for(int i=1;i<=Total_enemy;i++){    
            Temp_mx+=ptr->Normal_Damage[i];
            ptr->Normal_Damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            Temp_mx+=ptr->Break_damage[i];
            ptr->Break_damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            Temp_mx+=ptr->Dot_damage[i];
            ptr->Dot_damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            Temp_mx+=ptr->Superbreak_damage[i];
            ptr->Superbreak_damage[i] = 0;
        }
        return 0;
    }
    // cout<<ptr->Current_sub_choose<<endl;
    // cout<<ptr->Current_spilt<<endl;
    // cout<<ptr->Total_damage<<endl;


    if(ptr->Current_spilt==0){
        ptr->Current_spilt = 1;
        return 1;
    }
    
    if(ptr->Total_damage > ptr->Max){
        ptr->Max = ptr->Total_damage;
        ptr->Max_Average_Damage = ptr->Average_Damage;
        for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++){
            ptr->Max_damage_Substats[i] = ptr->Substats[i].second;
            ptr->Stop_reroll = 0;
        }
    }
    ptr->Total_damage = 0;
    ptr->Average_Damage = 0;
    ptr->Average_damage_instance.clear();
    
    for(int i=1;i<=Total_enemy;i++){
        ptr->Normal_Damage[i] = 0;
    }
    for(int i=1;i<=Total_enemy;i++){
        ptr->Break_damage[i] = 0;
    }
    for(int i=1;i<=Total_enemy;i++){
        ptr->Dot_damage[i] = 0;
    }
    for(int i=1;i<=Total_enemy;i++){
        ptr->Superbreak_damage[i] = 0;
    }
    
    if(ptr->Current_sub_choose+1==ptr->Current_spilt){
        
        if(1 == ptr->Stop_reroll||ptr->Separate_sub==0){
            ptr->Current_spilt++;
            if(ptr->Current_spilt==ptr->Substats.size()){
                ptr->Reroll_check=0;
                for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++){
                    ptr->Substats[i].second = ptr->Max_damage_Substats[i];
                }
                return 0;
            }
            ptr->Separate_sub = ptr->Total_substats-1;
            ptr->Current_sub_choose = 0;
            ptr->Stop_reroll = 1;

            ptr->Substats[0].second = ptr->Max_damage_Substats[0]-1;
            for(int i=1;i<ptr->Current_spilt;i++){
                ptr->Substats[i].second = ptr->Max_damage_Substats[i];
            }
            ptr->Substats[ptr->Current_spilt].second = ptr->Max_damage_Substats[ptr->Current_spilt]+1;
        
            
        }else{
        --ptr->Separate_sub;
        ptr->Current_sub_choose = 0;
        ptr->Stop_reroll = 1;
        ptr->Substats[0].second = ptr->Max_damage_Substats[0]-1;
        for(int i=1;i<ptr->Current_spilt;i++){
            ptr->Substats[i].second = ptr->Max_damage_Substats[i];
        }
        ptr->Substats[ptr->Current_spilt].second = ptr->Max_damage_Substats[ptr->Current_spilt]+1;
        }
    }else{
        ptr->Substats[ptr->Current_sub_choose].second++;
        ++ptr->Current_sub_choose;
        ptr->Substats[ptr->Current_sub_choose].second--;

    }
    return 1;

}
bool Permutation_Substats(Ally *ptr){
    if(0 == ptr->Reroll_check)return false;
    int index = 0;
        
        for(int i=1;i<=Total_enemy;i++){    
            ptr->Normal_Damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            ptr->Break_damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            ptr->Dot_damage[i] = 0;
        }
        for(int i=1;i<=Total_enemy;i++){
            ptr->Superbreak_damage[i] = 0;
        }
        for(int i=0;i<ptr->Substats.size();i++){
            index+= ptr->Substats[i].second*pow(ptr->Total_substats+1,i);
        }
        ptr->Damage_data[index] = ptr->Average_Damage;
        ptr->Average_Damage = 0;
        ptr->Average_damage_instance.clear();
    if(ptr->Substats[ptr->Substats.size()-1].second==ptr->Current_substats){
        if(Calculate_All_possible_mode){
            ptr->Current_substats--;
            ptr->Substats[0].second = ptr->Current_substats; 
            for(int i=1;i<ptr->Substats.size();i++){
                ptr->Substats[i].second = 0; 
            }
            if(ptr->Current_substats>=0)return true;
        }
        ptr->Reroll_check = 0;
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

#endif