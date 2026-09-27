#include "../include.h"

namespace Guinaifen{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(106,120,120,eidolon,ElementType::FIRE,Path::NIHILITY,"Guinaifen",UnitType::STANDARD);
        ptr->setAllyBaseStats(882,582,441);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(134);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *gui = ptr;
        #pragma region Ability

        if(ptr->eidolon>=1)enemyEffectRes-=10;

        function<void()> ba = [ptr,gui]() {
            genSkillPoint(gui,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Gui BA",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                for(auto &each : act->targetList){
                    dotSingleApply(gui,each,{DotType::BURN},"Gui Burn",2);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,110,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,gui]() {
            genSkillPoint(gui,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Gui Skill",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                for(auto &each : act->targetList){
                    dotSingleApply(gui,each,{DotType::BURN},"Gui Burn",2);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,132,20),
                DmgSrc(DmgSrcType::ATK,44,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,gui,ba,skill]() {
            if(sp>spSafety)skill();
            else ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [gui](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Gui Skill",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Guinaifen");
                for(auto &each : act->targetList){
                    dotTrigger(96,each,DotType::BURN);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,129.6,20),
                DmgSrc(DmgSrcType::ATK,129.6,20),
                DmgSrc(DmgSrcType::ATK,129.6,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gui](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::FIRE][AType::NONE] += 22.4;
            ptr->statsType[Stats::BE][AType::NONE] += 24;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gui](CharUnit *ptr) {
            ptr->statsType[Stats::DMG][AType::NONE] += 20;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gui](CharUnit *ptr) {
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Gui Tech",
                [ptr,gui](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                    for(auto &each : act->targetList){
                        dotSingleApply(gui,each,{DotType::BURN},"Gui Burn",2);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                dealDamage();
            }
            actionForward(gui->atvStats.get(),25);          
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gui](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Gui Burn")){
                dotRemove(enemy,{DotType::BURN});
            }       
        }));

        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,gui](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameDamageType(AType::BURN)){
                if(ptr->eidolon>=6){
                    debuffStackEnemyTargets(gui,act->targetList,{{Stats::VUL,AType::NONE,7.6}},1,4,"Firekiss");
                }else{
                    debuffStackEnemyTargets(gui,act->targetList,{{Stats::VUL,AType::NONE,7.6}},1,3,"Firekiss");
                }
            }      
        }));

        dotList.push_back(TriggerDotFunc(PRIORITY_ACTTACK, [ptr,gui](Enemy* target, double dotRatio, DotType dotType) {
            if (!target->getDebuff("Gui Burn")) return;
            if (dotType != DotType::GENERAL && dotType != DotType::BURN) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BURN,ptr,TraceType::SINGLE,"Gui Burn");
            if(ptr->eidolon>=2)act->addDamageIns(DmgSrc(DmgSrcType::ATK,280),target);
            else act->addDamageIns(DmgSrc(DmgSrcType::ATK,240),target);
            act->multiplyDmg(dotRatio);
            if(ptr->eidolon>=4)increaseEnergy(ptr,2);
            attack(act);
        }));
    }
}
