#include "../include.h"

namespace MortenaxBlade{
    const string BALEFIRE = "MortenaxBlade Balefire Bind";
    const string TAUNT = "MortenaxBlade Taunt";
    const string TECH = "MortenaxBlade Technique";
    const string CHARGE = "MortenaxBlade Charge";
    const string OVERFLOW = "MortenaxBlade Overflow";
    const string ZONE = "MortenaxBlade Zone";
    const string E1_RES = "MortenaxBlade E1";

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(107,160,160,eidolon,ElementType::FIRE,Path::NIHILITY,"MortenaxBlade",UnitType::STANDARD);
        AllyUnit *mb = ptr;
        ptr->setAllyBaseStats(1358,543,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::HP_P);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        // ใช้ Skill ต่อเมื่อ HP มากกว่ากี่ % ของ Max HP (ต่ำกว่านั้นใช้ Enhanced Basic ATK แทน) · 0 = ใช้ Skill ทุกครั้งที่ HP > 1
        ptr->adjust["MortenaxBlade Skill HP"] = 0;

        #pragma region extra
        // Balefire Bind: DEF -30% · DMG taken +50% · 2 turns (re-apply = refresh, ไม่ stack)
        function<void(Enemy *e)> balefire = [mb](Enemy *e){
            debuffSingleApply(mb,e,{{Stats::DEF_SHRED,AType::NONE,30},{Stats::VUL,AType::NONE,50}},BALEFIRE,2);
        };
        function<void(Enemy *e,int turns)> taunt = [mb](Enemy *e,int turns){
            debuffApply(mb,e,TAUNT,turns);
            e->addTaunt(mb);
        };
        function<bool()> inZone = [ptr](){
            return !ptr->countdownList[0]->isDeath();
        };

        // บัฟทั้งหมดระหว่าง Zone (ลง +1 / ถอน -1) · ผล A6 ที่เลือกตอนกาง Zone เก็บไว้ใน buffCheck เพื่อถอนให้ตรงกัน
        function<void(double sign)> zoneBuff = [ptr,mb](double sign){
            // Ult: Infinite Fury · A4: DMG taken -50% · Incoming Healing +50%
            buffSingle(mb,{
                {Stats::CR,AType::NONE,20*sign},
                {Stats::CD,AType::NONE,60*sign},
                {Stats::DMG_REDUCE,AType::NONE,50*sign},
                {Stats::HEALING_IN,AType::NONE,50*sign},
            });
            // A6 (+E4): ally targets DMG +50% (+50%)
            buffAllAlly({{Stats::DMG,AType::NONE,(ptr->eidolon>=4 ? 100.0 : 50.0)*sign}});
            if(ptr->getBuffCheck("MortenaxBlade A6 Nihility"))buffAllAlly({{Stats::DMG,AType::ULT,75*sign}});
            else buffSingle(mb,{{Stats::DMG,AType::NONE,75*sign}});
        };

        // E1: All-Type RES -20% ทุกศัตรูขณะ Zone (ถอนเฉพาะตัวที่ติดจริง)
        function<void()> applyE1 = [ptr,mb](){
            if(ptr->eidolon<1)return;
            for(auto &e : enemyList)debuffSingleApply(mb,e,{{Stats::RESPEN,AType::NONE,20}},E1_RES);
        };
        function<void()> removeE1 = [](){
            for(auto &e : enemyList){
                if(!e->getDebuff(E1_RES))continue;
                debuffRemove(e,E1_RES);
                debuffSingle(e,{{Stats::RESPEN,AType::NONE,-20}});
            }
        };

        // A2: Energy < 75% -> 75% (ตอนเริ่มเกม / Zone หาย)
        function<void()> energyFloor = [ptr](){
            if(ptr->currentEnergy < ptr->maxEnergy*0.75)ptr->currentEnergy = ptr->maxEnergy*0.75;
        };
        // A2: หลังกด Ult -> เคลียร์ overflow แล้วคืนเป็น Energy
        function<void()> releaseOverflow = [ptr](){
            double overflow = ptr->buffNote[OVERFLOW];
            ptr->buffNote[OVERFLOW] = 0;
            if(overflow>0)increaseEnergy(ptr,0,overflow);
        };

        function<void()> endZone = [ptr,mb,zoneBuff,removeE1,energyFloor](){
            if(ptr->countdownList[0]->isDeath())return;
            ptr->countdownList[0]->death();
            ptr->setBuffCheck(ZONE,false);
            zoneBuff(-1);
            removeE1();
            energyFloor();
            if(ptr->print)CharCmd::printUltEnd("MortenaxBlade");
        };
        #pragma endregion

        #pragma region Ability
        function<void()> ba = [ptr,mb,taunt]() {
            genSkillPoint(mb,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"MortenaxBlade BA",
            [ptr,taunt](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
                for(Enemy *e : act->targetList)taunt(e,1);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
            act->addToActionBar();
        };

        // Enhanced Basic ATK (Infinite Fury)
        function<void()> eba = [ptr,mb,taunt]() {
            genSkillPoint(mb,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"MortenaxBlade EBA",
            [ptr,taunt](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
                for(Enemy *e : act->targetList)taunt(e,1);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::HP,100,10));
            act->addToActionBar();
        };

        // Skill: ใช้ HP 10% · 72% AoE + 4 hit 24% สุ่มเป้า (ใส่ที่เป้าหลักทั้งหมด = best bounce) · ไม่ใช้ SP
        // extra = true -> Skill เพิ่มจาก Talent ซึ่งนับเป็น Follow-Up ATK (ไม่จบเทิร์น)
        function<shared_ptr<AllyAttackAction>(bool extra)> makeSkill = [ptr,mb](bool extra) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(extra ? AType::FUA : AType::SKILL,ptr,TraceType::AOE,
            extra ? "MortenaxBlade Talent Skill" : "MortenaxBlade Skill",
            [ptr,mb](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                decreaseHP(mb,mb,0,10,0);
                attack(act);
            });
            if(extra)act->addAttackType(AType::SKILL);
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,72,10),
                DmgSrc(DmgSrcType::HP,72,10),
                DmgSrc(DmgSrcType::HP,72,10)
            );
            for(int i=0;i<4;i++)act->addDamageIns(DmgSrc(DmgSrcType::HP,24,5));
            return act;
        };
        function<void()> skill = [makeSkill]() {
            makeSkill(false)->addToActionBar();
        };

        // Talent: Charge ครบ 9 (E2: 7) และ HP > 1 -> ใช้ Charge, Energy +25, Skill เพิ่ม 1 ครั้ง (Follow-Up ATK)
        function<void()> tryCharge = [ptr,mb,makeSkill](){
            int limit = (ptr->eidolon>=2) ? 7 : 9;
            if(mb->getStack(CHARGE)<limit||ptr->currentHP<=1)return;
            mb->addStack(CHARGE,-limit);
            increaseEnergy(ptr,25);
            shared_ptr<AllyAttackAction> act = makeSkill(true);
            act->addToActionBar();
            dealDamage();
        };
        function<void(int)> addCharge = [ptr,mb,inZone,tryCharge](int value){
            if(!inZone())return;
            mb->addStack(CHARGE,value);
            tryCharge();
        };
        #pragma endregion

        ptr->turnFunc = [ptr,mb,ba,eba,skill,inZone]() {
            if(!inZone()){
                ba();
                return;
            }
            if(ptr->currentHP>1 && ptr->currentHP > ptr->totalHP*ptr->adjust["MortenaxBlade Skill HP"]/100.0)skill();
            else eba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [mb,balefire,zoneBuff,applyE1,releaseOverflow](CharUnit *ptr) {
            if(ptr->countdownList[0]->isDeath()){
                // Fornax Ex Corpore: Balefire Bind ทุกศัตรู -> ใช้ HP 20% -> กาง Zone + Infinite Fury
                shared_ptr<AllyBuffAction> act =
                make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"MortenaxBlade Fornax Ex Corpore",
                [ptr,mb,balefire,zoneBuff,applyE1](shared_ptr<AllyBuffAction> &act){
                    if(ptr->print)CharCmd::printUltStart("MortenaxBlade");
                    for(auto &e : enemyList)balefire(e);
                    decreaseHP(mb,mb,0,20,0);
                    // A6: มีตัว Nihility อื่นในทีมไหม (ตัดสินตอนกาง Zone)
                    bool otherNihility = false;
                    for(auto &each : charList){
                        if(each->path==Path::NIHILITY&&!each->isSameName("MortenaxBlade"))otherNihility = true;
                    }
                    ptr->setBuffCheck("MortenaxBlade A6 Nihility",otherNihility);
                    ptr->setBuffCheck(ZONE,true);
                    ptr->countdownList[0]->summon();
                    zoneBuff(1);
                    applyE1();
                });
                act->addBuffSingleTarget(ptr);
                act->addToActionBar();
                releaseOverflow();
                dealDamage();
                return;
            }
            // Tenax Per Ignem: 350% Max HP AoE (E6 x1.5)
            double mult = (ptr->eidolon>=6) ? 525 : 350;
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"MortenaxBlade Tenax Per Ignem",
            [ptr](shared_ptr<AllyAttackAction> &act){
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,mult,20),
                DmgSrc(DmgSrcType::HP,mult,20),
                DmgSrc(DmgSrcType::HP,mult,20)
            );
            act->addToActionBar();
            releaseOverflow();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::FIRE][AType::NONE] += 22.4;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;
            ptr->statsType[Stats::CR][AType::NONE] += 12;

            // relic

            // substats

            // eidolon: ไม่ใส่ E3/E5 (ตัว 5★ ใช้เลเวลสกิลพื้นฐาน)
        }));

        // E2: Follow-Up ATK DMG ของทีม +75%
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=2)buffAllAlly({{Stats::DMG,AType::FUA,75}});
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [mb,taunt,energyFloor](CharUnit *ptr) {
            ptr->buffNote[OVERFLOW] = 0;
            mb->setStack(CHARGE,0);
            energyFloor();
            // Technique: Taunt ทุกศัตรู 1 เทิร์น · DMG taken -90% 2 เทิร์น (ดาเมจของ technique ไม่มีตัวเลขใน kit -> ไม่ใส่)
            if(ptr->technique){
                for(auto &e : enemyList)taunt(e,1);
                buffSingle(mb,{{Stats::DMG_REDUCE,AType::NONE,90}},TECH,2);
            }
        }));

        // Zone อยู่ข้าม wave -> ศัตรู wave ใหม่ได้ E1 ด้วย
        startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [applyE1](CharUnit *ptr) {
            if(!ptr->countdownList[0]->isDeath())applyE1();
        }));

        // A2: overflow Energy สูงสุด 80 (event ยิงก่อนบวก -> ส่วนที่เกิน max คือ overflow)
        whenEnergyIncreaseList.push_back(TriggerEnergyIncreaseFunc(PRIORITY_IMMEDIATELY, [ptr](CharUnit *target, double energy) {
            if(target!=ptr)return;
            double over = ptr->currentEnergy + energy - ptr->maxEnergy;
            if(over<=0)return;
            ptr->buffNote[OVERFLOW] = min(80.0, ptr->buffNote[OVERFLOW] + over);
        }));

        // E2: Ult ของตัวละครฝั่งเรานับเป็น Follow-Up ATK
        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if(ptr->eidolon<2)return;
            if(!act->isSameAction(AType::ULT)||act->isSameAction(AType::FUA))return;
            if(act->attacker!=act->attacker->owner)return;
            act->addAttackType(AType::FUA);
        }));

        // Talent: ระหว่าง Zone ทุกการโจมตีของฝั่งเรา -> Balefire Bind เป้าที่โดน + Charge 1
        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr,balefire,inZone,addCharge](shared_ptr<AllyAttackAction> &act) {
            if(!inZone())return;
            for(Enemy *e : act->targetList)balefire(e);
            addCharge(1);
            // E1: หลังใช้ Skill เพิ่มจาก Talent -> countdown ถูกหน่วง 15%
            if(ptr->eidolon>=1&&act->actionName=="MortenaxBlade Talent Skill"){
                actionForward(ptr->countdownList[0].get(),-15);
            }
        }));

        // A4: ระหว่าง Zone โดนโจมตี -> Balefire Bind ผู้โจมตี + Charge 1
        enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK, [ptr,mb,balefire,inZone,addCharge](Enemy *attacker, vector<AllyUnit *> target) {
            if(!inZone())return;
            for(AllyUnit *e : target){
                if(!e->isSameName(mb))continue;
                balefire(attacker);
                addCharge(1);
                return;
            }
        }));

        hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK, [ptr,mb,inZone,addCharge,endZone](Unit *trigger, AllyUnit *target, double value) {
            if(!target->isSameName(mb)||!inZone())return;
            // Ult: โดน killing blow (HP เหลือ 1 จากการโจมตีของศัตรู) -> ไม่ล้ม · Zone หาย · ฟื้น HP 50%
            if(trigger->canCastToEnemy()&&ptr->currentHP<=1){
                endZone();
                ptr->restoreHP(mb,HealSrc(HealSrcType::TOTAL_HP,50));
                return;
            }
            // E6: โดนดาเมจ / ใช้ HP -> Charge 1 · ใช้ได้อีกหลังจบเทิร์นของใครก็ได้
            if(ptr->eidolon>=6&&value>0&&!ptr->getBuffCheck("MortenaxBlade E6")){
                ptr->setBuffCheck("MortenaxBlade E6",true);
                addCharge(1);
            }
        }));

        // Charge ค้างตอน HP = 1 -> ฮีลแล้วลองใช้อีกครั้ง
        healingList.push_back(TriggerHealing(PRIORITY_ACTTACK, [mb,inZone,tryCharge](AllyUnit *healer, AllyUnit *target, double value) {
            if(!target->isSameName(mb)||!inZone())return;
            tryCharge();
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [mb](CharUnit *ptr) {
            ptr->setBuffCheck("MortenaxBlade E6",false);
            Enemy *e = turn->canCastToEnemy();
            if(e){
                if(isDebuffEnd(e,BALEFIRE))debuffSingle(e,{{Stats::DEF_SHRED,AType::NONE,-30},{Stats::VUL,AType::NONE,-50}});
                if(isDebuffEnd(e,TAUNT))e->removeTaunt(mb);
                return;
            }
            if(turn->isSameUnit(ptr)&&isBuffEnd(mb,TECH)){
                buffSingle(mb,{{Stats::DMG_REDUCE,AType::NONE,-90}});
            }
        }));

        //countdown: Infinite Fury (SPD 70) -> ถึงตาแล้ว Zone หาย
        setCountdownStats(ptr,70,"Infinite Fury");
        ptr->countdownList[0]->turnFunc = [endZone](){
            endZone();
        };
    }
}
