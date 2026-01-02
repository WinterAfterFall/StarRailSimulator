#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> BlackSwan_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "BlackSwan_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 35 + 5 * superimpose;
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                if(target->ShockCount>0&&isHaveToAddBuff(ptr,"BS LC Shock"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });

                if(target->WindSheerCount>0&&isHaveToAddBuff(ptr,"BS LC WindShear"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });
                if(target->BurnCount>0&&isHaveToAddBuff(ptr,"BS LC Burn"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });

                if(target->BleedCount>0&&isHaveToAddBuff(ptr,"BS LC Bleed"))
                buffSingle(ptr,{
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });
            }));
    
        };
    }
}