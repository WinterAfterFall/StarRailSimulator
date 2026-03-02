#include "../include.h"
namespace Relic{
    void MagicalGirl(CharUnit *ptr){
        ptr->Relic.Name = "Ever-Glorious Magical Girl";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 16;
            ptr->Stats_type[Stats::DEF_SHRED][AType::ElationDMG] += 10;
        }));

        PunchLine_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *SP_maker, int SP) {
            int buff = max(0,min(50,punchline)/5);
            buffAllAlly({
                {Stats::DEF_SHRED,AType::ElationDMG,buff - ptr->Buff_note["MagicalGirl Buff"]}
            });
            ptr->setBuffNote("MagicalGirl Buff",buff);
        }));
        
    }
    
}