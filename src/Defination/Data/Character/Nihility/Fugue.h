#include "../include.h"

namespace SomeChar{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(102,130,130,E,ElementType::Fire,Path::Nihility,"Fugue",UnitType::Standard);
        ptr->SetAllyBaseStats(1125,582,557);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Fugue BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> EBA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"Fugue EBA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,100,5)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::BA,ptr,TraceType::Blast,"Fugue Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                Increase_energy(ptr,30);
                if(isHaveToAddBuff(ptr,"Fugue Skill",3)){
                    for(auto &each : act->buffTargetList){
                        buffSingle(each,{{Stats::BE,AType::None,30}});
                        if(ptr->Eidolon>=1)buffSingle(each,{{Stats::BREAK_EFF,AType::None,50}});
                        if(ptr->Eidolon>=4)buffSingle(each,{{Stats::VUL,AType::None,20}});
                    }
                }
            });
            if(ptr->Eidolon>=6)act->addBuffAllAllies();
            else act->addBuffSingleTarget(chooseSubUnitBuff(ptr));
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,BA,Skill,EBA]() {
            if(ptr->getTurnCnt() == 1)genSkillPoint(ptr,1);
            if(ptr->getBuffCheck("Fugue Skill"))EBA();
            else Skill();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Fugue Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                if(ptr->Eidolon>=2)All_Action_forward(24);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->Dont_care_weakness = 100;
            act->addToActionBar();

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::HP_P][AType::None] += 10;
            ptr->Stats_type[Stats::BE][AType::None] += 24 + 30;
            ptr->Atv_stats->flatSpeed += 14;

            if(ptr->Eidolon>=6)ptr->Stats_type[Stats::BREAK_EFF][AType::None] += 50;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"Fugue Skill")) {
                if(ptr->Eidolon>=6){
                    buffAllAlly({
                        {Stats::BE,AType::None,-30},
                        {Stats::BREAK_EFF,AType::None,-50},
                        {Stats::VUL,AType::None,-20},
                    });
                }else{
                    buffSingle(chooseSubUnitBuff(ptr),{{Stats::BE,AType::None,-30}});
                    if(ptr->Eidolon>=1)buffSingle(chooseSubUnitBuff(ptr),{{Stats::BREAK_EFF,AType::None,-50}});
                    if(ptr->Eidolon>=4)buffSingle(chooseSubUnitBuff(ptr),{{Stats::VUL,AType::None,-20}});
                }
                
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            AllyUnit *ally = turn->canCastToAllyUnit();

            if(enemy){
                enemy->Debuff["Cloudflame_Luster"]=0;
                if(isDebuffEnd(enemy,"Fugue Debuff")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-18}});
                }  
            }
            if(ally){
                if(isBuffEnd(ally,"Fugue A6")){
                    buffResetStack(ally,{{Stats::BE,AType::None,12}},"Fugue A6");
                }
            }

        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target) {
            if(isBuffEnd(target,"Fugue A6")){
                buffResetStack(target,{{Stats::BE,AType::None,12}},"Fugue A6");
            }
        }));

        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameName(chooseSubUnitBuff(ptr))) {
                act->Dont_care_weakness  = max(act->Dont_care_weakness,50.0);
                for(auto &each : act->targetList){
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::None,18}},"Fugue Debuff",2);
                }

            }

        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            Superbreak_trigger(act,100,"Fugue");
            for(auto &each : act->targetList){
                if(each->Debuff["Cloudflame Luster"]==0 &&each->Current_toughness*(-1)>=each->Max_toughness*0.4){

                    Toughness_break(act,each);
                    each->Debuff["Cloudflame_Luster"]=1;
                }
            }

        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_ACTTACK, [ptr](Enemy *target, AllyUnit *Trigger){
            Action_forward(target->getAtvStats(),-15);
            buffStackAllAlly({{Stats::BE,AType::None,12}},1,2,"Fugue A6",2);
            if(ptr->Eidolon>=2)Increase_energy(ptr,3);
        }));
    }
}
