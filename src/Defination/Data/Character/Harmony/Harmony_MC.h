#include "../include.h"

namespace HarmonyMC{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);  
    void skillFunc(CharUnit *ptr);

    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit* ptr = setCharBasicStats( 105, 140, 140, eidolon, ElementType::IMAGINARY, Path::HARMONY, "Harmony_MC",UnitType::STANDARD);
        AllyUnit *hmcPtr = ptr;
        ptr->setAllyBaseStats(1087, 446, 679);
        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr](){
            if(sp > spSafety || ptr->atvStats->turnCnt == 1){
                skillFunc(ptr);           
            } else {
                basicAtk(ptr);
            }
        };
        
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hmcPtr](CharUnit *ptr){

            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"HMC Ult",
            [ptr,hmcPtr](shared_ptr<AllyBuffAction> &act){
                if(isHaveToAddBuff(hmcPtr,"Harmony_MC_ult",3))
                buffAllAlly({{Stats::BE,AType::NONE,33}});
            });
            act->addBuffAllAllies();

            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            ptr->statsType[Stats::BE][AType::NONE] += 37.3;
            ptr->statsType[Stats::RES][AType::NONE] += 10;
            ptr->statsEachElement[Stats::DMG][ElementType::IMAGINARY][AType::NONE] += 14.4;

            // relic

            // substats
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hmcPtr](CharUnit *ptr){
            ptr->buffNote["Harmony_MC_E4"] = calculateBreakEffectForBuff(ptr, 15);                  
            buffAllAllyExcludingBuffer(hmcPtr,{{Stats::BE,AType::TEMP,ptr->buffNote["Harmony_MC_E4"]}});
            buffAllAllyExcludingBuffer(hmcPtr,{{Stats::BE,AType::NONE,ptr->buffNote["Harmony_MC_E4"]}});
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            if(ptr->technique == 1){
                buffAllAlly({{Stats::BE,AType::NONE,30}});
            }
            ptr->energyRecharge += 25;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hmcPtr](CharUnit *ptr){
            if(isBuffEnd(hmcPtr,"Harmony_MC_ult")){
                buffAllAlly({{Stats::BE,AType::NONE,-33}});
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr){
            if(turn->name == "Harmony_MC" && turn->turnCnt == 3){
                ptr->energyRecharge -= 25;
            }
            if(turn->side == Side::ALLY || turn->side == Side::MEMOSPRITE){
                if(turn->turnCnt == 2 && ptr->technique == 1){
                    buffSingle(charUnit[turn->num].get(),{{Stats::BE,AType::NONE,-30}});
                }
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            if(ptr->buffCheck["Harmony_MC_ult"] == 1){
                superbreakTrigger(act, 100 * (1.7 - (0.1 * totalEnemy)),"HMC");
            }
        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *breaker){
            increaseEnergy(ptr, 11);
            actionForward(target->atvStats.get(), -30);
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,hmcPtr](AllyUnit *target, Stats statsType){
            if(target->atvStats->name != "Harmony_MC") return;
            if(statsType == Stats::BE){
                double temp = calculateBreakEffectForBuff(ptr, 15);
                buffAllAllyExcludingBuffer(hmcPtr,{{Stats::BE,AType::TEMP,temp - ptr->buffNote["Harmony_MC_E4"]}});
                buffAllAllyExcludingBuffer(hmcPtr,{{Stats::BE,AType::NONE,temp - ptr->buffNote["Harmony_MC_E4"]}});
                ptr->buffNote["Harmony_MC_E4"] =  temp ;
            }
        }));
 
    }



void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"HMC BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,110,10));
        act->addToActionBar();
    }
    void skillFunc(CharUnit *ptr){
        if(ptr->atvStats->turnCnt!=1)genSkillPoint(ptr,-1);     
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BOUNCE,"RMC Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,10));
        act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,55,5),6);
        act->addToActionBar();
    }




}