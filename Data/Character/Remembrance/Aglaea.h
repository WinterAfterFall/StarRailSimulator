
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
        Ally *ptr = SetAllyBasicStats(102,350,350,E,ET_LN,"Remembrance","Aglaea",TYPE_STD);
        SubUnit *AGptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1242,699,485);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,66,35,ET_LN,"Garmentmaker",TYPE_STD);
        SetCountdownStats(ptr,"Supreme_Stance");

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);




        //func
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Atv_stats->baseSpeed == -1) {
                Skill(ptr);
                return;
            }

            if (ptr->Countdown_ptr[0]->Atv_stats->baseSpeed != -1) {
                Enchance_Basic_Atk(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        ptr->addUltCondition([ptr,AGptr]() -> bool {
            if (ptr->Countdown_ptr[0]->Atv_stats->baseSpeed != -1 && 
                (ptr->Countdown_ptr[0]->Atv_stats->atv > ptr->Sub_Unit_ptr[0]->Atv_stats->atv && 
                (ptr->Sub_Unit_ptr[0]->Atv_stats->atv != ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv))) return false;
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->atv == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,AGptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_SINGLE,"AG Ult",
            [ptr,AGptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed == -1) Summon(ptr);

                if (ptr->Countdown_ptr[0]->Atv_stats->baseSpeed == -1) 
                AGptr->buffSingle({{ST_SPD, ST_SPD_P, 15.0 * ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]}});
                
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                ptr->Countdown_ptr[0]->resetATV(100);
                double BuffValue = calculateSpeedForBuff(ptr->Sub_Unit_ptr[0].get(), 360) + 
                calculateSpeedForBuff(ptr->Sub_Unit_ptr[1].get(), 720);

                ptr->buffAlly({{ST_FLAT_ATK, AT_TEMP, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->buffAlly({{ST_FLAT_ATK, AT_NONE, BuffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Aglaea_A2"] =  BuffValue;
                if (ptr->Print) CharCmd::printUltStart("Aglaea");
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 12.5;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ET_LN][AT_NONE] += 22.4;
        }));


        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"][AT_NONE] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr]() {
            if (ptr->Technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(ActionType::Technique,ptr->getSubUnit(),TT_AOE,"AG Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Increase_energy(ptr, 30);
                    ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = ptr->Sub_Unit_ptr[0]->Atv_stats->baseSpeed * 0.35;
                    Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    resetTurn(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
                    Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(), 100);
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
            if (act->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                if (act->Attacker->Stack["Brewed_by_Tears"] < 6) {
                    act->Attacker->buffSingle({{ST_SPD, ST_FLAT_SPD, 55.0}});
                    act->Attacker->Stack["Brewed_by_Tears"]++;
                    if (ptr->Countdown_ptr[0]->Atv_stats->baseSpeed != -1) {
                        AGptr->buffSingle({{ST_SPD, ST_SPD_P, 15.0}});
                    }
                }
            }
            if (act->Attacker->isSameUnitName("Aglaea")) {
                if (Enemy_unit[Main_Enemy_num]->debuffApply(ptr->getSubUnit(),"Seam_Stitch")) {
                    if (ptr->Eidolon >= 1) {
                        Enemy_unit[Main_Enemy_num]->debuffSingle({{ST_VUL, AT_NONE, 15}});
                    }
                }
            }
            if (act->Attacker->Atv_stats->num == ptr->Sub_Unit_ptr[0]->Atv_stats->num) {
                shared_ptr<AllyAttackAction> data_Additional = 
                make_shared<AllyAttackAction>(ActionType::Addtional,ptr->getSubUnit(),TT_SINGLE,"AG AddDmg");
                data_Additional->addDamageIns(DmgSrc(DmgSrcType::ATK,30));
                Attack(data_Additional);
                if (ptr->Eidolon >= 1) {
                    Increase_energy(ptr, 20);
                }
            }
        }));

        Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->Eidolon >= 2) {
                if (act->Attacker->Atv_stats->Unit_Name == "Aglaea" || act->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    ptr->buffStackAlly({{ST_DEF_SHRED,AT_NONE,14}},1,3,"Aglaea_E2");
                } else {
                    ptr->buffResetStack({{ST_DEF_SHRED,AT_NONE,14}},"Aglaea_E2");
                }
            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,AGptr](shared_ptr<AllyBuffAction> &act) {
            if (ptr->Eidolon >= 2) {
                if (act->Attacker->Atv_stats->Unit_Name == "Aglaea" || act->Attacker->Atv_stats->Unit_Name == "Garmentmaker") {
                    ptr->buffStackAlly({{ST_DEF_SHRED,AT_NONE,14}},1,3,"Aglaea_E2");
                } else {
                    ptr->buffResetStack({{ST_DEF_SHRED,AT_NONE,14}},"Aglaea_E2");
                }
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,AGptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Aglaea") return;
            if (ptr->Countdown_ptr[0]->Atv_stats->baseSpeed == -1) return;
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
            AGptr->buffSingle({{ST_SPD, ST_SPD_P, -15.0 * ptr->Sub_Unit_ptr[1]->Stack["Brewed_by_Tears"]}});
            
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
       
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_BLAST,"AG Joint",
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
    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"AG BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"AG Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                Summon(ptr);
                act->Turn_reset=false;
            }
        });
        act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
        act->addActionType(ActionType::Summon);
        act->addToActionBar();
    }
    void Summon(Ally *ptr){
        ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = ptr->Sub_Unit_ptr[0]->Atv_stats->baseSpeed*0.35;
        Update_Max_atv(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        resetTurn(ptr->Sub_Unit_ptr[1]->Atv_stats.get());
        Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
    }
    

    
    void Memo_Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_BLAST,"AG Memo Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,110,10),
            DmgSrc(DmgSrcType::ATK,65,5)
        );
        act->addActionType(ActionType::Summon);
        act->addToActionBar();
    }

    
    
    

    


}
#endif