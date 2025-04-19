
#ifndef Anaxa_H
#define Anaxa_H

#define F first
#define S second
#include "../Library.h"

namespace Jade{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


//temp


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(97,140,140,E,"Wind","Erudition","Anaxa",TYPE_STD);
        ptr->SetAllyBaseStats(970,757,558);

        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(ST_CRIT_RATE,ST_FLAT_SPD,ST_DMG_PERCENT,ST_ATK_PERCENT);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (sp>Sp_Safety) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({240, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({240, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({240, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_) {
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"] = 2;
                Attack(data_);
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Wind"]["None"] += 22.4;
            // relic
            // substats
        }));

    }



    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),TT_SINGLE,"Anaxa BA");
        data_.Add_Target_Adjacent();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),TT_BOUNCE,"Anaxa Skill");
        data_.Add_Target_FairBounce(5,{70,0,0,10});
        data_.Turn_reset=true; 
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }

}
#endif