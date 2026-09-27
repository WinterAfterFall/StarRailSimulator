#include "../include.h"

namespace SomeChar{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(speed,maxEnergy,ultCost,eidolon,ElementType::,Path::,name,UnitType::STANDARD);
        ptr->setAllyBaseStats(,,);

        //substats
        ptr->pushSubstats(Stats::);
        ptr->pushSubstats(Stats::);
        ptr->pushSubstats(Stats::);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire();
        ptr->setApplyBaseChance();
        ptr->setRelicMainStats(Stats::,Stats::,Stats::,Stats::);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::,ptr,TraceType::,,
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(,1);
                increaseEnergy(,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,ba,skill]() {

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {

        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::ICE][AType::NONE] += 22.4;
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;

            // relic

            // substats
        }));
    }
}
