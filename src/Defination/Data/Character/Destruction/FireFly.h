#include "../include.h"

namespace FireFly{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Skill_func(CharUnit *ptr);
    void Enchance_Skill_func(CharUnit *ptr);
    vector<BuffClass> combustionBuff(CharUnit *ptr, double sign);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats( 104, 240, 240, E, ElementType::Fire, Path::Destruction, "FireFly", UnitType::Standard);
        AllyUnit *FFptr = ptr;
        ptr->SetAllyBaseStats( 814, 523, 776);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
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
            // E2: start with 2 free extra turns (assume 2 kills per fight)
            if (ptr->Eidolon >= 2) {
            ptr->stack["FireFly_E2"] = 2;
            }
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, ptr, [ptr,FFptr]() {
            buffSingle(FFptr,combustionBuff(ptr,1));
            ptr->setStack("FireFly A2 delay",0);
            Action_forward(FFptr->Atv_stats.get(), 100);
            ptr->countdownList[0]->summon();
            if (ptr->Print)CharCmd::printUltStart("FireFly");
            }
        ));

        // A6: every 10 ATK above 1800 -> BE +0.8%
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,FFptr](AllyUnit *target, Stats StatsType) {
            if (target->Atv_stats->Name != "FireFly") return;
            if (StatsType == Stats::ATK_P || StatsType == Stats::FLAT_ATK) {
            double temp = 0;
            temp = floor(((ptr->Stats_type[Stats::ATK_P][AType::None] / 100 * ptr->baseAtk + ptr->baseAtk) + ptr->Stats_type[Stats::FLAT_ATK][AType::None] - 1800) / 10) * 0.8;
            if (temp <= 0)temp = 0;
            buffSingle(FFptr,
                {
                    {Stats::BE,AType::TEMP,temp - FFptr->buffNote["FireFly_ModuleY"]},
                    {Stats::BE,AType::None,temp - FFptr->buffNote["FireFly_ModuleY"]}
                });
            ptr->buffNote["FireFly_ModuleY"] = temp;

            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr] (Enemy *target, AllyUnit *Breaker) {
            if (ptr->Atv_stats->num != Breaker->Atv_stats->num || ptr->countdownList[0]->isDeath()) return;
            if (ptr->Eidolon >= 2) {
                ptr->stack["FireFly_E2"]++;
            }
            // A2: Weakness Break during Combustion delays the countdown by 10% (max 3 per Combustion)
            if (ptr->getStack("FireFly A2 delay") < 3) {
                ptr->addStack("FireFly A2 delay",1);
                Action_forward(ptr->countdownList[0]->Atv_stats.get(), -10);
            }
            }
        ));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (ptr->Technique == 1) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"FF Tech",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for(auto &each : act->targetList){
                    weaknessApply(ptr,each,{ElementType::Fire},"FireFly Weakness",2);
                }
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
            // Talent: energy below 50% at battle start -> set to 50%
            if (ptr->Current_energy < ptr->Max_energy / 2) ptr->Current_energy = ptr->Max_energy / 2;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->isSameUnit(ptr)) ptr->setBuffCheck("FireFly_E2_used",0);
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr]( shared_ptr<AllyAttackAction> &act ) {
            if (!act->isSameAction(ptr,AType::SKILL)) return;
            if (ptr->countdownList[0]->isDeath()) return;
            // E2: extra turn after Enhanced Skill kills/breaks, once per turn
            if (ptr->Eidolon >= 2 && ptr->stack["FireFly_E2"] > 0 && !ptr->getBuffCheck("FireFly_E2_used")) {
            ptr->stack["FireFly_E2"]--;
            ptr->setBuffCheck("FireFly_E2_used",1);
            Action_forward(ptr->Atv_stats.get(), 100);
            }
            // A4: during Combustion, BE >= 150%/300% -> Super Break 100%/150%
            if (ptr->Stats_type[Stats::BE][AType::None] >= 300) {
                Superbreak_trigger(act, 150,"");
            } else if (ptr->Stats_type[Stats::BE][AType::None] >= 150) {
                Superbreak_trigger(act, 100,"");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            isDebuffEnd(enemy,"FireFly Weakness");
        }));



        //countdown
        SetCountdownStats(ptr,70, "Combustion_state");
        ptr->countdownList[0]->Turn_func = [ptr,FFptr](){


            if(ptr->Print)CharCmd::printUltEnd("FireFly");
            buffSingle(FFptr,combustionBuff(ptr,-1));
            ptr->countdownList[0]->death();
        };
    }

    // Complete Combustion: SPD +60 · Break Efficiency +50% · Break DMG +20% · A2 BE +25%
    // E1 Enhanced Skill ignores 15% DEF · E6 RES PEN +20% + Break Efficiency +50%
    vector<BuffClass> combustionBuff(CharUnit *ptr, double sign){
        vector<BuffClass> buff = {
            {Stats::FLAT_SPD,AType::None,60*sign},
            {Stats::BREAK_EFF,AType::None,50*sign},
            {Stats::VUL,AType::Break,20*sign},
            {Stats::BE,AType::None,25*sign},
        };
        if (ptr->Eidolon >= 1) buff.push_back({Stats::DEF_SHRED,AType::SKILL,15*sign});
        if (ptr->Eidolon >= 4) buff.push_back({Stats::RES,AType::None,50*sign});
        if (ptr->Eidolon >= 6) {
            buff.push_back({Stats::RESPEN,AType::None,20*sign});
            buff.push_back({Stats::BREAK_EFF,AType::None,50*sign});
        }
        return buff;
    }

    void Skill_func(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act =
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Single,"FF Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,60,0);
            Attack(act);
            Action_forward(ptr->Atv_stats.get(), 25);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,80,8));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,120,12));
        act->addToActionBar();


    }
    void Enchance_Skill_func(CharUnit *ptr){
        if(ptr->Eidolon<1)genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act =
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"FF ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            double skill_dmg = 0;
            if(ptr->Stats_type[Stats::BE][AType::None]>=360){
                skill_dmg = 272;
            }else{
                skill_dmg = 200 + (ptr->Stats_type[Stats::BE][AType::None])*0.2;
            }

            // hit split 15/15/15/15/40 · adjacent = half of main
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skill_dmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skill_dmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.4*skill_dmg,12),DmgSrc(DmgSrcType::ATK,0.4*0.5*skill_dmg,6));

            for(auto &each : act->targetList){
                weaknessApply(ptr,each,{ElementType::Fire},"FireFly Weakness",2);
            }
            Attack(act);
        });
        act->addToActionBar();
    }
}
