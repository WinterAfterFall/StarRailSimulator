#include "../include.h"

void setup(){
    if(driverNum&&driverType==DriverType::NONE)driverType = DriverType::DOUBLE_TURN;
    
    sort(resetList.begin(), resetList.end(), TriggerFunc::triggerCmp);
    sort(whenOnFieldList.begin(), whenOnFieldList.end(), TriggerFunc::triggerCmp);
    sort(tuneStatsList.begin(), tuneStatsList.end(), TriggerFunc::triggerCmp);
    sort(startGameList.begin(), startGameList.end(), TriggerFunc::triggerCmp);
    sort(startWaveList.begin(), startWaveList.end(), TriggerFunc::triggerCmp);
    sort(beforeTurnList.begin(), beforeTurnList.end(), TriggerFunc::triggerCmp);
    sort(afterTurnList.begin(), afterTurnList.end(), TriggerFunc::triggerCmp);
    sort(ultimateList.begin(), ultimateList.end(), TriggerFunc::triggerCmp);
    sort(elationSkillList.begin(), elationSkillList.end(), TriggerFunc::triggerCmp);
    sort(beforeAhaInstantList.begin(), beforeAhaInstantList.end(), TriggerFunc::triggerCmp);
    sort(afterAhaInstantList.begin(), afterAhaInstantList.end(), TriggerFunc::triggerCmp);
    sort(whenUseUltList.begin(), whenUseUltList.end(), TriggerFunc::triggerCmp);
    

    sort(beforeActionList.begin(), beforeActionList.end(), TriggerFunc::triggerCmp);
    sort(afterActionList.begin(), afterActionList.end(), TriggerFunc::triggerCmp);
    sort(beforeAttackActionList.begin(), beforeAttackActionList.end(), TriggerFunc::triggerCmp);
    sort(afterAttackActionList.begin(), afterAttackActionList.end(), TriggerFunc::triggerCmp);
    sort(beforeAttackList.begin(), beforeAttackList.end(), TriggerFunc::triggerCmp);
    sort(afterAttackList.begin(), afterAttackList.end(), TriggerFunc::triggerCmp);
    sort(beforeAttackPerHitList.begin(), beforeAttackPerHitList.end(), TriggerFunc::triggerCmp);
    sort(afterAttackPerHitList.begin(), afterAttackPerHitList.end(), TriggerFunc::triggerCmp);
    sort(whenAttackList.begin(), whenAttackList.end(), TriggerFunc::triggerCmp);
    sort(buffList.begin(), buffList.end(), TriggerFunc::triggerCmp);

    sort(statsAdjustList.begin(), statsAdjustList.end(), TriggerFunc::triggerCmp);
    sort(healingList.begin(), healingList.end(), TriggerFunc::triggerCmp);
    sort(hpDecreaseList.begin(), hpDecreaseList.end(), TriggerFunc::triggerCmp);
    sort(allyDeathList.begin(), allyDeathList.end(), TriggerFunc::triggerCmp);

    sort(toughnessBreakList.begin(), toughnessBreakList.end(), TriggerFunc::triggerCmp);
    sort(beforeApplyDebuff.begin(), beforeApplyDebuff.end(), TriggerFunc::triggerCmp);
    sort(afterApplyDebuff.begin(), afterApplyDebuff.end(), TriggerFunc::triggerCmp);
    sort(enemyDeathList.begin(), enemyDeathList.end(), TriggerFunc::triggerCmp);

    sort(enemyHitList.begin(), enemyHitList.end(), TriggerFunc::triggerCmp);
    sort(dotList.begin(), dotList.end(), TriggerFunc::triggerCmp);
    sort(whenEnergyIncreaseList.begin(), whenEnergyIncreaseList.end(), TriggerFunc::triggerCmp);
    sort(skillPointList.begin(), skillPointList.end(), TriggerFunc::triggerCmp);
    sort(punchLineList.begin(), punchLineList.end(), TriggerFunc::triggerCmp);
    sort(afterDealingDamageList.begin(), afterDealingDamageList.end(), TriggerFunc::triggerCmp);
    
    if(rerollSubstatsMode == SubstatsRerollMode::STANDARD)rerollFunction = standardReroll;
    // ปิดไว้ก่อน — ใช้แค่ Standard (ดู Substats_Reset.h)
    // else
    // if(rerollSubstatsMode == SubstatsRerollMode::AllCombination)rerollFunction = AllCombinationReroll;
    // else
    // if(rerollSubstatsMode == SubstatsRerollMode::AllPossible)rerollFunction = AllPossibleReroll;
    
    for(int i=1;i<=totalAlly;i++){
        charUnit[i]->avgDmgRecord.resize(totalEnemy+1);
    }
    for(TriggerByYourSelfFunc &e : setupList){
        e.call(e.owner);
    }
    if(elationCount){
        atvList.push_back(aha.get());
    }
}

void reset(){
    turn = nullptr;
    sp =3;
    punchline = elationCount;
    ahaExtraFlatSpeed = 0;
    repellency = 0;
    currentAtv = 0;
    nextForwardPriority = 0;
    healCount = 0;
    decreaseHPCount = 0;
    basicReset();
    summonReset();
    countdownReset();
    
    for(TriggerByYourSelfFunc &e : resetList){
        e.call(e.owner);
    }
    
    memospriteReset();
    for(TriggerByYourSelfFunc &e : whenOnFieldList){
        e.call(e.owner);
    }
    for(int i=1;i<=totalAlly;i++){
        charUnit[i]->atkRequirment();
        charUnit[i]->hpRequirment();
        charUnit[i]->defRequirment();
        charUnit[i]->speedRequirment();
        charUnit[i]->ehrRequirment();
    }
    for(TriggerByYourSelfFunc &e : tuneStatsList){
        e.call(e.owner);
    }
    for(auto &each : charList){
        each->totalATK = calculateAtkOnStats(each);
        each->totalHP = calculateHpOnStats(each);
        each->totalDEF = calculateDefOnStats(each);
        if(auto *memo = each->memosprite.get()){
            memo->totalATK = calculateAtkOnStats(memo);
            memo->totalHP = calculateHpOnStats(memo);
            memo->totalDEF = calculateDefOnStats(memo);
        }
        each->currentHP = each->totalHP;
    }


    if(elationCount){
        Path temp = Path::ELATION;
        ahaSpeedAdjust(temp);
        for(auto &each : charList){
            if(each->path == Path::ELATION)buffSingle(each,{{Stats::CERTIFIED_BANGER,AType::NONE,20}},"CB Buff",2);
        }
    }
}

void startGame(){
    allAtvReset();
    for(TriggerByYourSelfFunc &e : startGameList){
        e.call(e.owner);
    }
}
void endWave(double totalAtv){
}
void startWave(int wave){
    if(wave!=0)allAtvReset();
    for(int i =1;i<=totalEnemy;i++){
        //Enemy_unit[i]->stats->toughnessStatus=1;
        //Enemy_unit[i]->stats->currentToughness=Enemy_unit[i]->maxToughness;
        enemyUnit[i]->whenToughnessBroken = 0;
        enemyUnit[i]->totalToughnessBrokenTime = 0;
    }
    for(TriggerByYourSelfFunc &e : startWaveList){
        e.call(e.owner);
    }
    
}
