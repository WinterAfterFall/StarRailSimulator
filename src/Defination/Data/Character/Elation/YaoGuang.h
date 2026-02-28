#include "../include.h"

namespace YaoGuang{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,180,180,E,ElementType::Physical,Path::Elation,"Yao Guang",UnitType::Standard);
        ptr->SetAllyBaseStats(1242,465,654);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(200);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);


        elationCount++;
        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"YG BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                genPunchLine(ptr,3);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,90,10),
                DmgSrc(DmgSrcType::ATK,30,5)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"YG Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                genPunchLine(ptr,3);
                Increase_energy(ptr,30);
                if(isHaveToAddBuff(ptr,"YG Skill",3)){
                    double buff = calculateElationForBuff(ptr,20);

                    buffAllAlly({
                        {Stats::Elation,AType::None,buff - ptr->getBuffNote("YG Skill")},
                        {Stats::Elation,AType::TEMP,buff - ptr->getBuffNote("YG Skill")}
                    });
                    if(ptr->Eidolon>=2)
                    buffAllAlly({
                        {Stats::SPD_P,AType::None,12},
                        {Stats::Elation,AType::None,16}
                    });

                    
                    ptr->setBuffNote("YG Skill",buff);

                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
        };
        #pragma endregion
        ptr->Turn_func = [ptr,BA,Skill]() {

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"YG Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart(ptr->getName());

                genPunchLine(ptr,5);

                buffAllAlly({
                    {Stats::RESPEN,AType::None,20}
                },"YG Ult",3);

                double oldPL = punchline;
                punchline = (ptr->Eidolon>=1)? 40 : 20;
                if(ptr->Eidolon>=4)
                buffAllAlly({
                    {Stats::MtprInc,AType::ElationSkill,50}
                });

                ++(turn->turnCnt);
                CharCmd::printText("Aha Instant");
                for(TriggerByYourSelf_Func &e : ElationSkill_List){
                    e.Call();
                }
                for(auto &each : charList){
                    if(each->path[0] == Path::Elation)buffSingle(each,{{Stats::CertifiedBanger,AType::None,1.0*punchline}},"CB Buff " + to_string(aha->turnCnt),2);
                }
                CBcheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,punchline});

                if(ptr->Eidolon>=4)
                buffAllAlly({
                    {Stats::MtprInc,AType::ElationSkill,-50}
                });
                punchline = oldPL;
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        ElationSkill_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::ElationSkill,ptr,TraceType::Aoe,"YG Elation",
            [ptr](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::None,16}},"Woe's Whisper",3);
                Increase_energy(ptr,5);    
                Attack(act);
                genSkillPoint(ptr,1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::Elation,100,20),
                DmgSrc(DmgSrcType::Elation,100,20),
                DmgSrc(DmgSrcType::Elation,100,20)
            );
            act->addEnemyBounce(
                DmgSrc(DmgSrcType::Elation,20,5),5
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Stats_type[Stats::CD][AType::None] += 60;
            ptr->Stats_type[Stats::Elation][AType::None] += 10+30;
            ptr->Atv_stats->flatSpeed += 9;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->Eidolon>=1)buffAllAlly({{Stats::DEF_SHRED,AType::ElationDMG,20}});
            if(ptr->Eidolon>=6){
                buffAllAlly({{Stats::Merrymake,AType::ElationDMG,25}});
                buffSingle(ptr,{{Stats::MtprInc,AType::ElationSkill,100}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"YG Skill")){
                buffAllAlly({
                        {Stats::Elation,AType::None,-ptr->getBuffNote("YG Skill")},
                        {Stats::Elation,AType::TEMP,-ptr->getBuffNote("YG Skill")}
                });
                ptr->setBuffNote("YG Skill",0);
                if(ptr->Eidolon>=2)
                buffAllAlly({
                    {Stats::SPD_P,AType::None,-12},
                    {Stats::Elation,AType::None,-16}
                });
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            Enemy *enemy = turn->canCastToEnemy();
            if(ally){
                if(isBuffEnd(ally,"YG Ult")){
                    buffSingle(ally,{{Stats::RESPEN,AType::None,20}});
                }
            }
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Woe's Whisper")){
                debuffSingle(enemy,{{Stats::VUL,AType::None,-16}});
            }

        }));

        

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(!ptr->Technique)return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"YG Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genPunchLine(ptr,3);
                Increase_energy(ptr,30);
                if(isHaveToAddBuff(ptr,"YG Skill",3)){
                    double buff = calculateElationForBuff(ptr,20);

                    buffAllAlly({
                        {Stats::Elation,AType::None,buff - ptr->getBuffNote("YG Skill")},
                        {Stats::Elation,AType::TEMP,buff - ptr->getBuffNote("YG Skill")}
                    });
                    
                    ptr->setBuffNote("YG Skill",buff);

                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            Deal_damage();
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            ptr->setBuffCheck("YG Talent SP check",0);
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *SP_maker, int SP) {
            if(SP<0)ptr->setBuffCheck("YG Talent SP check",1);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            
            if(ptr->Stats_type[Stats::CertifiedBanger][AType::None]<=0)return;
            shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(AType::ElationDMG,act->Attacker,TraceType::Single,"YG Talent");
            newAct->addDamageIns(DmgSrc(DmgSrcType::Elation,20));
            if(ptr->getBuffCheck("YG Talent SP check"))newAct->addDamageIns(DmgSrc(DmgSrcType::Elation,20));
            if(calculateElationOnStats(ptr)>calculateElationOnStats(act->Attacker))act->source = ptr;
            newAct->addAttackType(AType::Addtional);
            Attack(newAct);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* Target, Stats StatsType) {
            if(!Target->isSameName(ptr))return;
            if (StatsType == Stats::FLAT_SPD||StatsType == Stats::SPD_P) {
                double BuffValue = min(80.0,max(0.0,calculateSpeedOnStats(ptr) - 120));

                buffSingleChar(ptr,{{Stats::Elation, AType::None, BuffValue - ptr->Buff_note["YG A2"]}});
                ptr->Buff_note["YG A2"] =  BuffValue;
            }
        }));



    }
}
