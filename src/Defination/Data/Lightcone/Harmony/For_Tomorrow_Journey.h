#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> For_Tomorrow_Journey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "For_Tomorrow_Journey";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 12 + 4 * superimpose;
            }));

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameChar(ptr)) {
                    ptr->buffSingle({
                        {Stats::DMG,AType::None,(15.0 + 3 * superimpose)}
                    },"For_Tomorrow_Journey_Buff",1);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->isBuffEnd("Himeko_LC_buff")) {
                    ptr->buffSingle({
                        {Stats::DMG,AType::None,-(15.0 + 3 * superimpose)}
                    });
                }
            }));
        };
    }
}