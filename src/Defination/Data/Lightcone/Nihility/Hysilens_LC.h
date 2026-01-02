#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Hysilens_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Hysilens_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 35 + 5 * superimpose;
            }));

            WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                buffAllAlly({{Stats::SPD_P,AType::None,7.5 + 2.5*superimpose}});
            }));

            BeforeApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                // if(ptr->getBuffCheck("LC Hys using"))return;
                ptr->setBuffCheck("LC Hys using",1);
                if(Trigger->isSameStatsOwnerName(ptr)){
                    target->setDebuffNote("Hys LC TotalDebuff",target->Total_debuff);
                }
                // ptr->setBuffCheck("LC Hys using",0);
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                // if(ptr->getBuffCheck("LC Hys using"))return;
                ptr->setBuffCheck("LC Hys using",1);
                if(Trigger->isSameStatsOwnerName(ptr)){
                    if(target->Total_debuff-target->getDebuffNote("Hys LC TotalDebuff")==0)return;
                    // cout<<target->Total_debuff<<" "<<target->getDebuffNote("Hys LC TotalDebuff")<<endl;
                    // cout<<Trigger->getUnitName()<<" "<<target->getUnitName()<<endl;
                    target->debuffStackSingle({{Stats::VUL,AType::Dot,3.75 + 1.25 * superimpose}},ptr,target->Total_debuff-
                    target->getDebuffNote("Hys LC TotalDebuff"),6,"Hys LC");
                }
                // ptr->setBuffCheck("LC Hys using",0);
            }));
    
        };
    }
}