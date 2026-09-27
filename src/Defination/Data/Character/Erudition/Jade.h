
#include "../include.h"

namespace Jade{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);


//temp
    void jadeFua(CharUnit *ptr);
    void jadeTalent(CharUnit *ptr,int amount);
    void fua(CharUnit *ptr);
    void fuaEnchance(CharUnit *ptr);


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(103,140,140,eidolon,ElementType::QUANTUM,Path::ERUDITION,"Jade",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);

        // ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);
        // ptr->setSpeedRequire(140);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            
            if (allyPtr->getBuffCheck("Jade_Skill")) {
                basicAtk(ptr);
            } else {
                skill(ptr);
            }
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Jade Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                ptr->stack["Jade_Ultimate_stack"] = 2;
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::RES][AType::NONE] += 10;
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 22.4;

            // relic
            // substats
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            jadeTalent(ptr, totalEnemy);
            actionForward(ptr->atvStats.get(), 50);
            if (ptr->technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Jade Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    jadeTalent(ptr, 15);
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0),
                    DmgSrc(DmgSrcType::ATK,50,0)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (chooseAllyBuff(ptr)->atvStats->name == turn->name) {
                jadeTalent(ptr, 3);
            }
            
            if (isBuffEnd(ptr,"Jade_Skill")) {
                buffSingle(chooseAllyBuff(ptr),{{Stats::SPD_P,AType::NONE,-30}});
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAction("Jade",AType::FUA)) {
                jadeTalent(ptr, 5);
                return;
            }
            if (ptr->buffCheck["Jade_Skill"] == 0) return;
            if (act->attacker->atvStats->name != "Jade" && act->attacker->atvStats->name != chooseAllyBuff(ptr)->atvStats->name) return;

            int temp = act->targetList.size();
            if (ptr->eidolon >= 1 && temp < 3) temp = 3;
            ptr->stack["Jade_Talent"] += temp;
            jadeFua(ptr);
        }));

        enemyDeathList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *killer){
            jadeTalent(ptr, 1);
        }));
        



        
    }



    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"Jade BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),20);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,90,10),
            DmgSrc(DmgSrcType::ATK,30,5)
        );
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Jade Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),30);
            if(isHaveToAddBuff(ptr,"Jade_Skill",3)){
                buffSingle(chooseAllyBuff(ptr),{{Stats::SPD_P,AType::NONE,30}});
            }
        });
        act->addBuffSingleTarget(chooseAllyBuff(ptr));
        act->addToActionBar();

    }


            
        

    void jadeFua(CharUnit *ptr){

        while(ptr->stack["Jade_Talent"]>8){
            ptr->stack["Jade_Talent"]-=8;
            if(ptr->stack["Jade_Ultimate_stack"]>0){
                fuaEnchance(ptr);
                ptr->stack["Jade_Ultimate_stack"]--;             
            }else{
                fua(ptr);
            }
        }
        dealDamage();
    }
    void fua(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,10);
            if(ptr->eidolon>=1)buffSingle(ptr,{{Stats::DMG,AType::NONE,32}});
            attack(act);
            if(ptr->eidolon>=1)buffSingle(ptr,{{Stats::DMG,AType::NONE,-32}});
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5),
            DmgSrc(DmgSrcType::ATK,18,1.5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,48,4),
            DmgSrc(DmgSrcType::ATK,48,4),
            DmgSrc(DmgSrcType::ATK,48,4)
        );
        act->addToActionBar();
    }
    void fuaEnchance(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"Jade Fua",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,10);
            if(ptr->eidolon>=1)buffSingle(ptr,{{Stats::DMG,AType::NONE,32}});
            attack(act);
            if(ptr->eidolon>=1)buffSingle(ptr,{{Stats::DMG,AType::NONE,-32}});
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1),
            DmgSrc(DmgSrcType::ATK,20,1)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,120,6),
            DmgSrc(DmgSrcType::ATK,120,6),
            DmgSrc(DmgSrcType::ATK,120,6)
        );
        act->addToActionBar();
    }
    void jadeTalent(CharUnit *ptr,int amount){
        buffStackSingle(ptr,
            {{Stats::ATK_P,AType::NONE,0.5},
            {Stats::CD,AType::NONE,2.4}},
            amount,50,"Pawned_Asset");
        if(ptr->eidolon>=2&&ptr->stack["Pawned_Asset"]>=15&&isHaveToAddBuff(ptr,"Jade_E2")){
            buffSingle(ptr,{{Stats::CR,AType::NONE,18}});
        }

    }

}