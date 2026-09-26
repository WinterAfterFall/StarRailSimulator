#include "../include.h"

namespace Luocha{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Talent(CharUnit *ptr);
    void Abyss_Flower(CharUnit *ptr);


    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,100,100,E,ElementType::Imaginary,Path::Abundance,"Luocha",UnitType::Standard);
        ptr->SetAllyBaseStats(1280,756,363);

        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
       ptr->Turn_func = [ptr]() {
            Basic_Atk(ptr);
        };

        ptr->addUltCondition([ptr]() -> bool {
            // Field กางอยู่ -> ยังไม่กด ult รอให้หมดก่อน
            return !ptr->getBuffCheck("Cycle_of_Life");
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, ptr, [ptr]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Luocha Ult",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Attack(act);
            // E6: ลด All-Type RES ศัตรูทุกตัว 20% 2 เทิร์น
            // RESPEN ที่ Stats_type (ไม่ผูก element) = ลดทุกธาตุ (ดู CalStats.h:274)
            if(ptr->Eidolon>=6)debuffAllEnemyApply(ptr,{{Stats::RESPEN,AType::None,20}},"Luocha E6",2);
            ++ptr->stack["Abyss_Flower"];
            Abyss_Flower(ptr);
        });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20));
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Stats_type[Stats::DEF_P][AType::None] += 12.5;

            // relic

            // substats
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr]() {
            if (turn->Name == "Luocha") {
                if (isBuffEnd(Charptr,"Cycle_of_Life")) {
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{Stats::ATK_P,AType::None,-20}});
                    }
                }
            }
            Enemy *enemy = turn->canCastToEnemy();
            if (enemy && isDebuffEnd(enemy,"Luocha E6")) {
                debuffSingle(enemy,{{Stats::RESPEN,AType::None,-20}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ptr->stack["Abyss_Flower"] = 2;
                Abyss_Flower(ptr);
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->getBuffCheck("Cycle_of_Life")) {
                ptr->RestoreHP(
                    act->Attacker,
                    HealSrc(HealSrcType::ATK,18,HealSrcType::CONST,240),
                    HealSrc(HealSrcType::ATK,7,HealSrcType::CONST,93)
                );

            }
        }));
        

    }


    void Talent(CharUnit *ptr){
        Increase_energy(ptr,30);
        ++ptr->stack["Abyss_Flower"];

        // E2: เป้าที่จะได้ฮีลคือคนที่เสีย HP เยอะสุด (RestoreHP 3 args เลือกแบบนี้ - ดู ChangeHP.h:3)
        //   HP < 50%  -> Luocha Outgoing Healing +30% เฉพาะการฮีลครั้งนี้
        //   HP >= 50% -> kit ให้ Shield 18% ATK + 240 : engine ยังไม่มีระบบ shield จึงข้าม
        bool e2Boost = false;
        if(ptr->Eidolon>=2){
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

        if(e2Boost)buffSingle(ptr,{{Stats::HEALING_OUT,AType::None,30}});
        ptr->RestoreHP(HealSrc(HealSrcType::ATK,60,HealSrcType::CONST,800),HealSrc(),HealSrc());
        if(e2Boost)buffSingle(ptr,{{Stats::HEALING_OUT,AType::None,-30}});

        Abyss_Flower(ptr);
        
    }
    // E4 (ขณะ Field active -> ศัตรู Weakened สร้าง DMG น้อยลง 12%) ไม่ได้ implement
    // engine ไม่ได้คำนวณดาเมจที่ศัตรูสร้างใส่ฝ่ายเรา จึงไม่มีจุดให้ผลนี้เกาะ
    // (Stats::Mitigration เป็นการลดดาเมจ "ที่ฝ่ายเราตีออก" ไม่ใช่ดาเมจที่รับเข้า - ดู CalStats.h:399)
    void Abyss_Flower(CharUnit *ptr){
        if(ptr->stack["Abyss_Flower"]>=2){
            // kit: ครบ 2 stack -> กินทั้งหมดแล้วกาง Field
            // Field active เช็คจาก buffCheck["Cycle_of_Life"] ไม่ใช่จำนวน stack (stack ถูกกินไปแล้ว)
            bool wasActive = ptr->getBuffCheck("Cycle_of_Life");
            ptr->stack["Abyss_Flower"] -= 2;
            ptr->setBuffCheck("Cycle_of_Life",1);
            extendBuffTime(ptr,"Cycle_of_Life",2);
            if(ptr->Eidolon>=1&&!wasActive){
                buffAllAlly({{Stats::ATK_P,AType::None,20}});
            }
        }
    }
    void Basic_Atk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Luocha BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
            if(ptr->Atv_stats->turnCnt%2==1){
                Talent(ptr);
            }
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,4));
        act->addToActionBar();

    }





    

    
}