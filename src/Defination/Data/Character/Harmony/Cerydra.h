#include "../include.h"

namespace Cerydra{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(99,130,130,eidolon,ElementType::WIND,Path::HARMONY,"Cerydra",UnitType::STANDARD);
        ptr->setAllyBaseStats(1358,621,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        // ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::ATK_P,Stats::ATK_P,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *crd = ptr;

        function<void(int value)> charge = [ptr,crd](int value) {
            crd->addStack("Cerydra charge",value);
        };

        #pragma region Ability

        function<void()> ba = [ptr,crd]() {
            genSkillPoint(crd,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Crd BA",
            [ptr,crd](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(crd,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,crd,charge]() {
            genSkillPoint(crd,-1);
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Crd Skill",
            [ptr,crd,charge](shared_ptr<AllyBuffAction> &act){
                increaseEnergy(crd,30);
                charge(1);
                buffSingle(crd,{
                    {Stats::FLAT_SPD,AType::NONE,20}
                },"Veci",3);
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::FLAT_SPD,AType::NONE,20}
                },"Veci",3);
                if(ptr->eidolon>=1){
                    increaseEnergy(chooseAllyBuff(crd),2);
                }
            });
            act->addBuffSingleTarget();
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,crd,ba,skill]() {
            if(sp>spSafety+1)skill();
            else ba();
        };

        // ptr->turnFunc = [ptr,crd,BA,Skill]() {
        //     if(!chooseSubUnitBuff(crd)->getBuffCheck("Veci"))Skill();
        //     else BA();
        // };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [crd,charge](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Crd Ult",
            [ptr,crd,charge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Cerydra");
                charge(2);
                attack(act);
                crd->setStack("Cerydra Talent Limit",0);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20)
            );
            if(ptr->eidolon>=4)act->multiplyDmg(200);
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [crd,charge](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 22.4;
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;

            ptr->statsType[Stats::CR][AType::NONE] += 100;
            charge(2);
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [crd,charge](CharUnit *ptr) {
            if(ptr->eidolon>=1){
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::DEF_SHRED,AType::NONE,16}
                });
            }
            if(ptr->eidolon>=2){
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::DMG,AType::NONE,40}
                });
                buffSingle(crd,{
                    {Stats::DMG,AType::NONE,140}
                });
            }
            if(ptr->eidolon>=6){
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::RESPEN,AType::NONE,20}
                });
                buffSingle(crd,{
                    {Stats::RESPEN,AType::NONE,20}
                });
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [crd](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Veci")){
                buffSingle(ally,{{Stats::FLAT_SPD,AType::NONE,-20}});
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [crd,charge](CharUnit *ptr) {
            double temp = 0;
            temp = calculateAtkForBuff(crd,24);
            buffSingle(chooseAllyBuff(crd),
                {
                    {Stats::FLAT_ATK,AType::TEMP,temp - crd->buffNote["Cerydra Atk Buff"]},
                    {Stats::FLAT_ATK,AType::NONE,temp - crd->buffNote["Cerydra Atk Buff"]}
                });
            crd->buffNote["Cerydra Atk Buff"] = temp;

            double temp2 = min(max(0.0,floor((calculateAtkForBuff(crd,100) - 2000)/100)),20.0)*18;
            buffSingle(crd,
                {
                    {Stats::CD,AType::TEMP,temp2 - crd->buffNote["Cerydra Crit dam Buff"]},
                    {Stats::CD,AType::NONE,temp2 - crd->buffNote["Cerydra Crit dam Buff"]}
                });
            crd->buffNote["Cerydra Crit dam Buff"] = temp2;

            if(ptr->technique){
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Crd Skill",
            [ptr,crd,charge](shared_ptr<AllyBuffAction> &act){
                increaseEnergy(crd,30);
                charge(1);
                buffSingle(crd,{
                    {Stats::FLAT_SPD,AType::NONE,20}
                },"Veci",3);
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::FLAT_SPD,AType::NONE,20}
                },"Veci",3);
                if(ptr->eidolon>=1){
                    increaseEnergy(chooseAllyBuff(crd),2);
                }
            });
            act->turnReset = 0;
            act->addToActionBar();
            }
        }));

        beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyActionData> &act) {
            if(act->attacker->isSameName(chooseAllyBuff(crd))&&
            (act->isSameAction(AType::SKILL)||act->isSameAction(AType::BA))){
                increaseEnergy(ptr,5);
                if(!crd->getBuffCheck("Peerage"))charge(1);
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameAction(chooseAllyBuff(crd),AType::SKILL)&&crd->getBuffCheck("Peerage")){
                if(crd->getBuffCheck("Coup de Main")){
                    shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(*act);
                    newAct->addToActionBar();
                    crd->setBuffCheck("Coup de Main",0);
                }else{
                    crd->setBuffCheck("Peerage",0);
                    buffSingle(chooseAllyBuff(crd),{
                        {Stats::DMG,AType::SKILL,-72},
                        {Stats::RESPEN,AType::SKILL,-10},
                    });
                    if(ptr->eidolon>=1){
                        buffSingle(chooseAllyBuff(crd),{
                            {Stats::DEF_SHRED,AType::SKILL,-20}
                        });
                    }                    
                } 
            }
            if(crd->getStack("Cerydra charge")>=6){
                crd->addStack("Cerydra charge",-6);
                crd->setBuffCheck("Peerage",1);
                crd->setBuffCheck("Coup de Main",1);
                buffSingle(chooseAllyBuff(crd),{
                    {Stats::DMG,AType::SKILL,72},
                    {Stats::RESPEN,AType::SKILL,10},
                });
                if(ptr->eidolon>=1){
                    buffSingle(chooseAllyBuff(crd),{
                        {Stats::DEF_SHRED,AType::SKILL,20}
                    });
                }
            }
        }));
        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyAttackAction> &act) {
            if(act->attacker->isSameName(chooseAllyBuff(crd))&&crd->getStack("Cerydra Talent Limit")<20){
                crd->addStack("Cerydra Talent Limit",1);
                shared_ptr<AllyAttackAction> newAct = 
                    make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"Crd AddDmg");
                        newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,60));
                        if(ptr->eidolon>=6)newAct->multiplyDmg(600);
                    attack(newAct);
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,crd](AllyUnit *target, Stats statsType) {
            if (target->atvStats->name != "Cerydra") return;
            if (statsType == Stats::ATK_P || statsType == Stats::FLAT_ATK) {
            double temp = 0;
            temp = calculateAtkForBuff(crd,24);
            buffSingle(chooseAllyBuff(crd),
                {
                    {Stats::FLAT_ATK,AType::TEMP,temp - crd->buffNote["Cerydra Atk Buff"]},
                    {Stats::FLAT_ATK,AType::NONE,temp - crd->buffNote["Cerydra Atk Buff"]}
                });
            crd->buffNote["Cerydra Atk Buff"] = temp;
            double temp2 = min(max(0.0,floor((temp - 2000)/100)),20.0)*18;
            buffSingle(crd,
                {
                    {Stats::CD,AType::TEMP,temp2 - crd->buffNote["Cerydra Crit dam Buff"]},
                    {Stats::CD,AType::NONE,temp2 - crd->buffNote["Cerydra Crit dam Buff"]}
                });
            crd->buffNote["Cerydra Crit dam Buff"] = temp2;
            }
        }));
    }
}
