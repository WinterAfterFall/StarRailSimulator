
#include "../include.h"

namespace Jade{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);


//temp
    void Jade_Fua(CharUnit *ptr);
    void Jade_Talent(CharUnit *ptr,int amount);
    void Fua(CharUnit *ptr);
    void Fua_Enchance(CharUnit *ptr);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(103,140,140,E,ElementType::Quantum,Path::Erudition,"Jade",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);

        // ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);
        // ptr->setSpeedRequire(140);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            
            if (allyPtr->getBuffCheck("Jade_Skill")) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Jade Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"] = 2;
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 22.4;

            // relic
            // substats
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Jade_Talent(ptr, Total_enemy);
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 50);
            if (ptr->Technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"Jade Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Jade_Talent(ptr, 15);
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->UnitName == turn->UnitName) {
                Jade_Talent(ptr, 3);
            }
            
            if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Jade_Skill")) {
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::SPD_P,AType::None,-30}});
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAttack("Jade",AType::Fua)) {
                Jade_Talent(ptr, 5);
                return;
            }
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"] == 0) return;
            if (act->Attacker->Atv_stats->StatsOwnerName != "Jade" && act->Attacker->Atv_stats->StatsOwnerName != chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->StatsOwnerName) return;

            int temp = act->targetList.size();
            if (ptr->Eidolon >= 1 && temp < 3) temp = 3;
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"] += temp;
            Jade_Fua(ptr);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *Killer){
            Jade_Talent(ptr, 1);
        }));
        



        
    }



    void Basic_Atk(CharUnit *ptr){
        
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"Jade BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(charUnit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),20);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,90,10),
            DmgSrc(DmgSrcType::ATK,30,5)
        );
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"Jade Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(charUnit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Jade_Skill",3)){
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::SPD_P,AType::None,30}});
            }
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();

    }


            
        

    void Jade_Fua(CharUnit *ptr){

        while(ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]>8){
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]-=8;
            if(ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]>0){
                Fua_Enchance(ptr);
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]--;             
            }else{
                Fua(ptr);
            }
        }
        Deal_damage();
    }
    void Fua(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Aoe,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->buffSingle({{Stats::DMG,AType::None,32}});
            Attack(act);
            if(ptr->Eidolon>=1)ptr->buffSingle({{Stats::DMG,AType::None,-32}});
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,48,4),
            DmgSrc(DmgSrcType::ATK,48,4),
            DmgSrc(DmgSrcType::ATK,48,4)
        );
        act->addToActionBar();
    }
    void Fua_Enchance(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Aoe,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->buffSingle({{Stats::DMG,AType::None,32}});
            Attack(act);
            if(ptr->Eidolon>=1)ptr->buffSingle({{Stats::DMG,AType::None,-32}});
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,120,6),
            DmgSrc(DmgSrcType::ATK,120,6),
            DmgSrc(DmgSrcType::ATK,120,6)
        );
        act->addToActionBar();
    }
    void Jade_Talent(CharUnit *ptr,int amount){
        ptr->buffStackSingle(
            {{Stats::ATK_P,AType::None,0.5},
            {Stats::CD,AType::None,2.4}},
            amount,50,"Pawned_Asset");
        if(ptr->Eidolon>=2&&ptr->Sub_Unit_ptr[0]->Stack["Pawned_Asset"]>=15&&ptr->isHaveToAddBuff("Jade_E2")){
            ptr->buffSingle({{Stats::CR,AType::None,18}});
        }

    }

}