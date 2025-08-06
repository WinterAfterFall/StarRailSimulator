#include "../include.h"

namespace SomeChar{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(102,110,110,E,ElementType::Physical,Path::Nihility,"Hysilens",UnitType::Standard);
        ptr->SetAllyBaseStats(1203,602,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setApplyBaseChance(120);
        ptr->setRelicMainStats(Stats::EHR,Stats::ATK_P,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        SubUnit *hys =ptr->getSubUnit();

        #pragma region Ability

        function<void()> BA = [ptr,hys]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Hys BA",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                Skill_point(hys,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hys]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Aoe,"Hys Skill",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                Skill_point(hys,-1);
                Increase_energy(ptr,30);
                debuffAllEnemyApply({{Stats::VUL,AType::None,20}},hys,"Hys Vul",3);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,hys]() {

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Ice][AType::None] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 10;

            // relic

            // substats
        }));
    }
}
