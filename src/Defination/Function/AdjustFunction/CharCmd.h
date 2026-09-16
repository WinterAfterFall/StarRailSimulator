#include "../include.h"

namespace CharCmd{

    void printUltStart(string name){
        cout<<"------------------------------------------------------- "<<name<<" Ult Start at "<<Current_atv<<endl;
    
    }
    void printUltEnd(string name){
        cout<<"------------------------------------------------------- "<<name<<" Ult End at "<<Current_atv<<endl;
    
    }
    void printText(string text){
        cout<<"------------------------------------------------------- "<<text<<" at "<<Current_atv<<endl;
    }

    CharUnit* findAllyName(string name){
        for(int i = 1; i<= Total_ally;i++){
            if(charUnit[i]->Atv_stats->Name == name)return charUnit[i].get();
        }
        return nullptr;
    }
    
    void Set_Technique(CharUnit *ptr,int tech){
        ptr->Technique = tech;
    }
    
    
    void Set_Tune_Speed(CharUnit *ptr,double value){
        if(value==0)return;
        ptr->SpeedRequire = value;
    }
    void Set_Reroll_check(CharUnit *ptr,bool Bool){
        ptr->rerollActive = Bool;
    }
    void Timing_print(CharUnit *ptr){
        ptr->Print = 1;
    }
    bool Using_Skill(CharUnit *ptr){
        if(spMode==SPMode::Positive)return true;
        if(sp>Sp_Safety)return true;
        return false;
    }
}
