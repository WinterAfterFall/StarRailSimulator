
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
        Ally *ptr =  SetAllyBasicStats(112, 130, 130, E, "Lightning", "Harmony", "Tingyun",TYPE_STD);
        SubUnit *TYptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(847, 529, 397);
        ptr->Technique = 2;
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_ATK_P,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (chooseSubUnitBuff(allyPtr)->Buff_check["Benediction"] == 0) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            if (Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Current_energy <= 30) return;

            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff","Tingyun Ultimate");
            data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_->actionFunction = [ptr,TYptr](shared_ptr<AllyActionData> &data_){
                Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);
                if (ptr->Eidolon >= 1)
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,20}},"Windfall_of_Lucky_Springs",1);
                
                if (turn->Char_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[0]->Atv_stats->Char_Name && Ult_After_Turn == 0)
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,56}},"Rejoicing_Clouds",1);
                else
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,56}},"Rejoicing_Clouds",2);
            };
            Action_bar.push(data_);
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Lightning"]["None"] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 22.5;

            // relic

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Basic_Attack"] += 40;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            if (turn->Char_Name != "Tingyun") return;
            Increase_energy(ptr, 5);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            SubUnit* tempUnit = turn->canCastToSubUnit();
            if (!tempUnit) return;
            
            if (tempUnit->isBuffEnd("Nourished_Joviality")) {
                tempUnit->buffSingle({{ST_SPD,ST_SPD_P,-20}});
            }
            
            if (tempUnit->isBuffEnd("Benediction")) {
                tempUnit->buffSingle({{ST_ATK_P,AT_NONE,-55}});
            }
            if (tempUnit->isBuffEnd("Windfall_of_Lucky_Springs")) {
                tempUnit->buffSingle({{ST_SPD,ST_SPD_P,-20}});
            }
            if (tempUnit->isBuffEnd("Rejoicing_Clouds")) {
                tempUnit->buffSingle({{ST_DMG,AT_NONE,-56}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr,TYptr](shared_ptr<AllyActionData> &data_) {
            SubUnit* tempUnit = data_->Attacker;
            if (!tempUnit) return;
            if (tempUnit->getBuffCheck("Benediction")) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    shared_ptr<AllyActionData> temp = make_shared<AllyActionData>();
                    temp->Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target","Tingyun Talent");
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {66, 0, 0, 0});
                } else if (data_->Attacker->Atv_stats->Unit_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->currentSubUnitTargetNum]->Atv_stats->Unit_Name) {
                    shared_ptr<AllyActionData> temp = make_shared<AllyActionData>();
                    temp->Additional_set(tempUnit, "Single_target","Tingyun Talent");

                    if (ptr->Eidolon >= 4) 
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {64, 0, 0, 0});
                    else 
                    Cal_Additional_damage(temp, Enemy_unit[Main_Enemy_num].get(), {44, 0, 0, 0});
                    
                }
            }
            if (data_->Action_type.second == "Skill" && data_->Attacker->Atv_stats->Char_Name == "Tingyun") {
                ptr->Sub_Unit_ptr[0]->buffSingle({{ST_SPD,ST_SPD_P,20}},"Nourished_Joviality",1);
            }
        }));
    



    }

    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Tingyun Skill");
        data_->Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset = 1;
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            ptr->Sub_Unit_ptr[0]->buffSingle({{ST_ATK_P,AT_NONE,55}},"Benediction",3);

        };
        Action_bar.push(data_);
    }
    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Tingyun BasicAttack");
        data_->Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset = 1;
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        data_->Damage_spilt.Main.push_back({33,0,0,3});
        data_->Damage_spilt.Main.push_back({77,0,0,7});
        Action_bar.push(data_);
    }

    

    

    
}
#endif
