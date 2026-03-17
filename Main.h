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
