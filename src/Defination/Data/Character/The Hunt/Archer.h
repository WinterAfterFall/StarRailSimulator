#include "../include.h"

namespace Archer{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(105,220,220,E,ElementType::Quantum,"The Hunt","Archer",TYPE_STD);
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

        SubUnit *ac = ptr->getSubUnit();
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
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Archer BA",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                Skill_point(ac,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,ac]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Archer Skill",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                Skill_point(ac,-2);
                Increase_energy(ptr,30);
                ac->calStack(1,5,"Archer Skill Limit");
                if(ptr->Eidolon>=6)ac->buffStackSingle({{Stats::DMG,AType::SKILL,100}},1,3,"Circuit Connection");
                else ac->buffStackSingle({{Stats::DMG,AType::SKILL,100}},1,2,"Circuit Connection");
                Attack(act);
                if(ptr->Eidolon>=1){
                    ac->addStack("Archer E1",1);
                    if(ac->getStack("Archer E1")==3){
                        ac->setStack("Archer E1",0);
                        Skill_point(ac,2);
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
            make_shared<AllyAttackAction>(AType::Fua,ptr->getSubUnit(),TT_SINGLE,"Archer Fua",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                Skill_point(ac,1);
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
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,ac,BA,Skill]() {
            if(sp>=2 * ptr->Adjust["Archer Minimum"])Skill();
            else BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,ac,Charge]() {
            if (!ultUseCheck(ptr))return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TT_SINGLE,"Archer Ult",
            [ptr,ac,Charge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Archer");
                Charge(2);
                if(ptr->Eidolon>=2){
                    for(auto &each : act->targetList){
                        each->debuffSingleApply({{Stats::RESPEN,ElementType::Quantum,AType::None,20}},ac,"Archer E2",2);
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
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 6.7;

            // relic

            // substats
            if(ptr->Eidolon>=4)ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Ult] += 150;
            if(ptr->Eidolon>=6)ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::SKILL] += 20;

        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ac,Charge]() {
            Charge(1);
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TT_AOE,"Archer Tech",
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
            if(ptr->Eidolon>=6&&turn->isSameUnitName("Archer")){
                Skill_point(ac,1);
            }
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ac]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(ac->isBuffEnd("Archer A6")){
                ac->buffSingle({{Stats::CD,AType::None,-120}});
            }
            if(enemy&&enemy->isDebuffEnd("Archer E2")){
                enemy->debuffSingle({{Stats::RESPEN,ElementType::Quantum,AType::None,-20}});
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_Last, [ptr,Skill,ac,Charge,Fua](shared_ptr<AllyAttackAction> &act) {
            if(act->actionName=="Archer Skill"){
                if(sp>=2&&ac->getStack("Archer Skill Limit")<5){
                    Skill();
                }else{
                ac->buffResetStack({{Stats::DMG,AType::SKILL,100}},"Circuit Connection");
                ac->setStack("Archer Skill Limit",0);
                }
            }
            if(ac->getStack("Archer Charge")&&!act->isSameAtkerName("Archer")){
                Charge(-1);
                Fua();
            }
        }));

        Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_Last, [ptr,Skill,ac,Charge,Fua](SubUnit *SP_maker, int SP) {
            if(sp>=4){
                ac->buffSingle({{Stats::CD,AType::None,120}},"Archer A6",1);
            }
        }));
    }
}
