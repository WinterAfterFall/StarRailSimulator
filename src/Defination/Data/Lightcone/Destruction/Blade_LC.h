#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Blade_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1270,582,331);
            ptr->Light_cone.Name = "Blade_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                        
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE]+=15 + (3*superimpose);
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE]+=15 + (3*superimpose);
                
                }
            ));
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *Attacker,vector<SubUnit*> target){
                for(SubUnit* e : target){
                    if(e->isSameUnit(ptr->Sub_Unit_ptr[0].get())){
                        if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Blade_LC_Mark")){
                            ptr->Sub_Unit_ptr[0]->buffSingle({{ST_DMG,AT_NONE,(20.0 + 4*superimpose)}});
                        }
                        return;
                    }
                }
            }));
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,[ptr,superimpose](Unit *Trigger,SubUnit *target,double Value){
                if(!target->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
                if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Blade_LC_Mark")){
                            ptr->Sub_Unit_ptr[0]->buffSingle({{ST_DMG,AT_NONE,(20.0 + 4*superimpose)}});
                }
                
            }));
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyAttackAction> &act){
                if(!act->Attacker->isSameUnit(ptr->Sub_Unit_ptr[0].get()))return;
                if(ptr->Sub_Unit_ptr[0]->getBuffCheck("Blade_LC_Mark")){
                    ptr->Sub_Unit_ptr[0]->buffSingle({{ST_DMG,AT_NONE,-(20.0 + 4*superimpose)}});
                    ptr->Sub_Unit_ptr[0]->Buff_check["Blade_LC_Mark"] = 0;
                }
            }));
        };
    }
}
