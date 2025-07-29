
#include "../include.h"

namespace Gallagher{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);



    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(98,110,110,E,ElementType::Fire,"Abundance","Gallagher",TYPE_STD);
        ptr->SetAllyBaseStats(1305,529,441);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Atv_stats->turnCnt % 8 == 1) {
                Skill_func(ptr);
            } else {
                if (ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                    Enchance_Basic_Atk(ptr);
                } else {
                    Basic_Atk(ptr);
                }
            }
        };
        Ultimate_List.push_back({PRIORITY_DEBUFF, [ptr,Charptr = ptr->Sub_Unit_ptr[0].get()]() {
            if (phaseStatus == PhaseStatus::BeforeTurn || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0 || !ultUseCheck(ptr)) return;
            

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,Charptr,"Aoe","Gall Ult",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 1;
                    debuffAllEnemyApply({{Stats::VUL,AType::Break,13.2}},Charptr,"Besotted");  
                    if (ptr->Eidolon >= 4) {
                        extendDebuffAll("Besotted", 3);
                    } else {
                        extendDebuffAll("Besotted", 2);
                    }
                    Attack(act);
                });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,165,20),
                DmgSrc(DmgSrcType::ATK,165,20),
                DmgSrc(DmgSrcType::ATK,165,20)
            );

            act->addToActionBar();
            if(!actionBarUse)Deal_damage();
            if (ptr->Print) CharCmd::printUltStart("Gallagher");
        }});

        Reset_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 18;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BREAK_EFF][AType::None] += 20;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 20;
            }
        }});

        After_turn_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy * focusUnit = turn->canCastToEnemy();
            if(!focusUnit)return;
            if (focusUnit->isDebuffEnd("Besotted")) {
                focusUnit->debuffSingle({{Stats::VUL, AType::Break, -13.2}});
            }
            if (focusUnit->isDebuffEnd("Nectar_Blitz")) {
                focusUnit->atkPercent += 16;
            }
        }});


        Start_game_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Eidolon >= 1) {
                Increase_energy(ptr, 20);
            }
        }});

        When_Combat_List.push_back({PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr->getSubUnit()]() {
            double temp = calculateBreakEffectForBuff(ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            Charptr->buffSingle({{Stats::HEALING_OUT,AType::None,temp - Charptr->getBuffNote("Novel Concoction")}});
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp;
            if (ptr->Technique) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,Charptr,"Aoe","Gall Tech",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    debuffAllEnemyApply({{Stats::VUL, AType::Break, 13.2}},Charptr,"Besotted",2);
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }});

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_HEAL, [ptr](shared_ptr<AllyAttackAction> &act) {
            
            if(act->isSameAttack("Gallagher",AType::BA)&&act->Attacker->Buff_check["Gallagher_enchance_basic_atk"] == 1){
                ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 0;
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;
                        
                    }
                }
                ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::CONST,707.0*cnt));
            } else {
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;           
                    }
                }
                ptr->getSubUnit()->RestoreHP(act->Attacker,HealSrc(HealSrcType::CONST,707.0*cnt));
            }
        }));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](SubUnit* Target, Stats StatsType) {
            if(StatsType!=Stats::BE||!Target->isSameUnitName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->buffSingle({{Stats::HEALING_OUT,AType::None,temp - ptr->getSubUnit()->Buff_note["Novel Concoction"]}});
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp;
        }));

        

        //substats

        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Gall BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addToActionBar();
    }
    void Enchance_Basic_Atk(Ally *ptr){
       shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Gall EBA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            for(Enemy* &target : act->targetList){
                target->debuffApply(act->Attacker,"Nectar_Blitz");
                target->atkPercent -= 16;
                target->extendDebuff("Nectar_Blitz",2);
            }
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,62.5,7.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,37.5,4.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,150,18));
        act->addToActionBar();

    }
    void Skill_func(Ally *ptr){

        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Gall Skill",
        [ptr](shared_ptr<AllyBuffAction> act){
            ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::CONST,1768),HealSrc(),HealSrc());
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
}