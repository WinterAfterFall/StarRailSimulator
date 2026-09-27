#include "../include.h"

// Robin • Summeretto — kit: docs/kit-reference/Character/Remembrance/robin-summeretto.md (nanoka 4.5.54)
// Levels: Basic Lv.6 · Skill/Ult/Talent Lv.10 · Memosprite Skill/Talent Lv.6
// Model:
//   "Summer Songbirds" = one memosprite with a member count (1 Bessie · 2 +Drummie · 3 +Paddie)
//   outside Fever the Songbirds are on the field but take no turns (ATV_FREEZE)
//   Fever: Songbirds act, a countdown (SPD 140) drains Vibes, Robin takes no turns (ATV_FREEZE)
//   Vibes from "provide healing" = once per healer per turn · Shields are not modeled (no shield event)
namespace RobinSummeretto{
    const string SPECIAL_GUEST = "RobinSM Special Guest";

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(95,140,140,eidolon,ElementType::WIND,Path::REMEMBRANCE,"Robin Summeretto",UnitType::STANDARD);
        ptr->setAllyBaseStats(1203,602,485);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        // Talent: Songbirds Max HP 70% of Robin's · SPD 180% of Robin's
        setMemoStats(ptr,0,70,0,180,ElementType::WIND,"Summer Songbirds",UnitType::STANDARD);
        setCountdownStats(ptr,140,"RobinSM Fever");
        Memosprite *memo = ptr->memosprite.get();
        TimerATV *fever = ptr->countdownList[0].get();

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        #pragma region Helper

        function<bool()> inFever = [fever]() {
            return fever->isAlive();
        };

        function<double()> vibesCap = [ptr]() {
            return (ptr->eidolon>=2) ? 70.0 : 50.0;
        };

        // enemies DMG taken 8% / 12% / 16% by Songbirds member count
        function<void()> updateMemberVul = [ptr]() {
            int members = (int)ptr->getBuffNote("RobinSM Members");
            double value = (members==1) ? 8 : (members==2) ? 12 : (members>=3) ? 16 : 0;
            debuffAllEnemy({{Stats::VUL,AType::NONE,value - ptr->getBuffNote("RobinSM Vul")}});
            ptr->setBuffNote("RobinSM Vul",value);
        };

        // Fever buffs that scale with Vibes: Zone DEF ignore (15% + 0.5%·V) all allies · DMG (60% + 2%·V) Robin + Songbirds
        function<void()> updateFeverBuffs = [ptr,memo,inFever]() {
            double vibes = ptr->getBuffNote("RobinSM Vibes");
            double zone = inFever() ? 15 + 0.5*vibes : 0;
            double dmg = inFever() ? 60 + 2*vibes : 0;
            buffAllAlly({{Stats::DEF_SHRED,AType::NONE,zone - ptr->getBuffNote("RobinSM Zone")}});
            ptr->setBuffNote("RobinSM Zone",zone);
            buffSingle(ptr,{{Stats::DMG,AType::NONE,dmg - ptr->getBuffNote("RobinSM Fever DMG")}});
            buffSingle(memo,{{Stats::DMG,AType::NONE,dmg - ptr->getBuffNote("RobinSM Fever DMG")}});
            ptr->setBuffNote("RobinSM Fever DMG",dmg);
        };

        function<void()> enterFever = [ptr,memo,fever,updateFeverBuffs]() {
            CharCmd::printUltStart("Robin Summeretto Fever");
            ptr->status = UnitStatus::ATV_FREEZE;
            memo->status = UnitStatus::ALIVE;
            memo->resetATV();
            fever->summon();
            if(ptr->eidolon>=4){
                ptr->buffNote["RobinSM Vibes"] = min((ptr->eidolon>=2) ? 70.0 : 50.0,ptr->getBuffNote("RobinSM Vibes") + 12);
                double spd = 20 + 0.5*ptr->getBuffNote("RobinSM Vibes");
                buffSingle(memo,{{Stats::SPD_P,AType::NONE,spd}});
                ptr->setBuffNote("RobinSM E4",spd);
            }
            if(ptr->eidolon>=6){
                if(!ptr->getBuffCheck("RobinSM E6 First")){
                    ptr->setBuffCheck("RobinSM E6 First",1);
                    increaseEnergy(ptr,0,140);
                }
            }
            updateFeverBuffs();
        };

        function<void()> exitFever = [ptr,memo,fever,updateFeverBuffs,updateMemberVul]() {
            ptr->setBuffNote("RobinSM Vibes",0);
            fever->death();
            updateFeverBuffs();
            if(ptr->getBuffNote("RobinSM E4")>0){
                buffSingle(memo,{{Stats::SPD_P,AType::NONE,-ptr->getBuffNote("RobinSM E4")}});
                ptr->setBuffNote("RobinSM E4",0);
            }
            // Songbirds disappear
            memo->death();
            ptr->setBuffNote("RobinSM Members",0);
            updateMemberVul();
            // Robin takes turns again · Astride Summer's Nightwind: advance 50%
            ptr->status = UnitStatus::ALIVE;
            actionForward(ptr->atvStats.get(),50);
            CharCmd::printUltEnd("Robin Summeretto Fever");
        };

        // Talent: while Bessie is on the field, 6 Vibes -> Drummie, 12 -> Paddie · all three -> Fever
        function<void()> checkMembers = [ptr,memo,inFever,updateMemberVul,enterFever]() {
            if(memo->isDeath())return;
            double vibes = ptr->getBuffNote("RobinSM Vibes");
            int members = 1 + (vibes>=6 ? 1 : 0) + (vibes>=12 ? 1 : 0);
            if(members>ptr->getBuffNote("RobinSM Members")){
                ptr->setBuffNote("RobinSM Members",members);
                updateMemberVul();
            }
            if(ptr->getBuffNote("RobinSM Members")>=3&&!inFever())enterFever();
        };

        // A2: the ally who made Robin gain Vibes -> ATK +(16% + 0.4%·V) of Robin's Max HP if their ATK is higher, else CD +(40% + 1.5%·V), 2 turns
        function<void(AllyUnit*)> a2 = [ptr](AllyUnit *source) {
            if(!source)return;
            double vibes = ptr->getBuffNote("RobinSM Vibes");
            double atk = 0, cd = 0;
            if(calculateAtkOnStats(source)>calculateAtkOnStats(ptr))atk = calculateHpForBuff(ptr,16 + 0.4*vibes);
            else cd = 40 + 1.5*vibes;
            buffSingle(source,{
                {Stats::FLAT_ATK,AType::TEMP,atk - source->getBuffNote("RobinSM A2 ATK")},
                {Stats::FLAT_ATK,AType::NONE,atk - source->getBuffNote("RobinSM A2 ATK")},
                {Stats::CD,AType::TEMP,cd - source->getBuffNote("RobinSM A2 CD")},
                {Stats::CD,AType::NONE,cd - source->getBuffNote("RobinSM A2 CD")}
            });
            source->setBuffNote("RobinSM A2 ATK",atk);
            source->setBuffNote("RobinSM A2 CD",cd);
            source->setBuffCheck("RobinSM A2",1);
            extendBuffTime(source,"RobinSM A2",2);
        };

        // "the first time in this turn" key: the acting unit + its turn count
        function<string()> turnKey = []() {
            if(!turn)return string("none");
            return turn->name + " " + to_string(turn->turnCnt);
        };

        // gain Vibes (cap 50, E2 70) · A4 Groove energy · E2 +2 first ability per turn · A2 on the source
        function<void(AllyUnit*,double,bool)> gainVibes = [ptr,vibesCap,turnKey,a2,checkMembers,updateFeverBuffs](AllyUnit *source,double value,bool fromAbility) {
            string key = turnKey();
            if(ptr->getBuffNote("RobinSM Groove")>0&&ptr->buffNote["RobinSM Groove Turn " + key]==0){
                ptr->buffNote["RobinSM Groove Turn " + key] = 1;
                ptr->buffNote["RobinSM Groove"] -= 1;
                increaseEnergy(ptr,0,3);
            }
            if(ptr->eidolon>=2&&fromAbility&&ptr->buffNote["RobinSM E2 Turn " + key]==0){
                ptr->buffNote["RobinSM E2 Turn " + key] = 1;
                value += 2;
            }
            ptr->setBuffNote("RobinSM Vibes",min(vibesCap(),ptr->getBuffNote("RobinSM Vibes") + value));
            a2(source);
            checkMembers();
            updateFeverBuffs();
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"RobinSM BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,50,10)
            );
            act->addToActionBar();
        };

        // Skill: summon Bessie (Near the Sea's Heartbeat +20 Energy) · already on field -> heal 100% of their Max HP, +6 Vibes
        function<void()> skill = [ptr,memo,gainVibes,checkMembers,updateMemberVul]() {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"RobinSM Skill",
            [ptr,memo,gainVibes,checkMembers,updateMemberVul](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                if(memo->isDeath()){
                    memo->summon(100);
                    memo->status = UnitStatus::ATV_FREEZE;
                    ptr->setBuffNote("RobinSM Members",0);
                    increaseEnergy(ptr,20);
                    checkMembers();
                    updateMemberVul();
                    return;
                }
                ptr->restoreHP(memo,HealSrc(HealSrcType::TOTAL_HP,100));
                gainVibes(ptr,6,true);
            });
            act->addBuffSingleTarget(ptr);
            act->addActionType(AType::SUMMON);
            act->addToActionBar();
        };

        // Memosprite Skill: 150% of Songbirds' Max HP AoE (toughness 10) · Robin +20 Energy · E6 ×2 · E1 True DMG from the tally
        function<void()> memoSkill = [ptr,memo]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,memo,TraceType::AOE,"RobinSM Songbirds",
            [ptr,memo](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
                if(ptr->eidolon>=1&&ptr->getBuffNote("RobinSM E1 Tally")>0){
                    double ratio = 11 + 0.1*ptr->getBuffNote("RobinSM Vibes");
                    calDamageNote(act,enemyUnit[mainEnemyNum].get(),enemyUnit[mainEnemyNum].get(),
                        ptr->getBuffNote("RobinSM E1 Tally"),ratio,"RobinSM E1 True");
                    ptr->buffNote["RobinSM E1 Tally"] *= 0.5;
                }
            });
            double mtpr = (ptr->eidolon>=6) ? 300 : 150;
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,mtpr,10),
                DmgSrc(DmgSrcType::HP,mtpr,10),
                DmgSrc(DmgSrcType::HP,mtpr,10)
            );
            act->addAttackType(AType::SUMMON);
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr,memo,ba,skill]() {
            if(memo->isDeath()||sp>spSafety)skill();
            else ba();
        };

        memo->turnFunc = [memoSkill]() {
            memoSkill();
        };

        // Fever countdown: Vibes -50% (at least 12) · E6 fixed 140 Energy · Vibes 0 -> Songbirds leave, Fever ends
        fever->turnFunc = [ptr,fever,updateFeverBuffs,exitFever]() {
            if(ptr->eidolon>=6)increaseEnergy(ptr,0,140);
            double vibes = ptr->getBuffNote("RobinSM Vibes");
            vibes = max(0.0,vibes - max(12.0,vibes*0.5));
            ptr->setBuffNote("RobinSM Vibes",vibes);
            if(vibes<=0)exitFever();
            else{
                updateFeverBuffs();
                resetTurn(fever);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        // Ult: 1 ally (not Robin) advance 100% + fixed 20% of their Max Energy · Special Guest 2 turns
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            // E6: the Energy just spent is refilled from the stored bank (the stored 2nd Ultimate)
            double refill = min(ptr->getBuffNote("RobinSM E6 Bank"),ptr->maxEnergy - ptr->currentEnergy);
            if(refill>0){
                ptr->currentEnergy += refill;
                ptr->buffNote["RobinSM E6 Bank"] -= refill;
            }
            AllyUnit *target = chooseAllyBuff(ptr);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"RobinSM Ult",
            [ptr,target](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Robin Summeretto");
                if(target->owner==ptr)return;
                actionForward(target->atvStats.get(),100);
                increaseEnergy(target,20,0);
                AllyUnit *old = ptr->getBuffSubUnitTarget(SPECIAL_GUEST);
                if(old)old->setBuffCheck(SPECIAL_GUEST,0);
                ptr->setBuffSubUnitTarget(SPECIAL_GUEST,target);
                target->setBuffCheck(SPECIAL_GUEST,1);
                ptr->setBuffNote("RobinSM Special Guest Turns",2);
            });
            act->addBuffSingleTarget(target);
            act->addToActionBar();
            dealDamage();
        }));

        // E6: in Fever the Ultimate can be stored up to 2 times -> Energy past full goes to a bank (up to 1 more Ultimate)
        // the event fires before the Energy is added, so the overflow is (current + gained - max)
        if(ptr->eidolon>=6)
        whenEnergyIncreaseList.push_back(TriggerEnergyIncreaseFunc(PRIORITY_IMMEDIATELY, [ptr,inFever](CharUnit *target, double energy) {
            if(target!=ptr||!inFever())return;
            double overflow = ptr->currentEnergy + energy - ptr->maxEnergy;
            if(overflow<=0)return;
            ptr->setBuffNote("RobinSM E6 Bank",min(ptr->ultCost,ptr->getBuffNote("RobinSM E6 Bank") + overflow));
        }));

        // Special Guest: duration -1 at the start of Robin's turn
        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(!turn->isSameName(ptr->getName()))return;
            if(ptr->getBuffNote("RobinSM Special Guest Turns")<=0)return;
            ptr->buffNote["RobinSM Special Guest Turns"] -= 1;
            if(ptr->getBuffNote("RobinSM Special Guest Turns")>0)return;
            AllyUnit *guest = ptr->getBuffSubUnitTarget(SPECIAL_GUEST);
            if(guest)guest->setBuffCheck(SPECIAL_GUEST,0);
            ptr->setBuffSubUnitTarget(SPECIAL_GUEST,nullptr);
        }));

        // Talent: an ally uses an attack -> +1 Vibes (Special Guest or their summon: +2 more) · counted once per action
        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,gainVibes](shared_ptr<AllyAttackAction> &act) {
            if(act->attacker!=act->attackSetList[0].attacker)return;
            double value = 1;
            AllyUnit *guest = ptr->getBuffSubUnitTarget(SPECIAL_GUEST);
            if(guest&&guest->getBuffCheck(SPECIAL_GUEST)&&act->getChar()==guest->owner)value += 2;
            gainVibes(act->attacker,value,true);
        }));

        // Talent: an ally provides healing the first time in a turn -> +1 Vibes · A4: teammates healing Robin / Songbirds -> 12 Groove
        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,turnKey,gainVibes](AllyUnit *healer, AllyUnit *target, double value) {
            if(!healer)return;
            if(healer->owner!=ptr&&(target->owner==ptr))ptr->setBuffNote("RobinSM Groove",12);
            string key = "RobinSM Heal " + healer->getName() + " " + turnKey();
            if(ptr->buffNote[key]!=0)return;
            ptr->buffNote[key] = 1;
            gainVibes(healer,1,true);
        }));

        // E1: tally 100% of the non-True DMG dealt by allies
        if(ptr->eidolon>=1)
        afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr]
            (shared_ptr<AllyAttackAction> &act,Enemy *target,double damage) {
                ptr->buffNote["RobinSM E1 Tally"] += damage;
        }));

        // Technique: at battle start advance 20%, +6 Vibes, all allies DMG +30% for 2 turns
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gainVibes](CharUnit *ptr) {
            if(!ptr->technique)return;
            actionForward(ptr->atvStats.get(),20);
            gainVibes(ptr,6,false);
            buffAllAlly({{Stats::DMG,AType::NONE,30}},"RobinSM Technique",2);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"RobinSM Technique"))buffSingle(ally,{{Stats::DMG,AType::NONE,-30}});
            if(isBuffEnd(ally,"RobinSM A2")){
                buffSingle(ally,{
                    {Stats::FLAT_ATK,AType::TEMP,-ally->getBuffNote("RobinSM A2 ATK")},
                    {Stats::FLAT_ATK,AType::NONE,-ally->getBuffNote("RobinSM A2 ATK")},
                    {Stats::CD,AType::TEMP,-ally->getBuffNote("RobinSM A2 CD")},
                    {Stats::CD,AType::NONE,-ally->getBuffNote("RobinSM A2 CD")}
                });
                ally->setBuffNote("RobinSM A2 ATK",0);
                ally->setBuffNote("RobinSM A2 CD",0);
            }
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::HP_P][AType::NONE] += 18;
            ptr->statsType[Stats::CR][AType::NONE] += 6.7;
            ptr->atvStats->flatSpeed += 14;

            ptr->statsType[Stats::CR][AType::NONE] += 50; // A6 (Songbirds copy Robin's stats at memospriteReset)
        }));

        // E2: all allies RES PEN +18%
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=2)buffAllAlly({{Stats::RESPEN,AType::NONE,18}});
        }));

    }
}
