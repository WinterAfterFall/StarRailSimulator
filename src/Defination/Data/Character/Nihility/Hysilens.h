#include "../include.h"

namespace Hysilens{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(102,110,110,E,ElementType::Physical,Path::Nihility,"Hysilens",UnitType::Standard);
        ptr->SetAllyBaseStats(1203,602,485);

        //substats
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setApplyBaseChance(100);
        ptr->setEhrRequire(120);
        // ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        SubUnit *hys =ptr->getSubUnit();

        if(ptr->Eidolon>=4)Enemy_effect_res-=20;


        #pragma region Extra
        function<void(Enemy* enemy)> Talent = [ptr,hys](Enemy* enemy) {
            string dotName = "Hys Bleed";
            DotType dotType = DotType::Bleed;
            if(!enemy->getDebuff("Hys Bleed")){
            }
            else if(!enemy->getDebuff("Hys Burn")){
                dotName = "Hys Burn";
                DotType dotType = DotType::Burn;
            }
            else if(!enemy->getDebuff("Hys Shock")){
                dotName = "Hys Shock";
                DotType dotType = DotType::Shock;
            }
            else if(!enemy->getDebuff("Hys WindShear")){
                dotName = "Hys WindShear";
                DotType dotType = DotType::WindShear;
            }else{
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys Burn")){
                    dotName = "Hys Burn";
                    DotType dotType = DotType::Burn;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys Shock")){
                    dotName = "Hys Shock";
                    DotType dotType = DotType::Shock;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys WindShear")){
                    dotName = "Hys WindShear";
                    DotType dotType = DotType::WindShear;
                }
            }
            enemy->dotSingleApply({dotType},hys,dotName,2);
        };
        function<void(Enemy* enemy)> E1 = [ptr,hys](Enemy* enemy) {
            string dotName = "Hys E1 Bleed";
            DotType dotType = DotType::Bleed;
            if(!enemy->getDebuff("Hys E1 Bleed")){
            }
            else if(!enemy->getDebuff("Hys E1 Shock")){
                dotName = "Hys Shock";
                DotType dotType = DotType::Shock;
            }
            else if(!enemy->getDebuff("Hys E1 Burn")){
                dotName = "Hys Burn";
                DotType dotType = DotType::Burn;
            }
            else if(!enemy->getDebuff("Hys E1 WindShear")){
                dotName = "Hys WindShear";
                DotType dotType = DotType::WindShear;
            }else{
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 Shock")){
                    dotName = "Hys E1 Shock";
                    DotType dotType = DotType::Shock;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 Burn")){
                    dotName = "Hys E1 Burn";
                    DotType dotType = DotType::Burn;
                }
                if(enemy->getDebuffTimeCount(dotName) > enemy->getDebuffTimeCount("Hys E1 WindShear")){
                    dotName = "Hys E1 WindShear";
                    DotType dotType = DotType::WindShear;
                }
            }
            enemy->dotSingleApply({dotType},hys,dotName,2);
        };
        

        #pragma endregion

        #pragma region Ability

        function<void()> BA = [ptr,hys]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TraceType::Single,"Hys BA",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                Skill_point(hys,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,hys]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TraceType::Aoe,"Hys Skill",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                Skill_point(hys,-1);
                Increase_energy(ptr,30);
                debuffAllEnemyApply({{Stats::VUL,AType::None,20}},hys,"Hys Vul",3);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10),
                DmgSrc(DmgSrcType::ATK,140,10)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,hys,Skill,BA]() {
            for(int i = 1;i<= Total_enemy;i++){
                if(!Enemy_unit[i]->getDebuff("Hys Vul")){
                    Skill();
                    return;
                }
            }
            BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,hys]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TraceType::Aoe,"Hys Ult",
            [ptr,hys](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Hysilens");
                Skill_point(hys,1);
                for(auto &each : act->targetList){
                    if(each->debuffMark(hys,"Hys Ult")){
                        each->atkPercent-=15;
                        each->debuffSingle({{Stats::DEF_SHRED,AType::None,25}});
                    }
                    Dot_trigger(150,each,DotType::General);
                }
                hys->isHaveToAddBuff("Hys Ult",3);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 14;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            //A6
            if(ptr->Eidolon>=2)buffAllAlly({{Stats::DMG,AType::None,90}});
            else ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 90;

            //Eidolon
            if(ptr->Eidolon>=1){
                buffAllAlly({{Stats::MtprInc,AType::Dot,16}});
            }

        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent,E1]() {
                Skill_point(hys,1);
                for(int i=1;i<=Total_enemy;i++){
                    if(Enemy_unit[i]->debuffMark(hys,"Hys Ult")){
                        Enemy_unit[i]->atkPercent-=15;
                        Enemy_unit[i]->debuffSingle({{Stats::DEF_SHRED,AType::None,25}});
                    }
                }
                hys->isHaveToAddBuff("Hys Ult",3);
                if(ptr->Technique){
                    for(int i=1;i<=Total_enemy;i++){
                    Talent(Enemy_unit[i].get());
                    Talent(Enemy_unit[i].get());
                    if(ptr->Eidolon>=1)E1(Enemy_unit[i].get());
                    if(ptr->Eidolon>=1)E1(Enemy_unit[i].get());
                }
                }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;

            if(enemy->isDebuffEnd("Hys Vul")){
                enemy->debuffSingle({{Stats::VUL,AType::None,-20}});
            }
            if(enemy->isDebuffEnd("Hys Bleed"))enemy->dotRemove({DotType::Bleed});
            if(enemy->isDebuffEnd("Hys WindShear"))enemy->dotRemove({DotType::WindShear});
            if(enemy->isDebuffEnd("Hys Burn"))enemy->dotRemove({DotType::Burn});
            if(enemy->isDebuffEnd("Hys Shock"))enemy->dotRemove({DotType::Shock});
            if(enemy->isDebuffEnd("Hys E1 Bleed"))enemy->dotRemove({DotType::Bleed});
            if(enemy->isDebuffEnd("Hys E1 WindShear"))enemy->dotRemove({DotType::WindShear});
            if(enemy->isDebuffEnd("Hys E1 Burn"))enemy->dotRemove({DotType::Burn});
            if(enemy->isDebuffEnd("Hys E1 Shock"))enemy->dotRemove({DotType::Shock});
            
        }));
        
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,hys]() {
            hys->setStack("Hys Dot Limit",0);
            SubUnit *ally = turn->canCastToSubUnit();
            if(!ally)return;

            if(ally->isBuffEnd("Hys Ult")){
                CharCmd::printUltEnd("Hysilens");
                for(int i=1;i<=Total_enemy;i++){
                    Enemy_unit[i]->debuffSingle({{Stats::DEF_SHRED,AType::None,-25}});
                    Enemy_unit[i]->atkPercent -=15;
                    Enemy_unit[i]->debuffRemove("Hys Ult");
                }
            }
        }));

        BeforeAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,hys](shared_ptr<ActionData> &act) {
            hys->setStack("Hys Dot Limit",0);
        }));


        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent,E1](shared_ptr<AllyAttackAction> &act) {
            for(auto &each : act->targetList){
                Talent(each);
                if(ptr->Eidolon>=1)E1(each);
            }
        }));

        AfterAttack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,hys](shared_ptr<AllyAttackAction> &act) {
            if(act->isSameDamageType(AType::Dot)&&act->actionName!="Hys Ult Dot"){
                shared_ptr<AllyAttackAction> Newact = 
            make_shared<AllyAttackAction>(AType::Dot,ptr->getSubUnit(),TraceType::Single,"Hys Ult Dot");
                for (auto &each : act->targetList) {
                    if(ptr->Eidolon>=6)if(hys->getStack("Hys Dot Limit")>=12)break;
                    else if(hys->getStack("Hys Dot Limit")>=8)break;
                    hys->addStack("Hys Dot Limit",1);
                    if(ptr->Eidolon>=6)Newact->addDamageIns(DmgSrc(DmgSrcType::ATK,100));
                    else Newact->addDamageIns(DmgSrc(DmgSrcType::ATK,80));
                    Newact->addDamageType(AType::Ult);
                    Attack(Newact);
                }
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (Dot_type != DotType::General && Dot_type != DotType::Bleed) return;
            if (target->getDebuff("Hys Bleed")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Bleed,ptr->getSubUnit(),TraceType::Single,"Hys Bleed");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
            if (target->getDebuff("Hys E1 Bleed")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Bleed,ptr->getSubUnit(),TraceType::Single,"Hys E1 Bleed");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (Dot_type != DotType::General && Dot_type != DotType::WindShear) return;
            if (target->getDebuff("Hys WindShear")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WindShear,ptr->getSubUnit(),TraceType::Single,"Hys WindShear");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
            if (target->getDebuff("Hys E1 WindShear")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::WindShear,ptr->getSubUnit(),TraceType::Single,"Hys E1 WindShear");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (Dot_type != DotType::General && Dot_type != DotType::Burn) return;
            if (target->getDebuff("Hys Burn")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Burn,ptr->getSubUnit(),TraceType::Single,"Hys Burn");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
            if (target->getDebuff("Hys E1 Burn")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Burn,ptr->getSubUnit(),TraceType::Single,"Hys E1 Burn");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_IMMEDIATELY, [ptr,hys,Talent](Enemy* target, double Dot_ratio,DotType Dot_type) {
            if (Dot_type != DotType::General && Dot_type != DotType::Shock) return;
            if (target->getDebuff("Hys Shock")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Shock,ptr->getSubUnit(),TraceType::Single,"Hys Shock");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
            if (target->getDebuff("Hys E1 Shock")){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::Shock,ptr->getSubUnit(),TraceType::Single,"Hys E1 Shock");
                act->addDamageIns(DmgSrc(DmgSrcType::ATK,25),target);
                act->multiplyDmg(Dot_ratio);
                Attack(act);
            }
        }));
    }
}
