#ifndef Setup_Enemy_H
#define Setup_Enemy_H
#include "../Print.h"
void Enemy_func(Unit *ptr){
    auto target = dynamic_cast<Enemy*>(ptr);
    if(target){
    if(target->Toughness_status==0){
        target->Toughness_status = 1;
        target->Current_toughness =  target->Max_toughness;
        target->Total_toughness_broken_time+=(Current_atv - target->when_toughness_broken);
    }
    }
    ++target->Debuff["Attack_cnt"];
    if(target->Debuff["Attack_cnt"]%3==2){

        
        if(target){
        allEventWhenEnemyHit(target->Energy_gen,target);
        }else{
            cout<<"error from Enemy_func";
            exit(0);
        }
    }
}
void Setup_enemy(int num,double speed,double energy,double Toughness,string type){
    if(num ==0){
        cout<<"setup enemy error";
        exit(0);
    }
    Enemy_unit[num] = make_unique<Enemy>();

        Enemy_unit[num]->Atv_stats->Base_speed = speed;
        Enemy_unit[num]->Energy_gen = energy;
        Enemy_unit[num]->Max_toughness = Toughness;
        Enemy_unit[num]->Target_type = type;
        if(type == "Main"){
            Main_Enemy_num = num;
        }

        Enemy_unit[num]->Turn_func = Enemy_func;



        for(auto &e:Enemy_weak){
                Enemy_unit[num]->Weakness_type[e.first] = e.second;
        }
        
        Enemy_unit[num]->Atv_stats->Unit_num = num;
        Enemy_unit[num]->Atv_stats->Char_Name = "Enemy_";
        Enemy_unit[num]->Atv_stats->Char_Name += type;
        Enemy_unit[num]->Atv_stats->Unit_Name = Enemy_unit[num]->Atv_stats->Char_Name;
        Enemy_unit[num]->Atv_stats->Side = "Enemy";
        Enemy_unit[num]->Atv_stats->ptr_to_unit = Enemy_unit[num].get();
}

#endif