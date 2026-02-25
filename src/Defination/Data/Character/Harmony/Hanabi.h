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
        // Driver_num = hnb->Atv_stats->num;

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
            if(ptr->getBuffCheck("Hnb Free Skill"))Skill_point(hnb,0);
            else Skill_point(hnb,-1);
            ptr->setBuffCheck("Hnb Free Skill",0);

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"Hnb Skill",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                Increase_energy(hnb,30);
                double buff = (ptr->Eidolon>=6)? calculateCritdamForBuff(hnb,54) + 45 :calculateCritdamForBuff(hnb,24) + 45;

                buffSingle(chooseSubUnitBuff(hnb),{
                    {Stats::CD,AType::TEMP,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")}
                });
                buffSingle(chooseSubUnitBuff(hnb),{{Stats::RESPEN,AType::None,10}},"Hnb Skill",2);
                chooseSubUnitBuff(hnb)->setBuffNote("Hnb Skill",buff);
                
                if(ptr->Eidolon>=6){
                    for(auto &each : allyList){
                        if(!each->getBuffCheck("Hnb Cipher"))continue;
                        if(each->getBuffCheck("Hnb Skill"))continue;
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
                        });
                        if(isHaveToAddBuff(each,"Hnb E6 Link"))buffSingle(each,{{Stats::RESPEN,AType::None,10}});
                        each->setBuffNote("Hnb Skill",buff);
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
        
        // ptr->addUltCondition([ptr,hnb]() -> bool {
        //     if(Max_sp-sp<3)return false;
        //     return true;
        // });

        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(ptr->Light_cone.Name!="DDD"&&phaseStatus == PhaseStatus::BeforeTurn&&turn->isSameUnit(chooseSubUnitBuff(hnb)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hnb]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"Hnb Ult",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Hanabi");
                // start record overflow sp
                ptr->setBuffCheck("Hnb Ult",true);

                if(ptr->Eidolon>=4)Skill_point(hnb,7);
                else Skill_point(hnb,6);

                // Hnb Cipher
                if(ptr->Eidolon == 0)
                    buffAllAlly({
                        {Stats::VUL,AType::None,6.0*ptr->getStack("Hnb Talent")}
                    },"Hnb Cipher",3);
                else
                    buffAllAlly({
                        {Stats::VUL,AType::None,6.0*ptr->getStack("Hnb Talent")},
                        {Stats::ATK_P,AType::None,40}
                    },"Hnb Cipher",3);

                if(ptr->Eidolon>=6){
                    double buff = calculateCritdamForBuff(hnb,54) + 45;
                    for(auto &each : allyList){
                        if(each->getBuffCheck("Hnb Skill"))continue;
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
                        });
                        if(isHaveToAddBuff(each,"Hnb E6 Link"))buffSingle(each,{{Stats::RESPEN,AType::None,10}});
                        each->setBuffNote("Hnb Skill",buff);
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
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffAllAlly({{Stats::ATK_P,AType::None,45}});
            if(ptr->Eidolon>=1)buffSingle(ptr,{{Stats::SPD_P,AType::None,15}});
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            if(ptr->Technique)Skill_point(hnb,3);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            
            //Skill buff
            if(isBuffEnd(ally,"Hnb Skill")){
                buffSingle(ally,{
                    {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,-ally->getBuffNote("Hnb Skill")},
                    {Stats::RESPEN,AType::None,-10}
                });
                ally->setBuffNote("Hnb Skill",0);
                
                if(ptr->Eidolon>=6){
                    for(auto &each : allyList){
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::None,-each->getBuffNote("Hnb Skill")}
                        });
                        if(each->getBuffCheck("Hnb E6 Link")){
                            buffSingle(each,{{Stats::RESPEN,AType::None,-10}});
                            each->setBuffCheck("Hnb E6 Link",0);
                        }
                        each->setBuffNote("Hnb Skill",0);
                    }   
                }
            }

            // Hnb Ult
            if(isBuffEnd(ally,"Hnb Cipher")){
                buffSingle(ally,{{Stats::VUL,AType::None,-6.0 * ptr->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)buffSingle(ally,{{Stats::ATK_P,AType::None,-40}});
                if(ptr->Eidolon>=6&&!ally->getBuffCheck("Hnb Skill")){
                    buffSingle(ally,{
                        {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                        {Stats::CD,AType::None,-ally->getBuffNote("Hnb Skill")}
                    });
                    if(ally->getBuffCheck("Hnb E6 Link")){
                        buffSingle(ally,{{Stats::RESPEN,AType::None,-10}});
                        ally->setBuffCheck("Hnb E6 Link",0);
                    }
                    ally->setBuffNote("Hnb Skill",0);
                }
            }

            if(ptr->getBuffCheck("Hnb Ult")){
                ptr->setBuffCheck("Hnb Ult",0);
                Skill_point(ptr,ptr->getStack("Hnb sp record"));
                ptr->setStack("Hnb sp record",0);
            }

        }));
        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit* target) {
            
            //Skill buff
            if(isBuffGoneByDeath(target,"Hnb Skill")){
                buffSingle(target,{
                    {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::None,-target->getBuffNote("Hnb Skill")},
                    {Stats::RESPEN,AType::None,-10}
                });
                target->setBuffNote("Hnb Skill",0);
                
                if(ptr->Eidolon>=6){
                    for(auto &each : allyList){
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::None,-each->getBuffNote("Hnb Skill")}
                        });
                        each->setBuffNote("Hnb Skill",0);
                        if(each->getBuffCheck("Hnb E6 Link")){
                            buffSingle(each,{{Stats::RESPEN,AType::None,-10}});
                            each->setBuffCheck("Hnb E6 Link",0);
                        }
                    }   
                }
            }

            // Hnb Ult
            if(isBuffGoneByDeath(target,"Hnb Cipher")){
                buffSingle(target,{{Stats::VUL,AType::None,-6.0 * ptr->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)buffSingle(target,{{Stats::ATK_P,AType::None,-40}});
                if(ptr->Eidolon>=6&&!target->getBuffCheck("Hnb Skill")){
                    buffSingle(target,{
                        {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                        {Stats::CD,AType::None,-target->getBuffNote("Hnb Skill")}
                    });
                    if(target->getBuffCheck("Hnb E6 Link")){
                        buffSingle(target,{{Stats::RESPEN,AType::None,-10}});
                        target->setBuffCheck("Hnb E6 Link",0);
                    }
                    target->setBuffNote("Hnb Skill",0);
                }   
            }
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit *SP_maker, int SP) {
            if(ptr->getBuffCheck("Hnb Ult")){
                ptr->addStack("Hnb sp record",max(0,sp + SP - Max_sp));
            }
            if(SP>=0)return;
            if(!ptr->getStack("Hnb Talent")){
                for(auto &each : enemyList){
                    each->Total_debuff++;
                }
            }
            pair<int,int> stk = calStack(ptr,-SP,3,"Hnb Cipher");
            for(auto &each : allyList){
                if(each->getBuffCheck("Hnb Cipher")) buffSingle(each,{{Stats::VUL,AType::None,4.0*stk.first}});
                else buffSingle(each,{{Stats::VUL,AType::None,10.0*stk.first}});
            }
            if(ptr->Eidolon>=2)debuffAllEnemy({{Stats::DEF_SHRED,AType::None,10.0*stk.first}});

            if(SP_maker->getBuffCheck("Hnb Skill")||ptr->Eidolon>=6){
                Increase_energy(ptr,1);
            }

            if(ptr->getBuffNote("Hanabi turn note" + turn->getUnitName()) != turn->turnCnt || turn->turnCnt==0)
            ptr->setStack("Hnb sp record",0);

            ptr->addStack("Hnb sp record",SP*-1);
            if(ptr->getStack("Hnb sp record")>=3)ptr->setBuffCheck("Hnb Free Skill",1);
            
   
        }));
        

    }
}
