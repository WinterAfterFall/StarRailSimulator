
#ifndef Sunday_H
#define Sunday_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Sunday{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Skill(Ally *ptr);

    bool ult_condition(Ally *ptr);
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(96, 130, 130, E, "Imaginary", "Harmony", "Sunday",TYPE_STD);
        ptr->SetAllyBaseStats(1242, 640, 533);

        ptr->pushSubstats(ST_CRIT_DAM);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(133.4);
        ptr->setRelicMainStats(ST_HP_PERCENT,ST_FLAT_SPD,ST_HP_PERCENT,ST_EnergyRecharge);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            Skill(ptr);
        };

        ptr->addUltCondition([ptr]() -> bool {
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
        // ptr->addUltImmediatelyUseCondition([ptr]() -> bool {
        //     if(Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix"))return false;
        //     return true;
        // });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            AllyActionData data_ = AllyActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Buff", "Single_target","Sunday Ultimate");
            data_.Add_Buff_Single_Target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
            data_.actionFunction = [ptr](AllyActionData &data_){
                if (ptr->Print)CharCmd::printUltStart("Sunday");
                if (ptr->Eidolon >= 2) {
                    if (ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] == 0) {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] = 1;
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 2);
                    }
                }

                if(ptr->Eidolon>=6){
                    Stack_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_CRIT_RATE,AT_NONE,20,1,3,"The_Sorrowing_Body");
                    Extend_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"The_Sorrowing_Body",4);
                }

                if (chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Max_energy > 200)
                Increase_energy(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()), 20, 0);
                else
                Increase_energy(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()), 0, 40);

                if (Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix"))
                {
                    if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")){
                        for(unique_ptr<SubUnit> &e : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                            if(e->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                                Buff_single_target(e.get(),ST_CRIT_DAM, AT_TEMP, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                                Buff_single_target(e.get(),ST_CRIT_DAM, AT_NONE, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                                if (ptr->Eidolon >= 2)
                                Buff_single_target(e.get(), "Dmg%", AT_NONE, -30);
                                e->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                            }
                        }
                    }
                }
                ptr->Sub_Unit_ptr[0]->Buff_check["Ode_to_Caress_and_Cicatrix"] = 1;
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",chooseCharacterBuff(ptr->getSubUnit()));
                ptr->getSubUnit()->setBuffNote("Ode_to_Caress_and_Cicatrix",calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12);
                for(unique_ptr<SubUnit> &e : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                    if(e->currentHP==0)continue;
                    e->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    Buff_single_target(e.get(),ST_CRIT_DAM, AT_TEMP, ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                    Buff_single_target(e.get(),ST_CRIT_DAM, AT_NONE, ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                    if (ptr->Eidolon >= 2)
                    Buff_single_target(e.get(), "Dmg%", AT_NONE, 30);
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix", 3);
            };
            Action_bar.push(data_);
            
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 12.5;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed -= 2.3;


            // relic

            // substats
        }));


        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if(turn->isSameUnitName("Sunday")&&ptr->Eidolon>=4){
                Increase_energy(ptr,8);
            }
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Ode_to_Caress_and_Cicatrix"] = 0;
                if(!ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"))return;
                for(unique_ptr<SubUnit> &e : ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->Sub_Unit_ptr){
                    if(e->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                        Buff_single_target(e.get(),ST_CRIT_DAM, AT_TEMP, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                        Buff_single_target(e.get(),ST_CRIT_DAM, AT_NONE, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                        if (ptr->Eidolon >= 2)
                        Buff_single_target(e.get(), "Dmg%", AT_NONE, -30);
                        e->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                    }
                }
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",nullptr);
                if (ptr->Print)CharCmd::printUltEnd("Sunday");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            SubUnit *Temp_stats = turn->canCastToSubUnit();
            if (!Temp_stats||Temp_stats->getNum()!=ptr->getSubUnit()->currentAllyTargetNum) return;
            if (Buff_end(Temp_stats, "Benison_of_Paper_and_Rites")) {
                if (Temp_stats->ptr_to_unit->isAllyHaveSummon()) {
                    Buff_single_target(Temp_stats, "Dmg%", AT_NONE, -80);
                } else {
                    Buff_single_target(Temp_stats, "Dmg%", AT_NONE, -30);
                }
                Temp_stats->Buff_check["Benison_of_Paper_and_Rites"] = 0;
                if (ptr->Eidolon >= 1) {
                    if (turn->Side == "Memosprite") {
                        Buff_single_target(Temp_stats, "Def_shred", AT_NONE, -40);
                    } else {
                        Buff_single_target(Temp_stats, "Def_shred", AT_NONE, -16);
                        Buff_single_target(Temp_stats, "Def_shred", "Summon", -24);
                    }
                    Temp_stats->Buff_check["Sunday_E1"] = 0;
                }
            }
            if (Buff_end(Temp_stats, "The_Sorrowing_Body")) {
                if(ptr->Eidolon>=6){
                    Buff_single_target(Temp_stats, "Crit_rate", AT_NONE, -20*Temp_stats->Stack["The_Sorrowing_Body"]);
                    Temp_stats->Stack["The_Sorrowing_Body"] = 0;
                }else{
                    Buff_single_target(Temp_stats, "Crit_rate", AT_NONE, -20);
                    Temp_stats->Buff_check["The_Sorrowing_Body"] = 0;
                }
                
            }
            if (Buff_end(Temp_stats, "The_Glorious_Mysteries")){
                Buff_single_target(Temp_stats, "Dmg%", AT_NONE, -50);
                Temp_stats->setBuffCheck("The_Glorious_Mysteries",0);
            }
            
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Increase_energy(ptr, 25);
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](AllyActionData &data_) {
            if (chooseCharacterBuff(ptr->getSubUnit())->getBuffCheck("Ode_to_Caress_and_Cicatrix") && data_.actionName=="Sunday Skill") {
                Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](SubUnit *target, string StatsType) {
            if(ptr->Eidolon>=6&&target->getStack("The_Sorrowing_Body")>0&&StatsType == ST_CRIT_RATE){
                double temp = (calculateCritrateForBuff(target,100) - 100)*2;
                if(temp<0)temp=0;
                Buff_single_target(target, ST_CRIT_DAM, AT_TEMP, temp - target->getBuffNote("The_Sorrowing_Body"));
                Buff_single_target(target, ST_CRIT_DAM, AT_NONE, temp - target->getBuffNote("The_Sorrowing_Body"));
                target->Buff_note["The_Sorrowing_Body"] = temp;
            }
            if (target->Atv_stats->Unit_Name != "Sunday") return;
            if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) return;
            if (StatsType != ST_CRIT_DAM) return;   
            double buffValue = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12;
            for(unique_ptr<SubUnit> &e : chooseCharacterBuff(ptr->getSubUnit())->Sub_Unit_ptr ){
                if(!e->getBuffCheck("Ode_to_Caress_and_Cicatrix"))continue;
                Buff_single_target(e.get(), ST_CRIT_DAM, AT_TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                Buff_single_target(e.get(), ST_CRIT_DAM, AT_NONE, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix"));
            }
            ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"] =  buffValue;
            
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY,[ptr](SubUnit* target){
            if(target->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                Buff_single_target(target,ST_CRIT_DAM, AT_TEMP, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                Buff_single_target(target,ST_CRIT_DAM, AT_NONE, -ptr->getSubUnit()->getBuffNote("Ode_to_Caress_and_Cicatrix"));
                if (ptr->Eidolon >= 2)
                Buff_single_target(target, "Dmg%", AT_NONE, -30);
                target->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
            }
            if (target->getBuffCheck("Benison_of_Paper_and_Rites")) {
                target->setBuffCheck("Benison_of_Paper_and_Rites",0);
                target->setBuffCountdown("Benison_of_Paper_and_Rites",0);
                if (target->ptr_to_unit->isAllyHaveSummon()) {
                    Buff_single_target(target, "Dmg%", AT_NONE, -80);
                } else {
                    Buff_single_target(target, "Dmg%", AT_NONE, -30);
                }
                if (ptr->Eidolon >= 1) {
                    if (target->Atv_stats->Side == "Memosprite") {
                        Buff_single_target(target, "Def_shred", AT_NONE, -40);
                    } else {
                        Buff_single_target(target, "Def_shred", AT_NONE, -16);
                        Buff_single_target(target, "Def_shred", "Summon", -24);
                    }
                    target->Buff_check["Sunday_E1"] = 0;
                }
            }
            target->setBuffCountdown("The_Sorrowing_Body",0);
            if(ptr->Eidolon>=6){
                Buff_single_target(target, "Crit_rate", AT_NONE, -20*target->Stack["The_Sorrowing_Body"]);
                target->Stack["The_Sorrowing_Body"] = 0;
            }
            else
            {
                if(target->getBuffCheck("The_Sorrowing_Body")){
                    Buff_single_target(target, "Crit_rate", AT_NONE, -20);
                    target->Buff_check["The_Sorrowing_Body"] = 0;
                }
            }
            if (target->getBuffCheck("The_Glorious_Mysteries")){
                Buff_single_target(target, "Dmg%", AT_NONE, -50);
                target->setBuffCheck("The_Glorious_Mysteries",0);
                target->setBuffCountdown("The_Glorious_Mysteries",0);
            }
        }));





    }

    
    void Skill(Ally *ptr){
        AllyActionData temp = AllyActionData();
        temp.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Sunday Skill");
        temp.Add_Buff_Single_Target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
        temp.Turn_reset=true;
        temp.actionFunction = [ptr](AllyActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            if(ptr->Eidolon>=6){
                Stack_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_CRIT_RATE,AT_NONE,20,1,3,"The_Sorrowing_Body");
                Extend_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"The_Sorrowing_Body",4);
            }
            else
            {
                Buff_single_with_all_memo_each(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_CRIT_RATE,AT_NONE,20,"The_Sorrowing_Body");
                Extend_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"The_Sorrowing_Body",3);
            }

            if(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->isAllyHaveSummon())
            Buff_single_with_all_memo_each(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_DMG_PERCENT,AT_NONE,80,"Benison_of_Paper_and_Rites");
            else
            Buff_single_with_all_memo_each(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_DMG_PERCENT,AT_NONE,30,"Benison_of_Paper_and_Rites");
            
            
            if(ptr->Eidolon>=1){
                if(!Buff_check(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Sub_Unit_ptr[0].get(),"Sunday_E1")){
                    Buff_single_target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Sub_Unit_ptr[0].get(),"Def_shred",AT_NONE,16);
                    Buff_single_target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Sub_Unit_ptr[0].get(),"Def_shred","Summon",24);
                    chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get())->Sub_Unit_ptr[0]->Buff_check["Sunday_E1"]=1;
                }
                Buff_single_with_all_memo_each(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"Def_shred",AT_NONE,40,"Sunday_E1");
            }
            
            if(ptr->Technique==1&&!Buff_check(ptr->getSubUnit(),"Technique_use")){
                Buff_single_with_all_memo_each(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),ST_DMG_PERCENT,AT_NONE,50,"The_Glorious_Mysteries");
                ptr->getSubUnit()->setBuffCheck("Technique_use",1);
                ptr->Sub_Unit_ptr[0]->Buff_check["Technique_use"]=1;
                Extend_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"The_Glorious_Mysteries",2);
            }
            
            Extend_Buff_single_with_all_memo(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()),"Benison_of_Paper_and_Rites",2);
            
            
            //Action Forward
            for(std::unique_ptr<Unit> &e : chooseCharacterBuff(ptr->getSubUnit())->Summon_ptr){
                Action_forward(e->Atv_stats.get(),100);
            }
            for(int i=1 ;i<chooseCharacterBuff(ptr->getSubUnit())->Sub_Unit_ptr.size();i++){
                Action_forward(chooseCharacterBuff(ptr->getSubUnit())->getSubUnit(i)->Atv_stats.get(),100);
            }
            Action_forward(chooseCharacterBuff(ptr->getSubUnit())->getSubUnit()->Atv_stats.get(),100);
        };
        Action_bar.push(temp);
        
    }





    bool ult_condition(Ally *ptr){
        //if(Current_atv<150&&(Ally_unit[Main_dps_num]->Countdown_ptr[0]->Atv_stats->Base_speed==-1))return true;
        return false;
    }

}
#endif