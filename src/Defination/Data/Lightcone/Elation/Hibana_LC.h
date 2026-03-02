#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> Hibana_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,582,463);
            ptr->Light_cone.Name = "Hibana_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CD][AType::None] += 40 + superimpose * 8;
            }));

            Setup_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Max_sp+=min(3,elationCount);
            }));

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->setStack("Hibana LC sp count",0);
            }));

            Skill_point_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr,superimpose](AllyUnit *SP_maker, int SP) {
                if(ptr->isSameName(SP_maker)&&SP<0)
                ptr->addStack("Hibana LC sp count",-1*SP);
                buffStackSingle(ptr,{{Stats::DEF_SHRED,AType::ElationDMG,4.0 + superimpose}},-1.0*SP,4,"Hibana LC Defshred");
                if(ptr->getStack("Hibana LC sp count")>=4){
                    for(auto &each : allyList){
                        if(isHaveToAddBuff(each,"Stream Promo"))
                        buffSingle(each,{{Stats::Elation,AType::None,16.0 + 4 * superimpose}});
                    }
                }
            }));            
        };
    }
}
