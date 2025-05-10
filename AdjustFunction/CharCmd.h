#ifndef CharCmd_H
#define CharCmd_H

#include "../Class/Trigger_Function.h"

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
    
    void Set_Substats(Ally *ptr,int sub){
        ptr->Total_substats=sub;
        ptr->SeparateRatio=sub;
        ptr->Substats[0].second=sub;
    }
    void Set_Substats(Ally *ptr,int index,int sub){
        if(ptr->Substats.size()<=index){
            cout<<" Out of bound";
            exit(0);
        }
        ptr->Substats[index].second = sub;
    }
    void Switch_Substats(Ally *ptr,string temp1,string temp2){
        int index =-1;
        for(int i=0;i<ptr->Substats.size();i++){
            if(temp1==ptr->Substats[i].first){
                index = i;
                break;
            }
        }
        if(index==-1)return;
        for(int i=0;i<ptr->Substats.size();i++){
            if(temp2==ptr->Substats[i].first){
                ptr->Substats[index].first = temp2;
                ptr->Substats[i].first = temp1;
            }
        }
        return;
    }
    void Switch_Substats_toFirst(Ally *ptr,string temp){
        for(int i=0;i<ptr->Substats.size();i++){
            if(temp==ptr->Substats[i].first){
                ptr->Substats[i].first = ptr->Substats[0].first;
                ptr->Substats[0].first = temp;
                break;
            }
        }
        return;
    }
    void Set_Target_Buff(SubUnit *ptr,int num,int subnum){
        if(num!=0)ptr->defaultAllyTargetNum = num;
        if(num!=0)ptr->defaultSubUnitTargetNum = subnum;
    }
    void Set_Target_Buff(SubUnit *ptr,int num){
        if(num!=0)ptr->defaultAllyTargetNum = num;
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
        if(Sp_status=="Positive")return true;
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
#endif