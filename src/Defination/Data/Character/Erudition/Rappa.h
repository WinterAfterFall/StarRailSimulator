#include "../include.h"

namespace Rappa{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(96, 140, 140, E, ElementType::Imaginary, "Erudition", "Rappa", TYPE_STD);
        SubUnit *Rappaptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1087,718,461);
        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);



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

        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1)return false;
            return true;
        });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TT_SINGLE,"Rappa Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->Print)CharCmd::printUltStart("Rappa");
                ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 1;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] = 2;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 30;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BREAK_EFF][AType::None] += 50;
                if (ptr->Eidolon >= 1)ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::None] += 15;
                

                shared_ptr<AllyAttackAction> data_2 = 
                make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_BLAST,"Rappa EBA",
                [ptr](shared_ptr<AllyAttackAction> &data_2){
                    Increase_energy(ptr, 20);
                    Attack(data_2);
                });
                double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] + 2;
                ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] * 0.5 + 0.6;
                ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

                data_2->Dont_care_weakness = 50;
                data_2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 10),
                    DmgSrc(DmgSrcType::ATK, 50, 5)
                );
                data_2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 10),
                    DmgSrc(DmgSrcType::ATK, 50, 5)
                );
                data_2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp) 
                );
                data_2->addToActionBar();
                Deal_damage();
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 13.3;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 9;

            // relic

            // substats

            // skill
        }));




        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            Enemy *enemyUnit = turn->canCastToEnemy();
            if (enemyUnit) {
                
                if (enemyUnit->isDebuffEnd("Withered_Leaf")) {
                    enemyUnit->debuffSingle({{Stats::VUL,AType::Break,-enemyUnit->DebuffNote["Withered_Leaf"]}});
                }
            }
            if (turn->Char_Name == "Rappa") {
                if (ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"] == 0 && ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] == 1) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] -= 30;
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BREAK_EFF][AType::None] -= 50;

                    ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"] = 0;
                    if (ptr->Eidolon >= 1) {
                        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::None] -= 15;
                        Increase_energy(ptr, 20);
                    }
                    if (ptr->Print == 1) {
                        cout << " --------------Rappa Ult End at     " << Current_atv << endl;
                    }
                }
            }
        }));


        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            if(act->Attacker->Atv_stats->Char_Name=="Rappa"){
                if(ptr->Sub_Unit_ptr[0]->Buff_check["Rappa_Ult"]==1){
                    Superbreak_trigger(act,60,"");

                    shared_ptr<AllyAttackAction> data_2 = 
                    make_shared<AllyAttackAction>(AType::Break,ptr->getSubUnit(),TT_AOE,"Rappa Talent");
                    double temp = ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"];
                    for(int i=1;i<=Total_enemy;i++){
                        Cal_Break_damage(act,Enemy_unit[i].get(),temp);
                    }
                    ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = 0;
                }
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
                Increase_energy(ptr, 10);
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Break,ptr->getSubUnit(),TT_AOE,"Rappa Tech");
                shared_ptr<AllyAttackAction> data_2 = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TT_AOE,"Rappa Tech");
                for (int i = 1; i <= Total_enemy; i++) {
                    double temp;
                   
                    if (Enemy_unit[i]->Target_type == "Main") {
                        temp = 2;
                        Cal_Break_damage(act, Enemy_unit[i].get(), temp);
                    } else {
                        temp = 1.8;
                        Cal_Break_damage(act, Enemy_unit[i].get(), temp);
                    }
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
            target->debuffSingleApply({{Stats::VUL, AType::Break, temp - target->DebuffNote["Withered_Leaf"]}},Rappaptr,"Withered_Leaf",2);
        }));
    }


    void Enchance_Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_BLAST,"Rappa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr, 20);
            Attack(act);
        });
        double temp = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]+2;
        ptr->Sub_Unit_ptr[0]->Buff_note["Rappa_Talent"] = ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"]*0.5+0.6;
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Talent"] = 0;

        act->Dont_care_weakness = 50;
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 10),
            DmgSrc(DmgSrcType::ATK, 50, 5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 10),
            DmgSrc(DmgSrcType::ATK, 50, 5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp) 
        );
        act->addToActionBar();
        ptr->Sub_Unit_ptr[0]->Stack["Rappa_Ult"]--;
    }
    void Skill_func(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_AOE,"Rappa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5) 
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5) 
        );
        act->addToActionBar();
    }
}