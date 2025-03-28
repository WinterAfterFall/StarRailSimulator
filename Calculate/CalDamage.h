#ifndef Cal_damage_H
#define Cal_damage_H
#include<bits/stdc++.h>
#include "../Print.h"

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


void Cal_Damage(ActionData &data_,Enemy *target,Ratio_data Skill_mtpr){
    double Total_dmg = 0;
    bool Memo_check=1;
    if(data_.Attacker->Atv_stats->Side=="Memosprite"){
        for(auto e:data_.Skill_Type){
        if(e=="Summon")Memo_check=0;
    }
    }
    if(Memo_check){
        data_.Skill_Type.push_back("Summon");
    }
    if(Normal_Damage_Formula_check_mode&&data_.Attacker->Atv_stats->Unit_num==Normal_Damage_Formula_check_mode){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" :"<<endl;
        cout<<data_.Attacker->Base_atk<<" ";
        cout<<Cal_Atk_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Atk_ratio<<" ";
        cout<<data_.Attacker->Base_hp<<" ";
        cout<<Cal_Hp_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Hp_ratio<<" ";
        cout<<data_.Attacker->Base_def<<" ";
        cout<<Cal_Def_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Def_ratio<<" ";
        cout<<Cal_Bonus_dmg_multiplier(data_,target)<<" ";
        cout<<Cal_Crit_rate_multiplier(data_,target)<<" ";
        cout<<Cal_Crit_dam_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<" ";
        cout<<Cal_Toughness_multiplier(data_,target)<<" ";
        cout<<endl;
    }
    Total_dmg += Cal_Atk_multiplier(data_,target)*Skill_mtpr.Atk_ratio/100;
    Total_dmg += Cal_Hp_multiplier(data_,target)*Skill_mtpr.Hp_ratio/100;
    Total_dmg += Cal_Def_multiplier(data_,target)*Skill_mtpr.Def_ratio/100;
    Total_dmg = Total_dmg*Cal_Bonus_dmg_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Crit_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    
    
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Normal_Damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
    if(Normal_Damage_check_mode==data_.Attacker->Atv_stats->Unit_num){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" "<<data_.Action_type.second<<" "<<(long long)Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100<<" to Enemy"<<target->Atv_stats->Unit_num<<endl;
    }
    if(Memo_check){
        data_.Skill_Type.pop_back();
    }

}

void Cal_Toughness_reduction(ActionData &data_,Enemy* target,double Toughness_reduce){
    if(target->Weakness_type[data_.Damage_element]==0&& 0 == data_.Dont_care_weakness&&target->Current_toughness>0)return ;
    if(target->Weakness_type[data_.Damage_element]==0&& 0 != data_.Dont_care_weakness&&target->Current_toughness>0){
        Toughness_reduce*=(data_.Dont_care_weakness/100);
        target->Current_toughness-=Cal_Total_Toughness_Reduce(data_,target,Toughness_reduce);
        if(target->Current_toughness<=0){
            target->Current_toughness*=(100/data_.Dont_care_weakness);
        }
    }else{
        target->Current_toughness-=Cal_Total_Toughness_Reduce(data_,target,Toughness_reduce);
    }
    
    if(target->Current_toughness<=0&&target->Toughness_status==1){
        
        Toughness_break(data_,target);
        target->when_toughness_broken = Current_atv;
    }
}

void Cal_Break_damage(ActionData &data_,Enemy *target,double &Constant){
    double Total_dmg = Constant *Level_multiplier;
    if(Break_Formula_check_mode&&Break_Formula_check_mode==data_.Attacker->Atv_stats->Unit_num){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" ";
        cout<<(0.5+target->Max_toughness/40)<<" ";
        cout<<Cal_BreakEffect_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<" ";
        cout<<Cal_Toughness_multiplier(data_,target)<<" ";
        cout<<endl;
    }
    Total_dmg = Total_dmg*(0.5+target->Max_toughness/40);    
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Break_damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
    
}
void Cal_Freeze_damage(ActionData &data_,Enemy *target){
    double Total_dmg = Level_multiplier;
    
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Break_damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
    
}

void Cal_Dot_damage(ActionData &data_,Enemy *target,double Dot_ratio){
    double Total_dmg = 0;
    Total_dmg += Cal_Atk_multiplier(data_,target)*data_.Damage_spilt.Main[0].Atk_ratio/100;
    Total_dmg += Cal_Hp_multiplier(data_,target)*data_.Damage_spilt.Main[0].Hp_ratio/100;
    Total_dmg += Cal_Def_multiplier(data_,target)*data_.Damage_spilt.Main[0].Def_ratio/100;
    Total_dmg = Total_dmg*Cal_Bonus_dmg_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Dot_damage[target->Atv_stats->Unit_num] +=Total_dmg*Dot_ratio/100*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
}
void Cal_Dot_Toughness_break_damage(ActionData &data_,Enemy *target,double Dot_ratio){
    double Total_dmg = Level_multiplier*Dot_ratio/100;
        
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Break_damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
}
void Cal_Superbreak_damage(ActionData &data_,Enemy *target,double Superbreak_ratio){
    double Total_dmg = Level_multiplier*Superbreak_ratio/100;
    if(SuperBreak_Formula_check_mode&&SuperBreak_Formula_check_mode==data_.Attacker->Atv_stats->Unit_num){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" ";
        cout<<Superbreak_ratio<<" ";
        cout<<Cal_BreakEffect_multiplier(data_,target)<<" ";
        cout<<Cal_Superbreak_DamageIncrease_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<endl;
    }
    Total_dmg = Total_dmg*Cal_BreakEffect_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Superbreak_DamageIncrease_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Superbreak_damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
}
void Cal_Additional_damage(ActionData &data_,Enemy *target,Ratio_data Skill_mtpr){
    double Total_dmg = 0;
    if(Additional_Damage_Formula_check_mode&&data_.Attacker->Atv_stats->Unit_num==Additional_Damage_Formula_check_mode){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" :"<<endl;
        cout<<data_.Attacker->Base_atk<<" ";
        cout<<Cal_Atk_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Atk_ratio<<" ";
        cout<<data_.Attacker->Base_hp<<" ";
        cout<<Cal_Hp_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Hp_ratio<<" ";
        cout<<data_.Attacker->Base_def<<" ";
        cout<<Cal_Def_multiplier(data_,target)<<" * ";
        cout<<Skill_mtpr.Def_ratio<<" ";
        cout<<Cal_Bonus_dmg_multiplier(data_,target)<<" ";
        cout<<Cal_Crit_rate_multiplier(data_,target)<<" ";
        cout<<Cal_Crit_dam_multiplier(data_,target)<<" ";
        cout<<Cal_Def_shred_multiplier(data_,target)<<" ";
        cout<<Cal_Respen_multiplier(data_,target)<<" ";
        cout<<Cal_Vul_multiplier(data_,target)<<" ";
        cout<<Cal_Mitigation_multiplier(data_,target)<<" ";
        cout<<Cal_Toughness_multiplier(data_,target)<<" ";
        cout<<endl;
    }
    Total_dmg += Cal_Atk_multiplier(data_,target)*Skill_mtpr.Atk_ratio/100;
    Total_dmg += Cal_Hp_multiplier(data_,target)*Skill_mtpr.Hp_ratio/100;
    Total_dmg += Cal_Def_multiplier(data_,target)*Skill_mtpr.Def_ratio/100;
    Total_dmg = Total_dmg*Cal_Bonus_dmg_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Crit_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Def_shred_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Respen_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Vul_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Mitigation_multiplier(data_,target);
    Total_dmg = Total_dmg*Cal_Toughness_multiplier(data_,target);
    
    Ally_unit[data_.Attacker->Atv_stats->Unit_num]->Normal_Damage[target->Atv_stats->Unit_num] +=Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100;
    if(Additional_Damage_check_mode==data_.Attacker->Atv_stats->Unit_num){
        cout<<data_.Attacker->Atv_stats->Char_Name<<" "<<data_.Action_type.second<<" "<<(long long)Total_dmg*data_.Attacker->Stats_type["True_Damage"]["None"]/100<<" to Enemy"<<target->Atv_stats->Unit_num<<endl;
    }
}
double Cal_TotalPercentToughnessBrokenTime(Enemy *target,double Total_atv){
    double temp=0;
    if(target->Toughness_status==0){
        temp = (1*(target->Total_toughness_broken_time+(Total_atv - target->when_toughness_broken)) + 0.9*(Total_atv-(target->Total_toughness_broken_time+(Total_atv - target->when_toughness_broken))))/Total_atv; 
    }else{
        temp = (1*(target->Total_toughness_broken_time) + 0.9*(Total_atv-target->Total_toughness_broken_time))/Total_atv; 
    }
    return temp;
}
double Cal_Total_Toughness_Reduce(ActionData &data_,Enemy *target,double Base_Toughness_reduce){
    double ans = Base_Toughness_reduce;
    double Toughness_reduction_mtpr =100;
    double Weakness_Break_Efficiency_mtpr =100;
    Toughness_reduction_mtpr += data_.Attacker->Stats_type["Toughness_reduction"]["None"] + target->Stats_type["Toughness_reduction"]["None"];
    Weakness_Break_Efficiency_mtpr += data_.Attacker->Stats_type["Weakness_Break_Efficiency"]["None"] + target->Stats_type["Weakness_Break_Efficiency"]["None"];
    
    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Toughness_reduction_mtpr += data_.Attacker->Stats_type["Toughness_reduction"][data_.Skill_Type[i]] + target->Stats_type["Toughness_reduction"][data_.Skill_Type[i]];

        }
    for(int i=0,sz=data_.Skill_Type.size();i<sz;i++){
            Weakness_Break_Efficiency_mtpr += data_.Attacker->Stats_type["Weakness_Break_Efficiency"][data_.Skill_Type[i]] + target->Stats_type["Weakness_Break_Efficiency"][data_.Skill_Type[i]];

        }
     
    ans *= (Toughness_reduction_mtpr/100);
    ans *= ((Weakness_Break_Efficiency_mtpr)/100);
    return ans;
}
void Cal_ToughnessMultiplierAverage(){
    double temp[5] = {0,0,0,0,0};
    if(turn->turn_cnt<2)return;
    if(turn->Unit_num!=Main_dps_num)return;
    for(int i=1;i<=Total_enemy;i++){ 
        for(int j=1;j<=Total_ally;j++){
            temp[j]+=((Ally_unit[j]->Dot_damage[i]* Cal_TotalPercentToughnessBrokenTime(Enemy_unit[i].get(),Current_atv)+Ally_unit[j]->Normal_Damage[i] * Cal_TotalPercentToughnessBrokenTime(Enemy_unit[i].get(),Current_atv)+Ally_unit[j]->Superbreak_damage[i] +Ally_unit[j]->Break_damage[i]))/Current_atv;            
        }
    }

    for(int i=1;i<=Total_ally;i++){
        if(Current_atv<Ally_unit[i]->Last_note+20){
            Ally_unit[i]->Average_damage_instance[Ally_unit[i]->Average_damage_instance.size()-1] = temp[i];
        }else{
            Ally_unit[i]->Last_note = Current_atv;
            Ally_unit[i]->Average_damage_instance.push_back(temp[i]);
        }
       
        
    }
    //cout<<"Size = "<<Ally_unit[1]->Average_damage_instance.size()<<" "<<Ally_unit[1]->Average_damage_instance[Ally_unit[1]->Average_damage_instance.size()-1]<<endl;
}

#endif