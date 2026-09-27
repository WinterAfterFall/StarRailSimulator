#include "../include.h"

namespace Tribbie{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void printStats(CharUnit *ptr);

    



//temp
    void skill(CharUnit *ptr);
    void basicAtk(CharUnit *ptr);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(96,120,120,eidolon,ElementType::QUANTUM,Path::HARMONY,"Tribbie",UnitType::STANDARD);
        AllyUnit *tbPtr = ptr;
        ptr->setAllyBaseStats(1048,524,728);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CR,Stats::HP_P,Stats::HP_P,Stats::ER);



        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            if (allyPtr->getBuffCheck("Numinosity")) {
                basicAtk(ptr);
            } else {
                skill(ptr);
            }
        };

        ptr->charSetup.printFunc = printStats;

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [tbPtr](CharUnit *ptr) {

            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"TB Ult",
            [ptr,tbPtr](shared_ptr<AllyAttackAction> &act){
                if (isHaveToAddBuff(tbPtr,"Tribbie_Zone",2)) {
                        debuffAllEnemyMark({{Stats::VUL,AType::NONE,30}},ptr,"Tribbie_Zone");
    
                    // A4 Trace
                    ptr->buffNote["Tribbie_A4"] = 0;
                    for (int i = 1; i <= totalAlly; i++) {
                        ptr->buffNote["Tribbie_A4"] += calculateHpForBuff(charUnit[i].get(), 9);
                    }
                    buffSingle(tbPtr,{{Stats::FLAT_HP, AType::TEMP , ptr->buffNote["Tribbie_A4"]}});
                    buffSingle(tbPtr,{{Stats::FLAT_HP, AType::NONE, ptr->buffNote["Tribbie_A4"]}});
    
                    if (ptr->eidolon >= 4) {
                        buffAllAlly({{Stats::DEF_SHRED, AType::NONE, 18}});
                    }
                }
                for (int i = 1; i <= totalAlly; i++) {
                    if (i == ptr->atvStats->num) continue;
                    charUnit[i]->buffCheck["Tribbie_ult_launch"] = 0;
                }
                attack(act);
                
                if (ptr->print)CharCmd::printUltStart("Tribbie");
                if (ptr->eidolon >= 6) {
                    shared_ptr<AllyAttackAction> data2 = 
                    make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"TB Fua",
                    [ptr](shared_ptr<AllyAttackAction> &act){
                        increaseEnergy(ptr, 5);
                        attack(act);
                    });
                    data2->addDamageIns(
                        DmgSrc(DmgSrcType::HP,18,5),
                        DmgSrc(DmgSrcType::HP,18,5),
                        DmgSrc(DmgSrcType::HP,18,5)
                    );
                    data2->addToActionBar();
                    dealDamage();
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,30,20),
                DmgSrc(DmgSrcType::HP,30,20),
                DmgSrc(DmgSrcType::HP,30,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [tbPtr](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;

            // relic

            // substats
            if (ptr->eidolon >= 6) {
                ptr->statsType[Stats::DMG][AType::FUA] += 729;
            }
        }));


        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [tbPtr](CharUnit *ptr) {
            if (isBuffEnd(tbPtr,"Tribbie_Zone")) {
                ptr->buffCheck["Tribbie_Zone"] = 0;
                for(auto &each : enemyList){
                    debuffRemove(each,"Tribbie_Zone");
                    debuffSingle(each,{{Stats::VUL,AType::NONE,-30}});
                }
                if (ptr->eidolon >= 4) {
                    buffAllAlly({{Stats::DEF_SHRED, AType::NONE, -18}});
                }

                buffSingle(tbPtr,{{Stats::FLAT_HP, AType::TEMP , -ptr->buffNote["Tribbie_A4"]}});
                buffSingle(tbPtr,{{Stats::FLAT_HP, AType::NONE, -ptr->buffNote["Tribbie_A4"]}});

                ptr->buffNote["Tribbie_A4"] = 0;
                if (ptr->print)CharCmd::printUltEnd("Tribbie");
            }
            if (isBuffEnd(tbPtr,"Numinosity")) {
                buffAllAlly({{Stats::RESPEN, AType::NONE, -24}});
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [tbPtr](CharUnit *ptr) {
            if (isBuffEnd(tbPtr,"Tribbie_A2")) {
                buffResetStack(tbPtr,{{Stats::DMG, AType::NONE, 72}},"Tribbie_A2");
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [tbPtr](CharUnit *ptr) {
            increaseEnergy(ptr, 30);
            buffAllAlly({{Stats::RESPEN, AType::NONE, 24}});
            isHaveToAddBuff(tbPtr,"Numinosity", 3);
        }));
        
        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,tbPtr](shared_ptr<AllyAttackAction> &act) {
            int temp = act->targetList.size();
            if (act->isSameAction("Tribbie",AType::FUA)) {
                buffStackSingle(ptr,{{Stats::DMG, AType::NONE, 72}},1,3,"Tribbie_A2",3);
            }
            increaseEnergy(ptr, (1.5) * temp);
            if (tbPtr->getBuffCheck("Tribbie_Zone")) {
                shared_ptr<AllyAttackAction> data1 = 
                make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"TB AddDmg");
                if (ptr->eidolon >= 2) {
                    data1->addDamageIns(DmgSrc(DmgSrcType::HP,14.4 * (temp + 1)));
                } else {
                    data1->addDamageIns(DmgSrc(DmgSrcType::HP,12 * temp));
                }

                attack(data1);
            }
            if (act->isSameAction(AType::ULT)&& act->attacker->getBuffCheck("Tribbie_ult_launch") == 0 && act->attacker->atvStats->name != "Tribbie" && act->attacker->atvStats->side == Side::ALLY) {
                act->attacker->buffCheck["Tribbie_ult_launch"] = 1;
                shared_ptr<AllyAttackAction> data2 = 
                make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"TB Fua",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    increaseEnergy(ptr, 5);
                    attack(act);
                });
                data2->addDamageIns(
                    DmgSrc(DmgSrcType::HP,18,5),
                    DmgSrc(DmgSrcType::HP,18,5),
                    DmgSrc(DmgSrcType::HP,18,5)
                );
                data2->addToActionBar();
                dealDamage();
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,tbPtr](AllyUnit *target, Stats statsType) {
            if (!tbPtr->getBuffCheck("Tribbie_Zone")) return;
            if (statsType == Stats::HP_P || statsType == Stats::FLAT_HP) {
                // adjust
                double temp = 0;
                for (int i = 1; i <= totalAlly; i++) {
                    temp += calculateHpForBuff(charUnit[i].get(), 9);
                }
                
                // after
                buffSingle(tbPtr,{{Stats::FLAT_HP, AType::TEMP , temp - ptr->buffNote["Tribbie_A4"]}});
                buffSingle(tbPtr,{{Stats::FLAT_HP, AType::NONE, temp - ptr->buffNote["Tribbie_A4"]}});
                ptr->buffNote["Tribbie_A4"] = temp;
                return;
            }
        }));  
        if(ptr->eidolon>=1){
            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,tbPtr](shared_ptr<AllyAttackAction> &act) {
                if(tbPtr->getBuffCheck("Tribbie_Zone"))tbPtr->setBuffCheck("TB_TrueDmg",1);
            }));
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,tbPtr](shared_ptr<AllyAttackAction> &act) {
                tbPtr->setBuffCheck("TB_TrueDmg",0);
            }));
            afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,tbPtr]
                (shared_ptr<AllyAttackAction> &act, Enemy *target, double damage) {
                if(!tbPtr->getBuffCheck("TB_TrueDmg"))return;
                calDamageNote(act,target,enemyUnit[mainEnemyNum].get(),damage,24,"TB True " + act->actionName);
            }));
        }

    }


    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"TB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,30,10),
            DmgSrc(DmgSrcType::HP,15,5)
        );
        act->addToActionBar();
    }
    
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::AOE,"TB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            buffAllAlly({{Stats::RESPEN,AType::NONE,24}});
            isHaveToAddBuff(ptr,"Numinosity", 3);
        });
        act->addBuffAllAllies();
        act->addToActionBar();
    }






    void printStats(CharUnit *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->buffCheck["Numinosity"]<<" ";
        cout<<ptr->buffCheck["Tribbie_Zone"]<<" ";
        cout<<ptr->stack["Tribbie_A2"]<<" ";
        cout<<ptr->buffNote["Tribbie_A4"]<<" ";
        for(int i=1;i<=totalAlly;i++){
                if(i==ptr->atvStats->num)continue;
                cout<<charUnit[i]->buffCheck["Tribbie_ult_launch"]<<" ";
            }
    }
}
