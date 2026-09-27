#include "../include.h"
namespace Relic{
    void Knight(CharUnit *ptr);
    void Knight(CharUnit *ptr){
        ptr->Relic.name = "Knight";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::DEF_P][AType::NONE]+=15;
            ptr->statsType[Stats::SHEILD][AType::NONE]+=20;
        }));
        
    }
}