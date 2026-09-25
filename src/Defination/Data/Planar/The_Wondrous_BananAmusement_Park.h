#include "../include.h"
namespace Planar{
    void The_Wondrous_BananAmusement_Park(CharUnit *ptr){
        
        ptr->Planar.Name="The_Wondrous_BananAmusement_Park"; 
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 16;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            bool onField = ptr->summonList.size() != 0 || (ptr->memosprite && ptr->memosprite->isExisted());
            if (onField && !ptr->getBuffCheck("Banana")) {
                ptr->setBuffCheck("Banana", 1);
                ptr->Stats_type[Stats::CD][AType::None] += 32;
            } else if (!onField && ptr->getBuffCheck("Banana")) {
                ptr->setBuffCheck("Banana", 0);
                ptr->Stats_type[Stats::CD][AType::None] -= 32;
            }
        }));
       
    }
}