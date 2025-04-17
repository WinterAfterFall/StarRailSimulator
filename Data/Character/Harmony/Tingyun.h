
#ifndef Tingyun_H
#define Tingyun_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Tingyun{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit.push_back(make_unique<Ally>());
        Total_ally++;
        int num = Total_ally;
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(), 847, 529, 397);
        SetAllyBasicStats(Ally_unit[num].get(), 112, 130, 130, E, "Lightning", "Harmony", num, "Tingyun", "Ally");
        Ally_unit[num]->Technique = 2;

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (chooseSubUnitBuff(allyPtr)->Buff_check["Benediction"] == 0) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Current_energy <= 30) return;

            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff","Tingyun Ultimate");
            data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_.actionFunction = [ptr](ActionData &data_){
                Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);
                if (ptr->Eidolon >= 1) {
                    Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(), 20, 0);
                    Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()), "Windfall_of_Lucky_Springs", 1);
                }
                if (Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[0]->Buff_check["Rejoicing_Clouds"] == 0) {
                    Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()), "Dmg%", "None", 56);
                    chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Rejoicing_Clouds"] = 1;
                }
                if (turn->Char_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[0]->Atv_stats->Char_Name && Ult_After_Turn == 0)
                Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()), "Rejoicing_Clouds", 1);
                else
                Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()), "Rejoicing_Clouds", 2);
                
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 22.5;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 77.76;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Basic_Attack"] += 40;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Char_Name != "Tingyun") return;
            Increase_energy(ptr, 5);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            SubUnit* tempUnit = turn->canCastToSubUnit();
            if (!tempUnit) return;
            if (turn->Char_Name == "Tingyun") {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Nourished_Joviality")) {
                    Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), -20, 0);
                }
            }
            if (Buff_end(tempUnit, "Benediction")) {
                tempUnit->Buff_check["Benediction"] = 0;
                Buff_single_target(tempUnit, "Atk%", "None", -55);
            }
            if (Buff_end(tempUnit, "Windfall_of_Lucky_Springs")) {
                Speed_Buff(tempUnit->Atv_stats.get(), -20, 0);
            }
            if (Buff_end(tempUnit, "Rejoicing_Clouds")) {
                Buff_single_target(tempUnit, "Dmg%", "None", -56);
                tempUnit->Buff_check["Rejoicing_Clouds"] = 0;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData& data_) {
            SubUnit* tempUnit = data_.Attacker;
            if (!tempUnit) return;
            if (Buff_check(tempUnit, "Benediction")) {
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    ActionData temp = ActionData();
                    temp.Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target","Tingyun Talent");
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {66, 0, 0, 0});
                } else if (data_.Attacker->Atv_stats->Unit_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->currentSubUnitTargetNum]->Atv_stats->Unit_Name) {
                    ActionData temp = ActionData();
                    temp.Additional_set(tempUnit, "Single_target","Tingyun Talent");

                    if (ptr->Eidolon >= 4) 
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {64, 0, 0, 0});
                    else 
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {44, 0, 0, 0});
                    
                }
            }
            if (data_.Action_type.second == "Skill" && data_.Attacker->Atv_stats->Char_Name == "Tingyun") {
                Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), -20, 0);
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Nourished_Joviality", 1);
            }
        }));
    



    }

    void Skill(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Tingyun Skill");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Benediction")){
                Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Atk%","None",55);
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Benediction"] = 1;
            }
        };
        Action_bar.push(data_);
        
        Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Benediction",3);
    }
    void Basic_Atk(Ally *ptr){
        ActionData data_ = ActionData();
        
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Tingyun BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        data_.Damage_spilt.Main.push_back({33,0,0,3});
        data_.Damage_spilt.Main.push_back({77,0,0,7});
        Action_bar.push(data_);
    }

    

    

    
}
#endif
