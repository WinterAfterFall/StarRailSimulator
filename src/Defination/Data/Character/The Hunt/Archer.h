#include "../include.h"

namespace Archer{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(105,220,220,eidolon,ElementType::QUANTUM,Path::HUNT,"Archer",UnitType::STANDARD);
        ptr->setAllyBaseStats(1164,621,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CD,Stats::ATK_P,Stats::ATK_P,Stats::ATK_P);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *ac = ptr;
        maxSp +=2;
        ptr->adjust["Archer Minimum"] = 3;

        #pragma region extra
        function<void(int value)> charge = [ptr,ac](int value){
            ac->stack["Archer Charge"] += value;
            if(ac->stack["Archer Charge"]>=4)ac->stack["Archer Charge"] = 4;
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr,ac]() {
            genSkillPoint(ac,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Archer BA",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,ac]() {
            genSkillPoint(ac,-2);
            calStack(ac,1,5,"Archer Skill Limit");
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::SINGLE,"Archer Skill",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                if(ptr->eidolon>=6)buffStackSingle(ac,{{Stats::DMG,AType::SKILL,100}},1,3,"Circuit Connection");
                else buffStackSingle(ac,{{Stats::DMG,AType::SKILL,100}},1,2,"Circuit Connection");
                attack(act);
                if(ptr->eidolon>=1){
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

        function<void()> fua = [ptr,ac]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::SINGLE,"Archer Fua",
            [ptr,ac](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ac,1);
                increaseEnergy(ptr,5);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,10)
            );
            act->addToActionBar();
            dealDamage();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,ac,ba,skill]() {
            if(sp>=2 * ptr->adjust["Archer Minimum"])skill();
            else ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [ac,charge](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::SINGLE,"Archer Ult",
            [ptr,ac,charge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Archer");
                charge(2);
                if(ptr->eidolon>=2){
                    for(auto &each : act->targetList){
                        debuffSingleApply(ac,each,{{Stats::RESPEN,ElementType::QUANTUM,AType::NONE,20}},"Archer E2",2);
                    }
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,1000,30)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 22.4;
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::CR][AType::NONE] += 6.7;

            // relic

            // substats
            if(ptr->eidolon>=4)ptr->statsType[Stats::DMG][AType::ULT] += 150;
            if(ptr->eidolon>=6)ptr->statsType[Stats::DEF_SHRED][AType::SKILL] += 20;

        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ac,charge](CharUnit *ptr) {
            charge(1);
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Archer Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ac](CharUnit *ptr) {
            if(ptr->eidolon>=6&&turn->isSameName("Archer")){
                genSkillPoint(ac,1);
            }
        }));


        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ac](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(isBuffEnd(ac,"Archer A6")){
                buffSingle(ac,{{Stats::CD,AType::NONE,-120}});
            }
            if(enemy&&isDebuffEnd(enemy,"Archer E2")){
                debuffSingle(enemy,{{Stats::RESPEN,ElementType::QUANTUM,AType::NONE,-20}});
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_LAST, [ptr,skill,ac,charge,fua](shared_ptr<AllyAttackAction> &act) {
            if(act->actionName=="Archer Skill"){
                if(sp>=2&&ac->getStack("Archer Skill Limit")<5){
                    skill();
                }else{
                buffResetStack(ac,{{Stats::DMG,AType::SKILL,100}},"Circuit Connection");
                ac->setStack("Archer Skill Limit",0);
                }
            }
            if(ac->getStack("Archer Charge")&&!act->isSameName("Archer")){
                charge(-1);
                fua();
            }
        }));

        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_LAST, [ptr,skill,ac,charge,fua](AllyUnit *spMaker, int spChange) {
            if(sp>=4){
                buffSingle(ac,{{Stats::CD,AType::NONE,120}},"Archer A6",1);
            }
        }));
    }
}
