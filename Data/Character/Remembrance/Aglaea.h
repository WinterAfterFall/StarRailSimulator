
#ifndef Aglaea_H
#define Aglaea_H

#define F first
#define S second
#include "../Library.h"

namespace Aglaea{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Memo_Skill(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Summon(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(102,350,350,E,"Lightning","Remembrance","Aglaea",TYPE_STD);
        SubUnit *AGptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1242,699,485);
        SetMemoStats(ptr,66,35,"Lightning","Garmentmaker",TYPE_STD);
        SetCountdownStats(ptr,"Supreme_Stance");

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);




        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Atv_stats->Base_speed == -1) {
                Skill(ptr);
                return;
            }

            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1) {
                Enchance_Basic_Atk(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,AGptr]() {
            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1 && 
                (ptr->Countdown_ptr[0]->Atv_stats->atv > ptr->Sub_Unit_ptr[0]->Atv_stats->atv && 
                (ptr->Sub_Unit_ptr[0]->Atv_stats->atv != ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv))) return;
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->atv == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0) return;
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff", "Aglaea Ultimate");
            data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_->actionFunction = [ptr,AGptr](shared_ptr<AllyActionData> &data_) {
                if (ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed == -1) Summon(ptr);

                if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed == -1) 
                AGptr->buffSingle({{ST_SPD, ST_SPD_P, 15.0 * ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]}});
                
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                ptr->Countdown_ptr[0]->resetATV(100);
                double BuffValue = calculateSpeedForBuff(ptr->Sub_Unit_ptr[0].get(), 360) + 
                calculateSpeedForBuff(ptr->Sub_Unit_ptr[1].get(), 720);

                ptr->buffAlly({{ST_FLAT_ATK, AT_TEMP, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->buffAlly({{ST_FLAT_ATK, AT_NONE, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] =  BuffValue;
                if (ptr->Print) CharCmd::printUltStart("Aglaea");
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Lightning"]["None"] += 22.4;

            // relic

            // substats

            // countdown
        }));


        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"]["None"] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            if (ptr->Technique == 1) {
                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Aglaea Technique");
                data_->Add_Target_Other();
                data_->Damage_spilt.Main.push_back({100, 0, 0, 20});
                data_->Damage_spilt.Adjacent.push_back({100, 0, 0, 20});
                data_->Damage_spilt.Other.push_back({100, 0, 0, 20});
                data_->actionFunction = [ptr,AGptr](shared_ptr<AllyActionData> &data_) {
                    Increase_energy(ptr, 30);
                    ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed * 0.35;
                    Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    resetTurn(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(), 100);
                    Attack(data_);
                };
                Action_bar.push(data_);
                if (!actionBarUse) Deal_damage();
            }
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr,AGptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                if (data_->Attacker->Stack["Brewed_by_Tears"] < 6) {
                    data_->Attacker->buffSingle({{ST_SPD, ST_FLAT_SPD, 55.0}});
                    data_->Attacker->Stack["Brewed_by_Tears"]++;
                    if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed != -1) {
                        AGptr->buffSingle({{ST_SPD, ST_SPD_P, 15.0}});
                    }
                }
            }
            if (data_->Attacker->isSameUnitName("Aglaea")) {
                if (Enemy_unit[Main_Enemy_num]->debuffApply(ptr->getSubUnit(),"Seam_Stitch")) {
                    if (ptr->Eidolon >= 1) {
                        Enemy_unit[Main_Enemy_num]->debuffSingle({{ST_VUL, AT_NONE, 15}});
                    }
                }
            }
            if (data_->Attacker->Atv_stats->Unit_num == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num) {
                shared_ptr<AllyActionData> data_Additional = make_shared<AllyActionData>();
                data_Additional->Additional_set(data_->Attacker, "Single_target", "Aglaea Additional Damage");
                Cal_Additional_damage(data_Additional, Enemy_unit[Main_Enemy_num].get(), {30, 0, 0, 0});
                if (ptr->Eidolon >= 1) {
                    Increase_energy(ptr, 20);
                }
            }
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyActionData> &data_) {
            if (ptr->Eidolon >= 2) {
                if (data_->Attacker->Atv_stats->Unit_Name == "Aglaea" || data_->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    ptr->buffStackAlly({{ST_DEF_SHRED,AT_NONE,14}},1,3,"Aglaea_E2");
                } else {
                    ptr->buffResetStack({{ST_DEF_SHRED,AT_NONE,14}},"Aglaea_E2");
                }
            }
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyActionData> &data_) {
            if (ptr->Eidolon >= 2) {
                if (data_->Attacker->Atv_stats->Unit_Name == "Aglaea" || data_->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    ptr->buffStackAlly({{ST_DEF_SHRED,AT_NONE,14}},1,3,"Aglaea_E2");
                } else {
                    ptr->buffResetStack({{ST_DEF_SHRED,AT_NONE,14}},"Aglaea_E2");
                }
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,AGptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Aglaea") return;
            if (ptr->Countdown_ptr[0]->Atv_stats->Base_speed == -1) return;
            if (StatsType == "Speed") {
                // adjust
                double BuffValue = calculateSpeedForBuff(ptr->Sub_Unit_ptr[0].get(), 360) + 
                calculateSpeedForBuff(ptr->Sub_Unit_ptr[1].get(), 720);

                ptr->buffAlly({{ST_FLAT_ATK, AT_TEMP, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->buffAlly({{ST_FLAT_ATK, AT_NONE, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] =  BuffValue;
                return;
            }
        }));

        
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,AGptr](){
        
            Memo_Skill(ptr);
            
        };

        ptr->Countdown_ptr[0]->Turn_func = [ptr,AGptr](){
            AGptr->buffSingle({{ST_SPD, ST_SPD_P, 15.0 * ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]}});
            
            ptr->Countdown_ptr[0]->resetATV(-1);
            
            ptr->buffAlly({{ST_FLAT_ATK, AT_TEMP,-ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
            ptr->buffAlly({{ST_FLAT_ATK, AT_NONE,-ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
    
            ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] = 0;
            ptr->Sub_Unit_ptr[1]->Death(); 
            double temp =0;
            if(ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]>1){
                temp = ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]-1;
            }
            ptr->Sub_Unit_ptr[1]->buffSingle({{ST_SPD, ST_FLAT_SPD, -55.0 * temp}});
            ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"] = 1;
            Increase_energy(ptr,20);
    
            if(ptr->Print)CharCmd::printUltEnd("Aglaea");
        };


    }
    



    void Enchance_Basic_Atk(Ally *ptr){
       
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Aglaea Joint Attack");
        data_->Add_Target_Adjacent();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({200,0,0,10});
        data_->Damage_spilt.Main.push_back({200,0,0,10});

        data_->Damage_spilt.Adjacent.push_back({90,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({90,0,0,5});
        data_->All_Attacker.push_back(ptr->Sub_Unit_ptr[1].get());
        data_->Attack_trigger++;
        data_->Joint.push_back(AttackSource(1,ptr->Sub_Unit_ptr[1].get()));
        data_->actionFunction =[ptr](shared_ptr<AllyActionData> &data_ ){
            Increase_energy(ptr,20);
            Attack(data_);
        };

        Action_bar.push(data_);
    }
    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Aglaea BasicAttack");
        data_->Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->actionFunction =[ptr](shared_ptr<AllyActionData> &data_ ){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Aglaea Skill");
        data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        data_->Turn_reset=true;
        data_->Buff_type.push_back("Summon");
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                Summon(ptr);
                data_->Turn_reset=false;
            }
        };
        
        Action_bar.push(data_);
    }
    void Summon(Ally *ptr){
        ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed*0.35;
        Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        resetTurn(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
    }
    

    
    void Memo_Skill(Ally *ptr){

        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();

        data_->Skill_set(ptr->Sub_Unit_ptr[1].get(),"Blast","Garmentmaker Skill");
        data_->Add_Target_Adjacent();
        data_->Skill_Type.push_back("Summon");
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({110,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({66,0,0,5});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            Attack(data_);
        };
        Action_bar.push(data_);
    }

    
    
    

    


}
#endif