#include "../include.h"
namespace Planar{
    void TengokuLivestream(CharUnit *ptr){
        ptr->Planar.name="Tengoku@Livestream";
        
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 16;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setStack("Tengoku sp count",0);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Tengoku Buff"))
            buffSingle(ptr,{{Stats::CD,AType::NONE,-32}});
        }));

        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            if(spChange<0)
            ptr->addStack("Tengoku sp count",-1*spChange);
            if(ptr->getStack("Tengoku sp count")>=3)
            buffSingle(ptr,{{Stats::CD,AType::NONE,32}},"Tengoku Buff",3);  
        })); 
    }
}