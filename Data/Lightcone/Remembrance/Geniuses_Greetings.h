
#ifndef Geniuses_Greetings_H
#define Geniuses_Greetings_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Geniuses_Greetings(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Geniuses_Greetings";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["ATK%"][AT_NONE] += 12 + 4 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->buffAlly({{ST_DMG,AT_BA,(15.0 + superimpose * 5)}},"Geniuses_Greetings",3);
                }
            }));
    
            Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->buffAlly({{ST_DMG,AT_BA,(15.0 + superimpose * 5)}},"Geniuses_Greetings",3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptrToChar);
                if (!tempstats) return;
                if (ptr->getSubUnit()->isBuffEnd("Geniuses_Greetings")) {
                    ptr->getSubUnit()->buffSingle({{ST_DMG,AT_BA,-(15.0 + superimpose * 5)}});
                }
            }));
        };
    }
    void Geniuses_Greetings(Ally *ptr){

    }
    
}
#endif