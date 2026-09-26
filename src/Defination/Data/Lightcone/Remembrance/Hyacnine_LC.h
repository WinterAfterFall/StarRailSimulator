#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Hyacnine_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "Hyacnine_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Atv_stats->speedPercent += 15 + 3 * superimpose;
            }));

            BeforeAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<ActionData> &act) {
                AllyActionData *allyaction = act->castToAllyActionData();
                if(!allyaction)return;
                if(allyaction->Attacker->Atv_stats->side == Side::Memosprite
                    &&allyaction->Attacker->Atv_stats->num==ptr->Atv_stats->num
                    &&allyaction->isSameAction(AType::SKILL)){
                        debuffAllEnemyApply(allyaction->Attacker,{{Stats::VUL,AType::None,(13.5 + 4.5 * superimpose)}},"Hyacnine_LC Debuff",2);
                }
                if(!ptr->isSameName(allyaction->Attacker->Atv_stats->Name))return;
                if(allyaction->isSameAction(AType::BA)
                ||allyaction->isSameAction(AType::SKILL)
                ||allyaction->isSameAction(AType::Ult)){
                    double consumePercent = 0.75 + 0.25 * superimpose;
                    double temp = 0;
                    for(auto &each : allyList){
                        if(!each->isTargetable())continue;
                        temp += each->currentHP * consumePercent / 100;
                    }
                    ptr->buffNote["Hyacnine_LC Note"] += temp;
                    DecreaseHP(ptr,0,0,consumePercent);
                }
            }));

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                // kit: after the next attack launched by the wearer's memosprite
                if(act->Attacker->Atv_stats->side != Side::Memosprite
                    ||act->Attacker->Atv_stats->num != ptr->Atv_stats->num)return;
                double consumed = ptr->buffNote["Hyacnine_LC Note"];
                if(consumed <= 0)return;
                // reset first: the Additional DMG is also a memosprite attack and fires this list again
                ptr->setBuffNote("Hyacnine_LC Note",0);
                shared_ptr<AllyAttackAction> addtionaldmg =
                make_shared<AllyAttackAction>(AType::Addtional,act->Attacker,TraceType::Single,"Hyc LC AddDmg");
                addtionaldmg->addDamageIns(DmgSrc(DmgSrcType::CONST,consumed * (1.875 + 0.625 * superimpose),0));
                Attack(addtionaldmg);
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Hyacnine_LC Debuff")){
                    debuffSingle(enemy,{{Stats::VUL,AType::None,-(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }

}