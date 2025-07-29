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

    Ally* findAllyName(string name){
        for(int i = 1; i<= Total_ally;i++){
            if(Ally_unit[i]->getSubUnit()->Atv_stats->Char_Name == name)return Ally_unit[i].get();
        }
        return nullptr;
    }
    
    void Set_Technique(Ally *ptr,int tech){
        ptr->Technique = tech;
    }
    
    
    void Set_Tune_Speed(Ally *ptr,double value){
        if(value==0)return;
        ptr->SpeedRequire = value;
    }
    void Set_Reroll_check(Ally *ptr,bool Bool){
        ptr->Reroll_check = Bool;
    }
    void Timing_print(Ally *ptr){
        ptr->Print = 1;
    }
    bool Using_Skill(Ally *ptr){
        if(spMode==SPMode::Positive)return true;
        if(sp>Sp_Safety)return true;
        // if(Robin_num!=0){
        //     if(Ally_unit[Robin_num ]->Sub_Unit_ptr[0]->Atv_stats->Base_speed==-1)return true;
        //     if(!Ally_unit[Robin_num]->Wait_Other_Buff)return false;   
        // }
        return false;
    }
    void Set_Other_buff(Ally *ptr,bool Bool){
        ptr->Wait_Other_Buff=Bool;
    }
}
