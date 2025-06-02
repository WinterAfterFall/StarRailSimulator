
#ifndef Gallagher_H
#define Gallagher_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Gallagher{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);



    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(98,110,110,E,"Fire","Abundance","Gallagher",TYPE_STD);
        ptr->SetAllyBaseStats(1305,529,441);

        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(ST_HEALING_OUT,ST_FLAT_SPD,ST_ATK_P,ST_EnergyRecharge);


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
            if (Ult_After_Turn == 0 || ptr->Sub_Unit_ptr[0]->Atv_stats->atv == 0 || !ultUseCheck(ptr)) return;
            

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Ult,Charptr,"Aoe","Gall Ult",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 1;
                    debuffAllEnemyApply({{ST_VUL,AT_TEMP,13.2}},Charptr,"Besotted");  
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
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 18;

            // relic

            // substats
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"][AT_NONE] += 20;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 20;
            }
        }});

        After_turn_List.push_back({PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy * focusUnit = turn->canCastToEnemy();
            if(!focusUnit)return;
            if (focusUnit->isDebuffEnd("Besotted")) {
                focusUnit->debuffSingle({{ST_VUL, "Break_dmg", -13.2}});
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
            Charptr->buffSingle({{ST_HEALING_OUT,AT_NONE,temp - Charptr->getBuffNote("Novel Concoction")}});
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp;
            if (ptr->Technique) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(ActionType::Technique,Charptr,"Aoe","Gall Tech",
                [ptr,Charptr](shared_ptr<AllyAttackAction> &act){
                    debuffAllEnemyApply({{ST_VUL, "Break_dmg", 13.2}},Charptr,"Besotted",2);
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
            
            if(act->isSameAttack("Gallagher",AT_BA)&&act->Attacker->Buff_check["Gallagher_enchance_basic_atk"] == 1){
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
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](SubUnit* Target, string StatsType) {
            if(StatsType!=ST_BE||!Target->isSameUnitName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr->getSubUnit(),50);
            if(temp>75)temp = 75;
            ptr->getSubUnit()->buffSingle({{ST_HEALING_OUT,AT_NONE,temp - ptr->getSubUnit()->Buff_note["Novel Concoction"]}});
            ptr->getSubUnit()->Buff_note["Novel Concoction"] = temp;
        }));

        

        //substats

        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Gall BA",
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
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Gall EBA",
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
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Gall Skill",
        [ptr](shared_ptr<AllyBuffAction> act){
            ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::CONST,1768),HealSrc(),HealSrc());
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
}
#endif
