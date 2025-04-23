
#ifndef Anaxa_H
#define Anaxa_H

#define F first
#define S second
#include "../Library.h"

namespace Jade{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


//temp


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(97,140,140,E,"Wind","Erudition","Anaxa",TYPE_STD);
        ptr->SetAllyBaseStats(970,757,558);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(145);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (sp>Sp_Safety) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({240, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"] = 2;
                Attack(data_);
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Wind"][AT_NONE] += 22.4;
            // relic
            // substats
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy * enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(enemy->isDebuffEnd("Anaxa Weakness")){
                enemy->debuffRemoveStack("Anaxa Weakness");
                if(enemy->getDebuff(""))
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if(data_->actionName=="Anaxa BA"||data_->actionName=="Anaxa BA"){
                AdditionalSkill(ptr);
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
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            for(auto &e : data_->Target_Attack){
                if(e->calDebuffStack(data_->Attacker,"Anaxa Weakness",1,4).second >=2){
                    if(e->isHaveToAddDebuff("Qualitative Disclosure")){
                        e->debuffSingleApply(ST_DMG,AT_NONE,30);
                    }
                    Extend_Debuff_single_target(e,"Anaxa Weakness",3);
                }
            }
            Attack(data_);
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
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);

            Buff_single_target(data_->Attacker,ST_DMG,AT_NONE,20 * Total_enemy);
            int cnt = 5;
            while(1){
                for(auto &e : data_->Target_Attack){
                    if(e->calDebuffStack(data_->Attacker,"Anaxa Weakness",1,4).second >=2){
                        if(e->isHaveToAddDebuff("Qualitative Disclosure")){
                            e->debuffSingleApply(ST_DMG,AT_NONE,30);
                            Extend_Debuff_single_target(e,"Qualitative Disclosure",3);
                        }
                    }
                    --cnt;
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            Attack(data_);
            Buff_single_target(data_->Attacker,ST_DMG,AT_NONE,-20 * Total_enemy);
        };
        Action_bar.push(data_);
    }
    void AdditionalSkill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),TT_BOUNCE,"Anaxa AdditionalSkill");
        data_->Add_Target_FairBounce(5,{70,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);

            Buff_single_target(data_->Attacker,ST_DMG,AT_NONE,20 * Total_enemy);
            int cnt = 5;
            while(1){
                for(auto &e : data_->Target_Attack){
                    if(e->calDebuffStack(data_->Attacker,"Anaxa Weakness",1,4).second >=2){
                        if(e->isHaveToAddDebuff("Qualitative Disclosure")){
                            e->debuffSingleApply(ST_DMG,AT_NONE,30);
                            Extend_Debuff_single_target(e,"Qualitative Disclosure",3);
                        }
                    }
                    --cnt;
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            Attack(data_);
            Buff_single_target(data_->Attacker,ST_DMG,AT_NONE,-20 * Total_enemy);
        };
        Action_bar.push(data_);
        if(!actionBarUse)Deal_damage();
    }
    

}
#endif