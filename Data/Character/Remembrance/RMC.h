
#ifndef RMC_H
#define RMC_H

#define F first
#define S second
#include "../Library.h"

namespace RMC{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Increase_Charge(Ally *ptr,double charge);
    void Memo_Skill(Ally *ptr);
    void Memo_Echance_Skill(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,160,160,E,"Ice","Remembrance","RMC",TYPE_STD);
        ptr->SetAllyBaseStats(1048,543,631);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,68,0,"Ice","Mem",TYPE_STD);
        
        SubUnit *RMCptr = ptr->getSubUnit();
        SubUnit *Memptr = ptr->getSubUnit(1);
        //substats
        

        ptr->pushSubstats(ST_CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(ST_CD,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);


        //func
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,RMCptr,Memptr](){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt==1){
                Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
        };
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,RMCptr,Memptr](){
        
            if(ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]==1){
                Memo_Echance_Skill(ptr);
            }else{
                Memo_Skill(ptr);
            }
        };

        ptr->addUltCondition([ptr,RMCptr,Memptr]() -> bool {
            if (ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"] >= 60 && chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats->atv <= 20) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,RMCptr,Memptr]() {
            if (!ultUseCheck(ptr)) return;

            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(1),TT_AOE,"RMC Ult",
            [ptr,RMCptr,Memptr](shared_ptr<AllyAttackAction> &data_){
                Increase_Charge(ptr, 40);
                Memptr->buffSingle({{ST_CR,AT_NONE,100.0}});
                if (ptr->Print) CharCmd::printUltStart("RMC");
                
                Attack(data_);

                Memptr->buffSingle({{ST_CR,AT_NONE,-100.0}});
            });
            data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20)
            );
            data_->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 37.3;

            // relic

            // substats
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Mem") return;
            if (StatsType == ST_CD) {
                double buffValue = (calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4);
                buffAllAlly({{ST_CD, AT_TEMP, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
                buffAllAlly({{ST_CD, AT_NONE, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
                ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = buffValue;
                return;
            }
        }));


        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"][AT_NONE] += 688;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (ptr->Technique == 1) {
                for (int i = 1; i <= Total_enemy; i++) {
                    Action_forward(Enemy_unit[i]->Atv_stats.get(), -50);
                }
                shared_ptr<AllyAttackAction> data_ = 
                make_shared<AllyAttackAction>(ActionType::Technique,ptr->getSubUnit(),TT_AOE,"RMC Tech",
                [ptr](shared_ptr<AllyAttackAction> &data_){
                    Attack(data_);
                });
                data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0)
                );
                data_->addToActionBar();
                Deal_damage();
            }
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 30);
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            double buffValue = (calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4);
            buffAllAlly({{ST_CD, AT_TEMP, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
            buffAllAlly({{ST_CD, AT_NONE, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = buffValue;
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (chooseSubUnitBuff(RMCptr)->isBuffEnd("Mem_Support")) {
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",0);
                chooseCharacterBuff(RMCptr)->buffAlly({{ST_CR,AT_NONE,-10}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 1;
        }));
        AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]
            (shared_ptr<AllyAttackAction> &data_, Enemy *src, double damage) {
            Ally *ptr = data_->Attacker->ptrToChar;
            SubUnit *subUnit ;
            for(auto &each : ptr->Sub_Unit_ptr){
                if (each->getBuffCheck("Mem_Support")){
                    subUnit = each.get();
                    goto jump;
                }
            }
            return;
            jump:
            Cal_DamageNote(data_,src,src,damage,subUnit->getBuffNote("Mem_Support"),"Mem True " + data_->actionName);
        }));

        When_Energy_Increase_List.push_back(TriggerEnergy_Increase_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](Ally *target, double Energy) {
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed == -1) return;
            if(Energy==0){
                Increase_Charge(ptr,3);
                return;
            }
            if (Energy + target->Current_energy > target->Max_energy) {
                Energy = target->Max_energy - target->Current_energy;
            }
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] += Energy;
            Increase_Charge(ptr, floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10));
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] -= floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10) * 10;
        }));

        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](shared_ptr<AllyAttackAction> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name != "Mem" && data_->Attacker->Atv_stats->Side == "Memosprite" && ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] == 1) {
                Increase_energy(ptr, 8);
                ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 0;
            }
        }));



        

    }


    void Increase_Charge(Ally *ptr,double charge){
        if(ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed==-1)return;
        ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]+=charge;
        if(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]>=100){
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]= 0;
            ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=1;
            Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        }
    }


    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"RMC BA",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        });
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        data_->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> data_ = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,TT_AOE,
        [ptr](shared_ptr<AllyBuffAction> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
                ptr->Sub_Unit_ptr[1]->resetATV(130);
                Increase_Charge(ptr,90);
            }   
        });
        data_->addActionType(ActionType::Summon);
        data_->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
        data_->addToActionBar();

    }



    void Memo_Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_BOUNCE,"Mem Skill",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(ptr,10);
            Increase_Charge(ptr,5);
            Attack(data_);
        });
        data_->addActionType(ActionType::Summon);
        data_->addEnemyBounce(DmgSrc(DmgSrcType::ATK,39.6,5),4);
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10)
        );
        data_->addToActionBar();
    }
    void Memo_Echance_Skill(Ally *ptr){

        ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=0;

        shared_ptr<AllyBuffAction> data_ = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_SINGLE,"Mem Buff",
        [ptr,RMCptr = ptr->Sub_Unit_ptr[1].get()](shared_ptr<AllyBuffAction> &data_){
            Increase_energy(ptr,10);
            if(ptr->Print)CharCmd::printUltStart("Mem");
            if(chooseSubUnitBuff(RMCptr)->isHaveToAddBuff("Mem_Support",3)){
                if(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy == 0)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",36);
                else if (chooseCharacterBuff(RMCptr)->Max_energy >= 200)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",50);
                else 
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",30 + 2 * floor((chooseCharacterBuff(RMCptr)->Max_energy - 100) / 10));

                chooseCharacterBuff(RMCptr)->buffAlly({{ST_CR,AT_NONE,10}});
            }
            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats.get(),100);            
        });
        data_->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()));
        data_->addActionType(ActionType::Summon);
        data_->addToActionBar();
    }  
}
#endif