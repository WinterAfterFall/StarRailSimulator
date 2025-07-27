#include "../include.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Geniuses_Greetings(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Geniuses_Greetings";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12 + 4 * superimpose;
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                    ptr->buffAlly({{Stats::DMG,AType::BA,(15.0 + superimpose * 5)}},"Geniuses_Greetings",3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptrToChar);
                if (!tempstats) return;
                if (ptr->getSubUnit()->isBuffEnd("Geniuses_Greetings")) {
                    ptr->getSubUnit()->buffSingle({{Stats::DMG,AType::BA,-(15.0 + superimpose * 5)}});
                }
            }));
        };
    }
    void Geniuses_Greetings(Ally *ptr){

    }
    
}