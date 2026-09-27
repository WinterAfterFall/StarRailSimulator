#include "../include.h"

namespace Luka{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(103,130,130,eidolon,ElementType::PHYSICAL,Path::NIHILITY,"Luka",UnitType::STANDARD);
        ptr->setAllyBaseStats(917,582,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(134);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *lk = ptr;

        function<void(int amount)> fw = [ptr,lk](int amount) {
            if(amount>0){
                increaseEnergy(lk,3.0*amount);
                if(ptr->eidolon>=4)buffStackSingle(lk,{{Stats::ATK_P,AType::NONE,5}},amount,4,"Luka E4");
            }else{
            }
            lk->addStack("Fighting Will",amount);   // kit cap 4 - จงใจไม่ clamp (user สั่ง: จะได้ไม่ต้องจูน rotation คุมไม่ให้เกิน cap)
        };
        
        #pragma region Ability

        function<void()> ba = [ptr,lk,fw]() {
            genSkillPoint(lk,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Luka BA",
            [ptr,lk,fw](shared_ptr<AllyAttackAction> &act){
                fw(1);
                increaseEnergy(lk,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,110,10)
            );
            act->addToActionBar();
        };

        function<void()> eba = [ptr,lk,fw]() {
            genSkillPoint(lk,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Luka EBA",
            [ptr,lk,fw](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(lk,20);
                fw(-2);
                attack(act);
                for(auto &each : act->targetList){
                    if(ptr->eidolon>=6)
                    for(int i =1;i<=act->damageSplit.size()-1;i++){
                        dotTrigger(8,each,DotType::BLEED);
                    }
                    dotTrigger(88,each,DotType::BLEED);
                }

            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,22));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,22));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,22));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,22));
            if(lk->getBuffCheck("Luka EBA")){
                lk->setBuffCheck("Luka EBA",0);
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,22));
            }else lk->setBuffCheck("Luka EBA",1);
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,88,20));
            act->addToActionBar();
        };

        function<void()> skill = [ptr,lk,fw]() {
            genSkillPoint(lk,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::SINGLE,"Luka Skill",
            [ptr,lk,fw](shared_ptr<AllyAttackAction> &act){
                fw(1);
                if(ptr->eidolon>=2)fw(1);
                increaseEnergy(lk,30);
                for(auto &each : act->targetList){
                    dotSingleApply(lk,each,{DotType::BLEED},"Luka Bleed",3);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,132,20)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,lk,ba,skill,eba]() {
            if(!enemyUnit[mainEnemyNum]->getDebuff("Luka Bleed")){
                skill();
                return;
            }
            if(lk->getStack("Fighting Will")>=2){
                eba();
                return;
            }
            ba();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [lk,fw](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::SINGLE,"Luka Ult",
            [ptr,lk,fw](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Luka");
                fw(2);
                attack(act);
                for(auto &each : act->targetList){
                    debuffSingleApply(lk,each,{{Stats::VUL,AType::NONE,21.6}},"Luka Vul",3);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,356,30)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [lk](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::EHR][AType::NONE] += 18;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 12.5;
        }));

        if(ptr->eidolon>=1)
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [lk](CharUnit *ptr) {
            ptr->statsType[Stats::DMG][AType::NONE] += 15;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [lk,fw](CharUnit *ptr) {
            fw(1);
            if(ptr->technique){
            fw(1);
            shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::SINGLE,"Luka Tech",
                [ptr,lk](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                    for(auto &each : act->targetList){
                        dotSingleApply(lk,each,{DotType::BLEED},"Luka Bleed",3);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [lk](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Luka Bleed")){
                dotRemove(enemy,{DotType::BLEED});
            }    
            if(isDebuffEnd(enemy,"Luka Vul")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-21.6}});
            }    
        }));
        dotList.push_back(TriggerDotFunc(PRIORITY_ACTTACK, [ptr,lk](Enemy* target, double dotRatio, DotType dotType) {
            if (!target->getDebuff("Luka Bleed")) return;
            if (dotType != DotType::GENERAL && dotType != DotType::BLEED) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BLEED,ptr,TraceType::SINGLE,"Luka Bleed");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,372),target);
            act->multiplyDmg(dotRatio);
            attack(act);
        }));
        
    }
}
