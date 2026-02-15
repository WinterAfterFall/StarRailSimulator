#include "../include.h"

namespace Pela{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(105,110,110,E,ElementType::Ice,Path::Nihility,"Pela",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            Basic_Atk(ptr);
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            for (int i = 1; i <= Total_enemy; i++) {
                if (enemyUnit[i]->Debuff["Zone_Suppression"] == 0) return true;
            }
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Pela Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED, AType::None, 42}}, "Zone_Suppression",2);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Ice][AType::None] += 22.4;
            ptr->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Stats_type[Stats::EHR][AType::None] += 10;

            // relic

            // substats
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED, AType::None, 20}}, "Pela_Technique",2);
                Increase_energy(ptr, 20);
            }
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffAllAlly({{Stats::EHR, AType::None, 10}});
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->side == Side::Enemy) {
                if (enemyUnit[turn->num]->Debuff_time_count["Zone_Suppression"] == enemyUnit[turn->num]->Atv_stats->turnCnt) {
                    enemyUnit[turn->num]->Debuff["Zone_Suppression"] = 0;
                    enemyUnit[turn->num]->Stats_type[Stats::DEF_SHRED][AType::None] -= 42;
                    --enemyUnit[turn->num]->Total_debuff;
                }
                if (enemyUnit[turn->num]->Debuff_time_count["Pela_Technique"] == turn->turnCnt) {
                    enemyUnit[turn->num]->Stats_type[Stats::DEF_SHRED][AType::None] -= 20;
                    enemyUnit[turn->num]->Debuff["Pela_Technique"] = 0;
                    --enemyUnit[turn->num]->Total_debuff;
                }
            }
        }));
        
        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Name != "Pela") return;

            for (auto e : act->targetList) {
                if (e->Total_debuff == 0) continue;
                Increase_energy(ptr, 11);
                break;
            }

            if (ptr->Eidolon >= 6) {
                shared_ptr<AllyAttackAction> addDmg = 
                make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"Pela E6");
                for (auto e : act->targetList) {
                    addDmg->addDamageIns(DmgSrc(DmgSrcType::ATK,40),e);
                }
                Attack(addDmg);
            }
        }));
    }



    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Pela BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(charUnit[ptr->Atv_stats->num].get(),20);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        act->addToActionBar();
    }
}
