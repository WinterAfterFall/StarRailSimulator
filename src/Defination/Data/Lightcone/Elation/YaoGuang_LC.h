#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> YaoGuang_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,529);
            ptr->lightCone.name = "YaoGuang_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 15 + 3 * superimpose;
            }));

            startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                increaseEnergy(ptr,0,15);
            }));

            startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(isHaveToAddBuff(ptr,"Great Fortune",3)){
                    ptr->energyRecharge += 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::NONE,9.0 + superimpose},
                        {Stats::CD, AType::NONE,22.5 + 7.5 * superimpose}
                    });
                }
            }));

            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyBuffAction> &act) {
                if(!act->isSameAction(ptr,AType::ULT))return;
                if(isHaveToAddBuff(ptr,"Great Fortune",3)){
                    ptr->energyRecharge += 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::NONE,9.0 + superimpose},
                        {Stats::CD, AType::NONE,22.5 + 7.5 * superimpose}
                    });
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Great Fortune")) {
                    ptr->energyRecharge -= 10 + 2 * superimpose;
                    buffAllAlly({
                        {Stats::CR, AType::NONE,-(9.0 + superimpose)},
                        {Stats::CD, AType::NONE,-(22.5 + 7.5 * superimpose)}
                    });
                }
            }));
        };
    }
}
