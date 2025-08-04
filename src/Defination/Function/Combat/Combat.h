#include "../include.h"

void Take_action(){
    
    phaseStatus = PhaseStatus::BeforeTurn;
    After_Turn_Check = 0;
    if(!turn->extraTurn){
        ++(turn->turnCnt);
        allEventBeforeTurn();
    }
    allUltimateCheck();
    
    Print();
    if(Turn_Skip==0){
        
        turn->ptrToChar->Turn_func();  
        
        Deal_damage();
    }
    
    phaseStatus = PhaseStatus::AfterTurn;
    
    
    allUltimateCheck();
    After_Turn_Check = 1;
    
    if(!turn->extraTurn)allEventAfterTurn();

}

void Deal_damage(){
    if(actionBarUse)return;
    actionBarUse = true;
    while(!Action_bar.empty()){
        shared_ptr<ActionData> temp = Action_bar.front();
        phaseStatus = PhaseStatus::WhileAction;
        allEventBeforeAction(temp);
        if (auto allyActionData = dynamic_pointer_cast<AllyActionData>(temp)) {
            allEventWhenAllyAction(allyActionData);
            allyActionData->AllyAction();
        } else if (auto enemyActionData = dynamic_pointer_cast<EnemyActionData>(temp)) {
            enemyActionData->EnemyAction();
        }
        allEventAfterAction(temp);
        if(turn)allUltimateCheck();
        Action_bar.pop();
    }
    actionBarUse = false;
}
void AllyActionData::AllyAction(){
    std::shared_ptr<AllyActionData> self = shared_from_this();
    std::shared_ptr<AllyAttackAction> attackAction = dynamic_pointer_cast<AllyAttackAction>(self);
    std::shared_ptr<AllyBuffAction> buffAction = dynamic_pointer_cast<AllyBuffAction>(self);
    if(attackAction){
        allEventBeforeAttackAction(attackAction);
        
        if(attackAction->actionFunction)attackAction->actionFunction(attackAction);
        else Attack(attackAction);    
        
        for(int i = 0; i < attackAction->AttackSetList.size() ; i++){
            attackAction->Attacker = attackAction->AttackSetList[i].attacker;
            attackAction->actionTypeList = attackAction->AttackSetList[i].actionTypeList;
            attackAction->damageTypeList = attackAction->AttackSetList[i].damageTypeList;
            allEventWhenAttack(attackAction);
        }
        
        attackAction->Attacker = attackAction->AttackSetList[0].attacker;
        attackAction->actionTypeList = attackAction->AttackSetList[0].actionTypeList;
        attackAction->damageTypeList = attackAction->AttackSetList[0].damageTypeList;
        allEventAfterAttackAction(attackAction); 
        if(attackAction->damageNote)Cal_AverageDamage(attackAction->Attacker->ptrToChar,attackAction->targetList); 

    }else{
        if(buffAction->actionFunction)buffAction->actionFunction(buffAction);
        if(buffAction->Turn_reset)resetTurn(turn);
        allEventBuff(buffAction);
    }
    
}
void EnemyActionData::EnemyAction(){
    this->actionFunction();
    resetTurn(turn);
}
void Attack(shared_ptr<AllyAttackAction> &act){


    //32 45
    if(act->Attacker->ptrToChar->canCheckDmgformula()||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;2m";
        cout<<"----------------------------------------- Damage Check -----------------------------------------\n";
        cout << "\033[0m";
    }

    

    int dmgIns = 0;
    for(auto &each : act->AttackSetList){
        each.attacker->hitCount = 0;
    }
    for(auto &each : act->targetList){
        each->hitCount = 0;
    }

    allEventBeforeAttack(act);
    for(int i = 0;i<act->damageSplit.size();i++){
        if(dmgIns!=act->switchAttacker.size()&&act->switchAttacker[dmgIns].changeWhen==i){
            SwitchAtk &SwitchAtk = act->switchAttacker[dmgIns];
            act->Attacker = act->AttackSetList[SwitchAtk.changeTo].attacker;
            if(SwitchAtk.source)act->source = SwitchAtk.source;
            else act->source = act->Attacker;
            act->actionTypeList = act->AttackSetList[SwitchAtk.changeTo].actionTypeList;
            act->damageTypeList = act->AttackSetList[SwitchAtk.changeTo].damageTypeList;
            ++dmgIns;
        }
        act->Attacker->hitCount += act->damageSplit[i].size();
        for(auto &each2 : act->damageSplit[i]){
            each2.target->hitCount++;
        }
        
        allEventBeforeAttackPerHit(act);
        for(auto &each2 : act->damageSplit[i]){
            calDamage(act,each2.target,each2.dmgSrc);
            if(each2.dmgSrc.toughnessReduce>0)
            Cal_Toughness_reduction(act,each2.target,each2.dmgSrc.toughnessReduce);
        }
        allEventAfterAttackPerHit(act);
    }
    allEventAfterAttack(act);


    

    if(act->Attacker->ptrToChar->canCheckDmgformula()||act->Attacker->ptrToChar->checkDamage){
        cout<<"\033[0;38;5;2m";
        cout<<"------------------------------------------------------------------------------------------------\n";  
        cout << "\033[0m";
    }
    
    if(act->Turn_reset)resetTurn(turn);
}
void Skill_point(SubUnit *ptr,int p){
    
    allEventSkillPoint(ptr,p);
    sp+=p;
    if(sp>Max_sp){
        sp = Max_sp;
    }
    return ;
}
void Superbreak_trigger(shared_ptr<AllyAttackAction> &act, double Superbreak_ratio,string triggerName){
    shared_ptr<AllyAttackAction> data_2 = 
    make_shared<AllyAttackAction>(AType::SPB,act->Attacker,act->traceType,act->Attacker->Atv_stats->Unit_Name + " " + triggerName +" SPB");
    
    for(auto &each1 : act->damageSplit){
        for(auto &each2 : each1){
            each2.target->toughnessReduceNote += each2.dmgSrc.toughnessReduce;
        }
    }
    for(int i=1;i<=Total_enemy;i++){
        if(Enemy_unit[i]->Toughness_status==1)continue;
        double toughness_reduce = Enemy_unit[i]->toughnessReduceNote;
        Enemy_unit[i]->toughnessReduceNote = 0;
        if(toughness_reduce==0)continue;
        toughness_reduce = Cal_Total_Toughness_Reduce(act,Enemy_unit[i].get(),toughness_reduce);
        if(Enemy_unit[i]->Current_toughness+toughness_reduce<=0){
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*toughness_reduce/10);
        }else{
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*(-1)*Enemy_unit[i]->Current_toughness/10);
        }
    }
}

void Dot_trigger(double Dot_ratio,Enemy *target,DotType Dot_type){
    
    
    for(auto &each : target->breakDotList) {
        switch (each.type) {
            case BreakSEType::Bleed:
                if (Dot_type == DotType::General|| Dot_type == DotType::Bleed) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::Dot,each.ptr,TraceType::Single, "Break Bleed");
                    act->actionTypeList.push_back(AType::Bleed);
                    Cal_Dot_Toughness_break_damage(act, target, 
                        Dot_ratio * 2 * (0.5 + target->Max_toughness/40));
                }
                break;

            case BreakSEType::Burn:
                if (Dot_type == DotType::General|| Dot_type == DotType::Burn) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::Dot,each.ptr,TraceType::Single, "Break Burn");
                    act->actionTypeList.push_back(AType::Burn);
                    Cal_Dot_Toughness_break_damage(act, target, Dot_ratio * 1);
                }
                break;

            case BreakSEType::Shock:
                if (Dot_type == DotType::General|| Dot_type == DotType::Shock) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::Dot,each.ptr,TraceType::Single, "Break Shock");
                    act->actionTypeList.push_back(AType::Shock);
                    Cal_Dot_Toughness_break_damage(act, target, Dot_ratio * 2);
                }
                break;

            case BreakSEType::WindShear:
                if (Dot_type == DotType::General|| Dot_type == DotType::WindShear) {
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>
                    (AType::Dot,each.ptr,TraceType::Single, "Break WindShear");
                    act->actionTypeList.push_back(AType::WindShear);
                    Cal_Dot_Toughness_break_damage(act, target, 
                        Dot_ratio * 1 * each.stack);
                }
                break;

            default:
                break;
        }
    }
    
    for(TriggerDot_Func &e : Dot_List){
        e.Call(target,Dot_ratio,Dot_type);
    }
    
}
void Toughness_break(shared_ptr<AllyAttackAction> &act,Enemy* target){
    shared_ptr<AllyAttackAction> data_2;
    double Constant = 0;
    if(Force_break)
    data_2 = 
    make_shared<AllyAttackAction>(AType::Break, Ally_unit[Force_break]->Sub_Unit_ptr[0].get(),TraceType::Single,"Break");
    else
    data_2 =
    make_shared<AllyAttackAction>(AType::Break, act->Attacker,TraceType::Single,"Break");
    allEventBeforeApplyDebuff(act->Attacker,target);
    ++target->Total_debuff;
    

    if(SuperBreak__Mode==1){
        target->Atv_stats->atv=target->Atv_stats->Max_atv*0.5;
    }

    if(data_2->Damage_element==ElementType::Physical){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Bleed,data_2->Attacker,target->Atv_stats->turnCnt + 2));
        Constant=2;

    }else if(data_2->Damage_element==ElementType::Fire){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Burn,data_2->Attacker,target->Atv_stats->turnCnt + 2));
        Constant=2;

    }else if(data_2->Damage_element==ElementType::Ice){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Freeze,data_2->Attacker,target->Atv_stats->turnCnt + 1));
        Constant=1;

    }else if(data_2->Damage_element==ElementType::Lightning){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Shock,data_2->Attacker,target->Atv_stats->turnCnt + 2));
        Constant=1;

    }else if(data_2->Damage_element==ElementType::Wind){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::WindShear,data_2->Attacker,target->Atv_stats->turnCnt + 2,3));
        Constant=1.5;

    }else if(data_2->Damage_element==ElementType::Quantum){
        Action_forward(target->Atv_stats.get(),-20*calBreakEffectMultiplier(data_2,target));
        target->addBreakSEList(BreakSideEffect(BreakSEType::Entanglement,data_2->Attacker,target->Atv_stats->turnCnt + 1));
        Constant=0.5;

    }else if(data_2->Damage_element==ElementType::Imaginary){
        Action_forward(target->Atv_stats.get(),-30*calBreakEffectMultiplier(data_2,target));
        if(target->addBreakSEList(BreakSideEffect(BreakSEType::Imprisonment,data_2->Attacker,target->Atv_stats->turnCnt + 1)))
        target->speedBuff({Stats::SPD_P,AType::None,-10});
        Constant=0.5;
    }

    allEventAfterApplyDebuff(act->Attacker,target);    
    
    Cal_Break_damage(data_2,target,Constant);
    target->Toughness_status=0;
    allEventWhenToughnessBreak(data_2,target);
    
}
