
#ifndef Gallagher_H
#define Gallagher_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Gallagher{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);



    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(98,110,110,E,"Fire","Abundance","Gallagher",TYPE_STD);
        ptr->SetAllyBaseStats(1305,529,441);

        //substats
        ptr->pushSubstats("Break_effect");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(ST_HEALING_OUT,ST_FLAT_SPD,ST_ATK_PERCENT,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt % 8 == 1) {
                Skill_func(ptr);
            } else {
                if (ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                    Enchance_Basic_Atk(ptr);
                } else {
                    Basic_Atk(ptr);
                }
            }
        };
        Ultimate_List.push_back({PRIORITY_DEBUFF, [ptr]() {
            if (Ult_After_Turn == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0 || !ultUseCheck(ptr)) return;
            

            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Gallagher Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({165, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({165, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({165, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 1;
                debuffAllEnemyApplyVer(ptr->Sub_Unit_ptr[0].get(), "Vul", "Break_dmg", 13.2, "Besotted");  
                if (ptr->Eidolon >= 4) {
                    Extend_Debuff_All_Enemy("Besotted", 3);
                } else {
                    Extend_Debuff_All_Enemy("Besotted", 2);
                }
                Attack(data_);
            };
            Action_bar.push(data_);
            if (ptr->Print) CharCmd::printUltStart(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name);
            if(!actionBarUse)Deal_damage();
        }});

        Reset_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES]["None"] += 18;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"]["None"] += 20;
                ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 20;
            }
        }});

        After_turn_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy * focusUnit = turn->canCastToEnemy();
            if(!focusUnit)return;
            if (focusUnit->isDebuffEnd("Besotted")) {
                focusUnit->debuffSingleTarget("Vul", "Break_dmg", -13.2);
            }
            if (focusUnit->isDebuffEnd("Nectar_Blitz")) {
                focusUnit->atkPercent += 16;
            }
        }});


        Start_game_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Eidolon >= 1) {
                Increase_energy(ptr, 20);
            }
        }});

        When_Combat_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp - ptr->getSubUnit()->Buff_note["Novel Concoction"];
            Buff_single_target(ptr->getSubUnit(),ST_BREAK_EFFECT,AT_NONE,ptr->getSubUnit()->Buff_note["Novel Concoction"]);
            if (ptr->Technique) {
                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","gallagher Technique");
                data_->Damage_spilt.Main.push_back({50, 0, 0, 20});
                data_->Damage_spilt.Adjacent.push_back({50, 0, 0, 20});
                data_->Damage_spilt.Other.push_back({50, 0, 0, 20});
                Action_bar.push(data_);
                data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                    Extend_Debuff_All_Enemy("Besotted", 2);
                    debuffAllEnemyApplyVer(ptr->Sub_Unit_ptr[0].get(), "Vul", "Break_dmg", 13.2, "Besotted");
                    Attack(data_);
                };
                if (!actionBarUse) Deal_damage();
            }
        }});

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_HEAL, [ptr](shared_ptr<AllyActionData> &data_) {
            Heal_data healData = Heal_data();
            healData.setHealer(ptr->Sub_Unit_ptr[0].get());
            

            if (data_->Action_type.second == AT_BASIC_ATK && data_->Attacker->Atv_stats->Unit_Name == "Gallagher" && data_->Attacker->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 0;
                int cnt = 0;
                for (Enemy *e : data_->Target_Attack) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;
                        
                    }
                }
                healData.main.setRatio(0, 0, 0, 707*cnt, 0, 0);
                healData.adjacent.setRatio(0, 0, 0, 707*cnt, 0, 0);
                healData.other.setRatio(0, 0, 0, 707*cnt, 0, 0);
                Healing(healData);
            } else {
                int cnt = 0;
                for (Enemy *e : data_->Target_Attack) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;           
                    }
                }
                healData.main.setRatio(0, 0, 0, 707*cnt, 0, 0);
                Healing(healData.main, ptr->Sub_Unit_ptr[0].get(), data_->Attacker);
            }
        }));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](SubUnit* Target, string StatsType) {
            if(StatsType!=ST_BREAK_EFFECT||!Target->isSameUnitName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp - ptr->getSubUnit()->Buff_note["Novel Concoction"];
            Buff_single_target(ptr->getSubUnit(),ST_BREAK_EFFECT,AT_NONE,ptr->getSubUnit()->Buff_note["Novel Concoction"]);
        }));

        

        //substats

        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Gallagher Basic_Atk");
        data_->Add_Target_Main();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({55,0,0,5});
        data_->Damage_spilt.Main.push_back({55,0,0,5});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Enchance_Basic_Atk(Ally *ptr){
       
        
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Nectar Blitz");
        data_->Add_Target_Main();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({62.5,0,0,7.5});
        data_->Damage_spilt.Main.push_back({37.5,0,0,4.5});
        data_->Damage_spilt.Main.push_back({150,0,0,18});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            for(Enemy* &target : data_->Target_Attack){
                target->debuffApply(data_->Attacker,"Nectar_Blitz");
                target->atkPercent -= 16;
                target->extendDebuffTime("Nectar_Blitz",2);
            }
            Attack(data_);
        };
        Action_bar.push(data_);
        

    }
    void Skill_func(Ally *ptr){

        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Heal","Gallagher Skill");
        data_->Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_->resetTurn();
        data_->createHealRatio();
        data_->healPtr->setHealer(ptr->Sub_Unit_ptr[0].get());
        data_->healPtr->main.setRatio(0,0,0,1768,0,0);
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);

        };
        Action_bar.push(data_);
    }




}
#endif
