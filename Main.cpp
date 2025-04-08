#include<bits/stdc++.h>


#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
using std::cout ;
using std::vector;

#include"Library.h"

#include "./Data/Character/All_Character.h"
#include "./Data/Lightcone/All_Lighcone.h"
#include "./Data/Planar/All_Planar.h"
#include"./Data/Relic/All_Relic.h"
void SetValue(){
    Driver_num = 2;
    Driver_Type = "None"; //Swap_pull Always_pull Double_turn None
    Sp_status ="Positive"; //Positive Negative       
    //set unit
    Total_enemy =3;
    
    Wave[0] = 700;
    Wave[0]+=0.01;
    Print_Atv = 1;
    Formula_check_mode = 0;
    SuperBreak_Formula_check_mode = 0;  
    Break_Formula_check_mode = 0;
    
    Normal_Damage_Formula_check_mode = 0;
    Normal_Damage_check_mode = 0;
    Additional_Damage_Formula_check_mode = 0;
    Additional_Damage_check_mode = 0;
    // golden ratio
    rerollSubstatsMode = "Standard" ; //Standard AllCombination AllPossible

    Enemy_unit.resize(Total_enemy+1);
}
int main(){
    
    SetValue();
    //The_Herta::Setup(1,0,Erudition_Lightcone::The_Herta_LC,Relic::Scholar,Planar::Izumo);
    // Aglaea::Setup(1,0,Remembrance_Lightcone::SweatNowCryLess,Relic::Hero_Wreath,Planar::The_Wondrous_BananAmusement_Park);
    // Jingyuan::Setup_Jingyuan(1,2,Erudition_Lightcone::Before_Dawn,Relic::Grand_Duke,Planar::The_Wondrous_BananAmusement_Park);
    // Mydei::Setup(2,0,Destruction_Lightcone::Ninja_Record,Relic::Scholar,Planar::Bone_Collection);
    Castorice::Setup(1,2,Remembrance_Lightcone::Aglaea_LC(1),Relic::Poet_Dill,Planar::Bone_Collection);

    //Driver
    // Bronya::Setup(2,0,Harmony_Lightcone::But_the_Battle_Isnt_Over,Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);
    // Sunday::Setup(2,0,Harmony_Lightcone::But_the_Battle_Isnt_Over,Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);

    //Sub dps
    // Jade::Setup(2,0,Erudition_Lightcone::Cosmos_Fell,Relic::Grand_Duke,Planar::Izumo);
    //Serval::Setup(2,6,Harmony_Lightcone::Meshing_Cogs,Relic::Double_Speed,Planar::Lushaka);
    
    //Support
    Tribbie::Setup(3,0,Harmony_Lightcone::DDD(5),Relic::Poet_Dill,Planar::Broken_Keel);
    RMC::Setup(2,6,Remembrance_Lightcone::Victory_In_Blink,Relic::Double_Speed,Planar::Broken_Keel);
    // Robin::Setup(2,0,Harmony_Lightcone::For_Tomorrow_Journey,Relic::Double_Atk,Planar::Broken_Keel);
    // Ruan_Mei::Setup(2,0,Harmony_Lightcone::Memories_of_the_Past,Relic::Iron_Cavalry,Planar::Broken_Keel);
    //Tingyun::Setup(3,6,Harmony_Lightcone::DDD,Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);
    
    //Debuffer
    // Pela::Setup(3,6,Nihility_Lightcone::Before_the_Tutorial,Relic::Double_Speed,Planar::Broken_Keel);


    //Sustain
    Gallagher::Setup(4,6,Abundance_Lightcone::Multiplication(5),Relic::Iron_Cavalry,Planar::Broken_Keel);
    // Luocha::Setup(4,0,Abundance_Lightcone::Multiplication,Relic::Double_Atk,Planar::Broken_Keel);


    //adjust
    Ally_unit[1]->setAdjust("NetherwingLifeSpan",3);
    // Castorice::DriverCondition(Ally_unit[2].get(),Ally_unit[1].get());


    // Char_Command::Set_Reroll_check(Ally_unit[1].get(),0);
    // Char_Command::Set_Reroll_check(Ally_unit[2].get(),0);
    // Char_Command::Set_Reroll_check(Ally_unit[3].get(),0);
    // Char_Command::Set_Reroll_check(Ally_unit[4].get(),0);


    CharCmd::Timing_print(Ally_unit[1].get());
    CharCmd::Timing_print(Ally_unit[2].get());
    CharCmd::Timing_print(Ally_unit[3].get());
    CharCmd::Timing_print(Ally_unit[4].get());


    CharCmd::Set_Technique(Ally_unit[4].get(),0);


    Setup_enemy(1,158,15,160,300.0,3,"Main");
    Setup_enemy(2,158,10,160,300.0,3,"Adjacent");
    Setup_enemy(3,158,0,160,200.0,0,"Adjacent");
    
    //Setup_enemy(1,600,0,30,"Main");
    //Setup_enemy(2,600,0,30,"Adjacent");
    // Setup_enemy(3,130,0,90,"Adjacent");
    

    
    
    // Setup_enemy(4,130,0,90,0.0,0,"Other");
    // Setup_enemy(5,120,0,90,0.0,0,"Other");

    Setup();
    
    
    while(1){
        cout<<" ---------------------------------------------------------- ";
        cout<<endl;
        bool skip = 0;
        Reset();
        for(int i=1;i<=Total_ally;i++){
            Set_Stats(Ally_unit[i].get());
        }
        
        Start_game();cout<<endl;
        
    for(int i=0;i<Total_wave;i++){
        
        Current_atv=0;
        Start_wave(i);
        while(1){
            Turn_Skip=0;
            Find_turn();
            Atv_fix(turn->atv);
            
            if(Current_atv>Wave[i]){
                EndWave(Wave[i]);
                break;
            }
            
            Take_action();
            
        }
    }
    
    Cal_DamageSummary();
    printRoundResult();
    if(Reroll_substats())break;
    }
    printSummaryResult();
    // if(Calculate_All_Substats_mode){
    //     Calculate_All_Substats();
    //     Print_All_Substats();
    // }
    
    
    return 0;
}
