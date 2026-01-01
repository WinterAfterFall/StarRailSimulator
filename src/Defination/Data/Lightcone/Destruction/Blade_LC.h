#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Blade_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1270,582,331);
            ptr->Light_cone.Name = "Blade_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                        
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None]+=15 + (3*superimpose);
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None]+=15 + (3*superimpose);
                
                }
            ));
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *Attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    if(e->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get())){
                        if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Blade_LC_Mark")){
                            ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::DMG,AType::None,(20.0 + 4*superimpose)}});
                        }
                        return;
                    }
                }
            }));
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,[ptr,superimpose](Unit *Trigger,AllyUnit *target,double Value){
                if(!target->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get()))return;
                if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Blade_LC_Mark")){
                            ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::DMG,AType::None,(20.0 + 4*superimpose)}});
                }
                
            }));
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->Attacker->isSameStatsOwnerName(ptr->Sub_Unit_ptr[0].get()))return;
                if(ptr->Sub_Unit_ptr[0]->getBuffCheck("Blade_LC_Mark")){
                    ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::DMG,AType::None,-(20.0 + 4*superimpose)}});
                    ptr->Sub_Unit_ptr[0]->Buff_check["Blade_LC_Mark"] = 0;
                }
            }));
        };
    }
}
