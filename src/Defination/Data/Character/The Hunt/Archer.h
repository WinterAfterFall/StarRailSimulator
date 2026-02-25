#include "../include.h"

namespace Archer{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(105,220,220,E,ElementType::Quantum,Path::Hunt,"Archer",UnitType::Standard);
        ptr->SetAllyBaseStats(1164,621,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(Stats::CD,Stats::ATK_P,Stats::ATK_P,Stats::ATK_P);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *ac = ptr;
        Max_sp +=2;
        ptr->Adjust["Archer Minimum"] = 3;

        #pragma region extra
        function<void(int value)> Charge = [ptr,ac](int value){
            ac->Stack["Archer Charge"] += value;
            if(ac->Stack["Archer Charge"]>=4)ac->Stack["Archer Charge"] = 4;
        };

        #pragma endregion

        #pragma region Ability

        function<void()> BA = [ptr,ac]() {
            genSkillPoint(ac,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Archer BA",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,ac]() {
            genSkillPoint(ac,-2);
            calStack(ac,1,5,"Archer Skill Limit");
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Single,"Archer Skill",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=6)buffStackSingle(ac,{{Stats::DMG,AType::SKILL,100}},1,3,"Circuit Connection");
                else buffStackSingle(ac,{{Stats::DMG,AType::SKILL,100}},1,2,"Circuit Connection");
                Attack(act);
                if(ptr->Eidolon>=1){
                    ac->addStack("Archer E1",1);
                    if(ac->getStack("Archer E1")==3){
                        ac->setStack("Archer E1",0);
                        genSkillPoint(ac,2);
                    }
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,360,20)
            );
            act->addToActionBar();
        };

        function<void()> Fua = [ptr,ac]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Single,"Archer Fua",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ac,1);
                Increase_energy(ptr,5);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,10)
            );
            act->addToActionBar();
            Deal_damage();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,ac,BA,Skill]() {
            if(sp>=2 * ptr->Adjust["Archer Minimum"])Skill();
            else BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,ac,Charge]() {
            if (!ultUseCheck(ptr))return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Single,"Archer Ult",
            [ptr,ac,Charge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Archer");
                Charge(2);
                if(ptr->Eidolon>=2){
                    for(auto &each : act->targetList){
                        debuffSingleApply(ac,each,{{Stats::RESPEN,ElementType::Quantum,AType::None,20}},"Archer E2",2);
                    }
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,1000,30)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 22.4;
            ptr->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Stats_type[Stats::CR][AType::None] += 6.7;

            // relic

            // substats
            if(ptr->Eidolon>=4)ptr->Stats_type[Stats::DMG][AType::Ult] += 150;
            if(ptr->Eidolon>=6)ptr->Stats_type[Stats::DEF_SHRED][AType::SKILL] += 20;

        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ac,Charge]() {
            Charge(1);
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"Archer Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ac]() {
            if(ptr->Eidolon>=6&&turn->isSameName("Archer")){
                genSkillPoint(ac,1);
            }
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ac]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(isBuffEnd(ac,"Archer A6")){
                buffSingle(ac,{{Stats::CD,AType::None,-120}});
            }
            if(enemy&&isDebuffEnd(enemy,"Archer E2")){
                debuffSingle(enemy,{{Stats::RESPEN,ElementType::Quantum,AType::None,-20}});
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_Last, [ptr,Skill,ac,Charge,Fua](shared_ptr<AllyAttackAction> &act) {
            if(act->actionName=="Archer Skill"){
                if(sp>=2&&ac->getStack("Archer Skill Limit")<5){
                    Skill();
                }else{
                buffResetStack(ac,{{Stats::DMG,AType::SKILL,100}},"Circuit Connection");
                ac->setStack("Archer Skill Limit",0);
                }
            }
            if(ac->getStack("Archer Charge")&&!act->isSameName("Archer")){
                Charge(-1);
                Fua();
            }
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_Last, [ptr,Skill,ac,Charge,Fua](AllyUnit *SP_maker, int SP) {
            if(sp>=4){
                buffSingle(ac,{{Stats::CD,AType::None,120}},"Archer A6",1);
            }
        }));
    }
}
