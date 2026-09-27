#include "../include.h"
namespace Planar{
    void Arcadia(CharUnit *ptr){
        ptr->Planar.name="Arcadia";

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            int cnt = 0;
            for(auto &each : allyList){
                if(each->isExisted())cnt++;
            }
            double buff = 0;
            if(cnt<4){
                buff = (4 - cnt)* 12;
            }else if(cnt>4){
                buff = (cnt - 4)* 9;
            }

            buffSingleChar(ptr,{{Stats::DMG,AType::NONE,buff - ptr->getBuffNote("Arcadia")}});
            ptr->setBuffNote("Arcadia",buff);
        }));
    }
}