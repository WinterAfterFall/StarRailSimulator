#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> For_Tomorrow_Journey(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "For_Tomorrow_Journey";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12 + 4 * superimpose;
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                    ptr->getSubUnit()->buffSingle({
                        {Stats::DMG,AType::None,(15.0 + 3 * superimpose)}
                    },"For_Tomorrow_Journey_Buff",1);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Himeko_LC_buff")) {
                    ptr->getSubUnit()->buffSingle({
                        {Stats::DMG,AType::None,-(15.0 + 3 * superimpose)}
                    });
                }
            }));
        };
    }
}