#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> Hibana_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,582,463);
            ptr->lightCone.name = "Hibana_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 40 + superimpose * 8;
            }));

            setupList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                // effects of the same type cannot stack: only the first wearer adds SP limit
                for(auto &each : charList){
                    if(each->lightCone.name != "Hibana_LC")continue;
                    if(each != ptr)return;
                    break;
                }
                maxSp+=min(3,elationCount);
            }));

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->setStack("Hibana LC sp count",0);
            }));

            skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](AllyUnit *spMaker, int spChange) {
                if(ptr->isSameName(spMaker)&&spChange<0){
                    ptr->addStack("Hibana LC sp count",-1*spChange);
                    buffStackSingle(ptr,{{Stats::DEF_SHRED,AType::ELATION_DMG,4.0 + superimpose}},-1.0*spChange,4,"Hibana LC Defshred");
                    if(ptr->getStack("Hibana LC sp count")>=4){
                        for(auto &each : allyList){
                            if(isHaveToAddBuff(each,"Stream Promo"))
                            buffSingle(each,{{Stats::ELATION,AType::NONE,16.0 + 4 * superimpose}});
                        }
                    }
                }
            }));            
        };
    }
}
