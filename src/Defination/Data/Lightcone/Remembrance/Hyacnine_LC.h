#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Hyacnine_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,476,529);
            ptr->lightCone.name = "Hyacnine_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 15 + 3 * superimpose;
            }));

            beforeActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<ActionData> &act) {
                AllyActionData *allyaction = act->castToAllyActionData();
                if(!allyaction)return;
                if(allyaction->attacker->atvStats->side == Side::MEMOSPRITE
                    &&allyaction->attacker->atvStats->num==ptr->atvStats->num
                    &&allyaction->isSameAction(AType::SKILL)){
                        debuffAllEnemyApply(allyaction->attacker,{{Stats::VUL,AType::NONE,(13.5 + 4.5 * superimpose)}},"Hyacnine_LC Debuff",2);
                }
                if(!ptr->isSameName(allyaction->attacker->atvStats->name))return;
                if(allyaction->isSameAction(AType::BA)
                ||allyaction->isSameAction(AType::SKILL)
                ||allyaction->isSameAction(AType::ULT)){
                    double consumePercent = 0.75 + 0.25 * superimpose;
                    double temp = 0;
                    for(auto &each : allyList){
                        if(!each->isTargetable())continue;
                        temp += each->currentHP * consumePercent / 100;
                    }
                    ptr->buffNote["Hyacnine_LC Note"] += temp;
                    decreaseHP(ptr,0,0,consumePercent);
                }
            }));

            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                // kit: after the next attack launched by the wearer's memosprite
                if(act->attacker->atvStats->side != Side::MEMOSPRITE
                    ||act->attacker->atvStats->num != ptr->atvStats->num)return;
                double consumed = ptr->buffNote["Hyacnine_LC Note"];
                if(consumed <= 0)return;
                // reset first: the Additional DMG is also a memosprite attack and fires this list again
                ptr->setBuffNote("Hyacnine_LC Note",0);
                shared_ptr<AllyAttackAction> addtionaldmg =
                make_shared<AllyAttackAction>(AType::ADDTIONAL,act->attacker,TraceType::SINGLE,"Hyc LC AddDmg");
                addtionaldmg->addDamageIns(DmgSrc(DmgSrcType::CONST,consumed * (1.875 + 0.625 * superimpose),0));
                attack(addtionaldmg);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Hyacnine_LC Debuff")){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }

}