#include "../include.h"

namespace Sunday{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Skill(Ally *ptr);

    bool ult_condition(Ally *ptr);
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(96, 130, 130, E, ElementType::Imaginary, Path::Harmony, "Sunday",UnitType::Standard);
        SubUnit *SDptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1242, 640, 533);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        Driver_num = SDptr->Atv_stats->num;
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            Skill(ptr);
        };

        ptr->addUltCondition([ptr,SDptr]() -> bool {
            if(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->getSubUnit()->isSameUnitName("Saber"))return true;
            if(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy!=0){
                if (chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy <= 200 &&
                    chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy - 
                    chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Current_energy < 30) return false;
                if (chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy >= 200 &&
                    chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy - 
                    chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Current_energy 
                    < chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy * 0.2) return false;
            }
            return true;
        });
        // ptr->addUltImmediatelyUseCondition([ptr,SDptr]() -> bool {
        //     if(Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix"))return false;
        //     return true;
        // });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TraceType::Single,"SD Ult",
            [ptr,SDptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->Print)CharCmd::printUltStart("Sunday");
                if (ptr->Eidolon >= 2) {
                    if (ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] == 0) {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] = 1;
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 2);
                    }
                }

                if(ptr->Eidolon>=6)
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffStackAlly({{Stats::CR,AType::None,20}},1,3,"The_Sorrowing_Body",4);

                if (chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy > 200)
                Increase_energy(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()), 20, 0);
                else
                Increase_energy(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()), 0, 40);

                if (!SDptr->isHaveToAddBuff("Ode_to_Caress_and_Cicatrix",3))
                {
                    if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")){
                        for(unique_ptr<SubUnit> &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                            if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                                each->buffSingle({{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                each->buffSingle({{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                if (ptr->Eidolon >= 2)
                                each->buffSingle({{Stats::DMG, AType::None, -30}});
                                each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                            }
                        }
                    }
                }
                ptr->Sub_Unit_ptr[0]->Buff_check["Ode_to_Caress_and_Cicatrix"] = 1;
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",chooseCharacterBuff(ptr->getSubUnit()));
                ptr->getSubUnit()->setBuffNote("Ode_to_Caress_and_Cicatrix",calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12);
                for(unique_ptr<SubUnit> &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                    if(!each->isExsited())continue;
                    each->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    each->buffSingle({{Stats::CD, AType::TEMP, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    each->buffSingle({{Stats::CD, AType::None, SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->Eidolon >= 2)
                    each->buffSingle({{Stats::DMG, AType::None, 30}});
                }
            });
            act->addBuffAlly(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 12.5;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 18;


            // relic

            // substats
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            if(turn->isSameUnitName("Sunday")&&ptr->Eidolon>=4){
                Increase_energy(ptr,8);
            }
            if (SDptr->isBuffEnd("Ode_to_Caress_and_Cicatrix")) {
                if(!ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"))return;
                for(unique_ptr<SubUnit> &each : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                    if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                        each->buffSingle({{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        each->buffSingle({{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        if (ptr->Eidolon >= 2)
                        each->buffSingle({{Stats::DMG, AType::None, -30}});
                        each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                    }
                }
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",nullptr);
                if (ptr->Print)CharCmd::printUltEnd("Sunday");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,SDptr]() {
            SubUnit *Temp_stats = turn->canCastToSubUnit();
            if(!Temp_stats)return;
            if (Temp_stats->isBuffEnd("Benison_of_Paper_and_Rites")) {
                if (Temp_stats->ptrToChar->isAllyHaveSummon()) {
                    Temp_stats->buffSingle({{Stats::DMG,AType::None,-80}});
                } else {
                    Temp_stats->buffSingle({{Stats::DMG,AType::None,-30}});
                }
                if (ptr->Eidolon >= 1&&Temp_stats->isBuffEnd("Sunday_E1")) {
                    if (turn->side == Side::Memosprite) {
                        Temp_stats->buffSingle({{Stats::DEF_SHRED,AType::None,-40}});
                    } else {
                        Temp_stats->buffSingle({{Stats::DEF_SHRED,AType::None,-16}});
                        Temp_stats->buffSingle({{Stats::DEF_SHRED,AType::Summon,-24}});
                    }
                }
            }
            if (Temp_stats->isBuffEnd("The_Sorrowing_Body")) {
                if(ptr->Eidolon>=6){
                    Temp_stats->buffResetStack({{Stats::CR,AType::None,20}},"The_Sorrowing_Body");
                }else{
                    Temp_stats->buffSingle({{Stats::CR,AType::None,-20}});
                }
                
            }
            if (Temp_stats->isBuffEnd("The_Glorious_Mysteries")){
                Temp_stats->buffSingle({{Stats::DMG,AType::None,-50}});
            }
            
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr]() {
            Increase_energy(ptr, 25);
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,SDptr](shared_ptr<AllyBuffAction> &act) {
            if (chooseCharacterBuff(ptr->getSubUnit())->getBuffCheck("Ode_to_Caress_and_Cicatrix") && act->actionName=="SD Skill") {
                Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,SDptr](SubUnit *target, Stats StatsType) {
            if(ptr->Eidolon>=6&&target->getStack("The_Sorrowing_Body")>0&&StatsType == Stats::CR){
                double temp = (calculateCritrateForBuff(target,100) - 100)*2;
                if(temp<0)temp=0;
                target->buffSingle({{Stats::CD, AType::TEMP, temp - target->getBuffNote("The_Sorrowing_Body")}});
                target->buffSingle({{Stats::CD, AType::None, temp - target->getBuffNote("The_Sorrowing_Body")}});
                target->Buff_note["The_Sorrowing_Body"] = temp;
            }
            if (target->Atv_stats->Unit_Name != "Sunday") return;
            if (!target->getBuffCheck("Ode_to_Caress_and_Cicatrix")) return;
            if (StatsType != Stats::CD) return;   
            double buffValue = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12;
            for(unique_ptr<SubUnit> &each : chooseCharacterBuff(ptr->getSubUnit())->Sub_Unit_ptr ){
                if(!each->getBuffCheck("Ode_to_Caress_and_Cicatrix"))continue;
                each->buffSingle({{Stats::CD, AType::TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                each->buffSingle({{Stats::CD, AType::None, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
            }
            ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"] =  buffValue;
            
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY,[ptr,SDptr](SubUnit* target){
            if(target->isBuffGoneByDeath("Ode_to_Caress_and_Cicatrix")){
                target->buffSingle({{Stats::CD, AType::TEMP, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                target->buffSingle({{Stats::CD, AType::None, -SDptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                if (ptr->Eidolon >= 2)
                target->buffSingle({{Stats::DMG, AType::None, -30}});
            }
            if (target->isBuffGoneByDeath("Benison_of_Paper_and_Rites")){
                if (target->ptrToChar->isAllyHaveSummon()) {
                    target->buffSingle({{Stats::DMG,AType::None,-80}});
                } else {
                    target->buffSingle({{Stats::DMG,AType::None,-30}});
                }
                if (ptr->Eidolon >= 1&&target->isBuffGoneByDeath("Sunday_E1")) {
                    if (turn->side == Side::Memosprite) {
                        target->buffSingle({{Stats::DEF_SHRED,AType::None,-40}});
                    } else {
                        target->buffSingle({{Stats::DEF_SHRED,AType::None,-16}});
                        target->buffSingle({{Stats::DEF_SHRED,AType::Summon,-24}});
                    }
                }
            }
            if(ptr->Eidolon>=6){
                target->buffResetStack({{Stats::CR,AType::None,20}},"The_Sorrowing_Body");
            }
            else if(target->isBuffGoneByDeath("The_Sorrowing_Body"))
            {
                target->buffSingle({{Stats::CR,AType::None,-20}});
            }
            if (target->isBuffGoneByDeath("The_Glorious_Mysteries")){
                target->buffSingle({{Stats::DMG,AType::None,-50}});
            }
        }));





    }

    
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Single,"SD Skill",
        [ptr,SDptr=ptr->getSubUnit()](shared_ptr<AllyBuffAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            if(ptr->Eidolon>=6){
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffStackAlly({{Stats::CR,AType::None,20}},1,3,"The_Sorrowing_Body",4);
            }
            else
            {
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffAlly({{Stats::CR,AType::None,20}},"The_Sorrowing_Body",3);
            }

            if(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->isAllyHaveSummon())
            chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffAlly({{Stats::DMG,AType::None,80}},"Benison_of_Paper_and_Rites",2);
            else
            chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffAlly({{Stats::DMG,AType::None,30}},"Benison_of_Paper_and_Rites",2);

            if(ptr->Eidolon>=1){
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Sub_Unit_ptr[0]->buffSingle({
                    {Stats::DEF_SHRED,AType::None,16},
                    {Stats::DEF_SHRED,AType::Summon,24},
                },"Sunday_E1",2);
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffAlly({{Stats::DEF_SHRED,AType::None,40}},"Sunday_E1",2);
            }
            
            if(ptr->Technique==1&&!SDptr->getBuffCheck("Technique_use")){
                ptr->getSubUnit()->setBuffCheck("Technique_use",1);
                chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->buffAlly({{Stats::DMG,AType::None,50}},"The_Glorious_Mysteries",2);
            }
            
            //Action Forward
            for(std::unique_ptr<Unit> &e : chooseCharacterBuff(ptr->getSubUnit())->Summon_ptr){
                Action_forward(e->Atv_stats.get(),100);
            }
            for(int i=1 ;i<chooseCharacterBuff(ptr->getSubUnit())->Sub_Unit_ptr.size();i++){
                Action_forward(chooseCharacterBuff(ptr->getSubUnit())->getSubUnit(i)->Atv_stats.get(),100);
            }
            Action_forward(chooseCharacterBuff(ptr->getSubUnit())->getSubUnit()->Atv_stats.get(),100);
        });
        act->addBuffAlly(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }

    bool ult_condition(Ally *ptr){
        //if(Current_atv<150&&(Ally_unit[Main_dps_num]->Countdown_ptr[0]->Atv_stats->Base_speed==-1))return true;
        return false;
    }

}