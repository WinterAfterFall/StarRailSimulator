
#ifndef Jingyuan_H
#define Jingyuan_H

#define F first
#define S second
#include "../Library.h"

namespace Jingyuan{
    void Setup_Jingyuan(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);

    bool Temp_Turn_Condition(Unit *ptr);
    bool Temp_ult_Condition(Ally *ptr);



    void Setup_Jingyuan(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99, 130, 130, E, "Lightning", "Erudition", "Jingyuan",TYPE_STD);
        SubUnit *JYptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1164, 698, 485);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if ((sp <= Sp_Safety) || allyPtr->Atv_stats->turn_cnt == 1 && Sp_status == "Negative") {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,JYptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Ult,JYptr,TT_AOE,"JY Ult",
            [ptr,JYptr](shared_ptr<AllyAttackAction> &data_){
                Attack(data_);
                if (ptr->Print)CharCmd::printUltStart("Jingyuan");
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                if (ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] >= 10) {
                    ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 70;
                    ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,0});
                } else {
                    ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,30});
                }
            });
            data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            data_->addToActionBar();
            Deal_damage();
        }));
        

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,JYptr]() {
            if (!(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num == turn->Unit_num && turn->Side == "Ally")) return;
            
            if (JYptr->isBuffEnd("War_Marshal")) {
                JYptr->buffSingle({{ST_CR,AT_NONE,-10}});
            }
            ;
            if (ptr->Eidolon >= 2 && JYptr->isBuffEnd("Swing_Skies_Squashed")) {
                JYptr->buffSingle({
                    {ST_DMG,AT_BA,-20},
                    {ST_DMG,AT_SKILL,-20},
                    {ST_DMG,AT_ULT,-20}
                });
            }
        }));


        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 12.5;

            // relic

            // substats

            // LL
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
            ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 0;
            ptr->Summon_ptr[0]->Atv_stats->Speed_percent = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,JYptr]() {
            if (ptr->Technique == 1) {
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,30});

            }
            Increase_energy(ptr, 15);
        }));


        //LL
        SetSummonStats(ptr, 60, "LL");
        ptr->Summon_ptr[0]->Turn_func = [ptr,JYptr](){
            
            shared_ptr<AllyAttackAction> temp = 
            make_shared<AllyAttackAction>(ActionType::Fua,JYptr,TT_SINGLE,"LL Fua",
            [ptr,JYptr](shared_ptr<AllyAttackAction> &data_){
                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR]["Summon"]+=25;
                }

                for(int i=1;i<=ptr->Sub_Unit_ptr[0]->Stack["LL_stack"];i++){
                    if(ptr->Eidolon>=1)
                        data_->addDamageIns(
                            DmgSrc(DmgSrcType::ATK,66,5),
                            DmgSrc(DmgSrcType::ATK,33,5)
                        );
                    else
                        data_->addDamageIns(
                            DmgSrc(DmgSrcType::ATK,66,5),
                            DmgSrc(DmgSrcType::ATK,66*0.25,5)
                        );
                    
                }
                Attack(data_);

                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR]["Summon"]-=25;
                }
        
                turn->Flat_Speed = 0;
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
                
                
                if(ptr->Eidolon>=2){
                    JYptr->buffSingle({
                        {ST_DMG,AT_BA,20},
                        {ST_DMG,AT_SKILL,20},
                        {ST_DMG,AT_ULT,20}},
                        "Swing_Skies_Squashed",2
                    );
                }
            });
            temp->addActionType(ActionType::Summon);
            temp->setTurnReset(true);
            temp->addToActionBar();
            

        };
    }

    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"JY BA",
        [ptr](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        });
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5.5));
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,45,4.5));
        data_->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"JY Skill",
        [ptr,JYptr = ptr->getSubUnit()](shared_ptr<AllyAttackAction> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            JYptr->buffSingle({{ST_CR,AT_NONE,10}},"War_Marshal",2);
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]+=2;
            if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=10){
                ptr->Summon_ptr[0]->Atv_stats->Flat_Speed=70;
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,0});
            }else{
                ptr->Summon_ptr[0]->speedBuff({ST_SPD,ST_FLAT_SPD,20});
            }
            Attack(data_);
        });
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,40,4),
            DmgSrc(DmgSrcType::ATK,40,4),
            DmgSrc(DmgSrcType::ATK,40,4)
        );
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3)
        );
        data_->addDamageIns(
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3),
            DmgSrc(DmgSrcType::ATK,30,3)
        );
        data_->addToActionBar();
    }



    bool Temp_Turn_Condition(Unit *ptr){
        return true;
    }
    bool Temp_ult_Condition(Ally *ptr){
        return true;
    }
}
#endif