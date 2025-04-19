
#ifndef Jade_H
#define Jade_H

#define F first
#define S second
#include "../Library.h"

namespace Jade{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


//temp
    void Jade_Fua(Ally *ptr);
    void Jade_Talent(Ally *ptr,int amount);
    void Fua(Ally *ptr);
    void Fua_Enchance(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,140,140,E,"Quantum","Erudition","Jade",TYPE_STD);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CRIT_RATE,ST_ATK_PERCENT,ST_DMG_PERCENT,ST_ATK_PERCENT);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (Buff_check(allyPtr, "Jade_Skill")) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({240, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"] = 2;
                Attack(data_);
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"] += 22.4;

            // relic
            // substats
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Jade_Talent(ptr, Total_enemy);
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 50);
            if (ptr->Technique == 1) {
                
                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Technique");
                data_->Add_Target_Other();
                data_->Damage_spilt.Main.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Adjacent.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Other.push_back({50, 0, 0, 0});
                data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                    Jade_Talent(ptr, 15);
                    Attack(data_);
                };
                Action_bar.push(data_);
                if(!actionBarUse)Deal_damage();
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Char_Name == turn->Char_Name) {
                Jade_Talent(ptr, 3);
            }
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Jade_Skill")) {
                Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(), 0, -30);
                ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"] = 0;
            }
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == "Jade" && data_->Action_type.second == "Fua") {
                Jade_Talent(ptr, 5);
                return;
            }
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"] == 0) return;
            if (data_->Attacker->Atv_stats->Unit_Name != "Jade" && data_->Attacker->Atv_stats->Unit_Name != chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Unit_Name) return;

            int temp = data_->Target_Attack.size();
            if (ptr->Eidolon >= 1 && temp < 3) temp = 3;
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"] += temp;
            Jade_Fua(ptr);
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_){
            if(ptr->Eidolon >= 1 && data_->Attacker->Atv_stats->Unit_Name == "Jade" && data_->Action_type.second == "Fua"){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Dmg%", "None", 32);
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_){
            if(ptr->Eidolon >= 1 && data_->Attacker->Atv_stats->Unit_Name == "Jade" && data_->Action_type.second == "Fua"){
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Dmg%", "None", -32);
            }
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer){
            Jade_Talent(ptr, 1);
        }));
        



        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Jade BasicAtttack");
        data_->Add_Target_Adjacent();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({90,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({30,0,0,5});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Jade Skill");
        data_->Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        
        
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),0,30);
            ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"]=1;
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Jade_Skill",3);
        };
        Action_bar.push(data_);
    }


            
        

    void Jade_Fua(Ally *ptr){

        while(ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]>8){
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]-=8;
            if(ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]>0){
                Fua_Enchance(ptr);
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]--;             
            }else{
                Fua(ptr);
            }
        }
        if(!actionBarUse)Deal_damage();
    }
    void Fua(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Fua_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jade Fua");
        data_->Add_Target_Other();
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({48,0,0,10});

        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({48,0,0,10});

        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({48,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            Attack(data_);
        };
        Action_bar.push(data_);
        
    }
    void Fua_Enchance(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Fua_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jade Enchance Fua");
        data_->Add_Target_Other();
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({120,0,0,10});

        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({120,0,0,10});

        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({120,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Jade_Talent(Ally *ptr,int amount){
        Stack_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Atk%","None",0.5,amount,50,"Atk_Pawned_Asset");
        Stack_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Crit_dam","None",2.4,amount,50,"Crit_Pawned_Asset");
        if(ptr->Eidolon>=2&&ptr->Sub_Unit_ptr[0]->Buff_check["Jade_E2"]==0&&ptr->Sub_Unit_ptr[0]->Stack["Atk_Pawned_Asset"]>=15){
            ptr->Sub_Unit_ptr[0]->Buff_check["Jade_E2"]=1;
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Crit_rate","None",18);

        }

    }





}
#endif