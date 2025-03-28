
#ifndef Mydei_LC_H
#define Mydei_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    void Mydei_LC(Ally *ptr);
    void Mydei_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1376,476,397);
        ptr->Light_cone.Name = "Mydei_LC";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING][AT_NONE]+=20;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT][AT_NONE]+=18;
            
            }
        ));
        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr,ActionData &data_){
            if(!data_.Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            if(data_.Action_type.second == AT_SKILL||data_.Action_type.second == AT_ULT){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]++;
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,30);
                if(ptr->Sub_Unit_ptr[0]->currentHP>=50000.0/6.0){
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,30);
                    ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]++;
                    DecreaseHP(ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get(),0,6,0);
                }
            }
        }));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr,ActionData &data_){
            if(!data_.Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DMG_PERCENT,AT_NONE,-30*ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"]);
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_LC_Mark"] = 0;
        }));
    }
}
#endif