#include "../include.h"

namespace Ruan_Mei{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);  
    void Skill_func(CharUnit *ptr);
    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(104, 130, 130, E, ElementType::Ice, Path::Harmony, "Ruan_Mei",UnitType::Standard);
        AllyUnit *RMptr = ptr;
        ptr->SetAllyBaseStats(1087, 660, 485);
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        
        
        ptr->Turn_func = [ptr,allyptr = ptr ]() {
            if (allyptr->Buff_check["Mei_Skill"] == 0) {
                Skill_func(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,RMptr](){
            if(!ultUseCheck(ptr)) return;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"RM Ult",
            [ptr,RMptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Ruan Mei");
                if(isHaveToAddBuff(RMptr,"RuanMei_Ult",2)){
                    buffAllAlly({{Stats::RESPEN, AType::None, 25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{Stats::DEF_SHRED, AType::None, 20}});
                }
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Stats_type[Stats::BE][AType::None] += 37.3;
            ptr->Stats_type[Stats::DEF_P][AType::None] += 22.5;
            ptr->Atv_stats->flatSpeed += 5;

            // relic

            // substats
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({
                {Stats::BE, AType::None, 20},
                {Stats::SPD_P,AType::None,10}
            });
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTION, [ptr](){
            if(ptr->Technique == 1){
            
                shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"RM SKill",
                [ptr](shared_ptr<AllyBuffAction> &act){
                    Increase_energy(ptr,30);
                    buffAllAlly({
                        {Stats::DMG,AType::None,68},
                        {Stats::BREAK_EFF,AType::None,50},
                    });
                    isHaveToAddBuff(ptr,"Mei_Skill",3);
                });
                act->addBuffSingleTarget(ptr);
                act->setTurnReset(false);
                act->addToActionBar();
                Deal_damage();
                return;
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMptr](){
            if(isBuffEnd(RMptr,"Mei_Skill")){
                buffAllAlly({
                    {Stats::DMG,AType::None,-68},
                    {Stats::BREAK_EFF,AType::None,-50},
                });
            }
            if(turn->Name == "Ruan_Mei"){
                Increase_energy(ptr, 5);
                if(isBuffEnd(RMptr,"RuanMei_Ult")){
                    buffAllAlly({{Stats::RESPEN, AType::None, -25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{Stats::DEF_SHRED, AType::None, -20}});
                    if(ptr->Print == 1)CharCmd::printUltEnd("Ruan Mei");
                }
            }
            if(turn->side == Side::Enemy && Turn_Skip == 0){
                if(enemyUnit[turn->num]->Debuff["RuanMei_Ult_bloom"] == 1){
                    Turn_Skip = 1;
                    debuffRemove(enemyUnit[turn->num].get(),"RuanMei_Ult_bloom");
                    Action_forward(enemyUnit[turn->num]->Atv_stats.get(), -10 - (0.2 * (ptr->Stats_type[Stats::BE][AType::None])));
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>(AType::Break,ptr,TraceType::Single,"RM Ult Break");
                    double temp = 0.5;
                    Cal_Break_damage(act, enemyUnit[turn->num].get(), temp);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,RMptr](shared_ptr<AllyAttackAction> &act){
            if(RMptr->getBuffCheck("RuanMei_Ult")){
                for(Enemy * &e : act->targetList){
                    debuffApply(ptr,e,"RuanMei_Ult_bloom");
                }
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *Breaker){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Break,ptr,TraceType::Single,"RM Talent Break");
            double temp;
            temp = 1.2;
            Cal_Break_damage(act, target, temp);
        }));
    
    }



    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"RM BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    void Skill_func(CharUnit *ptr){
        Skill_point(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"RM Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            buffAllAlly({
                {Stats::DMG,AType::None,68},
                {Stats::BREAK_EFF,AType::None,50},
            });
            isHaveToAddBuff(ptr,"Mei_Skill",3);
        });
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();
    }
}
