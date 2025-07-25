#include "../include.h"

namespace Phainon{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(94,0,0,E,ElementType::Physical,"Destruction","Phainon",TYPE_STD);
        ptr->SetAllyBaseStats(1436,582,703);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetCountdownStats(ptr,ptr->getSubUnit()->Atv_stats->baseSpeed*0.6*7,"Phainon Extra Turn");
        SubUnit *pn = ptr->getSubUnit();
        Unit *pnCD = ptr->Countdown_ptr[0].get();
        

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(100);
        ptr->setRelicMainStats(ST_CR,ST_ATK_P,ST_DMG,ST_ATK_P);



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
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"PN BA",
            [ptr,pn](shared_ptr<AllyAttackAction> &act){
                Skill_point(pn,1);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,pn,CoreFlame]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BLAST,"PN Skill",
            [ptr,pn,CoreFlame](shared_ptr<AllyAttackAction> &act){
                Skill_point(pn,-1);
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
            make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_BLAST,"PN Creation",
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
            make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"PN Calamity",
            [ptr,pn,Scourge](shared_ptr<AllyBuffAction> &act){
                pn->setBuffCheck("Soulscorch",1);
                pn->setBuffCountdown("PN Counter",Total_enemy);
                Scourge(Total_enemy);
                for(int i=1;i<=Total_enemy;i++){
                    Action_forward(Enemy_unit[i]->getAtvStats(),1000);
                    Enemy_unit[i]->setDebuff("Soulscorch",1);
                    Enemy_unit[i]->dmgPercent-=75;
                }
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
        };

        function<void()> Foundation = [ptr,pn,Scourge]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BOUNCE,"PN Foundation",
            [ptr,pn,Scourge](shared_ptr<AllyAttackAction> &act){
                Scourge(-4);
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
            make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"PN FinalHit",
            [ptr,pn,pnCD,CoreFlame](shared_ptr<AllyAttackAction> &act){
                Attack(act);
                pn->buffSingle({
                    {ST_ATK_P,AT_NONE,-80},
                    {ST_HP_P,AT_NONE,-270}
                });
                pn->Atv_stats->extraTurn = 0;
                pnCD->death();
                for(int i=1;i<=Total_ally;i++){
                    for(auto &each :Ally_unit[i]->Sub_Unit_ptr){
                        if(each->isSameUnit(pn)){
                            each->status = UnitStatus::Alive;
                        }else if(pn->getBuffNote("PN Retire " + each->getCharName())==1){
                            each->status = UnitStatus::Alive;
                        }else if(pn->getBuffNote("PN Retire " + each->getCharName())==2){
                            each->status = UnitStatus::AtvFreeze;
                        }
                        pn->setBuffNote("PN Retire " + each->getCharName(),0);
                    }

                    for(auto &each :Ally_unit[i]->Summon_ptr){
                        if(each->status==UnitStatus::AtvFreeze){
                            each->status = UnitStatus::Alive;
                        }
                    }
                    for(auto &each :Ally_unit[i]->Countdown_ptr){
                        if(each->status==UnitStatus::AtvFreeze){
                            each->status = UnitStatus::Alive;
                        }
                    }
                }
                buffAllAlly({
                    {ST_SPD_P,ST_SPD,15}
                },"PN Spd Buff",1);
                pn->buffStackSingle({{ST_ATK_P,AT_NONE,50}},1,2,"PN A6");
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
             
        };

        ptr->Countdown_ptr[0]->Turn_func = [ptr,pn,Creation,Calamity,Foundation,FinalHit](){
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
                make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_SINGLE,"PN Ult",
                [ptr,pn,pnCD,Scourge,CoreFlame](shared_ptr<AllyBuffAction> &act){
                    CharCmd::printUltStart("Phainon");
                    pn->buffSingle({
                        {ST_ATK_P,AT_NONE,80},
                        {ST_HP_P,AT_NONE,270}
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
                        for(auto &each :Ally_unit[i]->Sub_Unit_ptr){
                            if(each->isSameUnit(pn)){
                                    each->status = UnitStatus::AtvFreeze;
                            }else if(each->status==UnitStatus::Alive){
                                pn->setBuffNote("PN Retire " + each->getCharName(),1);
                                each->status = UnitStatus::Retire;
                            }else if(each->status==UnitStatus::AtvFreeze){
                                pn->setBuffNote("PN Retire " + each->getCharName(),2);
                                each->status = UnitStatus::Retire;
                            }
                        }

                        for(auto &each :Ally_unit[i]->Summon_ptr){
                            if(each->status==UnitStatus::Alive){
                                each->status = UnitStatus::AtvFreeze;
                            }
                        }
                        for(auto &each :Ally_unit[i]->Countdown_ptr){
                            if(each->isSameUnit(pnCD))continue;
                            if(each->status==UnitStatus::Alive){
                                each->status = UnitStatus::AtvFreeze;
                            }
                        }
                    }

                    if(ptr->Eidolon>=1){
                        pn->buffSingle({
                            {ST_CD,AT_NONE,50}
                        },"PN E1",3);
                    }
                });
            act->addBuffSingleTarget(pn);
            act->addToActionBar();
            Deal_damage();
        }));

        #pragma endregion

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;

            // relic
            // substats
            // eidolon
            if(ptr->Eidolon>=2){
                ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_RESPEN][ElementType::Physical][AT_NONE] += 20;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn,CoreFlame,Scourge]() {
            if(ptr->Technique){
                Skill_point(pn,1);
                Scourge(2);
                for(int i=1;i<=Total_ally;i++){
                    Increase_energy(Ally_unit[i].get(),25);
                }
            }
            pn->buffStackSingle({{ST_ATK_P,AT_NONE,50}},1,2,"PN A6");
            CoreFlame(3);
            if(ptr->Eidolon>=6){
                CoreFlame(6);
            }
        }));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,pn]() {
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(ActionType::Technique,ptr->getSubUnit(),TT_AOE,"PN Tech",
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
            SubUnit *subunit = turn->canCastToSubUnit();
            if(enemy&&enemy->getDebuff("Soulscorch")){
                enemy->setDebuff("Soulscorch",0);
                enemy->dmgPercent+=75;
                pn->Buff_countdown["PN Counter"]--;
            }
            
            if(!pn->getBuffCountdown("PN Counter")&&pn->getBuffCheck("Soulscorch")){
                shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_BLAST,"PN Calamity",
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

            if(!subunit)return;
            if(subunit->isBuffEnd("PN Spd Buff")){
                subunit->buffSingle({
                    {ST_SPD_P,ST_SPD,-15}
                });
            }
            if(subunit->isBuffEnd("PN E1")){
                pn->buffSingle({
                    {ST_CD,AT_NONE,-50}
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
                if(each->isSameUnit(pn)){
                    CoreFlame(1);
                    pn->buffSingle({{ST_CD,AT_NONE,30}},"PN Talent",3);
                    if(act->actionName=="TY Ult"
                    || act->actionName=="SD Ult"){
                        CoreFlame(1);
                    }
                    break;
                }
            }
        }));


        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,CoreFlame](Enemy *Attacker, vector<SubUnit*> target) {
            if(pnCD->isAlive())return;
            for(auto &each : target){
                if(each->isSameUnit(pn)){
                    CoreFlame(1);
                    break;
                }
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD,CoreFlame](SubUnit *Healer, SubUnit *target, double Value) {
            if(target->isSameUnit(pn)){
                pn->buffSingle({{ST_DMG,AT_NONE,45}},"PN A4",4);
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD](SubUnit* target) {
            if(target->isBuffGoneByDeath("PN Spd Buff")){
                 target->buffSingle({
                    {ST_SPD_P,ST_SPD,-15}
                });
            }
            if(target->isBuffGoneByDeath("PN Talent")){
                pn->buffSingle({{ST_CD,AT_NONE,-30}});
            }
        }));

        if(ptr->Eidolon>=6)
        AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,pn,pnCD]
            (shared_ptr<AllyAttackAction> &act,Enemy *src,double damage) {
                if(act->actionName!="PN Foundation")return;
                Cal_DamageNote(act,src,Enemy_unit[Main_Enemy_num].get(),damage,36,"PN True Foundation");
        }));

    }

    void AddBuffCondition(){
        Ally *ptr = CharCmd::findAllyName("Phainon");
        SubUnit *pn = ptr->getSubUnit();
        
        Ally *sd = CharCmd::findAllyName("Sunday");
        Ally *tb = CharCmd::findAllyName("Tribbie");
        Ally *rb = CharCmd::findAllyName("Robin");
        Ally *bn = CharCmd::findAllyName("Bronya");
        Ally *rmc = CharCmd::findAllyName("RMC");
        Ally *rm = CharCmd::findAllyName("Ruan_Mei");
        Ally *ty = CharCmd::findAllyName("Tingyun");

        if(sd){
            ptr->addUltCondition([sd,ptr,pn]() -> bool {
                if(pn->getBuffCheck("Benison_of_Paper_and_Rites")&&pn->getBuffCheck("Ode_to_Caress_and_Cicatrix"))return true;
                return false;
            });
        }

        if(tb){
            ptr->addUltCondition([ptr,pn,tb]() -> bool {
                if(tb->getSubUnit()->getBuffCheck("Tribbie_Zone")&&tb->getSubUnit()->getBuffCheck("Numinosity"))return true;
                return false;
            });
        }

        if(rb){
            ptr->addUltCondition([ptr,pn,rb]() -> bool {
                if(rb->getSubUnit()->getBuffCheck("Pinion'sAria")&&!rb->Countdown_ptr[0]->isDeath())return true;
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
                if(rm->getSubUnit()->getBuffCheck("Mei_Skill")&&rm->getSubUnit()->getBuffCheck("RuanMei_Ult"))return true;
                return false;
            });
        }

        if(ty){
            ptr->addUltCondition([ptr,pn,rm]() -> bool {
                if(pn->getBuffCheck("Benediction")&&pn->getBuffCheck("Rejoicing_Clouds"))return true;
                return false;
            });
        }

        
    }
}
