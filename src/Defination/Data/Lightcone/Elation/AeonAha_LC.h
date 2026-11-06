#include "../include.h"
namespace Elation_Lightcone{
    // Upon the First Echo of "Aha" (Aeon Aha's Signature)
    // the DEF ignore is "cannot be stacked" -> one shared name on each ally (no wearer prefix)
    function<void(CharUnit *ptr)> AeonAha_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "AeonAha_LC";
            // base SPD 12/14/16/18/20
            ptr->atvStats->baseSpeed += 10 + 2 * superimpose;

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->setBuffCheck("Aha LC Punchline Used",0);
            }));

            // once every 1 turn -> re-armed at the start of the wearer's turn
            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                if(turn->isSameUnit(ptr))ptr->setBuffCheck("Aha LC Punchline Used",0);
            }));

            // Skill on one other ally -> +10/12/14/16/18 Punchline,
            //   then all allies ignore 16/18/20/22/24% DEF for the rest of the battle
            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyBuffAction> &act) {
                if(!act->isSameAction(ptr,AType::SKILL))return;
                if(act->buffTargetList.size()!=1||act->buffTargetList[0]==ptr)return;
                if(ptr->getBuffCheck("Aha LC Punchline Used"))return;
                ptr->setBuffCheck("Aha LC Punchline Used",1);
                genPunchLine(ptr,8 + 2 * superimpose);
                for(auto &each : allyList){
                    if(isHaveToAddBuff(each,"Upon the First Echo of Aha"))
                    buffSingle(each,{{Stats::DEF_SHRED,AType::NONE,14.0 + 2 * superimpose}});
                }
            }));
        };
    }
}
