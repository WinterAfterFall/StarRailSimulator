#include "../include.h"

// One Aha Instant = one action: action-level events fire once around all Elation Skills,
// using the first attack action and/or the first buff action in the bar as representatives
void runAhaInstantBar(){
    if(ahaInstantBar.empty())return;

    shared_ptr<AllyAttackAction> attackRep = nullptr;
    shared_ptr<AllyBuffAction> buffRep = nullptr;
    queue<shared_ptr<AllyActionData>> scan = ahaInstantBar;
    while(!scan.empty() && (!attackRep || !buffRep)){
        shared_ptr<AllyActionData> each = scan.front();
        scan.pop();
        if(!attackRep)attackRep = dynamic_pointer_cast<AllyAttackAction>(each);
        if(!buffRep)buffRep = dynamic_pointer_cast<AllyBuffAction>(each);
    }
    // attack representative is used for the generic action events when both exist
    shared_ptr<AllyActionData> allyRep = attackRep ? static_pointer_cast<AllyActionData>(attackRep) : static_pointer_cast<AllyActionData>(buffRep);
    shared_ptr<ActionData> actionRep = allyRep;

    PhaseStatus beforeStatus = phaseStatus;
    phaseStatus = PhaseStatus::WHILE_ACTION;
    allEventBeforeAction(actionRep);
    allEventBeforeAllyAction(allyRep);
    if(attackRep)allEventBeforeAttackAction(attackRep);

    while(!ahaInstantBar.empty()){
        shared_ptr<AllyActionData> allyActionData = ahaInstantBar.front();
        allyActionData->elationSkillAction();
        ahaInstantBar.pop();
    }

    if(attackRep)allEventAfterAttackAction(attackRep);
    if(buffRep)allEventBuff(buffRep);
    allEventAfterAllyAction(allyRep);
    allEventAfterAction(actionRep);
    phaseStatus = beforeStatus;
}
void ahaTurn(){
    ++(aha->turnCnt);

    beforeAhaInstant();
    
    CharCmd::printText("Aha Instant");
    for(TriggerByYourSelfFunc &e : elationSkillList){
        e.call(e.owner);
    }
    runAhaInstantBar();

    for(auto &each : charList){
        if(each->path == Path::ELATION)buffSingle(each,{{Stats::CERTIFIED_BANGER,AType::NONE,1.0*punchline}},"CB Buff " + to_string(aha->turnCnt),cbDuration);
    }
    cbCheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,punchline});

    genPunchLine(nullptr,-punchline);
    genPunchLine(nullptr,elationCount);
    
    afterAhaInstant();
    
    resetTurn(aha.get());
}
void ahaInstant(int pl){
    ++(aha->turnCnt);
    int oldPL = punchline;
    punchline = pl;

    beforeAhaInstant();

    CharCmd::printText("Aha Instant");
    for(TriggerByYourSelfFunc &e : elationSkillList){
        e.call(e.owner);
    }
    
    runAhaInstantBar();
    for(auto &each : charList){
        if(each->path == Path::ELATION)buffSingle(each,{{Stats::CERTIFIED_BANGER,AType::NONE,1.0*pl}},"CB Buff " + to_string(aha->turnCnt),cbDuration);
    }
    cbCheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,pl});

    punchline = oldPL;

    // after restoring punchline so Punchline gained in the hook (e.g. Hibana E1) is kept
    afterAhaInstant();
}
// Runs only the Elation Skills whose owner name is in names (fixed Punchline PL), no Certified Banger
void elationSkillTrigger(int pl, const vector<string> &names){
    int oldPL = punchline;
    punchline = pl;
    string text = "trigger Elation Skill :";
    for(size_t i = 0; i < names.size(); i++)text += (i ? ", " : " ") + names[i];
    CharCmd::printText(text);
    for(TriggerByYourSelfFunc &e : elationSkillList){
        if(find(names.begin(), names.end(), e.owner->getName()) == names.end())continue;
        e.call(e.owner);
    }
    
    runAhaInstantBar();

    punchline = oldPL;
}
