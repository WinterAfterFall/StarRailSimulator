#include "../include.h"

double calculateAtkOnStats(AllyUnit *ptr){
    double ans = ptr->baseAtk;
    ans*= (100+ptr->statsType[Stats::ATK_P][AType::NONE])/100.0;
    ans+= ptr->statsType[Stats::FLAT_ATK][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateHpOnStats(AllyUnit *ptr){
    double ans = ptr->baseHp;
    ans*= (100+ptr->statsType[Stats::HP_P][AType::NONE])/100.0;
    ans+= ptr->statsType[Stats::FLAT_HP][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateDefOnStats(AllyUnit *ptr){
    double ans = ptr->baseDef;
    ans*= (100+ptr->statsType[Stats::DEF_P][AType::NONE])/100.0;
    ans+= ptr->statsType[Stats::FLAT_DEF][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateSpeedOnStats(AllyUnit *ptr){
    double ans = ptr->atvStats->baseSpeed;
    ans*= (100 + ptr->atvStats->speedPercent)/100.0;
    ans+= ptr->atvStats->flatSpeed;
    return (ans < 0) ? 0 : ans;
}
double calculateCritrateOnStats(AllyUnit *ptr){
    double ans = ptr->statsType[Stats::CR][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateCritdamOnStats(AllyUnit *ptr){
    double ans = ptr->statsType[Stats::CD][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateBreakEffectOnStats(AllyUnit *ptr){
    double ans = ptr->statsType[Stats::BE][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateElationOnStats(AllyUnit *ptr){
    double ans = ptr->statsType[Stats::ELATION][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateEhrOnStats(AllyUnit *ptr){
    double ans = ptr->statsType[Stats::EHR][AType::NONE];
    return (ans < 0) ? 0 : ans;
}
double calculateHPLost(AllyUnit *ptr){
    double ans = ptr->totalHP - ptr->currentHP;
    return (ans < 0) ? 0 : ans;
}

double calculateAtkForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseAtk;
    ans*= (100+ptr->statsType[Stats::ATK_P][AType::NONE]-ptr->statsType[Stats::ATK_P][AType::TEMP])/100.0;
    ans+= ptr->statsType[Stats::FLAT_ATK][AType::NONE]-ptr->statsType[Stats::FLAT_ATK][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateHpForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseHp;
    ans*= (100+ptr->statsType[Stats::HP_P][AType::NONE]-ptr->statsType[Stats::HP_P][AType::TEMP])/100.0;
    ans+= ptr->statsType[Stats::FLAT_HP][AType::NONE]-ptr->statsType[Stats::FLAT_HP][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateDefForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseDef;
    ans*= (100+ptr->statsType[Stats::DEF_P][AType::NONE]-ptr->statsType[Stats::DEF_P][AType::TEMP])/100.0;
    ans+= ptr->statsType[Stats::FLAT_DEF][AType::NONE]-ptr->statsType[Stats::FLAT_DEF][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateSpeedForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->atvStats->baseSpeed;
    ans*= (100 + ptr->atvStats->speedPercent - ptr->statsType[Stats::SPD_P][AType::TEMP])/100.0;
    ans+= ptr->atvStats->flatSpeed - ptr->statsType[Stats::FLAT_SPD][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;

}
double calculateCritrateForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->statsType[Stats::CR][AType::NONE]-ptr->statsType[Stats::CR][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateCritdamForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->statsType[Stats::CD][AType::NONE]-ptr->statsType[Stats::CD][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateBreakEffectForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->statsType[Stats::BE][AType::NONE]-ptr->statsType[Stats::BE][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateEhrForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->statsType[Stats::EHR][AType::NONE] - ptr->statsType[Stats::EHR][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateElationForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->statsType[Stats::ELATION][AType::NONE] - ptr->statsType[Stats::ELATION][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}

double calAtkMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseAtk;
    double atkPercentMtpr = 100;
    double flatAtkMtpr = 0;
    
    atkPercentMtpr += act->source->statsType[Stats::ATK_P][AType::NONE] + target->statsType[Stats::ATK_P][AType::NONE];
    flatAtkMtpr += act->source->statsType[Stats::FLAT_ATK][AType::NONE] + target->statsType[Stats::FLAT_ATK][AType::NONE];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            atkPercentMtpr+= act->source->statsType[Stats::ATK_P][act->damageTypeList[i]];
            atkPercentMtpr+= target->statsType[Stats::ATK_P][act->damageTypeList[i]];
        
            flatAtkMtpr += act->source->statsType[Stats::FLAT_ATK][act->damageTypeList[i]];
            flatAtkMtpr += target->statsType[Stats::FLAT_ATK][act->damageTypeList[i]];
    }
    
    ans = (ans * atkPercentMtpr/100) + flatAtkMtpr;

    if(act->getChar()->canCheckDmgformulaATK()){
        cout<<"Base  Atk : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseAtk
        <<" Base  Atk% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->statsType[Stats::ATK_P][AType::NONE]
        <<" Base  Flat Atk : "<<setw(7)<<fixed<<setprecision(2)<<act->source->statsType[Stats::FLAT_ATK][AType::NONE]<<endl;
        cout<<"Total Atk : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total Atk% : "<<setw(6)<<fixed<<setprecision(2)<<atkPercentMtpr - 100
        <<" Total Flat Atk : "<<setw(7)<<fixed<<setprecision(2)<<flatAtkMtpr<<endl;
    }

    return (ans < 0) ? 0 : ans;
}
double calHpMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseHp;
    double hpPercentMtpr = 100;
    double flatHpMtpr = 0;

    hpPercentMtpr += act->source->statsType[Stats::HP_P][AType::NONE] + target->statsType[Stats::HP_P][AType::NONE];
    flatHpMtpr += act->source->statsType[Stats::FLAT_HP][AType::NONE] + target->statsType[Stats::FLAT_HP][AType::NONE];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            hpPercentMtpr+= act->source->statsType[Stats::HP_P][act->damageTypeList[i]];
            hpPercentMtpr+= target->statsType[Stats::HP_P][act->damageTypeList[i]];

            flatHpMtpr += act->source->statsType[Stats::FLAT_HP][act->damageTypeList[i]];
            flatHpMtpr += target->statsType[Stats::FLAT_HP][act->damageTypeList[i]];
    }
    
    ans = (ans * hpPercentMtpr/100) + flatHpMtpr;

    if(act->getChar()->canCheckDmgformulaHP()){
        cout<<"Base  Hp  : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseHp
        <<" Base   Hp% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->statsType[Stats::HP_P][AType::NONE]
        <<" Base  Flat  Hp  : "<<setw(7)<<fixed<<setprecision(2)<<act->source->statsType[Stats::FLAT_HP][AType::NONE]<<endl;
        cout<<"Total Hp  : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total  Hp% : "<<setw(6)<<fixed<<setprecision(2)<<hpPercentMtpr - 100
        <<" Total Flat  Hp : "<<setw(7)<<fixed<<setprecision(2)<<flatHpMtpr<<endl;
    }


    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseDef;
    double defPercentMtpr = 100;
    double flatDefMtpr = 0;

    defPercentMtpr += act->source->statsType[Stats::DEF_P][AType::NONE] + target->statsType[Stats::DEF_P][AType::NONE];
    flatDefMtpr += act->source->statsType[Stats::FLAT_DEF][AType::NONE] + target->statsType[Stats::FLAT_DEF][AType::NONE];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            defPercentMtpr+= act->source->statsType[Stats::DEF_P][act->damageTypeList[i]];
            defPercentMtpr+= target->statsType[Stats::DEF_P][act->damageTypeList[i]];

            flatDefMtpr += act->source->statsType[Stats::FLAT_DEF][act->damageTypeList[i]];
            flatDefMtpr += target->statsType[Stats::FLAT_DEF][act->damageTypeList[i]];
    }
    
    ans = (ans * defPercentMtpr/100) + flatDefMtpr;

    if(act->getChar()->canCheckDmgformulaDEF()){
        cout<<"Base  Def : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseDef
        <<" Base  Def% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->statsType[Stats::DEF_P][AType::NONE]
        <<" Base  Flat Def : "<<setw(7)<<fixed<<setprecision(2)<<act->source->statsType[Stats::FLAT_DEF][AType::NONE]<<endl;
        cout<<"Total Def : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total Def% : "<<setw(6)<<fixed<<setprecision(2)<<defPercentMtpr - 100
        <<" Total Flat Def : "<<setw(7)<<fixed<<setprecision(2)<<flatDefMtpr<<endl;
    }

    return (ans < 0) ? 0 : ans;
}
double calBonusDmgMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double bonusDmgMtpr = 100;
    
    bonusDmgMtpr += act->attacker->statsType[Stats::DMG][AType::NONE] + target->statsType[Stats::DMG][AType::NONE] + act->attacker->statsEachElement[Stats::DMG][act->damageElement][AType::NONE] + target->statsEachElement[Stats::DMG][act->damageElement][AType::NONE];
    
    

    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        bonusDmgMtpr += act->attacker->statsType[Stats::DMG][act->damageTypeList[i]] + act->attacker->statsEachElement[Stats::DMG][act->damageElement][act->damageTypeList[i]];
        bonusDmgMtpr += target->statsType[Stats::DMG][act->damageTypeList[i]] + target->statsEachElement[Stats::DMG][act->damageElement][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaDmg()){
        cout<<"Base  Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::DMG][AType::NONE] + act->attacker->statsEachElement[Stats::DMG][act->damageElement][AType::NONE]
        <<" Enemy Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::DMG][AType::NONE] + target->statsEachElement[Stats::DMG][act->damageElement][AType::NONE]
        <<" Total Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<bonusDmgMtpr - 100<<endl;
    }
    return (bonusDmgMtpr / 100 < 0) ? 0 : bonusDmgMtpr / 100;
}
double calCritRateMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double critRateMtpr;

    critRateMtpr = act->attacker->statsType[Stats::CR][AType::NONE] + target->statsType[Stats::CR][AType::NONE];
    for (int i = 0, sz = act->damageTypeList.size(); i < sz; i++) {
        critRateMtpr += act->attacker->statsType[Stats::CR][act->damageTypeList[i]] + target->statsType[Stats::CR][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaCritRate()){
        cout<<"Base  Crit rate : "<<setw(7)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::CR][AType::NONE]
        <<" Total Crit rate : "<<setw(7)<<fixed<<setprecision(2)<<critRateMtpr<<endl;
    }

    return (critRateMtpr < 0) ? 0 : critRateMtpr;
}

double calCritDamMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double critDamMtpr;

    critDamMtpr = act->attacker->statsType[Stats::CD][AType::NONE] + target->statsType[Stats::CD][AType::NONE];
    for (int i = 0, sz = act->damageTypeList.size(); i < sz; i++) {
        critDamMtpr += act->attacker->statsType[Stats::CD][act->damageTypeList[i]] + target->statsType[Stats::CD][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaCritDam()){
        cout<<"Base  Crit dam  : "<<setw(7)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::CD][AType::NONE]
        <<" Total Crit dam  : "<<setw(7)<<fixed<<setprecision(2)<<critDamMtpr<<endl;
    }

    return (critDamMtpr < 0) ? 0 : critDamMtpr;
}
double calCritMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    if(!act->critAble)return 1;

    // รวมสูตร CR/CD ไว้ที่ Cal_Crit_*_multiplier ที่เดียว (เดิมเขียนซ้ำในนี้)
    double critRateMtpr = calCritRateMultiplier(act,target);
    double critDamMtpr  = calCritDamMultiplier(act,target);

    if(critRateMtpr>=100){
        critRateMtpr = 100;
    }
    return max(1.0, 1+(critRateMtpr/100 * critDamMtpr/100));

}
double calDefShredMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double defShredMtpr;
    
    defShredMtpr = act->attacker->statsType[Stats::DEF_SHRED][AType::NONE] + target->statsType[Stats::DEF_SHRED][AType::NONE];
    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            defShredMtpr += act->attacker->statsType[Stats::DEF_SHRED][act->damageTypeList[i]] + target->statsType[Stats::DEF_SHRED][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaDefShred()){
        cout<<"Base  DefShred : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::DEF_SHRED][AType::NONE]
        <<" Enemy DefShred : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::DEF_SHRED][AType::NONE]
        <<" Total DefShred : "<<setw(6)<<fixed<<setprecision(2)<<defShredMtpr
        <<" Final Mtpr : "<<100/(100 + 115*(1-1*defShredMtpr/100))<<endl;
    }

    if(defShredMtpr>=100){
        defShredMtpr = 100;
    }

    return 100/(100 + 115*(1-1*defShredMtpr/100));
}
double calRespenMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double respenMtpr = 100;
    
    respenMtpr += act->attacker->statsType[Stats::RESPEN][AType::NONE] + target->statsType[Stats::RESPEN][AType::NONE] + act->attacker->statsEachElement[Stats::RESPEN][act->damageElement][AType::NONE] + target->statsEachElement[Stats::RESPEN][act->damageElement][AType::NONE];

    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        respenMtpr += act->attacker->statsType[Stats::RESPEN][act->damageTypeList[i]] + act->attacker->statsEachElement[Stats::RESPEN][act->damageElement][act->damageTypeList[i]];
        respenMtpr += target->statsType[Stats::RESPEN][act->damageTypeList[i]] + target->statsEachElement[Stats::RESPEN][act->damageElement][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaRespen()){
        cout<<"Base  Respen   : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::RESPEN][AType::NONE] + act->attacker->statsEachElement[Stats::RESPEN][act->damageElement][AType::NONE]
        <<" Enemy Respen   : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::RESPEN][AType::NONE] + target->statsEachElement[Stats::RESPEN][act->damageElement][AType::NONE]
        <<" Total Respen   : "<<setw(6)<<fixed<<setprecision(2)<<respenMtpr - 100<<endl;
    }

    return (respenMtpr / 100 < 0) ? 0 : respenMtpr / 100;
}
double calVulMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double vulMtpr = 100;
    
    vulMtpr += act->attacker->statsType[Stats::VUL][AType::NONE] + target->statsType[Stats::VUL][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        vulMtpr += act->attacker->statsType[Stats::VUL][act->damageTypeList[i]] + target->statsType[Stats::VUL][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaVul()){
        cout<<"Base  Vul      : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::VUL][AType::NONE]
        <<" Enemy Vul      : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::VUL][AType::NONE]
        <<" Total Vul      : "<<setw(6)<<fixed<<setprecision(2)<<vulMtpr - 100<<endl;
    }

    return (vulMtpr / 100 < 0) ? 0 : vulMtpr / 100;
}
double calBreakEffectMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double breakEffectMtpr = 100;
  
    breakEffectMtpr += act->attacker->statsType[Stats::BE][AType::NONE] + target->statsType[Stats::BE][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        breakEffectMtpr += act->attacker->statsType[Stats::BE][act->damageTypeList[i]] + target->statsType[Stats::BE][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaBE()){
        cout<<"Base  BE       : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::BE][AType::NONE]
        <<" Enemy BE       : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::BE][AType::NONE]
        <<" Total BE       : "<<setw(6)<<fixed<<setprecision(2)<<breakEffectMtpr - 100<<endl;
    }

    return (breakEffectMtpr / 100 < 0) ? 0 : breakEffectMtpr / 100;
}
double calElationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double elationMtpr = 100;
  
    elationMtpr += act->source->statsType[Stats::ELATION][AType::NONE] + target->statsType[Stats::ELATION][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        elationMtpr += act->source->statsType[Stats::ELATION][act->damageTypeList[i]] + target->statsType[Stats::ELATION][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaElation()){
        cout<<"Base  Elation  : "<<setw(6)<<fixed<<setprecision(2)<<act->source->statsType[Stats::ELATION][AType::NONE]
        <<" Enemy Elation  : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::ELATION][AType::NONE]
        <<" Total Elation  : "<<setw(6)<<fixed<<setprecision(2)<<elationMtpr - 100<<endl;
    }

    return (elationMtpr / 100 < 0) ? 0 : elationMtpr / 100;
}
double calMerryMakeMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double merrymakeMtpr = 100;
  
    merrymakeMtpr += act->attacker->statsType[Stats::MERRYMAKE][AType::NONE] + target->statsType[Stats::MERRYMAKE][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        merrymakeMtpr += act->attacker->statsType[Stats::MERRYMAKE][act->damageTypeList[i]] + target->statsType[Stats::MERRYMAKE][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaMM()){
        cout<<"Base  MM       : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::MERRYMAKE][AType::NONE]
        <<" Enemy MM       : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::MERRYMAKE][AType::NONE]
        <<" Total MM       : "<<setw(6)<<fixed<<setprecision(2)<<merrymakeMtpr - 100<<endl;
    }

    return (merrymakeMtpr / 100 < 0) ? 0 : merrymakeMtpr / 100;
}
double calPunchLineMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double punchlineCnt = 0;
    for(auto &each : act->damageTypeList){
        if(each == AType::ELATION_SKILL){
            if(act->getChar()->canCheckDmgformulaPL()){
                cout<<"Total PL        : "<<setw(6)<<fixed<<setprecision(2)<<punchline<<endl;
            }
            return (punchline < 0) ? 1 : (1+(punchline*5)/(240+punchline));
        }
    }

    punchlineCnt += act->attacker->statsType[Stats::CERTIFIED_BANGER][AType::NONE] + target->statsType[Stats::CERTIFIED_BANGER][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        punchlineCnt += act->attacker->statsType[Stats::CERTIFIED_BANGER][act->damageTypeList[i]] + target->statsType[Stats::CERTIFIED_BANGER][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaPL()){
        cout<<"Base  CB       : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::CERTIFIED_BANGER][AType::NONE]
        <<" Enemy CB       : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::CERTIFIED_BANGER][AType::NONE]
        <<" Total CB       : "<<setw(6)<<fixed<<setprecision(2)<<punchlineCnt<<endl;
    }

    return (punchlineCnt < 0) ? 1 : (1+(punchlineCnt*5)/(240+punchlineCnt));
}
double calToughnessMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    if(act->toughnessAvgCalculate||target->toughnessStatus==0){
        return 1;
    }else{
        return 0.9;
    }
}
double calSuperbreakDamageIncreaseMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double spbDmgMtpr = 100;
    spbDmgMtpr += act->attacker->statsType[Stats::SPB_INC][AType::NONE] + target->statsType[Stats::SPB_INC][AType::NONE];
    
    if(act->getChar()->canCheckDmgformulaSpbInc()){
        cout<<"Base  Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::SPB_INC][AType::NONE]
        <<" Enemy Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::SPB_INC][AType::NONE]
        <<" Total Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<spbDmgMtpr - 100<<endl;
    }

    return (spbDmgMtpr / 100 < 0) ? 0 : spbDmgMtpr / 100;
}
double calMitigationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double mitigationMtpr = 100;

    mitigationMtpr += act->attacker->statsType[Stats::MITIGRATION][AType::NONE] + target->statsType[Stats::MITIGRATION][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        mitigationMtpr += act->attacker->statsType[Stats::MITIGRATION][act->damageTypeList[i]] + target->statsType[Stats::MITIGRATION][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaMtgt()){
        cout<<"Base  Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::MITIGRATION][AType::NONE]
        <<" Enemy Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::MITIGRATION][AType::NONE]
        <<" Total Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<mitigationMtpr - 100<<endl;
    }

    return (mitigationMtpr / 100 < 0) ? 0 : mitigationMtpr / 100;
}
double calMultiplierIncrease(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double mtpr = 100;

    mtpr += act->attacker->statsType[Stats::MTPR_INC][AType::NONE] + target->statsType[Stats::MTPR_INC][AType::NONE];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        mtpr += act->attacker->statsType[Stats::MTPR_INC][act->damageTypeList[i]] + target->statsType[Stats::MTPR_INC][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaMtprInc()){
        cout<<"Base  Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<act->attacker->statsType[Stats::MTPR_INC][AType::NONE]
        <<" Enemy Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<target->statsType[Stats::MTPR_INC][AType::NONE]
        <<" Total Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<mtpr - 100<<endl;
    }

    return (mtpr / 100 < 0) ? 0 : mtpr / 100;
}
