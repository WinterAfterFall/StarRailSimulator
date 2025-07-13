#include "../include.h"

namespace Tingyun{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr =  SetAllyBasicStats(112, 130, 130, E, ElementType::Lightning, "Harmony", "Tingyun",TYPE_STD);
        SubUnit *TYptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(847, 529, 397);
        ptr->Technique = 2;
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_ATK_P,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (chooseSubUnitBuff(allyPtr)->Buff_check["Benediction"] == 0) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        ptr->addUltCondition([ptr,TYptr]() -> bool {
            if(chooseSubUnitBuff(TYptr)->isSameUnitName("Saber"))return true;
            if(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy==0)return true;
            if (Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Current_energy <= 30) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_SINGLE,"TY Ult",
            [ptr,TYptr](shared_ptr<AllyBuffAction> &act){
                Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);
                if (ptr->Eidolon >= 1)
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,20}},"Windfall_of_Lucky_Springs",1);
                
                if (turn->Char_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[0]->Atv_stats->Char_Name && Situation == "Before Turn")
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,56}},"Rejoicing_Clouds",1);
                else
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,56}},"Rejoicing_Clouds",2);
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Lightning][AT_NONE] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 22.5;

            // relic

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Basic_Attack"] += 40;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            if (turn->Char_Name != "Tingyun") return;
            Increase_energy(ptr, 5);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            SubUnit* tempUnit = turn->canCastToSubUnit();
            if (!tempUnit) return;
            
            if (tempUnit->isBuffEnd("Nourished_Joviality")) {
                tempUnit->buffSingle({{ST_SPD,ST_SPD_P,-20}});
            }
            
            if (tempUnit->isBuffEnd("Benediction")) {
                tempUnit->buffSingle({{ST_ATK_P,AT_NONE,-55}});
            }
            if (tempUnit->isBuffEnd("Windfall_of_Lucky_Springs")) {
                tempUnit->buffSingle({{ST_SPD,ST_SPD_P,-20}});
            }
            if (tempUnit->isBuffEnd("Rejoicing_Clouds")) {
                tempUnit->buffSingle({{ST_DMG,AT_NONE,-56}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,TYptr](shared_ptr<AllyAttackAction> &act) {
            SubUnit* tempUnit = act->Attacker;
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->getBuffCheck("Benediction")) {
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    shared_ptr<AllyAttackAction> temp = 
                    make_shared<AllyAttackAction>(ActionType::Addtional,chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),TT_SINGLE,"TY Talent");
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,66));
                    Attack(temp);
                } else if (act->Attacker->Atv_stats->Unit_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->currentSubUnitTargetNum]->Atv_stats->Unit_Name) {
                    shared_ptr<AllyAttackAction> temp = 
                    make_shared<AllyAttackAction>(ActionType::Addtional,tempUnit,TT_SINGLE,"TY Talent");

                    if (ptr->Eidolon >= 4) 
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,64));
                    else 
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,44));
                    Attack(temp);
                    
                }
            }
        }));
    



    }

    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"TY Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            act->buffTargetList[0]->buffSingle({{ST_ATK_P,AT_NONE,55}},"Benediction",3);
            ptr->Sub_Unit_ptr[0]->buffSingle({{ST_SPD,ST_SPD_P,20}},"Nourished_Joviality",1);

        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"TY BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,33,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,77,7));
        act->addToActionBar();
    }
}