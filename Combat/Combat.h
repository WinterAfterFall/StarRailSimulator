#ifndef COMBAT_H
#define COMBAT_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


void Take_action(){
    
    ++(turn->turn_cnt);
    Ult_After_Turn = 0;
    After_Turn_Check = 0;
    allEventBeforeTurn();
    allUltimateCheck();
    
    Print();
    if(Turn_Skip==0){
        
        turn->ptrToChar->Turn_func();  
        
        Deal_damage();
        
        
    }
    
    Ult_After_Turn = 1;
    
    
    allUltimateCheck();
    After_Turn_Check = 1;
    
    allEventAfterTurn();
    

}

void Deal_damage(){
    if(actionBarUse)return;
    actionBarUse = true;
    while(!Action_bar.empty()){
        shared_ptr<ActionData> temp = Action_bar.front();
        allEventBeforeAction(temp);
        if (auto allyActionData = dynamic_pointer_cast<AllyActionData>(temp)) {
            allyActionData->AllyAction();
        } else if (auto enemyActionData = dynamic_pointer_cast<EnemyActionData>(temp)) {
            enemyActionData->EnemyAction();
        }
        allEventAfterAction(temp);
        Action_bar.pop();
    }
    actionBarUse = false;
}
void AllyActionData::AllyAction(){
    std::shared_ptr<AllyActionData> self = shared_from_this();
    std::shared_ptr<AllyAttackAction> attackAction = dynamic_pointer_cast<AllyAttackAction>(self);
    std::shared_ptr<AllyBuffAction> buffAction = dynamic_pointer_cast<AllyBuffAction>(self);
    if(attackAction){
        allEventBeforeAttack(attackAction);
        
        if(attackAction->actionFunction)attackAction->actionFunction(attackAction);
        else Attack(attackAction);    
        
        for(int i = 0; i < attackAction->attackerList.size() ; i++){
            attackAction->Attacker = attackAction->attackerList[i];
            allEventWhenAttack(attackAction);
        }
        
        this->Attacker = attackAction->attackerList[0];
        allEventAfterAttack(attackAction); 
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
void Attack(shared_ptr<AllyAttackAction> &data_){
    int dmgIns = 0;
    for(auto &each : data_->attackerList){
        each->hitCount = 0;
    }
    for(auto &each : data_->targetList){
        each->hitCount = 0;
    }
    for(int i = 0;i<data_->damageSplit.size();i++){
        if(dmgIns!=data_->switchAttacker.size()&&data_->switchAttacker[dmgIns].changeWhen==i){
            data_->Attacker = data_->switchAttacker[dmgIns].attacker;
            data_->source = data_->switchAttacker[dmgIns].source;
            if(data_->switchAttacker[dmgIns].changeSkillType>=0)
                data_->abilityTypeList = data_->AbilitySetList[data_->switchAttacker[dmgIns].changeSkillType];
            ++dmgIns;
        }
        data_->Attacker->hitCount += data_->damageSplit[i].size();
        for(auto &each2 : data_->damageSplit[i]){
            each2.target->hitCount++;
        }
        allEventAttackHitCount(data_);

        for(auto &each2 : data_->damageSplit[i]){
            Cal_Damage(data_,each2.target,each2.dmgSrc);
            Cal_Toughness_reduction(data_,each2.target,each2.dmgSrc.toughnessReduce);
        }
    }
        
    if(data_->Turn_reset)resetTurn(turn);
}
void Skill_point(SubUnit *ptr,int p){
    
    allEventSkillPoint(ptr,p);
    sp+=p;
    if(sp>Max_sp){
        sp = Max_sp;
    }
    return ;
}
void Superbreak_trigger(shared_ptr<AllyAttackAction> &data_, double Superbreak_ratio,string triggerName){
    shared_ptr<AllyAttackAction> data_2 = 
    make_shared<AllyAttackAction>(ActionType::SPB,data_->Attacker,data_->traceType,data_->Attacker->Atv_stats->Unit_Name + " " + triggerName +" SPB");
    
    for(auto &each1 : data_->damageSplit){
        for(auto &each2 : each1){
            each2.target->toughnessReduceNote += each2.dmgSrc.toughnessReduce;
        }
    }
    for(int i=1;i<=Total_enemy;i++){
        if(Enemy_unit[i]->Toughness_status==1)continue;
        double toughness_reduce = Enemy_unit[i]->toughnessReduceNote;
        Enemy_unit[i]->toughnessReduceNote = 0;
        if(toughness_reduce==0)continue;
        toughness_reduce = Cal_Total_Toughness_Reduce(data_,Enemy_unit[i].get(),toughness_reduce);
        if(Enemy_unit[i]->Current_toughness+toughness_reduce<=0){
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*toughness_reduce/10);
        }else{
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*(-1)*Enemy_unit[i]->Current_toughness/10);
        }
    }
}
void Dot_trigger(double Dot_ratio,Enemy *target,string Dot_type){
    
    for(auto &each : target->breakDotList) {
        switch (each.type) {
            case BreakSEType::Bleed:
                if (Dot_type == AT_NONE || Dot_type == "Physical") {
                    shared_ptr<AllyAttackAction> data_ = 
                    make_shared<AllyAttackAction>
                    (ActionType::Dot,each.ptr,TT_SINGLE, "Bleed");
                    data_->abilityTypeList.push_back("Bleed");
                    Cal_Dot_Toughness_break_damage(data_, target, 
                        Dot_ratio * 2 * (0.5 + target->Max_toughness/40));
                }
                break;

            case BreakSEType::Burn:
                if (Dot_type == AT_NONE || Dot_type == "Fire") {
                    shared_ptr<AllyAttackAction> data_ = 
                    make_shared<AllyAttackAction>
                    (ActionType::Dot,each.ptr,TT_SINGLE, "Burn");
                    data_->abilityTypeList.push_back("Burn");
                    Cal_Dot_Toughness_break_damage(data_, target, Dot_ratio * 1);
                }
                break;

            case BreakSEType::Shock:
                if (Dot_type == AT_NONE || Dot_type == "Lightning") {
                    shared_ptr<AllyAttackAction> data_ = 
                    make_shared<AllyAttackAction>
                    (ActionType::Dot,each.ptr,TT_SINGLE, "Shock");
                    data_->abilityTypeList.push_back("Shock");
                    Cal_Dot_Toughness_break_damage(data_, target, Dot_ratio * 2);
                }
                break;

            case BreakSEType::WindShear:
                if (Dot_type == AT_NONE || Dot_type == "Wind") {
                    shared_ptr<AllyAttackAction> data_ = 
                    make_shared<AllyAttackAction>
                    (ActionType::Dot,each.ptr,TT_SINGLE, "WindShear");
                    data_->abilityTypeList.push_back("WindShear");
                    Cal_Dot_Toughness_break_damage(data_, target, 
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
void dotDamage(shared_ptr<AllyAttackAction> &data_,double Dot_ratio){
    for(auto &each : data_->attackerList){
        each->hitCount = 0;
    }
    for(auto &each : data_->targetList){
        each->hitCount = 0;
    }
    for(int i = 0;i<data_->damageSplit.size();i++){
        data_->Attacker->hitCount += data_->damageSplit[i].size();
        for(auto &each2 : data_->damageSplit[i]){
            each2.target->hitCount++;
        }
        allEventAttackHitCount(data_);
        for(auto &each2 : data_->damageSplit[i]){
            Cal_Damage(data_,each2.target,each2.dmgSrc);
        }
    }
}
void Toughness_break(shared_ptr<AllyActionData> &data_,Enemy* target){
    shared_ptr<AllyAttackAction> data_2;
    double Constant = 0;
    if(Force_break)
    data_2 = 
    make_shared<AllyAttackAction>(ActionType::Break, Ally_unit[Force_break]->Sub_Unit_ptr[0].get(),TT_SINGLE,"Break");
    else
    data_2 =
    make_shared<AllyAttackAction>(ActionType::Break, data_->Attacker,TT_SINGLE,"Break");
    ++target->Total_debuff;
    allEventApplyDebuff(data_->Attacker,target);
    

    if(SuperBreak__Mode==1){
        target->Atv_stats->atv=target->Atv_stats->Max_atv*0.5;
    }

    if(data_2->Damage_element=="Physical"){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Bleed,data_2->Attacker,target->Atv_stats->turn_cnt + 2));
        Constant=2;

    }else if(data_2->Damage_element=="Fire"){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Burn,data_2->Attacker,target->Atv_stats->turn_cnt + 2));
        Constant=2;

    }else if(data_2->Damage_element=="Ice"){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Freeze,data_2->Attacker,target->Atv_stats->turn_cnt + 1));
        Constant=1;

    }else if(data_2->Damage_element=="Lightning"){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::Shock,data_2->Attacker,target->Atv_stats->turn_cnt + 2));
        Constant=1;

    }else if(data_2->Damage_element=="Wind"){
        Action_forward(target->Atv_stats.get(),-25);
        target->addBreakSEList(BreakSideEffect(BreakSEType::WindShear,data_2->Attacker,target->Atv_stats->turn_cnt + 2,3));
        Constant=1.5;

    }else if(data_2->Damage_element=="Quantum"){
        Action_forward(target->Atv_stats.get(),-20*Cal_BreakEffect_multiplier(data_2,target));
        target->addBreakSEList(BreakSideEffect(BreakSEType::Entanglement,data_2->Attacker,target->Atv_stats->turn_cnt + 1));
        Constant=0.5;

    }else if(data_2->Damage_element=="Imaginary"){
        Action_forward(target->Atv_stats.get(),-30*Cal_BreakEffect_multiplier(data_2,target));
        if(target->addBreakSEList(BreakSideEffect(BreakSEType::Imprisonment,data_2->Attacker,target->Atv_stats->turn_cnt + 1)))
        target->speedBuff({ST_SPD,ST_SPD_P,-10});
        Constant=0.5;
    }
        
    
    Cal_Break_damage(data_2,target,Constant);
    target->Toughness_status=0;
    allEventWhenToughnessBreak(data_2,target);
    
}
#endif