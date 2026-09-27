#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Himeko_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,582,397);
            ptr->lightCone.name = "Himeko_LC";
    
            whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += (7.5 + superimpose * 1.5) * totalEnemy;
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Himeko_LC_buff")) {
                    ptr->statsType[Stats::DMG][AType::NONE] -= 25+superimpose*5;
                }
            }));
    
            toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *breaker) {
                buffSingle(ptr,{{Stats::DMG,AType::NONE,(25.0 + superimpose*5)}},"Himeko_LC_buff",1);
            }));
        };
    }
}