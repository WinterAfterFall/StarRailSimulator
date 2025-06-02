
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
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
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

            AllyActionData act = AllyActionData();
            // act.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),);
            act.actionFunction = [ptr](shared_ptr<AllyActionData> &act) {

            };
            Action_bar.push(act);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            // ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 12.5;
            // ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            // ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Lightning"][AT_NONE] += 22.4;

            // relic


            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += ptr->ExtraSpeed;
            
            // countdown
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"][AT_NONE] += 720;
            ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));



        // SetMemoStats(Ally_unit[num].get(),66,35,"Lightning","Garmentmaker","Memosprite");
        // SetCountdownStats(Ally_unit[num].get(),"Supreme_Stance");
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr](){

        };
        ptr->Countdown_ptr[0]->Turn_func = [ptr](){

        };


    }

}
#endif