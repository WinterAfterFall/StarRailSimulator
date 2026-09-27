#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> BlackSwan_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "BlackSwan_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::EHR][AType::NONE] += 35 + 5 * superimpose;
            }));

            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(!act->isSameOwnerName(ptr))return;
                for(Enemy* target : act->targetList){
                if(target->shockCount>0&&isHaveToAddBuff(ptr,"BS LC Shock"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::NONE,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::DOT,6.5+superimpose*0.7},
                });

                if(target->windSheerCount>0&&isHaveToAddBuff(ptr,"BS LC WindShear"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::NONE,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::DOT,6.5+superimpose*0.7},
                });
                if(target->burnCount>0&&isHaveToAddBuff(ptr,"BS LC Burn"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::NONE,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::DOT,6.5+superimpose*0.7},
                });

                if(target->bleedCount>0&&isHaveToAddBuff(ptr,"BS LC Bleed"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::NONE,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::DOT,6.5+superimpose*0.7},
                });
                }
            }));
    
        };
    }
}