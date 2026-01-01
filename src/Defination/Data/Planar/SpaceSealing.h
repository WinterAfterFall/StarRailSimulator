#include "../include.h"
namespace Planar{
    void SpaceSealing(CharUnit *ptr){
        
        ptr->Planar.Name = "SpaceSealing";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 24;
        }));
        
       
    }
}