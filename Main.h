#include "src/Library.h"

CharUnit* Char1;
CharUnit* Char2;
CharUnit* Char3;
CharUnit* Char4; 
void SetValue(){
    driverType = DriverType::None;
    spMode = SPMode::Negative;      
    //set unit
    
    Wave[0] = 800;
    Wave[0]+=0.01;
    Print_Atv = 1;
    bestBounce = 1;
    // golden ratio 
    rerollSubstatsMode = SubstatsRerollMode::Standard;

}
void SetCharacterPtr(){
    Char1 = charUnit[1].get();      
    Char2 = charUnit[2].get();
    Char3 = charUnit[3].get();
    Char4 = charUnit[4].get(); 
}
void Main(){
    Setup();
    
    while(1){
        cout<<" ---------------------------------------------------------- ";
        cout<<endl;
        bool skip = 0;
        Reset();
        for(int i=1;i<=Total_ally;i++){
            Set_Stats(charUnit[i].get());
        }
        Start_game();cout<<endl;
        
        for(int i=0;i<Total_wave;i++){
            
            Current_atv=0;
            Start_wave(i);  
            Deal_damage();
            

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
    std::cout << "Press Enter to end program..." <<endl;
    std::cin.get();
    return ;
}
int main(){ 
    
    // Char1->enableCheckDamage();
    Char1->enableCheckDamageFormula(DmgFormulaMode::All); 
    // Char4->enableCheckHealFormula();
    // Char4->enableCheckHeal();

    Char1->enableCheckHealReceive();
    Char2->enableCheckHealReceive();
    Char3->enableCheckHealReceive();
    Char4->enableCheckHealReceive();
    Char1->enableCheckHealReceiveFormula();
    Char2->enableCheckHealReceiveFormula();
    Char3->enableCheckHealReceiveFormula();
    Char4->enableCheckHealReceiveFormula();
    
    //--------------------- Set_Technique ------------------------
    
    
    // CharCmd::Set_Technique(Ally_unit[1].get(),0);
    // CharCmd::Set_Technique(Ally_unit[2].get(),0);
    // CharCmd::Set_Technique(Ally_unit[2].get(),0);
    // CharCmd::Set_Technique(Ally_unit[4].get(),0);
    
    
    
    //-----------------------------------------------------------
    
    // CharCmd::Set_Reroll_check(charUnit[1].get(),0);
    // CharCmd::Set_Reroll_check(Ally_unit[2].get(),0);
    // CharCmd::Set_Reroll_check(Ally_unit[3].get(),0);
    // CharCmd::Set_Reroll_check(Ally_unit[4].get(),0);
    
    
    CharCmd::Timing_print(charUnit[1].get());
    CharCmd::Timing_print(charUnit[2].get());
    CharCmd::Timing_print(charUnit[3].get());
    CharCmd::Timing_print(charUnit[4].get());
    
    
    
    // EnemyCmd::setEnemyWeakness(0,1,0,1,0,1,0);
    SetupEnemy(158,160,{10,15},{200,300},{4,6},2,EnemyType::Main);
    SetupEnemy(158,160,{10,10},{200,300},{4,6},2,EnemyType::Adjacent);
    // SetupEnemy(158,80,{0,0},{200,200},{2,3},1,EnemyType::Adjacent);  
    // SetupEnemy(130,80,{0,0},{0,0},{2,0},1,EnemyType::Other);
    // SetupEnemy(130,80,{0,0},{0,0},{2,0},1,EnemyType::Other);
    
}
