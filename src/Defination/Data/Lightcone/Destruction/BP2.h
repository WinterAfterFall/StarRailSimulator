#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> BP2(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,331);
            ptr->Light_cone.Name = "Destruction BP2";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                        
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AType::None]+=10 + (2*superimpose);
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::SKILL]+=20 + (4*superimpose);
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::Ult]+=20 + (4*superimpose);
                
                }
            ));
        };
    }
}
