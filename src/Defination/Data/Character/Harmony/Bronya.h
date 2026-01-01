#include "../include.h"

namespace Bronya{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    

//temp
    void Skill(CharUnit *ptr);

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(99,120,120,E,ElementType::Wind,Path::Harmony,"Bronya",UnitType::Standard);
        AllyUnit *Bronyaptr = ptr;
        ptr->SetAllyBaseStats(1242,582,534);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ER);
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
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"Bronya Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                //Ult ATKBUFF
                buffAllAlly({{Stats::ATK_P,AType::None,55}},"Bronya_Ult",2);

                //Ult CritBuff
                double temp = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(),16)+20;
                for(auto &e : act->buffTargetList){
                    e->buffSingle({{Stats::CD,AType::None,temp - e->Buff_note["Bronya_Ult"]}});
                    e->buffSingle({{Stats::CD,AType::TEMP,temp - e->Buff_note["Bronya_Ult"]}});
                    e->Buff_note["Bronya_Ult"] = temp;
                }

                //ดักในกรณีที่บัพในเทิร์นตัวละครอื่น
                if(phaseStatus == PhaseStatus::BeforeTurn && (turn->side == Side::AllyUnit || turn->side == Side::Ally)){
                    AllyUnit *temp = dynamic_cast<AllyUnit*>(turn->charptr);
                    temp->extendBuffTime("Bronya_Ult",1);
                }
                if(ptr->Print)CharCmd::printUltStart("Bronya");
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 24;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 22.4;
            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::BA] = 100;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            if(ptr->Technique == 1)buffAllAlly({{Stats::ATK_P,AType::None,15}},"Bronya_Technique",2);
            buffAllAlly({{Stats::DEF_P,AType::None,20}},"Bronya_A4",2);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Bronyaptr](){
            AllyUnit *tempstats = dynamic_cast<AllyUnit*>(turn->charptr);
            if(!tempstats) return;
            
            //BuffEND Skill
            if(tempstats->isBuffEnd("Bronya_Skill")){
                tempstats->buffSingle({{Stats::DMG,AType::None,-66}});
            }

            //E1 Cooldon reset
            if(Bronyaptr->isBuffEnd("Bronya_Skill_E1")){
                ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"] = 0;
            }
             //E2 buffend
            if(tempstats->isBuffEnd("Bronya_Skill_E2")){
                tempstats->buffSingle({{Stats::SPD_P,AType::None,-30}});
            }
            if(tempstats->isBuffEnd("Bronya_Ult")){
                tempstats->buffSingle({{Stats::ATK_P,AType::None,-55}});
                tempstats->buffSingle({{Stats::CD,AType::TEMP,-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->buffSingle({{Stats::CD,AType::None,-tempstats->Buff_note["Bronya_Ult"]}});
                tempstats->Buff_note["Bronya_Ult"] = 0;
            }
            if(tempstats->isBuffEnd("Bronya_A4")){
                tempstats->buffSingle({{Stats::DEF_P,AType::None,-20}});
            }
            if(tempstats->isBuffEnd("Bronya_Technique")){
                tempstats->buffSingle({{Stats::ATK_P,AType::None,-15}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(turn->UnitName == "Bronya"){
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] = 0;
            }
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->num != Driver_num) return;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            buffAllAlly({{Stats::DMG,AType::None,10}});
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act){
            if(act->isSameAttack("Bronya",AType::BA)){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),30);
            }
            if(ptr->Eidolon >= 4 && act->isSameAttack(AType::BA)&&!act->isSameUnitName("Bronya")&& ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] == 0){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::Fua,ptr,TraceType::Single,"Bronya E4",
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


    
    void Skill(CharUnit *ptr){

        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        //E1 คืน Sp
        if(ptr->Eidolon>=1){
            if(ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]==1&&ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Bronya_Skill_E1",1)){
                Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                
            }
            ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]++;
        }
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Single,"Bronya Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);

            //Buff นานแค่ไหน
            if(ptr->Eidolon>=6)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::DMG,AType::None,66}},"Bronya_Skill",2);
            else
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::DMG,AType::None,66}},"Bronya_Skill",1);

            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),100);

            //E2 buff Speed
            if(ptr->Eidolon>=2)
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{Stats::SPD_P,AType::None,30}},"Bronya_Skill_E2",1  );
            

        });
        act->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        act->addToActionBar();
    }
}