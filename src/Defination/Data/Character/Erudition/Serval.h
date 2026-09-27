#include "../include.h"

namespace Serval{
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);





//temp
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(104,100,100,eidolon,ElementType::LIGHTNING,Path::ERUDITION,"Serval",UnitType::STANDARD);
        AllyUnit *servalPtr = ptr;
        ptr->setAllyBaseStats(917,653,375);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            if (allyPtr->atvStats->turnCnt % 3 != 1) {
                basicAtk(ptr);
            } else {
                skill(ptr);
            }
        };

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::EHR][AType::NONE] += 18;
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsType[Stats::RES][AType::NONE] += 10;

            // relic

            // substats
        }));

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Serval Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                attack(act);
                if (ptr->eidolon >= 4){
                    for (auto &each : enemyList) {
                        if (debuffApply(ptr,each,"Serval_Shock")) {
                            each->changeShock(1);
                        }
                    }
                    extendDebuffAll("Serval_Shock", 2);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20),
                DmgSrc(DmgSrcType::ATK,194,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            if (turn->name == "Serval") {
                if (isBuffEnd(ptr,"Serval_A6")) {
                    ptr->statsType[Stats::ATK_P][AType::NONE] -= 20;
                }
            }
            if (turn->side == Side::ENEMY) {
                Enemy *tempstats = dynamic_cast<Enemy*>(turn->charptr);
                if (tempstats) {
                    if (isDebuffEnd(tempstats,"Serval_Shock")) {
                        tempstats->changeShock(-1);
                    }
                }
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            increaseEnergy(ptr, 15);
            if (ptr->eidolon >= 6) {
                ptr->statsType[Stats::DMG][AType::NONE] += 30;
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_BUFF, [ptr,servalPtr](Enemy* target, double dotRatio, DotType dotType) {
            if (!target->getDebuff("Serval_Shock")) return;
            if (dotType != DotType::GENERAL && dotType != DotType::SHOCK) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,"Serval Shock");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,114),target);
            act->multiplyDmg(dotRatio);
            attack(act);
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->name != "Serval") return;
            // มีศัตรูติด Shock อยู่สักตัว -> additional DMG ใส่ศัตรูทุกตัว ยิงครั้งเดียว
            bool anyShocked = false;
            for (int i = 1; i <= totalEnemy; i++) {
                if (enemyUnit[i]->getDebuff("Serval_Shock")) {
                    anyShocked = true;
                    break;
                }
            }
            if (!anyShocked) return;

            shared_ptr<AllyAttackAction> data2 = 
            make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::AOE,"Serval AddDmg");
            data2->addDamageIns(
                DmgSrc(DmgSrcType::ATK,79),
                DmgSrc(DmgSrcType::ATK,79),
                DmgSrc(DmgSrcType::ATK,79)
            );
            attack(data2);
            if (ptr->eidolon >= 2) {
                increaseEnergy(ptr, 4);   // E2: 1 ครั้งต่อการ trigger talent
            }
        }));

        enemyDeathList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,servalPtr](Enemy *target, AllyUnit *killer) {
            buffSingle(servalPtr,{{Stats::ATK_P,AType::NONE,20}},"Serval_A6",2);
        }));


        
    }



    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Serval BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10),chooseEnemyTarget(ptr));
        if(totalEnemy>=2&&ptr->eidolon>=1){
            if(ptr->enemyTargetNum==1){
                act->addDamageHit(DmgSrc(DmgSrcType::ATK,60,0),enemyUnit[2].get());
            }else{
                act->addDamageHit(DmgSrc(DmgSrcType::ATK,60,0),enemyUnit[1].get());
            }
        }
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Serval Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            for (auto &each : enemyList) {
                if (debuffApply(ptr,each,"Serval_Shock")) {
                        each->changeShock(1);
                }
            }
            extendDebuffAll("Serval_Shock", 2);
            attack(act);
        });
        act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,154,20),
                DmgSrc(DmgSrcType::ATK,66,10)
            );
        act->addToActionBar();
        
    }
}