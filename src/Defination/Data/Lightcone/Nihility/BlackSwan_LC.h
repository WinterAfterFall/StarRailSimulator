#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> BlackSwan_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "BlackSwan_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 35 + 5 * superimpose;
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, SubUnit *Trigger) {
                if(target->ShockCount>0&&ptr->getSubUnit()->isHaveToAddBuff("BS LC Shock"))
                ptr->getSubUnit()->buffSingle({
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });

                if(target->WindSheerCount>0&&ptr->getSubUnit()->isHaveToAddBuff("BS LC WindShear"))
                ptr->getSubUnit()->buffSingle({
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });
                if(target->BurnCount>0&&ptr->getSubUnit()->isHaveToAddBuff("BS LC Burn"))
                ptr->getSubUnit()->buffSingle({
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });

                if(target->BleedCount>0&&ptr->getSubUnit()->isHaveToAddBuff("BS LC Bleed"))
                ptr->getSubUnit()->buffSingle({
                    {Stats::ATK_P,AType::None,4.0+superimpose},
                    {Stats::DEF_SHRED,AType::None,6.5+superimpose*0.7},
                });
            }));
    
        };
    }
}