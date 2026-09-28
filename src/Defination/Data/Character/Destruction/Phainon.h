#include "../include.h"

namespace Phainon{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(94,0,0,eidolon,ElementType::PHYSICAL,Path::DESTRUCTION,"Phainon",UnitType::STANDARD);
        ptr->setAllyBaseStats(1433,582,703);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        setCountdownStats(ptr,ptr->atvStats->baseSpeed*0.6*7,"Phainon Extra Turn");
        CharUnit *pn = ptr;
        TimerATV *pnCD = ptr->countdownList[0].get();
        

        //substats
        // ptr->pushSubstats(Stats::CD);
        // ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(116);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);



        ptr->adjust["choose Calamity"] = 0;

        //function
        #pragma region extra
        function<void(int value)> coreFlame = [ptr,pn](int value){
            pn->buffNote["Core Flame"] += value;
        };

        function<void(int value)> scourge = [ptr,pn](int value){
            pn->buffNote["Scourge"] += value;
        };

        #pragma endregion


        #pragma region action
        function<void()> ba = [ptr,pn]() {
            genSkillPoint(pn,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"PN BA",
            [ptr,pn](shared_ptr<AllyAttackAction> &act){
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,pn,coreFlame]() {
            genSkillPoint(pn,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"PN Skill",
            [ptr,pn,coreFlame](shared_ptr<AllyAttackAction> &act){
                coreFlame(2);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,120,10)
            );
            act->addToActionBar();
        };
        
        function<void()> creation = [ptr,pn,scourge]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"PN Creation",
            [ptr,pn,scourge](shared_ptr<AllyAttackAction> &act){
                scourge(2);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,250,30),
                DmgSrc(DmgSrcType::ATK,75,20)
            );
            act->addToActionBar();
        };

        function<void()> calamity = [ptr,pn,scourge]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"PN Calamity",
            [ptr,pn,scourge](shared_ptr<AllyBuffAction> &act){
                pn->setBuffCheck("Soulscorch",1);
                pn->setBuffNote("Soulscorch",1);
                pn->setBuffCountdown("PN Counter",totalEnemy);
                scourge(totalEnemy);
                for(int i=1;i<=totalEnemy;i++){
                    actionForward(enemyUnit[i]->getAtvStats(),1000);
                    enemyUnit[i]->setDebuff("Soulscorch",1);
                    enemyUnit[i]->statsType[Stats::DMG_REDUCE][AType::NONE] += 75;
                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
        };

        function<void()> foundation = [ptr,pn,scourge]() {
            scourge(-4);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BOUNCE,"PN Foundation",
            [ptr,pn,scourge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printText("PN Foundation");
                attack(act);
            });
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,45,10/3),16);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,450,20)
            );
            act->addToActionBar();
        };

        function<void()> finalHit = [ptr,pn,scourge,pnCD,coreFlame]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"PN FinalHit",
            [ptr,pn,pnCD,coreFlame](shared_ptr<AllyAttackAction> &act){
                attack(act);
                buffSingle(pn,{
                    {Stats::ATK_P,AType::NONE,-80},
                    {Stats::HP_P,AType::NONE,-270}
                });
                pn->atvStats->extraTurn = 0;
                pnCD->death();
                for(auto &each : allyList){
                    if(each->isSameName(pn)){
                        each->status = UnitStatus::ALIVE;
                    }else if(pn->getBuffNote("PN Retire " + each->getName())==1){
                        each->status = UnitStatus::ALIVE;
                    }else if(pn->getBuffNote("PN Retire " + each->getName())==2){
                        each->status = UnitStatus::ATV_FREEZE;
                    }
                    pn->setBuffNote("PN Retire " + each->getName(),0);
                }
                for(auto &c : charList){
                    for(auto &each :c->summonList){
                        if(each->status==UnitStatus::ATV_FREEZE){
                            each->status = UnitStatus::ALIVE;
                        }
                    }
                    for(auto &each : c->countdownList){
                        if(each->status==UnitStatus::ATV_FREEZE){
                            each->status = UnitStatus::ALIVE;
                        }
                    }
                }
                buffAllAlly({
                    {Stats::SPD_P,AType::NONE,15}
                },"PN Spd Buff",1);
                buffStackSingle(pn,{{Stats::ATK_P,AType::NONE,50}},1,2,"PN A6");
                coreFlame(3);
                CharCmd::printUltEnd("Phainon");    

            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,960,20)
            );
            act->addToActionBar();
        };

        #pragma endregion

        #pragma region Action Choice

        ptr->turnFunc = [ptr,ba,skill](){
            if(sp>spSafety) skill();
            else ba();
            // Skill();
             
        };

        ptr->countdownList[0]->turnFunc = [ptr,pn,creation,calamity,foundation,finalHit](){
            if(pn->getBuffCountdown("PN Extra Turn")==4||(ptr->eidolon>=4&&ptr->getAdjust("choose Calamity")&&pn->getBuffNote("Scourge")<4&&totalEnemy>=2))
                calamity();
            else if(pn->getBuffCountdown("PN Extra Turn")==1)
                finalHit();
            else if(pn->getBuffNote("Scourge")>=4)
                foundation();
            else creation();
            pn->buffEnd["PN Extra Turn"] -= 1;
            resetTurn(turn);
        };


        #pragma endregion
        

        #pragma region Ult

        ptr->addUltCondition([ptr,pn,pnCD]() -> bool {
            if(pn->getBuffNote("Core Flame")>=12&&!pnCD->isAlive())return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [pn,pnCD,scourge,coreFlame](CharUnit *ptr) {
            coreFlame(-12);
            shared_ptr<AllyBuffAction> act =
                make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"PN Ult",
                [ptr,pn,pnCD,scourge,coreFlame](shared_ptr<AllyBuffAction> &act){
                    CharCmd::printUltStart("Phainon");
                    buffSingle(pn,{
                        {Stats::ATK_P,AType::NONE,80},
                        {Stats::HP_P,AType::NONE,270}
                    });
                    scourge(4);
                    pn->atvStats->extraTurn = 1;
                    if(turn->isSameName("Phainon")){
                        turn->turnCnt--;
                    }
                    pnCD->summon();
                    if(ptr->eidolon>=1) pnCD->resetATV(pn->getBaseSpeed()*0.66*7);
                    else pnCD->resetATV(pn->getBaseSpeed()*0.6*7);
                    actionForward(pnCD,1000);
                    pnCD->extraTurn = 1;
                    pn->setBuffCountdown("PN Extra Turn", 8);

                    for(auto &each :allyList){
                        if(each->isSameName(pn)){
                                each->status = UnitStatus::ATV_FREEZE;
                        }else if(each->status==UnitStatus::ALIVE){
                            pn->setBuffNote("PN Retire " + each->getName(),1);
                            each->status = UnitStatus::RETIRE;
                        }else if(each->status==UnitStatus::ATV_FREEZE){
                            pn->setBuffNote("PN Retire " + each->getName(),2);
                            each->status = UnitStatus::RETIRE;
                        }
                    }
                    for(auto &c : charList){
                        for(auto &each :c->summonList){
                            if(each->status==UnitStatus::ALIVE){
                                each->status = UnitStatus::ATV_FREEZE;
                            }
                        }
                        for(auto &each :c->countdownList){
                            if(each.get() == pnCD)continue;
                            if(each->status==UnitStatus::ALIVE){
                                each->status = UnitStatus::ATV_FREEZE;
                            }
                        }
                    }

                    if(ptr->eidolon>=1){
                        buffSingle(pn,{
                            {Stats::CD,AType::NONE,50}
                        },"PN E1",3);
                    }
                });
            act->addBuffSingleTarget(pn);
            act->addToActionBar();
            dealDamage();
        }));

        #pragma endregion

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->atvStats->flatSpeed += 5;

            // relic
            // substats
            // eidolon
            if(ptr->eidolon>=2){
                ptr->statsEachElement[Stats::RESPEN][ElementType::PHYSICAL][AType::NONE] += 20;
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [pn,coreFlame,scourge](CharUnit *ptr) {
            if(ptr->technique){
                genSkillPoint(pn,1);
                scourge(2);
                for(int i=1;i<=totalAlly;i++){
                    increaseEnergy(charUnit[i].get(),25);
                }
            }
            buffStackSingle(pn,{{Stats::ATK_P,AType::NONE,50}},1,2,"PN A6");
            coreFlame(1);   // A2: +1 at battle start (+3 when transformation ends)
            if(ptr->eidolon>=6){
                coreFlame(6);
            }
        }));

        startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [pn](CharUnit *ptr) {
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"PN Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,0),
                    DmgSrc(DmgSrcType::ATK,200,0),
                    DmgSrc(DmgSrcType::ATK,200,0)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [pn](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(enemy&&enemy->getDebuff("Soulscorch")){
                enemy->setDebuff("Soulscorch",0);
                enemy->statsType[Stats::DMG_REDUCE][AType::NONE] -= 75;
                pn->buffEnd["PN Counter"]--;
            }
            
            if(!pn->getBuffCountdown("PN Counter")&&pn->getBuffCheck("Soulscorch")){
                shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"PN Calamity",
            [ptr,pn](shared_ptr<AllyAttackAction> &act){
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40,5),
                DmgSrc(DmgSrcType::ATK,40,5),
                DmgSrc(DmgSrcType::ATK,40,5)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,10),4);
            if(ptr->eidolon>=4)pn->buffNote["Soulscorch"] +=4;
            act->multiplyDmg(100 + pn->getBuffNote("Soulscorch") * 20);
            pn->setBuffNote("Soulscorch",0);
            pn->setBuffCheck("Soulscorch",0);
            act->addToActionBar();
            dealDamage();
            }

            if(!ally)return;
            if(isBuffEnd(ally,"PN Spd Buff")){
                buffSingle(ally,{
                    {Stats::SPD_P,AType::NONE,-15}
                });
            }
            if(isBuffEnd(ally,"PN E1")){
                buffSingle(pn,{
                    {Stats::CD,AType::NONE,-50}
                });
            }
            if(isBuffEnd(pn,"PN Talent")){
                buffSingle(pn,{{Stats::CD,AType::NONE,-30}});
            }
            if(isBuffEnd(pn,"PN A4")){
                buffSingle(pn,{{Stats::DMG,AType::NONE,-45}});
            }
        }));

        
        afterActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,pn](shared_ptr<ActionData> &act) {
            EnemyActionData *enemyact =  act->castToEnemyActionData();
            if(enemyact&&pn->getBuffCheck("Soulscorch")){
                pn->buffNote["Soulscorch"] +=1;
            }
        }));
        
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameOwnerName(pn)&&pnCD->status==UnitStatus::ALIVE){
                pn->restoreHP(pn,HealSrc(HealSrcType::TOTAL_HP,20));
            }
            if(ptr->eidolon>=2&&act->actionName=="PN Foundation"){
                actionForward(pnCD,1000);
                pn->buffEnd["PN Extra Turn"]++;

            }
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,coreFlame](shared_ptr<AllyBuffAction> &act) {
            
            if(pnCD->isAlive())return;
            for(auto &each : act->buffTargetList){
                if(each->isSameName(pn)){
                    coreFlame(1);
                    buffSingle(pn,{{Stats::CD,AType::NONE,30}},"PN Talent",3);
                    if(act->actionName=="TY Ult"
                    || act->actionName=="SD Ult"
                    ||(act->actionName=="Crd Skill"&&act->attacker->owner->eidolon>=1)){
                        coreFlame(1);
                    }
                    break;
                }
            }
        }));


        enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,coreFlame](Enemy *attacker, vector<AllyUnit*> target) {
            if(pnCD->isAlive())return;
            for(auto &each : target){
                if(each->isSameName(pn)){
                    coreFlame(1);
                    break;
                }
            }
        }));

        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,coreFlame](AllyUnit *healer, AllyUnit *target, double value) {
            // A4: only heals from allies (Khaslana's self-heal after attacking does not count)
            if(target->isSameName(pn)&&!healer->isSameName(pn)){
                buffSingle(pn,{{Stats::DMG,AType::NONE,45}},"PN A4",4);
            }
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD](AllyUnit* target) {
            if(isBuffGoneByDeath(target,"PN Spd Buff")){
                 buffSingle(target,{
                    {Stats::SPD_P,AType::NONE,-15}
                });
            }
            if(isBuffGoneByDeath(target,"PN Talent")){
                buffSingle(pn,{{Stats::CD,AType::NONE,-30}});
            }
            if(isBuffGoneByDeath(target,"PN A4")){
                buffSingle(pn,{{Stats::DMG,AType::NONE,-45}});
            }
        }));

        if(ptr->eidolon>=6)
        afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD]
            (shared_ptr<AllyAttackAction> &act,Enemy *target,double damage) {
                if(act->actionName!="PN Foundation")return;
                calDamageNote(act,target,enemyUnit[mainEnemyNum].get(),damage,36,"PN True Foundation");
        }));

        setupList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [pn](CharUnit *ptr) {
        CharUnit *sd = CharCmd::findAllyName("Sunday");
        CharUnit *tb = CharCmd::findAllyName("Tribbie");
        CharUnit *rb = CharCmd::findAllyName("Robin");
        CharUnit *bn = CharCmd::findAllyName("Bronya");
        CharUnit *rmc = CharCmd::findAllyName("RMC");
        CharUnit *rm = CharCmd::findAllyName("Ruan_Mei");
        CharUnit *ty = CharCmd::findAllyName("Tingyun");

        if(sd){
            ptr->addUltCondition([sd,ptr,pn]() -> bool {
                if(pn->getBuffCheck("Benison_of_Paper_and_Rites")&&pn->getBuffCheck("Ode_to_Caress_and_Cicatrix"))return true;
                return false;
            });
        }

        if(tb){
            ptr->addUltCondition([ptr,pn,tb]() -> bool {
                if(tb->getBuffCheck("Tribbie_Zone")&&tb->getBuffCheck("Numinosity"))return true;
                return false;
            });
        }

        if(rb){
            ptr->addUltCondition([ptr,pn,rb]() -> bool {
                if(rb->getBuffCheck("Pinion'sAria")&&!rb->countdownList[0]->isDeath())return true;
                return false;
            });
        }

        if(bn){
            ptr->addUltCondition([ptr,pn,bn]() -> bool {
                if(pn->getBuffCheck("Bronya_Ult")&&pn->getBuffCheck("Bronya_Skill"))return true;
                return false;
            });
        }

        if(rmc){
            ptr->addUltCondition([ptr,pn,rmc]() -> bool {
                if(pn->getBuffCheck("Mem_Support"))return true;
                return false;
            });
        }

        if(rm){
            ptr->addUltCondition([ptr,pn,rm]() -> bool {
                if(rm->getBuffCheck("Mei_Skill")&&rm->getBuffCheck("RuanMei_Ult"))return true;
                return false;
            });
        }

        if(ty){
            ptr->addUltCondition([ptr,pn,rm]() -> bool {
                if(pn->getBuffCheck("Benediction")&&pn->getBuffCheck("Rejoicing_Clouds"))return true;
                return false;
            });
        }

        
        }));

    }
}
