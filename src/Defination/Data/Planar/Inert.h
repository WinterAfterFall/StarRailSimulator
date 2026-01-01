#include "../include.h"
namespace Planar{
    void Inert(CharUnit *ptr){
        
        ptr->Planar.Name = "SpaceSealing";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CR][AType::None] += 8;
            ptr->Stats_type[Stats::DMG][AType::Ult] += 15;
            ptr->Stats_type[Stats::DMG][AType::Fua] += 15;
        }));
        
       
    }
}