#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Jingliu_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,582,397);
            ptr->Light_cone.Name = "Jingliu_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None]+=17 + (3*superimpose);
            }));

            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *Attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    ptr->buffStackSingle({{Stats::DMG,AType::None,11.5 +2.5*superimpose}},1,3,"Jingliu_LC");
                }
                if(ptr->getStack("Jingliu_LC")>=3){
                    if(ptr->isHaveToAddBuff("Jingliu_LC Def Shred"))
                        ptr->buffSingle({{Stats::DEF_SHRED,AType::None,10.0 +2*superimpose}});
                }
            }));

            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,[ptr,superimpose](Unit *Trigger,AllyUnit *target,double Value){
                ptr->buffStackSingle({{Stats::DMG,AType::None,11.5 +2.5*superimpose}},1,3,"Jingliu_LC");
                if(ptr->getStack("Jingliu_LC")>=3){
                    if(ptr->isHaveToAddBuff("Jingliu_LC Def Shred"))
                        ptr->buffSingle({{Stats::DEF_SHRED,AType::None,10.0 +2*superimpose}});
                }

            }));
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->Attacker->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get()))return;
                ptr->buffResetStack({{Stats::DMG,AType::None,11.5 +2.5*superimpose}},"Jingliu_LC");
                if(ptr->getBuffCheck("Jingliu_LC Def Shred")){
                    ptr->buffSingle({{Stats::DEF_SHRED,AType::None,-(10.0 +2*superimpose)}});
                    ptr->setBuffCheck("Jingliu_LC Def Shred",0);
                }

            }));
        };
    }
}
