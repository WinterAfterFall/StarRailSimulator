#include "../include.h"
namespace Planar{
    void Arcadia(Ally *ptr){
        ptr->Planar.Name="Arcadia";

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            int cnt = 0;
            for(int i=1;i<=Total_ally;i++){
                for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                    if(each->isExsited())cnt++;
                }
            }
            double buff = 0;
            if(cnt<4){
                buff = (4 - cnt)* 12;
            }else if(cnt>4){
                buff = (cnt - 4)* 12;
            }

            ptr->buffAlly({{Stats::DMG,AType::None,buff - ptr->getSubUnit()->getBuffNote("Arcadia")}});
            ptr->getSubUnit()->setBuffNote("Arcadia",buff);
        }));
    }
}