#include "../include.h"

namespace SomeChar{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(,,,E,ElementType::,,,UnitType::Standard);
        ptr->SetAllyBaseStats(,,);

        //substats
        ptr->pushSubstats();
        ptr->pushSubstats();
        ptr->pushSubstats();
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire();
        ptr->setApplyBaseChance();
        ptr->setRelicMainStats(,,,);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::,ptr->getSubUnit(),,,"Kafka BA"
            [ptr](shared_ptr<AllyAttackAction> &act){
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
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

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
