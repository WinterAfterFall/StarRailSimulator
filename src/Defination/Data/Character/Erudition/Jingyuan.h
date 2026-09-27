
#include "../include.h"

namespace Jingyuan{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);

    bool tempTurnCondition(Unit *ptr);
    bool tempUltCondition(CharUnit *ptr);



    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(99, 130, 130, eidolon, ElementType::LIGHTNING, Path::ERUDITION, "Jingyuan",UnitType::STANDARD);
        AllyUnit *jyPtr = ptr;
        ptr->setAllyBaseStats(1164, 698, 485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);



        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            if ((sp <= spSafety) || allyPtr->atvStats->turnCnt == 1 && spMode == SPMode::NEGATIVE) {
                basicAtk(ptr);
            } else {
                skill(ptr);
            }
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [jyPtr](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,jyPtr,TraceType::AOE,"JY Ult",
            [ptr,jyPtr](shared_ptr<AllyAttackAction> &act){
                attack(act);
                if (ptr->print)CharCmd::printUltStart("Jingyuan");
                ptr->stack["LL_stack"] += 3;
                if (ptr->stack["LL_stack"] >= 10) {
                    ptr->summonList[0]->flatSpeed = 70;
                    ptr->summonList[0]->speedBuff({Stats::FLAT_SPD,AType::NONE,0});
                } else {
                    ptr->summonList[0]->speedBuff({Stats::FLAT_SPD,AType::NONE,30});
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            dealDamage();
        }));
        

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [jyPtr](CharUnit *ptr) {
            if (!(ptr->atvStats->num == turn->num && turn->side == Side::ALLY)) return;
            
            if (isBuffEnd(jyPtr,"War_Marshal")) {
                buffSingle(jyPtr,{{Stats::CR,AType::NONE,-10}});
            }
            ;
            if (ptr->eidolon >= 2 && isBuffEnd(jyPtr,"Swing_Skies_Squashed")) {
                buffSingle(jyPtr,{
                    {Stats::DMG,AType::BA,-20},
                    {Stats::DMG,AType::SKILL,-20},
                    {Stats::DMG,AType::ULT,-20}
                });
            }
        }));


        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 12.5;

            // relic

            // substats

            // LL
            ptr->stack["LL_stack"] = 3;
            ptr->summonList[0]->flatSpeed = 0;
            ptr->summonList[0]->speedPercent = 0;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [jyPtr](CharUnit *ptr) {
            if (ptr->technique == 1) {
                ptr->stack["LL_stack"] += 3;
                ptr->summonList[0]->speedBuff({Stats::FLAT_SPD,AType::NONE,30});

            }
            increaseEnergy(ptr, 15);
        }));


        //LL
        setSummonStats(ptr, 60, "LL");
        ptr->summonList[0]->turnFunc = [ptr,jyPtr](){
            
            shared_ptr<AllyAttackAction> temp = 
            make_shared<AllyAttackAction>(AType::FUA,jyPtr,TraceType::SINGLE,"LL Fua",
            [ptr,jyPtr](shared_ptr<AllyAttackAction> &act){
                if(ptr->stack["LL_stack"]>=6){
                    ptr->statsType[Stats::CR][AType::SUMMON]+=25;
                }

                for(int i=1;i<=ptr->stack["LL_stack"];i++){
                    if(ptr->eidolon>=1)
                        act->addDamageIns(
                            DmgSrc(DmgSrcType::ATK,66,5),
                            DmgSrc(DmgSrcType::ATK,33,5)
                        );
                    else
                        act->addDamageIns(
                            DmgSrc(DmgSrcType::ATK,66,5),
                            DmgSrc(DmgSrcType::ATK,66*0.25,5)
                        );
                    
                }
                attack(act);

                if(ptr->stack["LL_stack"]>=6){
                    ptr->statsType[Stats::CR][AType::SUMMON]-=25;
                }
        
                turn->flatSpeed = 0;
                ptr->stack["LL_stack"] = 3;
                
                
                if(ptr->eidolon>=2){
                    buffSingle(jyPtr,{
                        {Stats::DMG,AType::BA,20},
                        {Stats::DMG,AType::SKILL,20},
                        {Stats::DMG,AType::ULT,20}},
                        "Swing_Skies_Squashed",2
                    );
                }
            });
            temp->addAttackType(AType::SUMMON);
            temp->setTurnReset(true);
            temp->addToActionBar();
            

        };
    }

    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"JY BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,45,4.5));
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"JY Skill",
        [ptr,jyPtr = ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            buffSingle(jyPtr,{{Stats::CR,AType::NONE,10}},"War_Marshal",2);
            ptr->stack["LL_stack"]+=2;
            if(ptr->stack["LL_stack"]>=10){
                ptr->summonList[0]->flatSpeed=70;
                ptr->summonList[0]->speedBuff({Stats::FLAT_SPD,AType::NONE,0});
            }else{
                ptr->summonList[0]->speedBuff({Stats::FLAT_SPD,AType::NONE,20});
            }
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,40,4),
            DmgSrc(DmgSrcType::ATK,40,4),
            DmgSrc(DmgSrcType::ATK,40,4)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3)
        );
        act->addToActionBar();
    }



    bool tempTurnCondition(Unit *ptr){
        return true;
    }
    bool tempUltCondition(CharUnit *ptr){
        return true;
    }
}