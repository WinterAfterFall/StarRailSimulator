#include "../include.h"
namespace Relic{
    void Knight(Ally *ptr);
    void Knight(Ally *ptr){
        ptr->Relic.Name = "Knight";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AType::None]+=15;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_SHEILD][AType::None]+=20;
        }));
        
    }
}