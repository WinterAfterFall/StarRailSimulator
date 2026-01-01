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
                if(allyaction->Attacker->Atv_stats->side == Side::AllyUnit
                    &&allyaction->Attacker->Atv_stats->num==ptr->Atv_stats->num
                    &&allyaction->isSameAction(AType::SKILL)){
                        debuffAllEnemyApply({{Stats::VUL,AType::None,(13.5 + 4.5 * superimpose)}},allyaction->Attacker,"Hyacnine_LC Debuff",2);
                }
                if(!ptr->isSameStatsOwnerName(allyaction->Attacker->Atv_stats->StatsOwnerName))return;
                if(allyaction->isSameAction(AType::BA)
                ||allyaction->isSameAction(AType::SKILL)
                ||allyaction->isSameAction(AType::Ult)){
                    double temp = 0;
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : charUnit[i]->Sub_Unit_ptr){
                            temp+=each->currentHP*0.01;
                        }
                    }
                    ptr->Buff_note["Hyacnine_LC Note"] +=temp;
                    DecreaseHP(ptr,0,0,(0.75 + 0.25 * superimpose));
                }
            }));

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->Attacker->Atv_stats->side == Side::AllyUnit
                    &&act->Attacker->Atv_stats->num==ptr->Atv_stats->num
                    &&act->isSameAction(AType::SKILL)){
                        shared_ptr<AllyAttackAction> addtionaldmg = 
                        make_shared<AllyAttackAction>(AType::Addtional,act->Attacker,TraceType::Single,"Hyc LC AddDmg");
                        act->addDamageIns(DmgSrc(DmgSrcType::CONST,ptr->Buff_note["Hyacnine_LC Note"] * (1.875 + 0.625 * superimpose),0));
                        Attack(addtionaldmg);
                        
                        ptr->setBuffNote("Hyacnine_LC Note",0);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(enemy->isDebuffEnd("Hyacnine_LC Debuff")){
                    enemy->debuffSingle({{Stats::VUL,AType::None,-(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }
    
}