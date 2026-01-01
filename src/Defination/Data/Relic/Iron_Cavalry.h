#include "../include.h"
namespace Relic{
    void Iron_Cavalry(CharUnit *ptr);
    void Iron_Cavalry(CharUnit *ptr){
        ptr->Relic.Name = "Iron_Cavalry";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 16;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::Break] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::SPB] += 15;
        }));

        
    }
}