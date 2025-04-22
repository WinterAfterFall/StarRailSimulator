
#ifndef Jingyuan_H
#define Jingyuan_H

#define F first
#define S second
#include "../Library.h"

namespace Jingyuan{
    void Setup_Jingyuan(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);

    bool Temp_Turn_Condition(Unit *ptr);
    bool Temp_ult_Condition(Ally *ptr);



    void Setup_Jingyuan(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99, 130, 130, E, "Lightning", "Erudition", "Jingyuan",TYPE_STD);
        SubUnit *Jingyuanptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1164, 698, 485);

        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CRIT_RATE,ST_FLAT_SPD,ST_DMG_PERCENT,ST_ATK_PERCENT);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if ((sp <= Sp_Safety) || allyPtr->Atv_stats->turn_cnt == 1 && Sp_status == "Negative") {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,Jingyuanptr]() {
            if (((turn->Char_Name != "Jingyuan" || Ult_After_Turn == 1)) || !ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jingyuan Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({200, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({200, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({200, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                Attack(data_);
                if (ptr->Print)CharCmd::printUltStart("Jingyuan");
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                if (ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] >= 10) {
                    ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 70;
                    ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,0});
                } else {
                    ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,30});
                }
            };
            
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));
        

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Jingyuanptr]() {
            if (!(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num == turn->Unit_num && turn->Side == "Ally")) return;
            
            if (Jingyuanptr->isBuffEnd("War_Marshal")) {
                Jingyuanptr->buffSingle({{ST_CRIT_RATE,AT_NONE,-10}});
            }
            ;
            if (ptr->Eidolon >= 2 && Jingyuanptr->isBuffEnd("Swing_Skies_Squashed")) {
                Jingyuanptr->buffSingle({
                    {ST_DMG_PERCENT,AT_BASIC_ATK,-20},
                    {ST_DMG_PERCENT,AT_SKILL,-20},
                    {ST_DMG_PERCENT,AT_ULT,-20}
                });
            }
        }));


        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;

            // relic

            // substats

            // LL
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
            ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 0;
            ptr->Summon_ptr[0]->Atv_stats->Speed_percent = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Jingyuanptr]() {
            if (ptr->Technique == 1) {
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,30});

            }
            Increase_energy(ptr, 15);
        }));


        //LL
        SetSummonStats(ptr, 60, "LL");
        ptr->Summon_ptr[0]->Turn_func = [ptr,Jingyuanptr](){
            
            shared_ptr<AllyActionData> temp = make_shared<AllyActionData>();
            temp->Fua_set(ptr->Sub_Unit_ptr[0].get(),"Bounce","LL Attack");
            temp->Add_Target_Adjacent();
            temp->Skill_Type.push_back("Summon");
            temp->Turn_reset = 1;
            temp->actionFunction = [ptr,Jingyuanptr](shared_ptr<AllyActionData> &data_){
                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Summon"]+=25;
                }

                for(int i=1;i<=ptr->Sub_Unit_ptr[0]->Stack["LL_stack"];i++){
                    data_->Damage_spilt.Main.push_back({66,0,0,5});
                    if(ptr->Eidolon>=1){
                        data_->Damage_spilt.Adjacent.push_back({33,0,0,0});
                    }else{
                        data_->Damage_spilt.Adjacent.push_back({66*0.25,0,0,0});
                    }
                    
                }
                Attack(data_);

                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Summon"]-=25;
                }
        
                turn->Flat_Speed = 0;
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
                
                
                if(ptr->Eidolon>=2){
                    Jingyuanptr->buffSingle({
                        {ST_DMG_PERCENT,AT_BASIC_ATK,20},
                        {ST_DMG_PERCENT,AT_SKILL,20},
                        {ST_DMG_PERCENT,AT_ULT,20}},
                        "Swing_Skies_Squashed",2
                    );
                }
            };
            
            Action_bar.push(temp);
            

        };

        
        

         
            
    }

    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Jingyuan BasicAtttack");
        data_->Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({55,0,0,5.5});
        data_->Damage_spilt.Main.push_back({45,0,0,4.5});
        data_->actionFunction = [ptr] (shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jingyuan Skill");
        data_->Add_Target_Other();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({40,0,0,4});
        data_->Damage_spilt.Main.push_back({30,0,0,3});
        data_->Damage_spilt.Main.push_back({30,0,0,3});

        data_->Damage_spilt.Adjacent.push_back({40,0,0,4});
        data_->Damage_spilt.Adjacent.push_back({30,0,0,3});
        data_->Damage_spilt.Adjacent.push_back({30,0,0,3});

        data_->Damage_spilt.Other.push_back({40,0,0,4});
        data_->Damage_spilt.Other.push_back({30,0,0,3});
        data_->Damage_spilt.Other.push_back({30,0,0,3});
        data_->actionFunction = [ptr,Jingyuanptr = ptr->getSubUnit()] (shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Jingyuanptr->buffSingle({{ST_CRIT_RATE,AT_NONE,10}},"War_Marshal",2);
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]+=2;
            if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=10){
                ptr->Summon_ptr[0]->Atv_stats->Flat_Speed=70;
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,0});
            }else{
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,20});
            }
            Attack(data_);
        };
        Action_bar.push(data_);
        
    }



    bool Temp_Turn_Condition(Unit *ptr){
        return true;
    }
    bool Temp_ult_Condition(Ally *ptr){
        return true;
    }
}
#endif