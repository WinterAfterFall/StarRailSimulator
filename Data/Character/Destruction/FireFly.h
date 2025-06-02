#ifndef FireFly_H
#define FireFly_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace FireFly{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Skill_func(Ally *ptr);
    void Enchance_Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats( 104, 240, 240, E, ET_FIRE, "Destruction", "FireFly", TYPE_STD);
        SubUnit *FFptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats( 815, 524, 776);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_ATK_P,ST_BE);
        

        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr] (){
            if(ptr->Countdown_ptr[0]->Atv_stats->baseSpeed==-1){
                Skill_func(ptr);
            }else {
                Enchance_Skill_func(ptr);
            }
        };
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;

            // relic

            // substats

            // eidolon
            if (ptr->Eidolon >= 1) {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AT_NONE] += 15;
            }
            ptr->Countdown_ptr[0]->Atv_stats->baseSpeed = -1;
            if (ptr->Eidolon >= 2) {
            ptr->Sub_Unit_ptr[0]->Stack["FireFly_E2"] = 2;
            }
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr,FFptr]() {
            if (!ultUseCheck(ptr)) return;
            FFptr->buffSingle(
                {
                    {ST_SPD,ST_FLAT_SPD,60},
                    {ST_BREAK_EFF,AT_NONE,50},
                    {ST_VUL,AT_NONE,20},
                });
            Action_forward(FFptr->Atv_stats.get(), 100);
            ptr->Countdown_ptr[0]->resetATV(70);
            if (ptr->Print)CharCmd::printUltStart("FireFly");
            }
        ));
        

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,FFptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "FireFly") return;
            if (StatsType == "Atk%" || StatsType == "Flat_Atk") {
            double temp = 0;
            temp = floor(((ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] / 100 * ptr->Sub_Unit_ptr[0]->baseAtk + ptr->Sub_Unit_ptr[0]->baseAtk) + ptr->Sub_Unit_ptr[0]->Stats_type["Flat_Atk"][AT_NONE] - 1800) / 100) * 0.8;
            if (ptr->Sub_Unit_ptr[0]->Buff_note["FireFly_ModuleY"] <= 0)temp = 0;
            FFptr->buffSingle(
                {
                    {ST_BE,AT_TEMP,temp - FFptr->Buff_note["FireFly_ModuleY"]},
                    {ST_BE,AT_NONE,temp - FFptr->Buff_note["FireFly_ModuleY"]}
                });
            ptr->Sub_Unit_ptr[0]->Buff_note["FireFly_ModuleY"] = temp;
                
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr] (Enemy *target, SubUnit *Breaker) {
            if (ptr->Eidolon >= 2 && ptr->Sub_Unit_ptr[0]->Atv_stats->num == Breaker->Atv_stats->num && ptr->Countdown_ptr[0]->Atv_stats->baseSpeed == 70) {
                ptr->Sub_Unit_ptr[0]->Stack["FireFly_E2"]++;
            }
            }
        ));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Technique,ptr->getSubUnit(),"Aoe","FF Tech",
            [ptr](shared_ptr<AllyAttackAction> &act){
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            Deal_damage();
            }
        }));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            allEventAdjustStats(ptr->Sub_Unit_ptr[0].get(), ST_FLAT_ATK);
        }));
        
        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr]( shared_ptr<AllyAttackAction> &act ) {

            if (ptr->Eidolon >= 2 && ptr->Sub_Unit_ptr[0]->Stack["FireFly_E2"] > 0 && ptr->Countdown_ptr[0]->Atv_stats->baseSpeed == 70) {
            ptr->Sub_Unit_ptr[0]->Stack["FireFly_E2"]--;
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
            }
            if (act->isSameUnitName("FireFly")) {
            if (ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] >= 360) {
                Superbreak_trigger(act, 50,"");
            } else if (ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] >= 200) {
                Superbreak_trigger(act, 35,"");
            }
            }
        }));
        
        

        //countdown
        SetCountdownStats(ptr, "Combustion_state");
        ptr->Countdown_ptr[0]->Turn_func = [ptr,FFptr](){


            if(ptr->Print)CharCmd::printUltEnd("FireFly");
            FFptr->buffSingle(
                {
                    {ST_SPD,ST_FLAT_SPD,-60},
                    {ST_BREAK_EFF,AT_NONE,-50},
                    {ST_VUL,AT_NONE,-20},
                });
            ptr->Countdown_ptr[0]->resetATV(-1);
        };
    }
    
    void Skill_func(Ally *ptr){   
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"FF Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,60,0);
            Attack(act);
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 25);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,8));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,60,12));
        act->addToActionBar();


    }
    void Enchance_Skill_func(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BLAST,"FF ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            if(ptr->Eidolon<1)Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            double skill_dmg = 0;
            if(ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE]>=360){
                skill_dmg = 272;
            }else{
                skill_dmg = 200 + (ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE])*0.2;
            }

            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,4*skill_dmg,12),DmgSrc(DmgSrcType::ATK,2*skill_dmg,6));
            Attack(act);
        });
        act->addToActionBar();
    }
    




    
    
    
}
#endif
