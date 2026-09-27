#include "../include.h"

void takeAction(){

    if(turn == aha.get()){
        ahaTurn();
        return; 
    }
    phaseStatus = PhaseStatus::DOT_BEFORE_TURN;
    if(!turn->extraTurn){
        ++(turn->turnCnt);
        allEventBeforeTurn();
    }
    if(turn->canCastToAllyUnit())allUltimateCheck();
    print();
    if(turnSkip==0){
        
        turn->runTurn();  
        
        dealDamage();
    }
    
    phaseStatus = PhaseStatus::AFTER_TURN;
    if(!turn->extraTurn)allEventAfterTurn();

}
void dealDamage(){
    if(actionBarUse)return;
    actionBarUse = true;
    PhaseStatus beforeStatus = phaseStatus;
    while(!actionBar.empty()){
        shared_ptr<ActionData> temp = actionBar.front();
        phaseStatus = PhaseStatus::WHILE_ACTION;
        allEventBeforeAction(temp);
        if (auto allyActionData = dynamic_pointer_cast<AllyActionData>(temp)) {
            allEventBeforeAllyAction(allyActionData);
            allyActionData->allyAction();
            allEventAfterAllyAction(allyActionData);
        } else if (auto enemyActionData = dynamic_pointer_cast<EnemyActionData>(temp)) {
            enemyActionData->enemyAction();
        }
        allEventAfterAction(temp);
        if(turn)allUltimateCheck();
        actionBar.pop();
    }
    actionBarUse = false;
    phaseStatus = beforeStatus;
}
void AllyActionData::allyAction(){
    std::shared_ptr<AllyActionData> self = shared_from_this();
    std::shared_ptr<AllyAttackAction> attackAction = dynamic_pointer_cast<AllyAttackAction>(self);
    std::shared_ptr<AllyBuffAction> buffAction = dynamic_pointer_cast<AllyBuffAction>(self);
    if(attackAction){
        allEventBeforeAttackAction(attackAction);
        
        if(attackAction->actionFunction)attackAction->actionFunction(attackAction);
        else attack(attackAction);    
        
        for(int i = 0; i < attackAction->attackSetList.size() ; i++){
            attackAction->attacker = attackAction->attackSetList[i].attacker;
            attackAction->actionTypeList = attackAction->attackSetList[i].actionTypeList;
            attackAction->damageTypeList = attackAction->attackSetList[i].damageTypeList;
            allEventWhenAttack(attackAction);
        }
        
        attackAction->attacker = attackAction->attackSetList[0].attacker;
        attackAction->actionTypeList = attackAction->attackSetList[0].actionTypeList;
        attackAction->damageTypeList = attackAction->attackSetList[0].damageTypeList;
        allEventAfterAttackAction(attackAction); 
        if(attackAction->damageNote)calAverageDamage(attackAction->attacker->owner,attackAction->targetList); 

    }else{
        if(buffAction->actionFunction)buffAction->actionFunction(buffAction);
        if(buffAction->turnReset)resetTurn(turn);
        allEventBuff(buffAction);
    }
    
}
// Same as allyAction but without Before/AfterAttackAction:
// inside an Aha Instant each Elation Skill is not its own attack action
void AllyActionData::elationSkillAction(){
    std::shared_ptr<AllyActionData> self = shared_from_this();
    std::shared_ptr<AllyAttackAction> attackAction = dynamic_pointer_cast<AllyAttackAction>(self);
    std::shared_ptr<AllyBuffAction> buffAction = dynamic_pointer_cast<AllyBuffAction>(self);
    if(attackAction){
        if(attackAction->actionFunction)attackAction->actionFunction(attackAction);
        else attack(attackAction);    
        
        for(int i = 0; i < attackAction->attackSetList.size() ; i++){
            attackAction->attacker = attackAction->attackSetList[i].attacker;
            attackAction->actionTypeList = attackAction->attackSetList[i].actionTypeList;
            attackAction->damageTypeList = attackAction->attackSetList[i].damageTypeList;
            allEventWhenAttack(attackAction);
        }
        
        attackAction->attacker = attackAction->attackSetList[0].attacker;
        attackAction->actionTypeList = attackAction->attackSetList[0].actionTypeList;
        attackAction->damageTypeList = attackAction->attackSetList[0].damageTypeList;
        if(attackAction->damageNote)calAverageDamage(attackAction->attacker->owner,attackAction->targetList); 

    }else{
        if(buffAction->actionFunction)buffAction->actionFunction(buffAction);
        if(buffAction->turnReset)resetTurn(turn);
    }
    
}
void EnemyActionData::enemyAction(){
    this->actionFunction();
    resetTurn(turn);
}
void attack(shared_ptr<AllyAttackAction> &act){
    if(act->targetList.empty())act->addEnemyToTargetList();

    //32 45
    if(act->attacker->owner->canCheckDmgformula()||act->attacker->owner->checkDamage){
        cout<<"\033[0;38;5;2m";
        cout<<"----------------------------------------- Damage Check -----------------------------------------\n";
        cout << "\033[0m";
    }

    

    int dmgIns = 0;
    for(auto &each : act->attackSetList){
        each.attacker->hitCount = 0;
    }
    for(auto &each : act->targetList){
        each->hitCount = 0;
    }

    allEventBeforeAttack(act);
    for(int i = 0;i<act->damageSplit.size();i++){
        if(dmgIns!=act->switchAttacker.size()&&act->switchAttacker[dmgIns].changeWhen==i){
            SwitchAtk &SwitchAtk = act->switchAttacker[dmgIns];
            act->attacker = act->attackSetList[SwitchAtk.changeTo].attacker;
            if(SwitchAtk.source)act->source = SwitchAtk.source;
            else act->source = act->attacker;
            act->actionTypeList = act->attackSetList[SwitchAtk.changeTo].actionTypeList;
            act->damageTypeList = act->attackSetList[SwitchAtk.changeTo].damageTypeList;
            ++dmgIns;
        }
        act->attacker->hitCount += act->damageSplit[i].size();
        for(auto &each2 : act->damageSplit[i]){
            each2.target->hitCount++;
        }
        
        allEventBeforeAttackPerHit(act);
        for(auto &each2 : act->damageSplit[i]){
            calDamage(act,each2.target,each2.dmgSrc);
            calElationDamage(act,each2.target,each2.dmgSrc);
            if(each2.dmgSrc.toughnessReduce>0)
            calToughnessReduction(act,each2.target,each2.dmgSrc.toughnessReduce);
        }
        allEventAfterAttackPerHit(act);
    }
    allEventAfterAttack(act);


    

    if(act->attacker->owner->canCheckDmgformula()||act->attacker->owner->checkDamage){
        cout<<"\033[0;38;5;2m";
        cout<<"------------------------------------------------------------------------------------------------\n";  
        cout << "\033[0m";
    }
    
    if(act->turnReset)resetTurn(turn);
}
void genSkillPoint(AllyUnit *ptr,int p){
    
    allEventSkillPoint(ptr,p);
    sp+=p;
    if(sp>maxSp){
        sp = maxSp;
    }
    return;
}
void genPunchLine(AllyUnit *ptr,int p){

    allEventPunchLine(ptr,p);
    punchline+=p;
    punchline = max(punchline,0);
    return;
}
void superbreakTrigger(shared_ptr<AllyAttackAction> &act, double superbreakRatio,string triggerName){
    shared_ptr<AllyAttackAction> data2 = 
    make_shared<AllyAttackAction>(AType::SPB,act->attacker,act->traceType,act->attacker->atvStats->name + " " + triggerName +" SPB");
    
    for(auto &each1 : act->damageSplit){
        for(auto &each2 : each1){
            each2.target->toughnessReduceNote += each2.dmgSrc.toughnessReduce;
        }
    }
    for(int i=1;i<=totalEnemy;i++){
        if(enemyUnit[i]->toughnessStatus==1&&!dahliaCheck)continue;
        double toughnessReduce = enemyUnit[i]->toughnessReduceNote;
        enemyUnit[i]->toughnessReduceNote = 0;
        if(toughnessReduce==0)continue;
        // SPB ปกติเกิดบนเป้าที่ broken แล้ว (Broken mult ล็อค 1.0) → เก็บ real-time ไม่เฉลี่ย
        // SPB ผ่าน Dahlia บนเป้าที่ยังไม่ broken → Broken mult ไม่แน่นอน → เก็บใน pool ที่เฉลี่ย toughness/weaken
        data2->toughnessAvgCalculate = dahliaCheck ? 1 : 0;
        toughnessReduce = calTotalToughnessReduce(act,enemyUnit[i].get(),toughnessReduce);
        if(enemyUnit[i]->currentToughness+toughnessReduce<=0||dahliaCheck){
        calSuperbreakDamage(data2,enemyUnit[i].get(),superbreakRatio*toughnessReduce/10);
        }else{
        calSuperbreakDamage(data2,enemyUnit[i].get(),superbreakRatio*(-1)*enemyUnit[i]->currentToughness/10);
        }
    }
}

void dotTrigger(double dotRatio,Enemy *target,DotType dotType){
    
    
    for(auto &each : target->breakDotList) {
        switch (each.type) {
            case BreakSEType::BLEED:
                if (dotType == DotType::GENERAL|| dotType == DotType::BLEED) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::DOT,each.ptr,TraceType::SINGLE, "Break Bleed");
                    act->actionTypeList.push_back(AType::BLEED);
                    calDotToughnessBreakDamage(act, target, 
                        dotRatio * 2 * (0.5 + target->maxToughness/40));
                }
                break;

            case BreakSEType::BURN:
                if (dotType == DotType::GENERAL|| dotType == DotType::BURN) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::DOT,each.ptr,TraceType::SINGLE, "Break Burn");
                    act->actionTypeList.push_back(AType::BURN);
                    calDotToughnessBreakDamage(act, target, dotRatio * 1);
                }
                break;

            case BreakSEType::SHOCK:
                if (dotType == DotType::GENERAL|| dotType == DotType::SHOCK) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::DOT,each.ptr,TraceType::SINGLE, "Break Shock");
                    act->actionTypeList.push_back(AType::SHOCK);
                    calDotToughnessBreakDamage(act, target, dotRatio * 2);
                }
                break;

            case BreakSEType::WIND_SHEAR:
                if (dotType == DotType::GENERAL|| dotType == DotType::WIND_SHEAR) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::DOT,each.ptr,TraceType::SINGLE, "Break WindShear");
                    act->actionTypeList.push_back(AType::WIND_SHEAR);
                    calDotToughnessBreakDamage(act, target, 
                        dotRatio * 1 * each.stack);
                }
                break;

            default:
                break;
        }
    }
    
    for(TriggerDotFunc &e : dotList){
        e.call(target,dotRatio,dotType);
    }
    
}
void toughnessBreak(shared_ptr<AllyAttackAction> &act,Enemy* target){
    shared_ptr<AllyAttackAction> data2;
    double constant = 0;
    if(forceBreak)
    data2 = 
    make_shared<AllyAttackAction>(AType::BREAK, charUnit[forceBreak].get(),TraceType::SINGLE,"Break");
    else
    data2 =
    make_shared<AllyAttackAction>(AType::BREAK, act->attacker,TraceType::SINGLE,"Break");
    allEventBeforeApplyDebuff(act->attacker,target);
    ++target->totalDebuff;
    

    if(superBreakMode==1){
        target->atvStats->atv=target->atvStats->maxAtv*0.5;
    }

    if(data2->damageElement==ElementType::PHYSICAL){
        actionForward(target->atvStats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::BLEED,data2->attacker,target->atvStats->turnCnt + 2));
        constant=2;

    }else if(data2->damageElement==ElementType::FIRE){
        actionForward(target->atvStats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::BURN,data2->attacker,target->atvStats->turnCnt + 2));
        constant=2;

    }else if(data2->damageElement==ElementType::ICE){
        actionForward(target->atvStats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::FREEZE,data2->attacker,target->atvStats->turnCnt + 1));
        constant=1;

    }else if(data2->damageElement==ElementType::LIGHTNING){
        actionForward(target->atvStats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::SHOCK,data2->attacker,target->atvStats->turnCnt + 2));
        constant=1;

    }else if(data2->damageElement==ElementType::WIND){
        actionForward(target->atvStats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::WIND_SHEAR,data2->attacker,target->atvStats->turnCnt + 2,3));
        constant=1.5;

    }else if(data2->damageElement==ElementType::QUANTUM){
        actionForward(target->atvStats.get(),-20*calBreakEffectMultiplier(data2,target));
        target->addBreakSEList(BreakSideEffect(BreakSEType::ENTANGLEMENT,data2->attacker,target->atvStats->turnCnt + 1));
        constant=0.5;

    }else if(data2->damageElement==ElementType::IMAGINARY){
        actionForward(target->atvStats.get(),-30*calBreakEffectMultiplier(data2,target));
        if(target->addBreakSEList(BreakSideEffect(BreakSEType::IMPRISONMENT,data2->attacker,target->atvStats->turnCnt + 1)))
        target->speedBuff({Stats::SPD_P,AType::NONE,-10});
        constant=0.5;
    }

    allEventAfterApplyDebuff(act->attacker,target);    
    
    calBreakDamage(data2,target,constant);
    target->toughnessStatus=0;
    allEventWhenToughnessBreak(data2,target);
    
}
