#include "../include.h"

namespace CharCmd{

    void printUltStart(string name){
        cout<<"------------------------------------------------------- "<<name<<" Ult Start at "<<currentAtv<<endl;
    
    }
    void printUltEnd(string name){
        cout<<"------------------------------------------------------- "<<name<<" Ult End at "<<currentAtv<<endl;
    
    }
    void printText(string text){
        cout<<"------------------------------------------------------- "<<text<<" at "<<currentAtv<<endl;
    }

    CharUnit* findAllyName(string name){
        for(int i = 1; i<= totalAlly;i++){
            if(charUnit[i]->atvStats->name == name)return charUnit[i].get();
        }
        return nullptr;
    }
    
    void setTechnique(CharUnit *ptr,int tech){
        ptr->technique = tech;
    }
    
    
    void setTuneSpeed(CharUnit *ptr,double value){
        if(value==0)return;
        ptr->speedRequire = value;
    }
    void setRerollCheck(CharUnit *ptr,bool flag){
        ptr->rerollActive = flag;
    }
    void timingPrint(CharUnit *ptr){
        ptr->print = 1;
    }
    bool usingSkill(CharUnit *ptr){
        if(spMode==SPMode::POSITIVE)return true;
        if(sp>spSafety)return true;
        return false;
    }
}
