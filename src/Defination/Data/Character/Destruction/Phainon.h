#include "../include.h"

namespace Phainon{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(94,0,0,E,ElementType::Physical,Path::Destruction,"Phainon",UnitType::Standard);
        ptr->SetAllyBaseStats(1436,582,703);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetCountdownStats(ptr,ptr->Atv_stats->baseSpeed*0.6*7,"Phainon Extra Turn");
        Error *pn = ptr;
        Unit *pnCD = ptr->countdownList[0].get();
        

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(116);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);



        ptr->Adjust["choose Calamity"] = 0;

        //function
        #pragma region extra
        function<void(int value)> CoreFlame = [ptr,pn](int value){
            pn->Buff_note["Core Flame"] += value;
        };

        function<void(int value)> Scourge = [ptr,pn](int value){
            pn->Buff_note["Scourge"] += value;
        };

        #pragma endregion


        #pragma region action
        function<void()> BA = [ptr,pn]() {
            Skill_point(pn,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"PN BA",
            [ptr,pn](shared_ptr<AllyAttackAction> &act){
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,pn,CoreFlame]() {
            Skill_point(pn,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"PN Skill",
            [ptr,pn,CoreFlame](shared_ptr<AllyAttackAction> &act){
                CoreFlame(2);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,120,10)
            );
            act->addToActionBar();
        };
        
        function<void()> Creation = [ptr,pn,Scourge]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"PN Creation",
            [ptr,pn,Scourge](shared_ptr<AllyAttackAction> &act){
                Scourge(2);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,250,30),
                DmgSrc(DmgSrcType::ATK,75,20)
            );
            act->addToActionBar();
        };

        function<void()> Calamity = [ptr,pn,Scourge]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"PN Calamity",
            [ptr,pn,Scourge](shared_ptr<AllyBuffAction> &act){
                pn->setBuffCheck("Soulscorch",1);
                pn->setBuffCountdown("PN Counter",Total_enemy);
                Scourge(Total_enemy);
                for(int i=1;i<=Total_enemy;i++){
                    Action_forward(enemyUnit[i]->getAtvStats(),1000);
                    enemyUnit[i]->setDebuff("Soulscorch",1);
                    enemyUnit[i]->dmgPercent-=75;
                }
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
        };

        function<void()> Foundation = [ptr,pn,Scourge]() {
            Scourge(-4);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Bounce,"PN Foundation",
            [ptr,pn,Scourge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printText("PN Foundation");
                Attack(act);
            });
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,45,10/3),16);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,450,20)
            );
            act->addToActionBar();
        };

        function<void()> FinalHit = [ptr,pn,Scourge,pnCD,CoreFlame]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"PN FinalHit",
            [ptr,pn,pnCD,CoreFlame](shared_ptr<AllyAttackAction> &act){
                Attack(act);
                pn->buffSingle({
                    {Stats::ATK_P,AType::None,-80},
                    {Stats::HP_P,AType::None,-270}
                });
                pn->Atv_stats->extraTurn = 0;
                pnCD->death();
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each :charUnit[i]->Sub_Unit_ptr){
                        if(each->isSameStatsOwnerName(pn)){
                            each->status = UnitStatus::Alive;
                        }else if(pn->getBuffNote("PN Retire " + each->getCharName())==1){
                            each->status = UnitStatus::Alive;
                        }else if(pn->getBuffNote("PN Retire " + each->getCharName())==2){
                            each->status = UnitStatus::AtvFreeze;
                        }
                        pn->setBuffNote("PN Retire " + each->getCharName(),0);
                    }

                    for(auto &each :charUnit[i]->summonList){
                        if(each->status==UnitStatus::AtvFreeze){
                            each->status = UnitStatus::Alive;
                        }
                    }
                    for(auto &each :charUnit[i]->countdownList){
                        if(each->status==UnitStatus::AtvFreeze){
                            each->status = UnitStatus::Alive;
                        }
                    }
                }
                buffAllAlly({
                    {Stats::SPD_P,AType::None,15}
                },"PN Spd Buff",1);
                pn->buffStackSingle({{Stats::ATK_P,AType::None,50}},1,2,"PN A6");
                CoreFlame(3);
                CharCmd::printUltEnd("Phainon");    

            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,960,20)
            );
            act->addToActionBar();
        };

        #pragma endregion

        #pragma region Action Choice

        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,BA,Skill](){
            if(sp>Sp_Safety) Skill();
            else BA();
            // Skill();
             
        };

        ptr->countdownList[0]->Turn_func = [ptr,pn,Creation,Calamity,Foundation,FinalHit](){
            if(pn->getBuffCountdown("PN Extra Turn")==4||(ptr->Eidolon>=4&&ptr->getAdjust("choose Calamity")&&pn->getBuffNote("Scourge")<4&&Total_enemy>=2))
                Calamity();
            else if(pn->getBuffCountdown("PN Extra Turn")==1)
                FinalHit();
            else if(pn->getBuffNote("Scourge")>=4)
                Foundation();
            else Creation();
            pn->Buff_countdown["PN Extra Turn"] -= 1;
            resetTurn(turn);
        };


        #pragma endregion
        

        #pragma region Ult

        ptr->addUltCondition([ptr,pn,pnCD]() -> bool {
            if(pn->getBuffNote("Core Flame")>=12&&!pnCD->isAlive())return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,pn,pnCD,Scourge,CoreFlame]() {
            if (!ultUseCheck(ptr)) return;
            CoreFlame(-12);
            shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"PN Ult",
                [ptr,pn,pnCD,Scourge,CoreFlame](shared_ptr<AllyBuffAction> &act){
                    CharCmd::printUltStart("Phainon");
                    pn->buffSingle({
                        {Stats::ATK_P,AType::None,80},
                        {Stats::HP_P,AType::None,270}
                    });
                    Scourge(4);
                    pn->Atv_stats->extraTurn = 1;
                    if(turn->isSameUnitName("Phainon")){
                        turn->turnCnt--;
                    }
                    pnCD->summon();
                    if(ptr->Eidolon>=1) pnCD->resetATV(pn->getBaseSpeed()*0.66*7);
                    else pnCD->resetATV(pn->getBaseSpeed()*0.6*7);
                    Action_forward(pnCD->Atv_stats.get(),1000);
                    pnCD->Atv_stats->extraTurn = 1;
                    pn->setBuffCountdown("PN Extra Turn", 8);

                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each :charUnit[i]->Sub_Unit_ptr){
                            if(each->isSameStatsOwnerName(pn)){
                                    each->status = UnitStatus::AtvFreeze;
                            }else if(each->status==UnitStatus::Alive){
                                pn->setBuffNote("PN Retire " + each->getCharName(),1);
                                each->status = UnitStatus::Retire;
                            }else if(each->status==UnitStatus::AtvFreeze){
                                pn->setBuffNote("PN Retire " + each->getCharName(),2);
                                each->status = UnitStatus::Retire;
                            }
                        }

                        for(auto &each :charUnit[i]->summonList){
                            if(each->status==UnitStatus::Alive){
                                each->status = UnitStatus::AtvFreeze;
                            }
                        }
                        for(auto &each :charUnit[i]->countdownList){
                            if(each->isSameUnit(pnCD))continue;
                            if(each->status==UnitStatus::Alive){
                                each->status = UnitStatus::AtvFreeze;
                            }
                        }
                    }

                    if(ptr->Eidolon>=1){
                        pn->buffSingle({
                            {Stats::CD,AType::None,50}
                        },"PN E1",3);
                    }
                });
            act->addBuffSingleTarget(pn);
            act->addToActionBar();
            Deal_damage();
        }));

        #pragma endregion

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;

            // relic
            // substats
            // eidolon
            if(ptr->Eidolon>=2){
                ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::RESPEN][ElementType::Physical][AType::None] += 20;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn,CoreFlame,Scourge]() {
            if(ptr->Technique){
                Skill_point(pn,1);
                Scourge(2);
                for(int i=1;i<=Total_ally;i++){
                    Increase_energy(charUnit[i].get(),25);
                }
            }
            pn->buffStackSingle({{Stats::ATK_P,AType::None,50}},1,2,"PN A6");
            CoreFlame(3);
            if(ptr->Eidolon>=6){
                CoreFlame(6);
            }
        }));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn]() {
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"PN Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,0),
                    DmgSrc(DmgSrcType::ATK,200,0),
                    DmgSrc(DmgSrcType::ATK,200,0)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn]() {
            Enemy *enemy = turn->canCastToEnemy();
            Error *Error = turn->canCastToSubUnit();
            if(enemy&&enemy->getDebuff("Soulscorch")){
                enemy->setDebuff("Soulscorch",0);
                enemy->dmgPercent+=75;
                pn->Buff_countdown["PN Counter"]--;
            }
            
            if(!pn->getBuffCountdown("PN Counter")&&pn->getBuffCheck("Soulscorch")){
                shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Blast,"PN Calamity",
            [ptr,pn](shared_ptr<AllyAttackAction> &act){
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40,5),
                DmgSrc(DmgSrcType::ATK,40,5),
                DmgSrc(DmgSrcType::ATK,40,5)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,10),4);
            if(ptr->Eidolon>=4)pn->Buff_note["Soulscorch"] +=4;
            act->multiplyDmg(100 + pn->getBuffNote("Soulscorch") * 20);
            pn->setBuffNote("Soulscorch",0);
            pn->setBuffCheck("Soulscorch",0);
            act->addToActionBar();
            Deal_damage();
            }

            if(!Error)return;
            if(Error->isBuffEnd("PN Spd Buff")){
                Error->buffSingle({
                    {Stats::SPD_P,AType::None,-15}
                });
            }
            if(Error->isBuffEnd("PN E1")){
                pn->buffSingle({
                    {Stats::CD,AType::None,-50}
                });
            }
        }));

        
        AfterAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,pn](shared_ptr<ActionData> &act) {
            EnemyActionData *enemyact =  act->castToEnemyActionData();
            if(enemyact&&pn->getBuffCheck("Soulscorch")){
                pn->Buff_note["Soulscorch"] +=1;
            }
        }));
        
        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameAtker(pn)&&pnCD->status==UnitStatus::Alive){
                pn->RestoreHP(pn,HealSrc(HealSrcType::TOTAL_HP,20));
            }
            if(ptr->Eidolon>=2&&act->actionName=="PN Foundation"){
                Action_forward(pnCD->Atv_stats.get(),1000);
                pn->Buff_countdown["PN Extra Turn"]++;

            }
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,CoreFlame](shared_ptr<AllyBuffAction> &act) {
            
            if(pnCD->isAlive())return;
            for(auto &each : act->buffTargetList){
                if(each->isSameStatsOwnerName(pn)){
                    CoreFlame(1);
                    pn->buffSingle({{Stats::CD,AType::None,30}},"PN Talent",3);
                    if(act->actionName=="TY Ult"
                    || act->actionName=="SD Ult"
                    ||(act->actionName=="Crd Skill"&&act->Attacker->owner->Eidolon>=1)){
                        CoreFlame(1);
                    }
                    break;
                }
            }
        }));


        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,CoreFlame](Enemy *Attacker, vector<Error*> target) {
            if(pnCD->isAlive())return;
            for(auto &each : target){
                if(each->isSameStatsOwnerName(pn)){
                    CoreFlame(1);
                    break;
                }
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,CoreFlame](Error *Healer, Error *target, double Value) {
            if(target->isSameStatsOwnerName(pn)){
                pn->buffSingle({{Stats::DMG,AType::None,45}},"PN A4",4);
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD](Error* target) {
            if(target->isBuffGoneByDeath("PN Spd Buff")){
                 target->buffSingle({
                    {Stats::SPD_P,AType::None,-15}
                });
            }
            if(target->isBuffGoneByDeath("PN Talent")){
                pn->buffSingle({{Stats::CD,AType::None,-30}});
            }
        }));

        if(ptr->Eidolon>=6)
        AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD]
            (shared_ptr<AllyAttackAction> &act,Enemy *src,double damage) {
                if(act->actionName!="PN Foundation")return;
                Cal_DamageNote(act,src,enemyUnit[Main_Enemy_num].get(),damage,36,"PN True Foundation");
        }));

        Setup_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn]() {
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
