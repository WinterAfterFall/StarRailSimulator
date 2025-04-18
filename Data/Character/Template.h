
#ifndef Name_H
#define Name_H

#define F first
#define S second
#include "../Library.h"

namespace TemplateName{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Skill(Ally *ptr);
    void Basic_Atk(Ally *ptr);

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        // SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1242,699,485);
        // SetAllyBasicStats(Ally_unit[num].get(),102,350,350,E,"Lightning","Remembrance",num,"Aglaea",TYPE_STD);

        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats(ST_CRIT_RATE);
        ptr->pushSubstats(ST_ATK_PERCENT);
        ptr->setTotalSubstats(20);

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (1) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
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
            // ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;
            // ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 12;
            // ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 22.4;

            // relic
            if (ptr->Body_CritDam) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 32.4;
            }
            if (ptr->Speed_Boot) {
                ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Element_Orb) {
                ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 38.8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Er_Rope) {
                ptr->Energy_recharge += 19.4;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->ExtraSpeed;
            
            // countdown
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"]["None"] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        
        Ally_unit[num]->SetRelic(0,1,1,1);
        // Ally_unit[num]->Speed_tune_value = 135;



        // SetMemoStats(Ally_unit[num].get(),66,35,"Lightning","Garmentmaker","Memosprite");
        // SetCountdownStats(Ally_unit[num].get(),"Supreme_Stance");
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr](){

        };
        ptr->Countdown_ptr[0]->Turn_func = [ptr](){

        };


    }

}
#endif