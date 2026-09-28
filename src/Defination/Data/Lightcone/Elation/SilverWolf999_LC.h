#include "../include.h"
namespace Elation_Lightcone{
    // Welcome to the Cosmic City (Silver Wolf LV.999's Signature) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    function<void(CharUnit *ptr)> SilverWolf999_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1164,476,529);
            ptr->lightCone.name = "SilverWolf999_LC";

            // SPD 18/21/24/27/30% · Elation DMG ignores 20/24/28/32/36% DEF
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 15 + 3 * superimpose;
                ptr->statsType[Stats::DEF_SHRED][AType::ELATION_DMG] += 16 + 4 * superimpose;
                ptr->setBuffCheck("Cosmic City Used",0);
                ptr->setBuffNote("Cosmic City BA",0);
            }));

            // Ultimate on themselves -> +20/25/30/35/40 Punchline · once, re-armed after 3 Basic ATKs
            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyBuffAction> &act) {
                if(!act->isSameAction(ptr,AType::ULT))return;
                if(find(act->buffTargetList.begin(),act->buffTargetList.end(),ptr)==act->buffTargetList.end())return;
                if(ptr->getBuffCheck("Cosmic City Used"))return;
                ptr->setBuffCheck("Cosmic City Used",1);
                ptr->setBuffNote("Cosmic City BA",0);
                genPunchLine(ptr,15 + 5 * superimpose);
            }));

            afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &act) {
                if(!act->isSameAction(ptr,AType::BA))return;
                if(!ptr->getBuffCheck("Cosmic City Used"))return;
                ptr->buffNote["Cosmic City BA"] += 1;
                if(ptr->getBuffNote("Cosmic City BA")<3)return;
                ptr->setBuffCheck("Cosmic City Used",0);
                ptr->setBuffNote("Cosmic City BA",0);
            }));
        };
    }
}
