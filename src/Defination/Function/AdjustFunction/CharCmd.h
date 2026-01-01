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
            if(charUnit[i]->Atv_stats->UnitName == name)return charUnit[i].get();
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
        ptr->Reroll_check = Bool;
    }
    void Timing_print(CharUnit *ptr){
        ptr->Print = 1;
    }
    bool Using_Skill(CharUnit *ptr){
        if(spMode==SPMode::Positive)return true;
        if(sp>Sp_Safety)return true;
        // if(Robin_num!=0){
        //     if(Ally_unit[Robin_num ]->Sub_Unit_ptr[0]->Atv_stats->Base_speed==-1)return true;
        //     if(!Ally_unit[Robin_num]->Wait_Other_Buff)return false;   
        // }
        return false;
    }
    void Set_Other_buff(CharUnit *ptr,bool Bool){
        ptr->Wait_Other_Buff=Bool;
    }
}
