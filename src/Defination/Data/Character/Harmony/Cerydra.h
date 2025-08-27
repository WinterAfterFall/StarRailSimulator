#include "../include.h"

namespace Cerydra{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99,130,130,E,ElementType::Wind,Path::Harmony,"Cerydra",UnitType::Standard);
        ptr->SetAllyBaseStats(1358,621,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        // ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::ATK_P,Stats::ATK_P,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        SubUnit *crd = ptr->getSubUnit();

        function<void(int value)> charge = [ptr,crd](int value) {
            crd->addStack("Cerydra charge",value);
            if(crd->getStack("Cerydra charge")>=6){
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Talent,ptr->getSubUnit(),TraceType::Single,"Crd Talent",
            [ptr,crd](shared_ptr<AllyBuffAction> &act){
                crd->addStack("Cerydra charge",-6);
                crd->setBuffCheck("Peerage",1);
                crd->setBuffCheck("Coup de Main",1);
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::DMG,AType::SKILL,72},
                    {Stats::RESPEN,AType::SKILL,10},
                });
                if(ptr->Eidolon>=1){
                    chooseSubUnitBuff(crd)->buffSingle({
                        {Stats::DEF_SHRED,AType::SKILL,20}
                    });
                }
            });
            act->addToActionBar();
            }
        };

        #pragma region Ability

        function<void()> BA = [ptr,crd]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Crd BA",
            [ptr,crd](shared_ptr<AllyAttackAction> &act){
                Skill_point(crd,1);
                Increase_energy(crd,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,crd,charge]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Single,"Crd Skill",
            [ptr,crd,charge](shared_ptr<AllyBuffAction> &act){
                Skill_point(crd,-1);
                Increase_energy(crd,30);
                charge(1);
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::FLAT_SPD,AType::None,20}
                },"Veci",3);
                if(ptr->Eidolon>=1){
                    Increase_energy(chooseSubUnitBuff(crd),2);
                }
            });
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,crd,BA,Skill]() {
            if(sp>Sp_Safety)Skill();
            else BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,crd,charge]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TraceType::Aoe,"Crd Ult",
            [ptr,crd,charge](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Cerydra");
                charge(2);
                Attack(act);
                crd->setStack("Cerydra Talent Limit",0);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20),
                DmgSrc(DmgSrcType::ATK,240,20)
            );
            if(ptr->Eidolon>=4)act->multiplyDmg(200);
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 10;

            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 100;
            charge(2);
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge]() {
            if(ptr->Eidolon>=1){
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::DEF_SHRED,AType::None,16}
                });
            }
            if(ptr->Eidolon>=2){
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::DMG,AType::None,40}
                });
                crd->buffSingle({
                    {Stats::DMG,AType::None,140}
                });
            }
            if(ptr->Eidolon>=6){
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::RESPEN,AType::None,20}
                });
                crd->buffSingle({
                    {Stats::RESPEN,AType::None,20}
                });
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,crd]() {
            SubUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;
            if(ally->isBuffEnd("Veci")){
                ally->buffSingle({{Stats::FLAT_SPD,AType::None,-20}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge]() {
            double temp = 0;
            temp = calculateAtkForBuff(crd,24);
            chooseSubUnitBuff(crd)->buffSingle(
                {
                    {Stats::FLAT_ATK,AType::TEMP,temp - crd->Buff_note["Cerydra Atk Buff"]},
                    {Stats::FLAT_ATK,AType::None,temp - crd->Buff_note["Cerydra Atk Buff"]}
                });
            crd->Buff_note["Cerydra Atk Buff"] = temp;

            double temp2 = min(max(0.0,floor((calculateAtkForBuff(crd,100) - 2000)/100)),20.0)*18;
            crd->buffSingle(
                {
                    {Stats::CD,AType::TEMP,temp2 - crd->Buff_note["Cerydra Crit dam Buff"]},
                    {Stats::CD,AType::None,temp2 - crd->Buff_note["Cerydra Crit dam Buff"]}
                });
            crd->Buff_note["Cerydra Crit dam Buff"] = temp2;

            if(ptr->Technique){
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Single,"Crd Skill",
            [ptr,crd,charge](shared_ptr<AllyBuffAction> &act){
                Increase_energy(crd,30);
                charge(1);
                chooseSubUnitBuff(crd)->buffSingle({
                    {Stats::FLAT_SPD,AType::None,20}
                },"Veci",3);
                if(ptr->Eidolon>=1){
                    Increase_energy(chooseSubUnitBuff(crd),2);
                }
            });
            act->Turn_reset = 0;
            act->addToActionBar();
            }
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyActionData> &act) {
            if(act->Attacker->isSameUnit(chooseSubUnitBuff(crd))&&
            (act->isSameAction(AType::SKILL)||act->isSameAction(AType::BA))){
                Increase_energy(ptr,5);
                if(!crd->getBuffCheck("Peerage"))charge(1);
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameAction(chooseSubUnitBuff(crd),AType::SKILL)&&crd->getBuffCheck("Peerage")){
                if(crd->getBuffCheck("Coup de Main")){
                    shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(*act);
                    newAct->addToActionBar();
                    crd->setBuffCheck("Coup de Main",0);
                }else{
                    crd->setBuffCheck("Peerage",0);
                    chooseSubUnitBuff(crd)->buffSingle({
                        {Stats::DMG,AType::SKILL,-72},
                        {Stats::RESPEN,AType::SKILL,-10},
                    });
                    if(ptr->Eidolon>=1){
                        chooseSubUnitBuff(crd)->buffSingle({
                            {Stats::DEF_SHRED,AType::SKILL,-20}
                        });
                    }                    
                } 
            }
        }));
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,crd,charge](shared_ptr<AllyAttackAction> &act) {
            if(act->Attacker->isSameUnit(chooseSubUnitBuff(crd))&&crd->getStack("Cerydra Talent Limit")<20){
                crd->addStack("Cerydra Talent Limit",1);
                shared_ptr<AllyAttackAction> newAct = 
                    make_shared<AllyAttackAction>(AType::Addtional,ptr->getSubUnit(),TraceType::Single,"Crd AddDmg");
                        newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,60));
                        if(ptr->Eidolon>=6)newAct->multiplyDmg(600);
                    Attack(newAct);
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,crd](SubUnit *target, Stats StatsType) {
            if (target->Atv_stats->Unit_Name != "Cerydra") return;
            if (StatsType == Stats::ATK_P || StatsType == Stats::FLAT_ATK) {
            double temp = 0;
            temp = calculateAtkForBuff(crd,24);
            chooseSubUnitBuff(crd)->buffSingle(
                {
                    {Stats::FLAT_ATK,AType::TEMP,temp - crd->Buff_note["Cerydra Atk Buff"]},
                    {Stats::FLAT_ATK,AType::None,temp - crd->Buff_note["Cerydra Atk Buff"]}
                });
            crd->Buff_note["Cerydra Atk Buff"] = temp;
            double temp2 = min(max(0.0,floor((temp - 2000)/100)),20.0)*18;
            crd->buffSingle(
                {
                    {Stats::CD,AType::TEMP,temp2 - crd->Buff_note["Cerydra Crit dam Buff"]},
                    {Stats::CD,AType::None,temp2 - crd->Buff_note["Cerydra Crit dam Buff"]}
                });
            crd->Buff_note["Cerydra Crit dam Buff"] = temp2;
            }
        }));
    }
}
