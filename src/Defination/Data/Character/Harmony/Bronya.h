#include "../include.h"

namespace Bronya{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    

//temp
    void Skill(Ally *ptr);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99,120,120,E,ElementType::Wind,"Harmony","Bronya",TYPE_STD);
        SubUnit *Bronyaptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1242,582,534);
        //substats
        ptr->pushSubstats(ST_CD);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CD,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);
        ptr->setSpeedRequire(134);

        Driver_num = Bronyaptr->Atv_stats->num;

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){            
            Skill(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Bronyaptr](){
            if(!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Bronya Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                //Ult ATKBUFF
                buffAllAlly({{ST_ATK_P,AT_NONE,55}},"Bronya_Ult",2);

                //Ult CritBuff
                double temp = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(),16)+20;
                for(auto &e : act->buffTargetList){
                    e->buffSingle({{ST_CD,AT_NONE,temp - e->Buff_note["Bronya_Ult"]}});
                    e->buffSingle({{ST_CD,AT_TEMP,temp - e->Buff_note["Bronya_Ult"]}});
                    e->Buff_note["Bronya_Ult"] = temp;
                }

                //ดักในกรณีที่บัพในเทิร์นตัวละครอื่น
                if(Situation == "Before Turn" && (turn->Side == "Memosprite" || turn->Side == "Ally")){
                    SubUnit *temp = dynamic_cast<SubUnit*>(turn->ptrToChar);
                    temp->extendBuffTime("Bronya_Ult",1);
                }
                if(ptr->Print)CharCmd::printUltStart("Bronya");
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 24;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Wind][AT_NONE] += 22.4;
            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR]["Basic_Attack"] = 100;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            if(ptr->Technique == 1)buffAllAlly({{"Atk%",AT_NONE,15}},"Bronya_Technique",2);
            buffAllAlly({{"Def%",AT_NONE,20}},"Bronya_A4",2);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            SubUnit *tempstats = dynamic_cast<SubUnit*>(turn->ptrToChar);
            if(!tempstats) return;
            
            //BuffEND Skill
            if(tempstats->isBuffEnd("Bronya_Skill")){
                tempstats->buffSingle({{ST_DMG,AT_NONE,-66}});
            }

            //E1 Cooldon reset
            if(Bronyaptr->isBuffEnd("Bronya_Skill_E1")){
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"] = 0;
            }
             //E2 buffend
            if(tempstats->isBuffEnd("Bronya_Skill_E2")){
                tempstats->buffSingle({{ST_SPD,ST_SPD_P,-30}});
            }
            if(tempstats->isBuffEnd("Bronya_Ult")){
                tempstats->buffSingle({{"Atk%",AT_NONE,-55}});
                tempstats->buffSingle({{ST_CD,AT_TEMP,-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->buffSingle({{ST_CD,AT_NONE,-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->Buff_note["Bronya_Ult"] = 0;
            }
            if(tempstats->isBuffEnd("Bronya_A4")){
                tempstats->buffSingle({{ST_DEF_P,AT_NONE,-20}});
            }
            if(tempstats->isBuffEnd("Bronya_Technique")){
                tempstats->buffSingle({{"Atk%",AT_NONE,-15}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(turn->Char_Name == "Bronya"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 0;
            }
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->num != Driver_num) return;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({{ST_DMG,AT_NONE,10}});
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act){
            if(act->isSameAttack("Bronya",AT_BA)){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),30);
            }
            if(ptr->Eidolon >= 4 && act->isSameAttack(AT_BA)&&!act->isSameUnitName("Bronya")&& ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] == 0){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(ActionType::Fua,ptr->getSubUnit(),TT_SINGLE,"Bronya E4",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    Increase_energy(ptr,5);
                    Attack(act);
                });
                newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,80,10));
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 1;
                newAct->addToActionBar();
            }
        }));



        
    }


    
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_SINGLE,"Bronya Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);

            //Buff นานแค่ไหน
            if(ptr->Eidolon>=6)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,66}},"Bronya_Skill",2);
            else
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_DMG,AT_NONE,66}},"Bronya_Skill",1);

            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),100);

            //E2 buff Speed
            if(ptr->Eidolon>=2)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,30}},"Bronya_Skill_E2",1  );
            
            //E1 คืน Sp
            if(ptr->Eidolon>=1){
                if(ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]==1&&ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Bronya_Skill_E1",1)){
                    Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                    
                }
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]++;
            }
        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
}