
#ifndef Jade_H
#define Jade_H

#define F first
#define S second
#include "../Library.h"

namespace Jade{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


//temp
    void Jade_Fua(Ally *ptr);
    void Jade_Talent(Ally *ptr,int amount);
    void Fua(Ally *ptr);
    void Fua_Enchance(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,140,140,E,"Quantum","Erudition","Jade",TYPE_STD);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CR,ST_ATK_P,ST_DMG,ST_ATK_P);

        // ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_ATK_P);
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
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Jade Ult",
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
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Quantum"][AT_NONE] += 22.4;

            // relic
            // substats
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Jade_Talent(ptr, Total_enemy);
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 50);
            if (ptr->Technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(ActionType::Technique,ptr->getSubUnit(),TT_AOE,"Jade Tech",
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
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Char_Name == turn->Char_Name) {
                Jade_Talent(ptr, 3);
            }
            
            if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Jade_Skill")) {
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,-30}});
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAttack("Jade",AT_FUA)) {
                Jade_Talent(ptr, 5);
                return;
            }
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"] == 0) return;
            if (act->Attacker->Atv_stats->Unit_Name != "Jade" && act->Attacker->Atv_stats->Unit_Name != chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Unit_Name) return;

            int temp = act->targetList.size();
            if (ptr->Eidolon >= 1 && temp < 3) temp = 3;
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"] += temp;
            Jade_Fua(ptr);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer){
            Jade_Talent(ptr, 1);
        }));
        



        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_BLAST,"Jade BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,90,10),
            DmgSrc(DmgSrcType::ATK,30,5)
        );
        act->addToActionBar();
    }
    void Skill(Ally *ptr){
        
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Jade Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Jade_Skill",3)){
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,30}});
            }
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();

    }


            
        

    void Jade_Fua(Ally *ptr){

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
    void Fua(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_AOE,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,32}});
            Attack(act);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-32}});
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
    void Fua_Enchance(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_AOE,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,32}});
            Attack(act);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-32}});
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
    void Jade_Talent(Ally *ptr,int amount){
        ptr->getSubUnit()->buffStackSingle(
            {{ST_ATK_P,AT_NONE,0.5},
            {ST_CD,AT_NONE,2.4}},
            amount,50,"Pawned_Asset");
        if(ptr->Eidolon>=2&&ptr->Sub_Unit_ptr[0]->Stack["Pawned_Asset"]>=15&&ptr->getSubUnit()->isHaveToAddBuff("Jade_E2")){
            ptr->getSubUnit()->buffSingle({{ST_CR,AT_NONE,18}});
        }

    }





}
#endif