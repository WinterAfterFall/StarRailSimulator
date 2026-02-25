#include "../include.h"

namespace Robin{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    
    //temp
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    bool Double_Turn(CharUnit *ptr);
    

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(102, 160, 160, E, ElementType::Physical, Path::Harmony, "Robin",UnitType::Standard);
        AllyUnit *Robinptr = ptr;
        ptr->SetAllyBaseStats(1280, 640, 485);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(120);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::ATK_P,Stats::ATK_P,Stats::ER);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *rb = ptr;

        ptr->Turn_func = [ptr,allyptr = ptr]() {
            if (!allyptr->getBuffCheck("Pinion'sAria")) {
            Skill(ptr);
            } else {
            Basic_Atk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if(driverType!=DriverType::DoubleTurn)return true;
            AllyUnit *target = chooseSubUnitBuff(ptr);  
            if((charUnit[Driver_num]->Atv_stats->atv<charUnit[Driver_num]->Atv_stats->Max_atv*0.2 || target->Atv_stats->atv == 0))return false;
            if((charUnit[Driver_num]->Atv_stats->atv < target->Atv_stats->atv))return false;
            return true;
        });

        ptr->addUltCondition([ptr,rb]() -> bool {
            if(driverType!=DriverType::AlwaysPull){
                CharUnit *ally =charUnit[ptr->currentCharNum].get();
                    if(ally->getATV()==0)return false;
                for(auto &each : ally->memospriteList){
                    if(each->getATV()==0)return false;
                }
                return true;
            }
            AllyUnit *dps = chooseSubUnitBuff(ptr);
            AllyUnit *driver = charUnit[Driver_num].get();
            if(driver->getATV()>dps->getATV())return false;
            return true;
        });

        ptr->addUltCondition([ptr]() -> bool {
            if(driverType!=DriverType::AlwaysPull)return true;
            AllyUnit *dps = chooseSubUnitBuff(ptr);
            AllyUnit *driver = charUnit[Driver_num].get();
            if(driver->getATV()<dps->getATV())return false;
            return true;
        });

        ptr->addUltCondition([ptr]() -> bool {
            if(!ptr->countdownList[0]->isDeath())return false;
            if(!ptr->getBuffCheck("Pinion'sAria"))return false;
            return true;
        });
        
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Robinptr](){

            if(ultUseCheck(ptr)){
                shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"RB Ult",
                [ptr,Robinptr](shared_ptr<AllyBuffAction> &act){
                    ptr->countdownList[0]->summon();
                    ptr->Atv_stats->baseSpeed = -1;
                    Update_Max_atv(ptr->Atv_stats.get());
                    resetTurn(ptr->Atv_stats.get());

                    ptr->Buff_note["Concerto_state"] = calculateAtkForBuff(ptr, 22.8) + 200;
                    buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, ptr->Buff_note["Concerto_state"]}});
                    buffAllAlly({{Stats::FLAT_ATK, AType::None, ptr->Buff_note["Concerto_state"]}});

                    buffAllAlly({{Stats::CD, AType::Fua, 25}});
                    if(ptr->Eidolon >= 1)buffAllAlly({{Stats::RESPEN, AType::None, 24}});
                    if(ptr->Eidolon >= 2)buffAllAllyExcludingBuffer(Robinptr,{{Stats::SPD_P,AType::None,16}});
                    
                    All_Action_forward(100);
                });
                act->addBuffAllAllies();
                act->addToActionBar();
                if(ptr->Print)CharCmd::printUltStart("Robin");
                Deal_damage();
            }
            return;
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Atv_stats->flatSpeed += 5;
            // relic
            // substats
            ptr->Atv_stats->baseSpeed = 102;
            return;
        }));

        Start_wave_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                Increase_energy(ptr, 5);
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            Action_forward(ptr->Atv_stats.get(), 25);
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({{Stats::CD, AType::None, 20}});
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Robinptr](){
            if(isBuffEnd(Robinptr,"Pinion'sAria")){
                buffAllAlly({{Stats::DMG, AType::None, -50}});
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr, 2);
            if(ptr->Eidolon >= 2){
                Increase_energy(ptr, 1);
            }
            if(!ptr->countdownList[0]->isDeath()){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::Addtional,ptr,TraceType::Single,"RB AddDmg");
                double x1 = 0, x2 = 0;

                ptr->Stats_type[Stats::CR][AType::None] += 100;
                x1 = ptr->Stats_type[Stats::CD][AType::None];
                x2 = enemyUnit[Main_Enemy_num]->Stats_type[Stats::CD][AType::None];
                ptr->Stats_type[Stats::CD][AType::None] = 150;
                enemyUnit[Main_Enemy_num]->Stats_type[Stats::CD][AType::None] = 0;

                newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,120));
                Attack(newAct);

                ptr->Stats_type[Stats::CR][AType::None] -= 100;
                ptr->Stats_type[Stats::CD][AType::None] = x1;
                enemyUnit[Main_Enemy_num]->Stats_type[Stats::CD][AType::None] = x2;
            }
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr](AllyUnit *target, Stats StatsType){
            if(target->Atv_stats->Name != "Robin")return;
            if(ptr->countdownList[0]->isDeath())return;
            if(StatsType == Stats::ATK_P || StatsType == Stats::FLAT_ATK){
                double buffValue = calculateAtkForBuff(ptr, 22.8) + 200;
                buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, buffValue - ptr->Buff_note["Concerto_state"]}});
                buffAllAlly({{Stats::FLAT_ATK, AType::None, buffValue - ptr->Buff_note["Concerto_state"]}});
                ptr->Buff_note["Concerto_state"] = buffValue;
            }
        }));


        // countdown
        SetCountdownStats(ptr,90, "Concerto_state");
        ptr->countdownList[0]->Turn_func = [ptr,Robinptr](){
            if( !ptr->countdownList[0]->isDeath()){
                ptr->countdownList[0]->death();
                ptr->Atv_stats->baseSpeed = 102;
                Update_Max_atv(ptr->Atv_stats.get());
                resetTurn(ptr->Atv_stats.get());
                buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, -ptr->Buff_note["Concerto_state"]}});
                buffAllAlly({{Stats::FLAT_ATK, AType::None, -ptr->Buff_note["Concerto_state"]}});
                buffAllAlly({{Stats::CD, AType::Fua, -25}});
                if(ptr->Eidolon >= 1)buffAllAlly({{Stats::RESPEN, AType::None, -24}});
                if(ptr->Eidolon >= 2)buffAllAllyExcludingBuffer(Robinptr,{{Stats::SPD_P,AType::None,-16}});
                }
                Action_forward(ptr->Atv_stats.get(),100);
                if(ptr->Print)CharCmd::printUltEnd("Robin");
            };
        
        
    }


    void Skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"RB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,35);
            buffAllAlly({{Stats::DMG,AType::None,50}});
            ptr->setBuffCheck("Pinion'sAria",true);
            extendBuffTime(ptr,"Pinion'sAria", 3);
        });
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();
    }

    void Basic_Atk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"RB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
}
