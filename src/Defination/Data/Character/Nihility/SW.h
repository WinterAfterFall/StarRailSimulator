#include "../include.h"

namespace Pela{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(107,110,110,E,ElementType::Quantum,"Nihility","SW",TYPE_STD);
        ptr->SetAllyBaseStats(1048,640,461);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
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
