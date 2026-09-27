#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Phainon_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,687,397);
            ptr->lightCone.name = "Phainon_LC";
            ptr->atvStats->baseSpeed += 10 + superimpose * 2;
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DEF_SHRED][AType::NONE] += 13.5 + 4.5 * superimpose;
            }));
    
            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    buffSingle(ptr,{{Stats::DMG,AType::NONE,42.0 + 18.0 * superimpose}},"Blazing Sun",1);
                }
            }));

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Blazing Sun")) {
                    buffSingle(ptr,{{Stats::DMG,AType::NONE,-(42.0 + 18.0 * superimpose)}});
                }
            }));
        };
    }
}
