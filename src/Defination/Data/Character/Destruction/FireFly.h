#include "../include.h"

namespace FireFly{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Skill_func(CharUnit *ptr);
    void Enchance_Skill_func(CharUnit *ptr);

    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats( 104, 240, 240, E, ElementType::Fire, Path::Destruction, "FireFly", UnitType::Standard);
        AllyUnit *FFptr = ptr;
        ptr->SetAllyBaseStats( 815, 524, 776);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);
        

        ptr->Turn_func = [ptr] (){
            if(ptr->countdownList[0]->isDeath()){
                Skill_func(ptr);
            }else {
                Enchance_Skill_func(ptr);
            }
        };
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::BE][AType::None] += 37.3;
            ptr->Stats_type[Stats::RES][AType::None] += 18;
            ptr->Atv_stats->flatSpeed += 5;

            // relic

            // substats

            // eidolon
            if (ptr->Eidolon >= 1) {
            ptr->Stats_type[Stats::DEF_SHRED][AType::None] += 15;
            }
            if (ptr->Eidolon >= 2) {
            ptr->Stack["FireFly_E2"] = 2;
            }
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr,FFptr]() {
            if (!ultUseCheck(ptr)) return;
            buffSingle(FFptr,
                {
                    {Stats::FLAT_SPD,AType::None,60},
                    {Stats::BREAK_EFF,AType::None,50},
                    {Stats::VUL,AType::None,20},
                });
            Action_forward(FFptr->Atv_stats.get(), 100);
            ptr->countdownList[0]->summon();
            if (ptr->Print)CharCmd::printUltStart("FireFly");
            }
        ));
        

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,FFptr](AllyUnit *target, Stats StatsType) {
            if (target->Atv_stats->Name != "FireFly") return;
            if (StatsType == Stats::ATK_P || StatsType == Stats::FLAT_ATK) {
            double temp = 0;
            temp = floor(((ptr->Stats_type[Stats::ATK_P][AType::None] / 100 * ptr->baseAtk + ptr->baseAtk) + ptr->Stats_type[Stats::FLAT_ATK][AType::None] - 1800) / 100) * 0.8;
            if (ptr->Buff_note["FireFly_ModuleY"] <= 0)temp = 0;
            buffSingle(FFptr,
                {
                    {Stats::BE,AType::TEMP,temp - FFptr->Buff_note["FireFly_ModuleY"]},
                    {Stats::BE,AType::None,temp - FFptr->Buff_note["FireFly_ModuleY"]}
                });
            ptr->Buff_note["FireFly_ModuleY"] = temp;
                
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr] (Enemy *target, AllyUnit *Breaker) {
            if (ptr->Eidolon >= 2 && ptr->Atv_stats->num == Breaker->Atv_stats->num && !ptr->countdownList[0]->isDeath()) {
                ptr->Stack["FireFly_E2"]++;
            }
            }
        ));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"FF Tech",
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
            allEventAdjustStats(ptr, Stats::FLAT_ATK);
        }));
        
        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr]( shared_ptr<AllyAttackAction> &act ) {

            if (ptr->Eidolon >= 2 && ptr->Stack["FireFly_E2"] > 0 && !ptr->countdownList[0]->isDeath()) {
            ptr->Stack["FireFly_E2"]--;
            Action_forward(ptr->Atv_stats.get(), 100);
            }
            if (act->isSameName("FireFly")) {
            if (ptr->Stats_type[Stats::BE][AType::None] >= 360) {
                Superbreak_trigger(act, 50,"");
            } else if (ptr->Stats_type[Stats::BE][AType::None] >= 200) {
                Superbreak_trigger(act, 35,"");
            }
            }
        }));
        
        

        //countdown
        SetCountdownStats(ptr,70, "Combustion_state");
        ptr->countdownList[0]->Turn_func = [ptr,FFptr](){


            if(ptr->Print)CharCmd::printUltEnd("FireFly");
            buffSingle(FFptr,
                {
                    {Stats::FLAT_SPD,AType::None,-60},
                    {Stats::BREAK_EFF,AType::None,-50},
                    {Stats::VUL,AType::None,-20},
                });
            ptr->countdownList[0]->death();
        };
    }
    
    void Skill_func(CharUnit *ptr){   
        Skill_point(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Single,"FF Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,60,0);
            Attack(act);
            Action_forward(ptr->Atv_stats.get(), 25);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,8));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,60,12));
        act->addToActionBar();


    }
    void Enchance_Skill_func(CharUnit *ptr){
        if(ptr->Eidolon<1)Skill_point(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"FF ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            double skill_dmg = 0;
            if(ptr->Stats_type[Stats::BE][AType::None]>=360){
                skill_dmg = 272;
            }else{
                skill_dmg = 200 + (ptr->Stats_type[Stats::BE][AType::None])*0.2;
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
