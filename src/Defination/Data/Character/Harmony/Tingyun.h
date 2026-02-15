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
        
        ptr->Turn_func = [ptr, allyPtr = ptr]() {
            if (chooseSubUnitBuff(allyPtr)->Buff_check["Benediction"] == 0) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        ptr->addUltCondition([ptr,TYptr]() -> bool {
            if(chooseSubUnitBuff(TYptr)->isSameName("Saber"))return true;
            if(charUnit[ptr->currentCharNum]->Max_energy==0)return true;
            if (charUnit[ptr->currentCharNum]->Max_energy - charUnit[ptr->currentCharNum]->Current_energy <= 30) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"TY Ult",
            [ptr,TYptr](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Tingyun");
                Increase_energy(charUnit[ptr->currentCharNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);
                if (ptr->Eidolon >= 1)
                buffSingle(chooseSubUnitBuff(ptr),{{Stats::SPD_P,AType::None,20}},"Windfall_of_Lucky_Springs",1);
                
                if (turn->Name == charUnit[ptr->currentCharNum]->Atv_stats->Name && phaseStatus == PhaseStatus::BeforeTurn)
                buffSingle(chooseSubUnitBuff(ptr),{{Stats::DMG,AType::None,56}},"Rejoicing_Clouds",1);
                else
                buffSingle(chooseSubUnitBuff(ptr),{{Stats::DMG,AType::None,56}},"Rejoicing_Clouds",2);
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Lightning][AType::None] += 8;
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_type[Stats::DEF_P][AType::None] += 22.5;

            // relic

            // substats
            ptr->Stats_type[Stats::DMG][AType::BA] += 40;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            if (turn->Name != "Tingyun") return;
            Increase_energy(ptr, 5);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,TYptr]() {
            AllyUnit* tempUnit = turn->canCastToSubUnit();
            if (!tempUnit) return;
            
            if (isBuffEnd(tempUnit,"Nourished_Joviality")) {
                buffSingle(tempUnit,{{Stats::SPD_P,AType::None,-20}});
            }
            
            if (isBuffEnd(tempUnit,"Benediction")) {
                buffSingle(tempUnit,{{Stats::ATK_P,AType::None,-55}});
            }
            if (isBuffEnd(tempUnit,"Windfall_of_Lucky_Springs")) {
                buffSingle(tempUnit,{{Stats::SPD_P,AType::None,-20}});
            }
            if (isBuffEnd(tempUnit,"Rejoicing_Clouds")) {
                buffSingle(tempUnit,{{Stats::DMG,AType::None,-56}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,TYptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr,TYptr](shared_ptr<AllyAttackAction> &act) {
            AllyUnit* tempUnit = act->Attacker;
            if (chooseSubUnitBuff(ptr)->getBuffCheck("Benediction")) {
                if (act->Attacker->Atv_stats->Name == ptr->Atv_stats->Name) {
                    shared_ptr<AllyAttackAction> temp = 
                    make_shared<AllyAttackAction>(AType::Addtional,chooseSubUnitBuff(ptr),TraceType::Single,"TY Talent");
                    temp->addDamageIns(DmgSrc(DmgSrcType::ATK,66));
                    Attack(temp);
                } else if (act->Attacker->isSameName(chooseSubUnitBuff(ptr))) {
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
        Skill_point(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"TY Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            buffSingle(act->buffTargetList[0],{{Stats::ATK_P,AType::None,55}},"Benediction",3);
            buffSingle(ptr,{{Stats::SPD_P,AType::None,20}},"Nourished_Joviality",1);

        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr));
        act->addToActionBar();
    }
    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
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