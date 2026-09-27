#include "../include.h"
namespace Planar{
    void The_Wondrous_BananAmusement_Park(CharUnit *ptr){
        
        ptr->Planar.name="The_Wondrous_BananAmusement_Park"; 
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 16;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            bool onField = ptr->summonList.size() != 0 || (ptr->memosprite && ptr->memosprite->isExisted());
            if (onField && !ptr->getBuffCheck("Banana")) {
                ptr->setBuffCheck("Banana", 1);
                ptr->statsType[Stats::CD][AType::NONE] += 32;
            } else if (!onField && ptr->getBuffCheck("Banana")) {
                ptr->setBuffCheck("Banana", 0);
                ptr->statsType[Stats::CD][AType::NONE] -= 32;
            }
        }));
       
    }
}