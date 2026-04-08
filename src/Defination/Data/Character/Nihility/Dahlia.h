#include "../include.h"

namespace Dahlia{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(96,130,130,E,ElementType::Fire,Path::Nihility,"Dahlia",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,679,606);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::SPD_P,Stats::ATK_P,Stats::BE);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        DahliaCheck = 1;
        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Dahlia BA",
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

        function<void()> Skill = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Dahlia Skill",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                Increase_energy(ptr,30);
                if(isHaveToAddBuff(ptr,"Dahlia Skill",3)){
                    ptr->setBuffNote("Dahlia A2",calculateBreakEffectForBuff(ptr,24) + 50);
                    buffAllAlly({{Stats::BREAK_EFF,AType::None,50}});
                    buffAllAlly({{Stats::BE,AType::TEMP,ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::None,ptr->getBuffNote("Dahlia A2")}},"Dahlia A2",1);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,10),
                DmgSrc(DmgSrcType::ATK,160,10)
            );
            act->addToActionBar();
        };

        function<void()> Fua = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Bounce,"Dahlia Fua",
            [ptr](shared_ptr<AllyAttackAction> &act){
                if(ptr->getBuffCheck("Dahlia Fua SP"))ptr->setBuffCheck("Dahlia Fua SP",0);
                else genSkillPoint(ptr,1);  
                Increase_energy(ptr,2);
                for(auto &each : act->targetList){
                    debuffSingleApply(ptr,each,{{Stats::VUL,AType::None,12}},"Dahlia E4",2);
                }
                Attack(act);
                if(ptr->Eidolon>=6){
                    Action_forward(ptr->getAtvStats(),20);
                    Action_forward(chooseSubUnitBuff(ptr)->getAtvStats(),20);
                }
            });
            if(ptr->Eidolon>=4)act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,3),10);
            else act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,3),5);
            act->addToActionBar();
            Deal_damage();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,BA,Skill]() {
            if(ptr->getBuffCheck("Dahlia Skill"))BA();
            else Skill();

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Dahlia Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for(auto &each : act->targetList){
                    weaknessApply(ptr,each,{chooseCharacterBuff(ptr)->Element_type[0]},4);
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::None,18}},"Wilt",4);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,300,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::BE][AType::None] += 37.3;
            ptr->Stats_type[Stats::RES][AType::None] += 18;
            ptr->Atv_stats->flatSpeed += 5;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->Eidolon>=2)debuffAllEnemyApply(ptr,{{Stats::RESPEN,AType::None,20}},"Dahlia E2");
            if(ptr->Eidolon>=6){
                buffSingle(ptr,{{Stats::BE,AType::None,150}});
                buffSingle(chooseSubUnitBuff(ptr),{{Stats::BE,AType::None,150}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(isBuffEnd(ptr,"Dahlia Skill")){
                buffAllAlly({{Stats::BREAK_EFF,AType::None,-50}});
            }
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(isBuffEnd(ally,"Dahlia A2")){
                buffSingle(ally,{
                    {Stats::BE,AType::TEMP,-ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::None,-ptr->getBuffNote("Dahlia A2")}});
                ptr->setBuffNote("Dahlia A2",0);

            }
        }));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Wilt")){
                debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-18}});
            }
            if(isDebuffEnd(enemy,"Dahlia E4")){
                debuffSingle(enemy,{{Stats::VUL,AType::None,-12}});
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Dahlia A6")){
                buffSingle(ally,{{Stats::SPD_P,AType::None,-30}});
            }
        }));

        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,Fua](shared_ptr<AllyAttackAction> &act){
            if(act->Attacker->getBuffCheck("Dahlia A6")){
                for(auto &each1 : act->damageSplit){
                    for(auto &each : each1){
                        if(each.target->getDebuff("Dahlia A6"))continue;
                        each.dmgSrc.toughnessReduce += 20;
                        each.target->setDebuff("Dahlia A6",1);
                    }
                }
                for(auto &each : act->targetList){
                    each->setDebuff("Dahlia A6",0);
                }
            }
            if(ptr->Eidolon>=1 && (act->isSameName(chooseCharacterBuff(ptr)) || act->isSameName(ptr))){
                for(auto &each1 : act->damageSplit){
                    for(auto &each : each1){
                        if(each.target->getDebuff("Dahlia E1"))continue;
                        each.dmgSrc.toughnessReduce += max(10.0,min(300.0,each.target->Max_toughness*0.25));
                        each.target->setDebuff("Dahlia E1",1);
                    }
                }
            }
        }));

        AfterAction_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr,Fua](shared_ptr<ActionData> &act){
            for(auto &each : allyList){
                ptr->setBuffCheck("Dahlia A6",0);
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,Fua](shared_ptr<AllyAttackAction> &act){
            if(ptr->Eidolon>=1){
                if(act->isSameName(chooseCharacterBuff(ptr))||act->isSameName(ptr))Superbreak_trigger(act,100,"Dahlia");
                else Superbreak_trigger(act,60,"Dahlia");
            }
            else if(act->isSameName(chooseCharacterBuff(ptr))||act->isSameName(ptr)) Superbreak_trigger(act,60,"Dahlia");

            if(act->isSameAction(ptr,AType::Fua)){
                DahliaCheck = 0;
                Superbreak_trigger(act,200,"Dahlia");
                DahliaCheck = 1;
            }
            if(act->isSameName(chooseCharacterBuff(ptr))){
                Fua();
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Increase_energy(ptr,35);
            if(ptr->Technique){
                if(isHaveToAddBuff(ptr,"Dahlia Skill",3)){
                    ptr->setBuffNote("Dahlia A2",calculateBreakEffectForBuff(ptr,24) + 50);
                    buffAllAlly({{Stats::BREAK_EFF,AType::None,50}});
                    buffAllAlly({{Stats::BE,AType::TEMP,ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::None,ptr->getBuffNote("Dahlia A2")}},"Dahlia A2",1);
                }
            }
            if(ptr->Eidolon>=2){
                for(auto &each : enemyList){
                    weaknessApply(ptr,each,{chooseCharacterBuff(ptr)->Element_type[0]},3);
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::None,18}},"Wilt",3);
                }
            }
        }));

        WeaknessApply_List.push_back(TriggerByWeaknessApply_Func(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *Trigger,Enemy *target, vector<ElementType> elementList) {
            buffSingle(ptr,{{Stats::SPD_P,AType::None,30}},"Dahlia A6",2);
            if(Trigger->Element_type[0] == ElementType::Fire){
                Increase_energy(ptr,10,0);
                if(phaseStatus == PhaseStatus::WhileAction)ptr->setBuffCheck("Dahlia A6",1);
            }
        }));

    }
}
