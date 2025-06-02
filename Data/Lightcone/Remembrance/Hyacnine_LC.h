
#ifndef Hyacnine_LC_H
#define Hyacnine_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Hyacnine_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "Hyacnine_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 15 + 3 * superimpose;
            }));

            BeforeAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<ActionData> &act) {
                AllyActionData *allyaction = act->castToAllyActionData();
                if(!allyaction)return;
                if(allyaction->Attacker->Atv_stats->Side == "Memosprite"
                    &&allyaction->Attacker->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num
                    &&allyaction->isSameAction(AT_SKILL)){
                        debuffAllEnemyApply({{ST_VUL,AT_NONE,(13.5 + 4.5 * superimpose)}},allyaction->Attacker,"Hyacnine_LC Debuff",2);
                }
                if(!ptr->getSubUnit()->isSameUnitName(allyaction->Attacker->Atv_stats->Unit_Name))return;
                if(allyaction->isSameAction(AT_BA)
                ||allyaction->isSameAction(AT_SKILL)
                ||allyaction->isSameAction(AT_ULT)){
                    double temp = 0;
                    for(int i=1;i<=Total_ally;i++){
                        for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                            temp+=each->currentHP*0.01;
                        }
                    }
                    ptr->getSubUnit()->Buff_note["Hyacnine_LC Note"] +=temp;
                    DecreaseHP(ptr->getSubUnit(),0,0,(0.75 + 0.25 * superimpose));
                }
            }));

            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->Attacker->Atv_stats->Side == "Memosprite"
                    &&act->Attacker->Atv_stats->num==ptr->getSubUnit()->Atv_stats->num
                    &&act->isSameAction(AT_SKILL)){
                        shared_ptr<AllyAttackAction> addtionaldmg = 
                        make_shared<AllyAttackAction>(ActionType::Addtional,act->Attacker,TT_SINGLE,"Hyc LC AddDmg");
                        act->addDamageIns(DmgSrc(DmgSrcType::CONST,ptr->getSubUnit()->Buff_note["Hyacnine_LC Note"] * (1.875 + 0.625 * superimpose),0));
                        Attack(addtionaldmg);
                        
                        ptr->getSubUnit()->setBuffNote("Hyacnine_LC Note",0);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(enemy->isDebuffEnd("Hyacnine_LC Debuff")){
                    enemy->debuffSingle({{ST_VUL,AT_NONE,-(13.5 + 4.5 * superimpose)}});
                }
            }));
        };
    }
    
}
#endif