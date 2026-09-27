#include "../include.h"
namespace Relic{
    void MagicalGirl(CharUnit *ptr){
        ptr->Relic.name = "Ever-Glorious Magical Girl";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 16;
        }));
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffSingleChar(ptr,{{Stats::DEF_SHRED, AType::ELATION_DMG, 10.0}});
        }));

        punchLineList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            int buff = max(0,min(50,punchline)/5);
            buffSingleChar(ptr,{
                {Stats::DEF_SHRED,AType::ELATION_DMG,buff - ptr->buffNote["MagicalGirl Buff"]}
            });
            ptr->setBuffNote("MagicalGirl Buff",buff);
        }));
        
    }
    
}