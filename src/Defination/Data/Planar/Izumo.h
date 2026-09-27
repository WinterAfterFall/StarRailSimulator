#include "../include.h"
namespace Planar{
    void Izumo(CharUnit *ptr){
        
        ptr->Planar.name = "Izumo";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            for (int i = 1; i <= totalAlly; i++) {
                if (ptr->atvStats->name == charUnit[i]->atvStats->name) continue;
                if (charUnit[i]->path == ptr->path) {
                    ptr->statsType[Stats::CR][AType::NONE] += 12;
                    return;
                }
            }
        }));
        
       
    }
}