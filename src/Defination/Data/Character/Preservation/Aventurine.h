
// #ifndef Aventurine_H
// #define Aventurine_H

// #define endl '\n'
// #define F first
// #define S second
// #include"..\..\Setup.cpp"

// namespace Aventurine{
//     void Set_up(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//     void Reset(Ally *ptr);
//     void turnFunc(Unit *ptr);
//     void Ult_func(Ally *ptr);//*
//     void After_turn(Ally *ptr);
//     void Before_attack(Ally *ptr, Combat_data &act);
//     void Enemy_hit_func(Ally *ptr, Enemy *target);

//     void Set_up(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
//         Ally_unit[num] = make_unique<Ally>();

//         Ally_unit[num]->stats->baseHp = 1203;
//         Ally_unit[num]->stats->baseAtk = 446;
//         Ally_unit[num]->stats->Base_def = 655;
//         Ally_unit[num]->atvStats->Base_speed = 106;
//         Ally_unit[num]->stats->maxEnergy = 110;
//         Ally_unit[num]->stats->ultCost = 110;
//         Ally_unit[num]->stats->Eidolon = E;
//         Ally_unit[num]->stats->elementType = ElementType::IMAGINARY;
//         Ally_unit[num]->stats->Path = Path::PRESERVATION;
//         Ally_unit[num]->atvStats->Character_num = num;
//         Ally_unit[num]->atvStats->Name = "Aventurine";
//         Ally_unit[num]->atvStats->Side = Side::ALLY;
//         Ally_unit[num]->atvStats->owner = Ally_unit[num].get();
//         unit[num] = Ally_unit[num]->atvStats->owner;
//         Ally_unit[num]->stats->Ult_priority +=0;

//         //func
//         LC(Ally_unit[num].get());
//         Relic(Ally_unit[num].get());
//         Planar(Ally_unit[num].get());
        
//         Ally_unit[num]->turnFunc = turnFunc;
//         Ally_unit[num]->stats->Ult_func = Ult_func;
//         Ally_unit[num]->stats->Char_func.Reset_func = Reset;
//         Ally_unit[num]->stats->Char_func.After_turn_func = After_turn;
//         Ally_unit[num]->stats->Char_func.Before_attack_func = Before_attack;
//         Ally_unit[num]->stats->Char_func.Enemy_hit_func = Enemy_hit_func;
        
//     }
//     void Reset(Ally *ptr){
//         ptr->Dmg_bonus_each_element[ElementType::IMAGINARY][AType::NONE]+=14.4;
//         ptr->Def_percent[AType::NONE]+=35;

//         //relic
//         ptr->Def_percent[AType::NONE]+=54;
//         ptr->atvStats->Flat_speed+=25;
//         ptr->Def_percent[AType::NONE]+=54;
//         if(ptr->stats->Eidolon==0){
//             ptr->Def_percent[AType::NONE]+=54;
//         }else{
//             ptr->stats->energyRecharge+=19.4;
//         }
        

//         //substats
//         ptr->Def_percent[AType::NONE]+=68.04; //14
//         ptr->atvStats->Flat_speed+=13.8; //6
//         if(ptr->stats->Eidolon>=1){
//         for(int i=1;i<=totalAlly;i++){
//             Ally_unit[i]->Crit_dam[AType::NONE]+=20;
//         }
//         }


//     }
//     void turnFunc(Unit *ptr){
//         Combat_data temp;
//         if(ptr->atvStats->turnCnt<=4||ptr->atvStats->turnCnt%3!=2||Ally_unit[ptr->atvStats->Character_num]->stats->Eidolon>=1){
//             Skill_point(1);
//             temp.num = ptr->atvStats->Character_num;
//             temp.turnReset = 1;

//             temp.Action_type.first = "Attack";
//             temp.Action_type.second = AType::BA;

//             temp.damageElement = ElementType::IMAGINARY;
//             temp.Damage_type.push_back(AType::BA);

//             temp.targetType = "Single_target";
//             temp.Damage_spilt.Main.push_back({0,0,100,10});
            
//             increaseEnergy(Ally_unit[ptr->atvStats->Character_num]->stats.get(),20);
//             if(Ally_unit[ptr->atvStats->Character_num]->stats->Eidolon>=2){
//                 ++Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"];
//                 if(Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]>totalEnemy||Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]>3){
//                     Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]=1;
//                 }
//                 if(Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->stats->Debuff["Bounded_Rationality"]==0){
//                     Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->Respen[AType::NONE]+=12;
//                     Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->stats->Debuff["Bounded_Rationality"]=1;
//                     ++Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->stats->totalDebuff;
//                 }
//                 Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->stats->Debuff_time_count["Bounded_Rationality"]=Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]]->atvStats->turnCnt+3;
//                 Apply_debuff(Ally_unit[ptr->atvStats->Character_num].get(),Enemy_unit[Ally_unit[ptr->atvStats->Character_num]->stats->Buff_note["Basic_Attack_Target_Choose"]].get());
               

//             }
//         }else{
//             Skill_point(-1);
//             temp.num = ptr->atvStats->Character_num;
//             temp.turnReset = 1;

//             temp.Action_type.first = "Buff";
//             temp.Action_type.second = AType::SKILL;

//             temp.Buff_type.push_back("Shield");

//             temp.targetType = "Aoe";
//             increaseEnergy(Ally_unit[ptr->atvStats->Character_num]->stats.get(),30);
//         }
//         actionBar.push(temp);
//         if(ptr->atvStats->turnCnt%3==2){
//             Combat_data temp2;
//             temp2.num = ptr->atvStats->Character_num;

//             temp2.Action_type.first = "Attack";
//             temp2.Action_type.second = AType::FUA;

//             temp2.damageElement = ElementType::IMAGINARY;
//             temp2.Damage_type.push_back(AType::FUA);
//             temp2.Buff_type.push_back("Shield");

//             temp2.targetType = "Bounce";
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             actionBar.push(temp2);
//         }
        
//     }
//     void Ult_func(Ally *ptr){
//         if(Ult_use_check(ptr)){
            
//             Combat_data temp;
//             temp.num = ptr->atvStats->Character_num;

//             temp.Action_type.first = "Attack";
//             temp.Action_type.second = AType::ULT;

//             temp.damageElement = ElementType::IMAGINARY;
//             temp.Damage_type.push_back(AType::ULT);

//             temp.targetType = "Single_target";
//             temp.Damage_spilt.Main.push_back({0,0,270,10});
//             actionBar.push(temp);
//             ptr->stats->Stack["Shot_Loaded_Right"]+=4;
//             if(ptr->stats->Eidolon>=1){
//                 Combat_data temp3;
//                 temp3.num = ptr->atvStats->Character_num;

//                 temp3.Action_type.first = "Buff";
//                 temp3.Action_type.second = AType::ULT;

//                 temp3.Buff_type.push_back("Shield");

//                 temp3.targetType = "Aoe";
//                 actionBar.push(temp3);
//             }
//             if(ptr->stats->Stack["Shot_Loaded_Right"]>=7){
//                 ptr->stats->Stack["Shot_Loaded_Right"]-=7;
//                 Combat_data temp2;
//             temp2.num = ptr->atvStats->Character_num;

//             temp2.Action_type.first = "Attack";
//             temp2.Action_type.second = AType::FUA;

//             temp2.damageElement = ElementType::IMAGINARY;
//             temp2.Damage_type.push_back(AType::FUA);
//             temp2.Buff_type.push_back("Shield");
            
//             temp2.targetType = "Bounce";
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             actionBar.push(temp2);
//             }
//             Apply_debuff(ptr,Enemy_unit[mainEnemyNum].get());
//             if(Enemy_unit[mainEnemyNum]->stats->Debuff["Roulette_Shark"]==0){
//                 Enemy_unit[mainEnemyNum]->Crit_dam[AType::NONE]+=15;
//                 Enemy_unit[mainEnemyNum]->stats->Debuff["Roulette_Shark"]=1;
//                 ++Enemy_unit[mainEnemyNum]->stats->totalDebuff;
//             }
//             Enemy_unit[mainEnemyNum]->stats->Debuff_time_count["Roulette_Shark"]= 3 + Enemy_unit[mainEnemyNum]->atvStats->turnCnt;
//             dealDamage();
//         }
//     }
//     void After_turn(Ally *ptr){
//         if(turn->Name=="Enemy_Main"&&Enemy_unit[turn->Character_num]->stats->Debuff_time_count["Roulette_Shark"]==turn->turnCnt){
//             Enemy_unit[mainEnemyNum]->Crit_dam[AType::NONE]-=15;
//                 Enemy_unit[mainEnemyNum]->stats->Debuff["Roulette_Shark"]=0;
//             --Enemy_unit[mainEnemyNum]->stats->totalDebuff;
//         }
//         if(turn->Side==Side::ENEMY&&Enemy_unit[turn->Character_num]->stats->Debuff_time_count["Bounded_Rationality"]==turn->turnCnt&&Enemy_unit[turn->Character_num]->stats->Debuff["Bounded_Rationality"]==1){
//             Enemy_unit[turn->Character_num]->Respen[AType::NONE]-=12;
//             Enemy_unit[turn->Character_num]->stats->Debuff["Bounded_Rationality"]=0;
//             --Enemy_unit[turn->Character_num]->stats->totalDebuff;
//         }
//     }
//     void Before_attack(Ally *ptr, Combat_data &act){
//         if(Ally_unit[act.num]->atvStats->Name=="Aventurine"){
//             ptr->Crit_rate[AType::NONE]-=ptr->stats->Buff_note["Leverage"];
//             if(((ptr->Def_percent[AType::NONE]*ptr->stats->Base_def)+ptr->Def_flat[AType::NONE])>=1600);
//             ptr->stats->Buff_note["Leverage"] = floor(((ptr->Def_percent[AType::NONE]*ptr->stats->Base_def)+ptr->Def_flat[AType::NONE]-1600)/100)*2;
//             if(ptr->stats->Buff_note["Leverage"]>=48){
//                 ptr->stats->Buff_note["Leverage"] = 48;
//             }
//             ptr->Crit_rate[AType::NONE]+=ptr->stats->Buff_note["Leverage"];

//         }
//     }
//     void Enemy_hit_func(Ally *ptr, Enemy *target){
//         ptr->stats->Stack["Shot_Loaded_Right"]+=5;
//         if(ptr->stats->Stack["Shot_Loaded_Right"]>=7){
//                 ptr->stats->Stack["Shot_Loaded_Right"]-=7;
//                 Combat_data temp2;
//             temp2.num = ptr->atvStats->Character_num;

//             temp2.Action_type.first = "Attack";
//             temp2.Action_type.second = AType::FUA;

//             temp2.damageElement = ElementType::IMAGINARY;
//             temp2.Damage_type.push_back(AType::FUA);
//             temp2.Buff_type.push_back("Shield");
            
//             temp2.targetType = "Bounce";
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Main.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             temp2.Damage_spilt.Adjacent.push_back({0,0,25,1.0/3.0});
//             actionBar.push(temp2);
//             dealDamage();
//             }
//     }
// }
// #endif
