#include "../include.h"

namespace Sunday{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Skill(CharUnit *ptr);

    bool ult_condition(CharUnit *ptr);
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(96, 130, 130, E, ElementType::Imaginary, Path::Harmony, "Sunday",UnitType::Standard);
        AllyUnit *SDptr = ptr;
        ptr->SetAllyBaseStats(1242, 640, 533);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(134);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        Driver_num = SDptr->Atv_stats->num;
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            Skill(ptr);
        };

        ptr->addUltCondition([ptr,SDptr]() -> bool {
            if(chooseCharacterBuff(ptr)->isSameName("Saber"))return true;
            if(chooseCharacterBuff(ptr)->Max_energy!=0){
                if (chooseCharacterBuff(ptr)->Max_energy <= 200 &&
                    chooseCharacterBuff(ptr)->Max_energy - 
                    chooseCharacterBuff(ptr)->Current_energy < 30) return false;
                if (chooseCharacterBuff(ptr)->Max_energy >= 200 &&
                    chooseCharacterBuff(ptr)->Max_energy - 
                    chooseCharacterBuff(ptr)->Current_energy 
                    < chooseCharacterBuff(ptr)->Max_energy * 0.2) return false;
            }
            return true;
        });
        // ptr->addUltImmediatelyUseCondition([ptr,SDptr]() -> bool {
        //     if(Buff_check(ptr, "Ode_to_Caress_and_Cicatrix"))return false;
        //     return true;
        // });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"SD Ult",
            [ptr,SDptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->Print)CharCmd::printUltStart("Sunday");
                if (ptr->Eidolon >= 2) {
                    if (ptr->Buff_check["Ult_first_time"] == 0) {
                        ptr->Buff_check["Ult_first_time"] = 1;
                        genSkillPoint(ptr, 2);
                    }
                }

                if(ptr->Eidolon>=6)
                buffStackChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::None,20}},1,3,"The_Sorrowing_Body",4);

                if (chooseCharacterBuff(ptr)->Max_energy > 200)
                Increase_energy(chooseCharacterBuff(ptr), 20, 0);
                else
                Increase_energy(chooseCharacterBuff(ptr), 0, 40);

                if (!isHaveToAddBuff(SDptr,"Ode_to_Caress_and_Cicatrix",3))
                {
                    if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")){
                        //ตัวหลัก
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        if (ptr->Eidolon >= 2)
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::None, -30}});
                        ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                        //Memopsrite
                        for(auto &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memospriteList){
                            if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                                buffSingle(each.get(),{{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                buffSingle(each.get(),{{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                if (ptr->Eidolon >= 2)
                                buffSingle(each.get(),{{Stats::DMG, AType::None, -30}});
                                each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                            }
                        }
                    }
                }
                ptr->Buff_check["Ode_to_Caress_and_Cicatrix"] = 1;
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",chooseCharacterBuff(ptr));
                ptr->setBuffNote("Ode_to_Caress_and_Cicatrix",calculateCritdamForBuff(ptr, 30) + 12);
                if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->isTargetable()){
                    ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::None, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->Eidolon >= 2)
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::None, 30}});
                }
                for(auto &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memospriteList){
                    if(!each->isTargetable())continue;
                    each->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    buffSingle(each.get(),{{Stats::CD, AType::TEMP, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(each.get(),{{Stats::CD, AType::None, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->Eidolon >= 2)
                    buffSingle(each.get(),{{Stats::DMG, AType::None, 30}});
                }
            });
            act->addBuffChar(chooseCharacterBuff(ptr));
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Stats_type[Stats::DEF_P][AType::None] += 12.5;
            ptr->Stats_type[Stats::RES][AType::None] += 18;


            // relic

            // substats
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            if(turn->isSameName("Sunday")&&ptr->Eidolon>=4){
                Increase_energy(ptr,8);
            }
            if (isBuffEnd(SDptr,"Ode_to_Caress_and_Cicatrix")) {
                if(!ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"))return;
                if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->Eidolon >= 2)
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::None, -30}});
                    ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                }
                for(auto &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memospriteList){
                    if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                        buffSingle(each.get(),{{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        buffSingle(each.get(),{{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        if (ptr->Eidolon >= 2)
                        buffSingle(each.get(),{{Stats::DMG, AType::None, -30}});
                        each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                    }
                }
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",nullptr);
                if (ptr->Print)CharCmd::printUltEnd("Sunday");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            AllyUnit *Temp_stats = turn->canCastToAllyUnit();
            if(!Temp_stats)return;
            if (isBuffEnd(Temp_stats,"Benison_of_Paper_and_Rites")) {
                if (Temp_stats->owner->isAllyHaveSummon()) {
                    buffSingle(Temp_stats,{{Stats::DMG,AType::None,-80}});
                } else {
                    buffSingle(Temp_stats,{{Stats::DMG,AType::None,-30}});
                }
                if (ptr->Eidolon >= 1&&isBuffEnd(Temp_stats,"Sunday_E1")) {
                    if (turn->side == Side::Memosprite) {
                        buffSingle(Temp_stats,{{Stats::DEF_SHRED,AType::None,-40}});
                    } else {
                        buffSingle(Temp_stats,{{Stats::DEF_SHRED,AType::None,-16}});
                        buffSingle(Temp_stats,{{Stats::DEF_SHRED,AType::Summon,-24}});
                    }
                }
            }
            if (isBuffEnd(Temp_stats,"The_Sorrowing_Body")) {
                if(ptr->Eidolon>=6){
                    buffResetStack(Temp_stats,{{Stats::CR,AType::None,20}},"The_Sorrowing_Body");
                }else{
                    buffSingle(Temp_stats,{{Stats::CR,AType::None,-20}});
                }
                
            }
            if (isBuffEnd(Temp_stats,"The_Glorious_Mysteries")){
                buffSingle(Temp_stats,{{Stats::DMG,AType::None,-50}});
            }
            
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr]() {
            Increase_energy(ptr, 25);
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr](shared_ptr<AllyBuffAction> &act) {
            if (chooseCharacterBuff(ptr)->getBuffCheck("Ode_to_Caress_and_Cicatrix") && act->actionName=="SD Skill") {
                genSkillPoint(ptr, 1);
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,SDptr](AllyUnit *target, Stats StatsType) {
            if(ptr->Eidolon>=6&&target->getStack("The_Sorrowing_Body")>0&&StatsType == Stats::CR){
                double temp = (calculateCritrateForBuff(target,100) - 100)*2;
                if(temp<0)temp=0;
                buffSingle(target,{{Stats::CD, AType::TEMP, temp - target->getBuffNote("The_Sorrowing_Body")}});
                buffSingle(target,{{Stats::CD, AType::None, temp - target->getBuffNote("The_Sorrowing_Body")}});
                target->Buff_note["The_Sorrowing_Body"] = temp;
            }
            if (target->Atv_stats->Name != "Sunday") return;
            if (!target->getBuffCheck("Ode_to_Caress_and_Cicatrix")) return;
            if (StatsType != Stats::CD) return;   
            double buffValue = calculateCritdamForBuff(ptr, 30) + 12;
            if(chooseCharacterBuff(ptr)->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                buffSingle(chooseCharacterBuff(ptr),{{Stats::CD, AType::TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(chooseCharacterBuff(ptr),{{Stats::CD, AType::None, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
            }
            for(auto &each : chooseCharacterBuff(ptr)->memospriteList ){
                if(!each->getBuffCheck("Ode_to_Caress_and_Cicatrix"))continue;
                buffSingle(each.get(),{{Stats::CD, AType::TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(each.get(),{{Stats::CD, AType::None, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
            }
            ptr->Buff_note["Ode_to_Caress_and_Cicatrix"] =  buffValue;
            
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY,[ptr,SDptr](AllyUnit* target){
            if(isBuffGoneByDeath(target,"Ode_to_Caress_and_Cicatrix")){
                buffSingle(target,{{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(target,{{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                if (ptr->Eidolon >= 2)
                buffSingle(target,{{Stats::DMG, AType::None, -30}});
            }
            if (isBuffGoneByDeath(target,"Benison_of_Paper_and_Rites")){
                if (target->owner->isAllyHaveSummon()) {
                    buffSingle(target,{{Stats::DMG,AType::None,-80}});
                } else {
                    buffSingle(target,{{Stats::DMG,AType::None,-30}});
                }
                if (ptr->Eidolon >= 1&&isBuffGoneByDeath(target,"Sunday_E1")) {
                    if (turn->side == Side::Memosprite) {
                        buffSingle(target,{{Stats::DEF_SHRED,AType::None,-40}});
                    } else {
                        buffSingle(target,{{Stats::DEF_SHRED,AType::None,-16}});
                        buffSingle(target,{{Stats::DEF_SHRED,AType::Summon,-24}});
                    }
                }
            }
            if(ptr->Eidolon>=6){
                buffResetStack(target,{{Stats::CR,AType::None,20}},"The_Sorrowing_Body");
            }
            else if(isBuffGoneByDeath(target,"The_Sorrowing_Body"))
            {
                buffSingle(target,{{Stats::CR,AType::None,-20}});
            }
            if (isBuffGoneByDeath(target,"The_Glorious_Mysteries")){
                buffSingle(target,{{Stats::DMG,AType::None,-50}});
            }
        }));





    }

    
    void Skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"SD Skill",
        [ptr,SDptr=ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            if(ptr->Eidolon>=6){
                buffStackChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::None,20}},1,3,"The_Sorrowing_Body",4);
            }
            else
            {
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::None,20}},"The_Sorrowing_Body",3);
            }

            if(chooseCharacterBuff(ptr)->isAllyHaveSummon())
            buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::None,80}},"Benison_of_Paper_and_Rites",2);
            else
            buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::None,30}},"Benison_of_Paper_and_Rites",2);

            if(ptr->Eidolon>=1){
                buffSingle(chooseCharacterBuff(ptr),{
                    {Stats::DEF_SHRED,AType::None,16},
                    {Stats::DEF_SHRED,AType::Summon,24},
                },"Sunday_E1",2);
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DEF_SHRED,AType::None,40}},"Sunday_E1",2);
            }
            
            if(ptr->Technique==1&&!SDptr->getBuffCheck("Technique_use")){
                ptr->setBuffCheck("Technique_use",1);
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::None,50}},"The_Glorious_Mysteries",2);
            }
            
            //Action Forward
            for(std::unique_ptr<Unit> &e : chooseCharacterBuff(ptr)->summonList){
                Action_forward(e->Atv_stats.get(),100);
            }
            for(auto &each : chooseCharacterBuff(ptr)->memospriteList){
                Action_forward(each->Atv_stats.get(),100);
            }
            Action_forward(chooseCharacterBuff(ptr)->Atv_stats.get(),100);
        });
        act->addBuffChar(chooseCharacterBuff(ptr));
        act->addToActionBar();
    }

    bool ult_condition(CharUnit *ptr){
        //if(Current_atv<150&&(Ally_unit[Main_dps_num]->countdownList[0]->Atv_stats->Base_speed==-1))return true;
        return false;
    }

}