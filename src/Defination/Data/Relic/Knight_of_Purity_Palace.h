#include "../include.h"
namespace Relic{
    void Knight(CharUnit *ptr);
    void Knight(CharUnit *ptr){
        ptr->Relic.Name = "Knight";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::DEF_P][AType::None]+=15;
            ptr->Stats_type[Stats::SHEILD][AType::None]+=20;
        }));
        
    }
}