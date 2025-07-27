#include "../include.h"

void Basic_reset(){
    
    for(int i=1;i<=Total_ally;i++){
        
        //flat atk
        for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type){
            for(auto &e2:e1.second){
                e2.second = 0;
            }

        }
        for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_each_element){
            for(auto &e2:e1.second){
                for(auto &e3:e2.second){
                    e3.second = 0;
                }
                
            }

        }
        
        
        //ally edit
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->speedPercent = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->turnCnt = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->priority = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->extraTurn = 0;

            Ally_unit[i]->Energy_recharge = 100;
            Ally_unit[i]->Current_energy = Ally_unit[i]->Max_energy/2;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentAllyTargetNum = Ally_unit[i]->Sub_Unit_ptr[0]->defaultAllyTargetNum;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentSubUnitTargetNum = Ally_unit[i]->Sub_Unit_ptr[0]->defaultSubUnitTargetNum;
            Ally_unit[i]->Sub_Unit_ptr[0]->tauntMtpr = 1;
            Ally_unit[i]->Sub_Unit_ptr[0]->taunt = Ally_unit[i]->Sub_Unit_ptr[0]->baseTaunt;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentSheild = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->status = UnitStatus::Alive;

            
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Stack){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_note){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, SubUnit *> &e : Ally_unit[i]->Sub_Unit_ptr[0]->buffSubUnitTarget){
                e.second = nullptr;
            }
            for(std::pair<const std::string, Ally *> &e : Ally_unit[i]->Sub_Unit_ptr[0]->buffAllyTarget){
                e.second = nullptr;
            }

            Ally_unit[i]->currentTotalDmg = 0;
            for(auto &each : Ally_unit[i]->AvgDmgRecord){
                each.avgDmgInstance.clear();
                each.lastNote = 0;
                each.currentDmgRecord = 0;
            }
            for(auto &each : Ally_unit[i]->currentRealTimeDmg){
                each.second.total = 0;
                for(auto &each2 : each.second.type){
                    each2.second = 0;
                }
            }
            for(auto &each : Ally_unit[i]->currentNonRealTimeDmg){
                each.second.total = 0;
                for(auto &each2 : each.second.type){
                    each2.second = 0;
                }
            }


            
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_ATK][AType::None] += 352.8+38;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_HP][AType::None] += 76+705.6;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 4.86*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_DEF][AType::None] += 38;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 5+2.9*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 50+5.8*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 5.8*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 4.32*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 2.3*2;


            Ally_unit[i]->Body(Ally_unit[i].get());
            Ally_unit[i]->Boot(Ally_unit[i].get());
            Ally_unit[i]->Orb(Ally_unit[i].get());
            Ally_unit[i]->Rope(Ally_unit[i].get());
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += Ally_unit[i]->ExtraEhr;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += Ally_unit[i]->ExtraSpeed;
            
    }



        //enemy edit
        for(int i=1;i<=Total_enemy;i++){
            for(auto &e1:Enemy_unit[i]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:Enemy_unit[i]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }
                
                }

        }
            Enemy_unit[i]->Atv_stats->flatSpeed = 0;
            Enemy_unit[i]->Atv_stats->speedPercent = 0;
            Enemy_unit[i]->Atv_stats->turnCnt = 0;
            Enemy_unit[i]->Atv_stats->priority = 0;
            Enemy_unit[i]->Atv_stats->extraTurn = 0;
            Enemy_unit[i]->Toughness_status=1;
            Enemy_unit[i]->toughnessAvgMultiplier = 0;

            Enemy_unit[i]->Current_toughness=Enemy_unit[i]->Max_toughness;
            Enemy_unit[i]->Total_debuff=0;
            Enemy_unit[i]->tauntList.clear();
            Enemy_unit[i]->atkPercent = 0;
            Enemy_unit[i]->dmgPercent = 0;
            Enemy_unit[i]->AoeCharge = 0;
            Enemy_unit[i]->status = UnitStatus::Alive;

            for(auto &e: Enemy_unit[i]->AttackCoolDown){
                e.second = 0;
            }
            
            
            for(auto &e: Enemy_unit[i]->Weakness_type){
                e.second = Enemy_unit[i]->Default_Weakness_type[e.first];
            }

            for(auto &e: Enemy_unit[i]->Debuff){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->DebuffNote){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->Stack){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->Debuff_time_count){
                e.second = 0;
            }
            
            
            Enemy_unit[i]->Total_toughness_broken_time =0;
            Enemy_unit[i]->when_toughness_broken = 0;
            Enemy_unit[i]->breakDotList.clear();
            Enemy_unit[i]->breakEngList.clear();
            Enemy_unit[i]->breakFrzList.clear();
            Enemy_unit[i]->breakImsList.clear();
            
            Enemy_unit[i]->ShockCount = 0;
            Enemy_unit[i]->WindSheerCount = 0;
            Enemy_unit[i]->BleedCount = 0;
            Enemy_unit[i]->BurnCount = 0;
            Enemy_unit[i]->DotCount = 0;
            
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Fire][AType::None] = - Enemy_unit[i]->DefaultElementRes[ElementType::Fire];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Ice][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Ice];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Quantum][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Quantum];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Wind][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Wind];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Lightning][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Lightning];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Physical][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Physical];
            Enemy_unit[i]->Stats_each_element[Stats::RESPEN][ElementType::Imaginary][AType::None] = -Enemy_unit[i]->DefaultElementRes[ElementType::Imaginary];
            for(auto &e: Enemy_unit[i]->Weakness_typeCountdown){
                e.second = 0;
            }
            Enemy_unit[i]->currentWeaknessElementAmount = Enemy_unit[i]->defaultWeaknessElementAmount;
        }

    

}
void Memosprite_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=1,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[j]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }

                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type){
                for(auto &e2:e1.second){
                    Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type[e1.first][e2.first] = e2.second;
                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        Ally_unit[i]->Sub_Unit_ptr[j]->Stats_each_element[e1.first][e2.first][e3.first] = e3.second;
                    }

                }

            }
            for(auto &e :Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type[Stats::FLAT_HP]){    
                e.second *=(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Hp_Ratio/100);
            }
            Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type[Stats::FLAT_HP][AType::None] += Ally_unit[i]->Sub_Unit_ptr[j]->fixHP;
        //speed
        
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Stack){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_note){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, SubUnit *> &e : Ally_unit[i]->Sub_Unit_ptr[j]->buffSubUnitTarget){
                e.second = nullptr;
            }
            
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->turnCnt = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->priority = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->extraTurn = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->flatSpeed = Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed*(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Speed_Ratio/100);
        if(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Speed_Ratio!=0)Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->speedPercent = Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->speedPercent;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentAllyTargetNum = Ally_unit[i]->Sub_Unit_ptr[j]->defaultAllyTargetNum;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentSubUnitTargetNum = Ally_unit[i]->Sub_Unit_ptr[j]->defaultSubUnitTargetNum;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentSheild = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentHP = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->status = UnitStatus::Death;
        Ally_unit[i]->Sub_Unit_ptr[j]->tauntMtpr = 1;
        Ally_unit[i]->Sub_Unit_ptr[j]->taunt = Ally_unit[i]->Sub_Unit_ptr[j]->baseTaunt;

        }
        
    }
}
void Summon_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){  
        
        //speed
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->speedPercent=0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->flatSpeed=0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->turnCnt = 0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->priority = 0;
        Ally_unit[i]->Summon_ptr[j]->status = UnitStatus::Alive;

        }
    }
}
void Countdown_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){  
        
        //speed
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->speedPercent=0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->flatSpeed=0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->turnCnt = 0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->priority = 0;
        Ally_unit[i]->Countdown_ptr[j]->status = UnitStatus::Death;
        }
    }
}