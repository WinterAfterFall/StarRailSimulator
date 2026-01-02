#include "../include.h"

namespace Hanabi{
     void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,110,110,E,ElementType::Quantum,Path::Harmony,"Hanabi",UnitType::Standard);
        ptr->SetAllyBaseStats(1397,524,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        Max_sp+=3;
        if(ptr->Eidolon>=4)Max_sp++;
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        AllyUnit *hnb = ptr;
        Driver_num = hnb->Atv_stats->num;

        #pragma region Ability

        function<void()> BA = [ptr,hnb]() {
            Skill_point(hnb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Hnb BA",
            [hnb](shared_ptr<AllyAttackAction> &act){
                Increase_energy(hnb,30);
                Attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hnb]() {
            Skill_point(hnb,-1);
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"Hnb Skill",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                Increase_energy(hnb,30);
                double buff = (ptr->Eidolon>=6)? calculateCritdamForBuff(hnb,54) + 45 :calculateCritdamForBuff(hnb,24) + 45;

                chooseSubUnitBuff(hnb)->buffSingle({
                    {Stats::CD,AType::TEMP,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")}
                });
                chooseSubUnitBuff(hnb)->extendBuffTime("Hnb Skill",2);
                chooseSubUnitBuff(hnb)->setBuffNote("Hnb Skill",buff);
                
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            if(!each->getBuffCheck("Hnb Cipher"))continue;
                            each->buffSingle({
                                {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
                            });
                           each->setBuffNote("Hnb Skill",buff);
                        }   
                    }
                }
                Action_forward(chooseSubUnitBuff(hnb)->Atv_stats.get(),50);
            });
            act->addBuffSingleTarget(chooseSubUnitBuff(hnb));
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr, allyPtr = ptr,Skill,BA]() {
            Skill();
        };
        
        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(Max_sp-sp<3)return false;
            return true;
        });

        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(ptr->Light_cone.Name!="DDD"&&phaseStatus == PhaseStatus::BeforeTurn&&turn->isSameChar(chooseSubUnitBuff(hnb)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hnb]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"Hnb Ult",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                if(ptr->Eidolon>=4)Skill_point(hnb,5);
                else Skill_point(hnb,4);
                
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each : charUnit[i]->Sub_Unit_ptr){
                        if(each->isHaveToAddBuff("Hnb Cipher")){
                            each->buffSingle({{Stats::DMG,AType::None,10.0 * each->getStack("Hnb Talent")}});
                            if(ptr->Eidolon>=1){
                                each->buffSingle({{Stats::ATK_P,AType::None,40}});
                                each->extendBuffTime("Hnb Cipher",3);
                            }
                            else each->extendBuffTime("Hnb Cipher",2);
                        }
                    }   
                }

                if(ptr->Eidolon>=6){
                    double buff = calculateCritdamForBuff(hnb,54) + 45;
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",buff);
                        }   
                    }
                }

                
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::HP_P][AType::None] += 28;
            ptr->Stats_type[Stats::CD][AType::None] += 24;
            ptr->Stats_type[Stats::RES][AType::None] += 10;

            // relic

            // substats
            int qtCount = 0;

            for(int i=1;i<=Total_ally;i++){
                if(charUnit[i]->Element_type[0] ==ElementType::Quantum)
                    qtCount++;
            }

            double atkBuff = 20;
            if(qtCount == 2)atkBuff = 30;
            else if(qtCount >= 3)atkBuff = 45;
            for(int i=1;i<=Total_ally;i++){
                if(charUnit[i]->Element_type[0] ==ElementType::Quantum)
                    charUnit[i]->buffSingle({{Stats::ATK_P,AType::None,atkBuff}});
                else
                    charUnit[i]->buffSingle({{Stats::ATK_P,AType::None,15}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            if(ptr->Technique)Skill_point(hnb,3);
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            AllyUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Hnb Skill")){
                ally->buffSingle({
                    {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,-ally->getBuffNote("Hnb Skill")}
                });
                ally->setBuffNote("Hnb Skill",0);
                
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            AllyUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Hnb Cipher")){
                ally->buffSingle({{Stats::DMG,AType::None,-10.0 * ally->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)ally->buffSingle({{Stats::ATK_P,AType::None,-40}});
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            if(each->getBuffCheck("Hnb Skill"))continue;
                            each->buffSingle({
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
            if(isBuffEnd(ally,"Hnb Talent")){
                if(ally->getBuffCheck("Hnb Cipher"))
                    buffResetStack(ally,{{Stats::DMG,AType::None,16}},"Hnb Talent");
                else
                    buffResetStack(ally,{{Stats::DMG,AType::None,6}},"Hnb Talent");
                if(ptr->Eidolon>=2)buffResetStack(ally,{{Stats::DEF_SHRED,AType::None,8}},"Hnb E2");
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit* target) {
            if(target->isBuffGoneByDeath("Hnb Cipher")){
                target->buffSingle({{Stats::DMG,AType::None,-10.0 * target->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)target->buffSingle({{Stats::ATK_P,AType::None,-40}});
            }
            if(target->isBuffGoneByDeath("Hnb Talent")){
                if(target->getBuffCheck("Hnb Cipher"))
                    target->buffResetStack({{Stats::DMG,AType::None,16}},"Hnb Talent");
                else
                    target->buffResetStack({{Stats::DMG,AType::None,6}},"Hnb Talent");
                if(ptr->Eidolon>=2)target->buffResetStack({{Stats::DEF_SHRED,AType::None,8}},"Hnb E2");
            }
            if(target->isBuffGoneByDeath("Hnb Skill")){
                target->buffSingle({
                    {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,-target->getBuffNote("Hnb Skill")}
                });
                target->setBuffNote("Hnb Skill",0);


                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }

            }
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit *SP_maker, int SP) {
            if(SP>=0)return;
            for(int i=1;i<=Total_ally;i++){
                for(auto &each : charUnit[i]->Sub_Unit_ptr){
                    if(each->getBuffCheck("Hnb Cipher"))
                        each->buffStackSingle({{Stats::DMG,AType::None,16}},-SP,3,"Hnb Talent",2);
                    else 
                        each->buffStackSingle({{Stats::DMG,AType::None,6}},-SP,3,"Hnb Talent",2);
                    if(ptr->Eidolon>=2)each->buffStackSingle({{Stats::DEF_SHRED,AType::None,8}},-SP,3,"Hnb E2");
                }   
            }
        }));
        

    }
}
