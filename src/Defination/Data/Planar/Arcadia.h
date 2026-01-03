#include "../include.h"
namespace Planar{
    void Arcadia(CharUnit *ptr){
        ptr->Planar.Name="Arcadia";

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            int cnt = 0;
            for(auto &each : allyList){
                if(each->isExsited())cnt++;
            }
            double buff = 0;
            if(cnt<4){
                buff = (4 - cnt)* 12;
            }else if(cnt>4){
                buff = (cnt - 4)* 12;
            }

            buffSingleChar(ptr,{{Stats::DMG,AType::None,buff - ptr->getBuffNote("Arcadia")}});
            ptr->setBuffNote("Arcadia",buff);
        }));
    }
}