
#ifndef Serval_H
#define Serval_H

#define F first
#define S second
#include "../Library.h"

namespace Serval{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);





//temp
    bool Use_Skill();
    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(104,100,100,E,"Lightning","Erudition","Serval",TYPE_STD);
        SubUnit *Servalptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(917,653,375);
        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(ST_EHR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Atv_stats->turn_cnt % 3 != 1) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_EHR][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 10;

            // relic

            // substats
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Serval Ult",
            [ptr](shared_ptr<AllyAttackAction> &data_){
                Attack(data_);
                if (ptr->Eidolon >= 4){
                    for (int i = 1; i <= Total_enemy; i++) {
                        if (Enemy_unit[i]->debuffApply(ptr->getSubUnit(),"Serval_Shock")) {
                            Enemy_unit[i]->Debuff["Shock_check"]++;
                        }
                    }
                    extendDebuffAll("Serval_Shock", 2);
                }
            });
            data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20)
            );
            data_->addToActionBar();
            Deal_damage();
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (turn->Unit_Name == "Serval") {
                if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Serval_A6")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] -= 20;
                }
            }
            if (turn->Side == "Enemy") {
                Enemy *tempstats = dynamic_cast<Enemy*>(turn->ptrToChar);
                if (tempstats) {
                    if (tempstats->isDebuffEnd("Serval_Shock")) {
                        tempstats->Debuff["Shock_check"]--;
                    }
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            Increase_energy(ptr, 15);
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 30;
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_BUFF, [ptr,Servalptr](Enemy* target, double Dot_ratio, string Dot_type) {
            if (!target->getDebuff("Serval_Shock")) return;
            if (Dot_type != AT_NONE && Dot_type != "Lightning") return;
            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Dot,ptr->getSubUnit(),TT_SINGLE,"Serval Shock");
            data_->addDamageIns(DmgSrc(DmgSrcType::ATK,114,0));
            dotDamage(data_,Dot_ratio);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name != "Serval") return;
            shared_ptr<AllyAttackAction> data_2 = 
            make_shared<AllyAttackAction>(ActionType::Addtional,ptr->getSubUnit(),TT_SINGLE,"Serval AddDmg");
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->getDebuff("Serval_Shock")) {
                    Cal_Additional_damage(data_2, Enemy_unit[i].get(),DmgSrc(DmgSrcType::ATK,79,0));
                    if (ptr->Eidolon >= 2) {
                        Increase_energy(ptr, 4);
                    }
                }
            }
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,Servalptr](Enemy *target, SubUnit *Killer) {
            Servalptr->buffSingle({{ST_ATK_P,AT_NONE,20}},"Serval_A6",2);
        }));


        
    }



    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Serval BA",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        });
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10),chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        if(Total_enemy>=2&&ptr->Eidolon>=1){
            if(ptr->Sub_Unit_ptr[0]->Enemy_target_num==1){
                data_->addDamage(DmgSrc(DmgSrcType::ATK,60,0),Enemy_unit[2].get());
            }else{
                data_->addDamage(DmgSrc(DmgSrcType::ATK,60,0),Enemy_unit[1].get());
            }
        }
        data_->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BLAST,"Serval Skill",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->debuffApply(ptr->getSubUnit(),"Serval_Shock")) {
                    Enemy_unit[i]->Debuff["Shock_check"]++;
                }
            }
            extendDebuffAll("Serval_Shock", 2);
            Attack(data_);
        });
        data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,154,20),
                DmgSrc(DmgSrcType::ATK,66,10)
            );
        data_->addToActionBar();
        
    }







}
#endif