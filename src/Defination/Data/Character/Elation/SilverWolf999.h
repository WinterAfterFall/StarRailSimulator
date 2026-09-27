#include "../include.h"

// Silver Wolf LV.999 — kit: docs/kit-reference/Character/Elation/silver-wolf-lv-999.md (nanoka 4.5.54)
// Deterministic simplifications:
//   Top Loot Box proc  : every consumed SP adds the current fixed chance to an accumulator, box fires at 100%
//   Top Loot Box effect: fixed rotation Sword -> Kaboom -> Bean (kit weights by SP / Hidden MMR are not public)
//   E2 extra turn      : 100% action advance + 1 more Enhanced Basic ATK use
namespace SilverWolf999{
    const string GODMODE = "SW999 Godmode";

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(110,0,0,eidolon,ElementType::IMAGINARY,Path::ELATION,"Silver Wolf 999",UnitType::STANDARD);
        ptr->setAllyBaseStats(1048,388,655);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::HP_P,Stats::DEF_P);

        elationCount++;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Hidden MMR

        // Talent: CR +0.4% per MMR, past 100% CR it turns into CD +0.8% per MMR
        // modeled as CD +0.8% per MMR from the start — the substat reroll already fills CR up to 100%
        function<void()> updateMMRCritDmg = [ptr]() {
            double cdBuff = ptr->getBuffNote("SW999 MMR")*0.8;
            buffSingle(ptr,{{Stats::CD,AType::NONE,cdBuff - ptr->getBuffNote("SW999 MMR CD")}});
            ptr->setBuffNote("SW999 MMR CD",cdBuff);
        };

        // E2: every 120 MMR gained inside one Godmode (initial MMR included) -> extra turn + 1 Enhanced Basic ATK use
        function<void(double)> e2Gain = [ptr](double gained) {
            if(ptr->eidolon<2||!ptr->getBuffCheck(GODMODE))return;
            ptr->buffNote["SW999 E2 MMR"] += gained;
            while(ptr->getBuffNote("SW999 E2 MMR")>=120){
                ptr->buffNote["SW999 E2 MMR"] -= 120;
                ptr->buffNote["SW999 EBA Left"] += 1;
                actionForward(ptr->atvStats.get(),100);
            }
        };

        function<void(double)> gainMMR = [ptr,updateMMRCritDmg,e2Gain](double value) {
            double before = ptr->getBuffNote("SW999 MMR");
            double after = max(0.0,min(300.0,before + value));
            ptr->setBuffNote("SW999 MMR",after);
            updateMMRCritDmg();
            if(after>before)e2Gain(after - before);
        };

        // A4: Elation Skill counting >= 20 / >= 40 Punchline -> +20 / +40 MMR
        function<void()> a4 = [ptr,gainMMR]() {
            if(punchline>=40)gainMMR(40);
            else if(punchline>=20)gainMMR(20);
        };

        #pragma endregion

        #pragma region Top Loot Box

        // 90% Elation split among all enemies · each effect AoE 10 toughness
        function<shared_ptr<AllyAttackAction>()> makeLootBox = [ptr]() {
            int idx = (int)ptr->getBuffNote("SW999 Loot Idx") % 3;
            ptr->buffNote["SW999 Loot Idx"] += 1;
            string name = (idx==0) ? "SW999 Loot Sword" : (idx==1) ? "SW999 Loot Kaboom" : "SW999 Loot Bean";
            shared_ptr<AllyAttackAction> box =
            make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,TraceType::AOE,name,
            [ptr,idx](shared_ptr<AllyAttackAction> &act){
                attack(act);
                if(idx==1)genSkillPoint(ptr,2);
                else if(idx==2)genPunchLine(ptr,3);
            });
            double each = 90.0/max(1,totalEnemy);
            box->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,each,10),
                DmgSrc(DmgSrcType::ELATION,each,10),
                DmgSrc(DmgSrcType::ELATION,each,10)
            );
            box->turnReset = 0;
            return box;
        };

        #pragma endregion

        #pragma region Ability

        // Talent: while holding Certified Banger, BA / Skill add 40% Elation DMG to the enemies hit
        function<void(shared_ptr<AllyAttackAction> &,TraceType)> talentElation = [ptr](shared_ptr<AllyAttackAction> &src,TraceType traceType) {
            if(ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]<=0)return;
            shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ELATION_DMG,ptr,traceType,"SW999 Talent Elation");
            if(traceType==TraceType::AOE)
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::ELATION,40),
                    DmgSrc(DmgSrcType::ELATION,40),
                    DmgSrc(DmgSrcType::ELATION,40)
                );
            else elDmg->addDamageIns(DmgSrc(DmgSrcType::ELATION,40));
            elDmg->turnReset = 0;
            attack(elDmg);
        };

        function<void()> ba = [ptr,talentElation]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"SW999 BA",
            [ptr,talentElation](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                attack(act);
                talentElation(act,TraceType::SINGLE);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr,talentElation]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"SW999 Skill",
            [ptr,talentElation](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                genPunchLine(ptr,5);
                attack(act);
                talentElation(act,TraceType::AOE);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,10),
                DmgSrc(DmgSrcType::ATK,160,10),
                DmgSrc(DmgSrcType::ATK,160,10)
            );
            act->addToActionBar();
        };

        // Enhanced BA: 240% over 100 bounces in 4 segments of 25, a Top Loot Box between segments (3 total),
        // Final Hit 100% split among all enemies · with Certified Banger the ability DMG becomes Elation DMG
        // bounce toughness 10 total (0.1 each) · Final Hit AoE 10
        function<void(shared_ptr<AllyAttackAction> &,bool)> fillEbaSegment = [ptr](shared_ptr<AllyAttackAction> &seg,bool finalHit) {
            double mult = 1 + 0.15*min(2.0,floor(ptr->getBuffNote("SW999 MMR")/60));
            DmgSrcType type = (ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0) ? DmgSrcType::ELATION : DmgSrcType::ATK;
            seg->addEnemyBounce(DmgSrc(type,2.4*mult,0.1),25);
            if(finalHit){
                double each = 100.0*mult/max(1,totalEnemy);
                seg->addDamageIns(
                    DmgSrc(type,each,10),
                    DmgSrc(type,each,10),
                    DmgSrc(type,each,10)
                );
            }
        };

        function<void()> exitGodmode = [ptr,updateMMRCritDmg]() {
            ptr->setBuffCheck(GODMODE,0);
            ptr->setBuffNote("SW999 MMR",(ptr->eidolon>=1) ? ptr->getBuffNote("SW999 MMR")*0.2 : 0);
            updateMMRCritDmg();
            if(ptr->eidolon>=1)debuffAllEnemy({{Stats::VUL,AType::NONE,-20}});
            CharCmd::printUltEnd("Silver Wolf 999");
        };

        function<void()> eba = [ptr,fillEbaSegment,makeLootBox,exitGodmode]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BOUNCE,"SW999 EBA",
            [ptr,fillEbaSegment,makeLootBox,exitGodmode](shared_ptr<AllyAttackAction> &act){
                bool e6 = ptr->eidolon>=6&&ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>0;
                if(e6)buffSingle(ptr,{{Stats::MERRYMAKE,AType::NONE,50}});
                attack(act);
                for(int i=1;i<=3;i++){
                    // box from Enhanced BA does not count as an attack -> resolve inline, no action events
                    shared_ptr<AllyAttackAction> box = makeLootBox();
                    box->actionFunction(box);
                    shared_ptr<AllyAttackAction> seg = make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BOUNCE,"SW999 EBA");
                    fillEbaSegment(seg,i==3);
                    seg->turnReset = 0;
                    attack(seg);
                }
                if(e6)buffSingle(ptr,{{Stats::MERRYMAKE,AType::NONE,-50}});

                ptr->buffNote["SW999 EBA Left"] -= 1;
                if(ptr->getBuffNote("SW999 EBA Left")<=0)exitGodmode();
            });
            fillEbaSegment(act,false);
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,ba,skill,eba]() {
            if(ptr->getBuffCheck(GODMODE))eba();
            else if(sp>spSafety)skill();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return ptr->getBuffNote("SW999 MMR")>=60&&!ptr->getBuffCheck(GODMODE);
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [gainMMR,e2Gain](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"SW999 Ult",
            [ptr,gainMMR,e2Gain](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Silver Wolf 999");
                ptr->setBuffCheck(GODMODE,1);
                ptr->setBuffNote("SW999 EBA Left",3);
                ptr->setBuffNote("SW999 Loot Chance",100);
                ptr->setBuffNote("SW999 Loot Acc",0);
                ptr->setBuffNote("SW999 E2 MMR",0);

                if(ptr->eidolon>=1)debuffAllEnemy({{Stats::VUL,AType::NONE,20}});
                actionForward(ptr->atvStats.get(),100);
                if(ptr->eidolon>=2){
                    // extend every active buff on this unit by 1 turn
                    for(auto &each : ptr->buffEnd){
                        if(each.second>0)each.second++;
                    }
                    e2Gain(ptr->getBuffNote("SW999 MMR")); // initial MMR counts toward the 120 steps
                }
                gainMMR(20); // A6
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            dealDamage();
        }));

        // Normal: Pro-Gamer Move (+15 MMR) · Godmode: Honkai-DMG Demo (6 × 90% Elation, ST 10 total, resets box chance)
        elationSkillList.push_back(TriggerByYourSelfFunc(999, ptr, [gainMMR,a4](CharUnit *ptr) {
            if(!ptr->getBuffCheck(GODMODE)){
                CharCmd::printText("SW999 Pro-Gamer Move");
                gainMMR(15);
                a4();
                return;
            }
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::BOUNCE,"SW999 Honkai-DMG Demo",
            [ptr,a4](shared_ptr<AllyAttackAction> &act){
                int oldPL = punchline;
                if(ptr->eidolon>=4)punchline = oldPL*6; // E4: counts Punchline × 5 on top of the original
                attack(act);
                punchline = oldPL;
                a4();
                ptr->setBuffNote("SW999 Loot Chance",100);
                ptr->setBuffNote("SW999 Loot Acc",0);
            });
            act->addEnemyBounce(DmgSrc(DmgSrcType::ELATION,90,10.0/6),6);
            act->addToAhaInstant();
        }));

        // Zone: each SP consumed by an ally while in Godmode + holding Certified Banger rolls a Top Loot Box
        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr,makeLootBox](AllyUnit *spMaker, int spChange) {
            if(spChange>=0||!ptr->getBuffCheck(GODMODE))return;
            if(ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]<=0)return;
            for(int i=0;i<-spChange;i++){
                ptr->buffNote["SW999 Loot Acc"] += ptr->getBuffNote("SW999 Loot Chance");
                if(ptr->getBuffNote("SW999 Loot Acc")<100-1e-9)continue;
                ptr->buffNote["SW999 Loot Acc"] -= 100;
                ptr->buffNote["SW999 Loot Chance"] *= 0.2;
                makeLootBox()->addToActionBar();
                dealDamage();
            }
        }));

        // Talent: gaining Punchline gives the same amount of Hidden MMR (Aha reset refill has no source -> ignored)
        punchLineList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [gainMMR](AllyUnit *spMaker, int spChange) {
            if(spChange<=0||!spMaker)return;
            gainMMR(spChange);
        }));

        // Big Flipping Sword: True DMG = 20% of this box's DMG, on the highest-HP enemy (main target)
        afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr]
            (shared_ptr<AllyAttackAction> &act,Enemy *target,double damage) {
                if(act->actionName!="SW999 Loot Sword")return;
                calDamageNote(act,target,enemyUnit[mainEnemyNum].get(),damage,20,"SW999 Big Flipping Sword");
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsType[Stats::ELATION][AType::NONE] += 10;
            ptr->atvStats->flatSpeed += 9;

            ptr->setBuffNote("SW999 Loot Chance",100);
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            // E6: Absolute Weakness — all-type weakness; engine RES baseline is already 0 -> RES -20%
            if(ptr->eidolon>=6){
                for(auto &enemy : enemyList){
                    for(ElementType e : {ElementType::FIRE,ElementType::ICE,ElementType::LIGHTNING,ElementType::WIND,
                                         ElementType::QUANTUM,ElementType::IMAGINARY,ElementType::PHYSICAL}){
                        enemy->weaknessType[e] = 1;
                    }
                }
                debuffAllEnemy({{Stats::RESPEN,AType::NONE,20}});
            }
            statsAdjust(ptr,Stats::SPD_P);
        }));

        // Technique: Top Loot Box at each wave start with a fixed 99 Certified Banger
        startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [makeLootBox](CharUnit *ptr) {
            if(!ptr->technique)return;
            shared_ptr<AllyAttackAction> box = makeLootBox();
            auto boxFunc = box->actionFunction;
            box->actionFunction = [ptr,boxFunc](shared_ptr<AllyAttackAction> &act){
                double diff = 99 - ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE];
                ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE] += diff;
                boxFunc(act);
                ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE] -= diff;
            };
            box->addToActionBar();
            dealDamage();
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            // A2: SPD >= 160 -> Elation +50%, +2% per SPD above 160 (max 100 excess)
            if (statsType == Stats::FLAT_SPD||statsType == Stats::SPD_P) {
                double spd = calculateSpeedOnStats(ptr);
                double buffValue = (spd>=160) ? 50 + 2*min(100.0,spd - 160) : 0;
                buffSingleChar(ptr,{{Stats::ELATION, AType::NONE, buffValue - ptr->buffNote["SW999 A2"]}});
                ptr->buffNote["SW999 A2"] = buffValue;
            }
        }));

    }
}
