#include "../include.h"

namespace RMC{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void Increase_Charge(CharUnit *ptr,double charge);
    void Memo_Skill(CharUnit *ptr);
    void Memo_Echance_Skill(CharUnit *ptr);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(103,160,160,E,ElementType::Ice,Path::Remembrance,"RMC",UnitType::Standard);
        ptr->SetAllyBaseStats(1048,543,631);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,688,68,130,0,ElementType::Ice,"Mem",UnitType::Standard);
        
        AllyUnit *RMCptr = ptr;
        AllyUnit *Memptr = ptr->getMemosprite();
        //substats
        

        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        
        ptr->Turn_func = [ptr,RMCptr,Memptr](){
            if(ptr->Atv_stats->turnCnt==1){
                Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
        };
        ptr->memospriteList[0]->Turn_func = [ptr,RMCptr,Memptr](){
        
            if(ptr->memospriteList[0]->Buff_check["Mem_Charge"]==1){
                Memo_Echance_Skill(ptr);
            }else{
                Memo_Skill(ptr);
            }
        };

        ptr->addUltCondition([ptr,RMCptr,Memptr]() -> bool {
            if (ptr->memospriteList[0]->Buff_note["Mem_Charge"] >= 60 && chooseSubUnitBuff(ptr->memospriteList[0].get())->Atv_stats->atv <= 20) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,RMCptr,Memptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getMemosprite(),TraceType::Aoe,"RMC Ult",
            [ptr,RMCptr,Memptr](shared_ptr<AllyAttackAction> &act){
                Increase_Charge(ptr, 40);
                buffSingle(Memptr,{{Stats::CR,AType::None,100.0}});
                if (ptr->Print) CharCmd::printUltStart("RMC");
                
                Attack(act);

                buffSingle(Memptr,{{Stats::CR,AType::None,-100.0}});
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 14;
            ptr->Stats_type[Stats::HP_P][AType::None] += 14;
            ptr->Stats_type[Stats::CD][AType::None] += 37.3;

            // relic

            // substats
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](AllyUnit *target, Stats StatsType) {
            if (target->Atv_stats->Name != "Mem") return;
            if (StatsType == Stats::CD) {
                double buffValue = (calculateCritdamForBuff(ptr->memospriteList[0].get(), 13.2) + 26.4);
                buffAllAlly({{Stats::CD, AType::TEMP, buffValue - ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"]}});
                buffAllAlly({{Stats::CD, AType::None, buffValue - ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"]}});
                ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"] = buffValue;
                return;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (ptr->Technique == 1) {
                for (int i = 1; i <= Total_enemy; i++) {
                    Action_forward(enemyUnit[i]->Atv_stats.get(), -50);
                }
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"RMC Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                });
                act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0)
                );
                act->addToActionBar();
                Deal_damage();
            }
            Action_forward(ptr->Atv_stats.get(), 30);
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            double buffValue = (calculateCritdamForBuff(ptr->memospriteList[0].get(), 13.2) + 26.4);
            buffAllAlly({{Stats::CD, AType::TEMP, buffValue - ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"]}});
            buffAllAlly({{Stats::CD, AType::None, buffValue - ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"]}});
            ptr->memospriteList[0]->Buff_note["Mem_Talent_Buff"] = buffValue;
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (isBuffEnd(chooseSubUnitBuff(RMCptr),"Mem_Support")) {
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",0);
                buffSingleChar(chooseCharacterBuff(RMCptr),{{Stats::CR,AType::None,-10}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->memospriteList[0]->Buff_check["RMC_E2"] = 1;
        }));
        AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [RMCptr,Memptr]
            (shared_ptr<AllyAttackAction> &act, Enemy *src, double damage) {
            CharUnit *ptr = act->Attacker->owner;
            AllyUnit *ally;
            if (ptr->getBuffCheck("Mem_Support")){
                    ally = ptr;
                    goto jump;
            }
            for(auto &each : ptr->memospriteList){
                if (each->getBuffCheck("Mem_Support")){
                    ally = each.get();
                    goto jump;
                }
            }
            return;
            jump:
            Cal_DamageNote(act,src,src,damage,ally->getBuffNote("Mem_Support"),"Mem True " + act->actionName);
        }));

        When_Energy_Increase_List.push_back(TriggerEnergy_Increase_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](CharUnit *target, double Energy) {
            if(Energy==0){
                Increase_Charge(ptr,3);
                return;
            }
            if (Energy + target->Current_energy > target->Max_energy) {
                Energy = target->Max_energy - target->Current_energy;
            }
            ptr->memospriteList[0]->Buff_note["Mem_Energy_cnt"] += Energy;
            Increase_Charge(ptr, floor(ptr->memospriteList[0]->Buff_note["Mem_Energy_cnt"] / 10));
            ptr->memospriteList[0]->Buff_note["Mem_Energy_cnt"] -= floor(ptr->memospriteList[0]->Buff_note["Mem_Energy_cnt"] / 10) * 10;
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Name != "Mem" && act->Attacker->Atv_stats->side == Side::Memosprite && ptr->memospriteList[0]->Buff_check["RMC_E2"] == 1) {
                Increase_energy(ptr, 8);
                ptr->memospriteList[0]->Buff_check["RMC_E2"] = 0;
            }
        }));



        

    }


    void Increase_Charge(CharUnit *ptr,double charge){
        if(ptr->memospriteList[0]->isDeath())return;
        ptr->memospriteList[0]->Buff_note["Mem_Charge"]+=charge;
        if(ptr->memospriteList[0]->Buff_note["Mem_Charge"]>=100){
            ptr->memospriteList[0]->Buff_note["Mem_Charge"]= 0;
            ptr->memospriteList[0]->Buff_check["Mem_Charge"]=1;
            Action_forward(ptr->memospriteList[0]->Atv_stats.get(),100);
        }
    }


    void Basic_Atk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"RMC BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"RMC Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            if(ptr->memospriteList[0]->isDeath()){
                ptr->memospriteList[0]->summon(100);
                ptr->memospriteList[0]->resetATV(130);
                Increase_Charge(ptr,90);
            }   
        });
        act->addActionType(AType::Summon);
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();

    }



    void Memo_Skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Bounce,"Mem Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,10);
            Increase_Charge(ptr,5);
            Attack(act);
        });
        act->addAttackType(AType::Summon);
        act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,39.6,5),4);
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10)
        );
        act->addToActionBar();
    }
    void Memo_Echance_Skill(CharUnit *ptr){

        ptr->memospriteList[0]->Buff_check["Mem_Charge"]=0;

        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Single,"Mem Buff",
        [ptr,RMCptr = ptr->memospriteList[0].get()](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,10);
            if(ptr->Print)CharCmd::printUltStart("Mem");
            if(isHaveToAddBuff(chooseCharacterBuff(RMCptr),"Mem_Support",3)){
                if(chooseCharacterBuff(ptr->memospriteList[0].get())->Max_energy == 0)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",36);
                else if (chooseCharacterBuff(RMCptr)->Max_energy >= 200)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",50);
                else 
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",30 + 2 * floor((chooseCharacterBuff(RMCptr)->Max_energy - 100) / 10));

                buffSingleChar(chooseCharacterBuff(RMCptr),{{Stats::CR,AType::None,10}});
            }
            Action_forward(chooseSubUnitBuff(ptr->memospriteList[0].get())->Atv_stats.get(),100);            
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->memospriteList[0].get()));
        act->addActionType(AType::Summon);
        act->addToActionBar();
    }  
}