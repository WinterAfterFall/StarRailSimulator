#include "../include.h"
namespace Planar{
    void Lushaka(CharUnit *ptr);
    void Lushaka(CharUnit *ptr){
        
        ptr->Planar.name="Lushaka";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->energyRecharge += 5;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (ptr->atvStats->num != 1) {
                charUnit[1]->statsType[Stats::ATK_P][AType::NONE] += 12;
            }
        }));
       
    }
}