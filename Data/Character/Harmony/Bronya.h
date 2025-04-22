
#ifndef Bronya_H
#define Bronya_H

#define F first
#define S second
#include "../Library.h"

namespace Bronya{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    



//temp
    void Skill(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99,120,120,E,"Wind","Harmony","Bronya",TYPE_STD);
        SubUnit *Bronyaptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1242,582,534);
        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CRIT_DAM,ST_FLAT_SPD,ST_DMG_PERCENT,ST_EnergyRecharge);
        ptr->setSpeedRequire(133.4);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){            
            Skill(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Bronyaptr](){
            if(!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff","Bronya Ult");
            data_->Add_Buff_All_Ally();
            data_->actionFunction = [ptr,Bronyaptr](shared_ptr<AllyActionData> &data_){
                //Ult ATKBUFF
                buffAllAlly({{ST_ATK_PERCENT,AT_NONE,55}},"Bronya_Ult",2);

                //Ult CritBuff
                double temp = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(),16)+20;
                for(auto e : data_->Target_Buff){
                    e->buffSingle({{ST_CRIT_DAM,AT_NONE,temp - e->Buff_note["Bronya_Ult"]}});
                    e->buffSingle({{ST_CRIT_DAM,AT_TEMP,temp - e->Buff_note["Bronya_Ult"]}});
                }

                //ดักในกรณีที่บัพในเทิร์นตัวละครอื่น
                if(Ult_After_Turn == 0 && (turn->Side == "Memosprite" || turn->Side == "Ally")){
                    SubUnit *temp = dynamic_cast<SubUnit*>(turn->ptr_to_unit);
                    temp->extendBuffTime("Bronya_Ult",1);
                }
                if(ptr->Print)CharCmd::printUltStart("Bronya");
            };
            
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 24;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES]["None"] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Wind"]["None"] += 22.4;
            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Basic_Attack"] = 100;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            if(ptr->Technique == 1)buffAllAlly({{"Atk%","None",15}},"Bronya_Technique",2);
            buffAllAlly({{"Def%","None",20}},"Bronya_A4",2);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            SubUnit *tempstats = dynamic_cast<SubUnit*>(turn->ptr_to_unit);
            if(!tempstats) return;
            
            //BuffEND Skill
            if(tempstats->isBuffEnd("Bronya_Skill")){
                tempstats->buffSingle({{"Dmg%","None",-66}});
            }

            //E1 Cooldon reset
            if(Bronyaptr->isBuffEnd("Bronya_Skill_E1")){
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"] = 0;
            }
             //E2 buffend
            if(tempstats->isBuffEnd("Bronya_Skill_E2")){
                tempstats->buffSingle({{ST_SPD,ST_SPD_PERCENT,-30}});
            }
            if(tempstats->isBuffEnd("Bronya_Ult")){
                tempstats->buffSingle({{"Atk%","None",-55}});
                tempstats->buffSingle({{"Crit_dam",AT_TEMP,-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->buffSingle({{"Crit_dam","None",-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->Buff_note["Bronya_Ult"] = 0;
            }
            if(tempstats->isBuffEnd("Bronya_A4")){
                tempstats->buffSingle({{ST_DEF_PERCENT,"None",-20}});
            }
            if(tempstats->isBuffEnd("Bronya_Technique")){
                tempstats->buffSingle({{"Atk%","None",-15}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(turn->Char_Name == "Bronya"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 0;
            }
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num != Driver_num) return;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({{"Dmg%","None",10}});
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_){
            if(data_->Action_type.second == "Basic_Attack" && data_->Attacker->Atv_stats->Char_Name == "Bronya"){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),30);
            }
            if(ptr->Eidolon >= 4 && data_->Action_type.second == "Basic_Attack" && data_->Attacker->Atv_stats->Char_Name != "Bronya" && ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] == 0){
                shared_ptr<AllyActionData> data_temp = make_shared<AllyActionData>();
                data_temp->Fua_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Bronya E4");
                data_temp->Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
                data_temp->Damage_spilt.Main.push_back({80,0,0,10});
                Increase_energy(ptr,5);
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 1;
                data_temp->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                    Increase_energy(ptr,5);
                    Attack(data_);
                };
                
                Action_bar.push(data_temp);
            }
        }));



        
    }


    
    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Bronya Skill");
        data_->Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);

            //Buff นานแค่ไหน
            if(ptr->Eidolon>=6)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{"Dmg%","None",66}},"Bronya_Skill",2);
            else
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{"Dmg%","None",66}},"Bronya_Skill",1);

            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),100);

            //E2 buff Speed
            if(ptr->Eidolon>=2)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_PERCENT,30}},"Bronya_Skill_E2",1  );
            
            //E1 คืน Sp
            if(ptr->Eidolon>=1){
                if(ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]==1&&ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Bronya_Skill_E1",1)){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                    
                }
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]++;
            }
        };
        Action_bar.push(data_);
    }




}
#endif