#include "../include.h"

namespace DanHengIL{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102,140,140,eidolon,ElementType::IMAGINARY,Path::DESTRUCTION,"DanHengIL",UnitType::STANDARD);
        AllyUnit *dh = ptr;
        ptr->setAllyBaseStats(1241,698,363);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CD,Stats::ATK_P,Stats::DMG,Stats::ATK_P);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        // จำนวนครั้งสูงสุดที่เสริม Basic ATK ด้วย Dracore Libre ต่อเทิร์น (1..3) · ลดลงถ้าอยากเหลือ SP ให้ทีม
        ptr->adjust["DanHengIL Enhance"] = 3;

        #pragma region extra
        // Squama Sacrosancta: เก็บได้สูงสุด 3 (EX1 +1)
        function<void(int value)> addSquama = [ptr,dh](int value){
            int limit = 3 + (ptr->extraEidolon>=1 ? 1 : 0);
            dh->setStack("DanHengIL Squama",min(limit,dh->getStack("DanHengIL Squama")+value));
        };
        // ใช้ Squama ก่อน SP · การใช้ Squama นับเป็นการใช้ SP (ยิง skillPointList แต่ไม่ลด sp)
        function<void(int cost)> paySP = [ptr,dh](int cost){
            int useSquama = min(cost,dh->getStack("DanHengIL Squama"));
            if(useSquama>0){
                dh->addStack("DanHengIL Squama",-useSquama);
                allEventSkillPoint(dh,-useSquama);
            }
            if(cost-useSquama>0)genSkillPoint(dh,-(cost-useSquama));
        };
        // "อยู่ถึงจบเทิร์นของเขา": ได้ในเทิร์นตัวเอง -> จบเทิร์นนี้ · ได้นอกเทิร์น -> จบเทิร์นถัดไปของเขา
        function<int()> untilTurnEnd = [ptr](){
            return turn->isSameUnit(ptr) ? 0 : 1;
        };
        // จำนวน hit ตาม kit (ใช้นับ stack อย่างเดียว · ดาเมจไม่แบ่ง hit) · ท่าที่ kit ไม่บอกนับเป็น 1
        function<int(const string&)> hitCount = [](const string &name){
            if(name=="DanHengIL Beneficent Lotus")return 2;
            if(name=="DanHengIL Transcendence")return 3;
            if(name=="DanHengIL Divine Spear")return 5;
            if(name=="DanHengIL Fulgurant Leap")return 7;
            if(name=="DanHengIL Ult")return 3;
            return 1;
        };
        #pragma endregion

        #pragma region Ability
        // ไม่แบ่ง hit: kit ให้มาแค่ตัวคูณรวม -> ใส่เป็นดาเมจก้อนเดียว
        function<void()> ba = [ptr,dh]() {
            genSkillPoint(dh,1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"DanHengIL Beneficent Lotus",
            [ptr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
            act->addToActionBar();
        };

        function<void()> transcendence = [ptr,paySP]() {
            paySP(1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"DanHengIL Transcendence",
            [ptr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,260,20));
            act->addToActionBar();
        };

        function<void()> divineSpear = [ptr,paySP]() {
            paySP(2);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"DanHengIL Divine Spear",
            [ptr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,35);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,380,30),
                DmgSrc(DmgSrcType::ATK,60,10)
            );
            act->addToActionBar();
        };

        function<void()> fulgurantLeap = [ptr,paySP]() {
            paySP(3);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"DanHengIL Fulgurant Leap",
            [ptr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,40);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,500,40),
                DmgSrc(DmgSrcType::ATK,180,20)
            );
            act->addToActionBar();
        };

        // EX1 Moonset Stills the Deep: เป็น Follow-Up ATK แต่ดาเมจนับเป็นดาเมจ Basic ATK
        function<void()> moonset = [ptr,dh,addSquama]() {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::AOE,"DanHengIL Moonset Stills the Deep",
            [ptr,dh,addSquama](shared_ptr<AllyAttackAction> &act){
                buffSingle(dh,{{Stats::DMG,AType::NONE,240}},"DanHengIL Moonset Stills the Deep",3);
                attack(act);
                addSquama(1);
            });
            act->addDamageType(AType::BA);
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,500,10),
                DmgSrc(DmgSrcType::ATK,500,10),
                DmgSrc(DmgSrcType::ATK,500,10)
            );
            act->addToActionBar();
            dealDamage();
        };
        #pragma endregion

        // Dracore Libre ไม่นับเป็น Skill: แค่เลือกว่าจะเสริม Basic ATK กี่ครั้ง
        ptr->turnFunc = [ptr,dh,ba,transcendence,divineSpear,fulgurantLeap]() {
            int level = min((int)ptr->adjust["DanHengIL Enhance"],sp + dh->getStack("DanHengIL Squama"));
            if(level>=3)fulgurantLeap();
            else if(level==2)divineSpear();
            else if(level==1)transcendence();
            else ba();
        };

        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [addSquama](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::BLAST,"DanHengIL Ult",
            [ptr,addSquama](shared_ptr<AllyAttackAction> &act){
                if(ptr->print) CharCmd::printUltStart("DanHengIL");
                increaseEnergy(ptr,5);
                attack(act);
                addSquama(2);
                if(ptr->eidolon>=2){
                    addSquama(1);
                    // E2: เลื่อน action 100% — ถ้าอยู่ในเทิร์นตัวเองให้รอจบเทิร์นก่อน (afterTurn) ถ้านอกเทิร์นเลื่อนทันที
                    if(turn->isSameUnit(ptr))ptr->buffCheck["DanHengIL E2 Advance"] = 1;
                    else actionForward(ptr->atvStats.get(),100);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,140,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::IMAGINARY][AType::NONE] += 22.4;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;

            // relic

            // substats

            // eidolon: ไม่ใส่ E3/E5 (ตัว 5★ ใช้เลเวลสกิลพื้นฐาน)
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [addSquama](CharUnit *ptr) {
            // A2 Star Veil
            increaseEnergy(ptr,15);
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act =
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"DanHengIL Tech",
                [ptr,addSquama](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                    addSquama(1);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,120,20),
                    DmgSrc(DmgSrcType::ATK,120,20),
                    DmgSrc(DmgSrcType::ATK,120,20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        // A6 Jolt Anew: CRIT DMG +24% ใส่เป้าที่มีจุดอ่อน Imaginary (ดูจากเป้าหลัก แล้วใช้กับทั้งการโจมตี)
        // E6: RES PEN ที่สะสมไว้ ใช้กับ Fulgurant Leap ครั้งถัดไป
        // Outroar: kit ให้ 1 stack ก่อนทุก hit ตั้งแต่ hit ที่ 4 · ไม่แบ่ง hit -> ให้ครบทุก stack ก่อนดาเมจก้อนเดียว
        //   Divine Spear 2 stack (hit 4-5) · Fulgurant Leap 4 stack (hit 4-7)
        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,dh,hitCount](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameName("DanHengIL"))return;
            if(act->actionName=="DanHengIL Divine Spear"||act->actionName=="DanHengIL Fulgurant Leap"){
                // E4: อยู่ถึงจบเทิร์นถัดไปของเขา
                buffStackSingle(dh,{{Stats::CD,AType::NONE,12}},hitCount(act->actionName)-3,4,"DanHengIL Outroar",(ptr->eidolon>=4 ? 1 : 0));
            }
            for(Enemy *e : act->targetList){
                if(e->targetType!=EnemyType::MAIN)continue;
                if(e->weaknessType[ElementType::IMAGINARY]){
                    buffSingle(dh,{{Stats::CD,AType::NONE,24}});
                    ptr->buffCheck["DanHengIL A6"] = 1;
                }
                break;
            }
            if(act->actionName=="DanHengIL Fulgurant Leap"&&dh->getStack("DanHengIL E6")>0){
                ptr->buffNote["DanHengIL E6"] = 20.0 * dh->getStack("DanHengIL E6");
                buffSingle(dh,{{Stats::RESPEN,ElementType::IMAGINARY,AType::NONE,ptr->buffNote["DanHengIL E6"]}});
                dh->setStack("DanHengIL E6",0);
            }
        }));

        // Talent Righteous Heart: DMG +10% ต่อ hit สูงสุด 6 (E1: สูงสุด 10 และได้เพิ่มอีก 1 stack ต่อ hit)
        //   ไม่แบ่ง hit -> ให้ stack ตามจำนวน hit หลังการโจมตีจบ (ไม่ได้ช่วยดาเมจของการโจมตีนั้นเอง)
        afterAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,dh,hitCount,untilTurnEnd](shared_ptr<AllyAttackAction> &act) {
            if(!act->isSameName("DanHengIL"))return;
            int hits = hitCount(act->actionName);
            if(ptr->eidolon>=1)buffStackSingle(dh,{{Stats::DMG,AType::NONE,10}},2*hits,10,"DanHengIL Righteous Heart",untilTurnEnd());
            else buffStackSingle(dh,{{Stats::DMG,AType::NONE,10}},hits,6,"DanHengIL Righteous Heart",untilTurnEnd());
            if(ptr->buffCheck["DanHengIL A6"]){
                buffSingle(dh,{{Stats::CD,AType::NONE,-24}});
                ptr->buffCheck["DanHengIL A6"] = 0;
            }
            if(ptr->buffNote["DanHengIL E6"]>0){
                buffSingle(dh,{{Stats::RESPEN,ElementType::IMAGINARY,AType::NONE,-ptr->buffNote["DanHengIL E6"]}});
                ptr->buffNote["DanHengIL E6"] = 0;
            }
        }));

        // EX1: ทีมใช้ SP ครบทุก 5 (รวม Squama) -> ออก Follow-Up ATK หลัง action ปัจจุบันจบ
        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            if(ptr->extraEidolon<1||spChange>=0)return;
            ptr->buffNote["DanHengIL EX1 SP"] -= spChange;
        }));

        afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_ACTTACK, [ptr,moonset](shared_ptr<AllyActionData> &act) {
            while(ptr->buffNote["DanHengIL EX1 SP"]>=5){
                ptr->buffNote["DanHengIL EX1 SP"] -= 5;
                moonset();
            }
        }));

        // E6: เพื่อนร่วมทีมคนอื่นกด Ult -> Imaginary RES PEN +20% ให้ Fulgurant Leap ครั้งถัดไป สูงสุด 3 stack
        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,dh](CharUnit *ally) {
            if(ptr->eidolon<6||ally->isSameName("DanHengIL"))return;
            calStack(dh,1,3,"DanHengIL E6");
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [dh](CharUnit *ptr) {
            if(!turn->isSameUnit(ptr))return;
            if(isBuffEnd(dh,"DanHengIL Righteous Heart")){
                buffResetStack(dh,{{Stats::DMG,AType::NONE,10}},"DanHengIL Righteous Heart");
            }
            if(isBuffEnd(dh,"DanHengIL Outroar")){
                buffResetStack(dh,{{Stats::CD,AType::NONE,12}},"DanHengIL Outroar");
            }
            if(isBuffEnd(dh,"DanHengIL Moonset Stills the Deep")){
                buffSingle(dh,{{Stats::DMG,AType::NONE,-240}});
            }
            if(ptr->buffCheck["DanHengIL E2 Advance"]){
                ptr->buffCheck["DanHengIL E2 Advance"] = 0;
                actionForward(ptr->atvStats.get(),100);
            }
        }));
    }
}
