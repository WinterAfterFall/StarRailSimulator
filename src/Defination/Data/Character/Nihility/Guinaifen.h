#include "../include.h"

namespace Guinaifen{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(106,120,120,E,ElementType::Fire,Path::Nihility,"Guinaifen",UnitType::Standard);
        ptr->SetAllyBaseStats(882,582,441);

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

        AllyUnit *gui = ptr;
        #pragma region Ability

        if(ptr->Eidolon>=1)Enemy_effect_res-=10;

        function<void()> BA = [ptr,gui]() {
            Skill_point(gui,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Gui BA",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,20);
                for(auto &each : act->targetList){
                    each->dotSingleApply({DotType::Burn},gui,"Gui Burn",2);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,110,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,gui]() {
            Skill_point(gui,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Gui Skill",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,30);
                for(auto &each : act->targetList){
                    each->dotSingleApply({DotType::Burn},gui,"Gui Burn",2);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,132,20),
                DmgSrc(DmgSrcType::ATK,44,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,gui,BA,Skill]() {
            if(sp>Sp_Safety)Skill();
            else BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,gui]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Gui Skill",
            [ptr,gui](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Guinaifen");
                for(auto &each : act->targetList){
                    Dot_trigger(96,each,DotType::Burn);
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,129.6,20),
                DmgSrc(DmgSrcType::ATK,129.6,20),
                DmgSrc(DmgSrcType::ATK,129.6,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,gui]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Fire][AType::None] += 22.4;
            ptr->Stats_type[Stats::BE][AType::None] += 24;
            ptr->Stats_type[Stats::EHR][AType::None] += 10;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,gui]() {
            ptr->Stats_type[Stats::DMG][AType::None] += 20;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,gui]() {
            if(ptr->Technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Technique,ptr,TraceType::Aoe,"Gui Tech",
                [ptr,gui](shared_ptr<AllyAttackAction> &act){
                    Attack(act);
                    for(auto &each : act->targetList){
                        each->dotSingleApply({DotType::Burn},gui,"Gui Burn",2);
                    }
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                Deal_damage();
            }
            Action_forward(gui->Atv_stats.get(),25);          
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,gui]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(enemy->isDebuffEnd("Gui Burn")){
                enemy->dotRemove({DotType::Burn});
            }       
        }));

        BeforeAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,gui](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameDamageType(AType::Burn)){
                if(ptr->Eidolon>=6){
                    debuffStackEnemyTargets(act->targetList,{{Stats::VUL,AType::None,7.6}},gui,1,4,"Firekiss");
                }else{
                    debuffStackEnemyTargets(act->targetList,{{Stats::VUL,AType::None,7.6}},gui,1,3,"Firekiss");
                }
            }      
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_ACTTACK, [ptr,gui](Enemy* target, double Dot_ratio, DotType Dot_type) {
            if (!target->getDebuff("Gui Burn")) return;
            if (Dot_type != DotType::General && Dot_type != DotType::Burn) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Burn,ptr,TraceType::Single,"Gui Burn");
            if(ptr->Eidolon>=2)act->addDamageIns(DmgSrc(DmgSrcType::ATK,280),target);
            else act->addDamageIns(DmgSrc(DmgSrcType::ATK,240),target);
            act->multiplyDmg(Dot_ratio);
            if(ptr->Eidolon>=4)Increase_energy(ptr,2);
            Attack(act);
        }));
    }
}
