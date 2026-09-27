#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Anaxa_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Anaxa_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DMG][AType::NONE] += 50 + 10*superimpose;
            }));

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if(!turn->isSameName(ptr->atvStats->name))return;
                increaseEnergy(ptr,10);
            }));

            whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(!act->isSameName(ptr))return;
                for(auto &each : act->targetList){
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::NONE,(9.0 + superimpose * 3.0)}},"AnaxaLC_Debuff",2);
                }
            }));

            
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"AnaxaLC_Debuff")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-(9.0 + superimpose * 3.0)}});
                }
            }));
        };
    }
}