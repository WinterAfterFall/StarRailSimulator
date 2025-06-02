
// #ifndef Hanabi_H
// #define Hanabi_H

// #define endl '\n'
// #define F first
// #define S second
// #include"..\..\Setup.cpp"

// namespace Hanabi{
//     void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//     void Reset(Ally *ptr);
//     void When_Combat(Ally *ptr);
//     void Turn_func(Unit *ptr);
//     void Ult_func(Ally *ptr);//*
//     void Before_turn(Ally *ptr);
//     void After_turn(Ally *ptr);
//     void Before_attack(Ally *ptr, Combat_data &act);
//     void After_attack(Ally *ptr, Combat_data &act);
//     void Start_game(Ally *ptr);
//     void Buff_func(Ally *ptr, Combat_data &act);
    
//     void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
//         Ally_unit[num] = make_unique<Ally>();

//         Ally_unit[num]->stats->baseHp = 1397;
//         Ally_unit[num]->stats->baseAtk = 524;
//         Ally_unit[num]->stats->Base_def = 485;
//         Ally_unit[num]->Atv_stats->Base_speed = 101;
//         Ally_unit[num]->stats->Max_energy = 110;
//         Ally_unit[num]->stats->Ult_cost = 110;
//         Ally_unit[num]->stats->Eidolon = E;
//         Ally_unit[num]->stats->Element_type.push_back("Quantum");
//         Ally_unit[num]->stats->Path.push_back("Harmony");
//         Ally_unit[num]->Atv_stats->Character_num = num;
//         Ally_unit[num]->Atv_stats->Name = "Hanabi";
//         Ally_unit[num]->Atv_stats->Side = "Ally";
//         Ally_unit[num]->Atv_stats->ptrToChar = Ally_unit[num].get();
//         unit[num] = Ally_unit[num]->Atv_stats->ptrToChar;
//         Ally_unit[num]->stats->Ult_priority +=3;
//         Max_sp+=2;

//         //func
//         LC(Ally_unit[num].get());
//         Relic(Ally_unit[num].get());
//         Planar(Ally_unit[num].get());
        
//         Ally_unit[num]->Turn_func = Turn_func;
//         Ally_unit[num]->stats->Ult_func = Ult_func;
//         Ally_unit[num]->stats->Char_func.Reset_func = Reset;
//         Ally_unit[num]->stats->Char_func.Before_turn_func = Before_turn;
//         Ally_unit[num]->stats->Char_func.After_turn_func = After_turn;
//         Ally_unit[num]->stats->Char_func.Start_game_func = Start_game;


//     }
//     void Reset(Ally *ptr){
//         ptr->Hp_percent[AT_NONE]+=28;
//         ptr->Crit_dam[AT_NONE]+=24;


//         //relic
//         ptr->Crit_dam[AT_NONE]+=64.8;
//         ptr->Atv_stats->Flat_speed+=25;
//         ptr->Hp_percent[AT_NONE]+=43.2;
//         ptr->stats->Energy_recharge+=19.4;
        
//         //substats
//         ptr->Atv_stats->Flat_speed+=25.3;
//         ptr->Crit_dam[AT_NONE]+=52.2;
        
//     }
//     void When_Combat(Ally *ptr){
//         int temp = 0;
//         for(int i=1;i<=Total_ally;i++){
//         Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"] = 6;
//         Ally_unit[i]->Atk_percent[AT_NONE]+=15;
//         for(int k=0;k<Ally_unit[i]->stats->Memosprite_ptr.size();k++){
        
//         }
        
//         for(int j=0;j<Ally_unit[i]->stats->Element_type.size();j++){
//             if(Ally_unit[i]->stats->Element_type[j]=="Quantum"){
//             ++temp;
//             break;
//             }
//         }
            
        
//         }
//         for(int i=1;i<=Total_ally;i++){
//         for(int j=0;j<Ally_unit[i]->stats->Element_type.size();j++){
//         if(Ally_unit[i]->stats->Element_type[j]=="Quantum"){
//             if(temp>=3){
//                 Ally_unit[i]->Atk_percent[AT_NONE]+=30;
//             }else if(temp==2){
//                 Ally_unit[i]->Atk_percent[AT_NONE]+=15;
//             }else if(temp==1){
//                 Ally_unit[i]->Atk_percent[AT_NONE]+=5;
//             }
//             for(int k=0;k<Ally_unit[i]->stats->Memosprite_ptr.size();k++){
//             if(temp>=3){
//                 Ally_unit[i]->stats->Memosprite_ptr[k]->Atk_percent[AT_NONE]+=30;
//             }else if(temp==2){
//                 Ally_unit[i]->stats->Memosprite_ptr[k]->Atk_percent[AT_NONE]+=15;
//             }else if(temp==1){
//                 Ally_unit[i]->stats->Memosprite_ptr[k]->Atk_percent[AT_NONE]+=5;
//             }
//             }
//             break;
//         }

//         }
//         }
//     }
//     void Turn_func(Unit *ptr){
//         Combat_data act;
//             Skill_point(-1);
//             act.num = ptr->Atv_stats->Character_num;
//             act.Turn_reset = 1;

//             act.Action_type.first="Buff";
//             act.Action_type.second = "Skill";

//             act.Buff_type.push_back("Buff");

//             act.Target_type="Single_target";
//             Action_bar.push(act);
//             auto ally_ptr = dynamic_cast<Ally*>(ptr);
//             Increase_energy(ally_ptr->stats.get(),30);
//             Action_forward(Ally_unit[Main_dps_num]->Atv_stats.get(),50);
//             ally_ptr->stats->Buff_note["Dreamdiver"] = ptr->Crit_dam[AT_NONE]*0.24+45;
//             if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"]<=Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]+=ally_ptr->stats->Buff_note["Dreamdiver"];
//             }
//             Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"] = Ally_unit[Main_dps_num]->Atv_stats->turn_cnt+2;
            
//             return;
//     }
//     void Ult_func(Ally *ptr){
//         if(turn->Character_num!=Main_dps_num||turn->Side!="Ally"||Ult_After_Turn==1)return;

//         if(!Ult_use_check(ptr))return;
//         Combat_data act;
//         act.num = ptr->Atv_stats->Character_num;

//         act.Action_type.first="Buff";
//         act.Action_type.second = "Ultimate";

//         act.Buff_type.push_back("Buff");

//         act.Target_type="Aoe";
//         Action_bar.push(act);
//         Skill_point(4);

//         for(int i=1;i<=Total_ally;i++){
//             if(Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"]==6){
//                 Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"]=16;
//                 if(ptr->stats->Eidolon>=1){
//                     Ally_unit[i]->Atk_percent[AT_NONE]+=40;
//                 }
//             }
            
//             if(ptr->stats->Eidolon>=1){
//                 Ally_unit[i]->stats->Buff_countdown["Thousand_Faces"]=Ally_unit[i]->Atv_stats->turn_cnt+3;
//             }else{
//                 Ally_unit[i]->stats->Buff_countdown["Thousand_Faces"]=Ally_unit[i]->Atv_stats->turn_cnt+2;
//             }
            
        
//         Ally_unit[i]->Dmg_bonus[AT_NONE] -= Ally_unit[i]->stats->Buff_note["Red_Herring"];
//         Ally_unit[i]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*16;
//         Ally_unit[i]->Dmg_bonus[AT_NONE] += Ally_unit[i]->stats->Buff_note["Red_Herring"];
//         }
//         Deal_damage();
//     }
//     void Before_turn(Ally *ptr){
//         if(ptr->stats->Buff_note["Last_sp"]>sp){
//             if(ptr->stats->Stack["Red_Herring"]<3){
//                 ++ptr->stats->Stack["Red_Herring"];
//                 if(ptr->stats->Eidolon>=2){
//                 for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Def_shred[AT_NONE]+=8;
//                 }
//                 }
//             }
//             for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] -= Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"];
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] += Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_countdown["Red_Herring"] = Ally_unit[i]->Atv_stats->turn_cnt+2;
//             }
//         }
//         ptr->stats->Buff_note["Last_sp"] = sp;
//         if(turn->Character_num==Main_dps_num&&turn->Side=="Ally"){
//             if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"] == Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//                 Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]-=ptr->stats->Buff_note["Dreamdiver"];
//             }
//         }
//         if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"]>Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]-=ptr->stats->Buff_note["Dreamdiver"];
//             ptr->stats->Buff_note["Dreamdiver"] = ptr->Crit_dam[AT_NONE]*0.24+45;
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]+=ptr->stats->Buff_note["Dreamdiver"];
//         }
//     }
//     void After_turn(Ally *ptr){
//         if(turn->Side!="Ally")return;
//         if(Ally_unit[turn->Character_num]->stats->Buff_countdown["Thousand_Faces"]==Ally_unit[turn->Character_num]->Atv_stats->turn_cnt){
//             Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring_per_stack"] = 6;
//             if(ptr->stats->Eidolon>=1){
//                     Ally_unit[turn->Character_num]->Atk_percent[AT_NONE]+=40;
//                 }
//             Ally_unit[turn->Character_num]->Dmg_bonus[AT_NONE] -= Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring"];
//             Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring_per_stack"];
//             Ally_unit[turn->Character_num]->Dmg_bonus[AT_NONE] += Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring"];
//         }
//         if( Ally_unit[turn->Character_num]->stats->Buff_countdown["Red_Herring"] == Ally_unit[turn->Character_num]->Atv_stats->turn_cnt){
//             Ally_unit[turn->Character_num]->Dmg_bonus[AT_NONE] -= Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring"];
//             Ally_unit[turn->Character_num]->stats->Buff_note["Red_Herring"] =0;
//         }
//     }
//     void Before_attack(Ally *ptr, Combat_data &act){
//         if(ptr->stats->Buff_note["Last_sp"]>sp){
//             if(ptr->stats->Stack["Red_Herring"]<3){
//                 ++ptr->stats->Stack["Red_Herring"];
//                 if(ptr->stats->Eidolon>=2){
//                 for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Def_shred[AT_NONE]+=8;
//                 }
//                 }
//             }
//             for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] -= Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"];
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] += Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_countdown["Red_Herring"] = Ally_unit[i]->Atv_stats->turn_cnt+2;
//             }
//         }
//         ptr->stats->Buff_note["Last_sp"] = sp;
//         if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"]>Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]-=ptr->stats->Buff_note["Dreamdiver"];
//             ptr->stats->Buff_note["Dreamdiver"] = ptr->Crit_dam[AT_NONE]*0.24+45;
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]+=ptr->stats->Buff_note["Dreamdiver"];
//         }
//     }
//     void After_attack(Ally *ptr, Combat_data &act){
//         if(ptr->stats->Buff_note["Last_sp"]>sp){
//             if(ptr->stats->Stack["Red_Herring"]<3){
//                 ++ptr->stats->Stack["Red_Herring"];
//                 if(ptr->stats->Eidolon>=2){
//                 for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Def_shred[AT_NONE]+=8;
//                 }
//                 }
//             }
//             for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] -= Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"];
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] += Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_countdown["Red_Herring"] = Ally_unit[i]->Atv_stats->turn_cnt+2;
//             }
//         }
//         ptr->stats->Buff_note["Last_sp"] = sp;
//         if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"]>Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]-=ptr->stats->Buff_note["Dreamdiver"];
//             ptr->stats->Buff_note["Dreamdiver"] = ptr->Crit_dam[AT_NONE]*0.24+45;
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]+=ptr->stats->Buff_note["Dreamdiver"];
//         }
//     }
//     void Buff_func(Ally *ptr, Combat_data &act){
//         if(ptr->stats->Buff_note["Last_sp"]>sp){
//             if(ptr->stats->Stack["Red_Herring"]<3){
//                 ++ptr->stats->Stack["Red_Herring"];
//                 if(ptr->stats->Eidolon>=2){
//                 for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Def_shred[AT_NONE]+=8;
//                 }
//                 }
//             }
//             for(int i=1;i<=Total_ally;i++){
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] -= Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_note["Red_Herring"] = ptr->stats->Stack["Red_Herring"]*Ally_unit[i]->stats->Buff_note["Red_Herring_per_stack"];
//                 Ally_unit[i]->Dmg_bonus[AT_NONE] += Ally_unit[i]->stats->Buff_note["Red_Herring"];
//                 Ally_unit[i]->stats->Buff_countdown["Red_Herring"] = Ally_unit[i]->Atv_stats->turn_cnt+2;
//             }
//         }
//         ptr->stats->Buff_note["Last_sp"] = sp;
//         if(Ally_unit[Main_dps_num]->stats->Buff_countdown["Dreamdiver"]>Ally_unit[Main_dps_num]->Atv_stats->turn_cnt){
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]-=ptr->stats->Buff_note["Dreamdiver"];
//             ptr->stats->Buff_note["Dreamdiver"] = ptr->Crit_dam[AT_NONE]*0.24+45;
//             Ally_unit[Main_dps_num]->Crit_dam[AT_NONE]+=ptr->stats->Buff_note["Dreamdiver"];
//         }
//     }
//     void Start_game(Ally *ptr){
//         if(ptr->stats->Technique==1){
//         Skill_point(3);
//         ptr->stats->Buff_note["Last_sp"] = sp;
//         }
//     }
    

    

    
// }
// #endif
