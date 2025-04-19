
#ifndef Luocha_H
#define Luocha_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Luocha{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Talent(Ally *ptr);
    void Abyss_Flower(Ally *ptr);


    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(101,100,100,E,"Imaginary","Abundance","Luocha",TYPE_STD);
        ptr->SetAllyBaseStats(1280,756,363);

        ptr->pushSubstats(ST_ATK_PERCENT);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(ST_HEALING_OUT,ST_FLAT_SPD,ST_ATK_PERCENT,ST_EnergyRecharge);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
       ptr->Sub_Unit_ptr[0]->Turn_func = [ptr]() {
            Basic_Atk(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] >= 2) return;
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Luocha Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({200, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({200, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({200, 0, 0, 20});
            data_->actionFunction = [ptr](AllyActionData &data_) {
                Attack(data_);
                ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
                Abyss_Flower(ptr);
            };

            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;

            // relic

            // substats
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Char_Name == "Luocha") {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Cycle_of_Life")) {
                    if (ptr->Eidolon >= 1) {
                        Buff_All_Ally("Atk%", "None", -20);
                    }
                    ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] = 0;
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] = 2;
                Abyss_Flower(ptr);
            }
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](AllyActionData &data_) {
            if (ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] >= 2) {
                HealRatio healRatio = HealRatio();
                HealRatio healRatioMain = HealRatio();

                healRatioMain.setRatio(18, 0, 0, 240, 0, 0);
                healRatio.setRatio(7, 0, 0, 93, 0, 0);

                Healing(healRatioMain, healRatio, ptr->Sub_Unit_ptr[0].get(), data_.Attacker);
            }
        }));
        

    }


    void Talent(Ally *ptr){
        Increase_energy(ptr,30);
        ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
        Heal_data healData = Heal_data();
        healData.setHealer(ptr->Sub_Unit_ptr[0].get());
        healData.main.setRatio(60,0,0,800,0,0);
        Healing(healData);
        Abyss_Flower(ptr);
        
    }
    void Abyss_Flower(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]==2){
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Cycle_of_Life",2);
        if(ptr->Eidolon>=1){
            Buff_All_Ally("Atk%","None",20);
        }
        }
    }
    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Luocha Basic_Atk");
        data_->Add_Target_Main();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({30,0,0,3});
        data_->Damage_spilt.Main.push_back({30,0,0,3});
        data_->Damage_spilt.Main.push_back({40,0,0,4});
        data_->actionFunction = [ptr](AllyActionData &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt%2==1){
                Talent(ptr);
            }
        };
        Action_bar.push(data_);
        
    }





    

    
}
#endif
