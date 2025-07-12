#include "../include.h"

namespace SomeChar{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(,,,E,ElementType::,,,TYPE_STD);
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
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Ice][AT_NONE] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += 10;

            // relic

            // substats
        }));
    }
}
