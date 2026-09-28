#include "../include.h"
namespace Elation_Lightcone{
    // Until the Flowers Bloom Again (Evanescia's Signature) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    // the DMG-taken debuff is "effects of the same type cannot stack" -> one shared name (no wearer prefix)
    function<void(CharUnit *ptr)> Evanescia_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "Evanescia_LC";
            const string debuffName = "Until the Flowers Bloom Again";

            // CRIT DMG 60/75/90/105/120% · ERR 10/11.5/13/14.5/16%
            // Max Energy > 120: +0.3% ERR per 10 excess Max Energy (max 360 excess)
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 45 + 15 * superimpose;
                double excess = min(360.0,max(0.0,ptr->maxEnergy - 120));
                ptr->energyRecharge += 8.5 + 1.5 * superimpose + 0.3 * floor(excess/10);
            }));

            // wearer uses Elation Skill -> all enemies DMG taken 15/18.75/22.5/26.25/30% for 2 turns
            whenUseElationSkillList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](CharUnit *ally) {
                if(ally!=ptr)return;
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,11.25 + 3.75 * superimpose}},debuffName,2);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,debuffName](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,debuffName)){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(11.25 + 3.75 * superimpose)}});
                }
            }));
        };
    }
}
