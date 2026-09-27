#include "../include.h"

namespace Mydei{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void print(CharUnit *ptr);
    

    //
    void basicAtk(CharUnit *ptr);      
    void skill(CharUnit *ptr);
    void enchanceSkill(CharUnit *ptr);
    void godSlayer(CharUnit *ptr);
    void chargePoint(CharUnit *ptr,double point);
    double calculateChargePoint(AllyUnit *ptr,double value);
    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(95,160,160,eidolon,ElementType::IMAGINARY,Path::DESTRUCTION,"Mydei",UnitType::STANDARD);
        AllyUnit *mydeiPtr = ptr;
        ptr->setAllyBaseStats(1552,426,194);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::DMG,Stats::HP_P);




        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->turnFunc = [ptr](){
            if (ptr->buffCheck["Mydei_Vendetta"] == false) {
            skill(ptr);
            } else {
            enchanceSkill(ptr);
            }
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::BLAST,"Mydei Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for (Enemy* e : act->targetList) {
                    // Taunt เป้าหมาย+ข้างเคียง 2 เทิร์น (kit)
                    // debuffApply 4-arg: refresh countdown เสมอ · addTaunt มี dedup อยู่แล้ว
                    debuffApply(ptr,e,"Mydei_Taunt",2);
                    e->addTaunt(ptr);
                }
                ptr->restoreHP(
                    ptr,
                    HealSrc(HealSrcType::TOTAL_HP,20)
                );
                chargePoint(ptr, 20);
                attack(act);
                if(ptr->print) CharCmd::printUltStart("Mydei");
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,160,20),
                DmgSrc(DmgSrcType::HP,100,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;
            ptr->statsType[Stats::HP_P][AType::NONE] += 18;
            ptr->atvStats->flatSpeed += 5;

            // relic

            // substats
            // eidolon
        }));
        

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [mydeiPtr](CharUnit *ptr) {
            ptr->buffNote["Mydei_A6"] = (floor((ptr->totalHP - 4000) / 100) <= 40) ? floor((ptr->totalHP - 4000) / 100) : 40;
            if (ptr->buffNote["Mydei_A6"] < 0) ptr->buffNote["Mydei_A6"] = 0;

            ptr->statsType[Stats::CR][AType::NONE] += ptr->buffNote["Mydei_A6"] * 1.2;
            ptr->statsType[Stats::CR][AType::TEMP] += ptr->buffNote["Mydei_A6"] * 1.2;
            // A6 Incoming Healing +0.75%: engine has no incoming-heal stat, Outgoing works the same for Mydei's self-heals
            ptr->statsType[Stats::HEALING_OUT][AType::NONE] += ptr->buffNote["Mydei_A6"] * 0.75;
            ptr->statsType[Stats::HEALING_OUT][AType::TEMP] += ptr->buffNote["Mydei_A6"] * 0.75;
            if (ptr->eidolon >= 6) {
            ptr->buffCheck["Mydei_Vendetta"] = true;
            actionForward(ptr->atvStats.get(), 100);
            ptr->restoreHP(
                ptr,
                HealSrc(HealSrcType::TOTAL_HP,25)
            );
            ptr->statsType[Stats::FLAT_DEF][AType::NONE] -= 10000;
            ptr->statsType[Stats::FLAT_DEF][AType::TEMP] -= 10000;
            
            if (ptr->eidolon >= 2) buffSingle(mydeiPtr,{{Stats::DEF_SHRED,AType::NONE,15}});
            if (ptr->eidolon >= 4) buffSingle(mydeiPtr,{{Stats::CD,AType::NONE,30}});
            }

            allEventAdjustStats(ptr, Stats::HP_P);
            if (ptr->technique) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Mydei Tech",
            [ptr](shared_ptr<AllyAttackAction> &act){
                chargePoint(ptr, 50);
                attack(act);
                for (Enemy* e : act->targetList) {   // AoE -> Taunt ทุกตัว 1 เทิร์น (kit)
                    debuffApply(ptr, e, "Mydei_Taunt", 1);
                    e->addTaunt(ptr);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,80,20),
                DmgSrc(DmgSrcType::HP,80,20),
                DmgSrc(DmgSrcType::HP,80,20)
            );
            act->addToActionBar();
            dealDamage();
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr,mydeiPtr](AllyUnit *target, Stats statsType) {
            if (target->atvStats->name != "Mydei") return;
            if (statsType == Stats::FLAT_HP || statsType == Stats::HP_P) {
                
            if (mydeiPtr->getBuffCheck("Mydei_Vendetta")) {
                double temp = calculateHpForBuff(ptr, 50);
                buffSingle(mydeiPtr,{{Stats::FLAT_HP,AType::TEMP,temp - ptr->buffNote["Mydei_Talent"]}});
                buffSingle(mydeiPtr,{{Stats::FLAT_HP,AType::NONE,temp - ptr->buffNote["Mydei_Talent"]}});
                ptr->buffNote["Mydei_Talent"] = temp;
            }
            }
        }));

        hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr](Unit *trigger, AllyUnit *target, double value) {
            if (!target->isSameName("Mydei")) return;
            if (trigger->canCastToEnemy()) {
            chargePoint(ptr, ((ptr->buffNote["Mydei_A6"] * 2.5 + 100.0) / 100.0) * calculateChargePoint(ptr, value));
            } else {
            chargePoint(ptr, calculateChargePoint(ptr, value));
            }
        }));

        healingList.push_back(TriggerHealing(PRIORITY_ACTTACK, [ptr](AllyUnit *healer, AllyUnit *target, double value) {
            if (!target->isSameName("Mydei")) return;
            if (ptr->eidolon < 2) return;
            value = (value + ptr->buffNote["Mydei_E2"] <= target->totalHP) ? value : target->totalHP - ptr->buffNote["Mydei_E2"];
            ptr->buffNote["Mydei_E2"] += value;
            chargePoint(ptr, calculateChargePoint(ptr, value * 0.4));
        }));

        enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK, [ptr](Enemy *attacker, vector<AllyUnit *> target) {
            if (ptr->eidolon < 4) return;
            for (AllyUnit *e : target) {
            if (e->isSameName("Mydei")) goto jump;
            }
            return;
        jump:
        ptr->restoreHP(ptr,HealSrc(HealSrcType::TOTAL_HP,10));
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            ptr->buffNote["Mydei_E2"] = 0;
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->actionName == "GodSlayer") {
            ptr->buffCheck["Mydei_cannot_charge"] = 1;
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->buffCheck["Mydei_action"]) {
            ptr->buffCheck["Mydei_action"] = 0;
            actionForward(ptr->atvStats.get(), 100);
            }
            if (ptr->buffCheck["Mydei_cannot_charge"] == 1) {
            ptr->buffCheck["Mydei_cannot_charge"] = 0;
            }
        }));

        // Mydei_Taunt หมดอายุบนศัตรูตัวไหน -> เอา Mydei ออกจาก tauntList ของตัวนั้น (แยกอิสระต่อ enemy)
        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            Enemy *e = turn->canCastToEnemy();
            if (!e) return;
            if (isDebuffEnd(e, "Mydei_Taunt")) e->removeTaunt(ptr);
        }));

        // setMemoStats(ptr,66,35,ElementType::LIGHTNING,"MemName",Side::AllyUnit);
        // setCountdownStats(ptr,"Name");
        // ptr->memosprite->turnFunc = Mem_turn;
        // ptr->countdownList[0]->turnFunc = CountDown_turn;

    }


    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act =
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Mydei BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Mydei Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            decreaseHP(ptr,ptr,0,0,50);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,90,20),
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->addToActionBar();
    }
    void enchanceSkill(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"KingSlayer",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            decreaseHP(ptr,ptr,0,0,35);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,110,20),
            DmgSrc(DmgSrcType::HP,66,10)
        );
        act->addToActionBar();
    }
    void godSlayer(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"GodSlayer",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,10);
            attack(act);
        });

        if(ptr->eidolon>=1){
            act->traceType = TraceType::AOE;
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
        dealDamage();
    }




    
    
    
    void print(CharUnit *ptr){
        cout<<"Talent :"<<ptr->buffCheck["Mydei_Vendetta"]<<" ";
        cout<<"A6 :"<<ptr->buffNote["Mydei_A6"]<<" ";
        cout<<"Talent hp :"<<ptr->buffNote["Mydei_Talent"]<<" ";
        
        cout<<endl;
    }
    
    
    
    double calculateChargePoint(AllyUnit *ptr,double value){
        return (value/ptr->totalHP*100.0);
    }
    void chargePoint(CharUnit *ptr,double point){
        if(ptr->buffCheck["Mydei_cannot_charge"])return;
        // Talent: Charge cap 200
        ptr->buffNote["Mydei_Charge_point"] = min(200.0, ptr->buffNote["Mydei_Charge_point"] + point);
        if(ptr->buffNote["Mydei_Charge_point"]>=100&&ptr->buffCheck["Mydei_Vendetta"]==false){
            ptr->buffCheck["Mydei_Vendetta"]=true;
            ptr->buffNote["Mydei_Charge_point"]-=100;
            // advance 100%: during Mydei's own action wait until it ends (resetTurn), otherwise advance now
            if(turn->isSameUnit(ptr))ptr->buffCheck["Mydei_action"]=1;
            else actionForward(ptr->atvStats.get(), 100);
            ptr->restoreHP(
                    ptr,
                    HealSrc(HealSrcType::TOTAL_HP,25)
                );
            ptr->statsType[Stats::FLAT_DEF][AType::NONE] -= 10000;
            ptr->statsType[Stats::FLAT_DEF][AType::TEMP] -= 10000;    
            if (ptr->eidolon >= 2) buffSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,15}});
            if (ptr->eidolon >= 4) buffSingle(ptr,{{Stats::CD,AType::NONE,30}});
            allEventAdjustStats(ptr,Stats::HP_P);
        }
        if(!ptr->buffCheck["Mydei_Vendetta"])return;
        if(ptr->eidolon>=6){
            if(ptr->buffNote["Mydei_Charge_point"]>=100){
                ptr->buffNote["Mydei_Charge_point"]-=100;
                godSlayer(ptr);
            }
        }else{
            if(ptr->buffNote["Mydei_Charge_point"]>=150){
                ptr->buffNote["Mydei_Charge_point"]-=150;
                godSlayer(ptr);
            }
        }
        
    }

    

    
}
