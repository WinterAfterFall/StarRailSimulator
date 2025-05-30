
#ifndef Rappa_H
#define Rappa_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Rappa{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(96, 140, 140, E, "Imaginary", "Erudition", "Rappa", TYPE_STD);
        SubUnit *Rappaptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1087,718,461);
        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_ATK_P,ST_BE);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Buff_check["Rappa_Ult"] == 0) {
            Skill_func(ptr);
            } else {
            Enchance_Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1) return;
            if (!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->setUltimate(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Buff", "Rappa Ultimate");
            data_->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                if (ptr->Print)CharCmd::printUltStart("Rappa");
                ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 1;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] = 2;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 30;
                ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"][AT_NONE] += 50;
                if (ptr->Eidolon >= 1)ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AT_NONE] += 15;
                

                shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
                data_2->setBasicAttack(ptr->Sub_Unit_ptr[0].get(), "Blast", "Rappa Enchance BasicAttack");
                data_->Dont_care_weakness = 50;
                data_2->addEnemyOtherTarget();
                data_2->Damage_spilt.Main.push_back({100, 0, 0, 10});
                data_2->Damage_spilt.Main.push_back({100, 0, 0, 10});
                data_2->Damage_spilt.Main.push_back({100, 0, 0, 5});
                data_2->Damage_spilt.Adjacent.push_back({50, 0, 0, 5});
                data_2->Damage_spilt.Adjacent.push_back({50, 0, 0, 5});
                data_2->Damage_spilt.Adjacent.push_back({100, 0, 0, 5});
                data_2->Damage_spilt.Other.push_back({100, 0, 0, 5});

                double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] + 2;
                ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] * 0.5 + 0.6;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

                data_2->Damage_spilt.Main.push_back({0, 0, 0, temp});
                data_2->Damage_spilt.Adjacent.push_back({0, 0, 0, temp});
                data_2->Damage_spilt.Other.push_back({0, 0, 0, temp});

                data_2->actionFunction = [ptr](shared_ptr<AllyActionData> &data_2){
                    Increase_energy(ptr, 20);
                    Attack(data_2);
                };
                Action_bar.push(data_2);

                if(!actionBarUse)Deal_damage();
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();

            // extra turn
            
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 13.3;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 9;

            // relic

            // substats

            // skill
        }));




        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            Enemy *enemyUnit = turn->canCastToEnemy();
            if (enemyUnit) {
                
                if (enemyUnit->isDebuffEnd("Withered_Leaf")) {
                    enemyUnit->debuffSingle({{ST_VUL,AT_BREAK,-enemyUnit->DebuffNote["Withered_Leaf"]}});
                }
            }
            if (turn->Char_Name == "Rappa") {
                if (ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] == 0 && ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] -= 30;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"][AT_NONE] -= 50;

                    ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 0;
                    if (ptr->Eidolon >= 1) {
                        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AT_NONE] -= 15;
                        Increase_energy(ptr, 20);
                    }
                    if (ptr->Print == 1) {
                        cout << " --------------Rappa Ult End at     " << Current_atv << endl;
                    }
                }
            }
        }));


        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyActionData> &data_){
            if(data_->Attacker->Atv_stats->Char_Name=="Rappa"){
                if(ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"]==1){
                    Superbreak_trigger(data_,60);

                    shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                    data_->setBreakDmg(ptr->Sub_Unit_ptr[0].get(),"Rappa Break Talent");
                    double temp = ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"];

                    for(int i=1;i<=Total_enemy;i++){
                        Cal_Break_damage(data_,Enemy_unit[i].get(),temp);
                    }
                    ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = 0;
                }
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
                Increase_energy(ptr, 10);
                for (int i = 1; i <= Total_enemy; i++) {
                    shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                    double temp;
                    data_->setBreakDmg(ptr->Sub_Unit_ptr[0].get(), "Rappa Technique");

                    if (Enemy_unit[i]->Target_type == "Main") {
                        temp = 2;
                        Cal_Break_damage(data_, Enemy_unit[i].get(), temp);
                    } else {
                        temp = 1.8;
                        Cal_Break_damage(data_, Enemy_unit[i].get(), temp);
                    }
                    shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
                    data_2->setTechnique(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Rappa Technique");
                    data_2->addEnemyOtherTarget();
                    Cal_Toughness_reduction(data_2, Enemy_unit[i].get(), 30);
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,Rappaptr](Enemy *target, SubUnit *Breaker) {
            ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]++;
            if (target->Max_toughness > 90) {
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]++;
                Increase_energy(ptr, 10);
            }
            double temp = floor((calculateAtkForBuff(ptr->getSubUnit(),100) - 2400) / 100) + 2;
            if (temp > 10) 
            temp = 10;
            if (temp < 0)
            temp = 0;
            target->DebuffNote["Withered_Leaf"] = target->DebuffNote["Withered_Leaf"];
            target->debuffSingleApply({{ST_VUL, AT_BREAK, temp - target->DebuffNote["Withered_Leaf"]}},Rappaptr,"Withered_Leaf",2);
        }));
    }


    void Enchance_Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setBasicAttack(ptr->Sub_Unit_ptr[0].get(),"Blast","Rappa Enchance BasicAttack");
        data_->addEnemyOtherTarget();
        data_->Turn_reset = 1;
        data_->Dont_care_weakness = 50;
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->Damage_spilt.Main.push_back({100,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({50,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({50,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({100,0,0,5});
        data_->Damage_spilt.Other.push_back({100,0,0,5});

        double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]+2;
        ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]*0.5+0.6;
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

        data_->Damage_spilt.Main.push_back({0,0,0,temp});
        data_->Damage_spilt.Adjacent.push_back({0,0,0,temp});
        data_->Damage_spilt.Other.push_back({0,0,0,temp});
        
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"]--;
        
        
    }
    void Skill_func(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[0].get(),"Aoe","Rappa Skill");
        data_->addEnemyOtherTarget();
        data_->Turn_reset = 1;
        data_->Damage_spilt.Main.push_back({60,0,0,5});
        data_->Damage_spilt.Main.push_back({60,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({60,0,0,5});
        data_->Damage_spilt.Adjacent.push_back({60,0,0,5});
        data_->Damage_spilt.Other.push_back({60,0,0,5});
        data_->Damage_spilt.Other.push_back({60,0,0,5});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    





}
#endif
