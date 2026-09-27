#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> For_Tomorrow_Journey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "For_Tomorrow_Journey";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 12 + 4 * superimpose;
            }));

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::NONE,(15.0 + 3 * superimpose)}
                    },"For_Tomorrow_Journey_Buff",1);
                }
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"For_Tomorrow_Journey_Buff")) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::NONE,-(15.0 + 3 * superimpose)}
                    });
                }
            }));
        };
    }
}