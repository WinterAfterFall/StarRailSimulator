
#include "../include.h"

namespace Gallagher{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Enchance_Basic_Atk(CharUnit *ptr);
    void Skill_func(CharUnit *ptr);



    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(98,110,110,E,ElementType::Fire,Path::Abundance,"Gallagher",UnitType::Standard);
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
        
        ptr->Turn_func = [ptr]() {
            if (ptr->Atv_stats->turnCnt % 8 == 1) {
                Skill_func(ptr);
            } else {
                if (ptr->Buff_check["Gallagher_enchance_basic_atk"] == 1) {
                    Enchance_Basic_Atk(ptr);
                } else {
                    Basic_Atk(ptr);
                }
            }
        };
        Ultimate_List.push_back({PRIORITY_DEBUFF, [ptr,Charptr = ptr]() {
            if (phaseStatus == PhaseStatus::BeforeTurn || ptr->Atv_stats->atv == 0 || !ultUseCheck(ptr)) return;
            

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,Charptr,TraceType::Aoe,"Gall Ult",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    Action_forward(ptr->Atv_stats.get(), 100);
                    ptr->Buff_check["Gallagher_enchance_basic_atk"] = 1;
                    debuffAllEnemyApply(Charptr,{{Stats::VUL,AType::Break,13.2}},"Besotted");  
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
            ptr->Stats_type[Stats::BE][AType::None] += 13.3;
            ptr->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Stats_type[Stats::RES][AType::None] += 18;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Stats_type[Stats::BREAK_EFF][AType::None] += 20;
                ptr->Stats_type[Stats::BE][AType::None] += 20;
            }
        }});

        After_turn_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy * focusUnit = turn->canCastToEnemy();
            if(!focusUnit)return;
            if (isDebuffEnd(focusUnit,"Besotted")) {
                debuffSingle(focusUnit,{{Stats::VUL, AType::Break, -13.2}});
            }
            if (isDebuffEnd(focusUnit,"Nectar_Blitz")) {
                focusUnit->atkPercent += 16;
            }
        }});


        Start_game_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Eidolon >= 1) {
                Increase_energy(ptr, 20);
            }
        }});

        WhenOnField_List.push_back({PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr]() {
            double temp = calculateBreakEffectForBuff(ptr,50);
            if(temp>75)temp = 75;
            buffSingle(Charptr,{{Stats::HEALING_OUT,AType::None,temp - Charptr->getBuffNote("Novel Concoction")}});
            ptr->Buff_note["Novel Concoction"] = temp;
            if (ptr->Technique) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,Charptr,TraceType::Aoe,"Gall Tech",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    debuffAllEnemyApply(Charptr,{{Stats::VUL, AType::Break, 13.2}},"Besotted",2);
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
            
            if(act->isSameAction("Gallagher",AType::BA)&&act->Attacker->Buff_check["Gallagher_enchance_basic_atk"] == 1){
                ptr->Buff_check["Gallagher_enchance_basic_atk"] = 0;
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;
                        
                    }
                }
                ptr->RestoreHP(HealSrc(HealSrcType::CONST,707.0*cnt));
            } else {
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;           
                    }
                }
                ptr->RestoreHP(act->Attacker,HealSrc(HealSrcType::CONST,707.0*cnt));
            }
        }));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](AllyUnit* Target, Stats StatsType) {
            if(StatsType!=Stats::BE||!Target->isSameName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr,50);
            if(temp>75)temp = 75;
            buffSingle(ptr,{{Stats::HEALING_OUT,AType::None,temp - ptr->Buff_note["Novel Concoction"]}});
            ptr->Buff_note["Novel Concoction"] = temp;
        }));

        

        //substats

        
    }



    void Basic_Atk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Gall BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addToActionBar();
    }
    void Enchance_Basic_Atk(CharUnit *ptr){
        genSkillPoint(ptr,1);
       shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Gall EBA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            for(Enemy* &target : act->targetList){
                debuffApply(act->Attacker,target,"Nectar_Blitz");
                target->atkPercent -= 16;
                extendDebuff(target,"Nectar_Blitz",2);
            }
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,62.5,7.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,37.5,4.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,150,18));
        act->addToActionBar();

    }
    void Skill_func(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"Gall Skill",
        [ptr](shared_ptr<AllyBuffAction> act){
            ptr->RestoreHP(HealSrc(HealSrcType::CONST,1768),HealSrc(),HealSrc());
            Increase_energy(ptr,30);
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr));
        act->addToActionBar();
    }
}