#include "../include.h"

namespace Hanabi{
     void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(101,110,110,E,ElementType::Quantum,"Harmony","Hanabi",TYPE_STD);
        ptr->SetAllyBaseStats(1397,524,485);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(ST_CD,ST_FLAT_SPD,ST_HP_P,ST_EnergyRecharge);

        Max_sp+=3;
        if(ptr->Eidolon>=4)Max_sp++;
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        SubUnit *hnb = ptr->getSubUnit();
        Driver_num = hnb->Atv_stats->num;

        #pragma region Ability

        function<void()> BA = [ptr,hnb]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Hnb BA",
            [hnb](shared_ptr<AllyAttackAction> &act){
                Skill_point(hnb,1);
                Increase_energy(hnb,30);
                Attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hnb]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Hnb Skill",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                Skill_point(hnb,-1);
                Increase_energy(hnb,30);
                double buff = (ptr->Eidolon>=6)? calculateCritdamForBuff(hnb,54) + 45 :calculateCritdamForBuff(hnb,24) + 45;

                chooseSubUnitBuff(hnb)->buffSingle({
                    {ST_CD,AType::TEMP,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")},
                    {ST_CD,AType::None,buff - chooseSubUnitBuff(hnb)->getBuffNote("Hnb Skill")}
                });
                chooseSubUnitBuff(hnb)->extendBuffTime("Hnb Skill",2);
                chooseSubUnitBuff(hnb)->setBuffNote("Hnb Skill",buff);
                
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            if(!each->getBuffCheck("Hnb Cipher"))continue;
                            each->buffSingle({
                                {ST_CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                                {ST_CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
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
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get(),Skill,BA]() {
            Skill();
        };
        
        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(Max_sp-sp<3)return false;
            return true;
        });

        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(ptr->Light_cone.Name!="DDD"&&Situation == "Before Turn"&&turn->isSameChar(chooseSubUnitBuff(hnb)))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hnb]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TT_AOE,"Hnb Ult",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                if(ptr->Eidolon>=4)Skill_point(hnb,5);
                else Skill_point(hnb,4);
                
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                        if(each->isHaveToAddBuff("Hnb Cipher")){
                            each->buffSingle({{ST_DMG,AType::None,10.0 * each->getStack("Hnb Talent")}});
                            if(ptr->Eidolon>=1){
                                each->buffSingle({{ST_ATK_P,AType::None,40}});
                                each->extendBuffTime("Hnb Cipher",3);
                            }
                            else each->extendBuffTime("Hnb Cipher",2);
                        }
                    }   
                }

                if(ptr->Eidolon>=6){
                    double buff = calculateCritdamForBuff(hnb,54) + 45;
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {ST_CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                                {ST_CD,AType::None,buff - each->getBuffNote("Hnb Skill")}
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
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AType::None] += 24;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AType::None] += 10;

            // relic

            // substats
            int qtCount = 0;

            for(int i=1;i<=Total_ally;i++){
                if(Ally_unit[i]->getSubUnit()->Element_type[0] ==ElementType::Quantum)
                    qtCount++;
            }

            double atkBuff = 20;
            if(qtCount == 2)atkBuff = 30;
            else if(qtCount >= 3)atkBuff = 45;
            for(int i=1;i<=Total_ally;i++){
                if(Ally_unit[i]->getSubUnit()->Element_type[0] ==ElementType::Quantum)
                    Ally_unit[i]->getSubUnit()->buffSingle({{ST_ATK_P,AType::None,atkBuff}});
                else
                    Ally_unit[i]->getSubUnit()->buffSingle({{ST_ATK_P,AType::None,15}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            if(ptr->Technique)Skill_point(hnb,3);
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            SubUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(ally->isBuffEnd("Hnb Skill")){
                ally->buffSingle({
                    {ST_CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                    {ST_CD,AType::None,-ally->getBuffNote("Hnb Skill")}
                });
                ally->setBuffNote("Hnb Skill",0);
                
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {ST_CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {ST_CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hnb]() {
            SubUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(ally->isBuffEnd("Hnb Cipher")){
                ally->buffSingle({{ST_DMG,AType::None,-10.0 * ally->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)ally->buffSingle({{ST_ATK_P,AType::None,-40}});
                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            if(each->getBuffCheck("Hnb Skill"))continue;
                            each->buffSingle({
                                {ST_CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {ST_CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
            if(ally->isBuffEnd("Hnb Talent")){
                if(ally->getBuffCheck("Hnb Cipher"))
                    ally->buffResetStack({{ST_DMG,AType::None,16}},"Hnb Talent");
                else
                    ally->buffResetStack({{ST_DMG,AType::None,6}},"Hnb Talent");
                if(ptr->Eidolon>=2)ally->buffResetStack({{ST_DEF_SHRED,AType::None,8}},"Hnb E2");
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,hnb](SubUnit* target) {
            if(target->isBuffGoneByDeath("Hnb Cipher")){
                target->buffSingle({{ST_DMG,AType::None,-10.0 * target->getStack("Hnb Talent")}});
                if(ptr->Eidolon>=1)target->buffSingle({{ST_ATK_P,AType::None,-40}});
            }
            if(target->isBuffGoneByDeath("Hnb Talent")){
                if(target->getBuffCheck("Hnb Cipher"))
                    target->buffResetStack({{ST_DMG,AType::None,16}},"Hnb Talent");
                else
                    target->buffResetStack({{ST_DMG,AType::None,6}},"Hnb Talent");
                if(ptr->Eidolon>=2)target->buffResetStack({{ST_DEF_SHRED,AType::None,8}},"Hnb E2");
            }
            if(target->isBuffGoneByDeath("Hnb Skill")){
                target->buffSingle({
                    {ST_CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                    {ST_CD,AType::None,-target->getBuffNote("Hnb Skill")}
                });
                target->setBuffNote("Hnb Skill",0);


                if(ptr->Eidolon>=6){
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            each->buffSingle({
                                {ST_CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {ST_CD,AType::None,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }

            }
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr,hnb](SubUnit *SP_maker, int SP) {
            if(SP>=0)return;
            for(int i=1;i<=Total_ally;i++){
                for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                    if(each->getBuffCheck("Hnb Cipher"))
                        each->buffStackSingle({{ST_DMG,AType::None,16}},-SP,3,"Hnb Talent",2);
                    else 
                        each->buffStackSingle({{ST_DMG,AType::None,6}},-SP,3,"Hnb Talent",2);
                    if(ptr->Eidolon>=2)each->buffStackSingle({{ST_DEF_SHRED,AType::None,8}},-SP,3,"Hnb E2");
                }   
            }
        }));
        

    }
}
