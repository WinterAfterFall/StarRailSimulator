#include "../include.h"

namespace Aglaea{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

//temp
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void Memo_Skill(CharUnit *ptr);
    void Enchance_Basic_Atk(CharUnit *ptr);
    void Summon(CharUnit *ptr);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(102,350,350,E,ElementType::Lightning,Path::Remembrance,"Aglaea",UnitType::Standard);
        AllyUnit *AGptr = ptr;
        ptr->SetAllyBaseStats(1242,699,485);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,720,66,0,35,ElementType::Lightning,"Garmentmaker",UnitType::Standard);
        SetCountdownStats(ptr,100,"Supreme_Stance");

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        // ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ER);




        //func
        
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            if (ptr->getMemosprite()->isDeath()) {
                Skill(ptr);
                return;
            }

            if (ptr->countdownList[0]->isDeath()) {
                Basic_Atk(ptr);
            } else {
                Enchance_Basic_Atk(ptr);
            }
        };
        ptr->addUltCondition([ptr,AGptr]() -> bool {
            if (ptr->countdownList[0]->isDeath() && 
                (ptr->countdownList[0]->Atv_stats->atv > ptr->Atv_stats->atv && 
                (ptr->Atv_stats->atv != ptr->Atv_stats->Max_atv))) return false;
            if (ptr->memospriteList[0]->Atv_stats->atv == 0 || ptr->Atv_stats->atv == 0) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,AGptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"AG Ult",
            [ptr,AGptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->memospriteList[0]->isDeath()) Summon(ptr);

                if (ptr->countdownList[0]->isDeath()) 
                buffSingle(AGptr,{{Stats::SPD_P, AType::None, 15.0 * ptr->memospriteList[0]->Stack["Brewed_by_Tears"]}});
                
                Action_forward(ptr->Atv_stats.get(), 100);
                ptr->countdownList[0]->summon();
                double BuffValue = calculateSpeedForBuff(ptr, 360) + 
                calculateSpeedForBuff(ptr->memospriteList[0].get(), 720);

                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP, BuffValue - ptr->Buff_note["Aglaea_A2"]}});
                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::None, BuffValue - ptr->Buff_note["Aglaea_A2"]}});
                ptr->Buff_note["Aglaea_A2"] =  BuffValue;
                if (ptr->Print) CharCmd::printUltStart("Aglaea");
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            ptr->Stats_type[Stats::DEF_P][AType::None] += 12.5;
            ptr->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Stats_each_element[Stats::DMG][ElementType::Lightning][AType::None] += 22.4;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            if (ptr->Technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"AG Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Increase_energy(ptr, 30);
                    Summon(ptr);
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 20),
                    DmgSrc(DmgSrcType::ATK, 100, 20),
                    DmgSrc(DmgSrcType::ATK, 100, 20)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,AGptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Name == "Garmentmaker") {
                if (act->Attacker->Stack["Brewed_by_Tears"] < 6) {
                    buffSingle(act->Attacker,{{Stats::FLAT_SPD, AType::None, 55.0}});
                    act->Attacker->Stack["Brewed_by_Tears"]++;
                    if (!ptr->countdownList[0]->isDeath()) {
                        buffSingle(AGptr,{{Stats::SPD_P, AType::None, 15.0}});
                    }
                }
            }
            if (act->Attacker->isSameName("Aglaea")) {
                if (debuffApply(ptr,enemyUnit[Main_Enemy_num].get(),"Seam_Stitch")) {
                    if (ptr->Eidolon >= 1) {
                        debuffSingle(enemyUnit[Main_Enemy_num].get(),{{Stats::VUL, AType::None, 15}});
                    }
                }
            }
            if (act->Attacker->Atv_stats->num == ptr->Atv_stats->num) {
                shared_ptr<AllyAttackAction> data_Additional = 
                make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"AG AddDmg");
                data_Additional->addDamageIns(DmgSrc(DmgSrcType::ATK,30));
                Attack(data_Additional);
                if (ptr->Eidolon >= 1) {
                    Increase_energy(ptr, 20);
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->Eidolon >= 2) {
                if (act->Attacker->Atv_stats->Name == "Aglaea" || act->Attacker->Atv_stats->Name == "Garmentmaker") {
                    buffStackChar(ptr,{{Stats::DEF_SHRED,AType::None,14}},1,3,"Aglaea_E2");
                } else {
                    buffResetStack(ptr,{{Stats::DEF_SHRED,AType::None,14}},"Aglaea_E2");
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyBuffAction> &act) {
            if (ptr->Eidolon >= 2) {
                if (act->Attacker->Atv_stats->Name == "Aglaea" || act->Attacker->Atv_stats->Name == "Garmentmaker") {
                    buffStackChar(ptr,{{Stats::DEF_SHRED,AType::None,14}},1,3,"Aglaea_E2");
                } else {
                    buffResetStack(ptr,{{Stats::DEF_SHRED,AType::None,14}},"Aglaea_E2");
                }
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,AGptr](AllyUnit *target, Stats StatsType) {
            if (target->Atv_stats->Name != "Aglaea") return;
            if (ptr->countdownList[0]->isDeath()) return;
            if (StatsType == Stats::FLAT_SPD||StatsType == Stats::SPD_P) {
                // adjust
                double BuffValue = calculateSpeedForBuff(ptr, 360) + 
                calculateSpeedForBuff(ptr->memospriteList[0].get(), 720);

                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP, BuffValue - ptr->Buff_note["Aglaea_A2"]}});
                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::None, BuffValue - ptr->Buff_note["Aglaea_A2"]}});
                ptr->Buff_note["Aglaea_A2"] =  BuffValue;
                return;
            }
        }));

        
        ptr->memospriteList[0]->Turn_func = [ptr,AGptr](){
        
            Memo_Skill(ptr);
            
        };

        ptr->countdownList[0]->Turn_func = [ptr,AGptr](){
            buffSingle(AGptr,{{Stats::SPD_P, AType::None, -15.0 * ptr->memospriteList[0]->Stack["Brewed_by_Tears"]}});
            
            ptr->countdownList[0]->death();
            
            buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP,-ptr->Buff_note["Aglaea_A2"]}});
            buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::None,-ptr->Buff_note["Aglaea_A2"]}});
    
            ptr->Buff_note["Aglaea_A2"] = 0;
            ptr->memospriteList[0]->death(); 
            double temp =0;
            if(ptr->memospriteList[0]->Stack["Brewed_by_Tears"]>1){
                temp = ptr->memospriteList[0]->Stack["Brewed_by_Tears"]-1;
            }
            buffSingle(ptr->memospriteList[0].get(),{{Stats::FLAT_SPD, AType::None, -55.0 * temp}});
            ptr->memospriteList[0]->Stack["Brewed_by_Tears"] = 1;
            Increase_energy(ptr,20);
    
            if(ptr->Print)CharCmd::printUltEnd("Aglaea");
        };


    }
    



    void Enchance_Basic_Atk(CharUnit *ptr){
       
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"AG Joint",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,200,10),
            DmgSrc(DmgSrcType::ATK,90,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,200,10),
            DmgSrc(DmgSrcType::ATK,90,5)
        );
        act->setJoint();
        act->switchAttacker.push_back(SwitchAtk(1,1));
        act->addToActionBar();
    }
    void Basic_Atk(CharUnit *ptr){
        
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"AG BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        Skill_point(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"AG Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            if(ptr->memospriteList[0]->isDeath()){
                Summon(ptr);
                act->Turn_reset=false;
            }
        });
        act->addBuffSingleTarget(ptr);
        act->addActionType(AType::Summon);
        act->addToActionBar();
    }
    void Summon(CharUnit *ptr){
        ptr->getMemosprite()->summon(100);
        Action_forward(ptr->memospriteList[0]->Atv_stats.get(),100);
    }
    

    
    void Memo_Skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Blast,"AG Memo Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,110,10),
            DmgSrc(DmgSrcType::ATK,65,5)
        );
        act->addAttackType(AType::Summon);
        act->addToActionBar();
    }
}