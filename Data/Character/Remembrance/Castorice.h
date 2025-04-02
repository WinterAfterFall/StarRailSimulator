
#ifndef Name_H
#define Name_H

#define F first
#define S second
#include "../Library.h"

namespace TemplateName{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Kamikaze(Ally *ptr);

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1630,524,485);
        SetBasicStats(Ally_unit[num].get(),95,0,0,E,"Quantum","Remembrance",num,"Castorice","Ally");

        //substats
        ptr->pushSubstats(ST_CRIT_DAM);
        ptr->pushSubstats(ST_CRIT_RATE);
        ptr->pushSubstats(ST_HP_PERCENT);
        ptr->setTotalSubstats(20);


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->SetRelic(1,0,1,0);
        Ally_unit[num]->Speed_tune_value = 0;

        SetMemoStats(Ally_unit[num].get(),0,0,"Quantum","Netherwing","Memosprite");
        // SetCountdownStats(Ally_unit[num].get(),"Supreme_Stance");
        
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (ptr->getSubUnit(1)->currentHP==0) {
                Skill(ptr);
            } else {
                Enchance_Skill(ptr);
            }
        };
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr](){
            ActionData data_ = ActionData();
            data_.Skill_set(ptr->getSubUnit(1),"Aoe","Breath Scorches the Shadow");
            data_.Add_Target_Other();
            data_.Skill_Type.push_back("Summon");
            data_.resetTurn();
            while(ptr->getSubUnit(1)->currentHP>8500){
                
                if(ptr->getSubUnit(1)->getStack("Breath Scorches")==0){
                    data_.Damage_spilt.Main.push_back({24,0,0,10});
                    data_.Damage_spilt.Adjacent.push_back({24,0,0,10});
                    data_.Damage_spilt.Other.push_back({24,0,0,10});
                }
                else if(ptr->getSubUnit(1)->getStack("Breath Scorches")==1){
                    data_.Damage_spilt.Main.push_back({28,0,0,10});
                    data_.Damage_spilt.Adjacent.push_back({28,0,0,10});
                    data_.Damage_spilt.Other.push_back({28,0,0,10});
                }
                else {
                    data_.Damage_spilt.Main.push_back({34,0,0,10});
                    data_.Damage_spilt.Adjacent.push_back({34,0,0,10});
                    data_.Damage_spilt.Other.push_back({34,0,0,10});
                }
                ptr->getSubUnit(1)->Stack["Breath Scorches"]++;
            }
            data_.Damage_spilt.Main.push_back({40,0,0,10});
            data_.Damage_spilt.Adjacent.push_back({40,0,0,10});
            data_.Damage_spilt.Other.push_back({40,0,0,10});
            data_.actionFunction = [ptr](ActionData &data_){
                Attack(data_);
            };
            Action_bar.push(data_);
            
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {

            if (!ultUseCheck(ptr)) return;

            ActionData data_ = ActionData();
            // data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),);
            data_.actionFunction = [ptr](ActionData &data_) {

            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM]["None"] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"] += 14.4;

            // relic
            if (ptr->Body_CritDam) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 32.4;
            }
            if (ptr->Speed_Boot) {
                ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 43.2;
            }
            if (ptr->Element_Orb) {
                ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"] += 38.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 43.2;
            }
            if (ptr->Er_Rope) {
                ptr->Energy_recharge += 19.4;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 43.2;
            }

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
            
            // countdown
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, ptr->Speed_tune_value);
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"]["None"] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if(Buff_end(ptr->getSubUnit(1),"NetherwingLifeSpan")){
                Kamikaze(ptr);
            }
        }));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTION, [ptr](ActionData &data_) {
            if(data_.actionName=="Wings Sweep the Ruins"){
                
            }
        }));
    }
    void Kamikaze(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->getSubUnit(1),"Aoe","Wings Sweep the Ruins");
        data_.Add_Target_Other();
        data_.Skill_Type.push_back("Summon");
        data_.Damage_spilt.Main.push_back({0,40,0,5});
        data_.Damage_spilt.Main.push_back({0,40,0,5});
        if(Total_enemy==1){
            data_.Damage_spilt.Main.push_back({0,40,0,5});
            data_.Damage_spilt.Main.push_back({0,40,0,5});
            data_.Damage_spilt.Main.push_back({0,40,0,5});
            data_.Damage_spilt.Main.push_back({0,40,0,5});

        }else if(Total_enemy==2){
            data_.Damage_spilt.Main.push_back({0,40,0,5});
            data_.Damage_spilt.Main.push_back({0,40,0,5});
            data_.Damage_spilt.Adjacent.push_back({0,40,0,5});
            data_.Damage_spilt.Adjacent.push_back({0,40,0,5});

        }else {
            data_.Damage_spilt.Adjacent.push_back({0,40,0,5});
            data_.Damage_spilt.Adjacent.push_back({0,40,0,5});
        }
        data_.actionFunction = [ptr](ActionData &data_){
            Attack(data_);
        };
        Action_bar.push(data_);
        if(!actionBarUse)Deal_damage();
        
    }


}
#endif