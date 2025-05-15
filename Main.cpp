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
Ally* Char1;
Ally* Char2;
Ally* Char3;
Ally* Char4; 
void SetValue(){
    Driver_num = 2;
    Driver_Type = "None"; //Swap_pull Always_pull Double_turn None
    Sp_status ="Positive"; //Positive Negative       
    //set unit
    
    Wave[0] = 3000;
    Wave[0]+=0.01;
    Print_Atv = 1;
    Formula_check_mode = 0;
    SuperBreak_Formula_check_mode = 0;
    Break_Formula_check_mode = 0;
    
    Normal_Damage_Formula_check_mode = 4;
    Normal_Damage_check_mode = 0;
    Additional_Damage_Formula_check_mode = 0;
    Additional_Damage_check_mode = 0;
    // golden ratio
    rerollSubstatsMode = "Standard" ; //Standard AllCombination AllPossible

}
void SetCharacterPtr(){
    Char1 = Ally_unit[1].get();
    Char2 = Ally_unit[2].get();
    Char3 = Ally_unit[3].get();
    Char4 = Ally_unit[4].get();
}

int main(){

    SetValue();
    // The_Herta::Setup(2,Erudition_Lightcone::The_Herta_LC(1),Relic::Scholar,Planar::Izumo);
    // Aglaea::Setup(0,Remembrance_Lightcone::SweatNowCryLess(5),Relic::Hero_Wreath,Planar::The_Wondrous_BananAmusement_Park);
    // Jingyuan::Setup_Jingyuan(0,Erudition_Lightcone::Before_Dawn(1),Relic::Grand_Duke,Planar::The_Wondrous_BananAmusement_Park);
    Castorice::Setup(0,Remembrance_Lightcone::Castorice_LC(1),Relic::Poet_Dill,Planar::Bone_Collection);
    // Mydei::Setup(2,Destruction_Lightcone::Mydei_LC(1),Relic::Scholar,Planar::Bone_Collection);
    // Anaxa::Setup(2,Erudition_Lightcone::Anaxa_LC(1),Relic::GeniusBrilliant,Planar::SpaceSealing);
    
    //Driver
    // Sunday::Setup(0,Harmony_Lightcone::Bronya_LC(1),Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);
    // Bronya::Setup(0,Harmony_Lightcone::Bronya_LC(1),Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);
    
    //Sub dps
    // Serval:Setup(6,Erudition_Lightcone::Passkey(5),Relic::Eagle_Beaked_Helmet,Planar::Lushaka);
    // Jade::Setup(0,Erudition_Lightcone::Cosmos_Fell(5),Relic::Grand_Duke,Planar::Izumo);
    
    //Support
    Tribbie::Setup(0,Harmony_Lightcone::DDD(5),Relic::Poet_Dill,Planar::Broken_Keel);
    RMC::Setup(6,Remembrance_Lightcone::Victory_In_Blink(5),Relic::PairSet(ST_SPD_P,ST_SPD_P),Planar::Broken_Keel);
    // Robin::Setup(0,Harmony_Lightcone::For_Tomorrow_Journey(5),Relic::PairSet(ST_ATK_P,ST_ATK_P),Planar::Lushaka);
    // Ruan_Mei::Setup(1,Harmony_Lightcone::Memories_of_the_Past(5),Relic::PairSet(ST_BE,ST_BE),Planar::Broken_Keel);
    // Tingyun::Setup(6,Harmony_Lightcone::DDD(5),Relic::Sacerdos_Relived_Ordeal,Planar::Broken_Keel);
    
    //Debuffer
    // Pela::Setup(6,Nihility_Lightcone::Before_the_Tutorial(5),Relic::Eagle_Beaked_Helmet,Planar::Broken_Keel);


    //Sustain
    // Gallagher::Setup(6,Abundance_Lightcone::Multiplication(5),Relic::PairSet(ST_HEALING_OUT,ST_BE),Planar::Broken_Keel);
    // Luocha::Setup(0,Abundance_Lightcone::Multiplication(5),Relic::PairSet(ST_HEALING_OUT,ST_ATK_P),Planar::Broken_Keel);
    Hyacine::Setup(0,Remembrance_Lightcone::RemembranceHertaShop(5),Relic::Goddess_of_Sun_and_Thunder,Planar::GiantTree(1));

    SetCharacterPtr();
    
    //--------------------- adjust ------------------------
    
    Char4->enableCheckHealFormula();
    
    



    //--------------------- Set_Technique ------------------------


    // CharCmd::Set_Technique(Ally_unit[2].get(),0);
    // CharCmd::Set_Technique(Ally_unit[4].get(),0);



    //-----------------------------------------------------------

    CharCmd::Set_Reroll_check(Ally_unit[1].get(),0);
    CharCmd::Set_Reroll_check(Ally_unit[2].get(),0);
    CharCmd::Set_Reroll_check(Ally_unit[3].get(),0);
    CharCmd::Set_Reroll_check(Ally_unit[4].get(),0);


    CharCmd::Timing_print(Ally_unit[1].get());
    CharCmd::Timing_print(Ally_unit[2].get());
    CharCmd::Timing_print(Ally_unit[3].get());
    CharCmd::Timing_print(Ally_unit[4].get());



    EnemyCmd::setEnemyWeakness(0,1,0,1,0,1,0);
    SetupEnemy(158,160,{10,30},{200,300},{2,3},"Main");
    SetupEnemy(158,10,{10,20},{200,300},{2,3},"Adjacent");  
    // SetupEnemy(158,0,{0,0},{200,200},{2,3},"Adjacent");
    // SetupEnemy(130,0,{0,0},{0,0},{2,0},"Other");
    // SetupEnemy(130,0,{0,0},{0,0},{2,0},"Other");
    

    
    
    // SetupEnemy(4,130,0,90,0.0,0,"Other");
    // SetupEnemy(5,120,0,90,0.0,0,"Other");

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
