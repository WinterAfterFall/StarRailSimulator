#include "../include.h"
namespace Planar{
    void Inert(Ally *ptr){
        
        ptr->Planar.Name = "SpaceSealing";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Ult] += 15;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Fua] += 15;
        }));
        
       
    }
}