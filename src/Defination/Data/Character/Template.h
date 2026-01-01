#include "../include.h"

namespace SomeChar{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(speed,maxEnergy,UltCost,E,ElementType::,Path::,Name,UnitType::Standard);
        ptr->SetAllyBaseStats(,,);

        //substats
        ptr->pushSubstats(Stats::);
        ptr->pushSubstats(Stats::);
        ptr->pushSubstats(Stats::);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire();
        ptr->setApplyBaseChance();
        ptr->setRelicMainStats(Stats::,Stats::,Stats::,Stats::);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *ally = ptr;
        #pragma region Ability

        function<void()> BA = [ptr,ally]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::,ptr,TraceType::,,
            [ptr,ally](shared_ptr<AllyAttackAction> &act){
                Skill_point(,1);
                Increase_energy(,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,ally,BA,Skill]() {

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,ally]() {
            if (!ultUseCheck(ptr)) return;

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,ally]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Ice][AType::None] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 10;

            // relic

            // substats
        }));
    }
}
