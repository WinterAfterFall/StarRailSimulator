#include "../include.h"

namespace Tingyun{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr =  SetCharBasicStats(112, 130, 130, E, ElementType::Lightning, Path::Harmony, "Tingyun",UnitType::Standard);
        AllyUnit *TYptr = ptr;
        ptr->SetAllyBaseStats(847, 529, 397);
        ptr->Technique = 2;
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);


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
            if(chooseSubUnitBuff(TYptr)->isSameStatsOwnerName("Saber"))return true;
            if(charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy==0)return true;
            if (charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Max_energy - charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Current_energy <= 30) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"TY Ult",
            [ptr,TYptr](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Tingyun");
                Increase_energy(charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);
                if (ptr->Eidolon >= 1)
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::SPD_P,AType::None,20}},"Windfall_of_Lucky_Springs",1);
                
                if (turn->UnitName == charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[0]->Atv_stats->UnitName && phaseStatus == PhaseStatus::BeforeTurn)
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::DMG,AType::None,56}},"Rejoicing_Clouds",1);
                else
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::DMG,AType::None,56}},"Rejoicing_Clouds",2);
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Lightning][AType::None] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 22.5;

            // relic

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::BA] += 40;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            if (turn->UnitName != "Tingyun") return;
            Increase_energy(ptr, 5);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            AllyUnit* tempUnit = turn->canCastToSubUnit();
            if (!tempUnit) return;
            
            if (tempUnit->isBuffEnd("Nourished_Joviality")) {
                tempUnit->buffSingle({{Stats::SPD_P,AType::None,-20}});
            }
            
            if (tempUnit->isBuffEnd("Benediction")) {
                tempUnit->buffSingle({{Stats::ATK_P,AType::None,-55}});
            }
            if (tempUnit->isBuffEnd("Windfall_of_Lucky_Springs")) {
                tempUnit->buffSingle({{Stats::SPD_P,AType::None,-20}});
            }
            if (tempUnit->isBuffEnd("Rejoicing_Clouds")) {
                tempUnit->buffSingle({{Stats::DMG,AType::None,-56}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,TYptr](shared_ptr<AllyAttackAction> &act) {
            AllyUnit* tempUnit = act->Attacker;
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->getBuffCheck("Benediction")) {
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Sub_Unit_ptr[0]->Atv_stats->StatsOwnerName) {
                    shared_ptr<AllyAttackAction> temp = 
                    make_shared<AllyAttackAction>(AType::Addtional,chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),TraceType::Single,"TY Talent");
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,66));
                    Attack(temp);
                } else if (act->Attacker->Atv_stats->StatsOwnerName == charUnit[ptr->Sub_Unit_ptr[0]->currentAllyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->currentSubUnitTargetNum]->Atv_stats->StatsOwnerName) {
                    shared_ptr<AllyAttackAction> temp = 
                    make_shared<AllyAttackAction>(AType::Addtional,tempUnit,TraceType::Single,"TY Talent");

                    if (ptr->Eidolon >= 4) 
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,64));
                    else 
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,44));
                    Attack(temp);
                    
                }
            }
        }));
    



    }

    void Skill(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"TY Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            act->buffTargetList[0]->buffSingle({{Stats::ATK_P,AType::None,55}},"Benediction",3);
            ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::SPD_P,AType::None,20}},"Nourished_Joviality",1);

        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"TY BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,33,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,77,7));
        act->addToActionBar();
    }
}