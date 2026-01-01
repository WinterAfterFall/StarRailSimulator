#include "../include.h"

namespace Serval{
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);





//temp
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(104,100,100,E,ElementType::Lightning,Path::Erudition,"Serval",UnitType::Standard);
        AllyUnit *Servalptr = ptr;
        ptr->SetAllyBaseStats(917,653,375);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
                Basic_Atk(ptr);
                return;

            if (allyPtr->Atv_stats->turnCnt % 3 != 1) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 10;

            // relic

            // substats
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Serval Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                Attack(act);
                if (ptr->Eidolon >= 4){
                    for (int i = 1; i <= Total_enemy; i++) {
                        if (enemyUnit[i]->debuffApply(ptr,"Serval_Shock")) {
                            enemyUnit[i]->changeShock(1);
                        }
                    }
                    extendDebuffAll("Serval_Shock", 2);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (turn->StatsOwnerName == "Serval") {
                if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Serval_A6")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] -= 20;
                }
            }
            if (turn->side == Side::Enemy) {
                Enemy *tempstats = dynamic_cast<Enemy*>(turn->charptr);
                if (tempstats) {
                    if (tempstats->isDebuffEnd("Serval_Shock")) {
                        tempstats->changeShock(-1);
                    }
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            Increase_energy(ptr, 15);
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 30;
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_BUFF, [ptr,Servalptr](Enemy* target, double Dot_ratio, DotType Dot_type) {
            if (!target->getDebuff("Serval_Shock")) return;
            if (Dot_type != DotType::General && Dot_type != DotType::Shock) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Shock,ptr,TraceType::Single,"Serval Shock");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,114),target);
            act->multiplyDmg(Dot_ratio);
            Attack(act);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->StatsOwnerName != "Serval") return;
            shared_ptr<AllyAttackAction> data_2 = 
            make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"Serval AddDmg");
            for (int i = 1; i <= Total_enemy; i++) {
                if (enemyUnit[i]->getDebuff("Serval_Shock")) {
                    data_2->addDamageIns(DmgSrc(DmgSrcType::ATK,79));
                    Attack(data_2);
                    if (ptr->Eidolon >= 2) {
                        Increase_energy(ptr, 4);
                    }
                }
            }
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,Servalptr](Enemy *target, AllyUnit *Killer) {
            Servalptr->buffSingle({{Stats::ATK_P,AType::None,20}},"Serval_A6",2);
        }));


        
    }



    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Serval BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(charUnit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10),chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        if(Total_enemy>=2&&ptr->Eidolon>=1){
            if(ptr->Sub_Unit_ptr[0]->Enemy_target_num==1){
                act->addDamageHit(DmgSrc(DmgSrcType::ATK,60,0),enemyUnit[2].get());
            }else{
                act->addDamageHit(DmgSrc(DmgSrcType::ATK,60,0),enemyUnit[1].get());
            }
        }
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Serval Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            for (int i = 1; i <= Total_enemy; i++) {
                if (enemyUnit[i]->debuffApply(ptr,"Serval_Shock")) {
                        enemyUnit[i]->changeShock(1);
                }
            }
            extendDebuffAll("Serval_Shock", 2);
            Attack(act);
        });
        act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,154,20),
                DmgSrc(DmgSrcType::ATK,66,10)
            );
        act->addToActionBar();
        
    }
}