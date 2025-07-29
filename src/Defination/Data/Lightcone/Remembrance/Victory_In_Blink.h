#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Victory_In_Blink(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(847,476,397);
            ptr->Light_cone.Name = "Victory_In_Blink";
            string VictoryBlink = ptr->getSubUnit()->getUnitName() + " Victory_Blink";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 9 + 3 * superimpose;
            }));
    
            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink](shared_ptr<AllyBuffAction> &act) {
                if (act->Attacker->Atv_stats->side == Side::Memosprite &&
                    act->Attacker->ptrToChar->Sub_Unit_ptr[0]->Atv_stats->Char_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name) {
                    buffAllAlly({{Stats::DMG, AType::None, (6.0 + 2 * superimpose)}}, VictoryBlink,3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptrToChar);
                if (!tempstats) return;
                if (tempstats->isBuffEnd(VictoryBlink)) {
                    tempstats->Stats_type[Stats::DMG][AType::None] -= (6 + 2 * superimpose);
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,VictoryBlink](SubUnit* target) {
                if(target->isBuffGoneByDeath(VictoryBlink)){
                    target->Stats_type[Stats::DMG][AType::None] -= (6 + 2 * superimpose);
                }
            }));
        };
    }
    
}