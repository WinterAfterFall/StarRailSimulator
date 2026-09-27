#ifndef MAIN_H
#define MAIN_H
#include "src/Library.h"

CharUnit* char1;
CharUnit* char2;
CharUnit* char3;
CharUnit* char4; 
void setValue(){
    driverType = DriverType::NONE;
    spMode = SPMode::NEGATIVE;      
    //set unit
    
    wave[0] = 800;
    wave[0]+=0.01;
    printAtv = 1;
    bestBounce = 1;
    // golden ratio 
    rerollSubstatsMode = SubstatsRerollMode::STANDARD;

}
void setCharacterPtr(){
    char1 = charUnit[1].get();      
    char2 = charUnit[2].get();
    char3 = charUnit[3].get();
    char4 = charUnit[4].get(); 
}
void mainLoop(){
    setup();
    while(1){
        cout<<" ---------------------------------------------------------- ";
        cout<<endl;
        bool skip = 0;
        reset();
        for(int i=1;i<=totalAlly;i++){
            setStats(charUnit[i].get());
        }
        startGame();cout<<endl;
        
        for(int i=0;i<totalWave;i++){
            
            currentAtv=0;
            startWave(i);  
            dealDamage();
            

            while(1){
            turnSkip=0;
            findTurn();
            atvFix(turn->atv);
   
            if(currentAtv>wave[i]){
                endWave(wave[i]);
                break;
            }
            takeAction();
            
        }
    }
    
    calDamageSummary();
    printRoundResult();
    if(rerollSubstats())break;
    }
    printSummaryResult();
    std::cout << "Press Enter to end program..." <<endl;
    std::cin.get();
    return ;
}

#endif
