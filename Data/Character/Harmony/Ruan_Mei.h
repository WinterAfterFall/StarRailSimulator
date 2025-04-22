
#ifndef RuanMei_H
#define RuanMei_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Ruan_Mei{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);
    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(104, 130, 130, E, "Ice", "Harmony", "Ruan_Mei",TYPE_STD);
        ptr->SetAllyBaseStats(1087, 660, 485);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(ST_ATK_PERCENT,ST_FLAT_SPD,ST_ATK_PERCENT,ST_EnergyRecharge);

        
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,allyptr = ptr->Sub_Unit_ptr[0].get() ]() {
            if (allyptr->Buff_check["Mei_Skill"] == 0) {
                Skill_func(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Buff","RuanMei Ult");
            data_->Add_Buff_All_Ally();
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                if(ptr->Print)CharCmd::printUltStart("Ruan Mei");
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(), "RuanMei_Ult")){
                    buffAllAlly("Respen", "None", 25);
                    if(ptr->Eidolon >= 1){
                        buffAllAlly("Def_shred", "None", 20);
                    }
                }
                ptr->Sub_Unit_ptr[0]->Buff_check["RuanMei_Ult"] = 1;
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "RuanMei_Ult", 2);

            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 22.5;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 5;

            // relic

            // substats
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly("Dmg%", "None", 36);
            buffAllAlly("Break_effect", "None", 20);
            Speed_Buff_All_Ally_Exclude_Buffer(10, 0, "Ruan_Mei");
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTION, [ptr](){
            if(ptr->Technique == 1){
                

                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->Skill_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff","RuanMei Skill");
                data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
                data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                    Increase_energy(ptr, 30);
                    buffAllAlly("Dmg%", "None", 32);
                    buffAllAlly("Weakness_Break_Efficiency", "None", 50);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 1;
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Mei_Skill", 3);
                };
                Action_bar.push(data_);
                if(!actionBarUse)Deal_damage();
                return;
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(), "Mei_Skill")){
                ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 0;
                buffAllAlly("Dmg%", "None", -32);
                buffAllAlly("Weakness_Break_Efficiency", "None", -50);
            }
            if(turn->Char_Name == "Ruan_Mei"){
                Increase_energy(ptr, 5);
                if(Buff_end(ptr->Sub_Unit_ptr[0].get(), "RuanMei_Ult")){
                    buffAllAlly("Respen", "None", -25);
                    if(ptr->Eidolon >= 1){
                        buffAllAlly("Def_shred", "None", -20);
                    }
                    ptr->Sub_Unit_ptr[0]->Buff_check["RuanMei_Ult"] = 0;
                    if(ptr->Print == 1) cout << "-------------------------------------------- Ruan Mei ult end at " << Current_atv << endl;
                }
            }
            if(turn->Side == "Enemy" && Turn_Skip == 0){
                if(Enemy_unit[turn->Unit_num]->Debuff["RuanMei_Ult_bloom"] == 1){
                    Turn_Skip = 1;
                    Enemy_unit[turn->Unit_num]->debuffRemove("RuanMei_Ult_bloom");
                    Action_forward(Enemy_unit[turn->Unit_num]->Atv_stats.get(), -10 - (0.2 * (ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"])));
                    shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                    data_->Break_dmg_set(ptr->Sub_Unit_ptr[0].get(),"RuanMei Break");
                    double temp = 0.5;
                    Cal_Break_damage(data_, Enemy_unit[turn->Unit_num].get(), temp);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_){
            if(Buff_check(ptr->Sub_Unit_ptr[0].get(), "RuanMei_Ult")){
                for(Enemy * &e : data_->Target_Attack){
                    e->debuffApply(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult_bloom");
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Breaker){
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            double temp;
            data_->Break_dmg_set(ptr->Sub_Unit_ptr[0].get(),"RuanMei Break");
            temp = 1.2;
            Cal_Break_damage(data_, target, temp);
        }));
    
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","RuanMei BasicAttack");
        data_->Add_Target_Main();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill_func(Ally *ptr){
        
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","RuanMei Skill");
        data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        data_->Turn_reset = 1;
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            buffAllAlly("Dmg%","None",32);
            buffAllAlly("Weakness_Break_Efficiency","None",50);
            ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 1;
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Mei_Skill",3);
        };
        Action_bar.push(data_);
    }



    
    

}
#endif
