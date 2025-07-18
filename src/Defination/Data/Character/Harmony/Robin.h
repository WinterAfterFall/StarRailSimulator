#include "../include.h"

namespace Robin{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    
    //temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    bool Double_Turn(Ally *ptr);
    bool Ult_Condition(Ally *ptr);
    

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(102, 160, 160, E, ElementType::Physical, "Harmony", "Robin",TYPE_STD);
        SubUnit *Robinptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1280, 640, 485);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(120);
        ptr->setRelicMainStats(ST_ATK_P,ST_ATK_P,ST_ATK_P,ST_EnergyRecharge);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,allyptr = ptr->Sub_Unit_ptr[0].get()]() {
            if (!allyptr->getBuffCheck("Pinion'sAria")) {
            Skill(ptr);
            } else {
            Basic_Atk(ptr);
            }
        };
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Robinptr](){
            if(Driver_Type=="Double_turn"){
                if(Double_Turn(ptr))return;
            }else if(Driver_Type=="Swap_pull"){
                //if(Ally_unit[Driver_num]->Atv_stats->atv <= Ally_unit[Main_dps_num]->Atv_stats->atv &&Ally_unit[Main_dps_num]->Sub_Unit_ptr[0]->Summon_ptr==nullptr)return;
            }else if(Driver_Type=="Always_pull"){
                // if(Ally_unit[Driver_num]->Atv_stats->Name=="Hanabi"){
                //     if(Ally_unit[Driver_num]->Atv_stats->atv <= Ally_unit[Main_dps_num]->Atv_stats->atv)return;
                // }
                // if(Ally_unit[Driver_num]->Atv_stats->Name=="Sunday"){
                //     if(Ally_unit[Main_dps_num]->Sub_Unit_ptr[0]->Summon_ptr==nullptr){
                //         if(Ally_unit[Driver_num]->Atv_stats->atv <= Ally_unit[Main_dps_num]->Atv_stats->atv )return;
                //     }else{
                //     if(Ally_unit[Main_dps_num]->Atv_stats->turn_cnt <2||Ally_unit[Main_dps_num]->Sub_Unit_ptr[0]->Summon_ptr->Atv_stats->atv==0)return;
                //     if(Ally_unit[Driver_num]->Atv_stats->atv <=Ally_unit[Driver_num]->Atv_stats->Max_atv*0.5 )return;
                //     }
                // }
            }else{
                // if(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->atv < chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Max_atv*0.5 )return;
            }
            // if(Ult_Condition(ptr))return;
            if(ptr->Countdown_ptr[0]->isDeath() && ptr->Sub_Unit_ptr[0]->getBuffCheck("Pinion'sAria")&& ultUseCheck(ptr)){
                shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"RB Ult",
                [ptr,Robinptr](shared_ptr<AllyBuffAction> &act){
                    ptr->Countdown_ptr[0]->summon();
                    ptr->Sub_Unit_ptr[0]->Atv_stats->baseSpeed = -1;
                    Update_Max_atv(ptr->Sub_Unit_ptr[0]->Atv_stats.get());
                    resetTurn(ptr->Sub_Unit_ptr[0]->Atv_stats.get());

                    ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"] = calculateAtkForBuff(ptr->Sub_Unit_ptr[0].get(), 22.8) + 200;
                    buffAllAlly({{"Flat_Atk", AT_TEMP, ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});
                    buffAllAlly({{"Flat_Atk", AT_NONE, ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});

                    buffAllAlly({{ST_CD, "Fua", 25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{"Respen", AT_NONE, 24}});
                    if(ptr->Eidolon >= 2)Robinptr->buffAllAllyExcludingBuffer({{ST_SPD,ST_SPD_P,16}});
                    
                    All_Action_forward(100);
                });
                act->addBuffAllAllies();
                act->addToActionBar();
                if(ptr->Print)CharCmd::printUltStart("Robin");
                Deal_damage();
            }
            return;
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;
            // relic
            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->baseSpeed = 102;
            return;
        }));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                Increase_energy(ptr, 5);
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 25);
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({{ST_CD, AT_NONE, 20}});
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Robinptr](){
            if(Robinptr->isBuffEnd("Pinion'sAria")){
                buffAllAlly({{ST_DMG, AT_NONE, -50}});
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr, 2);
            if(ptr->Eidolon >= 2){
                Increase_energy(ptr, 1);
            }
            if(!ptr->Countdown_ptr[0]->isDeath()){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(ActionType::Addtional,ptr->getSubUnit(),TT_SINGLE,"RB AddDmg");
                double x1 = 0, x2 = 0;

                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 100;
                x1 = ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE];
                x2 = Enemy_unit[Main_Enemy_num]->Stats_type[ST_CD][AT_NONE];
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] = 150;
                Enemy_unit[Main_Enemy_num]->Stats_type[ST_CD][AT_NONE] = 0;

                newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,120));
                Attack(newAct);

                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] -= 100;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] = x1;
                Enemy_unit[Main_Enemy_num]->Stats_type[ST_CD][AT_NONE] = x2;
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr](SubUnit *target, string StatsType){
            if(target->Atv_stats->Unit_Name != "Robin")return;
            if(ptr->Countdown_ptr[0]->isDeath())return;
            if(StatsType == "Atk%" || StatsType == "Flat_Atk"){
                double buffValue = calculateAtkForBuff(ptr->Sub_Unit_ptr[0].get(), 22.8) + 200;
                buffAllAlly({{"Flat_Atk", AT_TEMP, buffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});
                buffAllAlly({{"Flat_Atk", AT_NONE, buffValue - ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});
                ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"] = buffValue;
            }
        }));


        // countdown
        SetCountdownStats(ptr,90, "Concerto_state");
        ptr->Countdown_ptr[0]->Turn_func = [ptr,Robinptr](){
            if( !ptr->Countdown_ptr[0]->isDeath()){
                ptr->Countdown_ptr[0]->death();
                ptr->Sub_Unit_ptr[0]->Atv_stats->baseSpeed = 102;
                Update_Max_atv(ptr->Sub_Unit_ptr[0]->Atv_stats.get());
                resetTurn(ptr->Sub_Unit_ptr[0]->Atv_stats.get());
                buffAllAlly({{"Flat_Atk", AT_TEMP, -ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});
                buffAllAlly({{"Flat_Atk", AT_NONE, -ptr->Sub_Unit_ptr[0]->Buff_note["Concerto_state"]}});
                buffAllAlly({{ST_CD, "Fua", -25}});
                if(ptr->Eidolon >= 1)buffAllAlly({{"Respen", AT_NONE, -24}});
                if(ptr->Eidolon >= 2)Robinptr->buffAllAllyExcludingBuffer({{ST_SPD,ST_SPD_P,-16}});
                }
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),100);
                if(ptr->Print)CharCmd::printUltEnd("Robin");
            };
        
        
    }


    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"RB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,35);
            buffAllAlly({{ST_DMG,AT_NONE,50}});
            ptr->Sub_Unit_ptr[0]->setBuffCheck("Pinion'sAria",true);
            ptr->Sub_Unit_ptr[0]->extendBuffTime("Pinion'sAria", 3);
        });
        act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
        act->addToActionBar();
    }

    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"RB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    
    bool Double_Turn(Ally *ptr){
        SubUnit *target =Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->currentSubUnitTargetNum].get();

        if((Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv<Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->Max_atv*0.2 || target->Atv_stats->atv == 0))return 1;
        if((Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv < target->Atv_stats->atv))return 1;
        return 0;
    }

    bool Ult_Condition(Ally *ptr){
        //if(Current_atv<150&&(Ally_unit[Main_dps_num]->Countdown_ptr[0]->Atv_stats->Base_speed==-1))return true;

        for(int i=0;i<Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Summon_ptr.size();i++){
            if(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Summon_ptr[i]->Atv_stats->atv==0)return true;
        }
        for(int i=0;i<Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr.size();i++){
            if(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[i]->Atv_stats->atv==0)return true;
        }
        return false;
    }

}
