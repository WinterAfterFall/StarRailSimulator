#include "SettingFunction.h"
int main(){
    
    int tAlly;
    SetValue();
    cout<<"How many character in the team : "<<endl;
    cin>>tAlly;
    for(int i=1;i<=tAlly;i++){
        BuildSelector();
    }
    for(auto &each : CharSelectList){
        each.Char(each.eidolon,each.LC,each.Relic,each.Planar);
    }   
    EnemySelector();
    SetCharacterPtr();
    Char1->enableCheckDamageFormula(DmgFormulaMode::Crit);   

    Main();
}
