#include "../include.h"
namespace Elation_Lightcone{
    // Colors for Tomorrow (Pearl's Signature) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    // "an Elation Skill on all allies" = a wearer's Elation Skill that queues no attack of its own
    // (Pearl's Dissolve Reason into Elation); an attacking Elation Skill does not trigger it
    function<void(CharUnit *ptr)> Pearl_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,476,595);
            ptr->lightCone.name = "Pearl_LC";
            string debuffName = ptr->getName() + " Colors for Tomorrow";

            // DEF 48/60/72/84/96%
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DEF_P][AType::NONE] += 36 + 12 * superimpose;
            }));

            // Elation Skill on all allies -> all enemies DMG taken 22/27.5/33/38.5/44% for 3 turns,
            //   fixed 10 Energy, heal all allies 10/12.5/15/17.5/20% of the wearer's DEF
            whenUseElationSkillList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](CharUnit *ally) {
                if(ally!=ptr)return;
                if(!ahaInstantBar.empty()){
                    shared_ptr<AllyActionData> &last = ahaInstantBar.back();
                    if(last->getChar()==ptr&&dynamic_pointer_cast<AllyAttackAction>(last))return;
                }
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,16.5 + 5.5 * superimpose}},debuffName,3);
                increaseEnergy(ptr,0,10);
                ptr->restoreHP(HealSrc(HealSrcType::DEF,7.5 + 2.5 * superimpose));
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,debuffName](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,debuffName)){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(16.5 + 5.5 * superimpose)}});
                }
            }));
        };
    }
}
