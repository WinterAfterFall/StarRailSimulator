#include "../include.h"

namespace Rappa{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void enchanceBasicAtk(CharUnit *ptr);
    void skillFunc(CharUnit *ptr);

    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(96, 140, 140, eidolon, ElementType::IMAGINARY, Path::ERUDITION, "Rappa", UnitType::STANDARD);
        AllyUnit *rappaPtr = ptr;
        ptr->setAllyBaseStats(1087,718,461);
        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);



        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            if (allyPtr->buffCheck["Rappa_Ult"] == 0) {
            skillFunc(ptr);
            } else {
            enchanceBasicAtk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->buffCheck["Rappa_Ult"] == 1)return false;
            return true;
        });
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {

            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"Rappa Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                if (ptr->print)CharCmd::printUltStart("Rappa");
                ptr->buffCheck["Rappa_Ult"] = 1;
                ptr->stack["Rappa_Ult"] = 2;
                ptr->statsType[Stats::BE][AType::NONE] += 30;
                ptr->statsType[Stats::BREAK_EFF][AType::NONE] += 50;
                if (ptr->eidolon >= 1)ptr->statsType[Stats::DEF_SHRED][AType::NONE] += 15;
                

                shared_ptr<AllyAttackAction> data2 = 
                make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"Rappa EBA",
                [ptr](shared_ptr<AllyAttackAction> &data2){
                    increaseEnergy(ptr, 20);
                    attack(data2);
                });
                double temp = ptr->stack["Rappa_Talent"] + 2;
                ptr->buffNote["Rappa_Talent"] = ptr->stack["Rappa_Talent"] * 0.5 + 0.6;
                ptr->stack["Rappa_Talent"] = 0;

                data2->dontCareWeakness = 50;
                data2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 10),
                    DmgSrc(DmgSrcType::ATK, 50, 5)
                );
                data2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 10),
                    DmgSrc(DmgSrcType::ATK, 50, 5)
                );
                data2->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
                    DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp) 
                );
                data2->addToActionBar();
                dealDamage();
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::BE][AType::NONE] += 13.3;
            ptr->atvStats->flatSpeed += 9;

            // relic

            // substats

            // skill
        }));




        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_DEBUFF, ptr, [](CharUnit *ptr) {
            Enemy *enemyUnit = turn->canCastToEnemy();
            if (enemyUnit) {
                
                if (isDebuffEnd(enemyUnit,"Withered_Leaf")) {
                    debuffSingle(enemyUnit,{{Stats::VUL,AType::BREAK,-enemyUnit->debuffNote["Withered_Leaf"]}});
                }
            }
            if (turn->name == "Rappa") {
                if (ptr->stack["Rappa_Ult"] == 0 && ptr->buffCheck["Rappa_Ult"] == 1) {
                    ptr->statsType[Stats::BE][AType::NONE] -= 30;
                    ptr->statsType[Stats::BREAK_EFF][AType::NONE] -= 50;

                    ptr->buffCheck["Rappa_Ult"] = 0;
                    if (ptr->eidolon >= 1) {
                        ptr->statsType[Stats::DEF_SHRED][AType::NONE] -= 15;
                        increaseEnergy(ptr, 20);
                    }
                    if (ptr->print == 1) {
                        cout << " --------------Rappa Ult End at     " << currentAtv << endl;
                    }
                }
            }
        }));


        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            if(act->attacker->atvStats->name=="Rappa"){
                if(ptr->buffCheck["Rappa_Ult"]==1){
                    superbreakTrigger(act,60,"");

                    shared_ptr<AllyAttackAction> data2 = 
                    make_shared<AllyAttackAction>(AType::BREAK,ptr,TraceType::AOE,"Rappa Talent");
                    double temp = ptr->buffNote["Rappa_Talent"];
                    for(int i=1;i<=totalEnemy;i++){
                        calBreakDamage(act,enemyUnit[i].get(),temp);
                    }
                    ptr->buffNote["Rappa_Talent"] = 0;
                }
            }
        }));


        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            if (ptr->technique == 1) {
                increaseEnergy(ptr, 10);
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::BREAK,ptr,TraceType::AOE,"Rappa Tech");
                shared_ptr<AllyAttackAction> data2 = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Rappa Tech");
                for (int i = 1; i <= totalEnemy; i++) {
                    double temp;
                   
                    if (enemyUnit[i]->targetType == EnemyType::MAIN) {
                        temp = 2;
                        calBreakDamage(act, enemyUnit[i].get(), temp);
                    } else {
                        temp = 1.8;
                        calBreakDamage(act, enemyUnit[i].get(), temp);
                    }
                    calToughnessReduction(data2, enemyUnit[i].get(), 30);
                }
            }
        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,rappaPtr](Enemy *target, AllyUnit *breaker) {
            ptr->stack["Rappa_Talent"]++;
            if (target->maxToughness > 90) {
                ptr->stack["Rappa_Talent"]++;
                increaseEnergy(ptr, 10);
            }
            double temp = floor((calculateAtkForBuff(ptr,100) - 2400) / 100) + 2;
            if (temp > 10) 
            temp = 10;
            if (temp < 0)
            temp = 0;
            target->debuffNote["Withered_Leaf"] = target->debuffNote["Withered_Leaf"];
            debuffSingleApply(rappaPtr,target,{{Stats::VUL, AType::BREAK, temp - target->debuffNote["Withered_Leaf"]}},"Withered_Leaf",2);
        }));
    }


    void enchanceBasicAtk(CharUnit *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"Rappa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr, 20);
            attack(act);
        });
        double temp = ptr->stack["Rappa_Talent"]+2;
        ptr->buffNote["Rappa_Talent"] = ptr->stack["Rappa_Talent"]*0.5+0.6;
        ptr->stack["Rappa_Talent"] = 0;

        act->dontCareWeakness = 50;
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 10),
            DmgSrc(DmgSrcType::ATK, 50, 5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 10),
            DmgSrc(DmgSrcType::ATK, 50, 5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp),
            DmgSrc(DmgSrcType::ATK, 100, 5.0 + temp) 
        );
        act->addToActionBar();
        ptr->stack["Rappa_Ult"]--;
    }
    void skillFunc(CharUnit *ptr){
        
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"Rappa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5) 
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5),
            DmgSrc(DmgSrcType::ATK, 60, 5) 
        );
        act->addToActionBar();
    }
}