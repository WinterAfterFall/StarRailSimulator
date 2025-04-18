#ifndef MYDEI_H
#define MYDEI_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Mydei{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Print(Ally *ptr);
    

    //
    void Basic_Atk(Ally *ptr);      
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void GodSlayer(Ally *ptr);
    void ChargePoint(Ally *ptr,double point);
    double CalculateChargePoint(SubUnit *ptr,double Value);
    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(95,160,160,E,"Imaginary","Destruction","Mydei",TYPE_STD);
        ptr->SetAllyBaseStats(1552,427,194);

        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Hp%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"] == false) {
            Skill(ptr);
            } else {
            Enchance_Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Blast","Mydei Ult");
            data_.Add_Target_Adjacent();
            data_.Damage_spilt.Main.push_back({0, 160, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({0, 100, 0, 20});
            
            
            data_.actionFunction = [ptr](ActionData &data_) {
                for (Enemy* e : data_.Target_Attack) {
                    e->target = ptr->Sub_Unit_ptr[0].get();
                    e->debuffApply(ptr->Sub_Unit_ptr[0].get(),"Mydei_Taunt");
                }

                HealRatio healratio = HealRatio();
                healratio.setRatio(0, 0, 0, 0, 20, 0);
                Healing(healratio, ptr->Sub_Unit_ptr[0].get(), ptr->Sub_Unit_ptr[0].get());
                ChargePoint(ptr, 20);
                Attack(data_);
                if(ptr->Print) CharCmd::printUltStart("Mydei");
            };
            
            

            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM]["None"] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 5;

            // relic
            if (ptr->Body_CritDam) {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 64.8;
            } else {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 43.2;
            }
            if (ptr->Speed_Boot) {
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            } else {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Element_Orb) {
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Imaginary"]["None"] += 38.8;
            } else {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }
            if (ptr->Er_Rope) {
            ptr->Energy_recharge += 19.4;
            } else {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 43.2;
            }

            // substats
            // eidolon
        }));
        

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] = (floor((ptr->Sub_Unit_ptr[0]->totalHP - 4000) / 100) <= 40) ? floor((ptr->Sub_Unit_ptr[0]->totalHP - 4000) / 100) : 40;
            if (ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] < 0) ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] = 0;

            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_NONE] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] * 1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_TEMP] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] * 1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_NONE] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] * 0.75;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_TEMP] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] * 0.75;
            if (ptr->Eidolon >= 6) {
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"] = true;
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
            HealRatio healratio = HealRatio();
            healratio.setRatio(0, 0, 0, 0, 25, 0);
            Healing(healratio, ptr->Sub_Unit_ptr[0].get(), ptr->Sub_Unit_ptr[0].get());
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_FLAT_DEF][AT_NONE] -= 10000;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_FLAT_DEF][AT_TEMP] -= 10000;
            if (ptr->Eidolon >= 2) Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_DEF_SHRED, AT_NONE, 15);
            if (ptr->Eidolon >= 4) Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_CRIT_DAM, AT_NONE, 30);
            }

            allEventAdjustStats(ptr->Sub_Unit_ptr[0].get(), "Hp%");
            if (ptr->Technique) {
            ActionData data_ = ActionData();
            data_.Technique_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Mydei Technique");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({0, 80, 0, 0});
            data_.Damage_spilt.Adjacent.push_back({0, 80, 0, 0});
            data_.Damage_spilt.Other.push_back({0, 80, 0, 0});
            ChargePoint(ptr, 50);
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Mydei") return;
            if (StatsType == ST_FLAT_HP || StatsType == ST_HP_PERCENT) {
            if (Buff_check(ptr->Sub_Unit_ptr[0].get(), "Mydei_Vendetta")) {
                double temp = calculateHpForBuff(ptr->Sub_Unit_ptr[0].get(), 50);
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_FLAT_HP, AT_TEMP, temp - ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]);
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), ST_FLAT_HP, AT_NONE, temp - ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]);
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"] = temp;
            }
            }
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr](Unit *Trigger, SubUnit *target, double Value) {
            if (!target->isSameUnitName("Mydei")) return;
            if (Trigger->canCastToEnemy()) {
            ChargePoint(ptr, ((ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] * 2.5 + 100.0) / 100.0) * CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(), Value));
            } else {
            ChargePoint(ptr, CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(), Value));
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr](SubUnit *Healer, SubUnit *target, double Value) {
            if (!target->isSameUnitName("Mydei")) return;
            if (ptr->Eidolon < 2) return;
            Value = (Value + ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] <= target->totalHP) ? Value : target->totalHP - ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"];
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] += Value;
            ChargePoint(ptr, CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(), Value * 0.4));
        }));

        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK, [ptr](Enemy *Attacker, vector<SubUnit *> target) {
            if (ptr->Eidolon < 4) return;
            for (SubUnit *e : target) {
            if (e->isSameUnitName("Mydei")) goto jump;
            }
            return;
        jump:
            HealRatio healratio = HealRatio();
            healratio.setRatio(0, 0, 0, 0, 10, 0);
            Healing(healratio, ptr->Sub_Unit_ptr[0].get(), ptr->Sub_Unit_ptr[0].get());
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] = 0;
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_) {
            if (data_.actionName == "GodSlayer") {
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_cannot_charge"] = 1;
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_) {
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"]) {
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"] = 0;
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
            }
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_cannot_charge"] == 1) {
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_cannot_charge"] = 0;
            }
        }));
        


        ptr->SetRelic(0,1,1,0);
        ptr->SpeedRequire = 135;



        // SetMemoStats(ptr,66,35,"Lightning","MemName","Memosprite");
        // SetCountdownStats(ptr,"Name");
        // ptr->Sub_Unit_ptr[1]->Turn_func = Mem_turn;
        // ptr->Countdown_ptr[0]->Turn_func = CountDown_turn;

    }


    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30,0);
        ActionData data_ = ActionData();
        Action_bar.push(data_);
        //none complete

    }
    void Skill(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Mydei Skill");
        data_.Add_Target_Adjacent();
        data_.resetTurn();
        data_.Damage_spilt.Main.push_back({0,90,0,20});
        data_.Damage_spilt.Adjacent.push_back({0,50,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,30,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get(),0,0,50);
            Attack(data_);
        };
        
        Action_bar.push(data_);
    }
    void Enchance_Skill(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","KingSlayer");
        data_.Add_Target_Adjacent();
        data_.resetTurn();
        data_.Damage_spilt.Main.push_back({0,110,0,20});
        data_.Damage_spilt.Adjacent.push_back({0,66,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,30,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get(),0,0,35);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void GodSlayer(Ally *ptr){
        
        ActionData data_ = ActionData();
        if(ptr->Eidolon>=1){
            data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","GodSlayer");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({0,155,0,15});
            data_.Damage_spilt.Main.push_back({0,155,0,15});
            data_.Damage_spilt.Adjacent.push_back({0,155,0,10});
            data_.Damage_spilt.Adjacent.push_back({0,155,0,10});
            data_.Damage_spilt.Other.push_back({0,155,0,10});
            data_.Damage_spilt.Other.push_back({0,155,0,10});
        }else{
            data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","GodSlayer");
            data_.Add_Target_Adjacent();
            data_.Damage_spilt.Main.push_back({0,140,0,15});
            data_.Damage_spilt.Main.push_back({0,140,0,15});
            data_.Damage_spilt.Adjacent.push_back({0,84,0,10});
            data_.Damage_spilt.Adjacent.push_back({0,84,0,10});
        }
        data_.actionFunction = [ptr](ActionData &data_){
            
            Increase_energy(ptr,10,0);
            Attack(data_);
        };
        
        Action_bar.push(data_);
        if(!actionBarUse)Deal_damage();
    }




    
    
    
    void Print(Ally *ptr){
        cout<<"Talent :"<<ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]<<" ";
        cout<<"A6 :"<<ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]<<" ";
        cout<<"Talent hp :"<<ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]<<" ";
        
        cout<<endl;
    }
    
    
    
    double CalculateChargePoint(SubUnit *ptr,double Value){
        return (Value/ptr->totalHP*100.0);
    }
    void ChargePoint(Ally *ptr,double point){
        if(ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_cannot_charge"])return;
        ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]+=point;
        if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=100&&ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]==false){
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]=true;
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=100;
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"]=1;
            HealRatio healratio = HealRatio();
            healratio.setRatio(0,0,0,0,25,0);
            Healing(healratio,ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get());
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_DEF,AT_TEMP,-10000);
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_DEF,AT_NONE,-10000);
            if(ptr->Eidolon>=2)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DEF_SHRED,AT_NONE,15);
            if(ptr->Eidolon>=4)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,30);
            allEventAdjustStats(ptr->Sub_Unit_ptr[0].get(),"Hp%");
        }
        if(ptr->Eidolon>=6){
            if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=100){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=100;
                GodSlayer(ptr);
            }
        }else{
            if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=150){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=150;
                ptr->Sub_Unit_ptr[0]->Buff_note["count"]++;
                GodSlayer(ptr);
            }
        }
        
    }

    

    
}
#endif
