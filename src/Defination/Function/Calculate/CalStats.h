#include "../include.h"

double calculateAtkOnStats(AllyUnit *ptr){
    double ans = ptr->baseAtk;
    ans*= (100+ptr->Stats_type[Stats::ATK_P][AType::None])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_ATK][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateHpOnStats(AllyUnit *ptr){
    double ans = ptr->baseHp;
    ans*= (100+ptr->Stats_type[Stats::HP_P][AType::None])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_HP][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateDefOnStats(AllyUnit *ptr){
    double ans = ptr->baseDef;
    ans*= (100+ptr->Stats_type[Stats::DEF_P][AType::None])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_DEF][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateSpeedOnStats(AllyUnit *ptr){
    double ans = ptr->Atv_stats->baseSpeed;
    ans*= (100 + ptr->Atv_stats->speedPercent)/100.0;
    ans+= ptr->Atv_stats->flatSpeed;
    return (ans < 0) ? 0 : ans;
}
double calculateCritrateOnStats(AllyUnit *ptr){
    double ans = ptr->Stats_type[Stats::CR][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateCritdamOnStats(AllyUnit *ptr){
    double ans = ptr->Stats_type[Stats::CD][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateBreakEffectOnStats(AllyUnit *ptr){
    double ans = ptr->Stats_type[Stats::BE][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateEhrOnStats(AllyUnit *ptr){
    double ans = ptr->Stats_type[Stats::EHR][AType::None];
    return (ans < 0) ? 0 : ans;
}
double calculateHPLost(AllyUnit *ptr){
    double ans = ptr->totalHP - ptr->currentHP;
    return (ans < 0) ? 0 : ans;
}

double calculateAtkForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseAtk;
    ans*= (100+ptr->Stats_type[Stats::ATK_P][AType::None]-ptr->Stats_type[Stats::ATK_P][AType::TEMP])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_ATK][AType::None]-ptr->Stats_type[Stats::FLAT_ATK][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateHpForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseHp;
    ans*= (100+ptr->Stats_type[Stats::HP_P][AType::None]-ptr->Stats_type[Stats::HP_P][AType::TEMP])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_HP][AType::None]-ptr->Stats_type[Stats::FLAT_HP][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateDefForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->baseDef;
    ans*= (100+ptr->Stats_type[Stats::DEF_P][AType::None]-ptr->Stats_type[Stats::DEF_P][AType::TEMP])/100.0;
    ans+= ptr->Stats_type[Stats::FLAT_DEF][AType::None]-ptr->Stats_type[Stats::FLAT_DEF][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateSpeedForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Atv_stats->baseSpeed;
    ans*= (100 + ptr->Atv_stats->speedPercent - ptr->Stats_type[Stats::SPD_P][AType::TEMP])/100.0;
    ans+= ptr->Atv_stats->flatSpeed - ptr->Stats_type[Stats::FLAT_SPD][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;

}
double calculateCritrateForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Stats_type[Stats::CR][AType::None]-ptr->Stats_type[Stats::CR][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateCritdamForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Stats_type[Stats::CD][AType::None]-ptr->Stats_type[Stats::CD][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateBreakEffectForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Stats_type[Stats::BE][AType::None]-ptr->Stats_type[Stats::BE][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateEhrForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Stats_type[Stats::EHR][AType::None] - ptr->Stats_type[Stats::EHR][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}
double calculateElationForBuff(AllyUnit *ptr,double ratio){
    double ans = ptr->Stats_type[Stats::Elation][AType::None] - ptr->Stats_type[Stats::Elation][AType::TEMP];
    return (ans * ratio / 100.0 < 0) ? 0 : ans * ratio / 100.0;
}

double calAtkMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseAtk;
    double Atk_percent_mtpr = 100;
    double Flat_atk_mtpr = 0;
    
    Atk_percent_mtpr += act->source->Stats_type[Stats::ATK_P][AType::None] + target->Stats_type[Stats::ATK_P][AType::None];
    Flat_atk_mtpr += act->source->Stats_type[Stats::FLAT_ATK][AType::None] + target->Stats_type[Stats::FLAT_ATK][AType::None];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            Atk_percent_mtpr+= act->source->Stats_type[Stats::ATK_P][act->damageTypeList[i]];
            Atk_percent_mtpr+= target->Stats_type[Stats::ATK_P][act->damageTypeList[i]];
        
            Flat_atk_mtpr += act->source->Stats_type[Stats::FLAT_ATK][act->damageTypeList[i]];
            Flat_atk_mtpr += target->Stats_type[Stats::FLAT_ATK][act->damageTypeList[i]];
    }
    
    ans = (ans * Atk_percent_mtpr/100) + Flat_atk_mtpr;

    if(act->getChar()->canCheckDmgformulaATK()){
        cout<<"Base  Atk : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseAtk
        <<" Base  Atk% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::ATK_P][AType::None]
        <<" Base  Flat Atk : "<<setw(7)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::FLAT_ATK][AType::None]<<endl;
        cout<<"Total Atk : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total Atk% : "<<setw(6)<<fixed<<setprecision(2)<<Atk_percent_mtpr - 100
        <<" Total Flat Atk : "<<setw(7)<<fixed<<setprecision(2)<<Flat_atk_mtpr<<endl;
    }

    return (ans < 0) ? 0 : ans;
}
double calHpMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseHp;
    double Hp_percent_mtpr = 100;
    double Flat_hp_mtpr = 0;

    Hp_percent_mtpr += act->source->Stats_type[Stats::HP_P][AType::None] + target->Stats_type[Stats::HP_P][AType::None];
    Flat_hp_mtpr += act->source->Stats_type[Stats::FLAT_HP][AType::None] + target->Stats_type[Stats::FLAT_HP][AType::None];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            Hp_percent_mtpr+= act->source->Stats_type[Stats::HP_P][act->damageTypeList[i]];
            Hp_percent_mtpr+= target->Stats_type[Stats::HP_P][act->damageTypeList[i]];

            Flat_hp_mtpr += act->source->Stats_type[Stats::FLAT_HP][act->damageTypeList[i]];
            Flat_hp_mtpr += target->Stats_type[Stats::FLAT_HP][act->damageTypeList[i]];
    }
    
    ans = (ans * Hp_percent_mtpr/100) + Flat_hp_mtpr;

    if(act->getChar()->canCheckDmgformulaHP()){
        cout<<"Base  Hp  : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseHp
        <<" Base   Hp% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::HP_P][AType::None]
        <<" Base  Flat  Hp  : "<<setw(7)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::FLAT_HP][AType::None]<<endl;
        cout<<"Total Hp  : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total  Hp% : "<<setw(6)<<fixed<<setprecision(2)<<Hp_percent_mtpr - 100
        <<" Total Flat  Hp : "<<setw(7)<<fixed<<setprecision(2)<<Flat_hp_mtpr<<endl;
    }


    return (ans < 0) ? 0 : ans;
}

double calDefMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double ans = act->source->baseDef;
    double Def_percent_mtpr = 100;
    double Flat_def_mtpr = 0;

    Def_percent_mtpr += act->source->Stats_type[Stats::DEF_P][AType::None] + target->Stats_type[Stats::DEF_P][AType::None];
    Flat_def_mtpr += act->source->Stats_type[Stats::FLAT_DEF][AType::None] + target->Stats_type[Stats::FLAT_DEF][AType::None];

    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            Def_percent_mtpr+= act->source->Stats_type[Stats::DEF_P][act->damageTypeList[i]];
            Def_percent_mtpr+= target->Stats_type[Stats::DEF_P][act->damageTypeList[i]];

            Flat_def_mtpr += act->source->Stats_type[Stats::FLAT_DEF][act->damageTypeList[i]];
            Flat_def_mtpr += target->Stats_type[Stats::FLAT_DEF][act->damageTypeList[i]];
    }
    
    ans = (ans * Def_percent_mtpr/100) + Flat_def_mtpr;

    if(act->getChar()->canCheckDmgformulaDEF()){
        cout<<"Base  Def : "<<setw(7)<<fixed<<setprecision(2)<<act->source->baseDef
        <<" Base  Def% : "<<setw(6)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::DEF_P][AType::None]
        <<" Base  Flat Def : "<<setw(7)<<fixed<<setprecision(2)<<act->source->Stats_type[Stats::FLAT_DEF][AType::None]<<endl;
        cout<<"Total Def : "<<setw(7)<<fixed<<setprecision(2)<<ans
        <<" Total Def% : "<<setw(6)<<fixed<<setprecision(2)<<Def_percent_mtpr - 100
        <<" Total Flat Def : "<<setw(7)<<fixed<<setprecision(2)<<Flat_def_mtpr<<endl;
    }

    return (ans < 0) ? 0 : ans;
}
double calBonusDmgMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Bonus_dmg_mtpr = 100;
    
    Bonus_dmg_mtpr += act->Attacker->Stats_type[Stats::DMG][AType::None] + target->Stats_type[Stats::DMG][AType::None] + act->Attacker->Stats_each_element[Stats::DMG][act->Damage_element][AType::None] + target->Stats_each_element[Stats::DMG][act->Damage_element][AType::None];
    
    

    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        Bonus_dmg_mtpr += act->Attacker->Stats_type[Stats::DMG][act->damageTypeList[i]] + act->Attacker->Stats_each_element[Stats::DMG][act->Damage_element][act->damageTypeList[i]];
        Bonus_dmg_mtpr += target->Stats_type[Stats::DMG][act->damageTypeList[i]] + target->Stats_each_element[Stats::DMG][act->Damage_element][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaDmg()){
        cout<<"Base  Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::DMG][AType::None] + act->Attacker->Stats_each_element[Stats::DMG][act->Damage_element][AType::None]
        <<" Enemy Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::DMG][AType::None] + target->Stats_each_element[Stats::DMG][act->Damage_element][AType::None]
        <<" Total Dmg%     : "<<setw(6)<<fixed<<setprecision(2)<<Bonus_dmg_mtpr - 100<<endl;
    }
    return Bonus_dmg_mtpr / 100;
    // return (Bonus_dmg_mtpr / 100 < 0) ? 0 : Bonus_dmg_mtpr / 100;
}
double calCritMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Crit_rate_mtpr;
    double Crit_dam_mtpr;
    
    if(!act->critAble)return 1;

    Crit_rate_mtpr = act->Attacker->Stats_type[Stats::CR][AType::None] + target->Stats_type[Stats::CR][AType::None];
    Crit_dam_mtpr = act->Attacker->Stats_type[Stats::CD][AType::None] + target->Stats_type[Stats::CD][AType::None];
    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            Crit_rate_mtpr += act->Attacker->Stats_type[Stats::CR][act->damageTypeList[i]] + target->Stats_type[Stats::CR][act->damageTypeList[i]];
            Crit_dam_mtpr += act->Attacker->Stats_type[Stats::CD][act->damageTypeList[i]] + target->Stats_type[Stats::CD][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaCritRate()){
        cout<<"Base  Crit rate : "<<setw(7)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::CR][AType::None]
        <<" Total Crit rate : "<<setw(7)<<fixed<<setprecision(2)<<Crit_rate_mtpr<<endl;
    }
    if(act->getChar()->canCheckDmgformulaCritDam()){
        cout<<"Base  Crit dam  : "<<setw(7)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::CD][AType::None]
        <<" Total Crit dam  : "<<setw(7)<<fixed<<setprecision(2)<<Crit_dam_mtpr<<endl;
    }
    if(Crit_rate_mtpr>=100){
        Crit_rate_mtpr = 100;
    }
    return (1+(Crit_rate_mtpr/100 * Crit_dam_mtpr/100));

}
double Cal_Crit_rate_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double Crit_rate_mtpr;

    Crit_rate_mtpr = act->Attacker->Stats_type[Stats::CR][AType::None] + target->Stats_type[Stats::CR][AType::None];
    for (int i = 0, sz = act->damageTypeList.size(); i < sz; i++) {
        Crit_rate_mtpr += act->Attacker->Stats_type[Stats::CR][act->damageTypeList[i]] + target->Stats_type[Stats::CR][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaCritRate()){
        cout<<"Base  Crit rate : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::CR][AType::None]
        <<" Total Crit rate : "<<setw(6)<<fixed<<setprecision(2)<<Crit_rate_mtpr<<endl;
    }

    return (Crit_rate_mtpr < 0) ? 0 : Crit_rate_mtpr;
}

double Cal_Crit_dam_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target) {
    double Crit_dam_mtpr;

    Crit_dam_mtpr = act->Attacker->Stats_type[Stats::CD][AType::None] + target->Stats_type[Stats::CD][AType::None];
    for (int i = 0, sz = act->damageTypeList.size(); i < sz; i++) {
        Crit_dam_mtpr += act->Attacker->Stats_type[Stats::CD][act->damageTypeList[i]] + target->Stats_type[Stats::CD][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaCritDam()){
        cout<<"Base  Crit dam : "<<setw(7)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::CR][AType::None]
        <<" Total Crit dam : "<<setw(7)<<fixed<<setprecision(2)<<Crit_dam_mtpr<<endl;
    }

    return (Crit_dam_mtpr < 0) ? 0 : Crit_dam_mtpr;
}
double calDefShredMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Def_shred_mtpr;
    
    Def_shred_mtpr = act->Attacker->Stats_type[Stats::DEF_SHRED][AType::None] + target->Stats_type[Stats::DEF_SHRED][AType::None];
    for(int i=0,sz=act->damageTypeList.size();i<sz;i++){
            Def_shred_mtpr += act->Attacker->Stats_type[Stats::DEF_SHRED][act->damageTypeList[i]] + target->Stats_type[Stats::DEF_SHRED][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaDefShred()){
        cout<<"Base  DefShred : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::DEF_SHRED][AType::None]
        <<" Enemy DefShred : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::DEF_SHRED][AType::None]
        <<" Total DefShred : "<<setw(6)<<fixed<<setprecision(2)<<Def_shred_mtpr
        <<" Final Mtpr : "<<100/(100 + 115*(1-1*Def_shred_mtpr/100))<<endl;
    }

    if(Def_shred_mtpr>=100){
        Def_shred_mtpr = 100;
    }

    return 100/(100 + 115*(1-1*Def_shred_mtpr/100));
}
double calRespenMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Respen_mtpr = 100;
    
    Respen_mtpr += act->Attacker->Stats_type[Stats::RESPEN][AType::None] + target->Stats_type[Stats::RESPEN][AType::None] + act->Attacker->Stats_each_element[Stats::RESPEN][act->Damage_element][AType::None] + target->Stats_each_element[Stats::RESPEN][act->Damage_element][AType::None];

    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        Respen_mtpr += act->Attacker->Stats_type[Stats::RESPEN][act->damageTypeList[i]] + act->Attacker->Stats_each_element[Stats::RESPEN][act->Damage_element][act->damageTypeList[i]];
        Respen_mtpr += target->Stats_type[Stats::RESPEN][act->damageTypeList[i]] + target->Stats_each_element[Stats::RESPEN][act->Damage_element][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaRespen()){
        cout<<"Base  Respen   : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::RESPEN][AType::None] + act->Attacker->Stats_each_element[Stats::RESPEN][act->Damage_element][AType::None]
        <<" Enemy Respen   : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::RESPEN][AType::None] + target->Stats_each_element[Stats::RESPEN][act->Damage_element][AType::None]
        <<" Total Respen   : "<<setw(6)<<fixed<<setprecision(2)<<Respen_mtpr - 100<<endl;
    }

    return (Respen_mtpr / 100 < 0) ? 0 : Respen_mtpr / 100;
}
double calVulMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Vul_mtpr = 100;
    
    Vul_mtpr += act->Attacker->Stats_type[Stats::VUL][AType::None] + target->Stats_type[Stats::VUL][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        Vul_mtpr += act->Attacker->Stats_type[Stats::VUL][act->damageTypeList[i]] + target->Stats_type[Stats::VUL][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaVul()){
        cout<<"Base  Vul      : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::VUL][AType::None]
        <<" Enemy Vul      : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::VUL][AType::None]
        <<" Total Vul      : "<<setw(6)<<fixed<<setprecision(2)<<Vul_mtpr - 100<<endl;
    }

    return (Vul_mtpr / 100 < 0) ? 0 : Vul_mtpr / 100;
}
double calBreakEffectMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double BreakEffect_mtpr = 100;
  
    BreakEffect_mtpr += act->Attacker->Stats_type[Stats::BE][AType::None] + target->Stats_type[Stats::BE][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        BreakEffect_mtpr += act->Attacker->Stats_type[Stats::BE][act->damageTypeList[i]] + target->Stats_type[Stats::BE][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaBE()){
        cout<<"Base  BE       : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::BE][AType::None]
        <<" Enemy BE       : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::BE][AType::None]
        <<" Total BE       : "<<setw(6)<<fixed<<setprecision(2)<<BreakEffect_mtpr - 100<<endl;
    }

    return (BreakEffect_mtpr / 100 < 0) ? 0 : BreakEffect_mtpr / 100;
}
double calElationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double elationMtpr = 100;
  
    elationMtpr += act->Attacker->Stats_type[Stats::Elation][AType::None] + target->Stats_type[Stats::Elation][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        elationMtpr += act->Attacker->Stats_type[Stats::Elation][act->damageTypeList[i]] + target->Stats_type[Stats::Elation][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaElation()){
        cout<<"Base  Elation  : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::Elation][AType::None]
        <<" Enemy Elation  : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::Elation][AType::None]
        <<" Total Elation  : "<<setw(6)<<fixed<<setprecision(2)<<elationMtpr - 100<<endl;
    }

    return (elationMtpr / 100 < 0) ? 0 : elationMtpr / 100;
}
double calMerryMakeMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double MerrymakeMtpr = 100;
  
    MerrymakeMtpr += act->Attacker->Stats_type[Stats::Merrymake][AType::None] + target->Stats_type[Stats::Merrymake][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        MerrymakeMtpr += act->Attacker->Stats_type[Stats::Merrymake][act->damageTypeList[i]] + target->Stats_type[Stats::Merrymake][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaMM()){
        cout<<"Base  MM       : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::Merrymake][AType::None]
        <<" Enemy MM       : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::Merrymake][AType::None]
        <<" Total MM       : "<<setw(6)<<fixed<<setprecision(2)<<MerrymakeMtpr - 100<<endl;
    }

    return (MerrymakeMtpr / 100 < 0) ? 0 : MerrymakeMtpr / 100;
}
double calPunchLineMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double PunchlineCnt = 0;
    for(auto &each : act->damageTypeList){
        if(each == AType::ElationSkill){
            if(act->getChar()->canCheckDmgformulaPL()){
                cout<<"Total PL        : "<<setw(6)<<fixed<<setprecision(2)<<punchline<<endl;
            }
            return (punchline < 0) ? 1 : (1+(punchline*5)/(240+punchline));
        }
    }

    PunchlineCnt += act->Attacker->Stats_type[Stats::CertifiedBanger][AType::None] + target->Stats_type[Stats::Merrymake][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        PunchlineCnt += act->Attacker->Stats_type[Stats::CertifiedBanger][act->damageTypeList[i]] + target->Stats_type[Stats::Merrymake][act->damageTypeList[i]];
    }
    
    if(act->getChar()->canCheckDmgformulaPL()){
        cout<<"Base  PL       : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::Merrymake][AType::None]
        <<" Enemy PL       : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::Merrymake][AType::None]
        <<" Total PL       : "<<setw(6)<<fixed<<setprecision(2)<<PunchlineCnt<<endl;
    }

    return (PunchlineCnt < 0) ? 1 : (1+(PunchlineCnt*5)/(240+PunchlineCnt));
}
double calToughnessMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    if(act->toughnessAvgCalculate||target->Toughness_status==0){
        return 1;
    }else{
        return 0.9;
    }
}
double Cal_Superbreak_DamageIncrease_multiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Spb_dmg_mtpr = 100;
    Spb_dmg_mtpr += act->Attacker->Stats_type[Stats::SPB_inc][AType::None] + target->Stats_type[Stats::SPB_inc][AType::None];
    
    if(act->getChar()->canCheckDmgformulaSpbInc()){
        cout<<"Base  Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::SPB_inc][AType::None]
        <<" Enemy Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::SPB_inc][AType::None]
        <<" Total Spb Inc. : "<<setw(6)<<fixed<<setprecision(2)<<Spb_dmg_mtpr - 100<<endl;
    }

    return (Spb_dmg_mtpr / 100 < 0) ? 0 : Spb_dmg_mtpr / 100;
}
double calMitigationMultiplier(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double Mitigation_mtpr = 100;

    Mitigation_mtpr += act->Attacker->Stats_type[Stats::Mitigration][AType::None] + target->Stats_type[Stats::Mitigration][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        Mitigation_mtpr += act->Attacker->Stats_type[Stats::Mitigration][act->damageTypeList[i]] + target->Stats_type[Stats::Mitigration][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaMtgt()){
        cout<<"Base  Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::Mitigration][AType::None]
        <<" Enemy Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::Mitigration][AType::None]
        <<" Total Mtgt     : "<<setw(6)<<fixed<<setprecision(2)<<Mitigation_mtpr - 100<<endl;
    }

    return (Mitigation_mtpr / 100 < 0) ? 0 : Mitigation_mtpr / 100;
}
double calMultiplierIncrease(shared_ptr<AllyAttackAction> &act,Enemy *target){
    double mtpr = 100;

    mtpr += act->Attacker->Stats_type[Stats::MtprInc][AType::None] + target->Stats_type[Stats::MtprInc][AType::None];
    for(int i = 0, sz = act->damageTypeList.size(); i < sz; i++){
        mtpr += act->Attacker->Stats_type[Stats::MtprInc][act->damageTypeList[i]] + target->Stats_type[Stats::MtprInc][act->damageTypeList[i]];
    }

    if(act->getChar()->canCheckDmgformulaMtprInc()){
        cout<<"Base  Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<act->Attacker->Stats_type[Stats::MtprInc][AType::None]
        <<" Enemy Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<target->Stats_type[Stats::MtprInc][AType::None]
        <<" Total Mtpr     : "<<setw(6)<<fixed<<setprecision(2)<<mtpr - 100<<endl;
    }

    return (mtpr / 100 < 0) ? 0 : mtpr / 100;
}