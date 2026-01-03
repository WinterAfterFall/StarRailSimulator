#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(CharUnit *ptr)> Victory_In_Blink(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(847,476,397);
            ptr->Light_cone.Name = "Victory_In_Blink";
            string VictoryBlink = ptr->getUnitName() + " Victory_Blink";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink]() {
                ptr->Stats_type[Stats::CD][AType::None] += 9 + 3 * superimpose;
            }));
    
            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink](shared_ptr<AllyBuffAction> &act) {
                if (act->Attacker->Atv_stats->side == Side::AllyUnit &&
                    act->Attacker->owner->Atv_stats->UnitName == ptr->Atv_stats->UnitName) {
                    buffAllAlly({{Stats::DMG, AType::None, (6.0 + 2 * superimpose)}}, VictoryBlink,3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink]() {
                AllyUnit *tempstats = dynamic_cast<AllyUnit *>(turn->charptr);
                if (!tempstats) return;
                if (isBuffEnd(tempstats,VictoryBlink)) {
                    tempstats->Stats_type[Stats::DMG][AType::None] -= (6 + 2 * superimpose);
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink](AllyUnit* target) {
                if(isBuffGoneByDeath(target,VictoryBlink)){
                    target->Stats_type[Stats::DMG][AType::None] -= (6 + 2 * superimpose);
                }
            }));
        };
    }
    
}