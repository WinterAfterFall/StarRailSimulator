#include "../include.h"

void Basic_reset(){
    
    for(int i=1;i<=Total_ally;i++){
        
        //flat atk
        for(auto &e1:charUnit[i]->Sub_Unit_ptr[0]->Stats_type){
            for(auto &e2:e1.second){
                e2.second = 0;
            }

        }
        for(auto &e1:charUnit[i]->Sub_Unit_ptr[0]->Stats_each_element){
            for(auto &e2:e1.second){
                for(auto &e3:e2.second){
                    e3.second = 0;
                }
                
            }

        }
        
        
        //ally edit
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed = 0;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->speedPercent = 0;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->turnCnt = 0;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->priority = 0;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->extraTurn = 0;

            charUnit[i]->Energy_recharge = 100;
            charUnit[i]->Current_energy = charUnit[i]->Max_energy/2;
            charUnit[i]->Sub_Unit_ptr[0]->currentAllyTargetNum = charUnit[i]->Sub_Unit_ptr[0]->defaultAllyTargetNum;
            charUnit[i]->Sub_Unit_ptr[0]->currentSubUnitTargetNum = charUnit[i]->Sub_Unit_ptr[0]->defaultSubUnitTargetNum;
            charUnit[i]->Sub_Unit_ptr[0]->tauntMtpr = 1;
            charUnit[i]->Sub_Unit_ptr[0]->taunt = charUnit[i]->Sub_Unit_ptr[0]->baseTaunt;
            charUnit[i]->Sub_Unit_ptr[0]->currentSheild = 0;
            charUnit[i]->Sub_Unit_ptr[0]->status = UnitStatus::Alive;

            
            for(auto &e:charUnit[i]->Sub_Unit_ptr[0]->Stack){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[0]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[0]->Buff_note){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[0]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, AllyUnit *> &e : charUnit[i]->Sub_Unit_ptr[0]->buffSubUnitTarget){
                e.second = nullptr;
            }
            for(std::pair<const std::string, CharUnit *> &e : charUnit[i]->Sub_Unit_ptr[0]->buffAllyTarget){
                e.second = nullptr;
            }

            charUnit[i]->currentTotalDmg = 0;
            for(auto &each : charUnit[i]->AvgDmgRecord){
                each.avgDmgInstance.clear();
                each.lastNote = 0;
                each.currentDmgRecord = 0;
            }
            for(auto &each : charUnit[i]->currentRealTimeDmg){
                each.second.total = 0;
                for(auto &each2 : each.second.type){
                    each2.second = 0;
                }
            }
            for(auto &each : charUnit[i]->currentNonRealTimeDmg){
                each.second.total = 0;
                for(auto &each2 : each.second.type){
                    each2.second = 0;
                }
            }


            
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 3.888*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_ATK][AType::None] += 352.8+38;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 3.888*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_HP][AType::None] += 76+705.6;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 4.86*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::FLAT_DEF][AType::None] += 38;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 5+2.9*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 50+5.8*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 5.8*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 3.888*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 0;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::RES][AType::None] += 4.32*2;
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 3.888*2;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 2.3*2;


            charUnit[i]->Body(charUnit[i].get());
            charUnit[i]->Boot(charUnit[i].get());
            charUnit[i]->Orb(charUnit[i].get());
            charUnit[i]->Rope(charUnit[i].get());
            charUnit[i]->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += charUnit[i]->ExtraEhr;
            charUnit[i]->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += charUnit[i]->ExtraSpeed;
            
    }



        //enemy edit
        for(int i=1;i<=Total_enemy;i++){
            for(auto &e1:enemyUnit[i]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:enemyUnit[i]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }
                
                }

        }
            enemyUnit[i]->Atv_stats->flatSpeed = 0;
            enemyUnit[i]->Atv_stats->speedPercent = 0;
            enemyUnit[i]->Atv_stats->turnCnt = 0;
            enemyUnit[i]->Atv_stats->priority = 0;
            enemyUnit[i]->Atv_stats->extraTurn = 0;
            enemyUnit[i]->Toughness_status=1;
            enemyUnit[i]->toughnessAvgMultiplier = 0;

            enemyUnit[i]->Current_toughness=enemyUnit[i]->Max_toughness;
            enemyUnit[i]->Total_debuff=0;
            enemyUnit[i]->tauntList.clear();
            enemyUnit[i]->atkPercent = 0;
            enemyUnit[i]->dmgPercent = 0;
            enemyUnit[i]->AoeCharge = 0;
            enemyUnit[i]->status = UnitStatus::Alive;

            for(auto &e: enemyUnit[i]->AttackCoolDown){
                e.second = 0;
            }
            
            
            for(auto &e: enemyUnit[i]->Weakness_type){
                e.second = enemyUnit[i]->Default_Weakness_type[e.first];
            }

            for(auto &e: enemyUnit[i]->Debuff){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->DebuffNote){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->Stack){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->Debuff_time_count){
                e.second = 0;
            }
            
            
            enemyUnit[i]->Total_toughness_broken_time =0;
            enemyUnit[i]->when_toughness_broken = 0;
            enemyUnit[i]->breakDotList.clear();
            enemyUnit[i]->breakEngList.clear();
            enemyUnit[i]->breakFrzList.clear();
            enemyUnit[i]->breakImsList.clear();
            
            enemyUnit[i]->ShockCount = 0;
            enemyUnit[i]->WindSheerCount = 0;
            enemyUnit[i]->BleedCount = 0;
            enemyUnit[i]->BurnCount = 0;
            enemyUnit[i]->DotCount = 0;
            
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Fire][AType::None] = - enemyUnit[i]->DefaultElementRes[ElementType::Fire];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Ice][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Ice];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Quantum][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Quantum];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Wind][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Wind];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Lightning][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Lightning];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Physical][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Physical];
            enemyUnit[i]->Stats_each_element[Stats::RESPEN][ElementType::Imaginary][AType::None] = -enemyUnit[i]->DefaultElementRes[ElementType::Imaginary];
            for(auto &e: enemyUnit[i]->Weakness_typeCountdown){
                e.second = 0;
            }
            enemyUnit[i]->currentWeaknessElementAmount = enemyUnit[i]->defaultWeaknessElementAmount;
        }

    

}
void Memosprite_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=1,sz = charUnit[i]->Sub_Unit_ptr.size();j<sz;j++){
            for(auto &e1:charUnit[i]->Sub_Unit_ptr[j]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:charUnit[i]->Sub_Unit_ptr[j]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }

                }

            }
            for(auto &e1:charUnit[i]->Sub_Unit_ptr[0]->Stats_type){
                for(auto &e2:e1.second){
                    charUnit[i]->Sub_Unit_ptr[j]->Stats_type[e1.first][e2.first] = e2.second;
                }

            }
            for(auto &e1:charUnit[i]->Sub_Unit_ptr[0]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        charUnit[i]->Sub_Unit_ptr[j]->Stats_each_element[e1.first][e2.first][e3.first] = e3.second;
                    }

                }

            }
            for(auto &e :charUnit[i]->Sub_Unit_ptr[j]->Stats_type[Stats::FLAT_HP]){    
                e.second *=(charUnit[i]->Sub_Unit_ptr[j]->Unit_Hp_Ratio/100);
            }
            charUnit[i]->Sub_Unit_ptr[j]->Stats_type[Stats::FLAT_HP][AType::None] += charUnit[i]->Sub_Unit_ptr[j]->fixHP;
        //speed
        
            for(auto &e:charUnit[i]->Sub_Unit_ptr[j]->Stack){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[j]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[j]->Buff_note){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->Sub_Unit_ptr[j]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, AllyUnit *> &e : charUnit[i]->Sub_Unit_ptr[j]->buffSubUnitTarget){
                e.second = nullptr;
            }
            
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->turnCnt = 0;
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->priority = 0;
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->extraTurn = 0;
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->baseSpeed = 
        charUnit[i]->Sub_Unit_ptr[j]->fixSpeed + calculateSpeedOnStats(charUnit[i])*charUnit[i]->Sub_Unit_ptr[j]->Unit_Speed_Ratio/100;
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->speedPercent = 0;
        charUnit[i]->Sub_Unit_ptr[j]->Atv_stats->flatSpeed = 0;
        charUnit[i]->Sub_Unit_ptr[j]->currentAllyTargetNum = charUnit[i]->Sub_Unit_ptr[j]->defaultAllyTargetNum;
        charUnit[i]->Sub_Unit_ptr[j]->currentSubUnitTargetNum = charUnit[i]->Sub_Unit_ptr[j]->defaultSubUnitTargetNum;
        charUnit[i]->Sub_Unit_ptr[j]->currentSheild = 0;
        charUnit[i]->Sub_Unit_ptr[j]->currentHP = 0;
        charUnit[i]->Sub_Unit_ptr[j]->status = UnitStatus::Death;
        charUnit[i]->Sub_Unit_ptr[j]->tauntMtpr = 1;
        charUnit[i]->Sub_Unit_ptr[j]->taunt = charUnit[i]->Sub_Unit_ptr[j]->baseTaunt;

        }
        
    }
}
void Summon_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = charUnit[i]->summonList.size();j<sz;j++){  
        
        //speed
        charUnit[i]->summonList[j]->Atv_stats->speedPercent=0;
        charUnit[i]->summonList[j]->Atv_stats->flatSpeed=0;
        charUnit[i]->summonList[j]->Atv_stats->turnCnt = 0;
        charUnit[i]->summonList[j]->Atv_stats->priority = 0;
        charUnit[i]->summonList[j]->status = UnitStatus::Alive;

        }
    }
}
void Countdown_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = charUnit[i]->countdownList.size();j<sz;j++){  
        
        //speed
        charUnit[i]->countdownList[j]->Atv_stats->speedPercent=0;
        charUnit[i]->countdownList[j]->Atv_stats->flatSpeed=0;
        charUnit[i]->countdownList[j]->Atv_stats->turnCnt = 0;
        charUnit[i]->countdownList[j]->Atv_stats->priority = 0;
        charUnit[i]->countdownList[j]->status = UnitStatus::Death;
        }
    }
}