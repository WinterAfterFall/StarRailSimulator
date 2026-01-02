#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Clara_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,582,397);
            ptr->Light_cone.Name = "Clara_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                ptr->Stats_type[Stats::ATK_P][AType::None]+=20 + (4*superimpose);
            }));
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,[ptr,superimpose](Enemy *Attacker,vector<AllyUnit*> target){
                for(AllyUnit* e : target){
                    if(e->isSameStatsOwnerName(ptr)){
                        e->RestoreHP(e,HealSrc(HealSrcType::ATK,6.0 + superimpose * 2.0));
                        e->buffSingle({{Stats::DMG,AType::None,(20.0 + 4*superimpose)}},"Clara_LC",1);
                        return;
                    }
                }
            }));
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if(isBuffEnd(ptr,"Clara_LC")){
                    buffSingle(ptr,{{Stats::DMG,AType::None,-(20.0 + 4*superimpose)}});
                }
            }));
            
        };
    }
}
