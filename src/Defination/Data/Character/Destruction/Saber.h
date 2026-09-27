#include "../include.h"

namespace Saber{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(101,360,360,eidolon,ElementType::WIND,Path::DESTRUCTION,"Saber",UnitType::STANDARD);
        ptr->setAllyBaseStats(1242,602,655);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(136);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *sb = ptr;

        #pragma region extra
        function<void(int value)> coreResonance = [ptr,sb](int value){
            sb->buffNote["Core Resonance"] += value;
            buffStackSingle(sb,{{Stats::CD,AType::NONE,4}},value,8,"Saber A6");
            if(ptr->eidolon>=2)buffStackSingle(sb,{{Stats::DEF_SHRED,AType::NONE,1}},value,15,"Saber E2");
        };

        function<double()> resetCR = [ptr,sb](){
            double ans = sb->buffNote["Core Resonance"];
            sb->setBuffNote("Core Resonance",0);
            sb->setBuffCheck("Saber ESkill",0);
            increaseEnergy(sb,0,8.0*ans);
            if(ptr->eidolon>=2)return 21*ans;
            else return 14*ans;
        };

        #pragma endregion

        #pragma region Ability

        function<void()> ba = [ptr,sb,coreResonance]() {
            genSkillPoint(sb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Saber BA",
            [ptr,sb,coreResonance](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(sb,20);
                attack(act);
                if(ptr->eidolon>=1)coreResonance(1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->setDamageNote(0);
            act->addToActionBar();
        };

        function<void()> eba = [ptr,sb,coreResonance]() {
            genSkillPoint(sb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::AOE,"Saber EBA",
            [ptr,sb,coreResonance](shared_ptr<AllyAttackAction> &act){
                sb->setBuffCheck("Saber EBA",0);
                increaseEnergy(sb,30);
                sb->setBuffCheck("Mana Flow",1);
                coreResonance(2);
                attack(act);
                if(ptr->eidolon>=1)coreResonance(1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,75,10),
                DmgSrc(DmgSrcType::ATK,75,10),
                DmgSrc(DmgSrcType::ATK,75,10)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,75,10),
                DmgSrc(DmgSrcType::ATK,75,10),
                DmgSrc(DmgSrcType::ATK,75,10)
            );

            if(totalEnemy==1||(bestBounce&&totalEnemy==5))
            act->multiplyDmg(370.0/150*100);
            if(totalEnemy==2)
            act->multiplyDmg(200);
            act->addToActionBar();
        };

        function<void()> skill = [ptr,sb,coreResonance]() {
            genSkillPoint(sb,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Saber Skill",
            [ptr,sb,coreResonance](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(sb,30);
                buffSingle(sb,{{Stats::CD,AType::NONE,50}},"Saber A6 Skill",2);
                coreResonance(3);
                attack(act);
                if(ptr->eidolon>=1)coreResonance(1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,150*0.1,2),
                DmgSrc(DmgSrcType::ATK,75*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,150*0.1,2),
                DmgSrc(DmgSrcType::ATK,75*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,150*0.1,2),
                DmgSrc(DmgSrcType::ATK,75*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,150*0.7,14),
                DmgSrc(DmgSrcType::ATK,75*0.7,7)
            );
            act->setDamageNote(0);
            act->addToActionBar();
        };

        function<void()> eSkill = [ptr,sb,resetCR,coreResonance]() {
            genSkillPoint(sb,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Saber ESkill",
            [ptr,sb,resetCR,coreResonance](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(sb,30);
                buffSingle(sb,{{Stats::CD,AType::NONE,50}},"Saber A6 Skill",2);
                attack(act);
                if(ptr->eidolon>=1)coreResonance(1);
            });

            double mtpr = resetCR();
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,(150 + mtpr)*0.1,2),
                DmgSrc(DmgSrcType::ATK,(75 + mtpr)*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,(150 + mtpr)*0.1,2),
                DmgSrc(DmgSrcType::ATK,(75 + mtpr)*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,(150 + mtpr)*0.1,2),
                DmgSrc(DmgSrcType::ATK,(75 + mtpr)*0.1,1)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,(150 + mtpr)*0.7,14),
                DmgSrc(DmgSrcType::ATK,(75 + mtpr)*0.7,7)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,sb,ba,eba,skill,eSkill]() {
            if(sb->getBuffCheck("Saber EBA"))eba();
            else if(sb->getBuffCheck("Saber ESkill"))eSkill();
            else if(sp>=1)skill();
            else ba();
        };
        

        ptr->addUltCondition([sb]() -> bool {
            if(!sb->getBuffCheck("Mana Flow"))return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [sb](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Saber Ult",
            [ptr,sb](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Saber");
                sb->setBuffCheck("Saber EBA",1);
                increaseEnergy(sb,0,sb->getBuffNote("Saber A4"));
                sb->buffNote["Saber A4"] = 0;
                if(ptr->eidolon>=4)buffStackSingle(sb,{{Stats::RESPEN,ElementType::WIND,AType::NONE,4}},1,3,"Saber E4");
                if(ptr->eidolon>=6){
                    if(sb->getBuffCountdown("Saber E6")==0){
                        sb->setBuffCountdown("Saber E6",2);
                        increaseEnergy(sb,0,300);
                    }else{
                        sb->buffEnd["Saber E6"]--;
                    }
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,280,40),
                DmgSrc(DmgSrcType::ATK,280,40),
                DmgSrc(DmgSrcType::ATK,280,40)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,110,2),10);
            act->addToActionBar();
            dealDamage();

        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 22.4;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;

            //trace
            ptr->statsType[Stats::CR][AType::NONE] += 20;

            if(ptr->eidolon>=1)ptr->statsType[Stats::DMG][AType::ULT] += 60;
            if(ptr->eidolon>=4)ptr->statsEachElement[Stats::RESPEN][ElementType::WIND][AType::NONE] += 8;
            if(ptr->eidolon>=6)ptr->statsEachElement[Stats::RESPEN][ElementType::WIND][AType::ULT] += 20;


        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sb](CharUnit *ptr) {
            if(isBuffEnd(sb,"Saber Talent")){
                buffSingle(sb,{{Stats::DMG,AType::NONE,-60}});
            }
            if(isBuffEnd(sb,"Saber Tech")){
                buffSingle(sb,{{Stats::ATK_P,AType::NONE,-35}});
            }
            if(isBuffEnd(sb,"Saber A6 Skill")){
                buffSingle(sb,{{Stats::CD,AType::NONE,-50}});
            }
            // Skill energy (30, via ER) + consumed Core Resonance (8 each, fixed) would fill Energy
            if(ptr->ultCost<=ptr->currentEnergy + 30*ptr->energyRecharge/100 + 8 * sb->buffNote["Core Resonance"]){
                sb->setBuffCheck("Saber ESkill",1);
                if(sb->getBuffCheck("Mana Flow")){
                    actionForward(sb->atvStats.get(),1000);
                    genSkillPoint(sb,1);
                    sb->setBuffCheck("Mana Flow",0);
                }
            }else sb->setBuffCheck("Saber ESkill",0);
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sb,coreResonance](CharUnit *ptr) {
            // A4: Energy below 60% at battle start -> set to 60%
            if(ptr->currentEnergy < ptr->maxEnergy*0.6)ptr->currentEnergy = ptr->maxEnergy*0.6;
            sb->setBuffCheck("Mana Flow",1);
            coreResonance(1);
            if(ptr->technique){
                coreResonance(2);
                buffSingle(sb,{{Stats::ATK_P,AType::NONE,35}},"Saber Tech",2);
            }
        }));

        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,sb,coreResonance](CharUnit *ally) {
            buffSingle(sb,{{Stats::DMG,AType::NONE,60}},"Saber Talent",2);
            coreResonance(3);
        }));

        whenEnergyIncreaseList.push_back(TriggerEnergyIncreaseFunc(PRIORITY_IMMEDIATELY, [ptr,sb,coreResonance](CharUnit *target, double energy) {
            if(!ptr->isSameOwner(target))return;

            if(ptr->currentEnergy + energy >= ptr->maxEnergy){
                sb->buffNote["Saber A4"] += ptr->currentEnergy + energy - ptr->maxEnergy ;
            }

        }));
    }

    void ultInTurnOnly(){
        CharUnit *ally = CharCmd::findAllyName("Saber");
        ally->addUltCondition([ally]() -> bool {
            if(turn->isSameName("Saber")&&phaseStatus == PhaseStatus::BEFORE_TURN)return true;
            return false;
        });
    }
}
