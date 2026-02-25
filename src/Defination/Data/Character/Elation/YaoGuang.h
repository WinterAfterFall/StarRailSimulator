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
                punchline = 20;
                ++(turn->turnCnt);
                CharCmd::printText("Aha Instant");
                for(TriggerByYourSelf_Func &e : ElationSkill_List){
                    e.Call();
                }
                for(auto &each : charList){
                    if(each->path[0] == Path::Elation)buffSingle(each,{{Stats::CertifiedBanger,AType::None,1.0*punchline}},"CB Buff " + to_string(aha->turnCnt),2);
                }
                CBcheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,punchline});
                punchline = oldPL;
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        ElationSkill_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"YG Ult")){
                buffSingle(ally,{{Stats::RESPEN,AType::None,20}});
            }
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Stats_type[Stats::Elation][AType::None] += 10;
            ptr->Atv_stats->flatSpeed += 9;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"YG Skill")){
                buffAllAlly({
                        {Stats::Elation,AType::None,-ptr->getBuffNote("YG Skill")},
                        {Stats::Elation,AType::TEMP,-ptr->getBuffNote("YG Skill")}
                });
                ptr->setBuffNote("YG Skill",0);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"YG Ult")){
                buffSingle(ally,{{Stats::RESPEN,AType::None,20}});
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


    }
}
