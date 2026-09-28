#include "../include.h"

void basicReset(){
    
    for(int i=1;i<=totalAlly;i++){
        
        //flat atk
        for(auto &e1:charUnit[i]->statsType){
            for(auto &e2:e1.second){
                e2.second = 0;
            }

        }
        for(auto &e1:charUnit[i]->statsEachElement){
            for(auto &e2:e1.second){
                for(auto &e3:e2.second){
                    e3.second = 0;
                }
                
            }

        }
        
        
        //ally edit
            charUnit[i]->atvStats->flatSpeed = 0;
            charUnit[i]->atvStats->speedPercent = 0;
            charUnit[i]->atvStats->turnCnt = 0;
            charUnit[i]->atvStats->priority = 0;
            charUnit[i]->atvStats->extraTurn = 0;

            charUnit[i]->energyRecharge = 100;
            charUnit[i]->currentEnergy = charUnit[i]->maxEnergy/2;
            charUnit[i]->currentCharNum = charUnit[i]->defaultCharNum;
            charUnit[i]->currentMemoNum = charUnit[i]->defaultMemoNum;
            charUnit[i]->tauntIncrease = 0;
            charUnit[i]->taunt = charUnit[i]->baseTaunt;
            charUnit[i]->currentSheild = 0;
            charUnit[i]->status = UnitStatus::ALIVE;

            
            for(auto &e:charUnit[i]->stack){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->buffEnd){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->buffNote){
                e.second = 0;
            }
            for(auto &e:charUnit[i]->buffCheck){
                e.second = 0;
            }
            for(std::pair<const std::string, AllyUnit *> &e : charUnit[i]->buffSubUnitTarget){
                e.second = nullptr;
            }
            for(std::pair<const std::string, CharUnit *> &e : charUnit[i]->buffAllyTarget){
                e.second = nullptr;
            }

            charUnit[i]->currentTotalDmg = 0;
            for(auto &each : charUnit[i]->avgDmgRecord){
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


            
            charUnit[i]->statsType[Stats::ATK_P][AType::NONE] += 3.888*2;
            charUnit[i]->statsType[Stats::FLAT_ATK][AType::NONE] += 352.8+38;
            charUnit[i]->statsType[Stats::HP_P][AType::NONE] += 3.888*2;
            charUnit[i]->statsType[Stats::FLAT_HP][AType::NONE] += 76+705.6;
            charUnit[i]->statsType[Stats::DEF_P][AType::NONE] += 4.86*2;
            charUnit[i]->statsType[Stats::FLAT_DEF][AType::NONE] += 38;
            charUnit[i]->statsType[Stats::CR][AType::NONE] += 5+2.9*2;
            charUnit[i]->statsType[Stats::CD][AType::NONE] += 50+5.8*2;
            charUnit[i]->statsType[Stats::BE][AType::NONE] += 5.8*2;
            charUnit[i]->statsType[Stats::EHR][AType::NONE] += 3.888*2;
            charUnit[i]->statsType[Stats::RES][AType::NONE] += 4.32*2;
            charUnit[i]->atvStats->flatSpeed += 2.3*2;


            charUnit[i]->body(charUnit[i].get());
            charUnit[i]->boot(charUnit[i].get());
            charUnit[i]->orb(charUnit[i].get());
            charUnit[i]->rope(charUnit[i].get());
            charUnit[i]->statsType[Stats::EHR][AType::NONE] += charUnit[i]->extraEhr;
            charUnit[i]->atvStats->flatSpeed += charUnit[i]->extraSpeed;
            charUnit[i]->statsType[Stats::ATK_P][AType::NONE] += charUnit[i]->extraAtk;
            charUnit[i]->statsType[Stats::HP_P][AType::NONE] += charUnit[i]->extraHp;
            charUnit[i]->statsType[Stats::DEF_P][AType::NONE] += charUnit[i]->extraDef;
            
    }



        //enemy edit
        for(int i=1;i<=totalEnemy;i++){
            for(auto &e1:enemyUnit[i]->statsType){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:enemyUnit[i]->statsEachElement){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }
                
                }

        }
            enemyUnit[i]->atvStats->flatSpeed = 0;
            enemyUnit[i]->atvStats->speedPercent = 0;
            enemyUnit[i]->atvStats->turnCnt = 0;
            enemyUnit[i]->atvStats->priority = 0;
            enemyUnit[i]->atvStats->extraTurn = 0;
            enemyUnit[i]->toughnessStatus=1;
            enemyUnit[i]->toughnessAvgMultiplier = 0;

            enemyUnit[i]->currentToughness=enemyUnit[i]->maxToughness;
            enemyUnit[i]->totalDebuff=0;
            enemyUnit[i]->tauntList.clear();
            enemyUnit[i]->aoeCharge = 0;
            enemyUnit[i]->status = UnitStatus::ALIVE;

            for(auto &e: enemyUnit[i]->attackCoolDown){
                e.second = 0;
            }
            
            
            for(auto &e: enemyUnit[i]->weaknessType){
                e.second = enemyUnit[i]->defaultWeaknessType[e.first];
            }

            for(auto &e: enemyUnit[i]->debuffCheck){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->debuffNote){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->stack){
                e.second = 0;
            }
            for(auto &e: enemyUnit[i]->debuffEnd){
                e.second = 0;
            }
            
            
            enemyUnit[i]->totalToughnessBrokenTime =0;
            enemyUnit[i]->whenToughnessBroken = 0;
            enemyUnit[i]->breakDotList.clear();
            enemyUnit[i]->breakEngList.clear();
            enemyUnit[i]->breakFrzList.clear();
            enemyUnit[i]->breakImsList.clear();
            
            enemyUnit[i]->shockCount = 0;
            enemyUnit[i]->windSheerCount = 0;
            enemyUnit[i]->bleedCount = 0;
            enemyUnit[i]->burnCount = 0;
            enemyUnit[i]->dotCount = 0;
            
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::FIRE][AType::NONE] = - enemyUnit[i]->defaultElementRes[ElementType::FIRE];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::ICE][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::ICE];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::QUANTUM][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::QUANTUM];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::WIND][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::WIND];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::LIGHTNING][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::LIGHTNING];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::PHYSICAL][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::PHYSICAL];
            enemyUnit[i]->statsEachElement[Stats::RESPEN][ElementType::IMAGINARY][AType::NONE] = -enemyUnit[i]->defaultElementRes[ElementType::IMAGINARY];
            for(auto &e: enemyUnit[i]->weaknessTypeCountdown){
                e.second = 0;
            }
            enemyUnit[i]->currentWeaknessElementAmount = enemyUnit[i]->defaultWeaknessElementAmount;
        }

    

}
void memospriteReset(){
    for(auto &each : charList){
        if(auto *memo = each->memosprite.get()){
            for(auto &e1:memo->statsType){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:memo->statsEachElement){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }

                }

            }
            for(auto &e1:each->statsType){
                for(auto &e2:e1.second){
                    memo->statsType[e1.first][e2.first] = e2.second;
                }

            }
            for(auto &e1:each->statsEachElement){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        memo->statsEachElement[e1.first][e2.first][e3.first] = e3.second;
                    }

                }

            }
            for(auto &e :memo->statsType[Stats::FLAT_HP]){    
                e.second *=(memo->unitHpRatio/100);
            }
            memo->statsType[Stats::FLAT_HP][AType::NONE] += memo->fixHP;
        //speed
        
            for(auto &e:memo->stack){
                e.second = 0;
            }
            for(auto &e:memo->buffEnd){
                e.second = 0;
            }
            for(auto &e:memo->buffNote){
                e.second = 0;
            }
            for(auto &e:memo->buffCheck){
                e.second = 0;
            }
            for(std::pair<const std::string, AllyUnit *> &e : memo->buffSubUnitTarget){
                e.second = nullptr;
            }
            
        memo->atvStats->turnCnt = 0;
        memo->atvStats->priority = 0;
        memo->atvStats->extraTurn = 0;
        memo->atvStats->baseSpeed = 
        memo->fixSpeed + calculateSpeedOnStats(each)*memo->unitSpeedRatio/100;
        memo->atvStats->speedPercent = 0;
        memo->atvStats->flatSpeed = 0;
        memo->currentCharNum = memo->defaultCharNum;
        memo->currentMemoNum = memo->defaultMemoNum;
        memo->currentSheild = 0;
        memo->currentHP = 0;
        memo->status = UnitStatus::DEATH;
        memo->tauntIncrease = 0;
        memo->taunt = memo->baseTaunt;

        }
        
    }
}
void summonReset(){
    for(int i=1;i<=totalAlly;i++){
        for(int j=0,sz = charUnit[i]->summonList.size();j<sz;j++){  
        
        //speed
        charUnit[i]->summonList[j]->speedPercent=0;
        charUnit[i]->summonList[j]->flatSpeed=0;
        charUnit[i]->summonList[j]->turnCnt = 0;
        charUnit[i]->summonList[j]->priority = 0;
        charUnit[i]->summonList[j]->extraTurn = 0;
        charUnit[i]->summonList[j]->status = UnitStatus::ALIVE;

        }
    }
}
void countdownReset(){
    for(int i=1;i<=totalAlly;i++){
        for(int j=0,sz = charUnit[i]->countdownList.size();j<sz;j++){  
        
        //speed
        charUnit[i]->countdownList[j]->speedPercent=0;
        charUnit[i]->countdownList[j]->flatSpeed=0;
        charUnit[i]->countdownList[j]->turnCnt = 0;
        charUnit[i]->countdownList[j]->priority = 0;
        charUnit[i]->countdownList[j]->extraTurn = 0;
        charUnit[i]->countdownList[j]->status = UnitStatus::DEATH;
        }
    }
}
