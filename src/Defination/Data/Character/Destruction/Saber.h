#include "../include.h"

namespace Saber{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,360,360,E,ElementType::Wind,Path::Destruction,"Saber",UnitType::Standard);
        ptr->SetAllyBaseStats(1242,602,655);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(136);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *sb = ptr;

        #pragma region extra
        function<void(int value)> CoreResonance = [ptr,sb](int value){
            sb->Buff_note["Core Resonance"] += value;
            buffStackSingle(sb,{{Stats::CD,AType::None,4}},value,8,"Saber A6");
            if(ptr->Eidolon>=2)buffStackSingle(sb,{{Stats::DEF_SHRED,AType::None,1}},value,15,"Saber E2");
        };

        function<double()> resetCR = [ptr,sb](){
            double ans = sb->Buff_note["Core Resonance"];
            sb->setBuffNote("Core Resonance",0);
            sb->setBuffCheck("Saber ESkill",0);
            Increase_energy(sb,0,8.0*ans);
            if(ptr->Eidolon>=2)return 21*ans;
            else return 14*ans;
        };

        #pragma endregion

        #pragma region Ability

        function<void()> BA = [ptr,sb,CoreResonance]() {
            Skill_point(sb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Saber BA",
            [ptr,sb,CoreResonance](shared_ptr<AllyAttackAction> &act){
                Increase_energy(sb,20);
                Attack(act);
                if(ptr->Eidolon>=1)CoreResonance(1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->setDamageNote(0);
            act->addToActionBar();
        };

        function<void()> EBA = [ptr,sb,CoreResonance]() {
            Skill_point(sb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Aoe,"Saber EBA",
            [ptr,sb,CoreResonance](shared_ptr<AllyAttackAction> &act){
                sb->setBuffCheck("Saber EBA",0);
                Increase_energy(sb,30);
                sb->setBuffCheck("Mana Flow",1);
                CoreResonance(2);
                Attack(act);
                if(ptr->Eidolon>=1)CoreResonance(1);
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

            if(Total_enemy==1||(bestBounce&&Total_enemy==5))
            act->multiplyDmg(370/150*100);
            if(Total_enemy==2)
            act->multiplyDmg(200);
            act->addToActionBar();
        };

        function<void()> Skill = [ptr,sb,CoreResonance]() {
            Skill_point(sb,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Saber Skill",
            [ptr,sb,CoreResonance](shared_ptr<AllyAttackAction> &act){
                Increase_energy(sb,30);
                buffSingle(sb,{{Stats::CD,AType::None,50}},"Saber A6",2);
                CoreResonance(3);
                Attack(act);
                if(ptr->Eidolon>=1)CoreResonance(1);
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

        function<void()> ESkill = [ptr,sb,resetCR,CoreResonance]() {
            Skill_point(sb,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Saber ESkill",
            [ptr,sb,resetCR,CoreResonance](shared_ptr<AllyAttackAction> &act){
                Increase_energy(sb,30);
                Attack(act);
                if(ptr->Eidolon>=1)CoreResonance(1);
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
        ptr->Turn_func = [ptr,sb,BA,EBA,Skill,ESkill]() {
            if(sb->getBuffCheck("Saber EBA"))EBA();
            else if(sb->getBuffCheck("Saber ESkill"))ESkill();
            else if(sp>=1)Skill();
            else BA();
        };
        

        ptr->addUltCondition([sb]() -> bool {
            if(!sb->getBuffCheck("Mana Flow"))return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,sb]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Saber Ult",
            [ptr,sb](shared_ptr<AllyAttackAction> &act){
                CharCmd::printUltStart("Saber");
                sb->setBuffCheck("Saber EBA",1);
                Increase_energy(sb,0,sb->getBuffNote("Saber A4"));
                sb->Buff_note["Saber A4"] = 0;
                if(ptr->Eidolon>=4)buffStackSingle(sb,{{Stats::RESPEN,ElementType::Wind,AType::None,4}},1,3,"Saber E4");
                if(ptr->Eidolon>=6){
                    if(sb->getBuffCountdown("Saber E6")==0){
                        sb->setBuffCountdown("Saber E6",2);
                        Increase_energy(sb,0,300);
                    }else{
                        sb->Buff_countdown["Saber E6"]--;
                    }
                }
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,280,40),
                DmgSrc(DmgSrcType::ATK,280,40),
                DmgSrc(DmgSrcType::ATK,280,40)
            );
            act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,110,2),10);
            act->addToActionBar();
            Deal_damage();

        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Wind][AType::None] += 22.4;
            ptr->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Stats_type[Stats::HP_P][AType::None] += 10;

            //trace
            ptr->Stats_type[Stats::CR][AType::None] += 20;

            if(ptr->Eidolon>=1)ptr->Stats_type[Stats::DMG][AType::Ult] += 60;
            if(ptr->Eidolon>=4)ptr->Stats_each_element[Stats::RESPEN][ElementType::Wind][AType::None] += 8;
            if(ptr->Eidolon>=6)ptr->Stats_each_element[Stats::RESPEN][ElementType::Wind][AType::Ult] += 20;


        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sb]() {
            if(isBuffEnd(sb,"Saber Talent")){
                buffSingle(sb,{{Stats::DMG,AType::None,-60}});
            }
            if(isBuffEnd(sb,"Saber Tech")){
                buffSingle(sb,{{Stats::ATK_P,AType::None,-35}});
            }
            if(isBuffEnd(sb,"Saber A6")){
                buffSingle(sb,{{Stats::CD,AType::None,-50}});
            }
            if(ptr->Ult_cost<=ptr->Current_energy + 8 * sb->Buff_note["Core Resonance"]){
                sb->setBuffCheck("Saber ESkill",1);
                if(sb->getBuffCheck("Mana Flow")){
                    Action_forward(sb->Atv_stats.get(),1000);
                    Skill_point(sb,1);
                    sb->setBuffCheck("Mana Flow",0);
                }
            }else sb->setBuffCheck("Saber ESkill",0);
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,sb,CoreResonance]() {
            Increase_energy(ptr,10,0);
            sb->setBuffCheck("Mana Flow",1);
            CoreResonance(1);
            if(ptr->Technique){
                CoreResonance(2);
                buffSingle(sb,{{Stats::ATK_P,AType::None,35}},"Saber Tech",2);
            }
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY, [ptr,sb,CoreResonance](CharUnit *ally) {
            buffSingle(sb,{{Stats::DMG,AType::None,60}},"Saber Talent",2);
            CoreResonance(3);
        }));

        When_Energy_Increase_List.push_back(TriggerEnergy_Increase_Func(PRIORITY_IMMEDIATELY, [ptr,sb,CoreResonance](CharUnit *target, double Energy) {
            if(!ptr->isSameChar(target))return;

            if(ptr->Current_energy + Energy >= ptr->Max_energy){
                sb->Buff_note["Saber A4"] += ptr->Current_energy + Energy - ptr->Max_energy ;
            }

        }));
    }

    void UltInTurnOnly(){
        CharUnit *ally = CharCmd::findAllyName("Saber");
        ally->addUltCondition([ally]() -> bool {
            if(turn->isSameUnitName("Saber")&&phaseStatus == PhaseStatus::BeforeTurn)return true;
            return false;
        });
    }
}
