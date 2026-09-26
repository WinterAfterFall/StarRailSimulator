#include "../include.h"
namespace Relic{
    void Poet_Dill(CharUnit *ptr);
    void Poet_Dill(CharUnit *ptr){
        ptr->Relic.Name = "Poet_Dill";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Atv_stats->speedPercent -= 8;
            ptr->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 10;
        }));
        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            buffSingleChar(ptr,{{Stats::CR, AType::None, 32.0}});
        }));
        
        
    }
}