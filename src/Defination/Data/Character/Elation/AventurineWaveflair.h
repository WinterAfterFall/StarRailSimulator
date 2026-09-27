#include "../include.h"

// Aventurine • Waveflair — kit: docs/kit-reference/Character/Elation/aventurine-waveflair.md (nanoka 4.5.54)
// Simplifications:
//   Fervor thresholds (10 · E1 10/20/30 · E2 +40/50) fire once each while Fervor climbs; All In! spending Fervor re-arms them
//   "after a teammate attacks" = afterAttackActionList of another character (an Aha Instant fires it once for the whole Aha)
//   Elation Skill toughness (user, raw stance ÷ 3): AoE raw 30 / 60 -> 10 / 20 · every bounce raw 1 -> 1/3 (Fervor bounces too)
//   His own Certified Banger (Technique, solo A4) = instances "AvWF CB <n>" lasting cbDuration + 1 (Talent)
namespace AventurineWaveflair{
    constexpr int PARTICIPANT_ID = 156;

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(107,130,130,eidolon,ElementType::QUANTUM,Path::ELATION,"Aventurine Waveflair",UnitType::STANDARD);
        ptr->setAllyBaseStats(1164,485,606);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        elationCount++;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        // his own Certified Banger instances: {buff name, amount}
        shared_ptr<vector<pair<string,double>>> ownCB = make_shared<vector<pair<string,double>>>();

        #pragma region Helper

        // Talent: his Certified Banger lasts 1 turn longer
        function<void(double)> gainCB = [ptr,ownCB](double value) {
            if(value<=0)return;
            ptr->buffNote["AvWF CB Id"] += 1;
            string name = "AvWF CB " + to_string((int)ptr->getBuffNote("AvWF CB Id"));
            buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,value}},name,cbDuration + 1);
            ownCB->push_back({name,value});
        };

        function<bool()> solo = []() {
            return elationCount<=1;
        };

        function<bool()> holdCB = [ptr]() {
            return ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0;
        };

        // free Cheers! with a fixed 20 Punchline · if an Aha Instant bar is still running (Fervor gained inside it),
        // casting now would nest another runAhaInstantBar on the same queue -> park it until the bar is empty
        function<void()> freeCheers = [ptr]() {
            if(!ahaInstantBar.empty()){
                ptr->buffNote["AvWF Pending Cheers"] += 1;
                return;
            }
            ptr->setBuffCheck("AvWF Free Cast",1);
            elationSkillTrigger(20,{ptr->getName()});
            ptr->setBuffCheck("AvWF Free Cast",0);
            ptr->setBuffCheck("AvWF All In Ready",1);
        };

        function<void()> flushCheers = [ptr,freeCheers]() {
            while(ptr->getBuffNote("AvWF Pending Cheers")>0&&ahaInstantBar.empty()){
                ptr->buffNote["AvWF Pending Cheers"] -= 1;
                freeCheers();
            }
        };

        // Talent: Fervor (cap 30, E2 50) · reaching 10 (E1 10/20/30, E2 +40/50) -> free Cheers!
        function<void(double)> addFervor = [ptr,freeCheers](double value) {
            double cap = (ptr->eidolon>=2) ? 50 : 30;
            double before = ptr->getBuffNote("AvWF Fervor");
            double after = min(cap,before + value);
            ptr->setBuffNote("AvWF Fervor",after);

            vector<double> thresholds = {10};
            if(ptr->eidolon>=1)thresholds = {10,20,30};
            if(ptr->eidolon>=2){ thresholds.push_back(40); thresholds.push_back(50); }
            for(double t : thresholds){
                if(!(before<t&&after>=t))continue;
                freeCheers();
            }
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"AvWF BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        // Skill: 240% ATK AoE (toughness 10) · +4 Punchline · +4 Fervor · with CB +40% Elation AoE · resets A6 count · E4 DEF ignore
        function<void()> skill = [ptr,holdCB,addFervor]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"AvWF Skill",
            [ptr,holdCB,addFervor](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                genPunchLine(ptr,4);
                ptr->setBuffNote("AvWF A6 Count",0);
                if(ptr->eidolon>=4)buffAllAlly({{Stats::DEF_SHRED,AType::NONE,18}},"AvWF E4",3);
                attack(act);
                if(holdCB()){
                    shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"AvWF Skill Elation");
                    elDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,40),
                        DmgSrc(DmgSrcType::ELATION,40),
                        DmgSrc(DmgSrcType::ELATION,40)
                    );
                    elDmg->turnReset = 0;
                    attack(elDmg);
                }
                addFervor(4);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,240,10),
                DmgSrc(DmgSrcType::ATK,240,10),
                DmgSrc(DmgSrcType::ATK,240,10)
            );
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,ba,skill]() {
            if(sp>spSafety)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        // Ult: 400% ATK AoE (toughness 20) · +6 Punchline · +8 Fervor · SPD +30% 4 turns · with CB +72% Elation AoE
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [holdCB,addFervor](CharUnit *ptr) {
            CharCmd::printUltStart("Aventurine Waveflair");
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"AvWF Ult",
            [ptr,holdCB,addFervor](shared_ptr<AllyAttackAction> &act){
                genPunchLine(ptr,6);
                buffSingle(ptr,{{Stats::SPD_P,AType::NONE,30}},"AvWF Ult",4);
                attack(act);
                if(holdCB()){
                    shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,"AvWF Ult Elation");
                    elDmg->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,72),
                        DmgSrc(DmgSrcType::ELATION,72),
                        DmgSrc(DmgSrcType::ELATION,72)
                    );
                    elDmg->turnReset = 0;
                    attack(elDmg);
                }
                addFervor(8);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,400,20),
                DmgSrc(DmgSrcType::ATK,400,20),
                DmgSrc(DmgSrcType::ATK,400,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        // Elation Skill: Cheers! = 60% Elation AoE (toughness 10) + 10 × 18% bounces (1/3 each)
        //   All In! = 60% AoE (toughness 20) + 10 × 18% bounces + 1 × 21% bounce per Fervor spent (all Fervor), bounces 1/3 each
        //   All In! when: the Aha Instant cast right after a free Cheers!, or every cast after the 2nd with E6
        //   E6: All In! outside an Aha Instant does not spend Fervor · solo A4: counts as a Follow-Up ATK · E2: +4 Fervor after
        elationSkillList.push_back(TriggerByYourSelfFunc(PARTICIPANT_ID, ptr, [solo,addFervor](CharUnit *ptr) {
            bool freeCast = ptr->getBuffCheck("AvWF Free Cast");
            bool inAha = ptr->getBuffCheck("AvWF In Aha")&&!freeCast;
            bool allIn = (inAha&&ptr->getBuffCheck("AvWF All In Ready"))
                       ||(ptr->eidolon>=6&&ptr->getBuffNote("AvWF Elation Uses")>=2);
            ptr->buffNote["AvWF Elation Uses"] += 1;

            int spent = 0;
            if(allIn){
                if(inAha)ptr->setBuffCheck("AvWF All In Ready",0);
                spent = (int)ptr->getBuffNote("AvWF Fervor");
                if(inAha||ptr->eidolon<6)ptr->setBuffNote("AvWF Fervor",0);
            }

            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,allIn ? "AvWF All In" : "AvWF Cheers",
            [ptr,addFervor](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,5);
                attack(act);
                if(ptr->eidolon>=2)addFervor(4);
            });
            double aoeToughness = allIn ? 20 : 10;
            double bounceToughness = 1.0/3;
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,60,aoeToughness),
                DmgSrc(DmgSrcType::ELATION,60,aoeToughness),
                DmgSrc(DmgSrcType::ELATION,60,aoeToughness)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,18,bounceToughness),10);
            if(spent>0)act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,21,bounceToughness),spent);
            if(solo())act->addAttackType(AType::FUA);
            act->addToAhaInstant();
        }));

        beforeAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setBuffCheck("AvWF In Aha",1);
        }));

        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [solo,flushCheers](CharUnit *ptr) {
            ptr->setBuffCheck("AvWF In Aha",0);
            flushCheers();
            // Talent: his Aha Certified Banger lasts 1 turn longer
            if(!cbCheck.empty())extendBuffTime(ptr,std::get<0>(cbCheck.back()),cbDuration + 1);
            // solo A4: the Aha SPD boost lasts until the Aha Instant ends
            if(solo()&&ahaExtraFlatSpeed!=0){
                ahaExtraFlatSpeed = 0;
                Path path = Path::ELATION;
                ahaSpeedAdjust(path);
            }
        }));

        // Talent: after a teammate attacks -> +1 Fervor, +1 Punchline · solo A4: +2 CB, +1 Punchline, Aha SPD +25
        // whenAttackList fires once per attack action (each Elation Skill inside an Aha Instant too),
        // once per attacker of that action -> count only the first attacker (joint attack = 1)
        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,solo,gainCB,addFervor](shared_ptr<AllyAttackAction> &act) {
            if(act->attacker!=act->attackSetList[0].attacker)return;
            if(act->getChar()==ptr)return;
            genPunchLine(ptr,1);
            if(solo()){
                gainCB(2);
                genPunchLine(ptr,1);
                ahaExtraFlatSpeed += 25;
                Path path = Path::ELATION;
                ahaSpeedAdjust(path);
            }
            addFervor(1);
        }));

        // parked free Cheers! from inside an elationSkillTrigger bar -> cast once that bar has finished
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [flushCheers](shared_ptr<AllyAttackAction> &act) {
            flushCheers();
        }));

        // A6: after a teammate uses Basic / Skill / FuA / Ult -> all allies CD +48% 3 turns, +2 Fervor · 6 times, reset by his Skill
        afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,addFervor](shared_ptr<AllyActionData> &act) {
            if(act->getChar()==ptr)return;
            if(ptr->getBuffNote("AvWF A6 Count")>=6)return;
            bool match = false;
            for(AType each : act->actionTypeList){
                if(each==AType::BA||each==AType::SKILL||each==AType::FUA||each==AType::ULT)match = true;
            }
            if(!match)return;
            ptr->buffNote["AvWF A6 Count"] += 1;
            buffAllAlly({{Stats::CD,AType::NONE,48}},"AvWF A6",3);
            addFervor(2);
        }));

        // Technique: on engage 100% ATK AoE (toughness 20) · +2 Fervor · +20 CB
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainCB,addFervor](CharUnit *ptr) {
            if(!ptr->technique)return;
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"AvWF Technique",
            [ptr,gainCB,addFervor](shared_ptr<AllyAttackAction> &act){
                attack(act);
                addFervor(2);
                gainCB(20);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,20),
                DmgSrc(DmgSrcType::ATK,100,20),
                DmgSrc(DmgSrcType::ATK,100,20)
            );
            act->turnReset = 0;
            act->addToActionBar();
            dealDamage();
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ownCB](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"AvWF A6"))buffSingle(ally,{{Stats::CD,AType::NONE,-48}});
            if(isBuffEnd(ally,"AvWF E4"))buffSingle(ally,{{Stats::DEF_SHRED,AType::NONE,-18}});
            if(!ally->isSameName(ptr))return;
            if(isBuffEnd(ptr,"AvWF Ult"))buffSingle(ptr,{{Stats::SPD_P,AType::NONE,-30}});
            for(auto itr = ownCB->begin(); itr != ownCB->end(); ){
                if(!isBuffEnd(ptr,itr->first)){ itr++; continue; }
                buffSingle(ptr,{{Stats::CERTIFIED_BANGER,AType::NONE,-itr->second}});
                itr = ownCB->erase(itr);
            }
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [ownCB](CharUnit *ptr) {
            ownCB->clear();
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsType[Stats::ELATION][AType::NONE] += 10;
            ptr->atvStats->flatSpeed += 9;

            ptr->statsType[Stats::CD][AType::NONE] += 48; // A6
            if(ptr->eidolon>=1)ptr->statsType[Stats::RESPEN][AType::NONE] += 24;
            if(ptr->eidolon>=6)ptr->statsType[Stats::MERRYMAKE][AType::NONE] += 25;
        }));

        // A4 (with other Elation characters): all allies Elation +20%, his own +80% more, while he is on the field
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [solo](CharUnit *ptr) {
            if(!solo()){
                buffAllAlly({{Stats::ELATION,AType::NONE,20}});
                buffSingle(ptr,{{Stats::ELATION,AType::NONE,80}});
            }
            statsAdjust(ptr,Stats::SPD_P);
        }));

        // A2: SPD >= 140 -> Elation +30%, +1% per SPD above 140 (max 200 excess)
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            if(statsType!=Stats::FLAT_SPD&&statsType!=Stats::SPD_P)return;
            double spd = calculateSpeedOnStats(ptr);
            double buffValue = (spd>=140) ? 30 + min(200.0,spd - 140) : 0;
            buffSingle(ptr,{{Stats::ELATION,AType::NONE,buffValue - ptr->getBuffNote("AvWF A2")}});
            ptr->setBuffNote("AvWF A2",buffValue);
        }));

    }
}
