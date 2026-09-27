#include "../include.h"

// One Aha Instant = one action: action-level events fire once around all Elation Skills,
// using the first attack action and/or the first buff action in the bar as representatives
void runAhaInstantBar(){
    if(AhaInstantBar.empty())return;

    shared_ptr<AllyAttackAction> attackRep = nullptr;
    shared_ptr<AllyBuffAction> buffRep = nullptr;
    queue<shared_ptr<AllyActionData>> scan = AhaInstantBar;
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
    phaseStatus = PhaseStatus::WhileAction;
    allEventBeforeAction(actionRep);
    allEventBeforeAllyAction(allyRep);
    if(attackRep)allEventBeforeAttackAction(attackRep);

    while(!AhaInstantBar.empty()){
        shared_ptr<AllyActionData> allyActionData = AhaInstantBar.front();
        allyActionData->ElationSkillAction();
        AhaInstantBar.pop();
    }

    if(attackRep)allEventAfterAttackAction(attackRep);
    if(buffRep)allEventBuff(buffRep);
    allEventAfterAllyAction(allyRep);
    allEventAfterAction(actionRep);
    phaseStatus = beforeStatus;
}
void AhaTurn(){
    ++(aha->turnCnt);

    BeforeAhaInstant();
    
    CharCmd::printText("Aha Instant");
    for(TriggerByYourSelf_Func &e : ElationSkill_List){
        e.Call(e.owner);
    }
    runAhaInstantBar();

    for(auto &each : charList){
        if(each->path == Path::Elation)buffSingle(each,{{Stats::CertifiedBanger,AType::None,1.0*punchline}},"CB Buff " + to_string(aha->turnCnt),CB_duration);
    }
    CBcheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,punchline});

    genPunchLine(nullptr,-punchline);
    genPunchLine(nullptr,elationCount);
    
    AfterAhaInstant();
    
    resetTurn(aha.get());
}
void AhaInstant(int PL){
    ++(aha->turnCnt);
    int oldPL = punchline;
    punchline = PL;

    BeforeAhaInstant();

    CharCmd::printText("Aha Instant");
    for(TriggerByYourSelf_Func &e : ElationSkill_List){
        e.Call(e.owner);
    }
    
    runAhaInstantBar();
    for(auto &each : charList){
        if(each->path == Path::Elation)buffSingle(each,{{Stats::CertifiedBanger,AType::None,1.0*PL}},"CB Buff " + to_string(aha->turnCnt),CB_duration);
    }
    CBcheck.push_back({"CB Buff " + to_string(aha->turnCnt),elationCount,PL});

    punchline = oldPL;

    // after restoring punchline so Punchline gained in the hook (e.g. Hibana E1) is kept
    AfterAhaInstant();
}
// Runs only the Elation Skills whose owner name is in names (fixed Punchline PL), no Certified Banger
void ElationSkillTrigger(int PL, const vector<string> &names){
    int oldPL = punchline;
    punchline = PL;
    string text = "trigger Elation Skill :";
    for(size_t i = 0; i < names.size(); i++)text += (i ? ", " : " ") + names[i];
    CharCmd::printText(text);
    for(TriggerByYourSelf_Func &e : ElationSkill_List){
        if(find(names.begin(), names.end(), e.owner->getName()) == names.end())continue;
        e.Call(e.owner);
    }
    
    runAhaInstantBar();

    punchline = oldPL;
}
