#include "../include.h"

namespace Hibana{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(107,160,160,eidolon,ElementType::FIRE,Path::ELATION,"Hibana",UnitType::STANDARD);
        ptr->setAllyBaseStats(1051,640,460);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        // ptr->setSpeedRequire(134);
        ptr->setAtkRequire(3600);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::ATK_P,Stats::ATK_P);
        
        elationCount++;
        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Hibana BA",
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
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"Hibana EBA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                int skillCharge = 0;
                while(sp){
                    if(ptr->getStack("Hbn Thrill")){
                        ptr->addStack("Hbn Thrill",-1);
                        if(ptr->eidolon>=2){
                            buffStackSingle(ptr,{{Stats::CD,AType::NONE,10}},1,4,"Hbn E2",2);
                        }
                        allEventSkillPoint(ptr,-1);
                    }
                    else genSkillPoint(ptr,-1);
                    skillCharge++;
                    ptr->addStack("Hibana Skill Count",1);
                    if(ptr->stack["Hibana Skill Count"]%6==3){
                        genSkillPoint(ptr,2);   
                        genPunchLine(ptr,2);
                    }
                    else genPunchLine(ptr,1);
                }
                act->multiplyDmg(100 + 20*skillCharge);
                
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,40);
                attack(act);
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::BLAST,"Hbn EBA Elation");
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,40),
                    DmgSrc(DmgSrcType::ELATION,20)
                );
                elDmg->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,20),skillCharge);
                attack(elDmg);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,50,5)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,ba,eba]() {
            if(sp + ptr->getStack("Hbn Thrill") >=3)eba();
            else ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            CharCmd::printUltStart("Hibana");
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Hibana Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){

                ptr->addStack("Hbn Thrill",1);
                if(elationCount==1)genPunchLine(ptr,2+2);
                else if(elationCount==2)genPunchLine(ptr,2+4);
                else{
                    genPunchLine(ptr,2+8);
                    ptr->addStack("Hbn Thrill",3);
                }
                if(ptr->eidolon>=4){
                    genPunchLine(ptr,5);
                    buffSingle(ptr,{{Stats::ELATION,AType::NONE,36}},"Hbn E4",3);
                }


                attack(act);
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"Hbn Ult Elation");
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,48),
                    DmgSrc(DmgSrcType::ELATION,48),
                    DmgSrc(DmgSrcType::ELATION,48)
                );
                attack(elDmg);
            });
            double mtpr = 0.6 * calculateElationOnStats(ptr) + 50;
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,mtpr,20),
                DmgSrc(DmgSrcType::ATK,mtpr,20),
                DmgSrc(DmgSrcType::ATK,mtpr,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        elationSkillList.push_back(TriggerByYourSelfFunc(144, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,"Hbn Elation Skill",
            [ptr](shared_ptr<AllyAttackAction> &act){
                ptr->addStack("Hbn Thrill",2);
                increaseEnergy(ptr,5);    
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,50),
                DmgSrc(DmgSrcType::ELATION,50),
                DmgSrc(DmgSrcType::ELATION,50)
            );
            act->addEnemyBounce(
                DmgSrc(DmgSrcType::ELATION,25),20
            );

            if(ptr->eidolon>=6)act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,25),min(punchline,40));
            act->addToAhaInstant();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ELATION][AType::NONE] += 28;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::CD][AType::NONE] += 13.3;

            ptr->statsType[Stats::ELATION][AType::NONE] += 80;

            if(ptr->eidolon>=6)ptr->statsType[Stats::RESPEN][AType::NONE] += 20;

        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ba,eba](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Hbn E2")){
            buffCharResetStack(ptr,{{Stats::CD,AType::NONE,10}},"Hbn E2");
            }
            if(isBuffEnd(ptr,"Hbn E4")){
            buffSingle(ptr,{{Stats::ELATION,AType::NONE,-36}});
            }
        }));



        punchLineList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            int buff = max(0,min(10,punchline));
            buffAllAlly({
                {Stats::CD,AType::TEMP,buff*8 - ptr->buffNote["Hbn Buff"]},
                {Stats::CD,AType::NONE,buff*8 - ptr->buffNote["Hbn Buff"]}
            });
            ptr->setBuffNote("Hbn Buff",buff*8);
            if(ptr->eidolon<1)return;
            buffAllAlly({
                {Stats::RESPEN,AType::TEMP,buff*1.5 - ptr->buffNote["Hbn E1"]},
                {Stats::RESPEN,AType::NONE,buff*1.5 - ptr->buffNote["Hbn E1"]}
            });
            ptr->setBuffNote("Hbn E1",buff*1.5);
        }));

        
        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ba,eba](CharUnit *ptr) {
            if(ptr->eidolon>=1)genPunchLine(ptr,1);

            if(ptr->eidolon>=2){
                if(sp + ptr->getStack("Hbn Thrill") >=3)eba();
                else ba();
                dealDamage();
            }
        }));

    }
}
