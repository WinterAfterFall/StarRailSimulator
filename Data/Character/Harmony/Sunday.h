
#ifndef Sunday_H
#define Sunday_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Sunday{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Skill(Ally *ptr);

    bool ult_condition(Ally *ptr);
    



    

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(), 1242, 640, 533);
        SetBasicStats(Ally_unit[num].get(), 96, 130, 130, E, "Imaginary", "Harmony", num, "Sunday", "Ally");

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            Skill(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (ult_condition(ptr)) return;
            if (Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy <= 200 &&
                Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Current_energy < 30 &&
                Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) return;
            if (Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy >= 200 &&
                Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Current_energy < Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy * 0.2 &&
                Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) return;
            if (!ultUseCheck(ptr)) return;
            
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Buff", "Single_target","Sunday Ultimate");
            data_.Add_Buff_Single_Target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
            data_.actionFunction = [ptr](ActionData &data_){
                if (ptr->Print)Char_Command::printUltStart("Sunday");
                if (ptr->Eidolon >= 2) {
                    if (ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] == 0) {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Ult_first_time"] = 1;
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 2);
                    }
                }
                if (Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy > 200)
                Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), 20, 0);
                else
                Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), 0, 40);
                
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) {
                    if (ptr->Eidolon >= 2) 
                    Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Dmg%", "None", 30);
                    
                    ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"] = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ode_to_Caress_and_Cicatrix"] = 1;
    
                    Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", AT_TEMP, ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
                    Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", "None", ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix", 3);
            };
            Action_bar.push(data_);
            
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] += 43.2;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, ptr->Speed_tune_value);
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) {
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", "None", -ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", AT_TEMP, -ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);

                if (ptr->Eidolon >= 2) {
                    Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Dmg%", "None", -30);
                }
                ptr->Sub_Unit_ptr[0]->Buff_check["Ode_to_Caress_and_Cicatrix"] = 0;
                if (ptr->Print) cout << "-------------------------------------------------- Sunday ult end at " << Current_atv << endl;
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (turn->Side != "Ally" && turn->Side != "Memosprite") return;
            if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->allyTargetNum) return;
            Sub_Unit *Temp_stats = dynamic_cast<Sub_Unit *>(turn->ptr_to_unit);
            if (!Temp_stats) return;
            if (Buff_end(Temp_stats, "Benison_of_Paper_and_Rites")) {
                if (Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Summon_ptr.size() != 0 || Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr.size() > 1) {
                    Buff_single_target(Temp_stats, "Dmg%", "None", -80);
                } else {
                    Buff_single_target(Temp_stats, "Dmg%", "None", -30);
                }
                Temp_stats->Buff_check["Benison_of_Paper_and_Rites"] = 0;
                if (ptr->Eidolon >= 1) {
                    if (turn->Side == "Memosprite") {
                        Buff_single_target(Temp_stats, "Def_shred", "None", -40);
                    } else {
                        Buff_single_target(Temp_stats, "Def_shred", "None", -16);
                        Buff_single_target(Temp_stats, "Def_shred", "Summon", -24);
                    }
                    Temp_stats->Buff_check["Sunday_E1"] = 0;
                }
            }
            if (Buff_end(Temp_stats, "The_Sorrowing_Body")) {
                Buff_single_target(Temp_stats, "Crit_rate", "None", -20);
                Temp_stats->Buff_check["The_Sorrowing_Body"] = 0;
            }

            if (Buff_end(Temp_stats, "The_Glorious_Mysteries")) {
                Buff_single_target(Temp_stats, "Dmg%", "None", -50);
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Increase_energy(ptr, 25);
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix") && data_.Action_type.second == "Skill" && turn->Char_Name == "Sunday") {
                Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](Sub_Unit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Sunday") return;
            if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ode_to_Caress_and_Cicatrix")) return;
            if (StatsType == "Crit_dam") {
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", "None", -ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", AT_TEMP, -ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);

                ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"] = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(), 30) + 12;

                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", "None", ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
                Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(), "Crit_dam", AT_TEMP, ptr->Sub_Unit_ptr[0]->Buff_note["Ode_to_Caress_and_Cicatrix"]);
            }
        }));

        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;
        Ally_unit[num]->Speed_tune_value=133.4;
        Ally_unit[num]->Substats.push_back({"Crit_dam",20});



    }

    
    void Skill(Ally *ptr){
        
        

        ActionData temp = ActionData();
        temp.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Sunday Skill");
        temp.Add_Buff_Single_Target(chooseCharacterBuff(ptr->Sub_Unit_ptr[0].get()));
        temp.Turn_reset=true;
        temp.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            Buff_single_with_all_memo_each(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Crit_rate","None",20,"The_Sorrowing_Body");
            if(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Summon_ptr.size()!=0||Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr.size()>1){
            Buff_single_with_all_memo_each(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Dmg%","None",80,"Benison_of_Paper_and_Rites");
            }else{
            Buff_single_with_all_memo_each(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Dmg%","None",30,"Benison_of_Paper_and_Rites");
            }
            
            if(ptr->Eidolon>=1){
                if(!Buff_check(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0].get(),"Sunday_E1")){
                    Buff_single_target(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0].get(),"Def_shred","None",16);
                    Buff_single_target(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0].get(),"Def_shred","Summon",24);
                    Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0]->Buff_check["Sunday_E1"]=1;
                }
                Buff_single_with_all_memo_each(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Def_shred","None",40,"Sunday_E1");
            }
            
            if(ptr->Technique==1&&ptr->Sub_Unit_ptr[0]->Buff_check["Technique_use"]==0){
                Buff_single_with_all_memo_each(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Dmg%","None",50,"The_Glorious_Mysteries");
                ptr->Sub_Unit_ptr[0]->Buff_check["Technique_use"]=1;
                Extend_Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"The_Glorious_Mysteries",2);
            }
            
            Extend_Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"The_Sorrowing_Body",3);
            Extend_Buff_single_with_all_memo(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),"Benison_of_Paper_and_Rites",2);
            
            
            
            for(int i=0;i<Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr.size();i++){
                Action_forward(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[i]->Atv_stats.get(),100);
            }
            for(int i=0;i<Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Summon_ptr.size();i++){
                Action_forward(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Summon_ptr[i]->Atv_stats.get(),100);
            }
            Action_forward(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0]->Atv_stats.get(),100);
        };
        Action_bar.push(temp);
        
    }





    bool ult_condition(Ally *ptr){
        //if(Current_atv<150&&(Ally_unit[Main_dps_num]->Countdown_ptr[0]->Atv_stats->Base_speed==-1))return true;
        return false;
    }

}
#endif