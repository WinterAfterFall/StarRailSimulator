#include "../include.h"
namespace Elation_Lightcone{
    // Summer Rides the Surf (Aventurine • Waveflair's Signature) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    // the kit text gives Updraft / Uptrend no duration -> once gained they stay for the battle
    // "which Elation Skill" = the action name the wearer queued (e.g. "AvWF Cheers" / "AvWF All In"),
    //   or "" when it queued no action
    function<void(CharUnit *ptr)> AventurineWaveflair_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "AventurineWaveflair_LC";
            shared_ptr<string> lastSkill = make_shared<string>();

            // CRIT Rate 18/21/24/27/30%
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,lastSkill](CharUnit *ptr) {
                ptr->statsType[Stats::CR][AType::NONE] += 15 + 3 * superimpose;
                ptr->setBuffCheck("Summer Surf Updraft",0);
                ptr->setBuffCheck("Summer Surf Uptrend",0);
                ptr->setBuffCheck("Summer Surf Used Once",0);
                ptr->setBuffNote("Summer Surf Uses",0);
                *lastSkill = "";
            }));

            // Elation Skill -> Updraft SPD 24/28/32/36/40% · different from the last one -> Uptrend Elation 40/55/70/85/100%
            //   every 3 Elation Skills -> +1 SP
            whenUseElationSkillList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,lastSkill](CharUnit *ally) {
                if(ally!=ptr)return;
                string skill = "";
                if(!ahaInstantBar.empty()&&ahaInstantBar.back()->getChar()==ptr)skill = ahaInstantBar.back()->actionName;

                if(!ptr->getBuffCheck("Summer Surf Updraft")){
                    ptr->setBuffCheck("Summer Surf Updraft",1);
                    buffSingle(ptr,{{Stats::SPD_P,AType::NONE,20.0 + 4 * superimpose}});
                }
                if(ptr->getBuffCheck("Summer Surf Used Once")&&skill!=*lastSkill&&!ptr->getBuffCheck("Summer Surf Uptrend")){
                    ptr->setBuffCheck("Summer Surf Uptrend",1);
                    buffSingle(ptr,{{Stats::ELATION,AType::NONE,25.0 + 15 * superimpose}});
                }
                ptr->setBuffCheck("Summer Surf Used Once",1);
                *lastSkill = skill;

                ptr->buffNote["Summer Surf Uses"] += 1;
                if(ptr->getBuffNote("Summer Surf Uses")>=3){
                    ptr->setBuffNote("Summer Surf Uses",0);
                    genSkillPoint(ptr,1);
                }
            }));

            // every wave start -> +1 SP
            startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                genSkillPoint(ptr,1);
            }));
        };
    }
}
