#include "../include.h"

namespace Mydei{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Print(CharUnit *ptr);
    

    //
    void Basic_Atk(CharUnit *ptr);      
    void Skill(CharUnit *ptr);
    void Enchance_Skill(CharUnit *ptr);
    void GodSlayer(CharUnit *ptr);
    void ChargePoint(CharUnit *ptr,double point);
    double CalculateChargePoint(AllyUnit *ptr,double Value);
    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(95,160,160,E,ElementType::Imaginary,Path::Destruction,"Mydei",UnitType::Standard);
        AllyUnit *Mydeiptr = ptr;
        ptr->SetAllyBaseStats(1552,427,194);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::DMG,Stats::HP_P);




        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->Turn_func = [ptr](){
            if (ptr->Buff_check["Mydei_Vendetta"] == false) {
            Skill(ptr);
            } else {
            Enchance_Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Blast,"Mydei Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for (Enemy* e : act->targetList) {
                    e->addTaunt(ptr);
                    debuffApply(ptr,e,"Mydei_Taunt");
                }
                ptr->RestoreHP(
                    ptr,
                    HealSrc(HealSrcType::TOTAL_HP,20)
                );
                ChargePoint(ptr, 20);
                Attack(act);
                if(ptr->Print) CharCmd::printUltStart("Mydei");
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,160,20),
                DmgSrc(DmgSrcType::HP,100,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Atv_stats->flatSpeed += 5;

            // relic

            // substats
            // eidolon
        }));
        

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Mydeiptr]() {
            ptr->Buff_note["Mydei_A6"] = (floor((ptr->totalHP - 4000) / 100) <= 40) ? floor((ptr->totalHP - 4000) / 100) : 40;
            if (ptr->Buff_note["Mydei_A6"] < 0) ptr->Buff_note["Mydei_A6"] = 0;

            ptr->Stats_type[Stats::CR][AType::None] += ptr->Buff_note["Mydei_A6"] * 1.2;
            ptr->Stats_type[Stats::CR][AType::TEMP] += ptr->Buff_note["Mydei_A6"] * 1.2;
            ptr->Stats_type[Stats::HEALING_OUT][AType::None] += ptr->Buff_note["Mydei_A6"] * 0.75;
            ptr->Stats_type[Stats::HEALING_OUT][AType::TEMP] += ptr->Buff_note["Mydei_A6"] * 0.75;
            if (ptr->Eidolon >= 6) {
            ptr->Buff_check["Mydei_Vendetta"] = true;
            Action_forward(ptr->Atv_stats.get(), 100);
            ptr->RestoreHP(
                ptr,
                HealSrc(HealSrcType::TOTAL_HP,25)
            );
            ptr->Stats_type[Stats::FLAT_DEF][AType::None] -= 10000;
            ptr->Stats_type[Stats::FLAT_DEF][AType::TEMP] -= 10000;
            
            if (ptr->Eidolon >= 2) buffSingle(Mydeiptr,{{Stats::DEF_SHRED,AType::None,15}});
            if (ptr->Eidolon >= 4) buffSingle(Mydeiptr,{{Stats::CD,AType::None,30}});
            }

            allEventAdjustStats(ptr, Stats::HP_P);
            if (ptr->Technique) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"Mydei Tech",
            [ptr](shared_ptr<AllyAttackAction> &act){
                ChargePoint(ptr, 50);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,80,20),
                DmgSrc(DmgSrcType::HP,80,20),
                DmgSrc(DmgSrcType::HP,80,20)
            );
            act->addToActionBar();
            Deal_damage();
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr,Mydeiptr](AllyUnit *target, Stats StatsType) {
            if (target->Atv_stats->StatsOwnerName != "Mydei") return;
            if (StatsType == Stats::FLAT_HP || StatsType == Stats::HP_P) {
                
            if (Mydeiptr->getBuffCheck("Mydei_Vendetta")) {
                double temp = calculateHpForBuff(ptr, 50);
                buffSingle(Mydeiptr,{{Stats::FLAT_HP,AType::TEMP,temp - ptr->Buff_note["Mydei_Talent"]}});
                buffSingle(Mydeiptr,{{Stats::FLAT_HP,AType::None,temp - ptr->Buff_note["Mydei_Talent"]}});
                ptr->Buff_note["Mydei_Talent"] = temp;
            }
            }
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr](Unit *Trigger, AllyUnit *target, double Value) {
            if (!target->isSameStatsOwnerName("Mydei")) return;
            if (Trigger->canCastToEnemy()) {
            ChargePoint(ptr, ((ptr->Buff_note["Mydei_A6"] * 2.5 + 100.0) / 100.0) * CalculateChargePoint(ptr, Value));
            } else {
            ChargePoint(ptr, CalculateChargePoint(ptr, Value));
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr](AllyUnit *Healer, AllyUnit *target, double Value) {
            if (!target->isSameStatsOwnerName("Mydei")) return;
            if (ptr->Eidolon < 2) return;
            Value = (Value + ptr->Buff_note["Mydei_E2"] <= target->totalHP) ? Value : target->totalHP - ptr->Buff_note["Mydei_E2"];
            ptr->Buff_note["Mydei_E2"] += Value;
            ChargePoint(ptr, CalculateChargePoint(ptr, Value * 0.4));
        }));

        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK, [ptr](Enemy *Attacker, vector<AllyUnit *> target) {
            if (ptr->Eidolon < 4) return;
            for (AllyUnit *e : target) {
            if (e->isSameStatsOwnerName("Mydei")) goto jump;
            }
            return;
        jump:
        ptr->RestoreHP(ptr,HealSrc(HealSrcType::TOTAL_HP,10));
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            ptr->Buff_note["Mydei_E2"] = 0;
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->actionName == "GodSlayer") {
            ptr->Buff_check["Mydei_cannot_charge"] = 1;
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->Buff_check["Mydei_action"]) {
            ptr->Buff_check["Mydei_action"] = 0;
            Action_forward(ptr->Atv_stats.get(), 100);
            }
            if (ptr->Buff_check["Mydei_cannot_charge"] == 1) {
            ptr->Buff_check["Mydei_cannot_charge"] = 0;
            }
        }));
        
        // SetMemoStats(ptr,66,35,ElementType::Lightning,"MemName",Side::AllyUnit);
        // SetCountdownStats(ptr,"Name");
        // ptr->memospriteList[0]->Turn_func = Mem_turn;
        // ptr->countdownList[0]->Turn_func = CountDown_turn;

    }


    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        Increase_energy(ptr,30,0);
        shared_ptr<AllyActionData> act = make_shared<AllyActionData>();
        Action_bar.push(act);
        //none complete

    }
    void Skill(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Mydei Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30,0);
            DecreaseHP(ptr,ptr,0,0,50);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,90,20),
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->addToActionBar();
    }
    void Enchance_Skill(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"KingSlayer",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30,0);
            DecreaseHP(ptr,ptr,0,0,35);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,110,20),
            DmgSrc(DmgSrcType::HP,66,10)
        );
        act->addToActionBar();
    }
    void GodSlayer(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"GodSlayer",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            Attack(act);
        });

        if(ptr->Eidolon>=1){
            act->traceType = TraceType::Aoe;
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,155,15),
                DmgSrc(DmgSrcType::HP,155,10),
                DmgSrc(DmgSrcType::HP,155,10)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,155,15),
                DmgSrc(DmgSrcType::HP,155,10),
                DmgSrc(DmgSrcType::HP,155,10)
            );
        }else{
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,140,15),
                DmgSrc(DmgSrcType::HP,84,10)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,140,15),
                DmgSrc(DmgSrcType::HP,84,10)
            );
        }
        act->addToActionBar();
        Deal_damage();
    }




    
    
    
    void Print(CharUnit *ptr){
        cout<<"Talent :"<<ptr->Buff_check["Mydei_Vendetta"]<<" ";
        cout<<"A6 :"<<ptr->Buff_note["Mydei_A6"]<<" ";
        cout<<"Talent hp :"<<ptr->Buff_note["Mydei_Talent"]<<" ";
        
        cout<<endl;
    }
    
    
    
    double CalculateChargePoint(AllyUnit *ptr,double Value){
        return (Value/ptr->totalHP*100.0);
    }
    void ChargePoint(CharUnit *ptr,double point){
        if(ptr->Buff_check["Mydei_cannot_charge"])return;
        ptr->Buff_note["Mydei_Charge_point"]+=point;
        if(ptr->Buff_note["Mydei_Charge_point"]>=100&&ptr->Buff_check["Mydei_Vendetta"]==false){
            ptr->Buff_check["Mydei_Vendetta"]=true;
            ptr->Buff_note["Mydei_Charge_point"]-=100;
            ptr->Buff_check["Mydei_action"]=1;
            ptr->RestoreHP(
                    ptr,
                    HealSrc(HealSrcType::TOTAL_HP,25)
                );
            ptr->Stats_type[Stats::FLAT_DEF][AType::None] -= 10000;
            ptr->Stats_type[Stats::FLAT_DEF][AType::TEMP] -= 10000;    
            if (ptr->Eidolon >= 2) buffSingle(ptr,{{Stats::DEF_SHRED,AType::None,15}});
            if (ptr->Eidolon >= 4) buffSingle(ptr,{{Stats::CD,AType::None,30}});
            allEventAdjustStats(ptr,Stats::HP_P);
        }
        if(ptr->Eidolon>=6){
            if(ptr->Buff_note["Mydei_Charge_point"]>=100){
                ptr->Buff_note["Mydei_Charge_point"]-=100;
                GodSlayer(ptr);
            }
        }else{
            if(ptr->Buff_note["Mydei_Charge_point"]>=150){
                ptr->Buff_note["Mydei_Charge_point"]-=150;
                ptr->Buff_note["count"]++;
                GodSlayer(ptr);
            }
        }
        
    }

    

    
}
