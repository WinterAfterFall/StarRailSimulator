#include "../include.h"

namespace Luocha{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);
    void talent(CharUnit *ptr);
    void abyssFlower(CharUnit *ptr);


    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(101,100,100,eidolon,ElementType::IMAGINARY,Path::ABUNDANCE,"Luocha",UnitType::STANDARD);
        ptr->setAllyBaseStats(1280,756,363);

        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
       ptr->turnFunc = [ptr]() {
            basicAtk(ptr);
        };

        ptr->addUltCondition([ptr]() -> bool {
            // Field กางอยู่ -> ยังไม่กด ult รอให้หมดก่อน
            return !ptr->getBuffCheck("Cycle_of_Life");
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_DEBUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Luocha Ult",
        [ptr](shared_ptr<AllyAttackAction> &act){
            attack(act);
            // E6: ลด All-Type RES ศัตรูทุกตัว 20% 2 เทิร์น
            // RESPEN ที่ statsType (ไม่ผูก element) = ลดทุกธาตุ (ดู CalStats.h:274)
            if(ptr->eidolon>=6)debuffAllEnemyApply(ptr,{{Stats::RESPEN,AType::NONE,20}},"Luocha E6",2);
            ++ptr->stack["Abyss_Flower"];
            abyssFlower(ptr);
        });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20));
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::HP_P][AType::NONE] += 18;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 12.5;

            // relic

            // substats
        }));


        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [charPtr = ptr](CharUnit *ptr) {
            if (turn->name == "Luocha") {
                if (isBuffEnd(charPtr,"Cycle_of_Life")) {
                    if (ptr->eidolon >= 1) {
                        buffAllAlly({{Stats::ATK_P,AType::NONE,-20}});
                    }
                }
            }
            Enemy *enemy = turn->canCastToEnemy();
            if (enemy && isDebuffEnd(enemy,"Luocha E6")) {
                debuffSingle(enemy,{{Stats::RESPEN,AType::NONE,-20}});
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (ptr->technique == 1) {
                ptr->stack["Abyss_Flower"] = 2;
                abyssFlower(ptr);
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->getBuffCheck("Cycle_of_Life")) {
                ptr->restoreHP(
                    act->attacker,
                    HealSrc(HealSrcType::ATK,18,HealSrcType::CONST,240),
                    HealSrc(HealSrcType::ATK,7,HealSrcType::CONST,93)
                );

            }
        }));
        

    }


    void talent(CharUnit *ptr){
        increaseEnergy(ptr,30);
        ++ptr->stack["Abyss_Flower"];

        // E2: เป้าที่จะได้ฮีลคือคนที่เสีย HP เยอะสุด (restoreHP 3 args เลือกแบบนี้ - ดู ChangeHP.h:3)
        //   HP < 50%  -> Luocha Outgoing Healing +30% เฉพาะการฮีลครั้งนี้
        //   HP >= 50% -> kit ให้ Shield 18% ATK + 240 : engine ยังไม่มีระบบ shield จึงข้าม
        bool e2Boost = false;
        if(ptr->eidolon>=2){
            AllyUnit *healTarget = nullptr;
            double mostLost = -1;
            for(auto &each : allyList){
                if(!each->isTargetable())continue;
                if(calculateHPLost(each) > mostLost){
                    mostLost = calculateHPLost(each);
                    healTarget = each;
                }
            }
            if(healTarget && healTarget->currentHP*2 < healTarget->totalHP)e2Boost = true;
        }

        if(e2Boost)buffSingle(ptr,{{Stats::HEALING_OUT,AType::NONE,30}});
        ptr->restoreHP(HealSrc(HealSrcType::ATK,60,HealSrcType::CONST,800),HealSrc(),HealSrc());
        if(e2Boost)buffSingle(ptr,{{Stats::HEALING_OUT,AType::NONE,-30}});

        abyssFlower(ptr);
        
    }
    // E4 (ขณะ Field active -> ศัตรู Weakened สร้าง DMG น้อยลง 12%) ไม่ได้ implement
    // engine ไม่ได้คำนวณดาเมจที่ศัตรูสร้างใส่ฝ่ายเรา จึงไม่มีจุดให้ผลนี้เกาะ
    // (Stats::MITIGRATION เป็นการลดดาเมจ "ที่ฝ่ายเราตีออก" ไม่ใช่ดาเมจที่รับเข้า - ดู CalStats.h:399)
    void abyssFlower(CharUnit *ptr){
        if(ptr->stack["Abyss_Flower"]>=2){
            // kit: ครบ 2 stack -> กินทั้งหมดแล้วกาง Field
            // Field active เช็คจาก buffCheck["Cycle_of_Life"] ไม่ใช่จำนวน stack (stack ถูกกินไปแล้ว)
            bool wasActive = ptr->getBuffCheck("Cycle_of_Life");
            ptr->stack["Abyss_Flower"] -= 2;
            ptr->setBuffCheck("Cycle_of_Life",1);
            extendBuffTime(ptr,"Cycle_of_Life",2);
            if(ptr->eidolon>=1&&!wasActive){
                buffAllAlly({{Stats::ATK_P,AType::NONE,20}});
            }
        }
    }
    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Luocha BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
            if(ptr->atvStats->turnCnt%2==1){
                talent(ptr);
            }
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,4));
        act->addToActionBar();

    }





    

    
}