#include "../include.h"

namespace Hysilens{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102,110,110,eidolon,ElementType::PHYSICAL,Path::NIHILITY,"Hysilens",UnitType::STANDARD);
        ptr->setAllyBaseStats(1203,602,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setApplyBaseChance(100);
        ptr->setEhrRequire(120);
        // ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::EHR,Stats::ATK_P,Stats::ATK_P,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *hys =ptr;



        #pragma region Extra
        function<void(Enemy* enemy)> talent = [ptr,hys](Enemy* enemy) {
            string dotName = "Hys Bleed";
            DotType dotType = DotType::BLEED;
            if(!enemy->getDebuff("Hys Bleed")){
            }
            else if(!enemy->getDebuff("Hys Burn")){
                dotName = "Hys Burn";
                dotType = DotType::BURN;
            }
            else if(!enemy->getDebuff("Hys Shock")){
                dotName = "Hys Shock";
                dotType = DotType::SHOCK;
            }
            else if(!enemy->getDebuff("Hys WindShear")){
                dotName = "Hys WindShear";
                dotType = DotType::WIND_SHEAR;
            }else{
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys Burn")){
                    dotName = "Hys Burn";
                    dotType = DotType::BURN;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys Shock")){
                    dotName = "Hys Shock";
                    dotType = DotType::SHOCK;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys WindShear")){
                    dotName = "Hys WindShear";
                    dotType = DotType::WIND_SHEAR;
                }
            }
            dotSingleApply(hys,enemy,{dotType},dotName,2);
        };
        function<void(Enemy* enemy)> e1 = [ptr,hys](Enemy* enemy) {
            string dotName = "Hys E1 Bleed";
            DotType dotType = DotType::BLEED;
            if(!enemy->getDebuff("Hys E1 Bleed")){
            }
            else if(!enemy->getDebuff("Hys E1 Shock")){
                dotName = "Hys E1 Shock";
                dotType = DotType::SHOCK;
            }
            else if(!enemy->getDebuff("Hys E1 Burn")){
                dotName = "Hys E1 Burn";
                dotType = DotType::BURN;
            }
            else if(!enemy->getDebuff("Hys E1 WindShear")){
                dotName = "Hys E1 WindShear";
                dotType = DotType::WIND_SHEAR;
            }else{
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 Shock")){
                    dotName = "Hys E1 Shock";
                    dotType = DotType::SHOCK;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 Burn")){
                    dotName = "Hys E1 Burn";
                    dotType = DotType::BURN;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 WindShear")){
                    dotName = "Hys E1 WindShear";
                    dotType = DotType::WIND_SHEAR;
                }
            }
            dotSingleApply(hys,enemy,{dotType},dotName,2);
        };
        

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr,hys]() {
            genSkillPoint(hys,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Hys BA",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,hys]() {
            genSkillPoint(hys,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"Hys Skill",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                debuffAllEnemyApply(hys,{{Stats::VUL,AType::NONE,20}},"Hys Vul",3);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,hys,skill,ba]() {
            for(int i = 1;i<= totalEnemy;i++){
                if(!enemyUnit[i]->getDebuff("Hys Vul")){
                    skill();
                    return;
                }
            }
            // if(hys->getTurnCnt()%3==1)Skill();
            ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hys](CharUnit *ptr) {
            genSkillPoint(hys,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Hys Ult",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Hysilens");
                for(auto &each : act->targetList){
                    if(debuffMark(hys,each,"Hys Ult")){
                        each->statsType[Stats::ATK_REDUCE][AType::NONE] += 15;
                        debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,25}});
                        if(ptr->eidolon>=4)debuffSingle(each,{{Stats::RESPEN,AType::NONE,20}});

                    }
                    dotTrigger(150,each,DotType::GENERAL);
                }
                isHaveToAddBuff(hys,"Hys Ult",3);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;
            ptr->atvStats->flatSpeed += 14;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            //A6
            if(ptr->eidolon>=2)buffAllAlly({{Stats::DMG,AType::NONE,90}});
            else ptr->statsType[Stats::DMG][AType::NONE] += 90;

            //Eidolon
            if(ptr->eidolon>=1){
                buffAllAlly({{Stats::MTPR_INC,AType::DOT,16}});
            }

        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hys,talent,e1](CharUnit *ptr) {
                genSkillPoint(hys,1);
                for(auto &each : enemyList){
                    if(debuffMark(hys,each,"Hys Ult")){
                        each->statsType[Stats::ATK_REDUCE][AType::NONE] += 15;
                        debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,25}});
                        if(ptr->eidolon>=4)debuffSingle(each,{{Stats::RESPEN,AType::NONE,20}});
                    }
                }
                isHaveToAddBuff(hys,"Hys Ult",3);
                if(ptr->technique){
                    for(int i=1;i<=totalEnemy;i++){
                    talent(enemyUnit[i].get());
                    talent(enemyUnit[i].get());
                    if(ptr->eidolon>=1)e1(enemyUnit[i].get());
                    if(ptr->eidolon>=1)e1(enemyUnit[i].get());
                }
                }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;

            if(isDebuffEnd(enemy,"Hys Vul")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-20}});
            }
            if(isDebuffEnd(enemy,"Hys Bleed"))dotRemove(enemy,{DotType::BLEED});
            if(isDebuffEnd(enemy,"Hys WindShear"))dotRemove(enemy,{DotType::WIND_SHEAR});
            if(isDebuffEnd(enemy,"Hys Burn"))dotRemove(enemy,{DotType::BURN});
            if(isDebuffEnd(enemy,"Hys Shock"))dotRemove(enemy,{DotType::SHOCK});
            if(isDebuffEnd(enemy,"Hys E1 Bleed"))dotRemove(enemy,{DotType::BLEED});
            if(isDebuffEnd(enemy,"Hys E1 WindShear"))dotRemove(enemy,{DotType::WIND_SHEAR});
            if(isDebuffEnd(enemy,"Hys E1 Burn"))dotRemove(enemy,{DotType::BURN});
            if(isDebuffEnd(enemy,"Hys E1 Shock"))dotRemove(enemy,{DotType::SHOCK});
            
        }));
        
        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hys](CharUnit *ptr) {
            for(int i=1;i<=totalEnemy;i++){
                enemyUnit[i]->setStack("Hys Dot Limit",0);
            }
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;

            if(isBuffEnd(ally,"Hys Ult")){
                CharCmd::printUltEnd("Hysilens");
                for(auto &each : enemyList){
                    debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,-25}});
                    if(ptr->eidolon>=4)debuffSingle(each,{{Stats::RESPEN,AType::NONE,-20}});
                    each->statsType[Stats::ATK_REDUCE][AType::NONE] -= 15;
                    debuffRemove(each,"Hys Ult");
                }
            }
        }));

        beforeActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,hys](shared_ptr<ActionData> &act) {
            for(int i=1;i<=totalEnemy;i++){
                enemyUnit[i]->setStack("Hys Dot Limit",0);
            }
        }));


        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,hys,talent,e1](shared_ptr<AllyAttackAction> &act) {
            for(auto &each : act->targetList){
                talent(each);
                if(ptr->eidolon>=1)e1(each);
            }
        }));

        afterAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,hys](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameDamageType(AType::DOT)&&act->actionName!="Hys Ult Dot"){
                shared_ptr<AllyAttackAction> newact = 
            make_shared<AllyAttackAction>(AType::DOT,ptr,TraceType::SINGLE,"Hys Ult Dot");
                for (auto &each : act->targetList) {
                    if(ptr->eidolon>=6){
                        if(each->getStack("Hys Dot Limit")>=12)break;
                    }else{
                        if(each->getStack("Hys Dot Limit")>=8)break;
                    }
                    each->addStack("Hys Dot Limit",1);
                    if(ptr->eidolon>=6)newact->addDamageIns(DmgSrc(DmgSrcType::ATK,100));
                    else newact->addDamageIns(DmgSrc(DmgSrcType::ATK,80));
                    newact->addDamageType(AType::ULT);
                    attack(newact);
                }
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,hys,talent](Enemy* target, double dotRatio,DotType dotType) {
            if (dotType != DotType::GENERAL && dotType != DotType::BLEED) return;
            if (target->getDebuff("Hys Bleed")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::BLEED,ptr,TraceType::SINGLE,"Hys Bleed");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
            if (target->getDebuff("Hys E1 Bleed")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::BLEED,ptr,TraceType::SINGLE,"Hys E1 Bleed");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,hys,talent](Enemy* target, double dotRatio,DotType dotType) {
            if (dotType != DotType::GENERAL && dotType != DotType::WIND_SHEAR) return;
            if (target->getDebuff("Hys WindShear")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WIND_SHEAR,ptr,TraceType::SINGLE,"Hys WindShear");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
            if (target->getDebuff("Hys E1 WindShear")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WIND_SHEAR,ptr,TraceType::SINGLE,"Hys E1 WindShear");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,hys,talent](Enemy* target, double dotRatio,DotType dotType) {
            if (dotType != DotType::GENERAL && dotType != DotType::BURN) return;
            if (target->getDebuff("Hys Burn")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::BURN,ptr,TraceType::SINGLE,"Hys Burn");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
            if (target->getDebuff("Hys E1 Burn")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::BURN,ptr,TraceType::SINGLE,"Hys E1 Burn");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_IMMEDIATELY, [ptr,hys,talent](Enemy* target, double dotRatio,DotType dotType) {
            if (dotType != DotType::GENERAL && dotType != DotType::SHOCK) return;
            if (target->getDebuff("Hys Shock")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,"Hys Shock");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
            if (target->getDebuff("Hys E1 Shock")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::SHOCK,ptr,TraceType::SINGLE,"Hys E1 Shock");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(dotRatio);
                attack(act);
            }
        }));
    }
}
