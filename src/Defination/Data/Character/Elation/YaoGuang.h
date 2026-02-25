#include "../include.h"

namespace YaoGuang{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,180,180,E,ElementType::Physical,Path::Elation,"Yao Guang",UnitType::Standard);
        ptr->SetAllyBaseStats(1242,465,654);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(200);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"YG BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                Skill_point(ptr,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,90,10),
                DmgSrc(DmgSrcType::ATK,30,5)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"YG BA",
            [ptr](shared_ptr<AllyBuffAction> &act){
                Skill_point(ptr,-1);
                Increase_energy(ptr,30);
                if(isHaveToAddBuff(ptr,"YG Skill",3)){
                    double buff = calculateElationForBuff(ptr,20);

                    buffAllAlly({
                        {Stats::Elation,AType::None,buff - ptr->getBuffNote("YG Skill")},
                        {Stats::Elation,AType::TEMP,buff - ptr->getBuffNote("YG Skill")}
                    });
                    
                    ptr->setBuffNote("YG Skill",buff);

                }
            });
            act->addToActionBar();
        };
        #pragma endregion
        ptr->Turn_func = [ptr,BA,Skill]() {

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Stats_type[Stats::Elation][AType::None] += 10;
            ptr->Atv_stats->flatSpeed += 9;

            // relic

            // substats
        }));
    }
}
