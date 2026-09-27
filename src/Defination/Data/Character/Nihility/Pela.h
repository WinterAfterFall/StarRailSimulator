#include "../include.h"

namespace Pela{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(105,110,110,eidolon,ElementType::ICE,Path::NIHILITY,"Pela",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            basicAtk(ptr);
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            for (int i = 1; i <= totalEnemy; i++) {
                if (enemyUnit[i]->debuffCheck["Zone_Suppression"] == 0) return true;
            }
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Pela Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED, AType::NONE, 42}}, "Zone_Suppression",2);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20),
                DmgSrc(DmgSrcType::ATK,108,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::ICE][AType::NONE] += 22.4;
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;

            // A2 Bash: kit = +20% DMG เฉพาะศัตรูที่ติด debuff → ใส่ตรง ๆ ไม่ผูกเงื่อนไข
            // (Pela ไม่ใช่ตัวดาเมจ และศัตรูติด debuff อยู่แล้วแทบตลอด)
            ptr->statsType[Stats::DMG][AType::NONE] += 20;

            // relic

            // substats
        }));


        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (ptr->technique == 1) {
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED, AType::NONE, 20}}, "Pela_Technique",2);
                increaseEnergy(ptr, 20);
            }
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffAllAlly({{Stats::EHR, AType::NONE, 10}});
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (turn->side == Side::ENEMY) {
                if (enemyUnit[turn->num]->debuffEnd["Zone_Suppression"] == enemyUnit[turn->num]->atvStats->turnCnt) {
                    enemyUnit[turn->num]->debuffCheck["Zone_Suppression"] = 0;
                    enemyUnit[turn->num]->statsType[Stats::DEF_SHRED][AType::NONE] -= 42;
                    --enemyUnit[turn->num]->totalDebuff;
                }
                if (enemyUnit[turn->num]->debuffEnd["Pela_Technique"] == turn->turnCnt) {
                    enemyUnit[turn->num]->statsType[Stats::DEF_SHRED][AType::NONE] -= 20;
                    enemyUnit[turn->num]->debuffCheck["Pela_Technique"] = 0;
                    --enemyUnit[turn->num]->totalDebuff;
                }
            }
        }));
        
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->name != "Pela") return;

            for (auto e : act->targetList) {
                if (e->totalDebuff == 0) continue;
                increaseEnergy(ptr, 11);
                break;
            }

            if (ptr->eidolon >= 6) {
                shared_ptr<AllyAttackAction> addDmg = 
                make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"Pela E6");
                for (auto e : act->targetList) {
                    addDmg->addDamageIns(DmgSrc(DmgSrcType::ATK,40),e);
                }
                attack(addDmg);
            }
        }));
    }



    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Pela BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),20);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,55,5)
        );
        act->addToActionBar();
    }
}
