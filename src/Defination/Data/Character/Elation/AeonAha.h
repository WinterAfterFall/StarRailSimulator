#include "../include.h"

// Aeon ★ Aha — kit: hsr.nanoka.cc/character/1511 + hsr.gachabase.net (4.6.54 BETA)
// Two different units: "Aeon Aha" (this character) and "Aha" (the engine's Aha entity, global `aha`)
// Ult / Technique / E6 / Exclusive act on the Aha entity, not on Aeon Aha
// Simplifications:
//   Wishpower = buffNote "AeonAha Wishpower" (cap 10, Ult at 8) · she has no Energy (maxEnergy 0)
//   Ult cost is paid when the Ult is queued (like Energy in ultUseCheck)
//   Emanator = chooseCharacterBuff (not herself -> first other character)
//   A2 extra 20% Elation DMG: attacked by Aeon Aha in the Emanator's element, inside the same FuA action
//   (switchAttacker element change) -> not an extra attack (user 2026-11-03)
//   A4: heals only (the sim has no shield event)
//   Elation Debt: the sim does not track enemy HP -> modeled as Enemy::elationDebt (% Max HP), every DMG x 100/(100 - debt)
//   (calDamageNote) · set once at battle start as a flat multiplier (user 2026-11-04):
//   E0-E5 x 200/190 (debt 5%) · E6 x 200/150 (debt 25%)
//   E3 / E5 not modeled (5★ base levels)
//   Faces of Elation = global ahaAscension (+ ahaAscensionE2) · Party Trick / Bliss = CB / Punchline gained while it is on
//   the Innate Traces live in each Elation character's own file
namespace AeonAha{
    constexpr int PARTICIPANT_ID = 1000; // highest -> always last in the Aha Instant (elationSkillList runs lowest ID first)
    const string EMANATOR = "AeonAha Emanator";

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(AEON_AHA_BASE_SPD,0,0,eidolon,ElementType::QUANTUM,Path::ELATION,"Aeon Aha",UnitType::STANDARD);
        ptr->setAllyBaseStats(1048,679,509);

        //substats
        ptr->setSpeedRequire(150); // A6 top tier: Elation +150%
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);

        elationCount++;
        aeonAha = ptr;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        // Global Passive: Aha Instant base SPD 80 -> Aeon Aha's base SPD (after the LC: her signature adds base SPD)
        aha->setBaseSpeed(ptr->atvStats->baseSpeed);

        #pragma region Helper

        function<void(double)> gainWishpower = [ptr](double value) {
            ptr->setBuffNote("AeonAha Wishpower",min(10.0,ptr->getBuffNote("AeonAha Wishpower") + value));
        };

        // Skill: Emanator lasts all fight until moved · Elation +20%
        function<void(CharUnit*)> setEmanator = [ptr](CharUnit *target) {
            AllyUnit *old = ptr->getBuffSubUnitTarget(EMANATOR);
            if(old==target)return;
            if(old)buffSingle(old,{{Stats::ELATION,AType::NONE,-20}});
            ptr->setBuffSubUnitTarget(EMANATOR,target);
            if(target)buffSingle(target,{{Stats::ELATION,AType::NONE,20}});
        };

        // E4: her Elation DMG also counts 100% of the teammates' total CB -> CB on her ELATION_DMG axis while her hit lands
        // (her Elation Skill counts Punchline, not CB -> not affected)
        function<void(shared_ptr<AllyAttackAction> &)> attackElation = [ptr](shared_ptr<AllyAttackAction> &act) {
            double extra = 0;
            if(ptr->eidolon>=4){
                for(auto &each : charList){
                    if(each==ptr)continue;
                    extra += max(0.0,each->statsType[Stats::CERTIFIED_BANGER][AType::NONE]);
                }
            }
            ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] += extra;
            attack(act);
            ptr->statsType[Stats::CERTIFIED_BANGER][AType::ELATION_DMG] -= extra;
        };

        // Faces of Elation: 3 turns (counted down at the start of her turn) · self CR +12% / DEF ignore 30% (E2 20% / 60%)
        // starting it again only refreshes the duration
        function<void()> startFaces = [ptr]() {
            ptr->setBuffNote("AeonAha Faces Turns",3);
            if(ahaAscension)return;
            ahaAscension = true;
            ahaAscensionE2 = ptr->eidolon>=2;
            double cr = (ptr->eidolon>=2) ? 20 : 12;
            double shred = (ptr->eidolon>=2) ? 60 : 30;
            buffSingle(ptr,{
                {Stats::CR,AType::NONE,cr},
                {Stats::DEF_SHRED,AType::NONE,shred}
            });
            ptr->setBuffNote("AeonAha Faces CR",cr);
            ptr->setBuffNote("AeonAha Faces Shred",shred);
            for(TriggerByYourSelfFunc &e : ahaAscensionStartList)e.call(e.owner);
        };

        function<void()> endFaces = [ptr]() {
            if(!ahaAscension)return;
            ahaAscension = false;
            buffSingle(ptr,{
                {Stats::CR,AType::NONE,-ptr->getBuffNote("AeonAha Faces CR")},
                {Stats::DEF_SHRED,AType::NONE,-ptr->getBuffNote("AeonAha Faces Shred")}
            });
            ptr->setBuffNote("AeonAha Faces CR",0);
            ptr->setBuffNote("AeonAha Faces Shred",0);
            for(TriggerByYourSelfFunc &e : ahaAscensionEndList)e.call(e.owner);
            ahaAscensionE2 = false; // after the end hooks, they may still read it
            CharCmd::printUltEnd("Aeon Aha");
        };

        #pragma endregion

        #pragma region Ability

        // BA: 50% Quantum Elation DMG single (toughness 10) · SP +1 · Wishpower +1
        function<void()> ba = [ptr,gainWishpower,attackElation]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"AeonAha BA",
            [ptr,gainWishpower,attackElation](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                attackElation(act);
                gainWishpower(1);
            });
            act->addDamageType(AType::ELATION_DMG);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,50,10)
            );
            act->addToActionBar();
        };

        // Skill: SP -1 · 1 other ally becomes the Emanator · Wishpower +1
        // then a FuA: 50% Quantum Elation AoE (toughness 10)
        //   + A2: 20% Elation in the Emanator's element on every enemy the FuA hit (same action -> not an extra attack) · SP +1
        function<void()> skill = [ptr,gainWishpower,setEmanator,attackElation]() {
            CharUnit *target = chooseCharacterBuff(ptr);
            if(target==ptr)target = nullptr;
            if(!target){
                for(auto &each : charList){
                    if(each==ptr)continue;
                    target = each;
                    break;
                }
            }
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"AeonAha Skill",
            [ptr,target,gainWishpower,setEmanator,attackElation](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                setEmanator(target);
                gainWishpower(1);

                shared_ptr<AllyAttackAction> fua =
                make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"AeonAha Skill FuA",
                [ptr,attackElation](shared_ptr<AllyAttackAction> &fua){
                    attackElation(fua);
                    fua->damageElement = ptr->elementType; // the A2 row switched it to the Emanator's element
                    genSkillPoint(ptr,1); // A2
                });
                fua->addDamageType(AType::ELATION_DMG);
                fua->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,50,10),
                    DmgSrc(DmgSrcType::ELATION,50,10),
                    DmgSrc(DmgSrcType::ELATION,50,10)
                );
                if(target){
                    fua->addDamageIns(
                        DmgSrc(DmgSrcType::ELATION,20),
                        DmgSrc(DmgSrcType::ELATION,20),
                        DmgSrc(DmgSrcType::ELATION,20)
                    );
                    // row 1 = A2: same attacker / types (attackSetList[0]), element -> Emanator's
                    fua->switchAttacker.push_back(SwitchAtk(0,1,target->elementType));
                }
                fua->addToActionBar();
            });
            if(target)act->addBuffSingleTarget(target);
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ba,skill]() {
            // Skill nets 0 SP (A2 gives it back) and hits harder -> cast it whenever 1 SP is there
            if(sp>0)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return ptr->getBuffNote("AeonAha Wishpower")>=8;
        });

        // Ult: Aha advance 20% · 200% Quantum Elation AoE (toughness 20) + 5 × 60% bounces (toughness 5)
        //   then Faces of Elation for 3 turns · resets the A4 quota
        //   E6: first Ult of the fight -> Aha advance 100% + 100 Punchline
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [startFaces,attackElation](CharUnit *ptr) {
            ptr->buffNote["AeonAha Wishpower"] -= 8;
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"AeonAha Ult",
            [ptr,startFaces,attackElation](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Aeon Aha");
                actionForward(aha.get(),20);
                if(ptr->eidolon>=6&&!ptr->getBuffCheck("AeonAha E6 Used")){
                    ptr->setBuffCheck("AeonAha E6 Used",1);
                    actionForward(aha.get(),100);
                    genPunchLine(ptr,100);
                }
                attackElation(act);
                ptr->setBuffCheck("AeonAha A4 Used",0);
                startFaces();
            });
            act->addDamageType(AType::ELATION_DMG);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,200,20),
                DmgSrc(DmgSrcType::ELATION,200,20),
                DmgSrc(DmgSrcType::ELATION,200,20)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,60,5),5);
            act->addToActionBar();
            dealDamage();
        }));

        // Elation Skill (always last): 60% Quantum Elation AoE (toughness 10) · Wishpower +1
        //   + True DMG = 20% (E4 25%) of all non-True DMG allies dealt in this Aha Instant, split equally among enemies
        //   cast outside an Aha Instant (e.g. EMC Ult) -> only this cast's own DMG is counted
        //   EMC Innate Trace: ahaTrueDmgOverride replaces the tally once
        elationSkillList.push_back(TriggerByYourSelfFunc(PARTICIPANT_ID, ptr, [gainWishpower](CharUnit *ptr) {
            bool outside = !ptr->getBuffCheck("AeonAha In Aha");
            if(outside){
                ptr->setBuffNote("AeonAha Tally",0);
                ptr->setBuffCheck("AeonAha Tally On",1);
            }
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,"AeonAha Elation Skill",
            [ptr,outside,gainWishpower](shared_ptr<AllyAttackAction> &act){
                attack(act);
                gainWishpower(1);

                double base = ptr->getBuffNote("AeonAha Tally");
                if(ahaTrueDmgOverride>=0){
                    base = ahaTrueDmgOverride;
                    ahaTrueDmgOverride = -1;
                }
                if(outside)ptr->setBuffCheck("AeonAha Tally On",0);

                double ratio = (ptr->eidolon>=4) ? 25 : 20;
                vector<Enemy*> targets;
                for(int i = 1; i <= totalEnemy; i++){
                    if(enemyUnit[i]->isTargetable())targets.push_back(enemyUnit[i].get());
                }
                for(Enemy *each : targets){
                    calDamageNote(act,each,each,base,ratio/targets.size(),"AeonAha True DMG");
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,60,10),
                DmgSrc(DmgSrcType::ELATION,60,10),
                DmgSrc(DmgSrcType::ELATION,60,10)
            );
            act->addToAhaInstant();
        }));

        // True DMG tally: every DMG an ally deals while recording (True DMG goes through calDamageNote only -> never counted)
        afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr]
            (shared_ptr<AllyAttackAction> &act,Enemy *target,double damage) {
                if(!ptr->getBuffCheck("AeonAha Tally On"))return;
                ptr->buffNote["AeonAha Tally"] += damage;
        }));

        beforeAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setBuffCheck("AeonAha In Aha",1);
            ptr->setBuffNote("AeonAha Tally",0);
            ptr->setBuffCheck("AeonAha Tally On",1);
        }));

        // Aha's own turn (turn == aha): re-arm the Talent · Faces: Bliss -> regain 10% of the Punchline it consumed
        // fixed-Punchline Aha Instants (Technique, Yao Guang Ult) consume nothing
        afterAhaInstantList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->setBuffCheck("AeonAha In Aha",0);
            ptr->setBuffCheck("AeonAha Tally On",0);
            if(turn!=aha.get())return;
            ptr->setBuffCheck("AeonAha Talent Used",0);
            if(!ahaAscension||cbCheck.empty())return;
            double used = std::get<2>(cbCheck.back());
            genPunchLine(ptr,(int)floor(used*0.1));
        }));

        // Talent: first time Punchline reaches 40 -> Wishpower +1 · all allies CD +40% 3 turns (again after Aha's turn)
        punchLineList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr,gainWishpower](AllyUnit *spMaker, int spChange) {
            if(spChange<=0||ptr->getBuffCheck("AeonAha Talent Used"))return;
            if(punchline + spChange<40)return; // the event fires before Punchline changes
            ptr->setBuffCheck("AeonAha Talent Used",1);
            gainWishpower(1);
            buffAllAlly({{Stats::CD,AType::NONE,40}},"AeonAha Talent",3);
        }));

        // Skill: Emanator's turn starts -> Wishpower +1 · her own turn starts -> Faces counts down
        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainWishpower,endFaces](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            AllyUnit *em = ptr->getBuffSubUnitTarget(EMANATOR);
            if(em&&ally==em)gainWishpower(1);
            if(ally==ptr&&ahaAscension){
                ptr->buffNote["AeonAha Faces Turns"] -= 1;
                if(ptr->getBuffNote("AeonAha Faces Turns")<=0)endFaces();
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"AeonAha Talent"))buffSingle(ally,{{Stats::CD,AType::NONE,-40}});
        }));

        // A4: healed by a teammate -> Wishpower +1, once until her next Ult
        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,gainWishpower](AllyUnit *healer, AllyUnit *target, double value) {
            if(target!=ptr||!healer||healer->owner==ptr)return;
            if(ptr->getBuffCheck("AeonAha A4 Used"))return;
            ptr->setBuffCheck("AeonAha A4 Used",1);
            gainWishpower(1);
        }));

        // A6: advance 30% at battle start · E1: Wishpower +5 · Technique: Aha extra turn with a fixed 20 Punchline
        // Elation Debt: E0-E5 x 200/190 (debt 5%), E6 x 200/150 (debt 25%) on every enemy from the start
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainWishpower](CharUnit *ptr) {
            double debt = (ptr->eidolon>=6) ? 25 : 5;
            for(int i = 1; i <= totalEnemy; i++)enemyUnit[i]->elationDebt = max(enemyUnit[i]->elationDebt,debt);
            actionForward(ptr->atvStats.get(),30);
            if(ptr->eidolon>=1)gainWishpower(5);
            if(!ptr->technique)return;
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"AeonAha Technique",
            [](shared_ptr<AllyBuffAction> &act){
                ahaInstant(20);
            });
            act->addBuffAllAllies();
            act->turnReset = 0;
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ahaAscension = false;
            ahaAscensionE2 = false;
            ahaTrueDmgOverride = -1;
            ptr->atvStats->flatSpeed += 5;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;
        }));

        // E1: all allies Elation DMG merrymake +15% while she is on the field
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=1)buffAllAlly({{Stats::MERRYMAKE,AType::NONE,15}});
            statsAdjust(ptr,Stats::SPD_P);
        }));

        // A6: SPD >= 125 / 150 -> Elation +120% / +150%
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            if(statsType!=Stats::FLAT_SPD&&statsType!=Stats::SPD_P)return;
            double spd = calculateSpeedOnStats(ptr);
            double buffValue = (spd>=150) ? 150 : (spd>=125) ? 120 : 0;
            buffSingle(ptr,{{Stats::ELATION,AType::NONE,buffValue - ptr->getBuffNote("AeonAha A6")}});
            ptr->setBuffNote("AeonAha A6",buffValue);
        }));

    }
}
