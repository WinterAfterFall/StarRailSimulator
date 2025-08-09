#include "../include.h"

namespace Luka{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,130,130,E,ElementType::Physical,Path::Nihility,"Luka",UnitType::Standard);
        ptr->SetAllyBaseStats(917,582,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(134);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        SubUnit *lk = ptr->getSubUnit();

        function<void(int amount)> FW = [ptr,lk](int amount) {
            if(amount>0){
                Increase_energy(lk,3.0*amount);
                if(ptr->Eidolon>=4)lk->buffStackSingle({{Stats::ATK_P,AType::None,5}},amount,4,"Luka E4");
            }else{
            }
            lk->addStack("Fighting Will",amount);
        };
        
        #pragma region Ability

        function<void()> BA = [ptr,lk,FW]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Luka BA",
            [ptr,lk,FW](shared_ptr<AllyAttackAction> &act){
                FW(1);
                Skill_point(lk,1);
                Increase_energy(lk,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,110,10)
            );
            act->addToActionBar();
        };

        function<void()> EBA = [ptr,lk,FW]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Luka EBA",
            [ptr,lk,FW](shared_ptr<AllyAttackAction> &act){
                Skill_point(lk,1);
                Increase_energy(lk,20);
                FW(-2);
                Attack(act);
                for(auto &each : act->targetList){
                    if(ptr->Eidolon>=6)
                    for(int i =1;i<=act->damageSplit.size()-1;i++){
                        Dot_trigger(8,each,DotType::Bleed);
                    }
                    Dot_trigger(88,each,DotType::Bleed);
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

        function<void()> Skill = [ptr,lk,FW]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Luka Skill",
            [ptr,lk,FW](shared_ptr<AllyAttackAction> &act){
                FW(1);
                if(ptr->Eidolon>=2)FW(1);
                Skill_point(lk,-1);
                Increase_energy(lk,30);
                for(auto &each : act->targetList){
                    each->dotSingleApply({DotType::Burn},lk,"Luka Bleed",3);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,132,20)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,lk,BA,Skill,EBA]() {
            if(!Enemy_unit[Main_Enemy_num]->getDebuff("Luka Bleed")){
                Skill();
                return;
            }
            if(lk->getStack("Fighting Will")>=2)EBA();
            BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,lk,FW]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Luka BA",
            [ptr,lk,FW](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Luka");
                FW(2);
                Attack(act);
                for(auto &each : act->targetList){
                    each->debuffSingleApply({{Stats::VUL,AType::None,21.6}},lk,"Luka Vul",3);
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,356,30)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,lk]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 12.5;
        }));

        if(ptr->Eidolon>=1)
        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,lk]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 15;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,lk,FW]() {
            FW(1);
            if(ptr->Technique){
            FW(1);
            shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr->getSubUnit(),TraceType::Single,"Luka Tech",
                [ptr,lk](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                    for(auto &each : act->targetList){
                        each->dotSingleApply({DotType::Burn},lk,"Luka Bleed",3);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                Deal_damage();
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,lk]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(enemy->isDebuffEnd("Luka Bleed")){
                enemy->dotRemove({DotType::Bleed});
            }    
            if(enemy->isDebuffEnd("Luka Vul")){
                enemy->debuffSingle({{Stats::VUL,AType::None,-21.6}});
            }    
        }));
        Dot_List.push_back(TriggerDot_Func(PRIORITY_ACTTACK, [ptr,lk](Enemy* target, double Dot_ratio, DotType Dot_type) {
            if (!target->getDebuff("Luka Bleed")) return;
            if (Dot_type != DotType::General && Dot_type != DotType::Bleed) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Burn,ptr->getSubUnit(),TraceType::Single,"Luka Bleed");
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,372),target);
            act->multiplyDmg(Dot_ratio);
            Attack(act);
        }));
        
    }
}
