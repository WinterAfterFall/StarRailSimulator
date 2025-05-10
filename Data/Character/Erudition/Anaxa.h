
#ifndef Anaxa_H
#define Anaxa_H

#define F first
#define S second
#include "../Library.h"

namespace  Anaxa{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void AdditionalSkill(Ally *ptr);
    void AnaxaDebuff(Ally *ptr, Enemy *enemy);


//temp


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(97,140,140,E,"Wind","Erudition","Anaxa",TYPE_STD);
        ptr->SetAllyBaseStats(970,757,558);
        SubUnit *Anaxaptr = ptr->getSubUnit();


        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(15);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_ATK_P,ST_ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (sp>Sp_Safety||turn->turn_cnt==1) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };
        // ptr->addUltCondition([ptr,Anaxaptr]() -> bool {
        //     SubUnit *Driverptr = Ally_unit[Driver_num]->Sub_Unit_ptr[0].get();
        //     if(Anaxaptr->Atv_stats->atv - Anaxaptr->Atv_stats->Max_atv*0.25 > Driverptr->Atv_stats->atv&&Anaxaptr->Atv_stats->atv!=0)
        //     return false;
        //     return true;
        // });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,Anaxaptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(Anaxaptr,TT_AOE,"Anaxa Ult");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({160,0,0,20});
            data_->Damage_spilt.Adjacent.push_back({160,0,0,20});
            data_->Damage_spilt.Other.push_back({160,0,0,20});

            data_->actionFunction = [ptr,Anaxaptr](shared_ptr<AllyActionData> &data_) {
                if(ptr->Print)CharCmd::printUltStart("Anaxa");
                for(auto &each : data_->Target_Attack){
                    each->debuffApply(Anaxaptr,"Sublimation",1);
                    each->weaknessApply(ET_FIRE,1);
                    each->weaknessApply(ET_ICE,1);
                    each->weaknessApply(ET_LN,1);
                    each->weaknessApply(ET_WIND,1);
                    each->weaknessApply(ET_QT,1);
                    each->weaknessApply(ET_IMG,1);
                    each->weaknessApply(ET_PHY,1);
                }
                for(auto &each : data_->Target_Attack){
                    each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                    each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                    if(each->currentWeaknessElementAmount>=5){
                        each->DebuffNote["AnaxaDmgBonus"] = 30;
                        each->debuffSingle({{ST_DMG,AT_NONE,30}});
                    }
                }
    
                Attack(data_);
    
                for(auto &each : data_->Target_Attack){
                    each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                    each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                    each->DebuffNote["AnaxaDmgBonus"] = 0;
                    each->DebuffNote["AnaxaA6"] = 0;
                }
            };
            Action_bar.push(data_);
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Wind"][AT_NONE] += 22.4;

            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 30;

            // relic
            // substats
            if(!ptr->Adjust["AnaxaA4"]){
                int cnt = 0;
                for(int i=1; i<=Total_ally;i++){
                    if(Ally_unit[i]->Path[0]=="Erudition")
                    cnt++;
                    
                }
                if(cnt>=2)ptr->Adjust["AnaxaA4"] = 2;
                else ptr->Adjust["AnaxaA4"] = 1;
            }
            if(ptr->Eidolon>=6){
                buffAllAlly({{ST_DMG,AT_NONE,50}});
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 140;
                
            }else if(ptr->Adjust["AnaxaA4"]==2){
                buffAllAlly({{ST_DMG,AT_NONE,50}});
            }else if(ptr->Adjust["AnaxaA4"]==1){
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 140;
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            ptr->getSubUnit()->buffStackSingle({{ST_DEF_SHRED,AT_NONE,4}},3,7,"Qualitative Shift");
            for(int i=1; i<= Total_enemy ;i++){
                AnaxaDebuff(ptr,Enemy_unit[i].get());
                if(ptr->Eidolon>=2){
                    AnaxaDebuff(ptr,Enemy_unit[i].get());
                    Enemy_unit[i]->debuffSingleMark({{ST_RESPEN,AT_NONE,20}},ptr->getSubUnit(),"AnaxaE2");
                }
                
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
            enemy->isDebuffEnd("Sublimation");
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            SubUnit *ally = turn->canCastToSubUnit();
            if(enemy){
                for(auto &e : Enemy_weak){
                    enemy->isDebuffEnd("AnaxaTalent" + e.first);
                }
                if(enemy->isDebuffEnd("AnaxaE1")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AT_NONE,-16}});
                }
            }
            if(ally){
                if(ally->isBuffEnd("AnaxaE4")){
                    ally->buffResetStack({{ST_ATK_P,AT_NONE,30}},"AnaxaE4");
                }
            }
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyActionData> &data_) {
            if(data_->Attacker->isSameUnitName("Anaxa")){
                if(ptr->Eidolon>=6){
                    for(auto &each : data_->Damage_spilt.Main){
                        each.Atk_ratio*=1.3;
                        each.Hp_ratio*=1.3;
                        each.Def_ratio*=1.3;
                    }
                    for(auto &each : data_->Damage_spilt.Adjacent){
                        each.Atk_ratio*=1.3;
                        each.Hp_ratio*=1.3;
                        each.Def_ratio*=1.3;
                    }
                    for(auto &each : data_->Damage_spilt.Other){
                        each.Atk_ratio*=1.3;
                        each.Hp_ratio*=1.3;
                        each.Def_ratio*=1.3;
                    }
                }
            }

        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,Anaxaptr](shared_ptr<AllyActionData> &data_) {
            if((data_->actionName=="Anaxa BA"||data_->actionName=="Anaxa Skill")){
                for(auto &each : data_->Target_Attack){
                    if(each->currentWeaknessElementAmount>=5){
                        AdditionalSkill(ptr);
                        break;
                    }
                }
            }
        }));
    }




    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),TT_SINGLE,"Anaxa BA");
        data_->Add_Target_Adjacent();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            for(auto &each : data_->Target_Attack){
                AnaxaDebuff(ptr,each);
            }

            for(auto &each : data_->Target_Attack){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(data_);

            for(auto &each : data_->Target_Attack){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),TT_BOUNCE,"Anaxa Skill");
        data_->Add_Target_FairBounce(5,{70,0,0,10});
        data_->Turn_reset=true;     
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->getSubUnit()->Atv_stats->turn_cnt==1){
                Increase_energy(ptr,30);
                if(ptr->Eidolon>=1){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                }
            }

            data_->Attacker->buffSingle({{ST_DMG,AT_NONE,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)data_->Attacker->buffStackSingle({{ST_ATK_P,AT_NONE,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : data_->Target_Attack){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : data_->Target_Attack){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(data_);

            for(auto &each : data_->Target_Attack){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            data_->Attacker->buffSingle({{ST_DMG,AT_NONE,-20.0 * Total_enemy}});

        };
        Action_bar.push(data_);
    }
    void AdditionalSkill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),TT_BOUNCE,"Anaxa AdditionalSkill");
        data_->Add_Target_FairBounce(5,{70,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);

            data_->Attacker->buffSingle({{ST_DMG,AT_NONE,20.0 * Total_enemy}});
            if(ptr->Eidolon>=4)data_->Attacker->buffStackSingle({{ST_ATK_P,AT_NONE,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            //เติม Debuff
            while(1){
                for(auto &each : data_->Target_Attack){
                    AnaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->Eidolon>=1)each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,16}},ptr->getSubUnit(),"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }

            for(auto &each : data_->Target_Attack){
                each->DebuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE,each->DebuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->DebuffNote["AnaxaDmgBonus"] = 30;
                    each->debuffSingle({{ST_DMG,AT_NONE,30}});
                }
            }

            Attack(data_);

            for(auto &each : data_->Target_Attack){
                each->debuffSingle({{ST_DEF_SHRED,AT_NONE, -each->DebuffNote["AnaxaA6"]}});
                each->debuffSingle({{ST_DMG,AT_NONE, -each->DebuffNote["AnaxaDmgBonus"]}});
                each->DebuffNote["AnaxaDmgBonus"] = 0;
                each->DebuffNote["AnaxaA6"] = 0;
            }
            data_->Attacker->buffSingle({{ST_DMG,AT_NONE,-20.0 * Total_enemy}});
        };
        Action_bar.push(data_);
        Deal_damage();
    }
    void AnaxaDebuff(Ally *ptr, Enemy *enemy) {
        string element;
        element = enemy->weaknessApplyChoose(3);
        enemy->debuffApply(ptr->getSubUnit(),"AnaxaTalent" + element,3);
    }
    

}
#endif