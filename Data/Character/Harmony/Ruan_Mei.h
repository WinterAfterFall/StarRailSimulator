
#ifndef RuanMei_H
#define RuanMei_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Ruan_Mei{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);
    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(104, 130, 130, E, "Ice", "Harmony", "Ruan_Mei",TYPE_STD);
        SubUnit *RMptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1087, 660, 485);
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(ST_BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(ST_ATK_P,ST_FLAT_SPD,ST_ATK_P,ST_EnergyRecharge);

        
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,allyptr = ptr->Sub_Unit_ptr[0].get() ]() {
            if (allyptr->Buff_check["Mei_Skill"] == 0) {
                Skill_func(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,RMptr](){
            if(!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"RM Ult",
            [ptr,RMptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Ruan Mei");
                if(RMptr->isHaveToAddBuff("RuanMei_Ult,2")){
                    buffAllAlly({{"Respen", AT_NONE, 25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{ST_DEF_SHRED, AT_NONE, 20}});
                }
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 22.5;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;

            // relic

            // substats
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({
                {ST_BE, AT_NONE, 20},
                {ST_SPD,ST_SPD_P,10}
            });
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTION, [ptr](){
            if(ptr->Technique == 1){
            
                shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"RM SKill",
                [ptr](shared_ptr<AllyBuffAction> &act){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
                    Increase_energy(ptr,30);
                    buffAllAlly({
                        {ST_DMG,AT_NONE,68},
                        {ST_BREAK_EFF,AT_NONE,50},
                    });
                    ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Mei_Skill",3);
                });
                act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
                act->setTurnReset(false);
                act->addToActionBar();
                Deal_damage();
                return;
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMptr](){
            if(RMptr->isBuffEnd("Mei_Skill")){
                buffAllAlly({
                    {ST_DMG,AT_NONE,-68},
                    {ST_BREAK_EFF,AT_NONE,-50},
                });
            }
            if(turn->Char_Name == "Ruan_Mei"){
                Increase_energy(ptr, 5);
                if(RMptr->isBuffEnd("RuanMei_Ult")){
                    buffAllAlly({{"Respen", AT_NONE, 25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{ST_DEF_SHRED, AT_NONE, 20}});
                    if(ptr->Print == 1)CharCmd::printUltEnd("Ruan Mei");
                }
            }
            if(turn->Side == "Enemy" && Turn_Skip == 0){
                if(Enemy_unit[turn->num]->Debuff["RuanMei_Ult_bloom"] == 1){
                    Turn_Skip = 1;
                    Enemy_unit[turn->num]->debuffRemove("RuanMei_Ult_bloom");
                    Action_forward(Enemy_unit[turn->num]->Atv_stats.get(), -10 - (0.2 * (ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE])));
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>(ActionType::Break,ptr->getSubUnit(),TT_SINGLE,"RM Ult Break");
                    double temp = 0.5;
                    Cal_Break_damage(act, Enemy_unit[turn->num].get(), temp);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
        }));

        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,RMptr](shared_ptr<AllyAttackAction> &act){
            if(RMptr->getBuffCheck("RuanMei_Ult")){
                for(Enemy * &e : act->targetList){
                    e->debuffApply(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult_bloom");
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Breaker){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Break,ptr->getSubUnit(),TT_SINGLE,"RM Talent Break");
            double temp;
            temp = 1.2;
            Cal_Break_damage(act, target, temp);
        }));
    
    }



    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"RM BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    void Skill_func(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"RM Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Increase_energy(ptr,30);
            buffAllAlly({
                {ST_DMG,AT_NONE,68},
                {ST_BREAK_EFF,AT_NONE,50},
            });
            ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Mei_Skill",3);
        });
        act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
        act->addToActionBar();
    }



    
    

}
#endif
