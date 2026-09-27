#include "SettingFunction.h"
int main(){
    
    int tAlly;
    setValue();
    cout<<"How many character in the team : "<<endl;
    cin>>tAlly;
    for(int i=1;i<=tAlly;i++){
        buildSelector();
    }
    for(auto &each : charSelectList){
        each.charSetup(each.eidolon,each.lc,each.Relic,each.Planar);
    }   
    enemySelector();
    setCharacterPtr();
    char1->enableCheckDamageFormula(DmgFormulaMode::CRIT);   

    mainLoop();
}
