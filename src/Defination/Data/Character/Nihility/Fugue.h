#include "../include.h"

namespace Fugue{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102,130,130,eidolon,ElementType::FIRE,Path::NIHILITY,"Fugue",UnitType::STANDARD);
        ptr->setAllyBaseStats(1125,582,557);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Fugue BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> eba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"Fugue EBA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,100,5)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::BA,ptr,TraceType::BLAST,"Fugue Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                if(isHaveToAddBuff(ptr,"Fugue Skill",3)){
                    for(auto &each : act->buffTargetList){
                        buffSingle(each,{{Stats::BE,AType::NONE,30}});
                        if(ptr->eidolon>=1)buffSingle(each,{{Stats::BREAK_EFF,AType::NONE,50}});
                        if(ptr->eidolon>=4)buffSingle(each,{{Stats::VUL,AType::NONE,20}});
                    }
                }
            });
            if(ptr->eidolon>=6)act->addBuffAllAllies();
            else act->addBuffSingleTarget(chooseAllyBuff(ptr));
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,ba,skill,eba]() {
            if(ptr->getTurnCnt() == 1)genSkillPoint(ptr,1);
            if(ptr->getBuffCheck("Fugue Skill"))eba();
            else skill();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {

            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Fugue Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                if(ptr->eidolon>=2)allActionForward(24);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->dontCareWeakness = 100;
            act->addToActionBar();
            dealDamage();

        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;
            ptr->statsType[Stats::BE][AType::NONE] += 24 + 30;
            ptr->atvStats->flatSpeed += 14;

            if(ptr->eidolon>=6)ptr->statsType[Stats::BREAK_EFF][AType::NONE] += 50;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Fugue Skill")) {
                if(ptr->eidolon>=6){
                    buffAllAlly({
                        {Stats::BE,AType::NONE,-30},
                        {Stats::BREAK_EFF,AType::NONE,-50},
                        {Stats::VUL,AType::NONE,-20},
                    });
                }else{
                    buffSingle(chooseAllyBuff(ptr),{{Stats::BE,AType::NONE,-30}});
                    if(ptr->eidolon>=1)buffSingle(chooseAllyBuff(ptr),{{Stats::BREAK_EFF,AType::NONE,-50}});
                    if(ptr->eidolon>=4)buffSingle(chooseAllyBuff(ptr),{{Stats::VUL,AType::NONE,-20}});
                }
                
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            AllyUnit *ally = turn->canCastToAllyUnit();

            if(enemy){
                if(isDebuffEnd(enemy,"Fugue Debuff")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-18}});
                }  
            }
            if(ally){
                if(isBuffEnd(ally,"Fugue A6")){
                    buffResetStack(ally,{{Stats::BE,AType::NONE,12}},"Fugue A6");
                }
            }

        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target) {
            if(isBuffEnd(target,"Fugue A6")){
                buffResetStack(target,{{Stats::BE,AType::NONE,12}},"Fugue A6");
            }
        }));

        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameName(chooseAllyBuff(ptr))) {
                act->dontCareWeakness  = max(act->dontCareWeakness,50.0);
                for(auto &each : act->targetList){
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::NONE,18}},"Fugue Debuff",2);
                }

            }

        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            superbreakTrigger(act,100,"Fugue");
            for(auto &each : act->targetList){
                if(each->debuffCheck["Cloudflame Luster"]==0&&each->currentToughness*(-1)>=each->maxToughness*0.4){
                    toughnessBreak(act,each);
                    each->debuffCheck["Cloudflame Luster"]=1;
                }
            }

        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_ACTTACK, [ptr](Enemy *target, AllyUnit *trigger){
            actionForward(target->getAtvStats(),-15);
            target->debuffCheck["Cloudflame Luster"]=0;
            buffStackAllAlly({{Stats::BE,AType::NONE,12}},1,2,"Fugue A6",2);
            if(ptr->eidolon>=2)increaseEnergy(ptr,3);
        }));
    }
}
