
#ifndef Pela_H
#define Pela_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Pela{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(105,110,110,E,"Ice","Nihility","Pela",TYPE_STD);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            Basic_Atk(ptr);
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->Debuff["Zone_Suppression"] == 0) return true;
            }
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Pela Ult",
            [ptr](shared_ptr<AllyAttackAction> &data_){
                debuffAllEnemyApply({{ST_DEF_SHRED, AT_NONE, 42}},ptr->Sub_Unit_ptr[0].get(), "Zone_Suppression",2);
                Attack(data_);
            });
            data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20)
            );
            data_->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Ice"][AT_NONE][AT_NONE] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += 10;

            // relic

            // substats
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                debuffAllEnemyApply({{ST_DEF_SHRED, AT_NONE, 20}},ptr->Sub_Unit_ptr[0].get(), "Pela_Technique",2);
                Increase_energy(ptr, 20);
            }
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffAllAlly({{"Ehr", AT_NONE, 10}});
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Side == "Enemy") {
                if (Enemy_unit[turn->Unit_num]->Debuff_time_count["Zone_Suppression"] == Enemy_unit[turn->Unit_num]->Atv_stats->turn_cnt) {
                    Enemy_unit[turn->Unit_num]->Debuff["Zone_Suppression"] = 0;
                    Enemy_unit[turn->Unit_num]->Stats_type[ST_DEF_SHRED][AT_NONE] -= 42;
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
                if (Enemy_unit[turn->Unit_num]->Debuff_time_count["Pela_Technique"] == turn->turn_cnt) {
                    Enemy_unit[turn->Unit_num]->Stats_type[ST_DEF_SHRED][AT_NONE] -= 20;
                    Enemy_unit[turn->Unit_num]->Debuff["Pela_Technique"] = 0;
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
            }
        }));
        
        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &data_) {
            if (data_->Attacker->Atv_stats->Char_Name != "Pela") return;

            for (auto e : data_->targetList) {
                if (e->Total_debuff == 0) continue;
                Increase_energy(ptr, 11);
                break;
            }

            if (ptr->Eidolon >= 6) {
                shared_ptr<AllyAttackAction> addDmg = 
                make_shared<AllyAttackAction>(ActionType::Addtional,ptr->getSubUnit(),TT_SINGLE,"Pela E6");
                for (auto e : data_->targetList) {
                    Cal_Additional_damage(addDmg, e, DmgSrc(DmgSrcType::ATK,40,0));
                }
            }
        }));
    }



    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Pela BA",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        });
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        data_->addToActionBar();
    }
    





    

    
}

#endif
